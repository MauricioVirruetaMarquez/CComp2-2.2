#include "RedNeuronalUnaCapa.h"
#include "FuncionesActivacion.h"
#include <cstdlib>
#include <iostream>

using namespace std;

RedNeuronalUnaCapa::RedNeuronalUnaCapa(int entradas, int neuronas, int tipo_funcion) {
	num_entradas = entradas;
	num_neuronas = neuronas;

	switch (tipo_funcion) {
	case 1:
		funcion_activacion = sigmoide;
		break;
	case 2:
		funcion_activacion = relu;
		break;
	case 3:
		funcion_activacion = tanh_activacion;
		break;
	default:
		funcion_activacion = sigmoide;
	}

	pesos = new double* [num_neuronas];
	for (int i = 0; i < num_neuronas; i++) {
		pesos[i] = new double[num_entradas];
		for (int j = 0; j < num_entradas; j++) {
			pesos[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
		}
	}

	sesgos = new double[num_neuronas];
	for (int i = 0; i < num_neuronas; i++) {
		sesgos[i] = ((double)rand() / RAND_MAX) * 2 - 1;
	}

}

RedNeuronalUnaCapa::~RedNeuronalUnaCapa() {
	for (int i = 0; i < num_neuronas; i++) {
		delete[] pesos[i];
	}
	delete[] pesos;
	delete[] sesgos;
}

double* RedNeuronalUnaCapa::propagar(double* entrada) {
	double* salida = new double[num_neuronas];

	for (int i = 0; i < num_neuronas; i++) {
		double suma = 0.0;
		for (int j = 0; j < num_entradas; j++) {
			suma += entrada[j] * pesos[i][j];
		}
		suma += sesgos[i];
		salida[i] = funcion_activacion(suma);
	}
	return salida;
}

void RedNeuronalUnaCapa::mostrar_pesos() {
	cout << "Pesos de la red:" << endl;
	for (int i = 0; i < num_neuronas; i++) {
		for (int j = 0; j < num_entradas; j++) {
			cout << pesos[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Sesgos:" << endl;
	for (int i = 0; i < num_entradas; i++) {
		cout << sesgos[i] << " ";
	}
	cout << endl;

}
