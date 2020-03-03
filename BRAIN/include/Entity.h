#ifndef ENTITY_H
#define ENTITY_H

#include<iostream>
using namespace std;

class Entity{
    private: 
       	int inc_Biologic;
       	int inc_Cultural;
	   	int inc_Emotional;
        string place;
        int x;
        int y;
        bool visited;
    public:
        Entity();
        Entity(int,int, int, string, int, int);
        //Getters
        int get_inc_Biologic();
        int get_inc_Cultural();
        int get_inc_Emotional();
        int get_x();
        int get_y();
        string get_place();
        //Setters
        void set_visited(bool);
};

#endif
