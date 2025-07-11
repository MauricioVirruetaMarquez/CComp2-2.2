#ifndef RED_NEURONAL_UNA_CAPA_H
#define RED_NEURONAL_UNA_CAPA_H


class RedNeuronalUnaCapa
{
private:
	int num_entradas;
	int num_neuronas;
	double** pesos;
	double* sesgos;
	double (*funcion_activacion)(double);

public:
	RedNeuronalUnaCapa(int entradas, int neuronas, int tipo_funcion);
	~RedNeuronalUnaCapa();

	double* propagar(double* entrada);
	void mostrar_pesos();
};

#endif

