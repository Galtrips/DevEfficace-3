#pragma once
#include <string>
#include <iomanip>
#include <chrono>
#include <ctime>
using namespace std;

class Complexe
{
private:
	int nb_Boucles;
	int nb_Operation_Unitaire;
	int nb_Appel_Fonctions;
	int nb_Tests;
	clock_t temps;
public:
	Complexe();
	int sommeOperation();
	void addBoucle();
	void addOperation();
	void addFonction();
	void addTest();
	void addTime();
	void exportToCsv(string name);
};

