# Libreria `BinarySearchTree` in C++

Libreria C++ per gestire un albero binario di ricerca (BST) tramite classi e
metodi. L'API precedente basata su `struct Node` e funzioni libere è stata
sostituita da `bst::BinarySearchTree`.

## API pubblica

L'header `bst.h` espone la classe:

```cpp
namespace bst {

    class BinarySearchTree
    {
    public:
        BinarySearchTree();
        ~BinarySearchTree();

        void insert(int value);
        bool search(int value) const;
        bool remove(int value);

        std::vector<int> inorder() const;
        std::vector<int> preorder() const;
        std::vector<int> postorder() const;

        void clear();
        bool empty() const;
    };

}
```

- `insert` aggiunge un valore; i duplicati vengono ignorati.
- `search` restituisce `true` se il valore è presente.
- `remove` elimina il valore e restituisce `true` se è stato trovato.
- Le funzioni di visita restituiscono i valori nell'ordine richiesto.
- `clear` elimina tutti i nodi; `empty` verifica se l'albero è vuoto.

La radice dell'albero è un attributo privato di `BinarySearchTree`; il chiamante
usa i metodi della classe invece di modificarla direttamente. La classe gestisce
la memoria dei nodi e il distruttore libera automaticamente l'albero.

## Esempio

```cpp
#include "bst.h"

#include <iostream>

int main()
{
    bst::BinarySearchTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    if (tree.search(5))
    {
        std::cout << "Il valore 5 esiste nell'albero.\n";
    }

    const std::vector<int> values = tree.inorder();
    tree.remove(10);
}
```

Non è necessario chiamare `clear` prima della fine del programma: il distruttore
della classe libera automaticamente la memoria. `clear` è disponibile per
svuotare esplicitamente un albero ancora in uso.

## Compilazione dei test

Il test autonomo non usa framework esterni:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic bst.cpp test_bst.cpp -o test_bst
./test_bst
```

Il test verifica inserimento, duplicati, ricerca, visite, rimozione di foglie e
nodi con uno o due figli, rimozione della radice e svuotamento dell'albero.

## Creazione di una libreria statica

```bash
g++ -std=c++11 -Wall -Wextra -pedantic -c bst.cpp -o bst.o
ar rcs libbst.a bst.o
```

Per usare la libreria da un altro programma:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -I. -L. -lbst -o programma
```

## Installazione su macOS

Per installare header e libreria nelle directory di sistema:

```bash
sudo cp bst.h /usr/local/include/
sudo cp libbst.a /usr/local/lib/
```

Dopo l'installazione, un programma può essere compilato con:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -lbst -o programma
```

## Windows

### MinGW e g++

```bash
g++ -std=c++11 -Wall -Wextra -pedantic -c bst.cpp -o bst.o
ar rcs libbst.a bst.o
g++ -std=c++11 main.cpp -I. -L. -lbst -o programma.exe
```

### Microsoft Visual C++

```powershell
cl /std:c++11 /c /EHsc bst.cpp
lib /OUT:bst.lib bst.obj
cl /std:c++11 /EHsc main.cpp /I. bst.lib
```

Il comando `cl` deve essere eseguito dal **Developer Command Prompt for Visual
Studio**.

## Crediti

* Autore: Massimo Jan Conte
