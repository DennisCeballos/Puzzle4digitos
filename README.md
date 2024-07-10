# Problema
Supongamos que tenemos un jueguito en el que se tiene un número de cuatro dígitos (por defecto empezando en 0000), y que se puede hacer cuatro movimientos:
* A : Aumentar en uno el valor de los primeros dos digitos,  ejem 0000 -> 0011
* B : Aumentar en uno el valor de los primeros tres digitos, ejem 0000 -> 0111
* C : Aumentar en uno el valor de los ultimos tres digitos,  ejem 0000 -> 1110
* D : Aumentar en uno el valor de los ultimos dos digitos,   ejem 0000 -> 1100

Para mantener la temática de _juego_, podemos hacer que cada número se comporte independientemente de los otro números y de forma cíclica. Es decir, se cumple que 9 + 1 = 0.

La pregunta: **¿Es posible conseguir todos los números desde 0000 hasta 9999 con esta operación?**

Con este programa de c++ se busca generar un grafo para poder verificar si todos los números se pueden generar con estas operaciones.
>(Podría hacerse con un simple array, pero prefiero mantener la idea de "grafo" porque la pregunta siguiente sería algo así como "cual es la ruta mínima para llegar de un número a tal otro").


## RESULTADOS
A primera instancia, parece ser que:
SÍ ES POSIBLE ALCANZAR TODOS LO NÚMEROS EXISTENTES
el codigo indica que se agregaron todos los elementos al array de "visitados" y por ende, todos los valores posibles desde 0000 hasta 9999 son alcanzables.

A continuación, la implementación de un algoritmo Dijkstra para encontrar movimientos para ir de un punto a otro.

# Representación del Grafo y Dijkstra
Ahora que sabemos que SÍ es posible alcanzar todos los números, implica que por cada par de números existe al menos un recorrido que los una.
Por lo cual ahora planeo que el código pueda retornar cuál es la forma más rápida de llegar desde una configuración de números hasta otra. Es decir, que pueda responder a preguntas de tipo: Si tuviera el número 4653, ¿qué movimientos debo hacer para llegar al número 5876?

Desde el principio expliqué que el problema se puede representar por medio de un grafo dirigido. Donde cada nodo es un número y las aristas de salida apuntan hacia los posibles numeros a los que se puede transformar el nodo inicial. Es por ello que, ante esta situación, se puede implementar un algoritmo como Dijkstra, para identificar ""rutas mínimas"" de un nodo a otro.
Basado en la implementación de Dijkstra de GeeksForGeeks, es necesario mantener la representación del grafo como una Matriz de adyacencia.