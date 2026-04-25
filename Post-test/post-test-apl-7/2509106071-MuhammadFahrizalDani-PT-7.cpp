#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <limits>
using namespace std;


struct Spesifikasi {
    int    kapasitas_penumpang;
    string kelas_penerbangan;
};

struct Pesawat {
    int         id;
    string      kode_pesawat;
    string      nama_maskapai;
    string      model;
    string      status;
    string      tahun_produksi;
    Spesifikasi spek;
};

struct Pengguna {
    string nama;
    string password;
    bool   aktif;
};


void tampilBanner(Pengguna *pUser) {
    cout << "\n";
    cout << "  +=================================================+\n";
    cout << "  |    >>>  MANAJEMEN ARMADA PESAWAT  <<<           |\n";
    cout << "  |      Sistem Informasi Pengelolaan Pesawat       |\n";
    cout << "  +=================================================+\n";
    if (pUser != nullptr && (*pUser).aktif)
        cout << "  | Login sebagai : " << left << setw(33) << (*pUser).nama << "|\n"
            << "  +=================================================+\n";
    cout << "\n";
}


void tampilTabelPesawat(Pesawat daftarPesawat[], int jumlahPesawat) {
    cout << "\n+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+"
        << string(18,'-') << "+" << string(14,'-') << "+" << string(8,'-') << "+"
        << string(12,'-') << "+" << string(26,'-') << "+\n";
    cout << "| " << left
        << setw(3)  << "ID"       << " | " << setw(8)  << "Kode"     << " | "
        << setw(18) << "Maskapai" << " | " << setw(16) << "Model"    << " | "
        << setw(12) << "Status"   << " | " << setw(6)  << "Tahun"    << " | "
        << setw(10) << "Kap."     << " | " << setw(24) << "Kelas"    << " |\n";
    cout << "+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+"
        << string(18,'-') << "+" << string(14,'-') << "+" << string(8,'-') << "+"
        << string(12,'-') << "+" << string(26,'-') << "+\n";
    for (int i = 0; i < jumlahPesawat; i++)
        cout << "| " << left
            << setw(3)  << daftarPesawat[i].id                       << " | "
            << setw(8)  << daftarPesawat[i].kode_pesawat             << " | "
            << setw(18) << daftarPesawat[i].nama_maskapai            << " | "
            << setw(16) << daftarPesawat[i].model                    << " | "
            << setw(12) << daftarPesawat[i].status                   << " | "
            << setw(6)  << daftarPesawat[i].tahun_produksi           << " | "
            << setw(10) << daftarPesawat[i].spek.kapasitas_penumpang << " | "
            << setw(24) << daftarPesawat[i].spek.kelas_penerbangan   << " |\n";
    cout << "+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+"
        << string(18,'-') << "+" << string(14,'-') << "+" << string(8,'-') << "+"
        << string(12,'-') << "+" << string(26,'-') << "+\n";
    cout << "  Total: " << jumlahPesawat << " pesawat\n";
}


void tampilTabelPesawat(Pesawat daftarPesawat[], int jumlahPesawat, bool ringkas) {
    cout << "\n+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+"
        << string(18,'-') << "+" << string(14,'-') << "+\n";
    cout << "| " << left << setw(3) << "ID" << " | " << setw(8) << "Kode" << " | "
        << setw(18) << "Maskapai" << " | " << setw(16) << "Model"
        << " | " << setw(12) << "Status" << " |\n";
    cout << "+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+"
        << string(18,'-') << "+" << string(14,'-') << "+\n";
    for (int i = 0; i < jumlahPesawat; i++)
        cout << "| " << left << setw(3) << daftarPesawat[i].id << " | "
            << setw(8)  << daftarPesawat[i].kode_pesawat  << " | "
            << setw(18) << daftarPesawat[i].nama_maskapai << " | "
            << setw(16) << daftarPesawat[i].model          << " | "
            << setw(12) << daftarPesawat[i].status         << " |\n";
    cout << "+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+"
        << string(18,'-') << "+" << string(14,'-') << "+\n";
}


bool statusValid(string *status) {
    if (*status == "Aktif" || *status == "Perawatan" || *status == "Tidak Aktif")
        return true;
    return false;
}

