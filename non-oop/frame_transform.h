#ifndef FRAME_TRANSFORM_H
#define FRAME_TRANSFORM_H

#include "structure.h"
#include "constants.h"

err_type transfer(frame3d& fr, transf_act tr);
err_type scale(frame3d& fr, scalse_act sc);
err_type rotate(frame3d& fr, rotate_act rt);

#endif // FRAME_TRANSFORM_H
