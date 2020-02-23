#include <iostream>
#include <Brain.h>
#include <string>
#include <fstream>
#include <random>
#include <macro.h>
using namespace std;

BRAIN::BRAIN(){
	T_biologico = 5;
	T_cultural = 5;
	T_emocional = 5;
}

BRAIN::~BRAIN(){}

void BRAIN::start(){}

string BRAIN::Leer_Data(int L) {
	int i = 1;
	string aux_cod;
	//string buffer;

	ifstream archivo;
	archivo.open("texto.txt",ios::in);
	
	if(not archivo)
		throw invalid_argument("No se puede abrir el archivo");

	while(not archivo.eof()){
		getline(archivo, aux_cod);
		if(i == L){
			//cout << endl << aux_cod<<"\n";
			break;
		}
		i++;
	}
	//strcpy(buffer,aux_cod.c_str());
	return aux_cod;
}

void BRAIN::Extraer(string instruccion_decodificar, string &dir_1, string &dir_2){
	dir_1 = instruccion_decodificar.substr(8, 4);
	dir_2 = instruccion_decodificar.substr(4, 4);
}

void BRAIN::Extraer_valores(string dir_1, string dir_2, string &valor_1, string &valor_2){
	string aux, dir_aux;
	ifstream archivo;
	archivo.open("Register_file.txt", ios::in);

	if(not archivo)
		throw invalid_argument("no se puede abrir el archivo");
	
	while(not archivo.eof()){
		getline(archivo, aux);
		dir_aux = aux.substr(4, 4);

		if(dir_1 == dir_aux)
			valor_1 = aux.substr(0, 4);
		else if(dir_2 == dir_aux)
			valor_2 = aux.substr(0, 4);
	}
	//cout << "VALOR 1: " << valor_1 << "\n";
	//cout << "VALOR 2: " << valor_2 << "\n";
}
int BRAIN::Aleatorio(){
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution < mt19937::result_type > dist6(1, 10);
	return dist6(rng);
}

string BRAIN::decToBinary(int n) { 
    int aux[nBits]; 
    string binaryNum;
    int i = 0; 
    while (n > 0) { 
        aux[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    for (int j = i - 1; j >= 0; j--)
        binaryNum.push_back(aux[j] + '0');
    return binaryNum;
} 