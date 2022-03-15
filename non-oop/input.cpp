#include <cstdio>
#include "structure.h"
#include "constants.h"


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

err_type init_frame(frame3d& fr, int ndots, int nsect)
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

err_type copy_frame(frame3d &fr_cop, const frame3d fr)
{
    err_type rc = init_frame(fr_cop, fr.ndots, fr.nsect);
    if (rc == OK)
    {
        for (int i = 0; i < fr.ndots; i++)
            fr_cop.dots[i] = fr.dots[i];
        for (int i = 0; i < fr.nsect; i++)
            fr_cop.sects[i] = fr.sects[i];
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
    int rc = fscanf(f, "%d %d", &(sect.start), &(sect.end));
    return rc == 2 ? OK : NON_SECT_ERR;
}

err_type input_frame(frame3d& fr, FILE* f)
{
    err_type rc = OK;
    if (!f)
        rc = FILE_OPEN_ERR;
    if (rc == OK)
    {
        int ndots = col_of_dots(f), nsects = 0;
        rc = col_of_sects(nsects, ndots, f);
        rewind(f);
        if (rc == OK)
        {
            rc = init_frame(fr, ndots, nsects);
            if (rc == OK)
            {
                for (int i = 0; rc == OK && i < ndots; i++)
                    rc = input_dot(fr.dots[i], f);
                for (int i = 0; rc == OK && i < nsects; i++)
                    rc = input_sect(fr.sects[i], f);
                if (rc != OK)
                    free_frame(fr);
            }
            else
                rc = MEMORY_ERR;
        }
        else
            rc = NON_SECT_ERR;
    }
    return rc;
}
