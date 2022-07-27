// Programer : Adam Rahmat Ilahi
// Tuesday, 22 March 2022
//
// Soal: Membuat sebuah pointer sederhana
//

#include <iostream>

int main(void){
    int x = 0,
    y = 0,
    *p = &x,
    *q = &y,
    **pp = &p;

    std::cout << "Nilai x    : " << x <<
    std::endl << "Nilai y    : " << y <<
    std::endl << "Nilai *p   : " << p <<
    std::endl << "Nilai *q   : " << q <<
    std::endl << "Nilai **pp : " << pp;  

/*
    std::string buah = "Apel";  // membuat variabel buah bertipe string
    std::string * P_buah;       // membuat variabel pointer

    P_buah = &buah; // variabel P_buah menyimpan alamat dari variabel buah

    std::cout << "Variabel buah   : " << buah << std::endl;
    std::cout << "Alamat buah     : " << &buah << std::endl; // alamat variabel buah
    std::cout << "Variabel P_buah : " << P_buah << std::endl;
    std::cout << "Alamat P_buah   : " << &P_buah << std::endl; // alamat variabel P_buah
*/
}