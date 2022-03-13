#include <cstdio>
#include "structure.h"
#include "constants.h"


int col_of_sections(FILE* f)
{
    int rc = 6;
    double x1, x2, x3, y1, y2, y3;
    int col = 0;
    while (rc == 6)
    {
        rc = fscanf(f, "%lf %lf %lf %lf %lf %lf", &x1, &x2, &x3, &y1, &y2, &y3);
        if (rc == 6)
            col++;
    }
    return col;
}

void free_frame(frame3d& fr)
{
    for (int i = 0; i < fr.leng; i++)
    {
        delete fr.mass[i].start;
        delete fr.mass[i].end;
    }
    delete fr.mass;
}

err_type input_dot(dot3d* dot1, FILE* f)
{
    err_type rc = fscanf(f, "%lf %lf %lf", &(dot1->x), &(dot1->y), &(dot1->z));
    return rc == 3 ? 0 : INPUT_ERR;
}

err_type input_sect(section3d& sect, FILE* f)
{
    err_type rc = 0;
    rc = input_dot(sect.start, f);
    if (!rc)
        rc = input_dot(sect.end, f);
    return rc;
}

err_type input_frame(FILE* f, frame3d& fr)
{
    err_type rc = OK;
    if (!f)
        rc = FILE_OPEN_ERR;
    if (!rc)
    {
        int col = col_of_sections(f);
        rewind(f);
        if (col != 0)
        {
            fr.leng = col;
            fr.mass = new section3d[col];
            for (int i = 0; i < col; i++)
            {
                fr.mass[i].start = new dot3d;
                fr.mass[i].end = new dot3d;
            }
            if (fr.mass)
            {
                for (int i = 0; i < col && !rc; i++)
                    rc = input_sect(fr.mass[i], f);
                if (rc)
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
