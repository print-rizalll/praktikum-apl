#include <iostream>
using namespace std;

int main() {
    int data[] = {30, 45, 85, 120, 250};
    int n = sizeof(data) / sizeof(data[0]);
    int cari;
    bool found = false;
    cout << "Masukkan Harga yang ingin dicari: ";
    cin >> cari;

    for (int i = 0; i < n; i++) {
        if (data[i] == cari) {
            cout << "Harga Anggrek ditemukan pada indeks ke-" << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Harga Anggrek tidak ditemukan dalam array." << endl;
    }
    return 0;
}



int main() {
    int data[] = {30, 45, 85, 120, 250};
    int n = sizeof(data) / sizeof(data[0]);
    int cari;
    bool found = false;
    cout << "Masukkan Harga yang ingin dicari: ";
    cin >> cari;

    for (int i = 0; i < n; i++) {
        if (data[i] == cari) {
            cout << "Harga Anggrek ditemukan pada indeks ke-" << i << endl;
            found = true;
            break;
        }
    } 

    if (!found) {
        cout << "Harga Anggrek tidak ditemukan dalam array." << endl;
    }
    return 0;
}


