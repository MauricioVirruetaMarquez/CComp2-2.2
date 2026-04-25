#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

struct Movimiento {
    char letra;
    bool fueCorrecta;
    bool yaIntentada;
    int vidasAntes;
};

template <typename T>
void limpiarArreglo(T *arreglo, int tamano, T valor) {
    for (int i = 0; i < tamano; i++) {
        *(arreglo + i) = valor;
    }
}

template <typename T>
bool contieneElemento(T *arreglo, int cantidad, T valor) {
    for (int i = 0; i < cantidad; i++) {
        if (*(arreglo + i) == valor) {
            return true;
        }
    }
    return false;
}

char convertirMayuscula(char letra) {
    if (letra >= 'a' && letra <= 'z') {
        return letra - ('a' - 'A');
    }
    return letra;
}

bool esLetra(char letra) {
    return (letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z');
}

void limpiarPantalla() {
    system("cls");
}

void mostrarEstado(char *palabra, char *correctas, int vidas, char *incorrectas,
                   int cantidadIncorrectas, int retrocesosRestantes) {
    char *ptrPalabra = palabra;

    cout << "==============================\n";
    cout << "        JUEGO AHORCADO\n";
    cout << "==============================\n";
    cout << "Vidas: " << vidas << '\n';
    cout << "Retrocesos restantes: " << retrocesosRestantes << "\n\n";

    cout << "Palabra: ";
    while (*ptrPalabra != '\0') {
        if (*(correctas + (ptrPalabra - palabra)) != '_') {
            cout << *(correctas + (ptrPalabra - palabra)) << ' ';
        } else {
            cout << "_ ";
        }
        ptrPalabra++;
    }
    cout << "\n\n";

    cout << "Letras incorrectas: ";
    if (cantidadIncorrectas == 0) {
        cout << "(ninguna)";
    } else {
        for (int i = 0; i < cantidadIncorrectas; i++) {
            cout << *(incorrectas + i) << ' ';
        }
    }
    cout << "\n\n";
    cout << "Ingresa una letra. Usa ! para retroceder la ultima jugada.\n";
}

bool palabraCompleta(char *correctas, int longitud) {
    for (int i = 0; i < longitud; i++) {
        if (*(correctas + i) == '_') {
            return false;
        }
    }
    return true;
}

bool letraEnPalabra(char *palabra, char letra) {
    char *ptr = palabra;
    while (*ptr != '\0') {
        if (*ptr == letra) {
            return true;
        }
        ptr++;
    }
    return false;
}

void revelarLetra(char *palabra, char *correctas, char letra) {
    for (int i = 0; *(palabra + i) != '\0'; i++) {
        if (*(palabra + i) == letra) {
            *(correctas + i) = letra;
        }
    }
}

void quitarLetraRevelada(char *palabra, char *correctas, char letra) {
    for (int i = 0; *(palabra + i) != '\0'; i++) {
        if (*(palabra + i) == letra) {
            *(correctas + i) = '_';
        }
    }
}

void eliminarIncorrecta(char *incorrectas, int &cantidadIncorrectas, char letra) {
    int posicion = -1;

    for (int i = 0; i < cantidadIncorrectas; i++) {
        if (*(incorrectas + i) == letra) {
            posicion = i;
            break;
        }
    }

    if (posicion == -1) {
        return;
    }

    for (int i = posicion; i < cantidadIncorrectas - 1; i++) {
        *(incorrectas + i) = *(incorrectas + i + 1);
    }

    cantidadIncorrectas--;
    *(incorrectas + cantidadIncorrectas) = '\0';
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    char palabra0[] = "PROGRAMA";
    char palabra1[] = "COMPUTADORA";
    char palabra2[] = "TECLADO";
    char palabra3[] = "VENTANA";
    char palabra4[] = "MURCIELAGO";
    char palabra5[] = "UNIVERSIDAD";
    char palabra6[] = "CODIGO";
    char palabra7[] = "ALGORITMO";
    char palabra8[] = "VARIABLE";
    char palabra9[] = "DESARROLLO";

    char *palabras[10] = {
        palabra0, palabra1, palabra2, palabra3, palabra4,
        palabra5, palabra6, palabra7, palabra8, palabra9
    };

    const int vidasIniciales = 6;
    const int maxRetrocesos = 10;
    const int maxIntentos = 60;
    const int maxLongitud = 30;
    const int totalPalabras = 10;

    bool jugarDeNuevo = true;

    while (jugarDeNuevo) {
        char *palabra = *(palabras + (rand() % totalPalabras));
        int longitud = static_cast<int>(strlen(palabra));

        char correctas[maxLongitud];
        char incorrectas[26];
        char intentadas[26];
        Movimiento historial[maxIntentos];

        limpiarArreglo(correctas, maxLongitud, '\0');
        limpiarArreglo(incorrectas, 26, '\0');
        limpiarArreglo(intentadas, 26, '\0');

        for (int i = 0; i < longitud; i++) {
            *(correctas + i) = '_';
        }
        *(correctas + longitud) = '\0';

        int cantidadIncorrectas = 0;
        int cantidadIntentadas = 0;
        int cantidadMovimientos = 0;
        int vidas = vidasIniciales;
        int retrocesosUsados = 0;

        while (vidas > 0 && !palabraCompleta(correctas, longitud)) {
            limpiarPantalla();
            mostrarEstado(palabra, correctas, vidas, incorrectas, cantidadIncorrectas,
                          maxRetrocesos - retrocesosUsados);

            char entrada[20];
            cout << "Tu eleccion: ";
            if (!(cin >> entrada)) {
                cout << "\nEntrada finalizada. Cerrando el juego.\n";
                return 0;
            }

            if (*(entrada + 0) == '!' && *(entrada + 1) == '\0') {
                if (retrocesosUsados >= maxRetrocesos) {
                    cout << "\nYa usaste los 10 retrocesos permitidos.\n";
                    system("pause");
                    continue;
                }

                if (cantidadMovimientos == 0) {
                    cout << "\nNo hay jugadas para deshacer.\n";
                    system("pause");
                    continue;
                }

                Movimiento ultimo = *(historial + (cantidadMovimientos - 1));
                cantidadMovimientos--;
                retrocesosUsados++;
                vidas = ultimo.vidasAntes;

                if (!ultimo.yaIntentada) {
                    for (int i = 0; i < cantidadIntentadas; i++) {
                        if (*(intentadas + i) == ultimo.letra) {
                            for (int j = i; j < cantidadIntentadas - 1; j++) {
                                *(intentadas + j) = *(intentadas + j + 1);
                            }
                            cantidadIntentadas--;
                            *(intentadas + cantidadIntentadas) = '\0';
                            break;
                        }
                    }

                    if (ultimo.fueCorrecta) {
                        quitarLetraRevelada(palabra, correctas, ultimo.letra);
                    } else {
                        eliminarIncorrecta(incorrectas, cantidadIncorrectas, ultimo.letra);
                    }
                }
                continue;
            }

            char letra = convertirMayuscula(*(entrada + 0));

            if (!esLetra(letra) || *(entrada + 1) != '\0') {
                cout << "\nDebes ingresar solo una letra valida.\n";
                system("pause");
                continue;
            }

            bool yaIntentada = contieneElemento(intentadas, cantidadIntentadas, letra);
            bool fueCorrecta = letraEnPalabra(palabra, letra);

            if (cantidadMovimientos < maxIntentos) {
                Movimiento *mov = historial + cantidadMovimientos;
                mov->letra = letra;
                mov->fueCorrecta = fueCorrecta;
                mov->yaIntentada = yaIntentada;
                mov->vidasAntes = vidas;
                cantidadMovimientos++;
            }

            if (yaIntentada) {
                cout << "\nEsa letra ya fue usada antes. No cambia nada.\n";
                system("pause");
                continue;
            }

            *(intentadas + cantidadIntentadas) = letra;
            cantidadIntentadas++;
            *(intentadas + cantidadIntentadas) = '\0';

            if (fueCorrecta) {
                revelarLetra(palabra, correctas, letra);
                cout << "\nBien! La letra " << letra << " si esta en la palabra.\n";
            } else {
                *(incorrectas + cantidadIncorrectas) = letra;
                cantidadIncorrectas++;
                *(incorrectas + cantidadIncorrectas) = '\0';
                vidas--;
                cout << "\nLa letra " << letra << " no esta en la palabra.\n";
            }

            system("pause");
        }

        limpiarPantalla();
        if (palabraCompleta(correctas, longitud)) {
            cout << "Ganaste! La palabra era: " << palabra << "\n";
        } else {
            cout << "Perdiste. La palabra era: " << palabra << "\n";
        }

        cout << "\nQuieres jugar otra ronda? (S/N): ";
        char respuesta;
        if (!(cin >> respuesta)) {
            cout << "\nEntrada finalizada. Cerrando el juego.\n";
            return 0;
        }

        respuesta = convertirMayuscula(respuesta);
        jugarDeNuevo = (respuesta == 'S');
    }

    cout << "\nGracias por jugar.\n";
    return 0;
}
