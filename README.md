# Implementasi Algoritma Kriptografi RSA (C++)

## 1. Penjelasan Program


Program ini merupakan implementasi sederhana dari algoritma kriptografi **RSA** yang digunakan untuk:

- Membuat pasangan kunci RSA (*public key* dan *private key*)
- Mengenkripsi pesan (*plaintext*) menjadi *ciphertext*
- Mendekripsi *ciphertext* kembali menjadi *plaintext*

Kunci yang dihasilkan:
- **Public Key** $(e, n)$ → digunakan untuk proses enkripsi
- **Private Key** $(d, n)$ → digunakan untuk proses dekripsi

## Video Demonstrasi

[![Video Demo Program](https://img.youtube.com/vi/VIDEO_ID/0.jpg)](https://youtu.be/VIDEO_ID)

---

## 2. Alur Program

Alur kerja program secara umum:

1. Program menentukan dua bilangan prima $p$ dan $q$.
2. Program menghitung:
   - $n = p \times q$
   - $\phi = (p - 1)(q - 1)$
3. Pengguna memasukkan nilai **eksponen publik** $(e)$.
4. Program menghitung **eksponen privat** $(d)$.
5. Program menampilkan pasangan kunci:
   - Public Key $(e, n)$
   - Private Key $(d, n)$
6. Program menampilkan menu:
   - **1 → Enkripsi**
   - **2 → Dekripsi**
   - **3 → Keluar**
7. Jika memilih **enkripsi**, pengguna memasukkan *plaintext* dan program menghasilkan *ciphertext*.
8. Jika memilih **dekripsi**, pengguna memasukkan *ciphertext* dan program mengubahnya kembali menjadi *plaintext*.

---

## 3. Cara Menjalankan Program

### a. Kompilasi Program
Pastikan compiler C++ (`g++`) sudah terpasang di sistem kamu, kemudian jalankan perintah berikut di terminal:

```bash
g++ rsa.cpp -o rsa
rsa.exe

contoh hasil run:
Masukkan nilai eksponen publik (e): 7
Public Key  (e, n) : (7, 391)
Private Key (d, n) : (151, 391)

Pilih menu: 1
Masukkan plaintext: .....

Pilih menu: 2
Masukkan ciphertext: [masukkan deretan angka dari hasil enkripsi]
