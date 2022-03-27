#include "constants.h"
#include "frame.h"
#include "structure.h"

size_t frames_length_dots(frame3d fr)
{
    return fr.ndots;
}

size_t frames_length_sects(frame3d fr)
{
    return fr.nsect;
}

bool is_empty(frame3d fr)
{
    return fr.ndots == 0 || fr.nsect == 0;
}
