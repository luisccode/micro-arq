#include <iostream>
#include <Brain.h>
#include <functions.h>
#include <string>
#include <fstream>
#include <random>
#include <macro.h>
using namespace std;

BRAIN::BRAIN(){
	Biologic = 6;
	Cultural = 5;
	Emotional = 4;
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
	int i = random_number(0, 6);
	//Para aumentar el termómetro Biológico
	if(is_the_first_smaller(Biologic, Cultural, Emotional, 1))
		move(entities, i);
	//Para aumentar el termómetro Cultural
	else if(is_the_first_smaller(Cultural, Biologic, Emotional, 2))
		move(entities, (i==21)? 2 : i+7); //Si se escoge a la Casa, no se le suma 7
	//Para aumentar el termómetro Emocional
	else if(is_the_first_smaller(Emotional, Biologic, Cultural, 3))
		move(entities, (i==21)? 2 : i+14);	//Si se escoge la casa, no se le suma 14
	
	else if(Biologic >= 7 and Cultural >= 6 and Emotional >= 6){
		int v = random_number(0, 2);
		move(entities, v+22);
		if(entities[v+22].get_place() == "--------")
			discover_place(entities, v+22);	//Si el lugar no se conoce, se va y se conoce xd
	}
}

bool is_the_first_smaller(int a, int b, int c, int opt){
	if(opt == 1)	//BIOLOGICO
		return(a <= b and a <= c) ? true : false;
	else if(opt == 2)	//CULTURAL
		return(a < b and a < c) ? true : false;
	else	//EMOCIONAL
		return(a < b and a <= c) ? true : false;
}

void BRAIN::move(vector<Entity> &entities, int i){
	int bio = entities[i].get_inc_Biologic();
	int cul = entities[i].get_inc_Cultural();
	int emo = entities[i].get_inc_Emotional();
	//ESTO SE TIENE QUE HACER CON EL MICRO
	Biologic += bio;
	Cultural += cul;
	Emotional += emo;

	if(Biologic > 10) Biologic = 10;
	if(Cultural > 10) Cultural = 10;
	if(Emotional > 10) Emotional = 10;

	for(int x = 0; x < entities.size(); x++)
		entities[x].set_visited(false);
	entities[i].set_visited(true);

	cout << "\nFUI A: " << entities[i].get_place() << "\n";
}