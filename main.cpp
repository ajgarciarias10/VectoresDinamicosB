#include <iostream>
#include "time.h"
#include "VDinamico.h"
#include "Aeropuerto.h"
#include "UTM.h"
#include <fstream>
#include <string>
#include <sstream>


/**
 * @brief
 *
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @return
 */
int main(int argc, const char * argv[]) {
    VDinamico<Aeropuerto> vector;
    std::ifstream is;
    std::stringstream  columnas;
    std::string fila;
    clock_t t_total = clock();

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
                contador++;
                /*
               std::cout
                       << " Aeropuerto: ( ID=" << id
                       << " ident=" << ident << " Tipo=" << tipo << " Nombre=" << nombre
                       << " Posicion=(" << latitud << ", " << longitud << ")"
                       << " Continente=" << continente << " Pais=" << iso_pais
                       << ")" << std::endl;
                */
                //Creamos puntero de tipo utm
               UTM *utm= new UTM(latitud,longitud);
               //Metemos el puntero utm en un objeto aeropuerto
               Aeropuerto *aeropuerto=new Aeropuerto(id,ident,tipo,nombre,continente,iso_pais,*utm);
               //Insertamos en el vector dinamicco
               vector.insertar(*aeropuerto);
               //Aumentamos el numero de elementos tras insertar
               nElementos++;
                //Borramos el aeropuerto
               delete aeropuerto;
               //Borramos utm
               delete utm;

           }
       }
       //Cerrar
       is.close();
       std::cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
   } else {
       std::cout << "Error de apertura en archivo" << std::endl;
   }
    //Contador de tiempo
   clock_t t_ordenar = clock();
   //Ordenar vector  de menor a mayor
   vector.ordenar();
   std::cout << "Tiempo durante el orden de menor a mayor: " << ((clock() - t_ordenar) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    //Mostramos por pantalla los primeros  30 aeropuertos
    for (int i =1   ; i < 30; ++i) {
        std::cout<< "Nombre: " + vector[i].getNombre() +" Id: "+ vector[i].getId() + "\n" << std::endl;
    }
    clock_t t_ordenar2 = clock();
   //Ordenar vector de mayor a menor
    vector.ordenarRev();
    std::cout << "Tiempo durante el orden de mayor a menor: " << ((clock() - t_ordenar2) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
   //Mostramos por pantalla los  ultimos  30 aeropuertos
    for (int i =1   ; i < 30; ++i) {
        std::cout<< "Nombre: " + vector[i].getNombre() +" Id: "+ vector[i].getId() + "\n" << std::endl;
    }
    clock_t t_busqueda = clock();
    //Busqueda Binaria por ids y devolver posicion
    VDinamico<Aeropuerto> busquedaPorID;
    UTM* utm = new UTM(0.0,0.0);
    busquedaPorID.insertar(Aeropuerto("345166","","","","","",*utm));
    busquedaPorID.insertar(Aeropuerto("6640","","","","","",*utm));
    busquedaPorID.insertar(Aeropuerto("6676","","","","","",*utm));
    busquedaPorID.insertar(Aeropuerto("345364","","","","","",*utm));
    busquedaPorID.insertar(Aeropuerto("6778","","","","","",*utm));

    //Antes de la busqueda binaria el vector tiene que ordenarser de mayor a menor
    vector.ordenar();
    for (int j = 0; j < 5 ; ++j) {
        int pos =  vector.busquedaBinaria(busquedaPorID[j]);
        if(pos != -1){
            std::cout<< "Aeropuerto: " + vector[pos].getNombre() + " Encontrado en la posicion : " + to_string(pos)+ "\n" << std::endl;
        }else{
            std::cout<< "El aeropuerto no ha sido encontrado con id: " + busquedaPorID[j].getId()+  "\n" << std::endl;

        }
    }
    delete utm;
    std::cout << "Tiempo de busqueda binaria: " << ((clock() - t_busqueda) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;


//Eliminar aeropuertos cuyo continente sea "NA"
   clock_t t_elimina_inser = clock();
   VDinamico<Aeropuerto> CNA;
   int i = 0;
    while (i < vector.tamlog()) {
       while(vector[i].getContinente() == "NA"){
           //Insertamos en el vector de AEROPUERTOS CON CONTINENTE NA
           CNA.insertar(vector[i]);
           //Borrar en el vector de Aeropuertos, la posicion de aeropuertos NA
           vector.borrar(i);
       }
       i++;
   }
   std::cout<< "Vector con continentes su tamaño es: " + to_string(vector.tamlog())  + "\n" << std::endl;
   std::cout<<"Contenido del vector sin contientes: "  "\n" <<std::endl;
   for (int i = 0; i < 20; ++i) {
       std::cout<< "Aeropuerto: " + vector[i].getNombre() + " Identificacion : " + vector[i].getIdent() + "\n" << std::endl;
   }

   std::cout<< "Vector sin contientes  su tamaño es: " + to_string(CNA.tamlog())  << std::endl;
   std::cout<<"Contenido del vector sin contientes: "  "\n" <<std::endl;
   for (int i = 0; i < 20; ++i) {
       CNA.ordenar();
       std::cout<< "Aeropuerto: " + CNA[i].getNombre() + " Identificacion : " + CNA[i].getIdent() + "\n" << std::endl;
   }
    std::cout << "Tiempo elimina e inserta: " << ((clock() - t_elimina_inser) / (float) CLOCKS_PER_SEC) << " segs."   "\n"<< std::endl;


    std::cout << "Tiempo total: " << ((clock() -t_total ) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;

    return 0;

  }
