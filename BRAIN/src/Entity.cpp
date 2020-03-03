#include <iostream>
#include <Entity.h>
using namespace std;

Entity::Entity(){
    visited = false;
}

Entity::Entity(int ib,int ic, int ie, string place, int x, int y){
    inc_Biologic = ib;
    inc_Cultural = ic;
    inc_Emotional = ie;
    this->place = place;
    this->x = x;
    this->y = y;
}

int Entity::get_inc_Biologic(){
    return inc_Biologic;
}

int Entity::get_inc_Cultural(){
    return inc_Cultural;
}

int Entity::get_inc_Emotional(){
    return inc_Emotional;
}

int Entity::get_x(){
    return x;
}

int Entity::get_y(){
    return y;
}

string Entity::get_place(){
    return place;
}

bool Entity::get_visited(){
    return visited;
}

void Entity::set_visited(bool visited){
    this->visited = visited;
}

void Entity::set_place(string name){
    place = name;
}