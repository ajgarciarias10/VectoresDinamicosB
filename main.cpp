#include <iostream>
#include "stdexcept"
#include "stdlib.h"
#include "time.h"
#include "VDinamico.h"


/**
 * @brief Crear un vector dinamico de tamaño 1 millon y almacena valores aleatorios no repetidos
 * Ademas de eso en funcion de lo que queramos ordena el vector
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @return
 */
int main() {
    int limite = 1000;
    //Definimos el vector dinamico con limite de elementos
    VDinamico<int> v(limite);
    int i =0;
    // Inicializo un semilla aleatoria
    srand(time(NULL));
    try{
        while (i<limite){
            bool encontrado=false;
            int numero = rand()%100000+67700;

            for (int j = 0; j < i && !encontrado; j++) {
                if (v[j] == numero){
                    encontrado= true;
                }
            }

            if(!encontrado){
                v[i]=numero;
                std::cout<<std::endl<< "i ="<< i;
                std::cout<<" ,numero: "<<v[i]<<std::endl;
                i++;
            }

        }

        //region Imprimo el vector menor a mayor
        v.ordenar();
        std::cout<<std::endl<<"Vector ordenado de menor a mayor:"<<std::endl;
        for (int j = 0; j <20; j++) {
            std::cout<<"Numero "<<j+1<<" : ";
            std::cout << v[j] << std::endl;
        }
        //endregion
        //region Imprimo el vector mayor a menor
        v.ordenarMayorAmenor();
        std::cout<<"Vector ordenado de mayor a menor:"<<std::endl;
        for (int j = 0; j <20; j++) {
            std::cout<<"Numero "<<j+1<<" : ";
            std::cout << v[j] << std::endl;
        }
        //endregion
    } catch (std::invalid_argument &error) {
        std::cerr<<error.what()<<std::endl;
    } catch (std::out_of_range &error) {
        std::cerr << error.what() << std::endl;
    } catch (std::bad_alloc &error) {
        std::cerr << error.what() << std::endl;
    }

}
