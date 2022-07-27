// Programmer : Adam Rahmat Ilahi
// Tuesday, 08 March 2022
/*
//soal:
        Buatlah Program C++ untuk :
          Menginputkan dan mencetak data pegawai sebanyak n pegawai.
            Dimana data pegawai yang disimpan adalah : nama, npp 
            (nomer pokok pegawai), alamat, jenis kelamin, tangal 
            masuk (tangal masuk terdiri dari tangal, bulan dan tahun),
            status pegawai (meliputi pegawai honorer dan pegawai 
            tetap), gaji.
*/

#include <iostream>
#include <string>


struct Data_Pegawai {
    std::string nama, 
    npp,
    alamat,
    jenis_kelamin,
    status_pegawai;
    int gaji;
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
    int Input_arr, i = 0, Input;
    std::string dump;

    std::cout << "####################" <<
    std::endl << "PROGRAM DATA PEGAWAI" <<
    std::endl << "####################\n\n";
    std::cout << "Inputkan jumlah pegawai\t: ";
    std::cin >> Input_arr; // cin gift /n to getline() 

    Data_Pegawai pegawai[Input_arr];

    // Input Data
    for(i = 0; i < Input_arr; i++) {
        std::cout << std::endl;
        std::getline(std::cin, dump ); // dump /n string-c++

        std::cout << "INPUT DATA PEGAWAI KE-" << i+1 << std::endl;
        std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
        std::endl << " Input Nama\t\t: ";
        std::getline(std::cin, pegawai[i].nama);
        
        std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
        std::endl << "Input NPP\t\t: ";
        std::getline(std::cin, pegawai[i].npp);
        
        std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
        std::endl << "Input Alamat\t\t: ";
        std::getline(std::cin, pegawai[i].alamat);
   
        while (true){
            std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
            std::endl << "1. Pria                  " <<
            std::endl << "2. Wanita                " <<
            std::endl << "Input Jenis Kelamin\t: ";
            std::cin >> Input;
            
            if(Input == 1){
                pegawai[i].jenis_kelamin = "Pria";
                break;
            }
            else if (Input == 2){
                pegawai[i].jenis_kelamin = "Wanita";
                break;
            }
            else {
                Error_msg();
            }
        }   
        
        std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
        std::endl << "Input Tanggal Masuk (DD/MM/YYYY)" << 
        std::endl;
        // Date Input
        while(true){ 
            std::cout << "Tangal (1 - 31)\t\t: ";
            std::cin >> Input;
            if(Input <= 31 && Input >= 1){
                pegawai[i].tangal_masuk.tanggal = Input;
                break;
            }
            else {
                Error_msg();
            }
        }

        // Month Input
        while(true){
            std::cout << "Bulan (1 - 12)\t\t: ";
            std::cin >> Input;
            if(Input <= 12 && Input >= 1){
                pegawai[i].tangal_masuk.bulan = Input;
                break;
            }
            else {
                Error_msg();
            }
        }

        // Year Input
        while(true){
            std::cout << "Tahun\t\t\t: ";
            std::cin >> Input;
            if(Input >= 1){
                pegawai[i].tangal_masuk.tahun = Input;
                break;
            }
            else {
                Error_msg();
            }
        }

        while(true){
            std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
            std::endl << "1. Pegawai Tetap         " <<
            std::endl << "2. Pegawai Honorer       " <<
            std::endl << "Status Pegawai (1 / 2)\t:";
            std::cin >> Input;

            if(Input == 1){
                pegawai[i].status_pegawai = "Pegawai Tetap";
                break;
            }
            else if(Input == 2){
                pegawai[i].status_pegawai = "Pegawai Honorer";
                break;
            }
            else {
                Error_msg();
            }
        }

        std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
        std::endl << "Input gaji pegawai\t: ";
        std::cin >> pegawai[i].gaji;

    }

    std::cout << std::endl << std::endl;

    // Output Data
    for (i = 0; i < Input_arr; i++){
        std::cout << "OUTPUT DATA PEGAWAI KE-" << i+1 << std::endl <<
        std::endl << "Nama           : " << pegawai[i].nama <<
        std::endl << "NPP            : " << pegawai[i].npp <<
        std::endl << "Alamat         : " << pegawai[i].alamat <<
        std::endl << "Jenis Kelamin  : " << pegawai[i].jenis_kelamin <<
        std::endl << "Tanggal Masuk  : " << pegawai[i].tangal_masuk.tanggal <<
                "/" << pegawai[i].tangal_masuk.bulan <<
                "/" << pegawai[i].tangal_masuk.tahun <<
        std::endl << "Status Pegawai : " << pegawai[i].status_pegawai <<
        std::endl << "Gaji Pegawai   : " << pegawai[i].gaji <<
        std::endl << std::endl;
    }
}