#include "b_tree.h"
using namespace std;

BTreeNode::BTreeNode() {
    num_keys = 0;
    for (int i = 0; i < MAX_KEYS + 1; i++) {
        children[i] = NULL;
    }
}

BTreeNode *createNode() {
    BTreeNode *newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
    if (newNode == NULL) {
        cout<<"La asignación de memoria falló.\n";
        exit(1);
    }
    newNode->num_keys = 0;
    return newNode;
}

void insert(BTreeNode** root, double key) {
    if (*root == NULL) {
        *root = createNode();
        (*root)->keys[0] = key;
        (*root)->num_keys = 1;
        cout << "Insertado en raíz: " << key << endl;  // Mensaje de depuración
    } else {
        if ((*root)->num_keys == MAX_KEYS) {
            BTreeNode *newRoot = createNode();
            newRoot->children[0] = *root;
            splitChild(newRoot, 0);
            *root = newRoot;
        }
        insertNonFull(*root, key);
    }
}

void splitChild(BTreeNode* parent, int i) {
    BTreeNode* fullNode = parent->children[i];
    BTreeNode* newNode = createNode();
    newNode->num_keys = (MAX_KEYS / 2); // Asumiendo que MAX_KEYS es impar

    // Mover la mitad de las claves al nuevo nodo
    for (int j = 0; j < newNode->num_keys; j++) {
        newNode->keys[j] = fullNode->keys[j + (MAX_KEYS / 2)];
    }

    // Mover los hijos del nodo lleno al nuevo nodo
    if (fullNode->children[0] != NULL) {
        for (int j = 0; j <= fullNode->num_keys; j++) {
            newNode->children[j] = fullNode->children[j + (MAX_KEYS / 2)];
        }
    }

    fullNode->num_keys = (MAX_KEYS / 2); // Reducir el número de claves en el nodo lleno

    // Insertar el nuevo nodo en el padre
    for (int j = parent->num_keys; j > i; j--) {
        parent->children[j + 1] = parent->children[j];
    }
    parent->children[i + 1] = newNode;

    for (int j = parent->num_keys - 1; j >= i; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[i] = fullNode->keys[(MAX_KEYS / 2) - 1];
    parent->num_keys++;
}

void insertNonFull(BTreeNode *node, double key) {
    int i = node->num_keys - 1;
    if (node->children[0] == NULL) {
        insertKey(node, key);
        return;
    }
    while (i >= 0 && node->keys[i] > key) {
        i--;
    }
    i++;
    if (node->children[i]->num_keys == MAX_KEYS) {
        splitChild(node, i);
        if (node->keys[i] < key) {
            i++;
        }
    }
    insertNonFull(node->children[i], key);
}

void insertKey(BTreeNode *node, double key) {
    int i = node->num_keys - 1;
    while (i >= 0 && node->keys[i] > key) {
        node->keys[i + 1] = node->keys[i];
        i--;
    }
    node->keys[i + 1] = key;
    node->num_keys++;
}

bool search(BTreeNode* root, double key) {
    if (root == NULL) {
        return false; // El árbol está vacío
    }

    int i = 0;
    // Busca la primera clave mayor o igual que la clave buscada
    while (i < root->num_keys && key > root->keys[i]) {
        i++;
    }

    // Si la clave es igual a la clave en el nodo actual
    if (i < root->num_keys && root->keys[i] == key) {
        return true; // Se encontró la clave
    }

    // Si el nodo es una hoja, la clave no está presente
    if (root->children[0] == NULL) {
        return false; // No se encontró la clave
    }

    // Busca en el hijo correspondiente
    return search(root->children[i], key);
}

void loadCSV(BTreeNode** root, const char *filename) {
    FILE *file = fopen(filename, "r");
    

    // Ignora la primera línea (encabezado)
    char buffer[1024];
    fgets(buffer, sizeof(buffer), file);

    int index;
    double key;
    // Lee cada línea con el formato "index,number" e ignora el índice
    while (fscanf(file, "%d,%lf", &index, &key) == 2) {
        // Convierte el valor a entero si tu B-Tree solo maneja enteros
        insert(root, key);
    }

    fclose(file);
}