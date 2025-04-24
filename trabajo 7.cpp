#include <iostream>

using namespace std;

void printArr(int *arr, int size) {
 int *ptr = arr;
 cout<<"[";
 for(int i = 0; i<size; i++, ptr++){
    cout<< *ptr << " ";
 }
  cout<< "]"<<endl;
}

void duplicaElems(int *arr,int  size){
    int *ptr = arr;
    int suma = 0;
    for (int i=0; i < size; i++, arr++){
        *arr *= 2;

    }
}

int main() {
    int arr[]={1,2,3,4,5,6};
    int size = sizeof(arr)/ sizeof(arr[0]);

    printArr(arr, size);
    duplicaElems(arr, size);
    printArr(arr, size);

}
