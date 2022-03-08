#include "structure.h"
#include "constants.h"
/*
 Observer plane: z = 0
*/

void normalaize(frame3d& fr)
{
    double min = (fr.mass[0]).start->z;
    for (int i = 0; i < fr.leng; i++)
    {
        if (min > fr.mass[i].start->z)
            min = fr.mass[i].start->z;
        if (min > fr.mass[i].end->z)
            min = fr.mass[i].end->z;
    }
    for (int i = 0; i < fr.leng; i++)
    {
        fr.mass[i].start->z -= min;
        fr.mass[i].end->z -= min;

        fr.mass[i].start->z += 1;
        fr.mass[i].end->z += 1;
    }
}
