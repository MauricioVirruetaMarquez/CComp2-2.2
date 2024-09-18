#include <iostream>
using namespace std;

int main() {
    int suma = 0;
    for (int i = 1; i < 1000000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            suma += i;
        }
    }
    cout << "las suma de los mutiplos: " << suma << endl;
}