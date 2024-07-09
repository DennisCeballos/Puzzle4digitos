#include <iostream>
#include <array>
#include <utility>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

// 
// * Algoritmo Dijkstra *
//  Adaptado GeeksForGeeks
//

int NO_PARENT = -1;

// Function to print shortest path
// from source to currentVertex
// using parents array
void printPath(int currentVertex, std::vector<int> parents)
{
	// Base case : Source node has
	// been processed
	if (currentVertex == NO_PARENT) {
		return;
	}
	printPath(parents[currentVertex], parents);
	std::cout << currentVertex << " ";
}

// A utility function to print
// the constructed distances
// array and shortest paths
void printSolution(int startVertex, std::vector<int> distances, std::vector<int> parents)
{
	int nVertices = distances.size();
	std::cout << "Vertex\t Distance\tPath";

	for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
    {
		if (vertexIndex != startVertex)
        {
			std::cout << "\n" << startVertex << " -> ";
			std::cout << vertexIndex << " \t\t ";
			std::cout << distances[vertexIndex] << "\t\t";
			printPath(vertexIndex, parents);
		}
	}
}

// Function that implements Dijkstra's
// single source shortest path
// algorithm for a graph
void dijkstra(int nVertices, std::vector<std::vector<int>> adjacencyMatrix, int startVertex)
{
	// shortestDistances[i] will hold the
	// shortest distance from src to i
	std::vector<int> shortestDistances(nVertices);

	// added[i] will true if vertex i is
	// included / in shortest path tree
	// or shortest distance from src to
	// i is finalized
	std::vector<bool> added(nVertices);

	// Initialize all distances as
	// INFINITE and added[] as false
	for (int vertexIndex = 0; vertexIndex < nVertices;
		vertexIndex++) {
		shortestDistances[vertexIndex] = INT_MAX;
		added[vertexIndex] = false;
	}

	// Distance of source vertex from
	// itself is always 0
	shortestDistances[startVertex] = 0;

	// Parent array to store shortest
	// path tree
	std::vector<int> parents(nVertices);

	// The starting vertex does not
	// have a parent
	parents[startVertex] = NO_PARENT;

	// Find shortest path for all
	// vertices
	for (int i = 1; i < nVertices; i++) {

		// Pick the minimum distance vertex
		// from the set of vertices not yet
		// processed. nearestVertex is
		// always equal to startNode in
		// first iteration.
		int nearestVertex = -1;
		int shortestDistance = INT_MAX;
		for (int vertexIndex = 0; vertexIndex < nVertices;
			vertexIndex++) {
			if (!added[vertexIndex]
				&& shortestDistances[vertexIndex]
					< shortestDistance) {
				nearestVertex = vertexIndex;
				shortestDistance
					= shortestDistances[vertexIndex];
			}
		}

		// Mark the picked vertex as
		// processed
		added[nearestVertex] = true;

		// Update dist value of the
		// adjacent vertices of the
		// picked vertex.
		for (int vertexIndex = 0; vertexIndex < nVertices;
			vertexIndex++) {
			int edgeDistance
				= adjacencyMatrix[nearestVertex]
								[vertexIndex];

			if (edgeDistance > 0
				&& ((shortestDistance + edgeDistance)
					< shortestDistances[vertexIndex])) {
				parents[vertexIndex] = nearestVertex;
				shortestDistances[vertexIndex]
					= shortestDistance + edgeDistance;
			}
		}
	}

	printSolution(startVertex, shortestDistances, parents);
}


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
    std::array<std::array<std::pair<int, int>, 4>, 10000> grafo;
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
    bool visitados[10000] = {false};

    // Pila para agregar a los nodos conforme se visitan (simula un recorrido por profundidad)
    std::stack<int> pilaElementos;
    pilaElementos.push(0);
    
    
    // Bucle para agregar los nodos
    int actual;
    int siguiente; //representa el numero *siguiente* al que apunta el nodo actual (variando a lo largo del bucle)
    while (!pilaElementos.empty())
    {
        //Obtiene el elemento encima
        actual = pilaElementos.top();
        pilaElementos.pop();

        //Impresion de Debug
        (actual%1000 == 0)? std::cout<<"Se esta revisando el numero :"<<actual<<std::endl : std::cout<<"";

        siguiente = operacionA(actual);
        // Agregar a la pila los valores de los movimientos posibles
        if ( !visitados[ siguiente ] )
        {
            //Se agrega a la pila solo en caso no se haya visitado
            pilaElementos.push( siguiente );
            visitados[ siguiente ] = true;
        }
        //Se agrega al array de conexiones de este mismo _nodo_
        grafo.at(actual).at(0) = { siguiente , 1}; //Por ahora el segundo valor del par se asigna siempre a 1


        siguiente = operacionB(actual);
        if ( !visitados[ siguiente ] )
        {
            pilaElementos.push( siguiente );
            visitados[ siguiente ] = true;

        }
        grafo.at(actual).at(1) = { siguiente , 1};


        siguiente = operacionC(actual);
        if ( !visitados[ operacionC(actual) ] )
        {
            pilaElementos.push(operacionC(actual));
            visitados[ operacionC(actual) ] = true;

        }
        grafo.at(actual).at(2) = { siguiente , 1};


        siguiente = operacionD(actual);
        if ( !visitados[ operacionD(actual) ] )
        {
            pilaElementos.push(operacionD(actual));
            visitados[ operacionD(actual) ] = true;

        }
        grafo.at(actual).at(3) = { siguiente , 1};
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

        if (rpta == "N" || rpta == "n")
        {
            break;
        }
        
        if (visitados[std::stoi(rpta)])
        {
            std::cout<<std::endl<<"El numero si se encuentra "<<std::endl;
        }
    }

    //Solo para verificar si funciona la asignacion de variables al ""grafo""
    for (int i = 0; i < 10; i++)
    {
        //
        //std::array<std::array<std::pair<int, int>, 4>, 9999> grafo;
        for ( std::pair<int, int> par : grafo.at(i))
        {
            std::cout<<i<<" "<<par.first<<std::endl;
        }
    }
    
    return 0;
}
