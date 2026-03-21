#include <iostream>
using namespace std;

template <typename T>
struct pila
{
    int N_ELEM;
    T* arr;
    T* top;
    pila(int nro);
    ~pila();
    bool lleno();
    bool vacio();
    bool push(T val);
    bool pop(T& val);
};

template <typename T>
pila<T>::pila(int nro)
{
    N_ELEM = nro;
    arr = new T[N_ELEM];
    top = NULL;
}

template <typename T>
bool pila<T>::lleno()
{
    return top == arr + N_ELEM - 1;
}

template <typename T>
bool pila<T>::vacio()
{
    return !top;
}

template <typename T>
bool pila<T>::push(T val)
{
    if (vacio())
        top = arr;
    else
    {
        if (lleno())
            return false;
        else
            top++;
    }
    *top = val;
    return true;
}

template <typename T>
bool pila<T>::pop(T& val)
{
    if (vacio())
        return false;
    val = *top;
    if (top == arr)
        top = NULL;
    else
        top--;
    return true;
}

template <typename T>
pila<T>::~pila()
{
    delete[] arr;
}

int main()
{
    cout << "--- Pila de enteros ---" << endl;
    pila<int> p1(5);
    p1.push(10);
    p1.push(20);
    p1.push(30);
    p1.push(40);
    p1.push(50);
    cout << "Pila llena: " << (p1.lleno() ? "si" : "no") << endl;
    int ival;
    cout << "Extrayendo: ";
    while (p1.pop(ival))
        cout << ival << " ";
    cout << endl;

    cout << "\n--- Pila de doubles ---" << endl;
    pila<double> p2(3);
    p2.push(1.1);
    p2.push(2.2);
    p2.push(3.3);
    double dval;
    cout << "Extrayendo: ";
    while (p2.pop(dval))
        cout << dval << " ";
    cout << endl;

    cout << "\n--- Pila de chars ---" << endl;
    pila<char> p3(4);
    p3.push('a');
    p3.push('b');
    p3.push('c');
    p3.push('d');
    char cval;
    cout << "Extrayendo: ";
    while (p3.pop(cval))
        cout << cval << " ";
    cout << endl;

    return 0;
}
