#include "constants.h"
#include "structure.h"
#include "frame_funcs.h"

#include <cmath>

err_type transfer_i_x(frame3d& fr, int i, double dx)
{
    err_type rc = OK;
    double x;
    rc = get_dot_i_x(x, i, fr);
    if (rc == OK)
        rc = set_i_dot_x(fr, i, x + dx);
    return rc;
}

err_type transfer_i_y(frame3d& fr, int i, double dy)
{
    err_type rc = OK;
    double y;
    rc = get_dot_i_y(y, i, fr);
    if (rc == OK)
        rc = set_i_dot_y(fr, i, y + dy);
    return rc;
}

err_type transfer_i_z(frame3d& fr, int i, double dz)
{
    err_type rc = OK;
    double z;
    rc = get_dot_i_z(z, i, fr);
    if (rc == OK)
        rc = set_i_dot_z(fr, i, z + dz);
    return rc;
}

err_type transfer(frame3d& fr, transf_act tr)
{
    err_type rc = OK;
    for (int i = 0; rc == OK && i < frames_length_dots(fr); i++)
    {
        rc = transfer_i_x(fr, i, tr.dx);
        if (rc == OK)
            rc = transfer_i_y(fr, i, tr.dy);
        if (rc == OK)
            rc = transfer_i_z(fr, i, tr.dz);
    }
    return rc;
}

err_type scale_i_x(frame3d& fr, int i, double kx)
{
    err_type rc = OK;
    double x;
    rc = get_dot_i_x(x, i, fr);
    if (rc == OK)
        rc = set_i_dot_x(fr, i, x * kx);
    return rc;
}

err_type scale_i_y(frame3d& fr, int i, double ky)
{
    err_type rc = OK;
    double y;
    rc = get_dot_i_y(y, i, fr);
    if (rc == OK)
        rc = set_i_dot_y(fr, i, y * ky);
    return rc;
}

err_type scale_i_z(frame3d& fr, int i, double kz)
{
    err_type rc = OK;
    double z;
    rc = get_dot_i_z(z, i, fr);
    if (rc == OK)
        rc = set_i_dot_z(fr, i, z * kz);
    return rc;
}

err_type scale(frame3d& fr, scalse_act sc)
{
    err_type rc = OK;
    for (int i = 0; !rc && i < frames_length_dots(fr); i++)
    {
        rc = scale_i_x(fr, i, sc.kx);
        if (!rc)
            rc = scale_i_y(fr, i, sc.ky);
        if (!rc)
            rc = scale_i_z(fr, i, sc.kz);
    }
    return rc;
}

void rotate_0xy(double& x, double& y, double ang)
{
    ang = ang / 360 * 2 * M_PI;
    double xf = x * cos(ang) + y * sin(ang);
    double yf = y * cos(ang) - x * sin(ang);
    x = xf;
    y = yf;
}

err_type rotate_i_xy(frame3d& fr, int i, double ang)
{
    err_type rc = OK;
    double x, y;
    rc = get_dot_i_x(x, i, fr);
    if (rc == OK)
        rc = get_dot_i_y(y, i, fr);
    if (rc == OK)
    {
        rotate_0xy(x, y, ang);
        rc = set_i_dot_x(fr, i, x);
        if (rc == OK)
            rc = set_i_dot_y(fr, i, y);
    }
    return rc;
}

void rotate_0yz(double& y, double& z, double ang)
{
    ang = ang / 360 * 2 * M_PI;
    double yf = y * cos(ang) + z * sin(ang);
    double zf = z * cos(ang) - y * sin(ang);
    z = zf;
    y = yf;
}

err_type rotate_i_yz(frame3d& fr, int i, double ang)
{
    err_type rc = OK;
    double z, y;
    rc = get_dot_i_z(z, i, fr);
    if (rc == OK)
        rc = get_dot_i_y(y, i, fr);
    if (rc == OK)
    {
        rotate_0yz(y, z, ang);
        rc = set_i_dot_z(fr, i, z);
        if (rc == OK)
            rc = set_i_dot_y(fr, i, y);
    }
    return rc;
}

void rotate_0xz(double& x, double& z, double ang)
{
    ang = ang / 360 * 2 * M_PI;
    double xf = x * cos(ang) + z * sin(ang);
    double zf = z * cos(ang) - x * sin(ang);
    z = zf;
    x = xf;
}

err_type rotate_i_xz(frame3d& fr, int i, double ang)
{
    err_type rc = OK;
    double x, z;
    rc = get_dot_i_x(x, i, fr);
    if (rc == OK)
        rc = get_dot_i_z(z, i, fr);
    if (rc == OK)
    {
        rotate_0xz(x, z, ang);
        rc = set_i_dot_x(fr, i, x);
        if (rc == OK)
            rc = set_i_dot_z(fr, i, z);
    }
    return rc;
}


err_type rotate(frame3d& fr, rotate_act rt)
{
    err_type rc = OK;
    for (int i = 0; !rc && i < frames_length_dots(fr); i++)
    {
        rc = rotate_i_xy(fr, i, rt.ang_xy);
        if (!rc)
            rc = rotate_i_yz(fr, i, rt.ang_yz);
        if (!rc)
            rc = rotate_i_xz(fr, i, rt.nag_xz);
    }
    return rc;
}
