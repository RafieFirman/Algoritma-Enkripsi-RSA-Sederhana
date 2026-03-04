# Implementasi Algoritma RSA Sederhana (C++)

Program ini merupakan implementasi sederhana dari algoritma kriptografi **RSA (Rivest–Shamir–Adleman)** menggunakan bahasa **C++**.  
RSA adalah algoritma **kriptografi kunci publik (asymmetric cryptography)** yang menggunakan dua kunci berbeda yaitu:

- **Public Key (e, n)** → digunakan untuk proses enkripsi
- **Private Key (d, n)** → digunakan untuk proses dekripsi

Program ini mendemonstrasikan tiga tahap utama algoritma RSA yaitu:
1. Key Generation (Pembangkitan Kunci)
2. Enkripsi
3. Dekripsi

## Video Demonstrasi

[Klik di sini untuk melihat video demonstrasi program](https://youtu.be/xxxxxxxx)
---

# 1. Key Generation (Pembangkitan Kunci)

Tahap ini digunakan untuk menghasilkan **public key** dan **private key**.

## a. Memilih dua bilangan prima
## b. Menghitung modulus
Nilai modulus dihitung menggunakan rumus: n = p × q
## c. Menghitung fungsi totient Euler
Nilai totient Euler dihitung menggunakan rumus: φ(n) = (p − 1)(q − 1)
## d. Memilih eksponen publik
Program meminta pengguna memasukkan nilai **e** sebagai **public exponent**.
Syarat nilai e:
- 1 < e < φ(n)
- gcd(e, φ(n)) = 1
## e. Menghitung eksponen privat
rumus = d × e ≡ 1 (mod φ(n))
## f. Membentuk pasangan kunci
Setelah semua nilai diperoleh maka terbentuk:
- Public Key : (e, n)
- Private Key : (d, n)

# Proses Enkripsi
1. Pengguna memilih menu **Enkripsi** pada program.
2. Pengguna memasukkan **plaintext** yang akan dienkripsi.
3. Setiap karakter pada plaintext dikonversi menjadi **nilai numerik menggunakan kode ASCII**.
4. Nilai numerik tersebut diproses menggunakan **public key (e, n)**.
5. Hasil proses enkripsi berupa **ciphertext dalam bentuk deretan angka** yang ditampilkan pada layar.

Ciphertext inilah yang dapat dikirimkan kepada penerima pesan.

---

# Proses Dekripsi
1. Pengguna memilih menu **Dekripsi** pada program.
2. Pengguna memasukkan **ciphertext** berupa deretan angka yang dipisahkan dengan spasi.
3. Setiap angka ciphertext diproses menggunakan **private key (d, n)**.
4. Hasil proses tersebut menghasilkan nilai numerik dari pesan asli.
5. Nilai numerik tersebut kemudian dikonversi kembali ke karakter menggunakan **kode ASCII**.

Setelah proses ini selesai, pesan asli akan ditampilkan kembali sebagai **plaintext**.

# Cara Menjalankan Program

Berikut langkah-langkah untuk menjalankan program RSA yang telah dibuat.

## 1. Kompilasi Program

Pastikan compiler C++ seperti **g++** sudah terpasang pada komputer.  
masukkan perintah berikut: g++ rsa.cpp -o rsa
kemudian masukkan perintah rsa.exe untuk run program


---

## 3. Memasukkan Eksponen Publik

Setelah program dijalankan, sistem akan meminta pengguna memasukkan nilai **eksponen publik (e)**.  
Nilai yang dimasukkan harus memenuhi syarat **relatif prima dengan φ(n)**.
Contoh input:

Masukkan nilai eksponen publik (e): 7

---

## 4. Menggunakan Menu Program
Setelah key generation selesai, program akan menampilkan menu:
- **1. Enkripsi** → untuk mengenkripsi plaintext menjadi ciphertext  
- **2. Dekripsi** → untuk mengembalikan ciphertext menjadi plaintext  
- **3. Keluar** → untuk menghentikan program
