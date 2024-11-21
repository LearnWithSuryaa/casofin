#ifndef FUNGSI_H
#define FUNGSI_H

void clearInputBuffer();
void inputanAmplitudo(int *amplitude);
void inputanLength(int *length);
void calculateSinWave(int amplitude, int length, int sinWave[]);
int calculatePadding(int terminalWidth, int length);
void printPadding(int padding);
void drawSinWave(int amplitude, int length, int terminalWidth);
void printCoordinates(int length, int amplitude);

#endif