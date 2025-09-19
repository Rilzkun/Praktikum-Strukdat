#include <iostream>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
};

Item* head = NULL;

void tambahItem(string nama, string tipe, int jumlahAwal) {
    Item* baru = new Item{nama, jumlahAwal, tipe, NULL};
    if (head == NULL) {
        head = baru;
    } else {
        Item* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = baru;
    }
}

void sisipItem(string nama, string tipe, int jumlahAwal, int posisi) {
    Item* baru = new Item{nama, jumlahAwal, tipe, NULL};
    if (posisi == 1) {
        baru->next = head;
        head = baru;
        return;
    }
    Item* temp = head;
    int hitung = 1;
    while (temp != NULL && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }
    if (temp == NULL) {
        cout << "Posisi tidak valid!\n";
        delete baru;
    } else {
        baru->next = temp->next;
        temp->next = baru;
    }
}

void hapusItemTerakhir() {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Item* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void gunakanItem(string nama) {
    Item* temp = head;
    Item* prev = NULL;
    while (temp != NULL && temp->namaItem != nama) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Item tidak ditemukan!\n";
        return;
    }
    temp->jumlah -= 1;
    cout << "Gunakan 1 " << temp->namaItem << " | Sisa: " << temp->jumlah << endl;
    if (temp->jumlah <= 0) {
        cout << temp->namaItem << " habis, dihapus dari inventory.\n";
        if (prev == NULL) head = temp->next;
        else prev->next = temp->next;
        delete temp;
    }
}

void tampilkanInventory() {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "\n=== Daftar Inventory ===\n";
    Item* temp = head;
    int i = 1;
    while (temp != NULL) {
        cout << i++ << ". " << temp->namaItem 
             << " (" << temp->tipe << ") | Jumlah: " << temp->jumlah << endl;
        temp = temp->next;
    }
    cout << "========================\n";
}

int main() {
    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    int pilihan;
    do {
        cout << "\n+-----------------------------------+\n";
        cout << "|   GAME INVENTORY MANAGEMENT       |\n";
        cout << "|   [" << nama << " - " << nim << "]\n";
        cout << "+-----------------------------------+\n";
        cout << "1. Tambah Item Baru\n";
        cout << "2. Sisipkan Item\n";
        cout << "3. Hapus Item Terakhir\n";
        cout << "4. Gunakan Item\n";
        cout << "5. Tampilkan Inventory\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            string namaItem, tipe;
            cout << "Nama item: ";
            getline(cin, namaItem);
            cout << "Tipe item: ";
            getline(cin, tipe);
            tambahItem(namaItem, tipe, 43); 
        } 
        else if (pilihan == 2) {
            string namaItem, tipe;
            cout << "Nama item: ";
            getline(cin, namaItem);
            cout << "Tipe item: ";
            getline(cin, tipe);
            sisipItem(namaItem, tipe, 43, 4); 
        } 
        else if (pilihan == 3) {
            hapusItemTerakhir();
        } 
        else if (pilihan == 4) {
            string namaItem;
            cout << "Nama item yang digunakan: ";
            getline(cin, namaItem);
            gunakanItem(namaItem);
        } 
        else if (pilihan == 5) {
            tampilkanInventory();
        }
    } while (pilihan != 0);

    return 0;
}