int cariIndexPesawat(Pesawat daftarPesawat[], int jumlahPesawat, int &idCari) {
    for (int i = 0; i < jumlahPesawat; i++)
        if (daftarPesawat[i].id == idCari) return i;
    return -1;
}

int totalKapasitas(Pesawat daftarPesawat[], int index, int jumlahPesawat) {
    if (index >= jumlahPesawat) return 0;
    return daftarPesawat[index].spek.kapasitas_penumpang
        + totalKapasitas(daftarPesawat, index + 1, jumlahPesawat);
}


void binarySearchID(Pesawat daftarPesawat[], int jumlahPesawat, int *idCari) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |  SEARCHING: Binary Search berdasar ID    |\n";
    cout << "  +------------------------------------------+\n";

    Pesawat temp[100];
    for (int i = 0; i < jumlahPesawat; i++) temp[i] = daftarPesawat[i];
    for (int i = 0; i < jumlahPesawat - 1; i++)
        for (int j = 0; j < jumlahPesawat - i - 1; j++)
            if (temp[j].id > temp[j+1].id) {
                Pesawat t = temp[j]; temp[j] = temp[j+1]; temp[j+1] = t;
            }

    int kiri  = 0;
    int kanan = jumlahPesawat - 1;
    int hasil = -1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (temp[tengah].id == *idCari) { hasil = tengah; break; }
        else if (temp[tengah].id < *idCari) kiri = tengah + 1;
        else kanan = tengah - 1;
    }

    if (hasil == -1) {
        cout << "  [!] Pesawat dengan ID " << *idCari << " tidak ditemukan.\n";
    } else {
        cout << "  [OK] Pesawat dengan ID " << *idCari << " ditemukan!\n";
        tampilTabelPesawat(temp, jumlahPesawat);
        cout << "\n  >> Data yang ditemukan:\n";
        cout << "     ID        : " << temp[hasil].id                       << "\n";
        cout << "     Kode      : " << temp[hasil].kode_pesawat             << "\n";
        cout << "     Maskapai  : " << temp[hasil].nama_maskapai            << "\n";
        cout << "     Model     : " << temp[hasil].model                    << "\n";
        cout << "     Status    : " << temp[hasil].status                   << "\n";
        cout << "     Tahun     : " << temp[hasil].tahun_produksi           << "\n";
        cout << "     Kapasitas : " << temp[hasil].spek.kapasitas_penumpang << "\n";
        cout << "     Kelas     : " << temp[hasil].spek.kelas_penerbangan   << "\n";
    }
}


void linearSearchNama(Pesawat daftarPesawat[], int jumlahPesawat, string *kataCari) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |  SEARCHING: Linear Search Nama Maskapai  |\n";
    cout << "  +------------------------------------------+\n";

    string kataLow = *kataCari;
    for (int i = 0; i < (int)kataLow.size(); i++)
        if (kataLow[i] >= 'A' && kataLow[i] <= 'Z') kataLow[i] += 32;

    int jumlahDitemukan = 0;

    cout << "\n+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+"
        << string(18,'-') << "+" << string(14,'-') << "+" << string(8,'-') << "+"
        << string(12,'-') << "+" << string(26,'-') << "+\n";
    cout << "| " << left
        << setw(3)  << "ID"       << " | " << setw(8)  << "Kode"     << " | "
        << setw(18) << "Maskapai" << " | " << setw(16) << "Model"    << " | "
        << setw(12) << "Status"   << " | " << setw(6)  << "Tahun"    << " | "
        << setw(10) << "Kap."     << " | " << setw(24) << "Kelas"    << " |\n";
    cout << "+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+"
        << string(18,'-') << "+" << string(14,'-') << "+" << string(8,'-') << "+"
        << string(12,'-') << "+" << string(26,'-') << "+\n";

    for (int i = 0; i < jumlahPesawat; i++) {
        string namaLow = daftarPesawat[i].nama_maskapai;
        for (int j = 0; j < (int)namaLow.size(); j++)
            if (namaLow[j] >= 'A' && namaLow[j] <= 'Z') namaLow[j] += 32;
        if (namaLow.find(kataLow) != string::npos) {
            cout << "| " << left
                << setw(3)  << daftarPesawat[i].id                       << " | "
                << setw(8)  << daftarPesawat[i].kode_pesawat             << " | "
                << setw(18) << daftarPesawat[i].nama_maskapai            << " | "
                << setw(16) << daftarPesawat[i].model                    << " | "
                << setw(12) << daftarPesawat[i].status                   << " | "
                << setw(6)  << daftarPesawat[i].tahun_produksi           << " | "
                << setw(10) << daftarPesawat[i].spek.kapasitas_penumpang << " | "
                << setw(24) << daftarPesawat[i].spek.kelas_penerbangan   << " |\n";
            jumlahDitemukan++;
        }
    }

    cout << "+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+"
        << string(18,'-') << "+" << string(14,'-') << "+" << string(8,'-') << "+"
        << string(12,'-') << "+" << string(26,'-') << "+\n";

    if (jumlahDitemukan == 0)
        cout << "  [!] Maskapai dengan kata kunci \"" << *kataCari << "\" tidak ditemukan.\n";
    else
        cout << "  [OK] Ditemukan " << jumlahDitemukan << " data dengan kata kunci \""
             << *kataCari << "\".\n";
}


