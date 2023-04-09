// =============================================================================
// Tarea 1a: Matrices Dinamicas, Constructores y Sobrecarga de Operadores
// =============================================================================
// 1. Utilizar unicamente los archivos de cabecera y codigo fuente provistos. Es
//    decir: main.cpp, foo.h y foo.cpp.
// 2. No se permite el uso de librerias adicionales.

#include "foo.h"

// Puede validar su codigo con la siguiente funcion main
int main(){
    srand(time(0));
    Matriz2D m1(3,4);
    Matriz2D m2(4,3);
    Matriz2D m3=m1*m2;
    cout<<m1<<"\n"<<m2<<"\n"<<m3;
}
