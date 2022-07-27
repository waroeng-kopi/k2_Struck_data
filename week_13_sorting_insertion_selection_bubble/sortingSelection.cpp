// Programmer : Adam Rahmat Ilahi
// Thursday, 07 July 2022
// 
// Membuat program dengan konsep Selection Sorting 
//

#include<iostream>

void swapping(int &a, int &b) { //swap the content of a and b
   int bantu;
   bantu = a;
   a = b;
   b = bantu;
}

void display(int *array, int panjangArray) {
   for(int index = 0; index < panjangArray; index++)
      std::cout << array[index] << " ";
   std::cout << std::endl;
}

void selectionSort(int *array, int panjangArray) {
   int i, j, bantu;

   for(i = 0; i<panjangArray-1; i++) {
      bantu = i;//mendapatkan index data awal
      for(j = i+1; j<panjangArray; j++){
         if(array[j] < array[bantu]){
            bantu = j;
         }
      }
      //menempatkan posisi yang sebenarnya
      swapping(array[i], array[bantu]);
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
   selectionSort(arr, panjangArray);
   std::cout << "Array setelah di Sorting: ";
   display(arr, panjangArray);
}