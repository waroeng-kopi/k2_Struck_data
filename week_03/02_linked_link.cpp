// Programer : Adam Rahmat Ilahi
// Tuesday, 22 March 2022
//
// Soal: Membuat sebuah Linked Link pada Pointer
//

#include <iostream>

class Node {
public:
    int Data;
    Node* Next;
};

// fungsi untuk mengoutputkan isi dari list
void PrintList(Node* n){
    while (n != NULL){
        std::cout << n->Data << " ";
        n = n->Next;
        while (true){
            std::cout << " : " << n->Next << std::endl;
            break;
        }
    }
}

// Menambahkan Node di depan
void AddInFront(Node** head, int data_baru){
    // 1. Membuat Note baru
    Node* Node_Baru = new Node();
    Node_Baru->Data = data_baru;
    // 2. Menaruh Node baru di depan head
    Node_Baru->Next = *head;
    // 3. Memindah head awal ke point data_baru
    *head = Node_Baru;
}

// Menambah Node di belakang
void AddInEnd(Node** head, int data_baru){
    // 1. Membuat Note baru
    Node* Node_Baru = new Node();
    Node_Baru->Data = data_baru;
    Node_Baru->Next = NULL;
    // 2. Jika linked list empty, node_baru jadi head node
    if(*head == NULL){
        *head = Node_Baru;
        return;
    }
    // 3. Mencari Node terakhir
    Node* Last = *head;
    while (Last->Next != NULL){
        Last = Last->Next;
    }
    // 4. Menambahkan node_baru setelah Node terakhir
    Last->Next = Node_Baru;
}

// Menambah Node setelah Nodea
void AddInAfter(Node* Sebelumnya, int data_baru){
    // 1. menguji jika Node sebelumnya bernilai NULL
    if(Sebelumnya == NULL){
        std::cout << "Node sebelumnya tidak boleh NULL";
        return;
    }
    // 2. Mempersiapkan Node baru
    Node* Node_Baru = new Node();
    Node_Baru->Data = data_baru;
    // 3. Menginputkan Node baru setelah Node sebelumnya
    Node_Baru->Next = Sebelumnya->Next;
    Sebelumnya->Next = Node_Baru;
}

int main(void){
    // misal saya akan membuat 3 Node yaitu
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // untuk mengakses variabel data di dalam Node maka
    head->Data = 1; // misal data head saya beri nilai 1
    head->Next = second; // next Node setelah head adalah second

    second->Data = 2;
    second->Next = third;

    third->Data = 3;
    third->Next = NULL; // karena sudah tidak ada lagi node nya, maka third menjadi tail

    AddInFront(&head, -1);

    AddInAfter(head, 0);

    AddInEnd(&head, 4);

    PrintList(head); // untuk mengoutputkan semua list cukup menggunakan head saja karena nanti akan berhubungan
}