# Libreria per un BinarySearchTree in C++

La libreria contiene un file header `bst.h` per le dichiarazioni - in cui vengono dichiarati il namespace "bst", lo `struct Node` e la funzione di inserimento `Node* insert()` - ed un file `bst.cpp` contenente le implementazioni.

# Struttura della libreria 

## File Header bst.h

Nel file header vengono dichiarati: 

1. Il namespace `bst`
2. Lo struct `Node`
    - 3 parametri: `int data` per il valore da memorizzare, `Node* left` e `Node* right`, due puntatori ai child-nodes inizializzati a `nullptr`
3. La funzione `Node* insert`
    - Due parametri formali: `Node* root` e `int val`
    - Alla fine restituisce il puntatore alla radice dell'albero

## File di implementazione bst.cpp

Nel file `bst.cpp` viene implementata la funzione `Node* insert`:

1. Se `root == nullptr`, viene creato e restituito un nuovo nodo contenente `val`
2. Se `val < root->data`, la funzione viene richiamata sul sottoalbero sinistro
3. Se `val > root->data`, la funzione viene richiamata sul sottoalbero destro
4. Se `val == root->data`, il nodo non viene modificato

La funzione utilizza la ricorsione per scorrere l'albero fino alla posizione corretta in cui inserire il nuovo valore.

# Compilazione della libreria

Per compilare la libreria è necessario utilizzare `CMake`:

```bash
cmake -S . -B build
cmake --build build
```

Al termine della compilazione viene generata la libreria statica `libBSTlib.a` nella cartella `build`.

## Utilizzo della libreria

Per utilizzare la libreria in un altro programma è necessario includere il file header e collegare la libreria compilata:

```cpp
#include "bst.h"

int main()
{
    bst::Node* root = nullptr;
    root = bst::insert(root, 10);
    root = bst::insert(root, 5);
    root = bst::insert(root, 15);
}
```

La libreria può essere collegata durante la compilazione con:

```bash
g++ main.cpp -I. -Lbuild -lBSTlib -o programma
```




## Crediti

* Autore: Massimo Jan Conte