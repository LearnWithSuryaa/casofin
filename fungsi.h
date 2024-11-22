#ifndef FUNGSI_H
#define FUNGSI_H

// Fungsi untuk membersihkan input buffer
void clearInputBuffer();

// Fungsi untuk mendapatkan lebar terminal
int getTerminalWidth();

// Fungsi untuk menu utama
void menuUtama();

// Fungsi untuk memasukkan nilai amplitudo
void inputanAmplitudo(int *amplitude);

// Fungsi untuk memasukkan panjang gelombang
void inputanLength(int *length);

// Fungsi untuk menghitung padding agar gelombang terpusat
int calculatePadding(int terminalWidth, int length);

// Fungsi untuk mencetak padding
void printPadding(int padding);

// Fungsi untuk memilih tipe gelombang (sinus atau kosinus)
void pilihTipeGelombang(int *tipeGelombang);

// Fungsi untuk menggambar gelombang berdasarkan tipe
void drawWave(int amplitude, int length, int terminalWidth, int tipeGelombang);

// Fungsi untuk menyimpan koordinat gelombang ke dalam file
void simpanKeFile(int amplitude, int length, int tipeGelombang);

#endif
