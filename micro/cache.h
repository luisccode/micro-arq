#ifndef CACHE_H
#define CACHE_H
#include <iomanip>
#include "macros.h"
#include <iostream>
#include<set>
#include <utility>
using namespace std;

SC_MODULE(Cache) {
	sc_in <sc_uint<4> > dir1,dir2;
	sc_in <sc_uint<4> > data_in1, data_in2;
	sc_out < sc_uint < INSTRUCTION > > data_out1, data_out2;
	set < pair < unsigned int, pair<unsigned int,unsigned int> >>data;
  	set < pair < unsigned int, pair<unsigned int,unsigned int> >>::iterator it, aux;

	sc_in <bool> enable;
	sc_out <bool> available_v1,available_v2;
	sc_in <bool> clk;

	void read() {
		if (clk.read() == 0 ) {
			it = data.begin();
			while (it!=data.end()){
				if( it->second.first == dir1.read() ){  // si la direccion es igual a la dir buscada 
					data_out1 = it->second.second; 
					aux = it;
				}
				it++; 
			}
			// se aumenta 1 al numero de accesos, OJO  podria salir mas facil con wsap()
			pair < unsigned int, pair<unsigned int,unsigned int> >g;
			g = make_pair(aux->first+1, make_pair(aux->second.first, aux->second.second));
			data.erase(aux); 
			data.insert (g);
		}
	}
	
	void write() {
		if (clk.read() && enable.read()) {
			pair < unsigned int, pair<unsigned int,unsigned int> >g1 = make_pair(1, make_pair(dir1.read(), data_in1.read()) );
			data.insert (g1);
			// el tamano maximo de la cache es 5
			if(data.size() >= 6){ // si se llena la cache eliminamos la variable menos usada
				it = data.begin();
				unsigned int min=it->first;
				while (it!=data.end()){
					if( (it->first <= min) && (it->second.first != data_in1.read()) ){ //se el selecciona la variable con menos accesos y que a la vez sea diferente de la nueva a ingresar
						aux = it;
						min=it->first;
					}
					it++; 
				}
				data.erase(aux); 
			}
		}
	}
	void update(){

	}
	SC_CTOR(Cache) {
		SC_METHOD(read);
		sensitive << clk.neg();
		SC_METHOD(write);
		sensitive << clk.pos();
	}
};

#endif
