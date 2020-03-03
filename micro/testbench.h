#ifndef TESTBENCH

#include <iomanip>
#include "macros.h"

SC_MODULE(Testbench)
{
  sc_in <bool> clk;
  sc_in < sc_uint < INSTRUCTION > > instruction, address_1, address_2, res_address, value_1, value_2, res;
  // sc_in < sc_uint < INSTRUCTION_SIZE> > pipe1 /*, pipe2, pipe3*/;

  void print()
  {
    cout << setw(4);
    for (int i = 0; i < INSTRUCTION; ++i) //Imprime la Instrucciones en binario
      cout << instruction.read().range(INSTRUCTION-(i+1),INSTRUCTION-(i+1));
    cout << setw(9) << "|    ";

    for (int i = 0; i < INSTRUCTION; ++i) //Imprime la Dirección del Operando 1 en binario
      cout << address_1.read().range(INSTRUCTION-(i+1),INSTRUCTION-(i+1));
    cout << "    | " << setw(4);

    for (int i = 0; i < INSTRUCTION; ++i) //Imprime la Dirección del Operando 2 en binario
      cout << address_2.read().range(INSTRUCTION-(i+1),INSTRUCTION-(i+1));
    cout << "    |" << setw(4);

    for (int i = 0; i < INSTRUCTION; ++i) //Imprime el Valor del Operando 1 en binario
      cout << value_1.read().range(INSTRUCTION-(i+1),INSTRUCTION-(i+1));
    cout << "    |" << setw(4);

    for (int i = 0; i < INSTRUCTION; ++i) //Imprime el Valor del Operando 2 en binario
      cout << value_2.read().range(INSTRUCTION-(i+1),INSTRUCTION-(i+1));
    cout << "   |" << setw(3);

    for (int i = 0; i < INSTRUCTION; ++i) //Imprime el Resultado de la operación en binario
      cout<< res_address.read().range(INSTRUCTION-(i+1),INSTRUCTION-(i+1));
    cout << " | " << setw(3);
    
    for (int i = 0; i < INSTRUCTION; ++i) //Imprime el Resultado de la operación en binario
      cout<< res.read().range(INSTRUCTION-(i+1),INSTRUCTION-(i+1));
    cout << " | " << setw(3);

    cout << instruction.read(); //Imprime las Instrucciones en decimal
    cout << setw (11) << "|   ";

    switch(instruction.read())
    {
      case 1: cout << "ADD"; break;
      case 2: cout << "SUB"; break;
      case 3: cout << "MUL"; break;
      case 4: cout << "DIV"; break;
      case 5: cout << "LOAD"; break;
      case 6: cout << "STORE"; break;
      default: cout << "Por definir"; break;
    }
    cout << "\n";
  }

  void test()
  {
    cout << "\nInstrucción|  Dir. Op1  |  Dir. Op2  | Val. Op1  | Val. Op2 | Res dir|  Res  | Inst. Decimal | Operación\n"
         << "------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < 6; ++i)
    {
      wait();
      print();
    }
    
    sc_stop();
  }

  SC_CTOR(Testbench)
  {
    SC_THREAD(test);
    sensitive << value_1 << value_2;
  }
};

#endif