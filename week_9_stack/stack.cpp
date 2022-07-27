// Programer : Adam Rahmat Ilahi
// Tuesday, 23 June 2022
//
// Soal: Membuat program dengan konsep stack (LIFO = Last In First Out)
//      Sediakan 2 buah stack
//      1. Stack pertama isi (PUSH) dengan data karakter :
//          'S','T','R','U','K','T','U','R'
//      2. Stack kedua isi (PUSH) dengan data karakter :
//          'D','A','T','A'
//      Kemudian lakukan keluarkan (POP) data dari stack secara bergantian, dimulai
//      dari stack pertama lalu ke stack kedua, dst dan cetak data yang sudah di-POP.
//      Sehingga output dari proses tersebut adalah : RAUTTAKDURTS
//

#include <iostream>

class stack {
public:
    char data;
    stack* link;
};

stack* stack_1 = NULL;
stack* stack_2 = NULL;

void Push1(char nilai){
    stack* Bantu = new stack();
    Bantu->data = nilai;
    Bantu->link = stack_1;
    stack_1 = Bantu;
}

void Push2(char nilai){
    stack* Bantu = new stack();
    Bantu->data = nilai;
    Bantu->link = stack_2;
    stack_2 = Bantu;
}

void Pop1(){
    stack* Bantu;
    if(stack_1 == NULL){
        return; // keluar dari Pop jika stack kosong
    }
    Bantu = stack_1;
    std::cout << Bantu->data << " ";
    stack_1 = stack_1->link;
    delete(Bantu);
}

void Pop2(){
    stack* Bantu;
    if(stack_2 == NULL){
        return; // keluar dari Pop jika stack kosong
    }
    Bantu = stack_2;
    std::cout << Bantu->data << " ";
    stack_2 = stack_2->link;
    delete(Bantu);
}

int main(void){
    char 
    nilai_stack_1 [] = {'S','T','R','U','K','T','U','R'},
    nilai_stack_2 [] = {'D','A','T','A'};
    
    // Push() process of stack 1
    for (int a = 0; a < 8; a++){
        Push1(nilai_stack_1[a]);
    }
    
    // Push() process of stack 2
    for (int a = 0; a < 4; a++){
        Push2(nilai_stack_2[a]);
    }
    
    // Pop() process of stack
    for (int a = 1; a <= 12; a++){
        Pop1();
        Pop2();
    }
    
}