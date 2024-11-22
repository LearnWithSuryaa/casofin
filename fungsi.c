#include <stdio.h>
#include <math.h>
#include <sys/ioctl.h>
#include <unistd.h>
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

int getTerminalWidth()
{
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1)
    {
        // Jika gagal membaca ukuran terminal, gunakan nilai default
        return 80;
    }
    return w.ws_col;
}


void menuUtama()
{
    int pilihan;
    int amplitude = 1;
    int length = 1;
    int terminalWidth = getTerminalWidth(); // Dapatkan lebar terminal secara dinamis
    int tipeGelombang = 1;  // Default: Gelombang sinus

    while (1)
    {
        printf("\n========= Menu Utama =========\n");
        printf("1. Masukkan Amplitudo\n");
        printf("2. Masukkan Panjang Gelombang\n");
        printf("3. Pilih Tipe Gelombang (Sinus/Kosinus)\n");
        printf("4. Tampilkan Gelombang\n");
        printf("5. Simpan Koordinat ke File\n");
        printf("6. Keluar\n");
        printf("Pilihan Anda: ");
        
        if (scanf("%d", &pilihan) != 1)
        {
            printf(RED "\nInput tidak valid. Masukkan angka!\n" RESET);
            clearInputBuffer();
            continue;
        }

        switch (pilihan)
        {
        case 1:
            inputanAmplitudo(&amplitude);
            break;
        case 2:
            inputanLength(&length);
            break;
        case 3:
            pilihTipeGelombang(&tipeGelombang);
            break;
        case 4:
            drawWave(amplitude, length, terminalWidth, tipeGelombang);
            break;
        case 5:
            simpanKeFile(amplitude, length, tipeGelombang);
            break;
        case 6:
            printf(GREEN "\nTerima kasih telah menggunakan program ini!\n" RESET);
            return;
        default:
            printf(RED "\nPilihan tidak valid. Silakan coba lagi.\n" RESET);
        }
    }
}

void inputanAmplitudo(int *amplitude)
{
    while (1)
    {
        printf("Masukkan nilai amplitudo (lebih dari 0): ");
        if (scanf("%d", amplitude) != 1)
        {
            printf(RED "\nInputan tidak valid. Mohon masukkan angka!\n" RESET);
            clearInputBuffer();
            continue;
        }

        if (*amplitude > 0)
        {
            printf(GREEN "\nAmplitudo yang dimasukkan adalah: %d\n" RESET, *amplitude);
            break;
        }
        else
        {
            printf(RED "\nAmplitudo harus lebih besar dari 0. Silakan coba lagi.\n" RESET);
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
            printf(RED "\nInputan tidak valid. Mohon masukkan angka!\n" RESET);
            clearInputBuffer();
            continue;
        }

        if (*length > 0)
        {
            printf(GREEN "\nPanjang gelombang yang dimasukkan adalah: %d\n" RESET, *length);
            break;
        }
        else
        {
            printf(RED "\nPanjang gelombang harus lebih besar dari 0. Silakan coba lagi.\n" RESET);
        }
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

void pilihTipeGelombang(int *tipeGelombang)
{
    printf("\nPilih tipe gelombang:\n");
    printf("1. Sinus\n");
    printf("2. Kosinus\n");
    printf("Pilihan Anda: ");
    
    if (scanf("%d", tipeGelombang) != 1 || (*tipeGelombang != 1 && *tipeGelombang != 2))
    {
        printf(RED "\nInput tidak valid. Pilihan default adalah Sinus.\n" RESET);
        *tipeGelombang = 1;
        clearInputBuffer();
    }
    else
    {
        printf(GREEN "\nTipe gelombang berhasil diubah.\n" RESET);
    }
}

void drawWave(int amplitude, int length, int terminalWidth, int tipeGelombang)
{
    printf("Grafik Gelombang:\n\n");

    int sinWave[length + 1];
    for (int x = 0; x <= length; x++)
    {
        double radians = (2 * PI * x) / length;
        double value = (tipeGelombang == 1) ? sin(radians) : cos(radians);
        sinWave[x] = (int)(amplitude * value + amplitude);
    }

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

void simpanKeFile(int amplitude, int length, int tipeGelombang)
{
    char filename[100];
    printf("Masukkan nama file untuk menyimpan data (contoh: grafik.txt): ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf(RED "\nGagal membuat file. Pastikan nama file valid.\n" RESET);
        return;
    }

    // Menentukan nama gelombang
    const char *namaGelombang = (tipeGelombang == 1) ? "Sinus" : "Kosinus";

    // Header untuk data koordinat
    fprintf(file, "x   |   y (%s)\n", namaGelombang);
    fprintf(file, "----|------------\n");

    int sinWave[length + 1];

    // Simpan koordinat dan hitung nilai y
    for (int x = 0; x <= length; x++)
    {
        double radians = (2 * PI * x) / length;
        double value = (tipeGelombang == 1) ? sin(radians) : cos(radians);
        sinWave[x] = (int)(amplitude * value + amplitude); // Posisi y untuk grafik
        fprintf(file, "%-3d | %10.2f\n", x, amplitude * value);
    }

    // Header untuk grafik
    fprintf(file, "\nGrafik Gelombang (%s):\n\n", namaGelombang);

    // Simpan grafik ASCII
    for (int y = 2 * amplitude; y >= 0; y--)
    {
        for (int x = 0; x <= length; x++)
        {
            if (sinWave[x] == y)
            {
                fprintf(file, "S"); // Titik gelombang
            }
            else if (y == amplitude)
            {
                fprintf(file, "-"); // Sumbu x
            }
            else
            {
                fprintf(file, " "); // Spasi kosong
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf(GREEN "\nData koordinat dan grafik berhasil disimpan ke file: %s\n" RESET, filename);
}
