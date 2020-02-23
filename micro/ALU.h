#ifndef ALU_H
#define ALU_H
#define Register_file "Register_file.txt"

#include <fstream>
#include <string>
#include "macros.h"

SC_MODULE(ALU)
{
  ifstream RF;
  sc_in <bool> clk;
  sc_out < sc_uint < INSTRUCTION > > value_1, value_2, res;
  sc_in < sc_uint < INSTRUCTION> > address_1, address_2, instruction;

  void operate()
  {
    RF.open(Register_file);
    string line;
    sc_uint < 4 > adress, v1, v2;
    
    while(not RF.eof())
    {
      getline(RF, line);
      for(int i = 4; i < OPERATOR_VALUE; ++i)
        (line[i] == '1') ? adress[OPERATOR_VALUE - 1 - i] = 1 : adress[OPERATOR_VALUE - 1 - i] = 0;
      
      if(adress == address_1)
      {
        for(int i = 0; i < 4; ++i)
          (line[i] == '1') ? v1[4 - 1 - i] = 1 : v1[4 - 1 - i] = 0;

        value_1.write(v1);
      }
      
      if(adress == address_2)
      {
        for(int i = 0; i < 4; ++i)
          (line[i] == '1') ? v2[4 - 1 - i] = 1 : v2[4 - 1 - i] = 0;

        value_2.write(v2);
      }
    }
    switch(instruction.read())
    {
      case 1: res.write(v1 + v2); break;
      case 2: res.write(v1 - v2); break;
      case 3: res.write(v1 * v2); break;
      case 4: res.write(int(v1 / v2)); break;
      default: break;
    }
    RF.close();
  }

  SC_CTOR(ALU)
  {
    SC_METHOD(operate);
    sensitive << address_1 << address_1;
  }

  ~ALU(){}
};

#endif