void menuSearching(Pesawat daftarPesawat[], int &jumlahPesawat) {
    bool kembali = false;
    while (!kembali) {
        cout << "\n  +------------------------------------------+\n";
        cout << "  |           MENU SEARCHING                 |\n";
        cout << "  +------------------------------------------+\n";
        cout << "  |  1. Binary Search     - Cari by ID       |\n";
        cout << "  |  2. Linear Search - Cari by Nama Maskapai|\n";
        cout << "  |  0. Kembali                              |\n";
        cout << "  +------------------------------------------+\n";
        cout << "  Pilihan: ";

        int pilihanCari;
        try {
            if (!(cin >> pilihanCari)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Input pilihan harus berupa angka!");
            }
            cin.ignore();
        } catch (const invalid_argument &e) {
            cout << "\n  [EXCEPTION] " << e.what() << "\n";
            cout << "  Tekan Enter untuk kembali..."; cin.get();
            continue;
        }

        if (pilihanCari == 1) {
            try {
                int idCari;
                cout << "  Masukkan ID yang dicari: ";
                if (!(cin >> idCari)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("ID harus berupa angka bulat positif!");
                }
                cin.ignore();
                if (idCari <= 0)
                    throw out_of_range("ID tidak boleh nol atau negatif!");
                binarySearchID(daftarPesawat, jumlahPesawat, &idCari);
            } catch (const invalid_argument &e) {
                cout << "\n  [EXCEPTION] " << e.what() << "\n";
            } catch (const out_of_range &e) {
                cout << "\n  [EXCEPTION] " << e.what() << "\n";
            }
            cout << "  Tekan Enter untuk kembali..."; cin.get();

        } else if (pilihanCari == 2) {
            string kataCari;
            cout << "  Masukkan nama maskapai yang dicari: ";
            getline(cin, kataCari);
            try {
                if (kataCari.empty())
                    throw invalid_argument("Kata kunci pencarian tidak boleh kosong!");
                linearSearchNama(daftarPesawat, jumlahPesawat, &kataCari);
            } catch (const invalid_argument &e) {
                cout << "\n  [EXCEPTION] " << e.what() << "\n";
            }
            cout << "  Tekan Enter untuk kembali..."; cin.get();

        } else if (pilihanCari == 0) {
            kembali = true;
        } else {
            cout << "\n  [!] Pilihan tidak valid.\n";
            cout << "  Tekan Enter untuk kembali..."; cin.get();
        }
    }
}


void bubbleSortNamaAscending(Pesawat daftarPesawat[], int &jumlahPesawat) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |  SORTING: Nama Maskapai A-Z (Bubble)     |\n";
    cout << "  +------------------------------------------+\n";
    for (int i = 0; i < jumlahPesawat - 1; i++)
        for (int j = 0; j < jumlahPesawat - i - 1; j++)
            if (daftarPesawat[j].nama_maskapai > daftarPesawat[j+1].nama_maskapai) {
                Pesawat temp       = daftarPesawat[j];
                daftarPesawat[j]   = daftarPesawat[j+1];
                daftarPesawat[j+1] = temp;
            }
    cout << "  [OK] Data diurutkan berdasarkan Nama Maskapai A-Z\n";
    tampilTabelPesawat(daftarPesawat, jumlahPesawat);
}


