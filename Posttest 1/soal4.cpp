#include <iostream>
using namespace std;

void tukar(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    cout << "\n=== SOAL 4: Pointer pada Fungsi ===\n";
    int x, y;
    cout << "Masukkan x: "; cin >> x;
    cout << "Masukkan y: "; cin >> y;

    int *px = &x, *py = &y;

    cout << "\nSebelum tukar: x=" << x << " y=" << y << endl;
    tukar(&px, &py);
    cout << "Sesudah tukar: x=" << x << " y=" << y << endl;

    return 0;
}
