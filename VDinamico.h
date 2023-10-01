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
    /* T *aeropuerto;
     * unsigned int tamal, tamf; */
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
    void insertar(const T& dato, unsigned long int pos = UINT_MAX);
    //Metodo para borrar en el vector por su posicion
    T borrar(unsigned int pos =UINT_MAX);
    //Busqueda Binaria
    int busquedaBinaria(T &dato);
    //Obterner el tamaño logico del vector
    unsigned int  tamlog();



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
 * @brief Metodo de inserccion de un dato
 * @tparam T
 * @param dato
 * @param pos
 */

template<class T>
void VDinamico<T>::insertar(const T& dato, unsigned long int pos){

    if(tamalog==tamafis) {
        T *vaux= new T[tamafis=tamafis*2];
        for(int i=0;i<tamalog;i++)
            vaux[i]=vector[i];
        delete[] vector;
        vector=vaux;
    }

    if(pos==UINT_MAX){
        vector[tamalog++]=dato;
    }else{
        if(pos<0 )
            throw std::out_of_range ("La posicion no puede ser mayor que el numero de elementos del vector");

        if(tamalog!=0) {
            tamalog++;
            for (int i = tamalog - 1; i > pos +1; i--) {
                vector[i] = vector[i - 1];
            }
            vector[pos] = dato;
        }
    }

}
/**
 * @brief  Metodo de borrado en funcion de la posicion
 * @tparam T
 * @param pos posicion a eliminar
 * @return
 */
template<class T>
T VDinamico<T>::borrar(unsigned  int pos){
    //Si el tamaño logico es un tercio menor que el tamaño fisico
    if(tamalog*3 < tamafis){
        //Reducimos el tamaño fisico a la mitad
        tamafis = tamafis / 2;
        //Creo un vector como puntero con  el nuevo tamaño fisico reducido
        int *vaux = new int[tamafis];
        //Recorro el vector y lo pasamos  al vector en el nuevo vector puntero
        for(unsigned  i=0 ; i < tamalog; i++){
            vaux[i]= vector[i];
        }
        //Borre el vector
        delete []vector;
        //Sobreescribimos en el vector
        vector=vaux;
    }
    //Las posicion ha superado el tamaño del vector
    if(pos > tamalog)
        throw std::out_of_range("Posicion fuera del vector");
    //Si no le mandas ninguna posicion
    if(pos==UINT_MAX){
        //Devolvemos el vector
        return vector[--tamalog];
    }
    else {
        //Comprobar si el tamaño logico no esta vacio
        if (tamalog != 0) {
            //Movemos los datos hacia atras
            for (unsigned i = pos; i <tamalog; i++) {
                vector[i] =  vector[i + 1] ;
            }
            tamalog--;
        }
        return vector[--tamalog];

    }







}
/**
 * @brief Metodo para realizar la busqueda binaria del dato en el vecto
 * @tparam T
 * @param dato
 * @return
 */
template<class T>
int VDinamico<T>::busquedaBinaria(T &dato) {
    //Antes de realizar esto el vector deberia estar ordenado
    //Inicializamos una posicion inferior
    int inf= 0;
    //Incializamos la posicion superior
    int sup = tamafis -1 ;
    //Variable para la busqueda de la posicion
    int curIn;
    //Mientras la posicion
    while(inf <= sup){
        //Reducimos el vector para la busqueda
        curIn = (inf + sup)/2;
        //Si el vector tiene el dato pues devolvemos el partido
        if(vector[curIn] == dato)
            return  curIn;
        //Si el datos es menor que la posicion del vector
        else if (vector[curIn] < dato) inf = curIn + 1 ;
            else sup = curIn - 1 ;

    }
    //En caso de que no se realice la busqueda del dato dentro del vector devolvemos el fallo
    return  -1;
}

/**
 * @brief Metdodo para devolver el tamaño lógico
 * @tparam T
 * @return
 */
template<class T>
unsigned int  VDinamico<T>::tamlog() {
    return  tamalog;
}
#endif //VECTORESDINAMICOSB_VDINAMICO_H
