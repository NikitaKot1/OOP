#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <QGraphicsScene>

struct dot3d{
    double x;
    double y;
    double z;
};

struct section{
    int start;
    int end;
};

struct frame3d{
    int ndots;
    dot3d *dots;
    int nsect;
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

struct action{
    transf_act tr;
    scalse_act sc;
    rotate_act rt;
};

/***********************************/

typedef QGraphicsScene scenet_t;

#endif // STRUCTURE_H
