# Lab6---part-2
# Proyecto de Árbol B - Inserción y Búsqueda desde un Archivo CSV

  Este proyecto implementa un Árbol B para insertar y buscar elementos en un árbol de manera eficiente. Se utiliza un archivo CSV para cargar datos en el árbol y un menú interactivo para insertar y buscar claves.

    Estructura del Proyecto

    	•	Main.cpp: Archivo principal que ejecuta el programa, cargando los datos del archivo CSV y proporcionando un menú para realizar operaciones.
    	•	b_tree.h: Encabezado que define las estructuras y funciones de un Árbol B, incluyendo las funciones de inserción, búsqueda, y carga de datos desde el CSV.
    	•	b_tree.cpp: Implementación de las funciones definidas en b_tree.h.

# Archivos

	1.	Main.cpp: Contiene la lógica principal para interactuar con el usuario y llamar a las funciones de inserción y búsqueda.
	2.	b_tree.h: Define la estructura BTreeNode y las funciones utilizadas en la manipulación del Árbol B.
	3.	b_tree.cpp: Implementa las funciones declaradas en b_tree.h.

# Estructura del Árbol B

	•	Cada nodo en el Árbol B tiene hasta MAX_KEYS claves.
	•	Si un nodo alcanza el número máximo de claves, se divide en dos.
	•	Los nodos del árbol contienen tanto claves como punteros a sus hijos, manteniendo el orden y permitiendo la búsqueda y la inserción de manera eficiente.

# Funciones Principales

	1.	**insert(BTreeNode root, double key): Inserta una clave en el árbol. Si el nodo raíz está lleno, se divide, y se crea una nueva raíz.
	2.	splitChild(BTreeNode *parent, int index): Divide un nodo lleno en dos, y sube la clave media al nodo padre.
	3.	insertNonFull(BTreeNode *node, double key): Inserta una clave en un nodo que no está lleno, manteniendo el orden de las claves.
	4.	search(BTreeNode *root, double key): Busca una clave en el árbol, retornando true si se encuentra o false si no.
	5.	**loadCSV(BTreeNode root, const char *filename): Carga datos desde un archivo CSV y los inserta en el Árbol B.

# Ejecución del Programa

# El programa carga automáticamente los datos desde un archivo CSV especificado. Una vez cargados los datos, el usuario puede interactuar mediante un menú:

	1.	Salir: Finaliza el programa.
	2.	Insertar: Permite al usuario ingresar una clave para insertarla en el Árbol B.
	3.	Buscar: Permite al usuario buscar una clave en el árbol e indica si fue encontrada o no.

## Ejemplo de Uso

Para compilar el programa:

g++ Main.cpp b_tree.cpp -o BTreeProgram

Para ejecutar el programa:

./BTreeProgram

El archivo random_numbers_1000000.csv debe estar en la misma carpeta que los archivos de código fuente, o se debe proporcionar la ruta completa en el código.

Notas

	•	Asegúrate de tener el archivo CSV con el formato índice,clave en cada línea.
	•	Este código es solo un ejemplo para mostrar cómo manejar un Árbol B y puede requerir ajustes según los requisitos de la aplicación.

Este README proporciona una visión general y guía de uso para el proyecto.
