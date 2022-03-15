#include "constants.h"
#include "structure.h"
#include "frame_transform.h"
#include "mainwindow.h"
#include "frame_funcs.h"
#include "output.h"
#include "input.h"

#include "cmath"

extern std::string fileName;
frame3d fr;

err_type control(scenet_t &sc, int tag, action act)
{
    err_type rc = OK;
    frame3d fr_cop;
    rc = copy_frame(fr_cop, fr);
    if (rc != OK)
        return rc;
    switch (tag) {
    case TRANSFERE:
        rc = transfer(fr_cop, act.tr);
        break;

    case SCALE:
        rc = scale(fr_cop, act.sc);
        break;

    case ROTATE:
        rc = rotate(fr_cop, act.rt);
        break;

    case PRINT:
    {
        FILE* f = fopen(fileName.c_str(), "r");
        if (!f)
            rc = FILE_OPEN_ERR;
        else
        {
            if (frames_length_dots(fr_cop) != 0)
                free_frame(fr_cop);
            rc = input_frame(fr_cop, f);
        }

        break;
    }

    default:
        rc = UNKNOWN_TAG;
        break;
    }
    if (rc == OK)
    {
        free_frame(fr);
        fr = fr_cop;
        drawFr(sc, fr);
    }
    return rc;
}
