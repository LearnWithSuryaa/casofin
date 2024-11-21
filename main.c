#include <stdio.h>
#include "fungsi.h"

int main()
{
    int amplitude, length;

    inputanAmplitudo(&amplitude);

    inputanLenght(&length);

    drawSinWave(amplitude, length);
    printf("\n");
    printCoordinates(length, amplitude);

    return 0;
}
