#include <iostream>
using namespace std;

void balikArray(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + n - i - 1);
        *(arr + n - i - 1) = temp;
    }
}

void soal1() {
    cout << "\n=== SOAL 1: Array + Pointer ===\n";
    const int n = 7;
    int arr[n];
    int kelipatan = 3;

    for (int i = 0; i < n; i++) {
        arr[i] = kelipatan;
        kelipatan += 3;
    }

    cout << "Sebelum dibalik: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    balikArray(arr, n);

    cout << "Sesudah dibalik: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void soal2() {
    cout << "\n=== SOAL 2: Array 2D ===\n";
    const int n = 3;
    int matriks[n][n];

    cout << "Masukkan elemen matriks 3x3:\n";
    for (int baris = 0; baris < n; baris++) {
        for (int kolom = 0; kolom < n; kolom++) {
            cout << "Elemen [" << baris+1 << "," << kolom+1 << "]: ";
            cin >> matriks[baris][kolom];
        }
    }

    int jumlah = 0;
    for (int i = 0; i < n; i++) {
        jumlah += matriks[i][i];             
        jumlah += matriks[i][n - 1 - i];     
    }

    cout << "\nMatriks 3x3:\n";
    for (int baris = 0; baris < n; baris++) {
        for (int kolom = 0; kolom < n; kolom++) cout << matriks[baris][kolom] << " ";
        cout << endl;
    }

    cout << "\nJumlah diagonal utama + sekunder: " << jumlah << endl;
}

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

void soal3() {
    cout << "\n=== SOAL 3: Struct + Array ===\n";
    const int n = 5;
    Mahasiswa mhs[n];

    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa " << i+1 << endl;
        cout << "Nama: "; cin >> mhs[i].nama;
        cout << "NIM: "; cin >> mhs[i].nim;
        cout << "IPK: "; cin >> mhs[i].ipk;
    }

    int indeksTertinggi = 0;
    for (int i = 1; i < n; i++) {
        if (mhs[i].ipk > mhs[indeksTertinggi].ipk) indeksTertinggi = i;
    }

    cout << "\nMahasiswa dengan IPK tertinggi:\n";
    cout << mhs[indeksTertinggi].nama << " - "
         << mhs[indeksTertinggi].nim << " - "
         << mhs[indeksTertinggi].ipk << endl;
}

void tukar(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

void soal4() {
    cout << "\n=== SOAL 4: Pointer pada Fungsi ===\n";
    int x, y;
    cout << "Masukkan x: "; cin >> x;
    cout << "Masukkan y: "; cin >> y;

    int *px = &x, *py = &y;

    cout << "\nSebelum tukar: x=" << x << " y=" << y << endl;
    tukar(&px, &py);
    cout << "Sesudah tukar: x=" << x << " y=" << y << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Soal 1: Array + Pointer\n";
        cout << "2. Soal 2: Array 2D\n";
        cout << "3. Soal 3: Struct + Array\n";
        cout << "4. Soal 4: Pointer pada Fungsi\n";
        cout << "0. Keluar\n";
        cout << "Pilih soal: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: soal1(); break;
            case 2: soal2(); break;
            case 3: soal3(); break;
            case 4: soal4(); break;
            case 0: cout << "Terima Kasih\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
