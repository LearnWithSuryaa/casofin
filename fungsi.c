#include <stdio.h>
#include <math.h>
#include "fungsi.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

#define PI 3.14159265

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void inputanAmplitudo(int *amplitude)
{
    while (1)
    {
        printf("Masukkan nilai amplitudo (lebih dari 0): ");
        if (scanf("%d", amplitude) != 1)
        {
            printf(RED "\nInputan tidak valid. Mohon masukkan angka!\n\n" RESET);
            clearInputBuffer();
            continue;
        }

        if (*amplitude > 0)
        {
            printf(GREEN "\nAmplitudo yang dimasukkan adalah: %d\n\n" RESET, *amplitude);
            break;
        }
        else
        {
            printf(RED "\nAmplitudo harus lebih besar dari 0. Silakan coba lagi.\n\n" RESET);
        }
    }
}

void inputanLength(int *length)
{
    while (1)
    {
        printf("Masukkan panjang gelombang (lebih dari 0): ");
        if (scanf("%d", length) != 1)
        {
            printf(RED "\nInputan tidak valid. Mohon masukkan angka!\n\n" RESET);
            clearInputBuffer();
            continue;
        }

        if (*length > 0)
        {
            printf(GREEN "\nPanjang gelombang yang dimasukkan adalah: %d\n\n" RESET, *length);
            break;
        }
        else
        {
            printf(RED "\nPanjang gelombang harus lebih besar dari 0. Silakan coba lagi.\n\n" RESET);
        }
    }
}

void calculateSinWave(int amplitude, int length, int sinWave[])
{
    for (int x = 0; x <= length; x++)
    {
        double radians = (2 * PI * x) / length;
        double sinValue = amplitude * sin(radians);
        sinWave[x] = (int)(sinValue + amplitude);
    }
}

int calculatePadding(int terminalWidth, int length)
{
    return (terminalWidth - length) / 2;
}

void printPadding(int padding)
{
    for (int p = 0; p < padding; p++)
    {
        printf(" ");
    }
}

void drawSinWave(int amplitude, int length, int terminalWidth)
{
    printf("Grafik Sinusoidal:\n\n");

    int sinWave[length + 1];
    calculateSinWave(amplitude, length, sinWave);

    int padding = calculatePadding(terminalWidth, length);

    for (int y = 2 * amplitude; y >= 0; y--)
    {
        printPadding(padding);

        for (int x = 0; x <= length; x++)
        {
            if (sinWave[x] == y)
            {
                printf("S");
            }
            else if (y == amplitude)
            {
                printf("-");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printCoordinates(int length, int amplitude)
{
    printf("\nTitik Koordinat (x, y):\n\n");

    for (int x = 0; x <= length; x++)
    {
        double radians = (2 * PI * x) / length;
        double sinValue = amplitude * sin(radians);

        printf("x = %-3d | y = %.2f\n", x, sinValue);
    }
}