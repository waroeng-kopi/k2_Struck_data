// Programer : Adam Rahmat Ilahi
// Tuesday, 22 March 2022
//
// Soal: Membuat sebuah singel Linked List pada Pointer
// yang dapat menambah, menghapus, mencari, dan mengoutputkan list
//

#include <iostream>
#include <stdlib.h> // system("CLS")

// Class dari simpul
//
//  entuk illustrasi dari simpul yang digunakan.
//  +---------+--------+
//  |  Nilai  |  Next  |--->
//  +---------+--------+
//

class Node {
public:
    int Nilai;
    Node* Next;
};

Node* Head = new Node(); // membuat Node untuk head

void Output_List(Node* n){
    while(n != NULL){
        std::cout << n->Nilai << " -> ";
        n = n->Next; // mengubah posisi dari Node awal ke Node berikutnya
    }
    std::cout << "NULL" << std::endl;
}

void Error_Msg(){
    std::cout << "Terjadi kesalahan, periksa kembali inputan" <<
    std::endl;
}

void TambahNode(int Data, int Posisi){
    Node* Bantu_1 = new Node();
    Bantu_1->Nilai = Data;

    if(Posisi <= 1){
        Bantu_1->Next = Head;
        Head = Bantu_1;
        return; // Menghentikan proses fungsi
    }

    Node* Bantu_2 = Head;

    for(int a = 0; a < Posisi-2; a++){
        Bantu_2 = Bantu_2->Next;
    }

    Bantu_1->Next = Bantu_2->Next;
    Bantu_2->Next = Bantu_1;
}

void HapusNode(int Posisi){
    Node* Bantu_1 = Head; // Mendapatkan nilai Head ke Bantu_1

    if(Posisi == 1){
        Head = Bantu_1->Next;
        delete Bantu_1;
        return;
    }

    for (int a = 0; a < Posisi-2; a++){
        Bantu_1 = Bantu_1->Next;
    }

    Node* Bantu_2 = Bantu_1->Next;
    Bantu_1->Next = Bantu_2->Next;
    delete Bantu_2;
    
}

int main(void){
    int Pilihan, Pilihan_01, Pilihan_02, Pilihan_03;
    Head = NULL; // Memberi nilai NULL pada Head
    int Bantu_Pcc = 1;

    // Menu Program
    while(true){
        std::cout << "#######################" <<
        std::endl << "#   Menu Pilihan :    #" <<
        std::endl << "#  1. Menambah Node   #" <<
        std::endl << "#  2. Menghapus Node  #" <<
        std::endl << "#  3. Mencari Node    #" <<
        std::endl << "#  4. Mencetak Node   #" <<
        std::endl << "#  0. Keluar          #" <<
        std::endl << "#######################" <<
        std::endl << "Pilihan : ";
        std::cin >> Pilihan;
        system("CLS"); // clear screen

        if(Pilihan == 0){
            break;
        }

        else if(Pilihan == 1){
            while(true){
                std::cout << "#######################" <<
                std::endl << "#   Menambah Node :   #" <<
                std::endl << "#  1. Di Depan Head   #" <<
                std::endl << "#  2. Setelah Node    #" <<
                std::endl << "#  3. Di Akhir Tail   #" <<
                std::endl << "#  0. Kembali         #" <<
                std::endl << "#######################" <<
                std::endl << "Pilihan : ";
                std::cin >> Pilihan_01;
                system("CLS");

                if(Pilihan_01 == 0){
                    break;
                }

                else if(Pilihan_01 == 1){
                    while(true){
                        std::cout << "Nilai yang ingin di inputkan : ";
                        std::cin >> Pilihan_02;
                        system("CLS");

                        // Memastikan inputan berupa bilangan Integer dan menghindari Error saat input nilai
                        if(Pilihan_02 >= 0 || Pilihan_02 <= 0){
                            TambahNode(Pilihan_02, 1);
                            break; // Keluar dari loop 1.1
                        }

                        else{
                            Error_Msg();
                        }
                    }
                    break; // keluar dari loop 1
                }

                else if(Pilihan_01 == 2){
                    while(true){
                        std::cout << "Nilai yang ingin di inputkan : ";
                        std::cin >> Pilihan_02;
                        std::cout << "Posisi Node : ";
                        std::cin >> Pilihan_03;
                        system("CLS");

                        // Memastikan inputan berupa bilangan Integer dan menghindari Error saat input nilai
                        Node* Bantu_1 = Head;
                        if(Pilihan_02 >= 0 || Pilihan_02 <= 0){
                            while (Bantu_1 != NULL){
                                Bantu_1 = Bantu_1->Next;
                                if (Bantu_Pcc == Pilihan_03){
                                    break;
                                }
                                Bantu_Pcc++;
                            }
                            TambahNode(Pilihan_02, Bantu_Pcc);
                            Bantu_Pcc = 1;
                            break;
                        }
                        else{
                            Error_Msg();
                        } 
                    }
                    break;
                }

                else if(Pilihan_01 == 3){
                    while(true){
                        std::cout << "Nilai yang ingin di inputkan : ";
                        std::cin >> Pilihan_02;
                        system("CLS");

                        // Memastikan inputan berupa bilangan Integer dan menghindari Error saat input nilai
                        if(Pilihan_02 >= 0 || Pilihan_02 <= 0){
                            // mencari posisi terakhir dari Node
                            Node* Bantu_1 = Head;
                            while(Bantu_1 != NULL){
                                Bantu_1 = Bantu_1->Next; // memindah posisi Next Node
                                Bantu_Pcc++; // agar proses penambahan terjadi di dalam loop (bukan diakhir loop)
                            }
                            
                            TambahNode(Pilihan_02, Bantu_Pcc);
                            Bantu_Pcc = 1;
                            break;
                        }
                        else{
                            Error_Msg();
                        } 
                    }
                    break;
                }

                else{
                    Error_Msg();
                }
            }
        }

        else if(Pilihan == 2){
            std::cout << "Nilai yang ingin di hapus : ";
            std::cin >> Pilihan_01;
            system("CLS");

            Node* Bantu_1 = Head;
            while(Bantu_1 != NULL){
                if(Bantu_1->Nilai == Pilihan_01){
                    HapusNode(Bantu_Pcc);
                    Bantu_Pcc = 1;
                    break;
                }
                else{
                    Bantu_1 = Bantu_1->Next;
                }
                Bantu_Pcc++;
            }
            if(Bantu_1 == NULL){
                std::cout << "Data yang ingin dicari tidak ada" << std::endl;
            }
        }

        else if(Pilihan == 3){
            std::cout << "Nilai yang ingin di cari : ";
            std::cin >> Pilihan_01;
            system("CLS");

            Node* Bantu_1 = Head;

            while (Bantu_1 != NULL)
            {
                if(Bantu_1->Nilai == Pilihan_01){
                    std::cout << Bantu_1->Nilai << " ada di index ke-" << Bantu_Pcc << std::endl;
                    break;
                }
                Bantu_1 = Bantu_1->Next;
                Bantu_Pcc++;
            }
            if(Bantu_1 == NULL){
                std::cout << "Data yang ingin dicari tidak ada" << std::endl;
            }
            
        }

        else if(Pilihan == 4){
            Output_List(Head);
        }

        else{
            Error_Msg();
        }
    }
}