#ifndef DOT_FUNCS_H
#define DOT_FUNCS_H

#include <structure.h>

dot3d &get_dot(frame3d fr, const size_t i);
double get_dots_x(dot3d d);
double get_dots_y(dot3d d);
double get_dots_z(dot3d d);
void set_dots_x(dot3d &d, const double x);
void set_dots_y(dot3d &d, const double y);
void set_dots_z(dot3d &d, const double z);
void copy_dot(dot3d& d_cop, const dot3d d);

section &get_sect(frame3d fr, const size_t i);
size_t get_start_sect(section sc);
size_t get_end_sect(section sc);
void set_start_sect(section& sc, const size_t start);
void set_end_sect(section& sc, const size_t end);
void copy_sect(section& sc_cop, const section sc);

#endif // DOT_FUNCS_H
