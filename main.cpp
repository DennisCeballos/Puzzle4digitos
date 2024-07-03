#include <iostream>
#include <array>
#include <utility>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

enum Movimientos
{
    A, //Significa hacer la operacion 0011 al numero
    B, //Significa hacer la operacion 0111 al numero
    C, //Significa hacer la operacion 1110 al numero
    D  //Significa hacer la operacion 1100 al numero
};

//Recibe un 'numero' y retorna el digito que se encuentre en la posicion 'pos'
int digitoEn(int numero, int pos)
{
    int divisor = static_cast<int>(std::pow(10, pos));
    return ( numero / divisor) % 10;
}

//Recibe un 'numero' y le asigna el valor 'nuevoVal' al digito en la posicion 'pos'
// advertencia que las posiciones en los numeros se cuentan de derecha a izquierda
int cambiarDigito(int numero, int pos, int nuevoVal)
{
    //Crea un array de tamaño de nroDigitos en el numero
    std::vector<int> elementos;
    int nroDigitos = (int) std::to_string(numero).length();
    
    if (nroDigitos < pos)
    {
        //En caso la posicion que se va reasignar es mayor al nroDigitos,
        nroDigitos = pos+1;
        //para que el array sea del tamano adecuado
    }

    elementos.resize(nroDigitos);
    
    //Rellenar el array
    for (size_t i = 0; i < elementos.size(); i++)
    {
        elementos[i] = digitoEn(numero, i);
    }

    //Cambiar el valor del digito en la pos indicada
    //!las posiciones de los digitos de los numeros se cuentan de derecha a izquierda
    elementos[pos] = nuevoVal;
    
    //Retornar los digitos concatenados en un solo numero
    int concatenado = 0;
    for (size_t i = 0; i < elementos.size(); i++)
    {
        concatenado = concatenado + elementos[i] * static_cast<int>(std::pow(10, i));
    }
    return concatenado;
    
}

//Operacion que se le puede aplicar a un numero
int operacionA(int numero)
{
    for (int i = 0; i <= 1; i++)
    {
        if ( digitoEn(numero, i)==9 )
        {
            numero = cambiarDigito(numero, i, 0);
        }
        else
        {
            numero = cambiarDigito(numero, i, digitoEn(numero,i)+1);
        }
    }
    return numero;
}

//Operacion que se le puede aplicar a un numero
int operacionB(int numero)
{
    for (int i = 0; i <= 2; i++)
    {
        if ( digitoEn(numero, i)==9 )
        {
            numero = cambiarDigito(numero, i, 0);
        }
        else
        {
            numero = cambiarDigito(numero, i, digitoEn(numero,i)+1);
        }
    }
    return numero;
}

//Operacion que se le puede aplicar a un numero
int operacionC(int numero)
{
    for (int i = 1; i <= 3; i++)
    {
        if ( digitoEn(numero, i)==9 )
        {
            numero = cambiarDigito(numero, i, 0);
        }
        else
        {
            numero = cambiarDigito(numero, i, digitoEn(numero,i)+1);
        }
    }
    return numero;
}

//Operacion que se le puede aplicar a un numero
int operacionD(int numero)
{
    for (int i = 2; i <= 3; i++)
    {
        if ( digitoEn(numero, i)==9 )
        {
            numero = cambiarDigito(numero, i, 0);
        }
        else
        {
            numero = cambiarDigito(numero, i, digitoEn(numero,i)+1);
        }
    }
    return numero;
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
    std::cout<<operacionD(hola)<<std::endl;
    
}