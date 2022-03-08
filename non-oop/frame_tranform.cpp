#include "constants.h"
#include "structure.h"
#include "frame_funcs.h"

#include <cmath>

err_type transfer_i_x(frame3d& fr, int i, double dx)
{
    err_type rc = OK;
    double x;
    if (frames_i_x(fr, i, true) != nullptr)
    {
        x = *frames_i_x(fr, i, true);
        rc = set_i_dot_x(fr, i, x + dx, true);
    }
    if (!rc && frames_i_x(fr, i, false) != nullptr)
    {
        x = *frames_i_x(fr, i, false);
        rc = set_i_dot_x(fr, i, x + dx, false);
    }
    return rc;
}

err_type transfer_i_y(frame3d& fr, int i, double dy)
{
    err_type rc = OK;
    double y;
    if (frames_i_y(fr, i, true) != nullptr)
    {
        y = *frames_i_y(fr, i, true);
        rc = set_i_dot_y(fr, i, y + dy, true);
    }
    if (!rc && frames_i_y(fr, i, false) != nullptr)
    {
        y = *frames_i_y(fr, i, false);
        rc = set_i_dot_y(fr, i, y + dy, false);
    }
    return rc;
}

err_type transfer_i_z(frame3d& fr, int i, double dz)
{
    err_type rc = OK;
    double z;
    if (frames_i_z(fr, i, true) != nullptr)
    {
        z = *frames_i_z(fr, i, true);
        rc = set_i_dot_z(fr, i, z + dz, true);
    }
    if (!rc && frames_i_z(fr, i, false) != nullptr)
    {
        z = *frames_i_z(fr, i, false);
        rc = set_i_dot_z(fr, i, z + dz, false);
    }
    return rc;
}

err_type transfer(frame3d& fr, transf_act tr)
{
    err_type rc = OK;
    for (int i = 0; i < fr.leng && !rc; i++)
    {
        rc = transfer_i_x(fr, i, tr.dx);
        if (!rc)
            rc = transfer_i_y(fr, i, tr.dy);
        if (!rc)
            rc = transfer_i_z(fr, i, tr.dz);
    }
    return rc;
}

err_type scale_i_x(frame3d& fr, int i, double kx)
{
    err_type rc = OK;
    double x;
    if (frames_i_x(fr, i, true) != nullptr)
    {
        x = *frames_i_x(fr, i, true);
        rc = set_i_dot_x(fr, i, x * kx, true);
    }
    if (!rc && frames_i_x(fr, i, false) != nullptr)
    {
        x = *frames_i_x(fr, i, false);
        rc = set_i_dot_x(fr, i, x * kx, false);
    }
    return rc;
}

err_type scale_i_y(frame3d& fr, int i, double ky)
{
    err_type rc = OK;
    double y;
    if (frames_i_y(fr, i, true) != nullptr)
    {
        y = *frames_i_y(fr, i, true);
        rc = set_i_dot_y(fr, i, y * ky, true);
    }
    if (!rc && frames_i_y(fr, i, false) != nullptr)
    {
        y = *frames_i_y(fr, i, false);
        rc = set_i_dot_y(fr, i, y * ky, false);
    }
    return rc;
}

err_type scale_i_z(frame3d& fr, int i, double kz)
{
    err_type rc = OK;
    double z;
    if (frames_i_z(fr, i, true) != nullptr)
    {
        z = *frames_i_z(fr, i, true);
        rc = set_i_dot_z(fr, i, z * kz, true);
    }
    if (!rc && frames_i_z(fr, i, false) != nullptr)
    {
        z = *frames_i_z(fr, i, false);
        rc = set_i_dot_z(fr, i, z * kz, false);
    }
    return rc;
}

err_type scale(frame3d& fr, scalse_act sc)
{
    err_type rc = OK;
    for (int i = 0; i < fr.leng && !rc; i++)
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
    if (frames_i_x(fr, i, true) != nullptr && frames_i_y(fr, i, true) != nullptr)
    {
        x = *frames_i_x(fr, i, true);
        y = *frames_i_y(fr, i, true);
        rotate_0xy(x, y, ang);
        rc = set_i_dot_x(fr, i, x, true);
        if (!rc)
            rc = set_i_dot_y(fr, i, y, true);
    }
    else
        rc = NULLPTR_COORD;
    if (!rc && frames_i_x(fr, i, false) != nullptr && frames_i_y(fr, i, true) != nullptr)
    {
        x = *frames_i_x(fr, i, false);
        y = *frames_i_y(fr, i, false);
        rotate_0xy(x, y, ang);
        rc = set_i_dot_x(fr, i, x, false);
        if (!rc)
            rc = set_i_dot_y(fr, i, y, false);
    }
    else if (!rc)
        rc = NULLPTR_COORD;
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
    if (frames_i_z(fr, i, true) != nullptr && frames_i_y(fr, i, true) != nullptr)
    {
        z = *frames_i_z(fr, i, true);
        y = *frames_i_y(fr, i, true);
        rotate_0yz(y, z, ang);
        rc = set_i_dot_z(fr, i, z, true);
        if (!rc)
            rc = set_i_dot_y(fr, i, y, true);
    }
    else
        rc = NULLPTR_COORD;
    if (!rc && frames_i_y(fr, i, false) != nullptr && frames_i_z(fr, i, false) != nullptr)
    {
        z = *frames_i_z(fr, i, false);
        y = *frames_i_y(fr, i, false);
        rotate_0yz(y, z, ang);
        rc = set_i_dot_z(fr, i, z, false);
        if (!rc)
            rc = set_i_dot_y(fr, i, y, false);
    }
    else if (!rc)
        rc = NULLPTR_COORD;
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
    if (frames_i_x(fr, i, true) != nullptr && frames_i_z(fr, i, true) != nullptr)
    {
        x = *frames_i_x(fr, i, true);
        z = *frames_i_z(fr, i, true);
        rotate_0xz(x, z, ang);
        rc = set_i_dot_z(fr, i, z, true);
        if (!rc)
            rc = set_i_dot_x(fr, i, x, true);
    }
    else
        rc = NULLPTR_COORD;
    if (!rc && frames_i_x(fr, i, false) != nullptr && frames_i_z(fr, i, false) != nullptr)
    {
        z = *frames_i_z(fr, i, false);
        x = *frames_i_x(fr, i, false);
        rotate_0xz(x, z, ang);
        rc = set_i_dot_z(fr, i, z, false);
        if (!rc)
            rc = set_i_dot_x(fr, i, x, false);
    }
    else if (!rc)
        rc = NULLPTR_COORD;
    return rc;
}


err_type rotate(frame3d& fr, rotate_act rt)
{
    err_type rc = OK;
    for (int i = 0; i < fr.leng && !rc; i++)
    {
        rc = rotate_i_xy(fr, i, rt.ang_xy);
        if (!rc)
            rc = rotate_i_yz(fr, i, rt.ang_yz);
        if (!rc)
            rc = rotate_i_xz(fr, i, rt.nag_xz);
    }
    return rc;
}
