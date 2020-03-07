#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Brain.h>
#include <Entity.h>

void decrease_thermometers(BRAIN &);
int random_number(int, int);
bool is_the_first_smaller(int, int, int, int);
void discover_place(vector<Entity> &, int i);

#endif