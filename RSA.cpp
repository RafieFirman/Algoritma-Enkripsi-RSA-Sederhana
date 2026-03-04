#include <iostream>
using namespace std;

/*
Digunakan untuk mengecek
gcd(e, φ(n)) = 1
Jika hasilnya 1 maka e relatif prima dengan φ(n)
*/
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

/*
Digunakan untuk mencari nilai d (eksponen privat)

Rumus RSA:
(d × e) mod φ(n) = 1
*/
long long modInverse(long long e, long long phi_n) {

    long long t = 0, newt = 1;
    long long r = phi_n, newr = e;

    while (newr != 0) {
        long long q = r / newr;
        long long temp = newt;
        newt = t - q * newt;
        t = temp;
        temp = newr;
        newr = r - q * newr;
        r = temp;
    }

    if (r > 1) return -1;
    if (t < 0)
        t += phi_n;

    return t;
}

/*
Digunakan untuk menghitung enkripsi dan dekripsi

Enkripsi  : c = m^e mod n
Dekripsi  : m = c^d mod n
*/
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int main() {
    // p dan q = bilangan prima
    long long p = 23;
    long long q = 17;

    // n = p × q
    long long n = p * q;

    // φ(n) = (p-1)(q-1)
    long long phi_n = (p - 1) * (q - 1);

    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "n = p × q = " << n << endl;
    cout << "phi(n) = " << phi_n << endl;

    // input eksponen publik
    long long e;
    cout << "\nMasukkan nilai eksponen publik (e): ";
    cin >> e;

    // cek gcd(e, φ(n)) = 1
    if (gcd(e, phi_n) != 1) {
        cout << "Nilai e tidak relatif prima dengan phi(n)\n";
        return 0;
    }

    // mencari d (eksponen privat)
    long long d = modInverse(e, phi_n);

    cout << "\nPublic Key  (e,n) : (" << e << "," << n << ")";
    cout << "\nPrivate Key (d,n) : (" << d << "," << n << ")\n";

    cin.ignore();

    while (true) {

        cout << "1. Enkripsi\n";
        cout << "2. Dekripsi\n";
        cout << "3. Keluar\n";
        cout << "Pilih :";

        int menu;
        cin >> menu;
        cin.ignore();

        if (menu == 1) {

            string plaintext;
            cout << "\nMasukkan plaintext: ";
            getline(cin, plaintext);

            cout << "\nCiphertext:\n";
            for (int i = 0; i < plaintext.length(); i++) {
                long long m = (int)plaintext[i];
                long long c = modExp(m, e, n);
                cout << c << " ";
            }

        }

        else if (menu == 2) {
            string input;
            long long cipher[100];
            int index = 0;

            cout << "\nMasukkan ciphertext: ";
            getline(cin, input);

            long long angka = 0;
            for (int i = 0; i <= input.length(); i++) {
                if (input[i] == ' ' || input[i] == '\0') {
                    cipher[index++] = angka;
                    angka = 0;
                }
                else {
                    angka = angka * 10 + (input[i] - '0');
                }
            }

            cout << "\nHasil Dekripsi:\n";
            for (int i = 0; i < index; i++) {
                long long m = modExp(cipher[i], d, n);

                cout << (char)m;
            }
            cout << endl;
        }
        else if (menu == 3) {
            break;
        }
    }
    return 0;
}