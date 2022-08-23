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

void Output_List(Node* n){
    while(n != NULL){
        std::cout << n->Nilai << " : " << n->Next << std::endl;
        n = n->Next; // mengubah posisi dari Node awal ke Node berikutnya
    }
}

void Error_Msg(){
    std::cout << "Terjadi kesalahan, periksa kembali inputan" <<
    std::endl;
}

void TambahNodeDepan(Node** Head_Awal, int Nilai_Baru){
    // Membuat Node baru dan memberinya nilai sesuai parameter
    Node* Node_Baru = new Node();
    Node_Baru->Nilai = Nilai_Baru;

    // Menaruh Node baru dengan menggunakan nilai pointer head
    Node_Baru->Next = *Head_Awal;

    // Menganti nilai head menjadi Node baru
    *Head_Awal = Node_Baru;
}

void TambahNodeSetelah(Node* Head_Awal, int Nilai_Baru){
    // menguji Node awal berbilai NULL
    if(Head_Awal == NULL){
        std::cout << "Node sebelumnya tidak boleh kososng" << std::endl;
        return; // keluar dari fungsi
    }

    // Membuat Node Baru
    Node* Node_Baru = new Node();
    Node* Node_Bantu = new Node();
    Node_Baru->Nilai = Nilai_Baru;

    Node_Bantu->Nilai = Head_Awal->Nilai;
    Node_Bantu->Next = Head_Awal->Next;



    // Mengambil nilai Head_Awal ke Node_Baru
    Node_Baru->Next = Head_Awal->Next;
    Head_Awal->Next = Node_Baru;
}

void TambahNodeBelakang(Node** Head_Awal, int Nilai_Baru){
    // Membuat Node baru
    Node* Node_Baru = new Node();
    Node_Baru->Nilai = Nilai_Baru;
    Node_Baru->Next = NULL;

    // Menguji Node apakah kosong
    if(*Head_Awal == NULL){
        *Head_Awal = Node_Baru;
        return;
    }

    // Mencari Node terakhir
    Node* Akhir = *Head_Awal; // Akhir mengambil nilai head

    // Mengulang Next Akhir untuk mencari Node terakhir
    while(Akhir->Next != NULL){
        Akhir = Akhir->Next;
    }

    // Ketika Node terakhir berhasil di temukan maka buat Node baru di akhir
    Akhir->Next = Node_Baru;
}

Node* Head = new Node(); // membuat Node untuk head

int main(void){
    int Pilihan, Pilihan_01, Pilihan_02, Posisi;

    
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
                            TambahNodeDepan(&Head, Pilihan_02);
                            break; // Keluar dari Loop 1.1
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
                        system("CLS");

                        // Memastikan inputan berupa bilangan Integer dan menghindari Error saat input nilai
                        if(Pilihan_02 >= 0 || Pilihan_02 <= 0){
                            
                            TambahNodeSetelah(Head, Pilihan_02);
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
                            
                            TambahNodeBelakang(&Head, Pilihan_02);
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