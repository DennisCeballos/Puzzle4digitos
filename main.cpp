#include <iostream>
#include <array>
#include <utility>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

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
    
    if (nroDigitos <= pos)
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

//
// Se podria simplificar estas operaciones solo con logica matematica, pero
// en pro de la _programacion funcional_ se recurrió a trabajar con estos argumentos
//

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

    // Array para representar los elementos ya visitados
    bool visitados[9999] = {false};

    // Pila para agregar a los nodos conforme se visitan (simula un recorrido por profundidad)
    std::stack<int> pilaElementos;
    pilaElementos.push(0);
    
    
    // Bucle para agregar los nodos
    int actual;
    while (!pilaElementos.empty())
    {
        //Obtiene el elemento encima
        actual = pilaElementos.top();
        pilaElementos.pop();

        // Agregar a la pila los valores de los movimientos posibles
        if ( !visitados[ operacionA(actual) ] )
        {
            //Se agrega a la pila solo en caso no se haya visitado
            pilaElementos.push(operacionA(actual));
            visitados[ operacionA(actual) ] = true;
        }

        if ( !visitados[ operacionB(actual) ] )
        {
            pilaElementos.push(operacionB(actual));
            visitados[ operacionB(actual) ] = true;
        }

        if ( !visitados[ operacionC(actual) ] )
        {
            pilaElementos.push(operacionC(actual));
            visitados[ operacionC(actual) ] = true;
        }

        if ( !visitados[ operacionD(actual) ] )
        {
            pilaElementos.push(operacionD(actual));
            visitados[ operacionD(actual) ] = true;
        }

        std::cout<<"Se reviso el numero :"<<actual<<std::endl;
    }

    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<"Termine de recorrer todos los nodos posibles"<<std::endl;
    std::cout<<"--------------------------------------------"<<std::endl;

    for (size_t i = 0; i < 9999; i++)
    {
        if (visitados[i] == false)
        {
            std::cout<<"No se genero el numero: "<<i<<std::endl;
        }
    }

    std::string rpta = "";
    while ( true )
    {
        std::cout<<"Ingresa el numero que quieras verificar (para salir es 'N')"<<std::endl;
        std::cin>>rpta;

        if (rpta == "N")
        {
            break;
        }
        
        if (visitados[std::stoi(rpta)])
        {
            std::cout<<std::endl<<"El numero si se encuentra "<<std::endl;
        }
    }
    
    return 0;
}