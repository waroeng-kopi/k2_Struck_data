// Programmer : Adam Rahmat Ilahi
// Saturday, 26 March 2022
// 
// Soal:
//          Buatlah program C++ untuk menginputkan n data (simpul),
//      kemudian cetak semua simpul
//      Note : Setiap kali input simpul baru harus langsung dicetak/ditampilkan
//      Setelah itu lakukan hapus data pada simpul
//      Kemudian lakukan pencarian data pada simpul 
//

#include <iostream>

class Node{
public:
    int Nilai;
    Node* Next;
};

// membuat simpul baru
Node* Head = new Node();

void Output_Simpul(Node* n){
    while (n != NULL){
        std::cout << n->Nilai << " -> ";
        n = n->Next; // mengubah 
    }
    std::cout << std::endl;
}

void Input_Simpul(int Nilai_Input, int Index){
    Node* Bantu_1 = new Node();
    Bantu_1->Nilai = Nilai_Input;
    
    if(Index == 1){
        Bantu_1->Next = Head;
        Head = Bantu_1;
        return; // Menghentikan proses fungsi
    }

    Node* Bantu_2 = Head;

    for(int a = 0; a < Index-2; a++){
        Bantu_2 = Bantu_2->Next;
    }

    Bantu_1->Next = Bantu_2->Next;
    Bantu_2->Next = Bantu_1;
}

void Hapus_Simpul(int Posisi){
    Node* Bantu_1 = Head;

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

int main(){
    int Input_JML_Data, Input_Nilai, Input_Index, Input_Hapus, Input_Cari;
    Head = NULL;

    std::cout << "+----------------------+" <<
    std::endl << "|  Program REMIDI UTS  |" << 
    std::endl << "+----------------------+" <<
    std::endl;

    std::cout << "Input jumlah data yang hendak digunakan : ";
    std::cin >> Input_JML_Data;

    // proses input dan cetak semua list
    for (int i = 1; i <= Input_JML_Data; i++){

        // input Simpul->Nilai
        std::cout << "Input Simpul ke-" << i << " : ";
        std::cin >> Input_Nilai;

        // input Simpul->Index
        std::cout << "Input Posisi dari simpul : ";
        std::cin >> Input_Index;

        // auto menangani error pada input index 1
        if (Input_Index > i && Head == NULL|| Input_Index <= 0 ){
            Input_Index = 1;
        }

        else if(Input_Index > i){
            Input_Index = i;
        }
        Input_Simpul(Input_Nilai, Input_Index);
        Output_Simpul(Head);
    }

    // proses hapus data pada list
    std::cout << 
    std::endl << "Hapus Simpul : ";
    std::cin >> Input_Hapus;
    
    Node* Bantu_1 = Head;

    for (int i = 1; i <= Input_JML_Data; i++){
        if(Bantu_1->Nilai == Input_Hapus){
            Hapus_Simpul(i);
            break;
        }
        else{
            Bantu_1 = Bantu_1->Next;
        }
        if(i == Input_JML_Data){
            std::cout << "Data yang ingin dihapus tidak ada" << std::endl;
        }
    }
    Output_Simpul(Head);

    // proses mencari data pada list
    std::cout <<
    std::endl << "Mencari Simpul : ";
    std::cin >> Input_Cari;

    for (int i = 1; i <= Input_JML_Data; i++){
        if(Bantu_1->Nilai == Input_Cari){
            std::cout << Bantu_1->Nilai << " ada di index ke-" << i << std::endl;
            break;
        }
        else{
            Bantu_1 = Bantu_1->Next;
        }
        if(i == Input_JML_Data){
            std::cout << "Data yang ingin dicari tidak ada" << std::endl;
        }
    }
    Output_Simpul(Head);

    return 0;
}