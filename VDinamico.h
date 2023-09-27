//
// Created by ajgar on 26/09/2023.
//

/**
 * @file VDinamico.h
 * @date 24/09/2023
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @title Vector Dinamico
 */
#include "stdexcept"
#include "algorithm"
#include "cmath"
#include "climits"
#ifndef VECTORESDINAMICOSB_VDINAMICO_H
#define VECTORESDINAMICOSB_VDINAMICO_H
template<class T>
class VDinamico {
private:
    //Puntero a tipo generico
    T *vector = nullptr;
    //Tamaño del vector sin signo long el entero mas grande
    unsigned long int tamalog = 0;
    unsigned long int tamafis = 1;
public :
    //Constructor por defecto
    VDinamico()=default;
    //Constructor por parametrizado
    VDinamico(unsigned  int n);
    //Constructor de copia
    VDinamico(const VDinamico<T>& origen);
    //Constructor de copia por trozos
    VDinamico(const VDinamico<T> &origen, unsigned  int posicioninicial, unsigned  int numElementos);
    //Destructor
    ~VDinamico();
    //Operator igual
    VDinamico<T> &operator = (const VDinamico <T> &origen);
    //Operator corchetes se usa para acceder al vector
    T &operator[](unsigned  long int pos);
    //Ordenar de menor a mayor
    void ordenar();
    //Ordenar de mayor a menor
    void ordenarRev();
    //Metodo de insertar en el vector
    void insertar(const T& dato, unsigned int pos =UINT_MAX);
};



/**
 * @brief Constructor parametrizado del vector dinamico
 * @tparam T
 * @param n Tamaño asignado al vector
 */
template<class T>
VDinamico<T>::VDinamico(unsigned int n) {
    tamalog = n;
    while(tamalog > tamafis){
        tamafis = tamafis * 2;
    }
    //Fijamos el vector con el tamaño fisico
    vector = new T[tamafis];
}
/**
 * @brief Constructor copia
 * @tparam T
 * @param origen Direccion de memoria del vector dinamico
 *
 */
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen) {
    //Reservamos en memoria con el tamaño del que vamos a copiar
    tamalog = origen.tamalog;
    vector = new T[tamafis=origen.tamafis];
    //Le pasamos cada posicion de memoria del vector origen
    for (int i = 0; i < origen.tamafis ; ++i) {
        vector[i] =origen.vector[i];
    }
}
/**
 * @brief Constructor de copia parcial
 * @tparam T
 * @param origen Direccion de memoria del vector dinamico
 * @param posicioninicial   Posicion inicial del vector dinamico
 * @param numElementos      Le pasamos el numero de elementos maximo que vamos a utilizar en el main
 */
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen, unsigned  int posicioninicial, unsigned  int numElementos){
         //Comprobamos si la posicion inicial supera el numero de elementos
         if (posicioninicial > numElementos) {
             throw std::out_of_range("Ha susperado el limite de elementos");
         }
         //Eliminamos el vector
         delete[]vector;
         //Creamos un vector con el tamaño asignado a la diferencia del numero de elementos con la posicion inical
         vector = new int[tamalog = numElementos - posicioninicial];
         /*
          * Para ver si es potencia de dos realizamos el log en base dos y si es un entero pues es log en base 2
          */
         if(log2(origen.tamafis%1 != 0)){
             tamafis = 1;
             while(origen.tamafis < origen.tamalog ){
                 tamafis = origen.tamafis*2;
             }
         }
        for (int i = 0; i < tamalog; ++i) {
            vector[i] = origen.vector[posicioninicial + i];
        }
}
/**
 * @brief Destructor del vector dinamico
 * @tparam T
 */
template <class T>
VDinamico<T>::~VDinamico() {
    //Borramos el vector
    delete[] vector;
}
/**
 * @brief Operator igual pasamos la posicion memoria del vector de origen al vector dinamico
 * @tparam T
 * @param origen
 * @return
 */

template<class T>
VDinamico<T> &VDinamico<T>::operator = (const VDinamico <T> &origen){
    //Comprobamos que no sea la misma direccion de memoria
    if(this!=origen) {
        //Eliminamos el vector que teniamos
        delete[] vector;
        tamalog = origen.tamalog;
        if(log2(origen.tamafis%1 != 0)){
            tamafis = 1;
            while(origen.tamafis < origen.tamalog ){
                tamafis = origen.tamafis*2;
            }
        }
        //Reservamos en memoria con el tamaño del que vamos a copiar
        vector = new int[tamalog = origen.tamalog];
        //Le pasamos cada posicion de memoria del vector origen
        for (int i = 0; i < origen.tamalog; ++i) {
            vector[i] = origen.vector[i];
        }
    }
    return *this;
}

/**
 * @brief Operator corchete devuelve el contenido del  vector
 * @tparam T
 * @param pos Parametro en el que utilizamos la posicion del vector para poder obtener el contenido del vector
 * @return
 */
template <class T>
T &VDinamico<T>::operator[](unsigned  long int pos){
    //Comprobamos si la posicion supera el tamaño
    if(pos >= tamalog){
        throw std::out_of_range("Ha superado el limite de elementos");
    }
    //En caso contrario devolvemos la posicion
    return vector[pos];
}

/**
 * @brief Ordena el vector de menor a mayor con la funcion sort
 * @tparam T
 */
template <class T>
void VDinamico<T>::ordenar() {
    std::sort(vector,vector + tamalog);
}

/**
 * @brief Ordena el vector de mayor a menor
 * @tparam T
 */
template <class T>
void VDinamico<T>::ordenarRev(){
    std::sort(vector,vector + tamalog,std::greater<T>());
}
/**
 * @brief Metodo de inserccion de un dato en memoria dinamica
 * @tparam T
 * @param dato
 * @param pos
 */

template<class T>
void VDinamico<T>::insertar(const T &dato, unsigned int pos) {
    //En caso de que el vector este lleno
    if(tamalog == tamafis){
        //Creamos un vector nuevo auxiliar
        int *vaux;
         //Que sea el potencia de dos de grande
        vaux = new int[tamafis = tamafis * 2];
        for (int i = 0; i < tamalog; ++i) {
                //Pasamos los datos del vector a la variable auxiliar
                vaux[i] = vector[i];
        }
        //Borramos el antiguo vector
        delete[]vector;
        //Y lo sobreescribimos
        vector = vaux;
    }
    if(pos > tamalog)
        throw std::out_of_range("Posicion fuera del vector");
    if(pos==UINT_MAX){

    }
///




}






#endif //VECTORESDINAMICOSB_VDINAMICO_H
