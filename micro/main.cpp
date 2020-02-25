#include <systemc.h>
#include <string>
#include <iomanip>
#include "pipe.h"
#include "first_pipe.h"
#include "second_pipe.h"
#include "macros.h"
#include "cache.h"
#include "fetch.h"
#include "ALU.h"

#include "testbench.h"

int sc_main(int argv, char* argc[])
{
  sc_time PERIOD(10, SC_NS);
  sc_time DELAY(10, SC_NS);
  sc_clock clock("clock", PERIOD, 0.5, DELAY, true);
  
  Fetch ft("fetch");
  First_pipe pipe1("pipe1");
  Cache cache("cache1");
  Second_pipe pipe2("pipe2");
  ALU alu("alu");
  Testbench tb("tb");
  
  sc_signal<bool> enable_sg;
  sc_signal < sc_uint < INSTRUCTION > > instruction_sg;
  sc_signal < sc_uint < INSTRUCTION > > address_1_sg, address_2_sg, res_address_sg, value_1_sg, value_2_sg, res_sg;
  sc_signal < sc_uint < INSTRUCTION_SIZE > > pc;
  
  ft.instruction_in(pc);
  ft.clk(clock);
  
  pipe1.clk(clock);
  pipe1.instruction_to_decode(pc);
  pipe1.instruction(instruction_sg);
  pipe1.address_1(address_1_sg);
  pipe1.address_2(address_2_sg);
  pipe1.res_address(res_address_sg);

  cache.clk(clock);
  cache.enable(enable_sg);
  cache.dir1(address_1_sg);
  cache.dir2(address_2_sg);
  cache.data_in1(value_1_sg);
  cache.data_in2(value_2_sg);
  cache.value_1(value_1_sg);
  cache.value_2(value_2_sg);


  pipe2.clk(clock);
  pipe2.address_1(address_1_sg);
  pipe2.address_2(address_2_sg);
  pipe2.value_1(value_1_sg);
  pipe2.value_2(value_2_sg);


  alu.clk(clock);
  alu.instruction(instruction_sg);
  alu.value_1(value_1_sg);
  alu.value_2(value_2_sg);
  alu.res(res_sg);

  tb.clk(clock);
  tb.instruction(instruction_sg);
  tb.address_1(address_1_sg);
  tb.address_2(address_2_sg);
  tb.res_address(res_address_sg);
  tb.value_1(value_1_sg);
  tb.value_2(value_2_sg);
  tb.res(res_sg);
  
  sc_start();
  return 0;
}
