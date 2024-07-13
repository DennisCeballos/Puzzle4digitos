#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

const int NRO_NUMEROS = 10000;
void coutINT(int); //Declaracion de la funcion para que pueda ser usada desde antes

//
// * Algoritmo Dijkstra *
//  Adaptado desde GeeksForGeeks
//

int NO_PARENT = -1;

// Function to print shortest path
// from source to currentVertex
// using parents array
void printPath(int currentVertex, std::vector<int> &parents)
{
    // Base case : Source node has
    // been processed
    if (currentVertex == NO_PARENT)
    {
        return;
    }
    printPath(parents[currentVertex], parents);
    coutINT( currentVertex ); std::cout << " ";
}

// A utility function to print
// the constructed distances
// array and shortest paths
void printHoleSolution(int startVertex, std::vector<int> &distances, std::vector<int> &parents)
{
    int nVertices = distances.size();
    std::cout << "Vertice\t\tDistancia\t\tCamino";

    for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
    {
        if (vertexIndex != startVertex)
        {
            std::cout << "\n"
                      << startVertex << " -> ";
            std::cout << vertexIndex << " \t\t ";
            std::cout << distances[vertexIndex] << "\t\t\t";
            printPath(vertexIndex, parents);
        }
    }
}

void printSolution_Especifico(int startVertex, int endVertex, std::vector<int> distances, std::vector<int> parents)
{
    std::cout << "Vertice \t\t Distancia \tCamino" << std::endl;
    coutINT( startVertex ); std::cout<< " -> "; coutINT( endVertex );
    std::cout<< " \t\t " << distances[endVertex] << "\t\t";
    printPath(endVertex, parents);
    std::cout<<std::endl;
}

// Function that implements Dijkstra's
// single source shortest path
// algorithm for a graph
// *en este caso ADAPTADO
void dijkstra(int nVertices, std::vector<std::vector<int>> adjacencyMatrix, int startVertex, std::vector<int> &shortestDistances, std::vector<int> &parents)
{
    // shortestDistances[i] will hold the
    // shortest distance from src to i
    //* en el codigo adaptado, este vector se recibe como referencia
    shortestDistances.clear();

    // added[i] will true if vertex i is
    // included / in shortest path tree
    // or shortest distance from src to
    // i is finalized
    std::vector<bool> added;

    // Initialize all distances as
    // INFINITE and added[] as false
    shortestDistances.resize(nVertices, INT_MAX);
    added.resize(nVertices, false);

    // Distance of source vertex from
    // itself is always 0
    shortestDistances[startVertex] = 0;

    // Parent array to store shortest
    // path tree
    //* en el codigo adaptado, este vector se recibe por referencia
    parents.clear();
    parents.resize(nVertices);

    // The starting vertex does not
    // have a parent
    parents[startVertex] = NO_PARENT;

    // Find shortest path for all
    // vertices
    for (int i = 1; i < nVertices; i++)
    {

        // Pick the minimum distance vertex ()
        // from the set of vertices not yet
        // processed. nearestVertex is
        // always equal to startNode in
        // first iteration.
        int nearestVertex = -1;
        int shortestDistance = INT_MAX;
        for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
        {
            if (!added[vertexIndex] && shortestDistances[vertexIndex] < shortestDistance)
            {
                nearestVertex = vertexIndex;
                shortestDistance = shortestDistances[vertexIndex];
            }
        }

        // Mark the picked vertex as
        // processed
        added[nearestVertex] = true;

        // Update dist value of the
        // adjacent vertices of the
        // picked vertex.
        for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
        {

            int edgeDistance = adjacencyMatrix[nearestVertex][vertexIndex];

            if (edgeDistance > 0 && ((shortestDistance + edgeDistance) < shortestDistances[vertexIndex]))
            {
                parents[vertexIndex] = nearestVertex;
                shortestDistances[vertexIndex] = shortestDistance + edgeDistance;
            }
        }
    }
}

//
//
// * Algoritmo Dijkstra *

// Imprime el numero de forma BONITA
// un numero siempre sera de tamano 4; "230" -> "0230", "65" -> "0065", "1" -> "0001"
void coutINT(int numero) //Reemplaza una linea de cout para imprimir un numero en formato "BONITO"
{
    std::cout << std::setw(4) << std::setfill('0') << numero;
}

// Recibe un 'numero' y retorna el digito que se encuentre en la posicion 'pos'
int digitoEn(int numero, int pos)
{
    int divisor = static_cast<int>(std::pow(10, pos));
    return (numero / divisor) % 10;
}

