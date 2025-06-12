#include <iostream>
#include <vector>

using namespace std;


double exp_aprox(double x) {
    double result = 1.0 + x + x * x / 2 + x * x * x / 6 + x * x * x * x / 24 + x * x * x * x * x / 120;
    return result;
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp_aprox(-x));
}

double sigmoid_derivada(double x) {
    return x * (1.0 - x);  
}

unsigned int seed = 1;

double randomDouble() {
    seed = (1103515245 * seed + 12345) % 2147483648;
    return ((double)(seed % 10000) / 10000.0) * 2 - 1; 
}

// ================ NEURONA Y CAPAS ==================

class Neurona {
public:
    vector<double> pesos;
    double salida;
    double delta;

    Neurona(int numEntradas) {
        for (int i = 0; i < numEntradas; ++i)
            pesos.push_back(randomDouble());
    }

    double activar(const vector<double>& entradas) {
        double suma = 0.0;
        for (size_t i = 0; i < pesos.size(); ++i)
            suma += pesos[i] * entradas[i];
        salida = sigmoid(suma);
        return salida;
    }
};

class Capa {
public:
    vector<Neurona> neuronas;

    Capa(int numNeuronas, int numEntradasPorNeurona) {
        for (int i = 0; i < numNeuronas; ++i)
            neuronas.emplace_back(numEntradasPorNeurona);
    }

    vector<double> feedforward(const vector<double>& entradas) {
        vector<double> salidas;
        for (auto& neurona : neuronas)
            salidas.push_back(neurona.activar(entradas));
        return salidas;
    }
};

class RedNeuronal {
public:
    vector<Capa> capas;

    RedNeuronal(const vector<int>& arquitectura) {
        for (size_t i = 1; i < arquitectura.size(); ++i)
            capas.emplace_back(Capa(arquitectura[i], arquitectura[i - 1]));
    }

    vector<double> feedforward(const vector<double>& entradasIniciales) {
        vector<double> activaciones = entradasIniciales;
        for (auto& capa : capas)
            activaciones = capa.feedforward(activaciones);
        return activaciones;
    }
};

// ===================== MAIN =====================

int main() {
    const int numEntradas = 2;
    RedNeuronal red({ numEntradas, 2, 1 });

    // Leer entrada del usuario
    vector<double> entrada(numEntradas);
    cout << "Ingrese " << numEntradas << " valores de entrada:\n";
    for (int i = 0; i < numEntradas; ++i) {
        cout << "Entrada " << i + 1 << ": ";
        cin >> entrada[i];
    }

    // Ejecutar red
    vector<double> salida = red.feedforward(entrada);

    cout << "Salida de la red: " << salida[0] << endl;
    return 0;
}
