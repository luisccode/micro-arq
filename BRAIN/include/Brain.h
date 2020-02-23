#ifndef BRAIN_H
#define BRAIN_H

#include<iostream>
#include <string>
using namespace std;

class BRAIN {
	public:
		int T_biologico;
		int T_cultural;
		int T_emocional;

		BRAIN();
		void start();
		~BRAIN(); // destructor

		string Leer_Data(int);
		void Extraer(string, string &, string &);
		void Extraer_valores(string, string, string &, string &);
		int Aleatorio();
		string decToBinary(int);
};
#endif

