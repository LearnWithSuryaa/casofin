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

void inputanLenght(int *length)
{
    while (1)
    {
        printf("Masukkan panjang gelombang (LENGTH): ");
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
            printf(RED "\nPanjang gelombang harus lebih besar dari 0. Silakan coba lagi.\n\ns" RESET);
        }
    }
}

void drawSinWave(int amplitude, int length)
{
    printf("Grafik Sinusoidal:\n\n");

    int sinWave[length + 1];

    for (int x = 0; x <= length; x++)
    {
        double radians = (2 * PI * x) / length;
        double sinValue = amplitude * sin(radians);

        sinWave[x] = (int)(sinValue + amplitude);
    }

    for (int y = 2 * amplitude; y >= 0; y--)
    {
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

        double y = sinValue;

        printf("x = %-3d | y = %.2f\n", x, y);
    }
}