#include <iostream>
#include <Brain.h>
#include <Entidad.h>
#include <vector>
#include <string>
#include <chrono>
#include <unistd.h>
using namespace std;

struct Tiempo{
	chrono::system_clock::time_point inicio;
	
	Tiempo(){
		inicio = chrono::system_clock::now();
	}
	~Tiempo(){
		auto fin = chrono::system_clock::now();
		chrono::duration < float > duracion = fin - inicio;
		cout << duracion.count() << " segundos\n";
	}
};

void Bajar_Termometros(BRAIN &);

int main(){
	Tiempo t;
	vector < Entidad > entidades;
	string instruccion_decodificar;
	string dir_1, dir_2, valor_1, valor_2;
	int L = 3;

	Entidad e00(3, 3, 5, "Restaurante chino");  entidades.push_back(e00);
	Entidad e01(0, 0, 0, "-----------------");  entidades.push_back(e01); //desconocido
	Entidad e02(5, 4, 2, "Universidad");  entidades.push_back(e02);
	Entidad e10(3, 4, 4, "Casa");  entidades.push_back(e10);
	Entidad e11(4, 4, 2, "Tienda de ropa");  entidades.push_back(e11);
	Entidad e12(5, 3, 2, "Museo");  entidades.push_back(e12);
	Entidad e20(1, 1, 1, "-----------------");  entidades.push_back(e20); // desconocido por conocer
	Entidad e21(3, 3, 3, "Banco");  entidades.push_back(e21);
	Entidad e22(3, 4, 6, "Restaurante italiano");  entidades.push_back(e22);

	BRAIN cerebro = BRAIN();
	cout << "Biologico: " << cerebro.T_biologico << "\n";
	Bajar_Termometros(cerebro);
	cout << "Biologico: " << cerebro.T_biologico << "\n";
	
	instruccion_decodificar = cerebro.Leer_Data(L);
	//cout << "\n" << instruccion_decodificar << "\n";

	cerebro.Extraer(instruccion_decodificar, dir_1, dir_2);
	//cout << "DIR 1: " << dir_1 << "\n";
	//cout << "DIR 2: " << dir_2 << "\n";
	cerebro.Extraer_valores(dir_1, dir_2, valor_1, valor_2);
	return 0;
}

void Bajar_Termometros(BRAIN &c){
	sleep(3);
	c.T_biologico -= 2;
	c.T_cultural -= 1;
	c.T_emocional -= 1;
}