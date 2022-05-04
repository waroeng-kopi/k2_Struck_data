// Programmer : Adam Rahmat Ilahi
// Saturday, 26 March 2022
// 
// Soal:
//          Membuat Program yang dapat menampilkan menu,
//      Yang dapat melakukan Konsep Linked List, yaitu :
//      Menambah Node, Menghapus Node, Mencari Node, 
//      Mengoutputkan Node.
//

#include <iostream>
#include <stdlib.h> // system("CLS")

// Class dari simpul
class Node {
public:
    int Nilai;
    Node* Next;
};

Node* Head = new Node(); // membuat Node untuk head

void Output_List(Node* n){
    while(n != NULL){
        std::cout << n->Nilai << " ";
        n = n->Next; // mengubah posisi dari Node awal ke Node berikutnya
    }
    std::cout << std::endl;

    int a = 1;
    n = Head;

    while(n != NULL){
        std::cout << a << " ";
        n = n->Next;
        a++;
    }
    std::cout << std::endl;
}

void Error_Msg(){
    std::cout << "Terjadi kesalahan, periksa kembali inputan" <<
    std::endl;
}

void TambahNode(int Data, int Posisi){
    Node* Bantu_1 = new Node();
    Bantu_1->Nilai = Data;
    Bantu_1->Next = NULL;

    if(Posisi == 1){
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

void HapusNode(int Data){
    Node* Bantu_1 = new Node();
    Bantu_1->Nilai = Data;
    
}

int main(void){
    int Pilihan, Pilihan_01, Pilihan_02, Pilihan_03;
    Head = NULL; // Memberi nilai NULL pada Head

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
                        if(Pilihan_02 >= 0 || Pilihan_02 <= 0){
                            TambahNode(Pilihan_02, Pilihan_03);
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
                            Node* n = Head;
                            int a = 1;

                            while(n->Next != NULL){
                                n = n->Next; // memindah posisi Next Node
                                a = a + 1; // agar proses penambahan terjadi di dalam loop (bukan diakhir loop)
                            }
                            
                            std::cout << "LOG : " << a << std::endl;
                            TambahNode(Pilihan_02, a);
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
            
        }

        else if(Pilihan == 3){
            
        }

        else if(Pilihan == 4){
            Output_List(Head);
        }

        else{
            Error_Msg();
        }
    }
}