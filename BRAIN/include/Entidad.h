#ifndef ENTIDAD_H
#define ENTIDAD_H

#include<iostream>
using namespace std;

class Entidad{
    private: 
       	int Aum_t_cultural;
       	int Aum_t_emocional;
	   	int Aum_t_biologico;
        string nombre;
    public:
        Entidad();
        Entidad(int atc,int ate, int atb, string nombre);
};

#endif
