#include <iostream>
#include "time.h"
#include "VDinamico.h"
#include "Aeropuerto.h"
#include "UTM.h"
#include <fstream>
#include <string>
#include <sstream>


/**
 * @brief Crear un vector dinamico de tamaño 1 millon y almacena valores aleatorios no repetidos
 * Ademas de eso en funcion de lo que queramos ordena el vector
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @return
 */
int main(int argc, const char * argv[]) {
    VDinamico<Aeropuerto> vector;
    Aeropuerto aeropuerto;

    std::ifstream is;
    std::stringstream  columnas;
    std::string fila;
    int contador=0;
    int nElementos=0;

    std::string id = "";
    std::string ident="";
    std::string tipo="";
    std::string nombre="";
    std::string latitud_str="";
    std::string longitud_str="";
    std::string continente="";
    std::string iso_pais="";

    float latitud, longitud;

    is.open("../aeropuertos.csv"); //carpeta de proyecto
    //Abrir
    if ( is.good() ) {

        clock_t t_ini = clock();

        while ( getline(is, fila ) ) {

            //¿Se ha leído una nueva fila?
            if (fila!="") {

                columnas.str(fila);

                //formato de fila: id;ident;tipo;nombre;latitud;longitud;continente;iso_pais

                getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas,ident,';');
                getline(columnas,tipo,';');
                getline(columnas,nombre,';');
                getline(columnas,latitud_str,';');
                getline(columnas,longitud_str,';');
                getline(columnas,continente,';');
                getline(columnas,iso_pais,';');


                //  Transformamos la latitud y longitud a float
                latitud=std::stof(latitud_str);
                longitud=std::stof(longitud_str);

                fila="";
                columnas.clear();
                contador++;
                /*
                std::cout
                        << " Aeropuerto: ( ID=" << id
                        << " ident=" << ident << " Tipo=" << tipo << " Nombre=" << nombre
                        << " Posicion=(" << latitud << ", " << longitud << ")"
                        << " Continente=" << continente << " Pais=" << iso_pais
                        << ")" << std::endl;
*/

                UTM *utm= new UTM(latitud,longitud);

                Aeropuerto *aeropuerto=new Aeropuerto(id,ident,tipo,nombre,continente,iso_pais,*utm);
                vector.insertar(*aeropuerto);
                nElementos++;

                delete aeropuerto;
                delete utm;

            }
        }

        //Cerrar
        is.close();
        std::cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;

    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
    vector.ordenar();
    for (int i =1   ; i < 30; ++i) {
        std::cout<< vector[i].getId()<< std::endl;
    }




    return 0;

}
