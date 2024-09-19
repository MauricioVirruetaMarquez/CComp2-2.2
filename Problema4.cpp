#include <iostream>

void esPrimo(int numero, bool &resultado) {
    resultado = true;
    if (numero <= 1) {
        resultado = false;
        return;
    }
    if (numero <= 3) {
        return;
    }
    if (numero % 2 == 0 || numero % 3 == 0) {
        resultado = false;
        return;
    }
    for (int i = 5; i * i <= numero; i += 6) {
        if (numero % i == 0 || numero % (i + 2) == 0) {
            resultado = false;
            return;
        }
    }
}
void encontrarPrimo(int objetivo, int &resultado) {
    int contador = 0;
    int numero = 1;
    bool es_primo;

    while (contador < objetivo) {
        numero++;
        esPrimo(numero, es_primo);
        if (es_primo) {
            contador++;
        }
    }
    resultado = numero;
}

int main() {
    int objetivo = 10001;
    int primo;

    encontrarPrimo(objetivo, primo);
    
    std::cout << "El 10001 st número primo es: " << primo << std::endl;
    return 0;
}
