#ifndef ENTIDAD_H
#define ENTIDAD_H

#include<iostream>
using namespace std;

class Entidad{
    private: 
       	int Aum_biologico;
       	int Aum_cultural;
	   	int Aum_emocional;
        bool visitado;

        string nombre;
    public:
        Entidad();
        Entidad(int atb,int atc, int ate, string nombre);
};

#endif
