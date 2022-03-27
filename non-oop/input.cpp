#include <cstdio>
#include "structure.h"
#include "constants.h"
#include "dot_funcs.h"
#include "frame_funcs.h"

int col_of_dots(FILE* f)
{
    int rc = 3;
    double x, y, z;
    int col = 0;
    char buff[1024];
    while (rc == 3)
    {
        fgets(buff, sizeof (buff), f);
        rc = sscanf(buff, "%lf %lf %lf", &x, &y, &z);
        if (rc == 3)
            col++;
    }
    return col;
}

err_type col_of_sects(int& rez, int maxr, FILE* f)
{
    err_type rc = OK;
    int drc = 2;
    int d1, d2;
    int col = 0;
    char buff[1024];
    while (drc == 2 && rc == OK && !feof(f))
    {
        fgets(buff, sizeof (buff), f);
        drc = sscanf(buff, "%d %d", &d1, &d2);
        if (d1 >= maxr || d1 < 0 || d2 >= maxr || d2 < 0)
            rc = NON_SECT_ERR;
        if (drc == 2)
            col++;
    }
    rez = col;
    return rc;
}

void free_frame(frame3d& fr)
{
    delete fr.dots;
    delete fr.sects;
    fr.ndots = 0;
    fr.nsect = 0;
}

err_type create_frame(frame3d& fr, int ndots, int nsect)
{
    err_type rc = OK;
    fr.ndots = ndots;
    fr.nsect = nsect;
    fr.dots = new dot3d[ndots];
    fr.sects = new section[nsect];
    if (!fr.dots || !fr.sects)
        rc = MEMORY_ERR;
    return rc;
}

frame3d init_frame()
{
    frame3d fr;
    fr.ndots = 0;
    fr.nsect = 0;
    fr.dots = nullptr;
    fr.sects = nullptr;
    return fr;
}

err_type copy_frame(frame3d &fr_cop, const frame3d fr)
{
    err_type rc = create_frame(fr_cop, fr.ndots, fr.nsect);
    if (rc == OK)
    {
        for (size_t i = 0; i < frames_length_dots(fr); i++)
            copy_dot(get_dot(fr_cop, i), get_dot(fr, i));
        for (size_t i = 0; i < frames_length_sects(fr); i++)
            copy_sect(get_sect(fr_cop, i), get_sect(fr, i));
    }

    return rc;
}

err_type input_dot(dot3d& dot1, FILE* f)
{
    int rc = fscanf(f, "%lf %lf %lf", &(dot1.x), &(dot1.y), &(dot1.z));
    return rc == 3 ? OK : INPUT_ERR;
}

err_type input_sect(section& sect, FILE* f)
{
    int rc = fscanf(f, "%llu %llu", &(sect.start), &(sect.end));
    return rc == 2 ? OK : NON_SECT_ERR;
}


err_type input_dots(dot3d *dots, size_t n, FILE* f)
{
    if (!n || !dots || !f)
        return INPUT_ERR;
    dot3d d;
    err_type rc = OK;
    for (size_t i = 0; !rc && i < n; i++)
    {
        rc = input_dot(d, f);
        if (rc == OK)
            copy_dot(dots[i], d);
    }
    return rc;
}

err_type input_sects(section *sects, size_t n, FILE* f)
{
    if (!n || !sects || !f)
        return INPUT_ERR;
    section sc;
    err_type rc = OK;
    for (size_t i = 0; !rc && i < n; i++)
    {
        rc = input_sect(sc, f);
        if (rc == OK)
            copy_sect(sects[i], sc);
    }
    return rc;
}



err_type input_frame(frame3d& fr, FILE* f)
{
    rewind(f);
    size_t n = frames_length_dots(fr);
    err_type rc = OK;
    rc = input_dots(fr.dots, n, f);
    if (rc == OK)
    {
        n = frames_length_sects(fr);
        rc = input_sects(fr.sects, n, f);
    }
    return rc;
}

err_type read_frame(frame3d& fr, FILE* f)
{
    if (!f)
        return FILE_OPEN_ERR;
    err_type rc = OK;
    frame3d fr_cop = init_frame();
    int ndots = col_of_dots(f), nsects = 0;
    rc = col_of_sects(nsects, ndots, f);
    if (rc == OK)
    {
        rc = create_frame(fr_cop, ndots, nsects);
        if (rc == OK)
        {
            rc = input_frame(fr_cop, f);
            if (rc == OK)
            {
                free_frame(fr);
                copy_frame(fr, fr_cop);
            }
        }
    }
    return rc;
}

err_type download_frame(frame3d& fr, input_act act)
{
    FILE *f = fopen(act.filename, "r");
    err_type rc = read_frame(fr, f);
    fclose(f);
    return rc;
}
