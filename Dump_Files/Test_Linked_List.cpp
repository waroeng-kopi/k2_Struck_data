#include <iostream>

class Node{
public:
    int Data;
    Node* Next;
};

Node* Head;

void Insert(int Data, int n){
    Node* temp1 = new Node();
    temp1->Data = Data;
    temp1->Next = NULL;

    if(n == 1){
        temp1->Next = Head;
        Head = temp1;
        return; // Exit Function
    }

    Node* temp2 = Head;

    for(int i = 0; i < n-2; i++){
        temp2 = temp2->Next;
    }

    temp1->Next = temp2->Next;
    temp2->Next = temp1;
}

void Print(){
    Node* temp = Head;
    while(temp != NULL){
        std::cout << temp->Data << " : " << temp->Next << std::endl;
        temp = temp->Next; // change Next Node
    }
    std::cout << std::endl;
}

int main(void){
    Head = NULL; // empty list
    Insert(2, 1); // list: 2
    Insert(3, 2); // list: 2,3
    Insert(4, 1); // list: 4,2,3
    Insert(5, 2); // list: 4,5,2,3
    Insert(6, 1); // list: 6,4,5,2,3
    Insert(7, 6); // list: 6,4,5,2,3,7
    Print();
}