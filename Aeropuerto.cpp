//
// Created by ajgar on 26/09/2023.
//

#include "Aeropuerto.h"



/**
 * @brief   Metodo Constructor de copia
 * @param origen
 */
Aeropuerto::Aeropuerto(const Aeropuerto &origen):id(origen.id),ident(origen.ident),tipo(origen.tipo),nombre(origen.nombre),continente(origen.continente),iso_pais(origen.iso_pais),posicion(origen.posicion) {}
/**
 * @brief Constructor parametrizado
 * @param id
 * @param iden
 * @param tipo
 * @param nombre
 * @param continente
 * @param iso_pais
 * @param posicion
 */
Aeropuerto::Aeropuerto(const string &id, const string &iden, const string &tipo, const string &nombre,
                       const string &continente, const string &iso_pais, UTM posicion) : id(id),ident(iden),tipo(tipo),nombre(nombre),continente(continente),iso_pais(iso_pais),posicion(posicion) {

}
bool Aeropuerto::operator==(const Aeropuerto &origen) {
        return  (this->id == origen.id);
}
/**
 * @brief Metodo Operator ==
 * @param origen
 * @return
  */
Aeropuerto &Aeropuerto::operator =(const Aeropuerto &origen){
    //Comprobamos que no sea la misma direccion de memoria
    if(this!= &origen){

        //Asignamos a cada operando  su valor
        id= origen.id;
        ident = origen.ident;
        tipo = origen.tipo;
        nombre = origen.nombre;
        continente = origen.continente;
        iso_pais = origen.iso_pais;
        posicion = origen.posicion;
    }
    //Devolvemos el aeropuerto
    return  *this;

}

/**
 * @brief Metodo operator < para comparar ids
 * @param origen
 * @return
 */
bool Aeropuerto::operator<(Aeropuerto &origen) {
    return  (stoi(id) < stoi(origen.id));

}

const string &Aeropuerto::getId() const {
    return id;
}

void Aeropuerto::setId(const string &id) {
    Aeropuerto::id = id;
}

const string &Aeropuerto::getIdent() const {
    return ident;
}

void Aeropuerto::setIdent(const string &ident) {
    Aeropuerto::ident = ident;
}

const string &Aeropuerto::getTipo() const {
    return tipo;
}

void Aeropuerto::setTipo(const string &tipo) {
    Aeropuerto::tipo = tipo;
}

const string &Aeropuerto::getNombre() const {
    return nombre;
}

void Aeropuerto::setNombre(const string &nombre) {
    Aeropuerto::nombre = nombre;
}

void Aeropuerto::setPosicion(const UTM &posicion) {
    Aeropuerto::posicion = posicion;
}

const string &Aeropuerto::getContinente() const {
    return continente;
}

void Aeropuerto::setContinente(const string &continente) {
    Aeropuerto::continente = continente;
}

const string &Aeropuerto::getIsoPais() const {
    return iso_pais;
}

void Aeropuerto::setIsoPais(const string &isoPais) {
    iso_pais = isoPais;
}


