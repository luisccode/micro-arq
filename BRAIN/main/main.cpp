#include <iostream>
#include <Brain.h>
#include <Entity.h>
#include <functions.h>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

int main(){
	BRAIN brain = BRAIN();
	vector <Entity> entities;
	string instruction_to_decode;
	string address_1, address_2, value_1, value_2;
	int L = 3;
	
	Entity e00(5, 2, 1, "Restaurante italiano", 0, 0);  entities.push_back(e00);
	Entity e03(5, 2, 4, "Restaurant mexicano", 0, 3);entities.push_back(e03);
	Entity e13(5, 2, 1, "Hospital", 1, 3); entities.push_back(e13);
	Entity e21(4, 1, 3, "Heladeria", 2, 1); entities.push_back(e21);
	Entity e30(5, 1, 2, "Gimnasio", 3, 0); entities.push_back(e30);
	Entity e33(5, 3, 2, "Restaurante chino", 3, 3); entities.push_back(e33);
	Entity e41(4, 2, 1, "Cafe", 4, 1); entities.push_back(e41);
	
	Entity e01(2, 5, 2, "Museo", 0, 1); entities.push_back(e01);
	Entity e02(1, 4, 1, "Acuario", 0, 2);  entities.push_back(e02);
	Entity e04(2, 5, 1, "Universidad", 0, 4); entities.push_back(e04);
	Entity e44(1, 4, 3, "Zoologico", 4, 4); entities.push_back(e44);
	Entity e42(2, 4, 1, "Biblioteca", 4, 2); entities.push_back(e42);
	Entity e24(1, 4, 2, "Trabajo", 2, 4); entities.push_back(e24);
	Entity e31(1, 4, 3, "Supermercado", 3, 1); entities.push_back(e31);
	
	Entity e10(2, 2, 4, "Mall", 1, 0); entities.push_back(e10);
	Entity e11(1, 1, 4, "Barberia", 1, 1); entities.push_back(e11);
	Entity e23(2, 2, 5, "Cine", 2, 3); entities.push_back(e23);
	Entity e32(1, 1, 4, "Tienda de ropa", 3, 2); entities.push_back(e32);
	Entity e34(4, 1, 5, "Casa de novia", 3, 4); entities.push_back(e34);
	Entity e40(1, 2, 4, "Casino", 4, 0); entities.push_back(e40);
	Entity e43(2, 3, 4, "Bar", 4, 3); entities.push_back(e43);
	
	Entity e22(3, 3, 3, "Casa", 2, 2); entities.push_back(e22);
	Entity e12(0, 0, 0, "--------", 1, 2); entities.push_back(e12); //Desconocida totalmente
	Entity e14(1, 1, 2, "Piscina", 1, 4); entities.push_back(e14); //Desconocida por conocer
	Entity e20(1, 1, 1, "Ferreteria", 2, 0); entities.push_back(e20); //Desconocida por conocer

	cout << "\nBiologico: " << brain.get_Biologic() << "\n";
	cout << "Cultural: " << brain.get_Cultural() << "\n";
	
	cout << "Emocional: " << brain.get_Emotional() << "\n";
	while(true){
		decrease_thermometers(brain);
		cout << "\nDISMINUYENDO TERMÓMETROS:\n";
		cout << "Biologico: " << brain.get_Biologic() << "\n";
		cout << "Cultural: " << brain.get_Cultural() << "\n";
		cout << "Emocional: " << brain.get_Emotional() << "\n";

		instruction_to_decode = brain.read_data(L);
		//cout << "\n" << instruction_to_decode << "\n";

		brain.extract_address(instruction_to_decode, address_1, address_2);
		//cout << "DIR 1: " << address_1 << "\n";
		//cout << "DIR 2: " << address_2 << "\n";
		brain.extract_value(address_1, address_2, value_1, value_2);
		brain.select_place(entities);
		cout << "Biologico: " << brain.get_Biologic() << "\n";
		cout << "Cultural: " << brain.get_Cultural() << "\n";
		cout << "Emocional: " << brain.get_Emotional() << "\n";
	}
	return 0;
}