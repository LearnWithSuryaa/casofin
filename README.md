# 🎨 Program Visualisasi Gelombang Sinusoidal

Program ini dirancang untuk membantu mahasiswa memahami konsep **gelombang sinusoidal** dengan cara visual yang interaktif. Dengan program ini, Anda dapat:
- Menginput nilai **amplitudo** dan **panjang gelombang**.
- Memilih tipe gelombang: **Sinus** atau **Kosinus**.
- Melihat grafik gelombang sinusoidal atau kosinus langsung di terminal.
- Mengetahui koordinat `(x, y)` untuk setiap titik gelombang.
- Menyimpan data koordinat dan grafik ke dalam file.

---

## ✨ Fitur

✅ **Validasi Input**: Memastikan input berupa bilangan bulat positif.  
✅ **Visualisasi Gelombang**: Menampilkan grafik gelombang sinusoidal atau kosinus di terminal.  
✅ **Titik Koordinat**: Menampilkan daftar koordinat `(x, y)` setiap titik dalam satu panjang gelombang.  
✅ **Penyimpanan File**: Menyimpan koordinat dan grafik gelombang ke dalam file (misalnya, `data.csv` atau `grafik.txt`).  
✅ **Pilihan Tipe Gelombang**: Memilih antara gelombang **Sinus** atau **Kosinus** untuk divisualisasikan dan disimpan.

---

## ⚙️ Cara Penggunaan

### Persiapan Awal
Pastikan Anda memiliki:
- Compiler **GCC** terpasang di sistem Anda.
- File berikut:
  - `main.c`
  - `fungsi.c`
  - `fungsi.h`
  - `Makefile`

### Langkah-Langkah

#### Clone atau download repositori ini ke komputer Anda:

   ```bash
   git clone https://github.com/LearnWithSuryaa/casofin
   cd casofin
   ```

#### 1️⃣ Kompilasi Program
Jalankan perintah berikut pada terminal untuk mengompilasi program:
```bash
make
```
> 💡 **Catatan**:  
> Perintah ini akan:
> - Mengompilasi file `.c` menjadi file `.o`.
> - Menghasilkan file eksekusi bernama `surya`.

#### 2️⃣ Menjalankan Program
Setelah kompilasi selesai, jalankan program menggunakan perintah:
```bash
make run
```
Program akan meminta Anda untuk memasukkan:
1. **Amplitudo**: Nilai bilangan bulat positif (> 0).  
2. **Panjang Gelombang**: Nilai bilangan bulat positif (> 0).
3. **Tipe Gelombang**: Memilih antara **Sinus** atau **Kosinus**.

Setelah input diterima, program akan:
- Menampilkan **grafik gelombang sinusoidal atau kosinus**.
- Menampilkan daftar **koordinat titik `(x, y)`**.
- Memberikan pilihan untuk **menyimpan data koordinat dan grafik** ke dalam file.

#### 3️⃣ Menyimpan Koordinat dan Grafik ke File
Setelah gelombang ditampilkan, Anda dapat memilih untuk menyimpan koordinat dan grafik ke dalam file. Program akan menanyakan nama file yang ingin digunakan (misalnya `grafik.txt` atau `data.csv`).

#### 4️⃣ Membersihkan File
Untuk membersihkan file yang dihasilkan seperti file object (`.o`) dan file eksekusi (`surya`), gunakan perintah:
```bash
make clean
```

---

## 📋 Contoh Output Program

### Input:
```
Masukkan nilai amplitudo (lebih dari 0): 5
Masukkan panjang gelombang (LENGTH): 20
Pilih tipe gelombang:
1. Sinus
2. Kosinus
Pilihan Anda: 1
```

### Output:
#### Grafik Gelombang (Sinus):
```
Grafik Gelombang Sinusoidal:

     S        S        
    S  S     S  S      
   S    S   S    S     
  S      S S      S    
 S        S        S   
-----------------------
 S        S        S   
  S      S S      S    
   S    S   S    S     
    S  S     S  S      
     S        S        
```

#### Koordinat `(x, y)`:
```
Titik Koordinat (x, y):

x = 0   | y = 0.00
x = 1   | y = 1.47
x = 2   | y = 2.85
...
x = 20  | y = 0.00
```

### Menyimpan ke File:
```
Masukkan nama file untuk menyimpan data (contoh: grafik.txt): data.csv

Data berhasil disimpan ke file: data.csv
```

---

## ✍️ Penulis

Program ini dibuat oleh:  
- [Suryahipersomniaa](https://www.instagram.com/suryahipersomniaa/)  
- [Satriya_dm](https://www.instagram.com/satriya_dm/)

---

## 📝 Lisensi

Program ini dilisensikan di bawah [MIT License](LICENSE), sehingga Anda bebas menggunakan untuk tujuan pembelajaran dan penelitian. 🚀