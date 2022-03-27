#ifndef OUTPUT_H
#define OUTPUT_H

#include "structure.h"
#include "constants.h"

err_type drawFr(scenet_t &sc, frame3d fr);
void printMessage(err_type rc);
void drawLine(scenet_t &sc, dot3d d1, dot3d d2);

#endif // OUTPUT_H
