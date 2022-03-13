#include "constants.h"
#include "structure.h"
#include "frame_transform.h"
#include "mainwindow.h"
#include "frame_funcs.h"
#include "output.h"

#include "cmath"

void control(frame3d& fr, int tag, action act, scenet_t *sc, err_type rc)
{
    if (rc != OK)
    {
        printMessage(rc);
        return;
    }
    switch (tag) {
    case TRANSFERE:
        rc = transfer(fr, act.tr);
        if (!rc)
            drawFr(fr, sc);
        else
            printMessage(rc);
        break;

    case SCALE:
        rc = scale(fr, act.sc);
        if (!rc)
            drawFr(fr, sc);
        else
            printMessage(rc);
        break;

    case ROTATE:
        rc = rotate(fr, act.rt);
        if (!rc)
            drawFr(fr, sc);
        else
            printMessage(rc);
        break;

    case PRINT:
        if (!rc)
            drawFr(fr, sc);
        else
            printMessage(rc);
        break;

    default:
        rc = UNKNOWN_TAG;
        printMessage(rc);
        break;
    }
}