// Recibe un 'numero' y le asigna el valor 'nuevoVal' al digito en la posicion 'pos'
//  advertencia que las posiciones en los numeros se cuentan de derecha a izquierda
int cambiarDigito(int numero, int pos, int nuevoVal)
{
    // Crea un array de tamaño de nroDigitos en el numero
    std::vector<int> elementos;
    int nroDigitos = (int)std::to_string(numero).length();

    if (nroDigitos <= pos)
    {
        // En caso la posicion que se va reasignar es mayor al nroDigitos,
        nroDigitos = pos + 1;
        // para que el array sea del tamano adecuado
    }

    elementos.resize(nroDigitos);

    // Rellenar el array
    for (size_t i = 0; i < elementos.size(); i++)
    {
        elementos[i] = digitoEn(numero, i);
    }

    // Cambiar el valor del digito en la pos indicada
    //! las posiciones de los digitos de los numeros se cuentan de derecha a izquierda
    elementos[pos] = nuevoVal;

    // Retornar los digitos concatenados en un solo numero
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

// Operacion que se le puede aplicar a un numero
int operacionA(int numero)
{
    for (int i = 0; i <= 1; i++)
    {
        if (digitoEn(numero, i) == 9)
        {
            numero = cambiarDigito(numero, i, 0);
        }
        else
        {
            numero = cambiarDigito(numero, i, digitoEn(numero, i) + 1);
        }
    }
    return numero;
}

// Operacion que se le puede aplicar a un numero
int operacionB(int numero)
{
    for (int i = 0; i <= 2; i++)
    {
        if (digitoEn(numero, i) == 9)
        {
            numero = cambiarDigito(numero, i, 0);
        }
        else
        {
            numero = cambiarDigito(numero, i, digitoEn(numero, i) + 1);
        }
    }
    return numero;
}

// Operacion que se le puede aplicar a un numero
int operacionC(int numero)
{
    for (int i = 1; i <= 3; i++)
    {
        if (digitoEn(numero, i) == 9)
        {
            numero = cambiarDigito(numero, i, 0);
        }
        else
        {
            numero = cambiarDigito(numero, i, digitoEn(numero, i) + 1);
        }
    }
    return numero;
}

// Operacion que se le puede aplicar a un numero
int operacionD(int numero)
{
    for (int i = 2; i <= 3; i++)
    {
        if (digitoEn(numero, i) == 9)
        {
            numero = cambiarDigito(numero, i, 0);
        }
        else
        {
            numero = cambiarDigito(numero, i, digitoEn(numero, i) + 1);
        }
    }
    return numero;
}

int main()
{
    // Grafo para representar todos los nodos
    // se utiliza la tecnica de MATRIZ DE ADYACENCIA para la representacion
    std::vector<std::vector<int>> grafo(NRO_NUMEROS, std::vector<int>(NRO_NUMEROS, 0));

    // Array para representar los elementos ya visitados
    bool visitados[NRO_NUMEROS] = {false};
    visitados[0] = true;

    // Pila para agregar a los nodos conforme se visitan (simula un recorrido por profundidad)
    std::stack<int> pilaElementos;
    pilaElementos.push(0);

    // Bucle para agregar los nodos
    int actual;
    int siguiente; // representa el numero *siguiente* al que apunta el nodo actual (variando a lo largo del bucle)
    while (!pilaElementos.empty())
    {
        // Obtiene el elemento de encima
        actual = pilaElementos.top();
        pilaElementos.pop();

        // Impresion de Debug
        (actual % 1000 == 0) ? std::cout << "Se esta revisando el numero :" << actual << std::endl : std::cout << "";

        siguiente = operacionA(actual);
        // Agregar a la pila los valores de los movimientos posibles
        if (!visitados[siguiente])
        {
            // Se agrega a la pila solo en caso no se haya visitado
            pilaElementos.push(siguiente);
            visitados[siguiente] = true;
        }
        // Se agrega a la matriz de adyacencia
        grafo.at(actual).at(siguiente) = 1; // Por ahora el valor (peso) se asigna siempre a 1

        siguiente = operacionB(actual);
        if (!visitados[siguiente])
        {
            pilaElementos.push(siguiente);
            visitados[siguiente] = true;
        }
        grafo.at(actual).at(siguiente) = 1;

        siguiente = operacionC(actual);
        if (!visitados[operacionC(actual)])
        {
            pilaElementos.push(operacionC(actual));
            visitados[operacionC(actual)] = true;
        }
        grafo.at(actual).at(siguiente) = 1;

        siguiente = operacionD(actual);
        if (!visitados[operacionD(actual)])
        {
            pilaElementos.push(operacionD(actual));
            visitados[operacionD(actual)] = true;
        }
        grafo.at(actual).at(siguiente) = 1;
    }

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Termine de recorrer todos los nodos posibles" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    // Demostracino que TODOS los numeros (desde 0000 hasta 9999) han sido generados
    for (size_t i = 0; i < NRO_NUMEROS; i++)
    {
        if (visitados[i] == false)
        {
            std::cout << "No se genero el numero: " << i << std::endl;
        }
    }

    //* Calculo de rutas con Dijkstra

    // Crear las variables necesarias para la operacion de Dijsktra
    std::vector<int> shortestDistances;
    std::vector<int> parents;

    // Entrada de datos para formulario
    std::string inicio = "";
    std::string fin = "";
    std::string lastInicio = "pepe"; //tiene que desde el inicio ser distinto

    while (true)
    {
        std::cout << "(Para salir de la ejecucion, ingresa N o n en cualquiera de las opciones)" << std::endl;
        
        std::cout << "Ingresa el numero de partida" << std::endl;
        std::cin >> inicio;

        std::cout << "Ingresa el numero objetivo" << std::endl;
        std::cin >> fin;

        //Las entradas de datos no tienen ningun tipo de validacion
        //porque asumo que ningun PAYASITO va ingresar un valor no numerico para esta parte

        if ( inicio == "n" || inicio == "N" || fin == "n" || fin == "N" )
        {
            break;    
        }

        std::cout << " -- RUTA SOLUCION -- " << std::endl;
        
        if ( inicio != lastInicio )
        {
            // Ejecutar Dijkstra dado un nodo de inicio
            dijkstra(NRO_NUMEROS, grafo, std::stoi(inicio), shortestDistances, parents);
        }

        // Imprimir la solucion
        printSolution_Especifico(std::stoi(inicio), std::stoi(fin), shortestDistances, parents);
        std::cout << std::endl;

        // Se guarda la variable para no repetir el algoritmo de Dijkstra muchas veces
        lastInicio = inicio;
    }

    return 0;
}
