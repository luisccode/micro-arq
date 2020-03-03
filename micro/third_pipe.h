#ifndef SECOND_PIPE
#define SECOND_PIPE

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "macros.h"
#define Register_file "Register_file.txt"

SC_MODULE(Third_pipe){
  sc_in <bool> clk;
  sc_in < sc_uint < INSTRUCTION > > res_address, res;
ifstream RF;

  void write_back(){
    int n_line=0;
    RF.open(Register_file);
    string new_line,line, res_value;
    sc_uint < 4 > adress;
    vector<string> all_lines;
    
    while(not RF.eof()){
      getline(RF, line);
      all_lines.push_back(line);
      for(int i = 4; i < OPERATOR_VALUE; ++i)
        (line[i] == '1') ? adress[OPERATOR_VALUE - 1 - i] = 1 : adress[OPERATOR_VALUE - 1 - i] = 0;
      
      if(adress == res_address){
            for (int i = 0; i < INSTRUCTION; ++i) 
               res_value.append( to_string( res.read().range(INSTRUCTION-(i+1),INSTRUCTION-(i+1)) ) ) ;
            
            new_line = res_value + line.substr(4,4);
            break;
      }
      n_line++;
    }
    RF.close();
   

    // int n=0;
    // ofstream RF2;
    // RF2.open(Register_file);
    // for(int i=0; i<all_lines.size(); i++){
    //     if(n==n_line){
    //         RF2<<new_line<<endl;
    //     }
    //     else{
    //         RF2<<all_lines[i]<<endl;
    //     }
    //     n++;
    // }
    // RF2.close();
  }
  SC_CTOR(Third_pipe)
  {
    SC_METHOD(write_back);
    sensitive << res_address;
  }

  ~Third_pipe(){}
};

#endif