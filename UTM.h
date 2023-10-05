//
// Created by ajgar on 26/09/2023.
//
/**
 * @file UTM.h
 * @date 04/10/2023
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @brief UTM
 */

#ifndef VECTORESDINAMICOSB_UTM_H
#define VECTORESDINAMICOSB_UTM_H


class UTM {
public:
    UTM()=default;

    UTM(const float  &latitud, const float &longuitud);

    float getLatitud() const;

    void setLatitud(float latitud);

    float getLonguitud() const;

    void setLonguitud(float longuitud);

private:
    float latitud = 0.0;
    float longuitud = 0.0;
};




#endif //VECTORESDINAMICOSB_UTM_H
