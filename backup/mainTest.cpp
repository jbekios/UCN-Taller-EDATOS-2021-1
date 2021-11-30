//
// Created by jbekios on 11/30/21.
//

int main(int){
    BinarySearchTree arbol;

    cout << endl;
    arbol.insert(8);
    arbol.insert(3);
    arbol.insert(1);
    arbol.insert(6);
    arbol.insert(4);
    arbol.insert(7);
    arbol.insert(10);
    arbol.insert(14);
    arbol.insert(13);

    cout << "Recorrido preorden: " << endl;
    arbol.preOrder();

    cout << endl << "Recorrido preorden sin el 8: " << endl;
    cout << endl;
    arbol.remove(8);
    arbol.preOrder();

    cout << endl;

    return 0;
}



