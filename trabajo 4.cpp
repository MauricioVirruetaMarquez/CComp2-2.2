#include <iostream>

using namespace std;

int sumArr(int arr[], int size){
    int *ptr = arr;
    int suma=0;
    for(int i=0; i < size ; i++, ptr++){
        suma+=*ptr;
    }
    return suma;

}

int main() {
    int arr[]={1,2,3,4,5,6};
    int tam = sizeof(arr) / sizeof(arr[0]);
    cout <<sumArr(arr, tam)<<endl;
    return 0;

}
