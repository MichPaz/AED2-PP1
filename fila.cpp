#include <iostream>

using namespace std;

template <class T>
class NoFila
{
private:
    T item;
    NoFila<T>* prox;
public:
    NoFila();

    void setItem(T);
    void setProx(NoFila<T>*);

    T getItem();
    NoFila<T>* getProx();
};

template <class T>
NoFila<T>::NoFila(){
    prox = NULL;
}

template <class T>
void NoFila<T>::setItem(T item)
{
    this->item = item;
}

template <class T>
void NoFila<T>::setProx(NoFila<T>* prox)
{
    this->prox = prox;
}

template <class T>
T NoFila<T>::getItem()
{
    return item;
}

template <class T>
NoFila<T>* NoFila<T>::getProx()
{
    return prox;
}



//---------------------------------------------
template <class T>
class Fila
{
private:
    NoFila<T> *frente ;
    NoFila<T> *tras ;
public:
    Fila();
    void enfileira(T);
    T desenfileira();
    bool vazia();
    void print();
};

template <class T>
Fila<T>::Fila()
{
    frente = new NoFila<T>;
    frente->setProx(NULL);
    tras = frente;
}

template <class T>
void Fila<T>::enfileira(T item)
{
    tras->setProx(new NoFila<T>);
    tras = tras->getProx();
    tras->setItem(item);
    tras->setProx(NULL);
}

template <class T>
T Fila<T>::desenfileira()
{
    NoFila<T>* aux = frente;
    frente=frente->getProx();

    NoFila<T>* aux1 = aux;
    delete aux1;

    return frente->getItem();
}

template <class T>
bool Fila<T>::vazia()
{
    return tras==frente;
}

template <class T>
void Fila<T>::print()
{
    NoFila<T> *aux = frente;
    if (vazia()){
        cout << "lista vazia"<< endl;
    }else{
        while(aux->getProx()!=NULL)
        {
            aux = aux->getProx();
            cout << aux->getItem() << endl;
        }
    }
}

/*int main(){
    Fila<int> fila;
    fila.print();
    fila.enfileira(3);
    fila.enfileira(6);
    fila.enfileira(4);
    fila.enfileira(1);

    cout << fila.desenfileira()<<endl;
    cout << fila.desenfileira()<<endl;

    fila.print();


    return 0;
}*/
