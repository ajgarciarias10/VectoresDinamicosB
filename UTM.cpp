//
// Created by ajgar on 26/09/2023.
//

#include "UTM.h"

float UTM::getLatitud() const {
    return latitud;
}

void UTM::setLatitud(float latitud) {
    UTM::latitud = latitud;
}

float UTM::getLonguitud() const {
    return longuitud;
}

void UTM::setLonguitud(float longuitud) {
    UTM::longuitud = longuitud;
}
