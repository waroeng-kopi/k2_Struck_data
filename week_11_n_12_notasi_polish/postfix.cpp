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

std::string StacktoArray(){
    Node* Bantu = Stack;
    std::string array;
    int angka = 0;

    do{
        array[angka] = Bantu->Data;
        Bantu = Bantu->Next;
        angka++;
    }while (Bantu != NULL);
    return array;
}

int main(void){
    Stack = NULL;
    Queue = NULL;
    std::string input,
    arrayStack;
    int panjangInput;

    std::cout << "Input notasi : ";
    std::getline(std::cin, input);

    for (int i = 0; i < input.length(); i++){
        // switch (input[i]){
        //     case '(':
        //         Push(input[i]);
        //         break;
        //     case ')':
        //         arrayStack = StacktoArray();
        //         for(int j = 0; j < arrayStack.length(); j++){
        //             // if(arrayStack[j] == '(' || arrayStack[j] == ')'){
        //             //     Pop();
        //             // }
        //             Pop();
        //         }
        //         break;
        //     case '^':
        //         Push(input[i]);
        //         break;
        //     case '/':
        //         Push(input[i]);
        //         break;
        //     case '*':
        //         Push(input[i]);
        //         break;
        //     case '-':
        //         Push(input[i]);
        //         break;
        //     case '+':
        //         Push(input[i]);
        //         break;
        //     default:
        //         Push(input[i]);
        //         break;
        // }

        if(input[i]=='('){
            Push(input[i]);
        }
        else if(input[i]==')'){
            arrayStack = StacktoArray();
            for(int j = 0; j < arrayStack.length(); j++){
                // if(arrayStack[j] == '(' || arrayStack[j] == ')'){
                //     Pop();
                // }
                Pop();
            }
        }
        else if(input[i]=='^'){
            Push(input[i]);
        }
        else if(input[i]=='/'){
            Push(input[i]);
        }
        else if(input[i]=='*'){
            Push(input[i]);
        }
        else if(input[i]=='-'){
            Push(input[i]);
        }
        else if(input[i]=='+'){
            Push(input[i]);
        }
        else{
            Push(input[i]);
        }
    }
}