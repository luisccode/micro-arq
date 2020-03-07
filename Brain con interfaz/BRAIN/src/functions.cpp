#include <iostream>
#include <functions.h>
#include <random>
#include <unistd.h>
#include <string>
using namespace std;

void decrease_thermometers(BRAIN &b){
	sleep(5);
	b.set_Biologic(b.get_Biologic() - 4);
	b.set_Cultural(b.get_Cultural() - 2);
	b.set_Emotional(b.get_Emotional() - 3);

	if(b.get_Biologic() <= 0) b.set_Biologic(1);
	if(b.get_Cultural() <= 0) b.set_Cultural(1);
	if(b.get_Emotional() <= 0) b.set_Emotional(1);

}

int random_number(int a, int b){
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution < mt19937::result_type > dist6(a, b);
	return dist6(rng);
}

void discover_place(vector<Entity> &entities, int i){
	int n = random_number(0, 3);
	string names[3] = {"Joyeria", "Estadio", "Spa"};
	entities[i].set_place(names[n]);
}