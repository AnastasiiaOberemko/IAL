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


void sort() {
	// TODO
	// pruchod seznamem a porovnani vahy sousedu -> quick sort 
}

void spojPodstromy(char vrcholy[], int val1, int val2) {
	// v poli vrcholu prepiseme hodnotu koncoveho bodu za pocatecni 
}

void KruskalAlgorithm () {
	// Ziskame hrany grafu z matici 
	int i, j; // definujeme pomocne promenne
	// Nastavime pocet hran v seznamu na nulu
	seznam.pocet = 0;
	// Projdeme matici a vyplnime seznam 
	for (i = 0; i < pocet; i++) {
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

	// Definujeme pole znaku pro vrcholy
	char vrcholy[MAX];
	// Definujeme pomocne promenne
	char hodnota1, hodnota2;

	// Nastavime hodnotu poctu hran vysledneho stromu na 0
	vysledek.pocet = 0;

	// TODO 
	// Protoze mame ve vyslednem strome mit pocet hran o jednu min nez pocet vrcholu 
	// tak do pomocnych promennych hodime hodnoty pocatecniho a koncoveho bodu prvni hrany v sortu 
	// porovname hodnoty 
	// pokud jsou stejne tak hranu zahodime
	// pokud ne tak danou hranu zaradime do vysledneho stromu a spojime podstromy 
	
}

void printResult () {
	// TODO
	// vypiseme vysledek
	// asi nejak "source - destination = weight" + celkova vaha
}

int main() {

	readMatrix();

	KruskalAlgorithm();

	printResult();
}
