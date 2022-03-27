#include <structure.h>

dot3d &get_dot(frame3d fr, const size_t i)
{
    return fr.dots[i];
}

double get_dots_x(dot3d d)
{
    return d.x;
}

double get_dots_y(dot3d d)
{
    return d.y;
}

double get_dots_z(dot3d d)
{
    return d.z;
}

void set_dots_x(dot3d &d, const double x)
{
    d.x = x;
}

void set_dots_y(dot3d &d, const double y)
{
    d.y = y;
}

void set_dots_z(dot3d &d, const double z)
{
    d.z = z;
}

void copy_dot(dot3d& d_cop, const dot3d d)
{
    set_dots_x(d_cop, get_dots_x(d));
    set_dots_y(d_cop, get_dots_y(d));
    set_dots_z(d_cop, get_dots_z(d));
}


section &get_sect(frame3d fr, const size_t i)
{
    return fr.sects[i];
}

size_t get_start_sect(section sc)
{
    return sc.start;
}

size_t get_end_sect(section sc)
{
    return sc.end;
}

void set_start_sect(section& sc, const size_t start)
{
    sc.start = start;
}

void set_end_sect(section& sc, const size_t end)
{
    sc.end = end;
}

void copy_sect(section& sc_cop, const section sc)
{
    set_start_sect(sc_cop, get_start_sect(sc));
    set_end_sect(sc_cop, get_end_sect(sc));
}

