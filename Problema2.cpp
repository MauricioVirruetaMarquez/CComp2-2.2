#include <iostream>

void encontrarMayorFactorPrimo(long& numero, long& mayorFactorPrimo) {
    long factorActual = 2;
    while (numero > mayorFactorPrimo) {
        if ((numero % factorActual == 0) && (factorActual > mayorFactorPrimo)) {
            mayorFactorPrimo = factorActual;
            numero /= factorActual; 
        } else {
            ++factorActual;
        }
    }
}

void mostrarResultado(long mayorFactorPrimo) {
    std::cout << mayorFactorPrimo << "\n";
}

int main() {
    long numero = 600851475143; 
    long mayorFactorPrimo = 0;
    encontrarMayorFactorPrimo(numero, mayorFactorPrimo);
    mostrarResultado(mayorFactorPrimo);
    return 0;
}
