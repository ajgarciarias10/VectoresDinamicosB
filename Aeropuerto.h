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
    UTM *posicion = nullptr;
public:
    //Constructor por defecto
    Aeropuerto() = default;
    //Constructor copia
    Aeropuerto(const Aeropuerto &origen);
    //Constructor parametrizado
    Aeropuerto(const string &id,const string &iden,
               const string &tipo, const string &nombre,
               const string &continente, const string &iso_pais, UTM *posicion);
    //Operador ==
    Aeropuerto &operator = (Aeropuerto &origen);
    //Operador <
    bool operator < (Aeropuerto &origen);

    const string &getId() const;

    void setId(const string &id);

    const string &getIdent() const;

    void setIdent(const string &ident);

    const string &getTipo() const;

    void setTipo(const string &tipo);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    UTM *getPosicion() const;

    void setPosicion(UTM *posicion);

    const string &getContinente() const;

    void setContinente(const string &continente);

    const string &getIsoPais() const;

    void setIsoPais(const string &isoPais);

public:


};



#endif //VECTORESDINAMICOSB_AEROPUERTO_H
