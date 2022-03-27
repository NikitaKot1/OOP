#include "constants.h"
#include "structure.h"
#include "frame_funcs.h"
#include "dot_funcs.h"
#include <cmath>

void transfer_dot(dot3d& dot, const double dx, const double dy, const double dz)
{
    double x = get_dots_x(dot) + dx;
    double y = get_dots_y(dot) + dy;
    double z = get_dots_z(dot) + dz;
    set_dots_x(dot, x);
    set_dots_y(dot, y);
    set_dots_z(dot, z);
}

void scale_dot(dot3d& dot, const double kx, const double ky, const double kz)
{
    double x = get_dots_x(dot) * kx;
    double y = get_dots_y(dot) * ky;
    double z = get_dots_z(dot) * kz;
    set_dots_x(dot, x);
    set_dots_y(dot, y);
    set_dots_z(dot, z);
}

err_type transfer(frame3d& fr, transf_act tr)
{
    if (is_empty(fr))
        return EMPTY_DOT;
    double dx = tr.dx;
    double dy = tr.dy;
    double dz = tr.dz;
    for (size_t i = 0; i < frames_length_dots(fr); i++)
        transfer_dot(get_dot(fr, i), dx, dy, dz);
    return OK;
}

err_type scale(frame3d& fr, scalse_act sc)
{
    if (is_empty(fr))
        return EMPTY_DOT;
    double kx = sc.kx;
    double ky = sc.ky;
    double kz = sc.kz;
    for (size_t i = 0; i < frames_length_dots(fr); i++)
        scale_dot(get_dot(fr, i), kx, ky, kz);
    return OK;
}

void rotate_0xy(double& x, double& y, double ang)
{
    ang = ang / 360 * 2 * M_PI;
    double xf = x * cos(ang) + y * sin(ang);
    double yf = y * cos(ang) - x * sin(ang);
    x = xf;
    y = yf;
}

void rotate_dot_xy(dot3d& dot, double ang)
{
    double x = get_dots_x(dot);
    double y = get_dots_y(dot);
    rotate_0xy(x, y, ang);
    set_dots_x(dot, x);
    set_dots_y(dot, y);
}

void rotate_0yz(double& y, double& z, double ang)
{
    ang = ang / 360 * 2 * M_PI;
    double zf = y * cos(ang) + z * sin(ang);
    double yf = z * cos(ang) - y * sin(ang);
    z = zf;
    y = yf;
}

void rotate_dot_yz(dot3d& dot, double ang)
{
    double z = get_dots_z(dot);
    double y = get_dots_y(dot);
    rotate_0yz(y, z, ang);
    set_dots_z(dot, z);
    set_dots_y(dot, y);
}

void rotate_0xz(double& x, double& z, double ang)
{
    ang = ang / 360 * 2 * M_PI;
    double xf = x * cos(ang) + z * sin(ang);
    double zf = z * cos(ang) - x * sin(ang);
    z = zf;
    x = xf;
}

void rotate_dot_xz(dot3d& dot, double ang)
{
    double x = get_dots_x(dot);
    double z = get_dots_z(dot);
    rotate_0xz(x, z, ang);
    set_dots_z(dot, z);
    set_dots_x(dot, x);
}


err_type rotate(frame3d& fr, rotate_act rt)
{
    if (is_empty(fr))
        return EMPTY_DOT;
    double axy = rt.ang_xy;
    double ayz = rt.ang_yz;
    double axz = rt.nag_xz;
    for (size_t i = 0; i < frames_length_dots(fr); i++)
    {
        rotate_dot_xy(get_dot(fr, i), axy);
        rotate_dot_yz(get_dot(fr, i), ayz);
        rotate_dot_xz(get_dot(fr, i), axz);
    }
    return OK;
}
