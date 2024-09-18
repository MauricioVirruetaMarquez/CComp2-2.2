#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Introduce un numero: ";
    cin >> n;

    for (int i = 2; i < n; i++) {
        int esPrimo = 1;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                esPrimo = 0; 
                break;
            }
        }
        if (esPrimo == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}

//implementa un programa que solicite un numero n e imprima todos los numeros primos menores a n.