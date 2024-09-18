#include "Date.h"
class Date {
private:
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y) {
        if (m >= 1 && m <= 12) {
            month = m;
        }
        else {
            month = 1;
        }
        day = d;
        year = y;
    }

    void displayDate() {
        cout << month << "/" << day << "/" << year << endl;
    }
};
int main() {
    Date date1(5, 15, 2024);
    date1.displayDate();

    Date date2(13, 15, 2024);
    date2.displayDate();

    return 0;
}
//cree una clase llamada Date que incluya 3 datos como miembro de la clase: month(de tipo int), day (de tipo int int). su clase debe tener un miembro constructor con tres parametros
//que utilice los parametros para inicializar los datos miembros de clase. para fines de este ejercicio suponga que los valores proporcionados para year y day son correctos, pero asegurese
//de que el valor month este en el rango de 1 a 12; si no es asi; establezca month en 1. Proporciones una funcion mimebros displayDate que muestre el mes, dia y año separados por barras
//diagonales (/). Esriba la funcion donde cree dos objetos de tipo date uno con el mes valido y otro con el mes invalido, imprima los vaolres de ambos objetos