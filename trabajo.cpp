#include <iostream>

using namespace std;

void insertSort(int arr[], int tam) {

    for(int i = 1; i < tam; i++){

        int actual = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > actual) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1 ] = actual;
    }

}

int main() {

    int arr[] = {5, 3, 4, 1};
    int tam = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    for (int i = 0; i < tam; i++)

        cout << arr[i] << " ";
        cout << endl;

        insertSort(arr, tam);

        cout<< "Array ordenado con insert sort: ";
        for (int i = 0; i < tam; i++)

            cout<< arr[i] <<" ";
            cout << endl;
            return 0;




}
