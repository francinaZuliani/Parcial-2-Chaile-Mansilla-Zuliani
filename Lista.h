#ifndef U02_LISTAS_LISTA_LISTA_H_
#define U02_LISTAS_LISTA_LISTA_H_
#include "nodo.h"

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Lista {
private:
    nodo<T> *inicio; // si la lista está vacia, su puntero de inicio debe apuntar al puntero nulo
public:
  Lista();

  Lista(const Lista<T> &li);

  ~Lista();

  bool esVacia();

  int getTamanio();

  void insertar(int pos, T dato);

  void insertarPrimero(T dato);

  void insertarUltimo(T dato);

  void remover(int pos);

  T getDato(int pos);

  void reemplazar(int pos, T dato);

  void vaciar();

  void imprimir();
};

/**
 * Constructor de la clase Lista
 * @tparam T
 */
template <class T> Lista<T>::Lista() {
    inicio = nullptr;
}

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template <class T> Lista<T>::Lista(const Lista<T> &li) {
    inicio = li.inicio;
}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T> Lista<T>::~Lista() {
    //llamar al metodo vaciar
    vaciar();
    delete inicio;
}

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T> bool Lista<T>::esVacia() { return inicio == nullptr;
    //equivalente a:
    // if (inicio == nullptr)
    //{
    //    return true;
   // }else{return false;}
}

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template <class T> int Lista<T>::getTamanio()
{
    nodo<T> *aux = inicio;
    int tam=0;
    while (aux != nullptr)
    {
        aux = aux->getSiguiente();
        tam++;
    }
    return tam;
    // -> sirve para acceder a los atributos desde un puntero - si no es puntero hay q hacer nodo.getdato()
}

/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template <class T> void Lista<T>::insertar(int pos, T dato)
{
    nodo<T> *aux = inicio;
    int posactual =0;
//defino nuevo nodo
    nodo<T> *nuevo = new nodo <T>;
    nuevo -> setDato (dato);
//navego a la posicion anterior de la q quiero llegar
   if (pos==0)
   {nuevo->setSiguiente(inicio);
   inicio = nuevo;
   return;
   }

    while (aux != nullptr && posactual < pos -1)
    {
        aux = aux->getSiguiente();
        posactual ++;
    }

    if (aux== nullptr)
    {
        throw 400;
    }

    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarPrimero(T dato)
{
    insertar (0,dato);
}

/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarUltimo(T dato) {
    nodo <T> *aux=inicio;

    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(dato);

    if (aux== nullptr)
    {
        nuevo->setSiguiente(inicio);
        inicio=nuevo;
        return;
    }

    while (aux->getSiguiente() != nullptr)
    {
        aux = aux -> getSiguiente();
    }

    nuevo->setSiguiente(aux->getSiguiente());
    //nuevo->setsiguiente(nullptr); //equivalente a la linea superior
    aux->setSiguiente(nuevo);

}

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template <class T> void Lista<T>::remover(int pos) {
    nodo<T> *aux=inicio, *aborrar;
    int posactual =0;

    if(pos==0)
    {
        inicio = inicio -> getSiguiente();
        delete aux;
        return;
    }

    while (aux != nullptr && posactual < pos -1)
    {
        aux = aux->getSiguiente();
        posactual ++;
    }

    if (aux== nullptr)
    {
        throw 400;
    }
    aborrar= aux->getSiguiente();
    aux->setSiguiente(aborrar->getSiguiente());
    delete aborrar;
}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template <class T> T Lista<T>::getDato(int pos) {
    nodo<T> *aux = inicio;
    int posactual=0;

    while (aux != nullptr && posactual < pos)
    {
        aux = aux->getSiguiente();
        posactual ++;
    }

    if (aux== nullptr)
    {
        throw 400;
    }
    return aux -> getDato();
}

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template <class T> void Lista<T>::reemplazar(int pos, T dato) {
    nodo<T> *aux = inicio;
    int posactual=0;

    while (aux != nullptr && posactual < pos)
    {
        aux = aux->getSiguiente();
        posactual ++;
    }

    if (aux== nullptr)
    {
        throw 400;
    }
    aux -> getDato();
}

/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template <class T> void Lista<T>::vaciar() {
    nodo <T> *aux = inicio, *aborrar;
    while (aux != nullptr)
    {
        aborrar=aux;
        aux=aux->getSiguiente();
        delete aborrar;
    }
    inicio = nullptr;
}
/**
 * funcion que imprime la lista enlazada
 * @tparam T
 */

template <class T> void Lista<T>::imprimir()
{
    nodo <T> *aux = inicio;

    while (aux!= nullptr)
    {
        std::cout<<aux->getDato()<<" -> ";
        aux=aux->getSiguiente();
    }
    std::cout<<"NULL"<<std::endl;
}
#endif // U02_LISTAS_LISTA_LISTA_H_
