#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <main.h>


// Funkce na nacteni matrice ze vstupu
void readMatrix () {
	// TODO - v dokumentace bychom meli pridat nejaky koncovy automat na zpracovani vstupu
	// Vstupni vrcholy muzou byt bud ocislovane, bud pojmenovane a to male nebo velka pismenka
	// asi bych tady jeste pridala neco jako "nebo zadejte -h nebo -help pro vice info" a dat ukazkovy vstup
	printf("Zadejte graf pomoci matice souvislosti: \n");
	// TODO
	// ze vstupu dostavame matice jako string a musime ji nacist do dvojrozmerneho pole Graf[][]
}


void sort() {
	// TODO
	// pruchod seznamem a porovnani vahy sousedu -> quick sort 
}

void spojPodstromy() {
	// tuto cast za chvyli doplnim 
}

void KruskalAlgorithm () {
	// Ziskame hrany grafu z matici 
	int i, j; // definujeme pomocne promenne
	// Nastavime pocet hran v seznamu na nulu
	seznam.pocet = 0;
	// Projdeme matici a vyplnime seznam 
	for (i = 2; i < pocet+1; i++) {
		for (j = 1; j < i; j++) {
			// Protoze chceme vahu hrany jako cislo a ne znak, pouzijeme funkci atoi() coz prevede string do integeru
			if (atoi(Graf[i][j]) != 0) {
				seznam.info[seznam.pocet].source = i;
				seznam.info[seznam.pocet].destination = j;
				seznam.info[seznam.pocet].weight = atoi(Graf[i][j]);
				seznam.pocet++;
			}
		}
	}

	// sortujeme hrany podle jejich vahy
	sort();


	//za chvyli tuto cast doplnim 

		// Definujeme pole znaku pro vrcholy
		//char vrcholy[MAX];
		// Definujeme pomocne promenne
		//char hodnota1, hodnota2;

		// Nastavime hodnotu poctu hran vysledneho stromu na 0
		//vysledek.pocet = 0;
	//
}

void printResult () {
	// TODO
	// vypiseme vysledek
	// asi nejak "source - destination = weight" + celkova vaha
}

int main() {

	printf("Zadejte pocet vrcholu: ");
	scanf("%d", &pocet);

	readMatrix();

	KruskalAlgorithm();

	printResult();
}