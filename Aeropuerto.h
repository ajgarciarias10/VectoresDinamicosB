//
// Created by ajgar on 26/09/2023.
//
/**
 * @file Aeropuerto.h
 * @date 04/10/2023
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @brief Aeropuerto
 */
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
    //Get ID
    const string &getId() const;
    //Get Identificacion
    const string &getIdent() const;
    //Get Nombre
    const string &getNombre() const;
    //Get Continente
    const string &getContinente() const;
    //Set Id
    void setId(const string &id);
};



#endif //VECTORESDINAMICOSB_AEROPUERTO_H
