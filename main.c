#include <stdio.h>
#include "fungsi.h"

int main()
{
    int amplitude, length;
    const int terminalWidth = 80; 

    inputanAmplitudo(&amplitude);
    inputanLength(&length);

    drawSinWave(amplitude, length, terminalWidth);
    printCoordinates(length, amplitude);

    return 0;
}
