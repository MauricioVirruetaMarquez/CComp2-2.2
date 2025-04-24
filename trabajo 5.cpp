#include <iostream>

using namespace std;

bool esPrimo(int num){
    if (num == 1) return false;
    for(int i = 2; i <num; i++){

        if(num%i==0)
            return false;
    }
    return true;
}
int contarPrimos(int arr[], int size){
    int *ptr= arr;
    int cont = 0;
    for (int i=0; i < size; i++, ptr++){
        if(esPrimo(*ptr)){
            cont++;
        }
    }

    return cont;
}
int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << contarPrimos(arr, size)<< endl;
    return 0;


}
