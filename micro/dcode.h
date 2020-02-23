#ifndef DCODE_H
#define DCODE_H

#include <string>
#include <iomanip>
#include "macros.h"
using namespace std;

SC_MODULE(Dcode)
{
  sc_in <bool> clk;
  sc_in < sc_uint < INSTRUCTION_SIZE > > instruction_to_decode;
  sc_out < sc_uint < INSTRUCTION > > instruction;
  sc_out < sc_uint < INSTRUCTION > > address_1, address_2, res_address;
  sc_uint < INSTRUCTION > temp;

  void dcode()
  {
    instruction.write(instruction_to_decode.read().range(3, 0));
    address_1.write(instruction_to_decode.read().range(7, 4));
    address_2.write(instruction_to_decode.read().range(11, 8));
    res_address.write(instruction_to_decode.read().range(15, 12));
  }
  
  SC_CTOR(Dcode)
  {
    SC_METHOD(dcode);
    sensitive << clk.pos();
  }
  
  ~Dcode(){}
};

#endif