#ifndef SECOND_PIPE_H 
#define SECOND_PIPE_H

#include <iomanip>
#include "macros.h"
#include <string>

#define Register_file "Register_file.txt"

SC_MODULE(Second_pipe)
{
  ifstream RF;
  sc_in <bool> clk;
  sc_in < sc_uint < INSTRUCTION> > address_1, address_2;
  sc_out < sc_uint < INSTRUCTION > > value_1, value_2;
	sc_out <bool> available_v1,available_v2;

  void operate(){
    RF.open(Register_file);
    string line;
    sc_uint < 4 > adress, v1, v2;
    
    while(not RF.eof()){
      getline(RF, line);
      for(int i = 4; i < OPERATOR_VALUE; ++i)
        (line[i] == '1') ? adress[OPERATOR_VALUE - 1 - i] = 1 : adress[OPERATOR_VALUE - 1 - i] = 0;
      
      if(adress == address_1){
        for(int i = 0; i < 4; ++i)
          (line[i] == '1') ? v1[4 - 1 - i] = 1 : v1[4 - 1 - i] = 0;

        value_1.write(v1);
      }
      
      if(adress == address_2){
        for(int i = 0; i < 4; ++i)
          (line[i] == '1') ? v2[4 - 1 - i] = 1 : v2[4 - 1 - i] = 0;

        value_2.write(v2);
      }
    }
    RF.close();
  }

  SC_CTOR(Second_pipe)
  {
    SC_METHOD(operate);
    sensitive << address_1 << address_1;
  }

  ~Second_pipe(){}
};



#endif