#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"


/**
* Funkce readMatrix na��t� graf, ze zadan�ho souboru.
* Soubor je vybr�n podle zadan�ho n�zvu (i s koncovkou) a jsou hled�ny v slo�ce `input/`. 
* Dok�e otev��t .csv i .txt soubory. Jednotliv� polo�ky jsou odd�leny ',' 
* a jednotliv� ��dky jsou denodu�e odd�leny '\n' tedy enterem vtext editoru.
* 
* Matice ze soubory je na�tena do dvourozm�rn�ho pole `Graf[MAX][MAX]`,
* kde za pomoc� matice sousednosti (adjacency matrix) bude nad�le interpretov�na jako Graf.
* Jednotliv� hodnoty jsou typu Integer.
*/
void readMatrix () {
	// TODO - v dokumentace bychom meli pridat nejaky koncovy automat na zpracovani vstupu
	// Vstupni vrcholy muzou byt bud ocislovane, bud pojmenovane a to male nebo velka pismenka
	// asi bych tady jeste pridala neco jako "nebo zadejte -h nebo -help pro vice info" a dat ukazkovy vstup

	char buffer[MAX];
	char* record, *line;
	char file_name[20];
	char path[32];

	printf("Zadej nazev souboru: 		(ukazkova matice: example01.csv)\n");
	scanf("%s", file_name);
	strcpy(path, "input/");
	strcat(path, file_name);

	FILE* in = fopen(path, "r");				//Otev�e soubor, jinak ukon�� program s 1.
	if (in == NULL)
	{
		perror("\n file opening failed");
		exit(1);
	}

	printf("\n\nNactena matice:\n\n");
	for (int i = 0; (line = fgets(buffer, sizeof(buffer), in)) != NULL; i++)
	{
		record = strtok(line, ",");
		for (int j = 0; record != NULL; j++)
		{
			Graf[i][j] = atoi(record);			//Nahraje danou polo�ku jako Integer.
			record = strtok(NULL, ",");
			printf("%d \t", Graf[i][j]);
		}
		printf("\n");

		pocet = i + 1;						//Nastav� po�et vrchol�. (globaln� prom�n�)
	}
	printf("\n\n");
}

/**
* Funkce sort se�ad� seznam hran.
* Je pou�it Bubble-sort jak �ad�c� algoritmus.
* �azen� je prov�d�no nad polem info v glob�ln� prom�n� seznam. (seznam.info)
* 
* V�stupen funcke je tedy se�azen� posloupnost hran podle vah v poly seznam.info, od nejmen�� na prvn�m indexu 
* a� po nevy��� na indexu seznam.pocet, kde maxim�ln� velikost je MAX, tedy index MAX-1.
*/
void sort() {
	for (int i = 0; i < seznam.pocet; i++)
	{
		hrana temp = seznam.info[i];
		int j = i - 1;
		while (j >= 0 && temp.weight < seznam.info[j].weight)
		{
			seznam.info[j + 1] = seznam.info[j];
			j--;
		}
		seznam.info[j + 1] = temp;
	}
}

void spojPodstromy(int vrcholy[], int val1, int val2) {
	// v poli vrcholu prepiseme hodnotu koncoveho bodu za pocatecni 
	int i;

	for (i = 0; i < pocet; i++) {
		if (vrcholy[i] == val2) {
			vrcholy[i] = val1;
		}
	}
}

void KruskalAlgorithm () {
	// Ziskame hrany grafu z matici 
	int i, j; // definujeme pomocne promenne
	// Nastavime pocet hran v seznamu na nulu
	seznam.pocet = 0;
	// Projdeme matici a vyplnime seznam 
	for (i = 1; i < pocet; i++) {
		for (j = 0; j < i; j++) {
			// Protoze chceme vahu hrany jako cislo a ne znak, pouzijeme funkci atoi() coz prevede string do integeru
			if (Graf[i][j] != 0) {
				seznam.info[seznam.pocet].source = i;
				seznam.info[seznam.pocet].dest = j;
				seznam.info[seznam.pocet].weight = Graf[i][j];
				seznam.pocet++;
			}
		}
	}
	for (i = 0; i < seznam.pocet; i++) {
		printf("Hrana: %d - %d: %d\n", seznam.info[i].source, seznam.info[i].dest, seznam.info[i].weight);
	}

	// sortujeme hrany podle jejich vahy
	sort();
	for (i = 0; i < seznam.pocet; i++) {
		printf("Serazena hrana: %d - %d: %d\n", seznam.info[i].source, seznam.info[i].dest, seznam.info[i].weight);
	}
	// Definujeme pole znaku pro vrcholy
	int vrcholy[MAX];
	// Definujeme pomocne promenne
	char hodnota1, hodnota2;

	// Nastavime hodnotu poctu hran vysledneho stromu na 0
	vysledek.pocet = 0;

	// Protoze mame ve vyslednem strome mit pocet hran o jednu min nez pocet vrcholu 
	// tak do pomocnych promennych hodime hodnoty pocatecniho a koncoveho bodu prvni hrany v sortu 
	// porovname hodnoty 
	// pokud jsou stejne tak hranu zahodime
	// pokud ne tak danou hranu zaradime do vysledneho stromu a spojime podstromy 
	for (i = 0; i < seznam.pocet; i++) {
		vrcholy[i] = i;
	}

	for (i = 0; i < seznam.pocet; i++) {
		hodnota1 = vrcholy[seznam.info[i].source];
		hodnota2 = vrcholy[seznam.info[i].dest];

		if (hodnota1 != hodnota2) {
			vysledek.info[vysledek.pocet] = seznam.info[i];
			weight += seznam.info[i].weight;
			vysledek.pocet = vysledek.pocet + 1;
			spojPodstromy(vrcholy, hodnota1, hodnota2);
		}
		// jinak zahodime hranu 
	}
	
}

void printResult () {
	// TODO
	// vypiseme vysledek
	// asi nejak "source - destination = weight" + celkova vaha
	int i;
	printf("Minimalni kostra grafu: %d\n", weight);
	for (i = 0; i < vysledek.pocet; i++) {
		printf("Vysledni hrana: %d - %d: %d\n", vysledek.info[i].source, vysledek.info[i].dest, vysledek.info[i].weight);
	}
}

int main() {

	readMatrix();

	KruskalAlgorithm();

	printResult();
}