void selectionSortKapasitasDescending(Pesawat daftarPesawat[], int *jumlahPesawat) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |  SORTING: Kapasitas Terbesar (Selection) |\n";
    cout << "  +------------------------------------------+\n";
    for (int i = 0; i < *jumlahPesawat - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < *jumlahPesawat; j++)
            if (daftarPesawat[j].spek.kapasitas_penumpang >
                daftarPesawat[maxIdx].spek.kapasitas_penumpang)
                maxIdx = j;
        if (maxIdx != i) {
            Pesawat temp          = daftarPesawat[i];
            daftarPesawat[i]      = daftarPesawat[maxIdx];
            daftarPesawat[maxIdx] = temp;
        }
    }
    cout << "  [OK] Data diurutkan berdasarkan Kapasitas Terbesar ke Terkecil\n";
    tampilTabelPesawat(daftarPesawat, *jumlahPesawat);
}


void insertionSortTahunAscending(Pesawat daftarPesawat[], int &jumlahPesawat) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |  SORTING: Tahun Produksi Lama-Baru       |\n";
    cout << "  |           (Insertion Sort)               |\n";
    cout << "  +------------------------------------------+\n";
    for (int i = 1; i < jumlahPesawat; i++) {
        Pesawat key = daftarPesawat[i];
        int j = i - 1;
        while (j >= 0 && daftarPesawat[j].tahun_produksi > key.tahun_produksi) {
            daftarPesawat[j+1] = daftarPesawat[j];
            j--;
        }
        daftarPesawat[j+1] = key;
    }
    cout << "  [OK] Data diurutkan berdasarkan Tahun Produksi Terlama ke Terbaru\n";
    tampilTabelPesawat(daftarPesawat, jumlahPesawat);
}


void menuSorting(Pesawat daftarPesawat[], int &jumlahPesawat) {
    bool kembali = false;
    while (!kembali) {
        cout << "\n  +------------------------------------------+\n";
        cout << "  |           MENU SORTING                   |\n";
        cout << "  +------------------------------------------+\n";
        cout << "  |  1. Bubble Sort   - Nama Maskapai A-Z    |\n";
        cout << "  |  2. Selection Sort- Kapasitas Terbesar   |\n";
        cout << "  |  3. Insertion Sort- Tahun Produksi Lama  |\n";
        cout << "  |  0. Kembali                              |\n";
        cout << "  +------------------------------------------+\n";
        cout << "  Pilihan: ";
        int pilihanSort;
        cin >> pilihanSort; cin.ignore();

        if      (pilihanSort == 1) { bubbleSortNamaAscending(daftarPesawat, jumlahPesawat); cout << "  Tekan Enter..."; cin.get(); }
        else if (pilihanSort == 2) { selectionSortKapasitasDescending(daftarPesawat, &jumlahPesawat); cout << "  Tekan Enter..."; cin.get(); }
        else if (pilihanSort == 3) { insertionSortTahunAscending(daftarPesawat, jumlahPesawat); cout << "  Tekan Enter..."; cin.get(); }
        else if (pilihanSort == 0) { kembali = true; }
        else { cout << "\n  [!] Pilihan tidak valid.\n"; cout << "  Tekan Enter..."; cin.get(); }
    }
}


bool registerUser(Pengguna daftarUser[], int &jumlahUser, int MAX_USER) {
    cout << "\n  +----------------------------------+\n";
    cout << "  |      REGISTER AKUN BARU         |\n";
    cout << "  +----------------------------------+\n";

    try {
        if (jumlahUser >= MAX_USER)
            throw runtime_error("Kapasitas user penuh! Tidak bisa mendaftar.");

        string regNama, regPass;
        cout << "  Nama     : "; getline(cin, regNama);
        cout << "  Password : "; getline(cin, regPass);

        if (regNama.empty() || regPass.empty())
            throw invalid_argument("Nama dan Password tidak boleh kosong!");

        for (int i = 0; i < jumlahUser; i++)
            if (daftarUser[i].nama == regNama)
                throw runtime_error("Username \"" + regNama + "\" sudah terdaftar!");

        daftarUser[jumlahUser++] = {regNama, regPass, true};
        cout << "\n  [OK] Registrasi berhasil! Silakan login.\n";
        return true;

    } catch (const invalid_argument &e) {
        cout << "\n  [EXCEPTION] " << e.what() << "\n";
    } catch (const runtime_error &e) {
        cout << "\n  [EXCEPTION] " << e.what() << "\n";
    }
    return false;
}

