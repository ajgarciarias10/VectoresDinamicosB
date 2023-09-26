//
// Created by ajgar on 26/09/2023.
//

#ifndef VECTORESDINAMICOSB_AEROPUERTO_H
#define VECTORESDINAMICOSB_AEROPUERTO_H
#include "stdexcept"
#include "algorithm"
#include "UTM.h"
#include <string>
using namespace  std;
class Aeropuerto {
private:
    string id;
    string ident;
    string tipo;
    string nombre;
    UTM *posicion;
    string continente;
    string iso_pais;

};


#endif //VECTORESDINAMICOSB_AEROPUERTO_H
