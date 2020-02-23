#include <iostream>
#include <Entidad.h>

using namespace std;
Entidad::Entidad(){

}
Entidad::Entidad(int atc,int ate, int atb, string nombre){
    Aum_t_cultural = atc;
    Aum_t_emocional = ate;
    Aum_t_biologico = atb;
    this->nombre = nombre;
}