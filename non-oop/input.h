#ifndef INPUT_H
#define INPUT_H

#include "structure.h"
#include "constants.h"
#include <cstdio>

void free_frame(frame3d& fr);
err_type copy_frame(frame3d &fr_cop, const frame3d fr);
frame3d init_frame();
err_type create_frame(frame3d& fr, int ndots, int nsect);
err_type read_frame(frame3d& fr, FILE* f);
err_type download_frame(frame3d& fr, input_act act);

#endif // INPUT_H