Pengguna* loginUser(Pengguna daftarUser[], int &jumlahUser) {
    int percobaan = 0;
    while (percobaan < 3) {
        cout << "\n  +----------------------------------+\n";
        cout << "  |    LOGIN  (" << (percobaan+1) << " / 3)             |\n";
        cout << "  +----------------------------------+\n";

        string inputNama, inputPass;
        cout << "  Username : "; getline(cin, inputNama);
        cout << "  Password : "; getline(cin, inputPass);

        try {
            if (inputNama.empty() || inputPass.empty())
                throw invalid_argument("Username dan Password tidak boleh kosong!");

            for (int i = 0; i < jumlahUser; i++)
                if (daftarUser[i].nama == inputNama &&
                    daftarUser[i].password == inputPass &&
                    daftarUser[i].aktif)
                    return &daftarUser[i];

            throw runtime_error("Username atau Password salah!");

        } catch (const invalid_argument &e) {
            cout << "\n  [EXCEPTION] " << e.what() << "\n";
            continue;

        } catch (const runtime_error &e) {
            cout << "\n  [!] " << e.what() << "\n";
            percobaan++;
            if (percobaan < 3)
                cout << "  Sisa percobaan: " << (3 - percobaan) << "\n";
            else {
                cout << "\n  +===========================================+\n"
                    << "  |  [!!] Login gagal 3x. Program berhenti.  |\n"
                    << "  +===========================================+\n\n";
                exit(0);
            }
        }
    }
    return nullptr;
}


void tambahPesawat(Pesawat daftarPesawat[], int &jumlahPesawat, int &idCounter, int MAX_PESAWAT) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |       TAMBAH DATA PESAWAT                |\n";
    cout << "  +------------------------------------------+\n";

    try {
        if (jumlahPesawat >= MAX_PESAWAT)
            throw runtime_error("Data pesawat sudah penuh! (maks " + to_string(MAX_PESAWAT) + ")");

        Pesawat baru;
        baru.id = idCounter++;

        cout << "  Kode Pesawat                         : "; getline(cin, baru.kode_pesawat);
        cout << "  Nama Maskapai                        : "; getline(cin, baru.nama_maskapai);
        cout << "  Model Pesawat                        : "; getline(cin, baru.model);

        if (baru.kode_pesawat.empty() || baru.nama_maskapai.empty() || baru.model.empty())
            throw invalid_argument("Kode, Nama Maskapai, dan Model tidak boleh kosong!");

        while (true) {
            cout << "  Status (Aktif/Perawatan/Tidak Aktif) : "; getline(cin, baru.status);
            string *pStatus = &baru.status;
            if (statusValid(pStatus)) break;
            else cout << "  [!] Status tidak valid! Pilihan: Aktif, Perawatan, Tidak Aktif\n";
        }

        cout << "  Tahun Produksi                       : "; getline(cin, baru.tahun_produksi);

        while (true) {
            cout << "  Kapasitas Penumpang                  : ";
            string kapStr; getline(cin, kapStr);
            try {
                int kap = stoi(kapStr);
                if (kap <= 0)
                    throw out_of_range("Kapasitas harus lebih dari 0!");
                baru.spek.kapasitas_penumpang = kap;
                break;
            } catch (const invalid_argument &) {
                cout << "  [EXCEPTION] Kapasitas harus berupa angka bulat!\n";
            } catch (const out_of_range &e) {
                cout << "  [EXCEPTION] " << e.what() << "\n";
            }
        }

        cout << "  Kelas Penerbangan                    : "; getline(cin, baru.spek.kelas_penerbangan);

        daftarPesawat[jumlahPesawat++] = baru;
        cout << "\n  [OK] Pesawat ditambahkan! (ID: " << baru.id << ")\n";
        cout << "  Total kapasitas armada kini: "
            << totalKapasitas(daftarPesawat, 0, jumlahPesawat) << " penumpang\n";

    } catch (const invalid_argument &e) {
        cout << "\n  [EXCEPTION] " << e.what() << "\n";
        idCounter--;
    } catch (const runtime_error &e) {
        cout << "\n  [EXCEPTION] " << e.what() << "\n";
        idCounter--;
    }
}


