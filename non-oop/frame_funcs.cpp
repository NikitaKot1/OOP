#include "constants.h"
#include "frame.h"
#include "structure.h"

int frames_length_dots(frame3d fr)
{
    return fr.ndots;
}

int frames_length_sects(frame3d fr)
{
    return fr.nsect;
}

err_type get_dot_i_x(double &x, const int i, const frame3d fr)
{
    err_type rc = OK;
    if (i < fr.ndots && i >= 0)
        x = fr.dots[i].x;
    else
        rc = UNKNOWN_COORD;
    return rc;
}

err_type get_dot_i_y(double &y, const int i, const frame3d fr)
{
    err_type rc = OK;
    if (i < fr.ndots && i >= 0)
        y = fr.dots[i].y;
    else
        rc = UNKNOWN_COORD;
    return rc;
}

err_type get_dot_i_z(double &z, const int i, const frame3d fr)
{
    err_type rc = OK;
    if (i < fr.ndots && i >= 0)
        z = fr.dots[i].z;
    else
        rc = UNKNOWN_COORD;
    return rc;
}

err_type set_i_dot_x(frame3d& fr, const int i, const double x)
{
    err_type rc = OK;
    if (i >= 0 && i < fr.ndots)
        fr.dots[i].x = x;
    else
        rc = UNKNOWN_COORD;
    return rc;
}

err_type set_i_dot_y(frame3d& fr, const int i, const double y)
{
    err_type rc = OK;
    if (i >= 0 && i < fr.ndots)
        fr.dots[i].y = y;
    else
        rc = UNKNOWN_COORD;
    return rc;
}

err_type set_i_dot_z(frame3d& fr, const int i, const double z)
{
    err_type rc = OK;
    if (i >= 0 && i < fr.ndots)
        fr.dots[i].z = z;
    else
        rc = UNKNOWN_COORD;
    return rc;
}


err_type get_i_sect(int &rez1, int &rez2, const int i, const frame3d fr)
{
    err_type rc = OK;
    if (i >= 0 && i < fr.nsect)
    {
            rez1 = fr.sects[i].start;
            rez2 = fr.sects[i].end;
    }
    else
        rc = UNKNOWN_SECT;
    return rc;
}
