#include <systemc.h>
#include <string>
#include <iomanip>
#include "pipe.h"
#include "dcode.h"
#include "macros.h"
#include "fetch.h"
#include "ALU.h"
#include "testbench.h"

int sc_main(int argv, char* argc[])
{
  sc_time PERIOD(10, SC_NS);
  sc_time DELAY(10, SC_NS);
  sc_clock clock("clock", PERIOD, 0.5, DELAY, true);
  
  Fetch ft("fetch");
  Dcode dcode("dcode");
  ALU alu("alu");
  Testbench tb("tb");
  
  
  sc_signal < sc_uint < INSTRUCTION > > instruction_sg;
  sc_signal < sc_uint < INSTRUCTION > > address_1_sg, address_2_sg, res_address_sg, value_1_sg, value_2_sg, res_sg;
  sc_signal < sc_uint < INSTRUCTION_SIZE > > pc;
  
  ft.instruction_in(pc);
  ft.clk(clock);
  
  dcode.clk(clock);
  dcode.instruction_to_decode(pc);
  dcode.instruction(instruction_sg);
  dcode.address_1(address_1_sg);
  dcode.address_2(address_2_sg);
  dcode.res_address(res_address_sg);

  alu.clk(clock);
  alu.instruction(instruction_sg);
  alu.address_1(address_1_sg);
  alu.address_2(address_2_sg);
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
