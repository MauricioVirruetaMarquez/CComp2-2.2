#include <iostream>

using namespace std;

void invertirArr(int *ini, int *fin) {
    while(ini < fin) {
        int tmp=*ini;
        *ini = *fin;
        *fin = tmp;
        ini++;
        fin--;

    }

}
void printArr(int *arr, int size) {
 int *ptr = arr;
 cout<<"[";
 for(int i = 0; i<size; i++, ptr++){
    cout<< *ptr << " ";
 }
  cout<< "]";
}


int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *inicio = arr;
    int *fin = arr + size -1;
    printArr(arr, size);
    invertirArr(inicio, fin);
    printArr(arr, size);
    return 0;

}
