#include <iostream>
#include <array>
#include <utility>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

enum Movimientos
{
    A, //Significa sumar 0011 al numero
    B, //Significa sumar 0111 al numero
    C, //Significa sumar 1110 al numero
    D  //Significa sumar 1100 al numero
};

//Recibe un 'numero' y retorna el digito que se encuentre en la posicion 'pos'
int intPosicion(int numero, int pos)
{
    int divisor = static_cast<int>(std::pow(10, pos));
    return ( numero / divisor) % 10;
}

//Recibe un 'numero' y le asigna el valor 'nuevoVal' al digito en la posicion 'pos'
int setPos(int numero, int pos, int nuevoVal)
{
    std::vector<int> elementos;
    elementos.resize(std::to_string(numero).length());
    
    for (size_t i = 0; i < elementos.size(); i++)
    {
        elementos[i] = intPosicion(numero, i);
    }
    return elementos[0];
}

int opSuma(int valor, Movimientos movimiento)
{
    switch (movimiento)
    {
    case Movimientos::A:
        if ( intPosicion(valor, 4)==9 )
        {

        }
        return valor+11;
        break;
    
    default:
        return 0;
        break;
    }

}

int main()
{
    // Grafo para representar todos los nodos
    std::array<std::array<std::pair<int, int>, 4>, 9999> grafo;
    // ARRAY [ ARRAY [par int-int] ]
    // Es un array de 9999 que contiene un array de 4 que cada uno contiene un par de enteros
    /*Se ve de la siguiente forma aprox
    pos 0               -  pos 1             - ...
    [elementoA, peso]   -  [elementoA, peso] - ...
    [elementoB, peso]   -  [elementoA, peso] - ...
    [elementoC, peso]   -  [elementoA, peso] - ...
    [elementoD, peso]   -  [elementoA, peso] - ...
    */

    std::stack<int> pilaElementos;
    pilaElementos.push(0);
    /*
    int actual;
    while (!pilaElementos.empty())
    {
        //Obtiene el elemento encima
        actual = pilaElementos.top();
        pilaElementos.pop();

        //Agregar a la pila el primer valor del movimiento

        


    }*/
    int hola = 9876;
    std::cout<<intPosicion(hola, 0)<<std::endl;
    std::cout<<intPosicion(hola, 1)<<std::endl;
    std::cout<<intPosicion(hola, 2)<<std::endl;
    std::cout<<intPosicion(hola, 3)<<std::endl;
    
}