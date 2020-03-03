#include <iostream>
#include <Entidad.h>

using namespace std;
Entidad::Entidad(){

}
Entidad::Entidad(int atc,int ate, int atb, string nombre){
    Aum_cultural = atc;
    Aum_emocional = ate;
    Aum_biologico = atb;
    this->nombre = nombre;
}