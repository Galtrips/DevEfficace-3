#include "complexe.h"
#include <ostream>
#include <fstream>
#include <iostream>

using namespace std;

Complexe::Complexe() {
	this->nb_Appel_Fonctions = 0;
	this->nb_Boucles = 0;
	this->nb_Operation_Unitaire = 0;
	this->nb_Tests = 0;
	this->temps = std::clock();
}

void Complexe::exportToCsv(string name) {
	
	ofstream file("data.csv", ios::app);
	if (file.is_open()) {
		file << name + ";";
		file << to_string(nb_Appel_Fonctions) + ";";
		file << to_string(nb_Boucles) + ";";
		file << to_string(nb_Operation_Unitaire) + ";";
		file << to_string(nb_Tests) + ";";
		file << to_string(float(temps / CLOCKS_PER_SEC)) + ";";
		file << to_string(this->sommeOperation()) + ";";
		file << "\n";
	}
	file.close();
}

int Complexe::sommeOperation() {
	return nb_Appel_Fonctions + nb_Boucles + nb_Operation_Unitaire + nb_Tests;
}

void Complexe::addBoucle() {
	this->nb_Boucles++;
}

void Complexe::addOperation() {
	this->nb_Operation_Unitaire++;
}

void Complexe::addFonction() {
	this->nb_Appel_Fonctions++;
}

void Complexe::addTest() {
	this->nb_Tests++;
}

void Complexe::addTime() {
	this->temps = 1000.0 * (clock() - this->temps);
	cout << this->temps << endl;
}