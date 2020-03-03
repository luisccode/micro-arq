#include <iostream>
#include <Brain.h>
#include <functions.h>
#include <string>
#include <fstream>
#include <random>
#include <macro.h>
using namespace std;

bool is_the_first_smaller(int, int, int);

BRAIN::BRAIN(){
	Biologic = 7;
	Cultural = 6;
	Emotional = 5;
}

BRAIN::~BRAIN(){}

void BRAIN::set_Biologic(int Biologic){
	this->Biologic = Biologic;
}

void BRAIN::set_Cultural(int Cultural){
	this->Cultural = Cultural;
}

void BRAIN::set_Emotional(int Emotional){
	this->Emotional = Emotional;
}

int BRAIN::get_Biologic(){
	return Biologic;
}

int BRAIN::get_Cultural(){
	return Cultural;
}

int BRAIN::get_Emotional(){
	return Emotional;
}

void BRAIN::start(){}

string BRAIN::read_data(int L) {
	int i = 1;
	string line;
	//string buffer;

	ifstream file;
	file.open("texto.txt",ios::in);
	
	if(not file.is_open())
		throw invalid_argument("No se puede abrir el archivo");

	while(not file.eof()){
		getline(file, line);
		if(i == L){
			//cout << endl << line<<"\n";
			break;
		}
		i++;
	}
	//strcpy(buffer,line.c_str());
	return line;
}

void BRAIN::extract_address(string instruction_to_decode, string &address_1, string &address_2){
	address_1 = instruction_to_decode.substr(8, 4);
	address_2 = instruction_to_decode.substr(4, 4);
}

void BRAIN::extract_value(string address_1, string address_2, string &value_1, string &value_2){
	string aux, aux_address;
	ifstream file;
	file.open("Register_file.txt", ios::in);

	if(not file.is_open())
		throw invalid_argument("No se puede abrir el archivo");
	
	while(not file.eof()){
		getline(file, aux);
		aux_address = aux.substr(4, 4);

		if(address_1 == aux_address)
			value_1 = aux.substr(0, 4);
		else if(address_2 == aux_address)
			value_2 = aux.substr(0, 4);
	}
	//cout << "VALOR 1: " << value_1 << "\n";
	//cout << "VALOR 2: " << value_2 << "\n";
}

string BRAIN::dec_to_binary(int n){ 
    int aux[nBits]; 
    string binary_num;
    int i = 0; 
    while (n > 0){ 
        aux[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    for (int j = i - 1; j >= 0; j--)
        binary_num.push_back(aux[j] + '0');
    return binary_num;
}

void BRAIN::select_place(vector<Entity> &entities){
	int i = random_number(0, 2);
	//Para aumentar el termómetro Biológico
	if(is_the_first_smaller(Biologic, Cultural, Emotional)){
		move(entities, i);
	}
	//Para aumentar el termómetro Cultural
	else if(is_the_first_smaller(Cultural, Biologic, Emotional)){
		move(entities, (i==2)? 2 : i+3); //Si se escoge a la Casa, no se le suma 3
	}
	//Para aumentar el termómetro Emocional
	else if(is_the_first_smaller(Emotional, Biologic, Cultural)){
		move(entities, (i==2)? 2 : i+6);	//Si se escoge la casa, no se le suma 6
	}
}

bool is_the_first_smaller(int a, int b, int c){
	return(a < b and a < c) ? true : false;
}

void BRAIN::move(vector<Entity> &entities, int i){
	int bio = entities[i].get_inc_Biologic();
	int cul = entities[i].get_inc_Cultural();
	int emo = entities[i].get_inc_Emotional();
	//ESTO SE TIENE QUE HACER CON EL MICRO
	Biologic += bio;
	Cultural += cul;
	Emotional += emo;

	for(int x = 0; x < entities.size(); x++)
		entities[x].set_visited(false);
	entities[i].set_visited(true);
	cout << "\nFUI A: " << entities[i].get_place() << "\n";
}