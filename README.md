
# 🎨 Program Visualisasi Gelombang Sinusoidal

Program ini dirancang untuk membantu mahasiswa memahami konsep **gelombang sinusoidal** dengan cara visual yang interaktif. Dengan program ini, Anda dapat:
- Menginput nilai **amplitudo** dan **panjang gelombang**.
- Melihat grafik gelombang sinusoidal di terminal.
- Mengetahui koordinat `(x, y)` untuk setiap titik gelombang.

---

## ✨ Fitur

✅ **Validasi Input**: Memastikan input berupa bilangan bulat positif.  
✅ **Visualisasi Gelombang**: Menampilkan grafik sinusoidal langsung di terminal.  
✅ **Titik Koordinat**: Menampilkan daftar koordinat `(x, y)` setiap titik dalam satu panjang gelombang.

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

Setelah input diterima, program akan:
- Menampilkan **grafik gelombang sinusoidal**.
- Menampilkan daftar **koordinat titik `(x, y)`**.

#### 3️⃣ Membersihkan File
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
```

### Output:
#### Grafik Gelombang:
```
Grafik Sinusoidal:

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

---

## ✍️ Penulis

Program ini dibuat oleh:  
- [Suryahipersomniaa](https://www.instagram.com/suryahipersomniaa/)  
- [Satriya_dm](https://www.instagram.com/satriya_dm/)

---

## 📝 Lisensi

Program ini dilisensikan di bawah [MIT License](LICENSE), sehingga Anda bebas menggunakan untuk tujuan pembelajaran dan penelitian. 🚀