void lihatPesawat(Pesawat daftarPesawat[], int jumlahPesawat) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |       DAFTAR ARMADA PESAWAT              |\n";
    cout << "  +------------------------------------------+\n";
    if (jumlahPesawat == 0) { cout << "  [!] Belum ada data pesawat.\n"; return; }
    tampilTabelPesawat(daftarPesawat, jumlahPesawat);
    cout << "  Total kapasitas seluruh armada: "
        << totalKapasitas(daftarPesawat, 0, jumlahPesawat) << " penumpang\n";
}


void ubahPesawat(Pesawat daftarPesawat[], int jumlahPesawat) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |       UBAH DATA PESAWAT                  |\n";
    cout << "  +------------------------------------------+\n";
    if (jumlahPesawat == 0) { cout << "  [!] Belum ada data pesawat.\n"; return; }

    tampilTabelPesawat(daftarPesawat, jumlahPesawat, true);

    try {
        int idCari;
        cout << "\n  ID yang akan diubah: ";
        if (!(cin >> idCari)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("ID harus berupa angka!");
        }
        cin.ignore();

        int idx = cariIndexPesawat(daftarPesawat, jumlahPesawat, idCari);
        if (idx == -1)
            throw runtime_error("ID " + to_string(idCari) + " tidak ditemukan dalam data!");

        Pesawat *pPesawat = &daftarPesawat[idx];
        cout << "\n  Masukkan data baru (Enter = lewati):\n\n";
        string inp;

        cout << "  Kode Pesawat [" << pPesawat->kode_pesawat << "]: ";
        getline(cin, inp); if (!inp.empty()) pPesawat->kode_pesawat = inp;

        cout << "  Nama Maskapai [" << pPesawat->nama_maskapai << "]: ";
        getline(cin, inp); if (!inp.empty()) pPesawat->nama_maskapai = inp;

        cout << "  Model [" << pPesawat->model << "]: ";
        getline(cin, inp); if (!inp.empty()) pPesawat->model = inp;

        while (true) {
            cout << "  Status [" << pPesawat->status << "] (Enter=lewati): "; getline(cin, inp);
            if (inp.empty()) break;
            string *pStatus = &inp;
            if (statusValid(pStatus)) { pPesawat->status = inp; break; }
            else cout << "  [!] Status tidak valid! Pilihan: Aktif, Perawatan, Tidak Aktif\n";
        }

        cout << "  Tahun Produksi [" << pPesawat->tahun_produksi << "]: ";
        getline(cin, inp); if (!inp.empty()) pPesawat->tahun_produksi = inp;

        cout << "  Kapasitas Penumpang [" << pPesawat->spek.kapasitas_penumpang << "]: ";
        getline(cin, inp);
        if (!inp.empty()) {
            try {
                int kap = stoi(inp);
                if (kap <= 0)
                    throw out_of_range("Kapasitas harus lebih dari 0!");
                pPesawat->spek.kapasitas_penumpang = kap;
            } catch (const invalid_argument &) {
                cout << "  [EXCEPTION] Kapasitas harus berupa angka! Nilai lama dipertahankan.\n";
            } catch (const out_of_range &e) {
                cout << "  [EXCEPTION] " << e.what() << " Nilai lama dipertahankan.\n";
            }
        }

        cout << "  Kelas Penerbangan [" << pPesawat->spek.kelas_penerbangan << "]: ";
        getline(cin, inp); if (!inp.empty()) pPesawat->spek.kelas_penerbangan = inp;

        cout << "\n  [OK] Data ID " << idCari << " berhasil diperbarui.\n";

    } catch (const invalid_argument &e) {
        cout << "\n  [EXCEPTION] " << e.what() << "\n";
    } catch (const runtime_error &e) {
        cout << "\n  [EXCEPTION] " << e.what() << "\n";
    }
}


