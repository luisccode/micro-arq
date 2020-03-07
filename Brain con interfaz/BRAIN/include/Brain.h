#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <Entity.h>
#include <string>
#include <vector>
using namespace std;

class BRAIN{
		private:
		int Biologic;
		int Cultural;
		int Emotional;

		public:
		BRAIN();	//Constructor
		~BRAIN(); //Destructor
		
		//Setters
		void set_Biologic(int);
		void set_Cultural(int);
		void set_Emotional(int);

		//Getters
		int get_Biologic();
		int get_Cultural();
		int get_Emotional();

		void start();
		string read_data(int);
		void extract_address(string, string &, string &);
		void extract_value(string, string, string &, string &);
		string dec_to_binary(int);
		void select_place(vector<Entity> &);
		void move(vector<Entity> &, int);
};

#endif