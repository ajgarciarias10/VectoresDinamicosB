/**
 * @file main.cpp
 * @brief Practica 1b
 * @date 04/10/2023
 * @post 1- Lectura de un fichero csv que contiene los datos de un aeropuerto
 * @post 2- Inserccion en una estructura de datos : vector dinamico, que en este caso VDinamico<Aeropuerto>
 * @post 3- Tras eso hemos realizado operaciones  dentor del vector que son : busqueda, inserccion y borrado
 * @post 4- Y tambien hemos realizado un tipo de busqueda eficiente que es la busqueda binaria
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @return
 */
#include <iostream>
#include "time.h"
#include "VDinamico.h"
#include "Aeropuerto.h"
#include "UTM.h"
#include <fstream>
#include <string>
#include <sstream>
int main(int argc, const char * argv[]) {
    VDinamico<Aeropuerto> vector;
    std::ifstream is;
    std::stringstream  columnas;
    std::string fila;
    clock_t t_total = clock();

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
        clock_t  t_ini  =clock();


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
               //Insertamos en el vector dinamicco
               vector.insertar(*new Aeropuerto(id,ident,tipo,nombre,continente,iso_pais,*new UTM(latitud,longitud)));
           }
       }
       //Cerrar
       is.close();
       std::cout << "Tiempo lectura y escritura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
   } else {
       std::cout << "Error de apertura en archivo" << std::endl;
   }
    try {
        std::cout<<std::endl<<"-------------------------------------Ordenar Menor a Mayor--------------------------------------""\n"<<std::endl<<std::endl;

        //Contador de tiempo
        clock_t t_ordenar = clock();

        //Ordenar vector  de menor a mayor
        vector.ordenar();

        //Mostramos por pantalla los primeros  30 aeropuertos
        for (int i = 1; i < 30; ++i) {
            std::cout<< "ID: " + vector[i].getId() +"; Aeropuerto: " + vector[i].getNombre()+"\n"<< std::endl;;
        }

        std::cout << "Tiempo durante el orden de menor a mayor: " << ((clock() - t_ordenar) / (float) CLOCKS_PER_SEC)
                  << " segs."  << std::endl;

        std::cout<<std::endl<<"-------------------------------------Ordenar Mayor a Menor--------------------------------------"<<std::endl<<std::endl;

        clock_t t_ordenar2 = clock();

        //Ordenar vector de mayor a menor
        vector.ordenarRev();

        //Mostramos por pantalla los  ultimos  30 aeropuertos
        for (int i = 1; i < 30; ++i) {
            std::cout<< "ID: " + vector[i].getId() +"; Aeropuerto: " + vector[i].getNombre()+"\n"<< std::endl;;
        }
        std::cout << "Tiempo durante el orden de mayor a menor: " << ((clock() - t_ordenar2) / (float) CLOCKS_PER_SEC)
                  << " segs."<< std::endl;

        std::cout<<std::endl<<"-------------------------------------Busqueda Binaria/Dicotomica--------------------------------------"<<std::endl<<std::endl;

        clock_t t_busqueda = clock();

        //Busqueda Binaria por ids y devolver posicion
        VDinamico<Aeropuerto> busquedaPorID(5);
        Aeropuerto aux;
        for (int i = 0; i < 5 ; ++i) {
            busquedaPorID.insertar(aux);
        }
        busquedaPorID[0].setId("345166");
        busquedaPorID[1].setId("6640");
        busquedaPorID[2].setId("6676");
        busquedaPorID[3].setId("345364");
        busquedaPorID[4].setId("6778");

        //Antes de la busqueda binaria el vector tiene que ordenarser de mayor a menor
        vector.ordenar();
        for (int j = 0; j < 5; ++j) {
            int pos = vector.busquedaBinaria(busquedaPorID[j]);
            if (pos != -1) {
                std::cout
                        << "ID: " + vector[pos].getId() +"; Aeropuerto: " + vector[pos].getNombre() + "; Encontrado en la posicion : " + to_string(pos) +
                           "\n" << std::endl;
            } else {
                std::cout << "El aeropuerto no ha sido encontrado con id: " + busquedaPorID[j].getId() + "\n"
                          << std::endl;

            }
        }
        std::cout << "Tiempo de busqueda binaria: " << ((clock() - t_busqueda) / (float) CLOCKS_PER_SEC) << " segs."
                  << std::endl;

        std::cout<<std::endl<<"-------------------------------------Insertar y eliminar por continente = NA --------------------------------------"<<std::endl<<std::endl;

        //Eliminar aeropuertos cuyo continente sea "NA"
        clock_t t_elimina_inser = clock();
        VDinamico<Aeropuerto> CNA;
        int i = 0;
        while (i < vector.tamlog()) {
            while (vector[i].getContinente() == "NA") {
                //Insertamos en el vector de AEROPUERTOS CON CONTINENTE NA
                CNA.insertar(vector[i]);
                //Borrar en el vector de Aeropuertos, la posicion de aeropuertos NA
                vector.borrar(i);
            }
            i++;
        }

        std::cout << "Vector con continentes su tamaño es: " << vector.tamlog() << "\n" << std::endl;
        std::cout << "Contenido del vector con contientes: "  "\n" << std::endl;
        for (int i = 0; i < 20; ++i) {
            std::cout << "ID: " + vector[i].getId() +"; Aeropuerto: " + vector[i].getNombre() +"\n" << std::endl;
        }

        std::cout << "Vector sin contientes  su tamaño es: " <<CNA.tamlog() << std::endl;
        std::cout << "Contenido del vector sin contientes: "  "\n" << std::endl;
        //Los 20 primeros
        CNA.ordenar();
        for (int i = 0; i < 20; ++i) {
            std::cout
                    << "ID: " << CNA[i].getId() <<"; Aeropuerto: " << CNA[i].getNombre() <<"\n" << std::endl;
        }
        std::cout << "Tiempo elimina e inserta: " << ((clock() - t_elimina_inser) / (float) CLOCKS_PER_SEC)<< " segs."   "\n" << std::endl;
        std::cout << "Tiempo total: " << ((clock() - t_total) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;

    }catch (std::out_of_range &e) {
        std::cerr<<e.what();
    }catch (std::bad_alloc &e){
        std::cerr<<e.what();
    } catch (std::invalid_argument &e) {
        std::cerr<<e.what();
    }
    return 0;

  }
