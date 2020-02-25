#ifndef ALU_H
#define ALU_H

#include <string>
#include "macros.h"

SC_MODULE(ALU)
{
  sc_in <bool> clk;
  sc_in < sc_uint < INSTRUCTION > > value_1, value_2,instruction;
  sc_out < sc_uint < INSTRUCTION > > res;

  void operate(){
    switch(instruction.read()){ 
      case 1: res.write(value_1.read() + value_2.read() ); break;
      case 2: res.write(value_1.read() - value_2.read() ); break;
      case 3: res.write(value_1.read() * value_2.read() ); break;
      case 4: res.write(int(value_1.read() / value_2.read() )); break;
      default: break;
    }
  }

  SC_CTOR(ALU)
  {
    SC_METHOD(operate);
    sensitive << value_1 << value_2;
  }

  ~ALU(){}
};

#endif