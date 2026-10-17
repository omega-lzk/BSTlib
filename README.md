# Libreria per un BinarySearchTree in C++

La libreria contiene un file header `bst.h` per le dichiarazioni nel namespace `bst` e un file `bst.cpp` contenente le implementazioni procedurali ricorsive.

# Struttura della libreria 

## File Header bst.h

Nel file header vengono dichiarati: 

1. Il namespace `bst`
2. Lo struct `Node`
    - 3 parametri: `int data` per il valore da memorizzare, `Node* left` e `Node* right`, due puntatori ai child-nodes inizializzati a `nullptr`
3. La funzione `Node* insert`
    - Due parametri formali: `Node* root` e `int val`
    - Alla fine restituisce il puntatore alla radice dell'albero
4. La funzione `Node* search`
    - Restituisce il nodo cercato oppure `nullptr`
5. Le funzioni `inorder`, `preorder` e `postorder`
    - Scrivono i valori nella `vector<int>` fornita dal chiamante
6. La funzione `Node* remove`
    - Restituisce la nuova radice dopo la rimozione
    - Gestisce foglie, nodi con un figlio e nodi con due figli
7. La funzione `void clear`
    - Libera tutti i nodi e imposta la radice a `nullptr`

## File di implementazione bst.cpp

Nel file `bst.cpp` viene implementata la funzione `Node* insert`:

1. Se `root == nullptr`, viene creato e restituito un nuovo nodo contenente `val`
2. Se `val < root->data`, la funzione viene richiamata sul sottoalbero sinistro
3. Se `val > root->data`, la funzione viene richiamata sul sottoalbero destro
4. Se `val == root->data`, il nodo non viene modificato

La funzione utilizza la ricorsione per scorrere l'albero fino alla posizione corretta in cui inserire il nuovo valore. I duplicati vengono ignorati, come richiesto dalla proprietà del BST.

## Gestione della memoria

I nodi creati con `insert` devono essere liberati chiamando `clear` quando l'albero non serve più:

```cpp
bst::clear(root);
```

La funzione `remove` libera il nodo rimosso; il risultato va sempre riassegnato alla radice.

# Creazione e compilazione da Terminale

## Creazione di una libreria statica

Per creare la libreria statica è necessario prima generare il file oggetto:

```bash
g++ -c bst.cpp -o bst.o
```

Successivamente si archivia il file oggetto nella libreria statica `libbst.a`:

```bash
ar rcs libbst.a bst.o
```

## Installazione di sistema su macOS

Per rendere la libreria visibile a qualsiasi progetto senza dover specificare ogni volta i percorsi con `-L` o `-I`, è possibile copiarla nelle directory di sistema `/usr/local`:

```bash
# Copia l'header nella cartella degli include globali
sudo cp bst.h /usr/local/include/

# Copia la libreria nella cartella delle librerie globali
sudo cp libbst.a /usr/local/lib/
```

## Utilizzo della libreria

Per utilizzare la libreria in un altro programma è necessario includere il file header e collegare la libreria compilata:

```cpp
#include "bst.h"
#include <vector>

int main()
{
    bst::Node* root = nullptr;
    root = bst::insert(root, 10);
    root = bst::insert(root, 5);
    root = bst::insert(root, 15);

    if (bst::search(root, 5) != nullptr)
    {
        // Il valore 5 esiste nell'albero.
    }

    std::vector<int> values;
    bst::inorder(root, values);
    root = bst::remove(root, 10);
    bst::clear(root);
}
```

Se la libreria è stata installata nelle directory di sistema, può essere collegata durante la compilazione con:

```bash
g++ -std=c++11 main.cpp bst.cpp -o programma
```

## Compilazione dei test

Il test autonomo non usa framework esterni:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic bst.cpp test_bst.cpp -o test_bst
./test_bst
```

Verifica inserimento, duplicati, ricerca, visite, i tre casi di rimozione,
rimozione della radice e liberazione della memoria.

## Creazione e compilazione su Windows

### Utilizzando MinGW e g++

Con MinGW la procedura è simile a quella utilizzata su macOS e Linux:

```bash
g++ -c bst.cpp -o bst.o
ar rcs libbst.a bst.o
```

Per compilare un programma utilizzando la libreria:

```bash
g++ main.cpp -I. -L. -lbst -o programma.exe
```

Le opzioni `-I.` e `-L.` indicano rispettivamente al compilatore dove trovare il file header e la libreria.

### Utilizzando Microsoft Visual C++

Con Visual C++ viene generato un file di libreria con estensione `.lib`:

```powershell
cl /c /EHsc bst.cpp
lib /OUT:bst.lib bst.obj
```

Per compilare un programma utilizzando la libreria:

```powershell
cl /EHsc main.cpp /I. bst.lib
```

Il comando `cl` deve essere eseguito dal **Developer Command Prompt for Visual Studio**, così da avere disponibili anche gli strumenti `lib` e `cl`.




## Crediti

* Autore: Massimo Jan Conte