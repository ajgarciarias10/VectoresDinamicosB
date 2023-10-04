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
    string id = "",ident = "", tipo =" ", nombre = "",continente = " ", iso_pais = "";
    UTM posicion  ;
public:
    //Constructor por defecto
    Aeropuerto();
    //Constructor copia
    Aeropuerto(const Aeropuerto &origen);
    //Constructor parametrizado
    Aeropuerto(const string &id,const string &iden,
               const string &tipo, const string &nombre,
               const string &continente, const string &iso_pais, UTM posicion);
    //Operador ==
    bool operator == (const Aeropuerto &origen);
    //Operador =
    Aeropuerto &operator = (const Aeropuerto &origen);
    //Operador <
    bool operator< (const Aeropuerto &origen) const;
    //Getters que he usado
    const string &getId() const;
    const string &getIdent() const;
    const string &getNombre() const;
    const string &getContinente() const;
};



#endif //VECTORESDINAMICOSB_AEROPUERTO_H