void hapusPesawat(Pesawat daftarPesawat[], int &jumlahPesawat) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |       HAPUS DATA PESAWAT                 |\n";
    cout << "  +------------------------------------------+\n";
    if (jumlahPesawat == 0) { cout << "  [!] Belum ada data pesawat.\n"; return; }

    tampilTabelPesawat(daftarPesawat, jumlahPesawat, true);

    try {
        int idCari;
        cout << "\n  ID yang akan dihapus: ";
        if (!(cin >> idCari)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("ID harus berupa angka!");
        }
        cin.ignore();

        int idx = cariIndexPesawat(daftarPesawat, jumlahPesawat, idCari);
        if (idx == -1)
            throw runtime_error("ID " + to_string(idCari) + " tidak ditemukan dalam data!");

        Pesawat *pPesawat = &daftarPesawat[idx];
        cout << "\n  Akan dihapus: [" << pPesawat->kode_pesawat << "] "
            << pPesawat->nama_maskapai << " - " << pPesawat->model << "\n";
        string kf; cout << "  Yakin hapus? (y/n): "; getline(cin, kf);
        if (kf == "y" || kf == "Y") {
            for (int i = idx; i < jumlahPesawat - 1; i++) daftarPesawat[i] = daftarPesawat[i+1];
            jumlahPesawat--;
            cout << "\n  [OK] Data ID " << idCari << " berhasil dihapus.\n";
        } else {
            cout << "\n  [i] Penghapusan dibatalkan.\n";
        }

    } catch (const invalid_argument &e) {
        cout << "\n  [EXCEPTION] " << e.what() << "\n";
    } catch (const runtime_error &e) {
        cout << "\n  [EXCEPTION] " << e.what() << "\n";
    }
}


void lihatUser(Pengguna daftarUser[], int *jumlahUser) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |       DAFTAR PENGGUNA TERDAFTAR          |\n";
    cout << "  +------------------------------------------+\n";
    cout << "\n+" << string(5,'-') << "+" << string(25,'-') << "+" << string(20,'-') << "+\n";
    cout << "| " << left << setw(3) << "No" << " | " << setw(23) << "Nama"
        << " | " << setw(18) << "Password" << " |\n";
    cout << "+" << string(5,'-') << "+" << string(25,'-') << "+" << string(20,'-') << "+\n";
    for (int i = 0; i < *jumlahUser; i++)
        cout << "| " << left << setw(3) << (i+1) << " | " << setw(23) << daftarUser[i].nama
            << " | " << setw(18) << daftarUser[i].password << " |\n";
    cout << "+" << string(5,'-') << "+" << string(25,'-') << "+" << string(20,'-') << "+\n";
    cout << "  Total: " << *jumlahUser << " pengguna\n";
}


