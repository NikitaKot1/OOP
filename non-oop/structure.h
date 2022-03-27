#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <QGraphicsScene>

struct dot3d{
    double x;
    double y;
    double z;
};

struct section{
    size_t start;
    size_t end;
};

struct frame3d{
    size_t ndots;
    dot3d *dots;
    size_t nsect;
    section *sects;
};

/*********************************/

struct transf_act{
    double dx;
    double dy;
    double dz;
};

struct scalse_act{
    double kx;
    double ky;
    double kz;
};

struct rotate_act{
    double ang_xy;
    double ang_yz;
    double nag_xz;
};

struct input_act{
    const char *filename;
};

struct action{
    transf_act tr;
    scalse_act sc;
    rotate_act rt;
    input_act inp;
};

/***********************************/

typedef QGraphicsScene scenet_t;

#endif // STRUCTURE_H
