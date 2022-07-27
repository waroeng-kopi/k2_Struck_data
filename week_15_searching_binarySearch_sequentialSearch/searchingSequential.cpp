// Programmer : Adam Rahmat Ilahi
// Thursday, 07 July 2022
// 
// Membuat program dengan konsep Sequential Search
//

#include<iostream>

int main(void){
    int arr1[5];
    int req;
    int location=-5;
    std::cout<<"Enter 5 numbers to store in array: "<<std::endl;
    for(int i=0; i<5; i++){
        std::cin>>arr1[i];
    }
    std::cout<<std::endl;
    std::cout<<"Enter the number you want to find :";
    std::cin>>req;
    std::cout<<std::endl;
 
    for(int w=0;w<5;w++){
        if(arr1[w] == req){
            location=w;
        }
    }
    if(location !=-5){
        std::cout<<"Required number is found out at the location:"<<location+1;
        std::cout<<std::endl;
    }
    else{
        std::cout<<"Number is not found ";
    }
}