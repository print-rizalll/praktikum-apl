// #include <iostream>
// using namespace std;

// // struct Mahasiswa{
// //     long long nim;
// //     string nama;
// //     float nilai;
// // };


// int main() {
// //     Mahasiswa mhs1;
// //     mhs1.nim = 2509106071;
// //     mhs1.nama = "Rizal";
// //     mhs1.nilai = 99.5;

// //     cout << "NIM: " << mhs1.nim << endl;
// //     cout << "Nama: " << mhs1.nama << endl;
// //     cout << "Nilai: " << mhs1.nilai << endl;

// //     return 0;
// // }

// struct date {
//     int month;
//     int day;
//     int year;
// };
// struct mahasiswa{
//     string name;
//     struct date birthday;
// };

// struct mahasiswa mhs[10];

// mhs[0].name = "Ihsan";
// mhs[0].birthday.day = 30;
// mhs[0].birthday.month = 1;
// mhs[0].birthday.year = 2007;

// mhs[1].name = "Rizal";
// mhs[1].birthday.day = 13;
// mhs[1].birthday.month = 9;
// mhs[1].birthday.year = 2006;

// cout << mhs[1].birthday.year << endl;
// cout << mhs[0].name << endl;
// cout << mhs[1].name << endl;
// }

#include <iostream>
using namespace std;

struct Alamat {
    string jalan;
    int    nomor;
    string kota;
};

struct Mahasiswa {
    string nama;
    int    umur;
    string jurusan;
    Alamat alamat;
};

#define MAX_MAHASISWA 100
int panjang = 0;
Mahasiswa mhs[MAX_MAHASISWA];

int main() {
    int pilihan, index;
    
    do {
        cout << "==============================" << endl;
        cout << "   Menu Manajemen Mahasiswa  " << endl;
        cout << "==============================" << endl;
        cout << "1. Tampilkan Data Mahasiswa"  << endl;
        cout << "2. Tambah Data Mahasiswa"     << endl;
        cout << "3. Ubah Data Mahasiswa"       << endl;
        cout << "4. Hapus Data Mahasiswa"      << endl;
        cout << "5. Keluar"                    << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            
        case 1: // READ
            if (panjang == 0) {
                cout << "Belum ada data mahasiswa." << endl;
            } else {
                cout << "Daftar Mahasiswa:" << endl;
                cout << "================================" << endl;
                for (int i = 0; i < panjang; i++) {
                    cout << "Mahasiswa ke-" << i + 1 << endl;
                    cout << "Nama    : " << mhs[i].nama    << endl;
                    cout << "Umur    : " << mhs[i].umur    << endl;
                    cout << "Jurusan : " << mhs[i].jurusan << endl;
                    cout << "Alamat  : " << mhs[i].alamat.jalan
                        << " No. " << mhs[i].alamat.nomor
                        << ", "    << mhs[i].alamat.kota << endl;
                    cout << "--------------------------------" << endl;
                }
            }
            break;
            
        case 2: // CREATE
            if (panjang < MAX_MAHASISWA) {
                cin.ignore();
                cout << "Masukkan nama     : ";
                getline(cin, mhs[panjang].nama);
                
                cout << "Masukkan umur     : ";
                cin >> mhs[panjang].umur;
                
                cin.ignore();
                cout << "Masukkan jurusan  : ";
                getline(cin, mhs[panjang].jurusan);
                
                cout << "--- Alamat ---" << endl;
                cout << "Jalan : ";
                getline(cin, mhs[panjang].alamat.jalan);
                
                cout << "Nomor : ";
                cin >> mhs[panjang].alamat.nomor;
                
                cin.ignore();
                cout << "Kota  : ";
                getline(cin, mhs[panjang].alamat.kota);
                
                panjang++;
                cout << "Data berhasil ditambahkan!" << endl;
            } else {
                cout << "Kapasitas penuh!" << endl;
            }
            break;
            
        case 3: // UPDATE
            if (panjang == 0) {
                cout << "Belum ada mahasiswa untuk diubah." << endl;
            } else {
                cout << "Daftar Mahasiswa" << endl;
                cout << "==================" << endl;
                for (int i = 0; i < panjang; i++) {
                    cout << i + 1 << ". " << mhs[i].nama << endl;
                }
                
                cout << "Masukkan nomor mahasiswa yang akan diubah: ";
                cin >> index;
                
                if (index > 0 && index <= panjang) {
                    cin.ignore();
                    cout << "Masukkan nama mahasiswa baru: ";
                    getline(cin, mhs[index - 1].nama);
                    
                    cout << "Masukkan umur mahasiswa baru: ";
                    cin >> mhs[index - 1].umur;
                    
                    cin.ignore();
                    cout << "Masukkan jurusan mahasiswa baru: ";
                    getline(cin, mhs[index - 1].jurusan);
                    
                    cout << "Masukkan alamat mahasiswa baru:" << endl;
                    cout << "Jalan: ";
                    getline(cin, mhs[index - 1].alamat.jalan);
                    
                    cout << "Nomor: ";
                    cin >> mhs[index - 1].alamat.nomor;
                    
                    cin.ignore();
                    cout << "Kota: ";
                    getline(cin, mhs[index - 1].alamat.kota);
                    
                    cout << "Mahasiswa berhasil diubah" << endl;
                } else {
                    cout << "Nomor mahasiswa tidak valid" << endl;
                }
            }
            break;
            
        case 4: // DELETE
            if (panjang == 0) {
                cout << "Belum ada mahasiswa untuk dihapus." << endl;
            } else {
                cout << "Daftar Mahasiswa" << endl;
                cout << "==================" << endl;
                for (int i = 0; i < panjang; i++) {
                    cout << i + 1 << ". " << mhs[i].nama << endl;
                }
                
                cout << "Masukkan nomor mahasiswa yang akan dihapus: ";
                cin >> index;
                
                if (index > 0 && index <= panjang) {
                    for (int i = index - 1; i < panjang - 1; i++) {
                        mhs[i] = mhs[i + 1];
                    }
                    panjang--;
                    cout << "Mahasiswa berhasil dihapus" << endl;
                } else {
                    cout << "Nomor mahasiswa tidak valid" << endl;
                }
            }
            break;
            
        case 5:
            cout << "Sampai jumpa!" << endl;
            break;
            
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
        
    } while (pilihan != 5);
    
    return 0;
}