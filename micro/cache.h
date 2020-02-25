#ifndef CACHE_H
#define CACHE_H

#include <systemc.h>
#include <iostream>
#include <iomanip>

using namespace std;

SC_MODULE(cache) {
	
	sc_in <sc_uint<4> > dir;
	sc_in <sc_uint<32> > data_in;
	sc_out <sc_uint<32> > data_out;
	
	sc_uint<32> data[16];
	
	sc_in <bool> enable;
	sc_in <bool> clk;

	void read() {
		if (clk.read() == 0) {
			data_out = data[dir.read()];
			cout << "Leyendo: data[" << dir.read() << "] almacena " << data[dir.read()] << "\n";
		}
	}
	
	void write() {
		// la condición del if es equivalente a:
		// (clk.read() != 0) && (enable.read() != 0)
		if (clk.read() && enable.read()) {
			data[dir.read()] = data_in.read();
			cout << "Escribiendo: data[" << dir.read() << "] = " << data[dir.read()] << "\n";
			for (int i = 0; i < 16; ++i) {
				cout << setw(2) << i << ": ";
				for (int j = 31; j >= 0; --j)
					cout << data[i].range(j,j);
				cout << endl;
			}
		}
	}

	SC_CTOR(cache) {
		SC_METHOD(read);
		sensitive << clk.neg(); //0
		SC_METHOD(write);
		sensitive << clk.pos(); //1
	}
};

#endif//CACHE_H
