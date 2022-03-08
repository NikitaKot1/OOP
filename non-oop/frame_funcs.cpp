#include "constants.h"
#include "frame.h"
#include "structure.h"

int frames_length(frame3d& fr)
{
    return fr.leng;
}

double* frames_i_x(frame3d& fr, int i, bool start=true)
{
    if (i >= 0 && i < fr.leng)
    {
        if (start)
            return &(fr.mass[i].start->x);
        else
            return &(fr.mass[i].end->x);
    }
    return nullptr;
}

double* frames_i_y(frame3d& fr, int i, bool start=true)
{
    if (i >= 0 && i < fr.leng)
    {
        if (start)
            return &(fr.mass[i].start->y);
        else
            return &(fr.mass[i].end->y);
    }
    return nullptr;
}

double* frames_i_z(frame3d& fr, int i, bool start=true)
{
    if (i >= 0 && i < fr.leng)
    {
        if (start)
            return &(fr.mass[i].start->z);
        else
            return &(fr.mass[i].end->z);
    }
    return nullptr;
}

err_type set_i_dot_x(frame3d& fr, int i, double x, bool start=true)
{
    if (i >= 0 && i < fr.leng)
    {
        if (start)
            fr.mass[i].start->x = x;
        else
            fr.mass[i].end->x = x;
        return OK;
    }
    return FRAME_I_ERR;
}

err_type set_i_dot_y(frame3d& fr, int i, double y, bool start=true)
{
    if (i >= 0 && i < fr.leng)
    {
        if (start)
            fr.mass[i].start->y = y;
        else
            fr.mass[i].end->y = y;
        return OK;
    }
    return FRAME_I_ERR;
}

err_type set_i_dot_z(frame3d& fr, int i, double z, bool start=true)
{
    if (i >= 0 && i < fr.leng)
    {
        if (start)
            fr.mass[i].start->z = z;
        else
            fr.mass[i].end->z = z;
        return OK;
    }
    return FRAME_I_ERR;
}
