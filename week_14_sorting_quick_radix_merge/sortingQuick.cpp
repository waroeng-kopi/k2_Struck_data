// Programmer : Adam Rahmat Ilahi
// Thursday, 07 July 2022
// 
// Membuat program dengan konsep Quick Sorting 
//

#include<iostream>

void swapping(int &a, int &b) { //membalik var a dan var b
   int bantu;
   bantu = a;
   a = b;
   b = bantu;
}

void display(int *array, int panjangArray) {
    for(int index = 0; index < panjangArray; index++){
        std::cout << array[index] << " ";
    }
    std::cout << std::endl;
}

int partition(int *array, int lower, int upper) {
   //menentukan lokasi dari pivot
   int pivot, start, end;
   pivot = array[lower];      //data pertama adalah pivot
   start = lower; end = upper;

   while(start < end) {
      while(array[start] <= pivot && start<end) {
         start++;      //start pointer pindah ke kanan
      }

      while(array[end] > pivot) {
         end--;      //end pointer pindah ke kiri
      }

      if(start < end) {
         swapping(array[start], array[end]); //menukar nilai terbesar dan terkecil
      }
   }

   array[lower] = array[end];
   array[end] = pivot;
   return end;
}

void quickSort(int *array, int left, int right) {
   int q;

   if(left < right) {
      q = partition(array, left, right);
      quickSort(array, left, q-1);    //mengurutkan sub-array kiri
      quickSort(array, q+1, right);   //mengurutkan sub-array kanan
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
   quickSort(arr, 0, panjangArray-1); //(n-1) untuk index terakhir
   std::cout << "Array setelah di Sorting: ";
   display(arr, panjangArray);
}