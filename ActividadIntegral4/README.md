## Descripción
Este es la actividad integral de Luis Edgar Ramirez. En la que se registran la interconexión entre distintos aeropuertos del mundo. Lo que hace el programa es que modela esas relaciones en un grafo. En esta representación, que un nodo tenga pocos o muchos significa que hay menos o más destinos en los que se puede volar. Se puede buscar la ruta entre un aeropuerto inicial y un aeropuerto destino. Se utilizó el algoritmo Breadth First Search, como son muchas las conexiones entonces es más probalbe que llegue al destino en menor cantidad de pasos que si se hubiera usado un Depth First Search. También se puede buscar el aeropuerto que tiene más puntos de conexión. Los datos se obtienen al leer una tabla de datos en formato csv. Primero se obtienen todos los aeropuertos y se almacena solamente su código de identificación, luego se lee la tabla de relaciones y se almacenan en forma de arcos o "edges".

## Compilación y ejecución
Para compilar en Linux, ejecute en la terminal
~~~
clang++-7 -pthread -std=c++17 -o main main.cpp
~~~

Para correr en Linux, ejecute en la terminal
~~~
./main
~~~
El código se probó utulizando el editor de texto en línea Repl.it

## Complejidad del código
El programa usa una única estructura de datos: el vector. Esto nos permite tener la eficiencia de un arreglo pero al mismo tiempo la flexibilidad de la lista. 

#### BFS()
La complejidad temporal de este algoritmo es lineal o O(n+m) donde n es el número de nodos y m el número de arcos; porque, para el peor de los casos, debe de recorrer todos los nodos y todos los arcos.

#### node_with_more_conections()
La complejidad temporal es lineal o O(n) donde n es el número de nodeos. Esto por que a cada nodo va buscando el número de conexiones que tiene y va comparando uno por uno.


## Casos de prueba
#### Caso 1
~~~
[IN]: 1
[OUT]: MSP
~~~
#### Caso 2
~~~
[IN]: 2 ABE DTW
[OUT]: ABE DTW
~~~
#### Caso 3
~~~
[IN]: 2 ABQ SLC
[OUT]: ABQ HOU DAL ORD DFW PHX ATL SFO SAN IAH MDW PDX SLC
~~~
