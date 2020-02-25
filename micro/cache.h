#ifndef CACHE_H
#define CACHE_H


#include <iomanip>
#include "macros.h"
#include <string>

using namespace std;

SC_MODULE(Cache) {
	
	sc_in <sc_uint<4> > dir1,dir2;
	sc_in <sc_uint<4> > data_in1,data_in2;
	sc_out < sc_uint < INSTRUCTION > > value_1, value_2;

	sc_uint<4> data[5];

	sc_in <bool> enable;
	sc_in <bool> clk;

	void read() {
		if (clk.read() == 0 ) {
			value_1 = data[dir1.read()];
			value_2 = data[dir2.read()];
			cout << "Leyendo: data[" << dir1.read() << "] almacena " << data[dir1.read()] << "\n";
			cout << "Leyendo: data[" << dir2.read() << "] almacena " << data[dir2.read()] << "\n";
		}
	}
	
	void write() {
		// la condición del if es equivalente a:
		// (clk.read() != 0) && (enable.read() != 0)
		if (clk.read() && enable.read()) {
			data[dir1.read()] = data_in1.read();
			data[dir2.read()] = data_in2.read();
			cout << "Escribiendo: data[" << dir1.read() << "] = " << data[dir1.read()] << "\n";
			cout << "Escribiendo: data[" << dir2.read() << "] = " << data[dir2.read()] << "\n";
			for (int i = 0; i < 5; ++i) {
				cout << setw(2) << i << ": ";
				for (int j = 3; j >= 0; --j)
					cout << data[i].range(j,j);
				cout << endl;
			}
		}
	}

	SC_CTOR(Cache) {
		SC_METHOD(read);
		sensitive << clk.neg(); //0
		SC_METHOD(write);
		sensitive << clk.pos(); //1
	}
};

#endif//CACHE_H
