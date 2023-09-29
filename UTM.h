//
// Created by ajgar on 26/09/2023.
//

#ifndef VECTORESDINAMICOSB_UTM_H
#define VECTORESDINAMICOSB_UTM_H


class UTM {
public:
    UTM()=default;

    float getLatitud() const;

    void setLatitud(float latitud);

    float getLonguitud() const;

    void setLonguitud(float longuitud);

private:
    float latitud = 0.0;
    float longuitud = 0.0;
};



#endif //VECTORESDINAMICOSB_UTM_H
