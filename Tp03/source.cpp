#include <ostream>
#include "complexe.h"

using namespace std;


int* tab1D(int N, Complexe& c) {

	c.addOperation();
	int* tab1D = new int[N];

	c.addBoucle();
	c.addOperation(); // int i = 0
	for (int i = 0; i < N; i++) {
		tab1D[i] = rand() % 1000;
		c.addFonction(); // appel à rand()
		c.addOperation(); // rand() % 1000
		c.addOperation(); // tab1D[i] =
		c.addOperation(); // i++
		c.addTest(); // i<N
	}
	c.addTime();

	return tab1D;
}

int** tab2D(int N, Complexe& c) {

	c.addOperation();
	int** tab2D = new int*[N];

	c.addBoucle();
	c.addOperation(); // int i =0
	for (int i = 0; i < N; i++) {
		tab2D[i] = new int[N];
		c.addOperation(); // i++
		c.addOperation(); // new int[N]
		c.addTest(); // i<N
	}

	c.addBoucle();
	c.addOperation(); // int i =0
	for (int i = 0; i < N; i++) {
		c.addBoucle();
		c.addOperation(); // int j =0
		for (int j = 0; j < N; j++) {
			tab2D[i][j] = rand() % 1000;
			c.addOperation(); // j++
			c.addTest(); // j < N
			c.addFonction(); // appel à rand
			c.addOperation(); // rand() % 1000
			c.addOperation(); //tab2D =
		}
		c.addOperation(); // i++
		c.addTest(); //i<N
	}
	c.addTime();
	return tab2D;
}

int main(int argsv, char* argc) {

	srand(time(NULL));
	int i = 0;
	while (i != 200) {
		Complexe fonc1;
		int x1 = rand() % 1000;
		int* tab1 = tab1D(x1, fonc1);

		Complexe fonc2;
		int** tab2 = tab2D(rand() % x1, fonc2);

		fonc1.exportToCsv("T1D " + to_string(x1));
		fonc2.exportToCsv("T2D " + to_string(x1));
		i++;
	}

	return EXIT_SUCCESS;
}