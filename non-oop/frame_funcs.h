#ifndef FRAME_FUNCS_H
#define FRAME_FUNCS_H

#include "structure.h"
#include "constants.h"

int frames_length(frame3d& fr);
double* frames_i_x(frame3d& fr, int i, bool start=true);
double* frames_i_y(frame3d& fr, int i, bool start=true);
double* frames_i_z(frame3d& fr, int i, bool start=true);
err_type set_i_dot_x(frame3d& fr, int i, double x, bool start=true);
err_type set_i_dot_y(frame3d& fr, int i, double y, bool start=true);
err_type set_i_dot_z(frame3d& fr, int i, double z, bool start=true);


#endif // FRAME_FUNCS_H
