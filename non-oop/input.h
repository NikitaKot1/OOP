#ifndef INPUT_H
#define INPUT_H

#include "structure.h"
#include "constants.h"
#include <cstdio>

void free_frame(frame3d& fr);
err_type init_frame(frame3d& fr, int ndots, int nsect);
err_type copy_frame(frame3d &fr_cop, const frame3d fr);
err_type input_frame(frame3d& fr, FILE* f);

#endif // INPUT_H
