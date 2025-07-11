#include <ctime>
#include <cstdlib>
#include <iostream>
#include "RedNeuronalUnaCapa.h"

using namespace std;

int main()
{
    srand(time(NULL));

    int num_entradas = 3;
    int num_neuronas = 2;

    RedNeuronalUnaCapa red_sigmoide(num_entradas, num_neuronas, 10);
    RedNeuronalUnaCapa red_relu(num_entradas, num_neuronas, 0);
    RedNeuronalUnaCapa red_tanh(num_entradas, num_neuronas, -1);

    double* entrada = new double[num_entradas];
    entrada[0] = 0.5;
    entrada[1] = -0.3;
    entrada[2] = 0.8;


    double* salida_sigmoide = red_sigmoide.propagar(entrada);
    cout << "Salida con funcion Sigmoide: " << endl;
    for (int i = 0; i < num_neuronas; i++) cout << salida_sigmoide[i] << " ";
    cout << endl;

    double* salida_relu = red_relu.propagar(entrada);
    cout << "Salida con funcion ReLu:" << endl;
    for (int i = 0; i < num_neuronas; i++) cout << salida_relu[i] << " ";
    cout << endl;

    double* salida_tanh = red_tanh.propagar(entrada);
    cout << "Salida con funcion Tanh:" << endl;
    for (int i = 0; i < num_neuronas; i++) cout << salida_tanh[i] << " ";
    cout << endl;

    cout << "\n--- Pesos de red Sigmoide ---" << endl;
    red_sigmoide.mostrar_pesos();

    cout << "\n--- Pesos de red ReLU ---" << endl;
    red_relu.mostrar_pesos();

    cout << "\n--- Pesos de red Tanh ---" << endl;
    red_tanh.mostrar_pesos();

    delete[] entrada;
    delete[] salida_sigmoide;
    delete[] salida_relu;
    delete[] salida_tanh;

    return 0;
}
