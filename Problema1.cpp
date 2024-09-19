#include <iostream>

void calcularSumaFibonacci(int& sum) {
    int a = 1, b = 2;
    while (b <= 4000000) {
        if (b % 2 == 0) {
            sum += b;
        }
        int next = a + b;
        a = b;
        b = next;
    }
}

void mostrarResultado(int sum) {
    std::cout << "La suma de los pares Fibonacci: " << sum << std::endl;
}

int main() {
    int sum = 0;
    calcularSumaFibonacci(sum);
    mostrarResultado(sum);
    return 0;
}