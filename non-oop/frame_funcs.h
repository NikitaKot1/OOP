#ifndef FRAME_FUNCS_H
#define FRAME_FUNCS_H

#include "structure.h"
#include "constants.h"

int frames_length_dots(frame3d fr);
int frames_length_sects(frame3d fr);
err_type get_dot_i_x(double &x, const int i, const frame3d fr);
err_type get_dot_i_y(double &y, const int i, const frame3d fr);
err_type get_dot_i_z(double &z, const int i, const frame3d fr);
err_type set_i_dot_x(frame3d& fr, const int i, const double x);
err_type set_i_dot_y(frame3d& fr, const int i, const double y);
err_type set_i_dot_z(frame3d& fr, const int i, const double z);
err_type get_i_sect(int &rez1, int &rez2, const int i, const frame3d fr);

#endif // FRAME_FUNCS_H
