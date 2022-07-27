// Programmer : Adam Rahmat Ilahi
// Tuesday, 05 july 2022
//
// Membuat program dengan konsep Insertion Sorting 
//

#include<iostream>

void display(int *array, int panjangArray) {
   for(int index = 0; index < panjangArray; index++){
      std::cout << array[index] << " ";
   }
   std::cout << std::endl;
}

void insertionSort(int *array, int panjangArray) {
   int bantu, j;
   for(int i = 1; i<panjangArray; i++) {
      bantu = array[i]; //variabel bantu menyimpan nilai dari array ke-i
      j = i;
      while(j > 0 && array[j-1]>bantu) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = bantu;   //array ke-j menyimpan nilai dari variabel bantu
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
   insertionSort(arr, panjangArray);
   std::cout << "Array setelah di Sorting: ";
   display(arr, panjangArray);
}