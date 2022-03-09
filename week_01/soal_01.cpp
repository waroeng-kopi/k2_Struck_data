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
#include <string>


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

void Error_msg(){
    std::cout << "Terjadi masalah pada inputan, periksa kembali kesalahan." << std::endl;
}

int main(void){
    int input, i;

    std::cout << "PROGRAM DATA PEGAWAI\n\n";
    std::cout << "Inputkan jumlah pegawai : ";
    std::cin >> input;

    Data_Pegawai pegawai[input];

    for(i = 0; i < input; i++) {
        std::cout << "Input nama : "; fflush(stdin);
        std::getline(std::cin, pegawai[i].nama);
        std::cout << "Input npp : ";
        std::getline(std::cin, pegawai[i].npp);
        std::cout << "Input alamat : ";
        std::getline(std::cin, pegawai[i].alamat);
        std::cout << "Input jenis kelamin (p = pria / w = wanita) : ";
        std::getline(std::cin, pegawai[i].jenis_kelamin);
        for (int j = 0; j < pegawai[i].jenis_kelamin.length(); j++){
            pegawai[i].jenis_kelamin[j] = tolower(pegawai[i].jenis_kelamin[j]);
            if (strcmp(pegawai[i].jenis_kelamin[j],"p")==0 || strcmp(pegawai[i].jenis_kelamin[j],"w")==0){
                break;
            }
            else{
                std::cout << "input haruslah 'p' atau 'w'" << std::endl;
            }
        }
        
        while(true){
            std::cout << "Input status pegawai (tetap / honorer) : ";
            std::getline(std::cin, pegawai[i].status_pegawai);
            if(strcmp(pegawai[i].status_pegawai,"tetap")==0 || strcmp(pegawai[i].status_pegawai,"honorer")==0){
                break;
            }
            else{
                std::cout << "input haruslah 'tetap' / 'honorer'" << std::endl;
            }           
        }

    }
}