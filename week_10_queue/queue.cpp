// Programer : Adam Rahmat Ilahi
// Tuesday, 23 June 2022
//
// Soal: Membuat program dengan menggunakan konsep QUEUE 
//      (FIFO = FIrst In First Out)
//

#include <iostream>
#include <stdlib.h> // system("CLS")

class Queue {
public:
    int Data;
    Queue* Next;
};

Queue* front = new Queue();

void Print(Queue* n){
    while(n != NULL){
        std::cout << n->Data << " ";
        n = n->Next;
    }
}

void Enqueue(int Data){
    Queue* Bantu_1 = new Queue();
    Bantu_1->Data = Data;
    Bantu_1->Next = NULL;

    if(front == NULL){
        front = Bantu_1;
        return;
    }

    Queue* Bantu_2 = front;

    while(Bantu_2->Next != NULL){
        Bantu_2 = Bantu_2->Next;
    }

    Bantu_1->Next = Bantu_2->Next;
    Bantu_2->Next = Bantu_1;
}

void Dequeue(){
    Queue* Bantu_1 = front;

    front = Bantu_1->Next;
    delete Bantu_1;
    return;
}

int InputHandler(){
    int pilihan;

    std::cout << "Opsi : ";
    std::cin >> pilihan;

    while(!std::cin.good()){
        std::cout << "Error pada input" << std::endl;

        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');

        std::cout << "Opsi : ";
        std::cin >> pilihan;
    }

    return pilihan;
}

int main(void){
    int pilihan, input;
    front = NULL;

    while(true){
        std::cout << 
        std::endl << "+---------------------+" <<
        std::endl << "+  1. Enqueue         +" <<
        std::endl << "+  2. Dequeue         +" <<
        std::endl << "+  3. print of queue  +" <<
        std::endl << "+  0. Keluar          +" <<
        std::endl << "+---------------------+" <<
        std::endl;
        
        pilihan = InputHandler();

        // error input handler
        
        if(pilihan == 0){
            break; // exit loop 1
        }
        else if(pilihan == 1){
            std::cout << "Data yang ingin dimasukkan : ";
            std::cin >> input;
            Enqueue(input);
        }
        else if(pilihan == 2){
            Dequeue();
        }
        else if(pilihan == 3){
            Print(front);
        }
        else{
            std::cout << "Input harus diantara 0 sampai 3" << std::endl;
        }
    }
}