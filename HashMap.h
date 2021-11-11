#ifndef U05_HASH_HASHMAP_HASHMAP_H_
#define U05_HASH_HASHMAP_HASHMAP_H_

#include "HashEntry.h"

template <class K, class T>
        class HashMap
                {
                private:
                    HashEntry<K, T> **tabla;
                    unsigned int tamanio;

                    static unsigned int hashFunc(K clave); //funcion por si no recibimos otra
                    static unsigned int hashFuncion(K clave);
                    unsigned int (*hashFuncP)(K clave);

                public:
                    explicit HashMap(unsigned int k); //constructor para definir el tamaño de la tabla

                    HashMap(unsigned int k, unsigned int (*hashFuncP)(K clave)); // constructor aceptar parametro para
                    // definir el tamaño de la tabla y recibe una funcion

                    T get(K clave); //pasar la clave y te devuelve el contenido

                    void put(K clave, T valor); // insercion
                    void put2(K clave, T valor); // insercion
                    void remove(K clave);

                    ~HashMap(); //destructor

                    bool esVacio(); //vacia

                    void print(); //imprimir
                };

template <class K, class T>
        HashMap<K, T>::HashMap(unsigned int k)
        {
            tamanio = k;
            tabla = new HashEntry<K, T> *[tamanio];
            for (int i = 0; i < tamanio; i++)
            {
                tabla[i] = NULL;
            }
            hashFuncP = hashFunc;
        }

        template <class K, class T>
                HashMap<K, T>::HashMap(unsigned int k, unsigned int (*fp)(K))
                {
                    tamanio = k;
                    tabla = new HashEntry<K, T> *[tamanio];
                    for (int i = 0; i < tamanio; i++)
                    {
                        tabla[i] = NULL;
                    }
                    hashFuncP = fp;
                }

                template <class K, class T>
                        HashMap<K, T>::~HashMap()
                        {
                            for (int i = 0; i < tamanio; i++)
                            {
                                if (tabla[i] != NULL)
                                {
                                    delete tabla[i];
                                }
                            }
                        }
                        template <class K, class T>


                                T HashMap<K, T>::get(K clave)
                                {
                                    unsigned int pos = hashFuncP(clave) % tamanio;
                                    if (tabla[pos] == NULL)
                                    {
                                        return 0;
                                    }

                                    if(tabla[pos]->getClave() == clave){
                                        return tabla[pos]->getValor();
                                    }else{
                                        throw 409;
                                    }
                                }

                                template <class K, class T>
                                        void HashMap<K, T>::put(K clave, T valor)
                                        {
                                            unsigned int pos = hashFuncP(clave) % tamanio;

                                            if (tabla[pos] != NULL)
                                            {
                                                tabla[pos]->setValor(tabla[pos]->getValor() + valor); //Contagios++
                                                return;
                                                //throw 409;
                                            }

                                            tabla[pos] = new HashEntry<K, T>(clave, valor); //Corresponde a una fila en la tabla HASH
                                        }
                                        template <class K, class T>
                                        void HashMap<K, T>::put2(K clave, T valor)
                                        {
                                            unsigned int pos = hashFuncP(clave) % tamanio;

                                            if (tabla[pos] != NULL)
                                            {
                                                return;
                                                //throw 409;
                                            }

                                            tabla[pos] = new HashEntry<K, T>(clave, valor); //Corresponde a una fila en la tabla HASH
                                        }

                                        template <class K, class T>
                                                void HashMap<K, T>::remove(K clave) {}

                                                template <class K, class T>
                                                        bool HashMap<K, T>::esVacio()
                                                        {
                                                            for (int i = 0; i < tamanio; i++)
                                                            {
                                                                if (tabla[i] != NULL)
                                                                {
                                                                    return false;
                                                                }
                                                            }
                                                            return true;
                                                        }

                                                        template <class K, class T>
                                                                unsigned int HashMap<K, T>::hashFunc(K clave)
                                                                {
                                                                    return (unsigned int)clave;
                                                                }

                                                                template <class K, class T>
                                                                        void HashMap<K, T>::print()
                                                                        {

                                                                            std::cout << "i"
                                                                            << " "
                                                                            << "Clave"
                                                                            << "\t\t"
                                                                            << "Valor" << std::endl;
                                                                            std::cout << "--------------------" << std::endl;
                                                                            for (int i = 0; i < tamanio; i++)
                                                                            {
                                                                                std::cout << i << " ";
                                                                                if (tabla[i] != NULL)
                                                                                {
                                                                                    std::cout << tabla[i]->getClave() << "\t\t";
                                                                                    std::cout << tabla[i]->getValor();
                                                                                }
                                                                                std::cout << std::endl;
                                                                            }
                                                                        }

#endif // U05_HASH_HASHMAP_HASHMAP_H_