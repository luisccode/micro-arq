#ifndef FETCH_H
#define FETCH_H
#define MI_filename "ISA.txt"

#include <fstream>
#include <string>
#include "macros.h"
using namespace std;

SC_MODULE(Fetch){
  ifstream MI;
  sc_in <bool> clk;
  sc_out < sc_uint < INSTRUCTION_SIZE> > instruction_in;
  
  void fetch()
	{
		string line;
		getline(MI, line);
		sc_uint < INSTRUCTION_SIZE > read_instruction;

		for(int i = 0; i < INSTRUCTION_SIZE; ++i)
      (line[i] == '1') ? read_instruction[INSTRUCTION_SIZE - 1 - i] = 1 : read_instruction[INSTRUCTION_SIZE - 1 - i] = 0;

    instruction_in.write(read_instruction);
	}
  
  SC_CTOR (Fetch)
  {
    MI.open(MI_filename);
    SC_METHOD(fetch);
    sensitive << clk.pos();
  }
  
  ~Fetch()
  {
    MI.close();
  }
};

#endif
