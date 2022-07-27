// Programmer : Adam Rahmat Ilahi
// Tuesday, 08 March 2022
/*
//soal:
        Buatlah Program C++ untuk :
          Membuat menu untuk :
            Menginputkan dan mencetak data mahasiswa sebanyak n mahasiswa.
            Dimana data mahasiswa yang disimpan adalah : nama, npm, jurusan
            (jurusan yang ada yaitu : T.Informatika, T.Elektro, T.Mesin, T.Sipil,
            T.Kimia, T.Industri), alamat, jenis kelamin, tepat / tangal lahir
            (tangal lahir meliputi tangal, bulan, tahun), umur, Indeks Prestasi (IP 
            terdiri dari IPS dan IPK).
*/

#include <iostream>
#include <string>

struct Data_MHS {
  std::string nama,
  npm,
  jurusan,
  alamat,
  jenis_kelamin;
  struct TTL {
    std::string tempat;
    int tanggal,
    bulan,
    tahun;
  }ttl;
  int umur;
  struct IP {
    float IPS,
    IPK;
  }ip;
};

void Error_msg(){
    std::cout << "Terjadi masalah pada inputan, periksa kembali kesalahan." << std::endl;
}

int main(void){
  int Input_arr, i;
  float Input;
  std::string dump;

  std::cout << "######################" <<
  std::endl << "PROGRAM DATA MAHASISWA" <<
  std::endl << "######################\n" <<
  std::endl << "Inputkan jumlah Mahasiswa : ";
  std::cin >> Input_arr;

  Data_MHS mhs[Input_arr];

  // Input Data
  for(i = 0; i < Input_arr; i++) {
    std::cout << std::endl;
    std::getline(std::cin, dump ); // dump /n string-c++

    std::cout << "INPUT DATA MAHASISWA KE-" << i+1 << std::endl;
    std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
    std::endl << " Input Nama\t\t: ";
    std::getline(std::cin, mhs[i].nama);
        
    std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
    std::endl << "Input NPM\t\t: ";
    std::getline(std::cin, mhs[i].npm);
        
    while(true){
      std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
      std::endl << "1. T.Informatika" <<
      std::endl << "2. T.Elektro" <<
      std::endl << "3. T.Mesin" <<
      std::endl << "4. T.Sipil" <<
      std::endl << "5. T.Kimia" <<
      std::endl << "6. T.Industri" <<
      std::endl << "Input Jurusan\t\t: ";
      std::cin >> Input;

      if(Input == 1){
        mhs[i].jurusan = "T.Informatika";
        break;
      }

      else if(Input == 2){
        mhs[i].jurusan = "T.Elektro";
        break;
      }

      else if(Input == 3){
        mhs[i].jurusan = "T.Mesin";
        break;
      }

      else if(Input == 4){
        mhs[i].jurusan = "T.Sipil";
        break;
      }

      else if(Input == 5){
        mhs[i].jurusan = "T.Kimia";
        break;
      }

      else if(Input == 6){
        mhs[i].jurusan = "T.Industri";
        break;
      }

      else {
        Error_msg();
      }
    }

    std::getline(std::cin, dump ); // dump /n string-c++

    std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
    std::endl << "Input Alamat\t\t: ";
    std::getline(std::cin, mhs[i].alamat);

    while (true){
      std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
      std::endl << "1. Pria                  " <<
      std::endl << "2. Wanita                " <<
      std::endl << "Input Jenis Kelamin\t: ";
      std::cin >> Input;
            
        if(Input == 1){
          mhs[i].jenis_kelamin = "Pria";
          break;
        }
        else if (Input == 2){
          mhs[i].jenis_kelamin = "Wanita";
          break;
        }
        else {
          Error_msg();
        }
      }
        
      std::getline(std::cin, dump ); // dump /n string-c++

      std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
      std::endl << "Input Tanggal Lahir (DD/MM/YYYY)" << 
      std::endl;
        
      std::cout << "Tempat\t\t\t: ";
      std::getline(std::cin, mhs[i].ttl.tempat);
        
      // Date Input
      while(true){ 
        std::cout << "Tangal (1 - 31)\t\t: ";
        std::cin >> Input;
        if(Input <= 31 && Input >= 1){
          mhs[i].ttl.tanggal = Input;
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
          mhs[i].ttl.bulan = Input;
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
          mhs[i].ttl.tahun = Input;
          break;
        }
        else {
          Error_msg();
        }
      }

      // Age Input
      while(true){
        std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
        std::endl << "Input Umur\t\t: ";
        std::cin >> mhs[i].umur;

        if(mhs[i].umur >= 1) {
          break;
        }
        else {
          Error_msg();
        }
      }

      // IPS Input
      while(true){
        std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
        std::endl << "Input IPS\t\t:";
        std::cin >> Input;

        if(Input >= 0.0 && Input <= 4.0){
          mhs[i].ip.IPS = Input;
          break;
        }
        else {
          Error_msg();
        }
      }

      // IPK Input
      while(true){
        std::cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+" <<
        std::endl << "Input IPK\t\t:";
        std::cin >> Input;

        if(Input >= 0.0 && Input <= 4.0){
          mhs[i].ip.IPK = Input;
          break;
        }
        else {
          Error_msg();
        }
      }
    }

    std::cout << std::endl << std::endl;

    // Output Data
    for (i = 0; i < Input_arr; i++){
        std::cout << "OUTPUT DATA MAHASISWA KE-" << i+1 << std::endl <<
        std::endl << "Nama           : " << mhs[i].nama <<
        std::endl << "NPP            : " << mhs[i].npm <<
        std::endl << "Alamat         : " << mhs[i].alamat <<
        std::endl << "Jenis Kelamin  : " << mhs[i].jenis_kelamin <<
        std::endl << "Tanggal Masuk  : " << mhs[i].ttl.tempat <<
                ", " << mhs[i].ttl.tanggal <<
                "/" << mhs[i].ttl.bulan <<
                "/" << mhs[i].ttl.tahun <<
        std::endl << "Umur           : " << mhs[i].umur <<
        std::endl << "IPS            : " << mhs[i].ip.IPS <<
        std::endl << "IPK            : " << mhs[i].ip.IPK <<
        std::endl << std::endl;
    }
  
}