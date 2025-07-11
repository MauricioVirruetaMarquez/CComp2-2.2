#include "FuncionesActivacion.h"

double sigmoide(double x) {
	return 1.0 / (1.0 + exp(-x));
}

double relu(double x) {
	return (x > 0) ? x : 0;
}

double tanh_activacion(double x) {
	return tanh(x);
}