int main() {
    const int MAX_PESAWAT = 100;
    const int MAX_USER    = 50;

    Pesawat  daftarPesawat[MAX_PESAWAT];
    Pengguna daftarUser[MAX_USER];

    int jumlahPesawat = 0;
    int jumlahUser    = 0;
    int idCounter     = 1;

    daftarUser[0] = {"rizal", "071", true};
    jumlahUser = 1;

    daftarPesawat[0] = {idCounter++, "GA-001", "Garuda Indonesia", "Boeing 737-800",   "Aktif",       "2015", {162, "Ekonomi & Bisnis"}};
    daftarPesawat[1] = {idCounter++, "JT-045", "Lion Air",         "Boeing 737 MAX 8", "Aktif",       "2019", {210, "Ekonomi"}};
    daftarPesawat[2] = {idCounter++, "QZ-102", "AirAsia",          "Airbus A320neo",   "Perawatan",   "2018", {186, "Ekonomi"}};
    daftarPesawat[3] = {idCounter++, "SJ-088", "Sriwijaya Air",    "Boeing 737-500",   "Tidak Aktif", "2005", {120, "Ekonomi"}};
    daftarPesawat[4] = {idCounter++, "ID-201", "Batik Air",        "Airbus A330-300",  "Aktif",       "2020", {440, "Ekonomi & Bisnis & First"}};
    jumlahPesawat = 5;


    Pengguna *userLogin = nullptr;

    while (true) {
        userLogin = nullptr;
        bool sudahLogin = false;

        while (!sudahLogin) {
            Pengguna kosong = {"", "", false};
            tampilBanner(&kosong);
            cout << "  +-----------------------------+\n";
            cout << "  |        MENU AWAL            |\n";
            cout << "  |  1. Login                   |\n";
            cout << "  |  2. Register Akun Baru      |\n";
            cout << "  |  0. Keluar Program          |\n";
            cout << "  +-----------------------------+\n";
            cout << "  Pilihan: ";

            int pilihanAwal;
            try {
                if (!(cin >> pilihanAwal)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Pilihan harus berupa angka (0/1/2)!");
                }
                cin.ignore();
            } catch (const invalid_argument &e) {
                cout << "\n  [EXCEPTION] " << e.what() << "\n";
                cout << "  Tekan Enter untuk melanjutkan..."; cin.get();
                continue;
            }

            if (pilihanAwal == 1) {
                userLogin = loginUser(daftarUser, jumlahUser);
                if (userLogin != nullptr) {
                    cout << "\n  [OK] Login berhasil! Selamat datang, " << userLogin->nama << "\n";
                    cout << "  Tekan Enter untuk melanjutkan..."; cin.get();
                    sudahLogin = true;
                }
            } else if (pilihanAwal == 2) {
                registerUser(daftarUser, jumlahUser, MAX_USER);
                cout << "  Tekan Enter untuk melanjutkan..."; cin.get();
            } else if (pilihanAwal == 0) {
                cout << "\n  Sampai jumpa!\n\n"; return 0;
            } else {
                cout << "\n  [!] Pilihan tidak valid.\n";
                cout << "  Tekan Enter untuk melanjutkan..."; cin.get();
            }
        }


        bool jalan = true;
        while (jalan) {
            tampilBanner(userLogin);
            cout << "  +------------------------------------------+\n";
            cout << "  |            MENU UTAMA                    |\n";
            cout << "  +------------------------------------------+\n";
            cout << "  |  1. Tambah Data Pesawat   (Create)       |\n";
            cout << "  |  2. Lihat Semua Pesawat   (Read)         |\n";
            cout << "  |  3. Ubah Data Pesawat     (Update)       |\n";
            cout << "  |  4. Hapus Data Pesawat    (Delete)       |\n";
            cout << "  |  5. Lihat Daftar User                    |\n";
            cout << "  |  6. Sorting Data Pesawat     (Sort)      |\n";
            cout << "  |  7. Searching Data Pesawat   (Search)    |\n";
            cout << "  |  0. Logout                               |\n";
            cout << "  +------------------------------------------+\n";
            cout << "  Pilihan: ";

            int pilihan;
            try {
                if (!(cin >> pilihan)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Pilihan harus berupa angka (0-7)!");
                }
                cin.ignore();
            } catch (const invalid_argument &e) {
                cout << "\n  [EXCEPTION] " << e.what() << "\n";
                cout << "  Tekan Enter untuk kembali..."; cin.get();
                continue;
            }

            if      (pilihan == 1) { tambahPesawat(daftarPesawat, jumlahPesawat, idCounter, MAX_PESAWAT); }
            else if (pilihan == 2) { lihatPesawat(daftarPesawat, jumlahPesawat); }
            else if (pilihan == 3) { ubahPesawat(daftarPesawat, jumlahPesawat); }
            else if (pilihan == 4) { hapusPesawat(daftarPesawat, jumlahPesawat); }
            else if (pilihan == 5) { lihatUser(daftarUser, &jumlahUser); }
            else if (pilihan == 6) { menuSorting(daftarPesawat, jumlahPesawat); }
            else if (pilihan == 7) { menuSearching(daftarPesawat, jumlahPesawat); }
            else if (pilihan == 0) {
                cout << "\n  [OK] Logout berhasil. Kembali ke menu login...\n";
                userLogin = nullptr; jalan = false;
            } else {
                cout << "\n  [!] Pilihan tidak valid.\n";
            }

            if (pilihan != 0 && pilihan != 6 && pilihan != 7)
                { cout << "  Tekan Enter untuk kembali..."; cin.get(); }
        }
    }
    return 0;
}