#include <iostream>
using namespace std;

void balikArray(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + n - i - 1);
        *(arr + n - i - 1) = temp;
    }
}

int main() {
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

    return 0;
}
