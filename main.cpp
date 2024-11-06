#include "b_tree.h"
#include <iostream>

using namespace std;



int main() {
    BTreeNode *root = NULL;
    //string filename = "random_numbers_1000000.csv";
    
    const char *filename = "random_numbers_1000000.csv";  // Cambia esto por la ruta de tu archivo
    loadCSV(&root, filename);
    cout<<"FIN"<<endl;
    int opcion = -1;
    bool found = false;
    double key = 0.11;
    
    
    
    while(true){
        cout<<"1 insertar"<<endl;
        cout<<"2 buscar"<<endl;
        cout<<"Ingresar opcion: ";
        cin>>opcion;
        switch(opcion){
            case 0:
                return 0;
            case 1:
                cout<<"ingrese la llave a insertar: ";
                cin>>key;
                insert(&root, key);
                break;
            case 2:
                cout<<"ingrese la llave a buscar: ";
                cin>>key;    
                found = search(root, key);
                if(found)
                    cout<<"llave encontrada"<<endl;
                else
                    cout<<"llave no encontrada"<<endl;
                break;
            
            default:
                cout<<"opcion invalida"<<endl;
                break;
            
        }
    }
    cout<<"wa"<<endl;
    return 0;
}