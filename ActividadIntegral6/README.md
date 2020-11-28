## Descripción
Este es la actividad integral de Luis Edgar Ramirez. En ella se puede consultar el conjunto de datos sobre las emisiones de cárbono que producen los países durante un año a lo largo de la historia. Tiene un tamaño de cuatro columnas (país, código del país, año y emisiones totales) y 20,853 entradas. El usuario puede imprimir en consola toda la tabla o una porción de ella ingresando un rango; puede ordenar la tabla o una porción de ella, en base a una de las cuatro variables disponibes (entidad, el código, año y emisiones totales); y buscar cualquier valor en la tabla.

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

## Estructura nueva

#### Trie Tree
Los árboles Trie son un tipo de árbol específico para almacenar palabras de forma que cada nodo guarda  un character que pueden tener varias palabaras en común. Si recorremos un camino (path) hacia una de las hojas, encontraremos que se forma una palabra. Se usuan comúnmente para hacer algún tipo de validación de palabras. Por ejemplo, si un problema te da una lista de palabras y te preguntas  qué palabras comienzan con las letras "ca" entonces es sencillo usar un trie para reducir la complejidad de tiempo y no tener que buscar en todas las palabras. 

## Complejidad del código
El programa usa dos estructuras fundamentales, lista doblemente ligada para almacenar los datos en forma de una matriz de cadenas, y árbol binario que se usa únicamente para buscar valores. Para ordenar la matriz, se utiliza el Bubble Sort. Este no es el más eficiente, sin embargo se decidió usar este porque la longitud de la tabla no es de tamaño considerado para que la eficiencia juegue un papel fundamental, y estos algoritmos son mucho más fácilesde implementar y de leer, por lo que se le dio prioridad a esto, en vez de algoritmos que resulvan la tarea un poco más rápido.

#### Bubble Sort
La complejidad temporal de este algoritmo es menor que cuadrática. Sin embargo, contemplamos que para el peor de los casos la complejidad se redondea a cuadrática, O(n^2). 

#### Sequential Search (Binary Search Tree)
La complejida temporal de la función es logarítmica para el promedio de los casos, porque por cada iteración, el algoritmo descarta la mitad de los valores. Sin embargo, se puede dar el caso de que el árbol se haya creado de forma degenerada, y eso aumentaría el tiempo de búsqueda a O(n).

#### Add Word (Trie Tree)
La función insert() recibe como parámetro un string que contenga una palabra y esta será añadida al Trie. Cada caracter de la palabra será almacenada en un nodo del árbol. Si el caracter en una posición i es igual al character de otra palabra entonces compartirán nodo y en cuanto el caracter difiera, se realizará una ramificación del árbol con el nuevo character. La complejidad temporal para hacer una inserción dependerá del tamaño de la palabra que será tomará un tiempo lieal o O(n). Para agregar una nueva palabra al Trie, lo que se hace es recorrer cada caracter de la palabra y en cada iteración guarda el primer caracter del string en el nodo y pasará el resto de la palara para que se añadan en los siguientes nodos. 

#### Search (Trie Tree)
La función search() recibe como parámetro un string que contenga una palabra y se encarga de buscar si dicha palabra existe de forma exacta dentro del árbol; regresa un 1 si la encuentra o 0 si no. La complejidad temporal para buscar si una palabra existe en el árbol es O(n), donde n es el tamaño de la palabra. Esto porque solo recorrerá los nodos que tengan el character correspondiente de la palabra. El algoritmo que usa para buscar es prácticamente igual que usa la función insert(), con la diferecia de que en cada nodo compara que el valor del char almacenado sea igual al de la palabra en dicha posición.

### Complejidad de otras funciones

#### Lectura de datos
Leer los datos tiene una complejidad temporal lineal en todos los casos, o O(n), porque tiene que recorrer todo los caracteres del archivo para guardarlos. Lo mismo para la complejidad espacial.

#### Desplegar datos
De igual manera, tiene una complejidad temporal lineal para el peor de los casos, O(n), porque recorre toda la tabla. 

## Casos de prueba
### Ordenamiento
#### Caso 1
~~~
[IN]: 2 0 10
[OUT]:
ENTITY     CODE     YEAR     CO2-EMISSIONS
EU-28        1830    87005344
Myanmar    MMR    1929    3048448
Finland    FIN    1933    3224320
Czechoslovakia    OWID_CZS    1956    107318560
Slovenia    SVN    1959    3992183.44
Norway    NOR    1969    22193766.31
Dominican Republic    DOM    1971    3518697.01
Papua New Guinea    PNG    1974    1586512
South Korea    KOR    1977    105691588.4
Bermuda    BMU    2012    476320
~~~
#### Caso 2
~~~
[IN]: 2 2 8
[OUT]:
ENTITY     CODE     YEAR     CO2-EMISSIONS
Myanmar    MMR    1929    3048448
Norway    NOR    1969    22193766.31
Dominican Republic    DOM    1971    3518697.01
Papua New Guinea    PNG    1974    1586512
South Korea    KOR    1977    105691588.4
Bermuda    BMU    2012    476320
~~~

### Búsqueda
#### Caso 1
~~~
[IN]: 3 1 COL
[OUT]:
ENTITY     CODE     YEAR     CO2-EMISSIONS
Colombia    COL    1961    18196303.65
~~~
#### Caso 2
~~~
[IN]: 3 2 1961
[OUT]:
ENTITY     CODE     YEAR     CO2-EMISSIONS
Greece    GRC    1961    9808427.02
~~~

### Busqueda por Trie
#### Caso 1
~~~
[IN]: 4 Cu
[OUT]: 
La entidad 'Cu' no existe.
~~~
#### Caso 1
~~~
[IN]: 4 Cuba
[OUT]: 
La entidad 'Cuba' si existe.
~~~