#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Introduce un numero entero: ";
    cin >> x;

    for (int i = 1; i <= x; i += 2) {
        if (i > 1) {
            cout << ",";
        }
        cout << i;
    }

    return 0;
}
//Implementar una programa que solicite un numero entero de N e imprima los numeros impares desde 1 hasta n separados por comas ojo al final de la impresion no debe tener , osea que si
//N= 10 imprima 1,3,5,9 sin coma al final