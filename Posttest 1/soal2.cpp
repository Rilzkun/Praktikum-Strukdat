#include <iostream>
using namespace std;

int main() {
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
    return 0;
}
