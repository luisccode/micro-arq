#include <iostream>
#include <functions.h>
#include <Brain.h>
#include <random>
#include <unistd.h>

void decrease_thermometers(BRAIN &b){
	sleep(3);
	b.set_Biologic(b.get_Biologic() - 3);
	b.set_Cultural(b.get_Cultural() - 2);
	b.set_Emotional(b.get_Emotional() - 2);
}

int random_number(int a, int b){
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution < mt19937::result_type > dist6(a, b);
	return dist6(rng);
}