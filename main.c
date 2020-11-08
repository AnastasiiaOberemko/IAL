#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"


/**
* Funkce readMatrix naèítá graf, ze zadaného souboru.
* Soubor je vybrán podle zadaného názvu (i s koncovkou) a jsou hledány v složce `input/`. 
* Dokáže otevøít .csv i .txt soubory. Jednotlivé položky jsou oddìleny ',' 
* a jednotlivé øádky jsou denoduše oddìleny '\n' tedy enterem vtext editoru.
* 
* Matice ze soubory je naètena do dvourozmìrného pole `Graf[MAX][MAX]`,
* kde za pomocí matice sousednosti (adjacency matrix) bude nadále interpretována jako Graf.
* Jednotlivé hodnoty jsou typu Integer.
*/
void readMatrix () {
	// TODO - v dokumentace bychom meli pridat nejaky koncovy automat na zpracovani vstupu
	// Vstupni vrcholy muzou byt bud ocislovane, bud pojmenovane a to male nebo velka pismenka
	// asi bych tady jeste pridala neco jako "nebo zadejte -h nebo -help pro vice info" a dat ukazkovy vstup

	char buffer[MAX];
	char* record, *line;
	char file_name[20];
	char path[32];

	printf("Zadej nazev souboru: \n");
	scanf("%s", file_name);
	strcpy(path, "input/");
	strcat(path, file_name);

	FILE* in = fopen(path, "r");				//Otevøe soubor, jinak ukonèí program s 1.
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
			Graf[i][j] = atoi(record);			//Nahraje danou položku jako Integer.
			record = strtok(NULL, ",");
			printf("%d \t", Graf[i][j]);
		}
		printf("\n");
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
	for (i = 2; i < pocet+1; i++) {
		for (j = 1; j < i; j++) {
			// Protoze chceme vahu hrany jako cislo a ne znak, pouzijeme funkci atoi() coz prevede string do integeru
			if (atoi(Graf[i][j]) != 0) {
				seznam.info[seznam.pocet].source = i;
				seznam.info[seznam.pocet].dest = j;
				seznam.info[seznam.pocet].weight = atoi(Graf[i][j]);
				seznam.pocet++;
			}
		}
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

	//printf("Zadejte pocet vrcholu: ");
	//scanf("%d", &pocet);

	readMatrix();

	KruskalAlgorithm();

	printResult();
}
