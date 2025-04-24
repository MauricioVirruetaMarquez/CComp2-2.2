#include <iostream>

using namespace std;


void printArr(int arr[], int size) {
 int tam = sizeof(arr) / sizeof(arr[0]);
 int i = 0;
 int *ptr;
 cout<<"[";
    while(i < tam){
        ptr = &arr[i];

        cout << *ptr <<" ";
    i++;
    }
  cout<< "]";
}

int main() {

 int arr[6] = {1,2,3,4,5,6};
 int tam = sizeof(arr) / sizeof(arr[0]);
 int *ptr;
 ptr = &arr[0];
 cout<< ptr << endl;
 cout<< *ptr<< endl;
  ptr = &arr[1];
 cout<< ptr << endl;
 cout<< *ptr<< endl;
  ptr = &arr[2];
 cout<< ptr << endl;
 cout<< *ptr<< endl;
  ptr = &arr[3];
 cout<< ptr << endl;
 cout<< *ptr<< endl;
  ptr = &arr[4];
 cout<< ptr << endl;
 cout<< *ptr<< endl;
  ptr = &arr[5];
 cout<< ptr << endl;
 cout<< *ptr<< endl;


 cout<< arr << endl;
 cout<< *arr <<endl;
    printArr(arr, tam);
}
