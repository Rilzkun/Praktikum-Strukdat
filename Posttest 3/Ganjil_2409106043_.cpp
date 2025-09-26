#include <iostream>
using namespace std;

struct Item {
    int id;
    string nama;
    string tipe;
    int jumlah;
    Item* next;
    Item* prev;
};

Item* head = NULL;
Item* tail = NULL;
int autoID = 1;

void tambahItem(string nama, string tipe, int jumlah) {
    Item* baru = new Item;
    baru->id = autoID++;
    baru->nama = nama;
    baru->tipe = tipe;
    baru->jumlah = jumlah;
    baru->next = NULL;
    baru->prev = NULL;

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void sisipItem(string nama, string tipe, int jumlah, int posisi) {
    Item* baru = new Item;
    baru->id = autoID++;
    baru->nama = nama;
    baru->tipe = tipe;
    baru->jumlah = jumlah;
    baru->next = NULL;
    baru->prev = NULL;

    if (posisi == 1) {
        baru->next = head;
        if (head != NULL) head->prev = baru;
        head = baru;
        if (tail == NULL) tail = baru;
    } else {
        Item* temp = head;
        int i = 1;
        while (temp != NULL && i < posisi-1) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            cout << "Posisi tidak valid\n";
            delete baru;
        } else {
            baru->next = temp->next;
            baru->prev = temp;
            if (temp->next != NULL) temp->next->prev = baru;
            temp->next = baru;
            if (baru->next == NULL) tail = baru;
        }
    }
}

void hapusItemTerakhir() {
    if (tail == NULL) {
        cout << "Inventory kosong\n";
    } else {
        Item* hapus = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete hapus;
    }
}

void gunakanItem(string nama) {
    Item* temp = head;
    while (temp != NULL && temp->nama != nama) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Item tidak ditemukan\n";
    } else {
        temp->jumlah--;
        cout << "Gunakan 1 " << temp->nama << " | sisa: " << temp->jumlah << endl;
        if (temp->jumlah <= 0) {
            if (temp == head) head = temp->next;
            if (temp == tail) tail = temp->prev;
            if (temp->prev != NULL) temp->prev->next = temp->next;
            if (temp->next != NULL) temp->next->prev = temp->prev;
            delete temp;
        }
    }
}

void tampilDepan() {
    if (head == NULL) {
        cout << "Inventory kosong\n";
    } else {
        Item* temp = head;
        while (temp != NULL) {
            cout << "[" << temp->id << "] " << temp->nama << " (" << temp->tipe << ") Jumlah: " << temp->jumlah << endl;
            temp = temp->next;
        }
    }
}

void tampilBelakang() {
    if (tail == NULL) {
        cout << "Inventory kosong\n";
    } else {
        Item* temp = tail;
        while (temp != NULL) {
            cout << "[" << temp->id << "] " << temp->nama << " (" << temp->tipe << ") Jumlah: " << temp->jumlah << endl;
            temp = temp->prev;
        }
    }
}

void cariItem() {
    if (head == NULL) {
        cout << "Inventory kosong\n";
        return;
    }
    int pilih;
    cout << "Cari berdasarkan (1=ID, 2=Nama): ";
    cin >> pilih;
    cin.ignore();
    if (pilih == 1) {
        int cariID;
        cout << "Masukkan ID: ";
        cin >> cariID;
        Item* temp = head;
        while (temp != NULL && temp->id != cariID) temp = temp->next;
        if (temp == NULL) cout << "Tidak ditemukan\n";
        else cout << "[" << temp->id << "] " << temp->nama << " (" << temp->tipe << ") Jumlah: " << temp->jumlah << endl;
    } else {
        string cariNama;
        cout << "Masukkan Nama: ";
        getline(cin, cariNama);
        Item* temp = head;
        while (temp != NULL && temp->nama != cariNama) temp = temp->next;
        if (temp == NULL) cout << "Tidak ditemukan\n";
        else cout << "[" << temp->id << "] " << temp->nama << " (" << temp->tipe << ") Jumlah: " << temp->jumlah << endl;
    }
}

int main() {
    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    int pilih;
    do {
        cout << "\n=== INVENTORY GAME [" << nama << " - " << nim << "] ===\n";
        cout << "1. Tambah Item\n";
        cout << "2. Sisip Item\n";
        cout << "3. Hapus Item Terakhir\n";
        cout << "4. Gunakan Item\n";
        cout << "5. Lihat dari Depan\n";
        cout << "6. Lihat dari Belakang\n";
        cout << "7. Cari Item\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            string nama, tipe; int jumlah;
            cout << "Nama item: "; getline(cin, nama);
            cout << "Tipe item: "; getline(cin, tipe);
            cout << "Jumlah: "; cin >> jumlah; cin.ignore();
            tambahItem(nama, tipe, jumlah);
        } else if (pilih == 2) {
            string nama, tipe; int jumlah, pos;
            cout << "Nama item: "; getline(cin, nama);
            cout << "Tipe item: "; getline(cin, tipe);
            cout << "Jumlah: "; cin >> jumlah;
            cout << "Posisi: "; cin >> pos; cin.ignore();
            sisipItem(nama, tipe, jumlah, pos);
        } else if (pilih == 3) {
            hapusItemTerakhir();
        } else if (pilih == 4) {
            string nama;
            cout << "Nama item yang digunakan: ";
            getline(cin, nama);
            gunakanItem(nama);
        } else if (pilih == 5) {
            tampilDepan();
        } else if (pilih == 6) {
            tampilBelakang();
        } else if (pilih == 7) {
            cariItem();
        }
    } while (pilih != 0);

    return 0;
}
