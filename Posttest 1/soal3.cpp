#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
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

    return 0;
}
