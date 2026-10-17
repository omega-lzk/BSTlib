# Libreria per un BinarySearchTree in C++

La libreria contiene un file header `bst.h` per le dichiarazioni nel namespace `data_structures` e un file `bst.cpp` contenente le implementazioni. La classe `BST` nasconde la gestione dei nodi e offre un'interfaccia semplice per inserimento, ricerca, visite, rimozione e distruzione dell'albero.

# Struttura della libreria 

## File Header bst.h

Nel file header vengono dichiarati:

1. Il namespace `data_structures`
2. Lo `struct Node`, usato internamente dalla classe:
    - `int data` per il valore memorizzato
    - `Node* left` e `Node* right`, inizializzati a `nullptr`
3. La classe `BST`, che conserva privatamente la radice dell'albero e offre i metodi pubblici:
    - `insert(int val)`
    - `search(int val) const`
    - `inorder() const`, `preorder() const` e `postorder() const`
    - `remove(int val)`
    - `clear()`

## File di implementazione bst.cpp

Le operazioni dell'albero sono implementate con funzioni helper ricorsive private:

1. Se la radice del sottoalbero è `nullptr`, `insert` crea un nuovo nodo.
2. I valori minori vengono inseriti a sinistra e quelli maggiori a destra.
3. Se il valore è già presente, il duplicato viene ignorato.
4. `search` restituisce `true` se trova il valore e `false` altrimenti.
5. Le visite restituiscono un `vector<int>` con l'ordine richiesto.
6. `remove` gestisce foglie, nodi con un figlio e nodi con due figli usando il successore inorder.

## Gestione della memoria

Ogni nodo creato da `BST::insert` appartiene all'oggetto. Il distruttore libera automaticamente tutti i nodi; se serve svuotare l'albero prima della fine dell'oggetto, chiamare:

```cpp
albero.clear();
```

La funzione `BST::remove` libera il nodo rimosso. La radice viene aggiornata internamente dalla classe.

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
    data_structures::BST albero;
    albero.insert(10);
    albero.insert(5);
    albero.insert(15);

    if (albero.search(5))
    {
        // Il valore 5 esiste nell'albero.
    }

    std::vector<int> sorted = albero.inorder();
}
```

Se la libreria è stata installata nelle directory di sistema, può essere collegata durante la compilazione con:

```bash
g++ -std=c++11 main.cpp bst.cpp -o programma
```

## Compilazione dei test

Il progetto include `test_bst.cpp`, un eseguibile di test autonomo che non usa framework esterni:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic bst.cpp test_bst.cpp -o test_bst
./test_bst
```

I test verificano inserimento, duplicati, ricerca, tutte le visite, rimozione di foglie e nodi con uno o due figli, rimozione della radice e distruzione dell'albero.

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