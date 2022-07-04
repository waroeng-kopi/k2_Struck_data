// Programer : Adam Rahmat Ilahi
// Wednesday, 29 June 2022
//
//  Membuat program dengan konsep notasi polis postfix
//  

#include <iostream>
#include <string>

class Node{
public:
    char Data;
    Node* Next;
};

Node* Stack = new Node();
Node* Queue = new Node();
Node* front = new Node();

// stack
void Push(char nilai){
    Node* Bantu = new Node();
    Bantu->Data = nilai;
    Bantu->Next = Stack;
    Stack = Bantu;
}

void Pop(){
    Node* Bantu;
    if(Stack == NULL){
        return;
    }
    Bantu = Stack;
    if(Bantu->Data == '(' || Bantu->Data == ')'){
        Stack = Stack->Next;
        return;
    }
    std::cout << Bantu->Data << " ";
    Stack = Stack->Next;
    delete(Bantu);
}

// queue
void Enqueue(char Data){
    Node* Bantu_1 = new Node();
    Bantu_1->Data = Data;
    Bantu_1->Next = NULL;

    if(front == NULL){
        front = Bantu_1;
        return;
    }

    Node* Bantu_2 = front;

    while(Bantu_2->Next != NULL){
        Bantu_2 = Bantu_2->Next;
    }

    Bantu_1->Next = Bantu_2->Next;
    Bantu_2->Next = Bantu_1;
}

void Dequeue(){
    Node* Bantu_1 = front;

    front = Bantu_1->Next;
    delete Bantu_1;
    return;
}

int main(void){
    Stack = NULL;
    Queue = NULL;
    std::string input;
    int panjangInput;

    std::cout << "Input notasi : ";
    std::getline(std::cin, input);

    for (int i = 0; i < input.length(); i++){
        if(input[i] == '('){
            // push ke dalam stack
            Push(input[i]);
        }
        else if(input[i] == ')'){
            // pop stack dan enqueue sampai bertemu (
            while(true){
                Pop();
            }
        }
        else if(input[i] == '^'){
            Push(input[i]);
        }
        else if(input[i] == '/'){
            Push(input[i]);
        }
        else if(input[i] == '*'){
            Push(input[i]);
        }
        else if(input[i] == '-'){
            Push(input[i]);
        }
        else if(input[i] == '+'){
            Push(input[i]);
        }
        else if (input[i] >= 'A' && input[i] <= 'Z'){
            Enqueue(input[i]);
        }
        continue;
    }
}