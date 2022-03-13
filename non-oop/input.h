#ifndef INPUT_H
#define INPUT_H

#include "structure.h"
#include "constants.h"
#include <cstdio>

err_type input_frame(FILE* f, frame3d& fr);
err_type input_sect(section3d& sect, FILE* f);
err_type input_dot(dot3d* dot1, FILE* f);
void free_frame(frame3d& fr);
int col_of_sections(FILE* f);

#endif // INPUT_H
