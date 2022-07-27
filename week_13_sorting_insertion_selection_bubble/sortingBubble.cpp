// Programmer : Adam Rahmat Ilahi
// Thursday, 07 July 2022
// 
// Membuat program dengan konsep Bubble Sorting 
//

#include<iostream>

void swapping(int &a, int &b) { //memindah var a dan var b
   int bantu;
   bantu = a;
   a = b;
   b = bantu;
}

void display(int *array, int panjangArray) {
    for(int index = 0; index<panjangArray; index++){
      std::cout << array[index] << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(int *array, int panjangArray) {
    for(int i = 0; i<panjangArray; i++) {
        int swaps = 0; //bagian untuk mendeteksi swap lain
        for(int j = 0; j<panjangArray-i-1; j++) {
            if(array[j] > array[j+1]) { //when the current item is bigger than next
                swapping(array[j], array[j+1]);
                swaps = 1; //mengeset swap
            }
        }
        if(!swaps){
            break; // No swap in this pass, so array is sorted
        }
    }
}

int main(void) {
   int panjangArray;
   std::cout << "Input panjang dari data: ";
   std::cin >> panjangArray;

   int arr[panjangArray];    //membuat array dengan index dari input
   std::cout << "Input data:" << std::endl;
   for(int index = 0; index < panjangArray; index++) {
      std::cin >> arr[index];
   }

   std::cout << "Array sebelum di Sorting: ";
   display(arr, panjangArray);
   bubbleSort(arr, panjangArray);

   std::cout << "Array setelah di Sorting: ";
   display(arr, panjangArray);
}