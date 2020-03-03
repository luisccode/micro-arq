#include <iostream>
#include <Brain.h>
#include <Entity.h>
#include <functions.h>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

struct Time{
	chrono::system_clock::time_point start;
	
	Time(){
		start = chrono::system_clock::now();
	}
	~Time(){
		auto end = chrono::system_clock::now();
		chrono::duration < float > duration = end - start;
		cout << duration.count() << " segundos\n";
	}
};

int main(){
	Time t;
	BRAIN brain = BRAIN();
	vector <Entity> entities;
	string instruction_to_decode;
	string address_1, address_2, value_1, value_2;
	int L = 3;
	
	Entity e00(4, 1, 2, "Restaurante chino", 0, 0);  entities.push_back(e00);
	Entity e01(4, 2, 1, "Restaurante italiano", 0, 1);  entities.push_back(e01);
	Entity e02(3, 2, 3, "Casa", 1, 2);  entities.push_back(e02);
	Entity e10(1, 4, 2, "Universidad", 1, 0);  entities.push_back(e10);
	Entity e11(1, 4, 2, "Museo", 1, 1);  entities.push_back(e11);
	Entity e12(1, 2, 4, "Tienda de ropa", 1, 2);  entities.push_back(e12);
	Entity e20(1, 2, 4, "Parque", 2, 0);  entities.push_back(e20);
	Entity e21(1, 1, 1, "-----------------", 2, 1);  entities.push_back(e21); // desconocido por conocer
	Entity e22(0, 0, 0, "-----------------", 2, 2);  entities.push_back(e22); //desconocido

	for(int i = 0; i < 5; i++){
		cout << "\nBiologico: " << brain.get_Biologic() << "\n";
		cout << "Cultural: " << brain.get_Cultural() << "\n";
		cout << "Emocional: " << brain.get_Emotional() << "\n";

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