#include "constants.h"
#include "structure.h"
#include "frame_transform.h"

err_type control(frame3d& fr, int tag, action act)
{
    err_type rc = OK;
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

    default:
        rc = UNKNOWN_TAG;
        break;
    }
    return rc;
}
