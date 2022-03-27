#include "constants.h"
#include "structure.h"
#include "frame_transform.h"
#include "mainwindow.h"
#include "frame_funcs.h"
#include "output.h"
#include "input.h"

#include "cmath"

err_type control(scenet_t &sc, int tag, action act)
{
    err_type rc = OK;
    static frame3d fr = init_frame();
    if (rc != OK)
        return rc;
    switch (tag) {
    case TRANSFERE:
        rc = transfer(fr, act.tr);
        break;

    case SCALE:
        rc = scale(fr, act.sc);
        break;

    case ROTATE:
        rc = rotate(fr, act.rt);
        break;

    case INPUT:
        rc = download_frame(fr, act.inp);
        break;

    case PRINT:
        drawFr(sc, fr);
        break;

    default:
        rc = UNKNOWN_TAG;
        break;
    }

    return rc;
}
