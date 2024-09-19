#include <iostream>

void esPalindromo(int num, int &resultado) {
    int original = num, volteado = 0;
    while (num > 0) {
        volteado = volteado * 10 + num % 10;
        num /= 10;
    }
    resultado = (original == volteado) ? 1 : 0;
}

void elPalindromomasGrande(int &PalindromoGrande) {
    for (int i = 999; i >= 100; --i) {
        for (int j = i; j >= 100; --j) {
            int producto = i * j;
            int esPal;
            esPalindromo(producto, esPal);
            if (esPal && producto > PalindromoGrande) {
                PalindromoGrande = producto;
            }
        }
    }
}

int main() {
    int PalindromoGrande = 0;
    elPalindromomasGrande(PalindromoGrande);
    std::cout << "El mayor palindromo producto de dos números de 3 dígitos es: " << PalindromoGrande << std::endl;
    return 0;
}
