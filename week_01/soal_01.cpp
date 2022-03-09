// Programmer : Adam Rahmat Ilahi
// Tuesday, 08 March 2022
/*
//soal:
        Buatlah Program C++ untuk :
          Menginputkan dan mencetak data pegawai sebanyak n pegawai.
            Dimana data pegawai yang disimpan adalah : nama, npp (nomer 
            pokok pegawai), alamat, jenis kelamin, tangal masuk (tangal masuk
            terdiri dari tangal, bulan dan tahun), status pegawai (meliputi pegawai
            honorer dan pegawai tetap), gaji.
*/

#include <iostream>

struct Data_Pegawai {
    std::string nama, 
    npp,
    alamat,
    jenis_kelamin,
    status_pegawai,
    gaji;
    struct Tanggal_Masuk {
        int tanggal,
        bulan,
        tahun;
    }tangal_masuk;
};

int main(void){
    int input;

    std::cout << "PROGRAM DATA PEGAWAI\n\n";
    std::cout << "Inputkan jumlah pegawai : ";
    std::cin >> input;

    struct 
}