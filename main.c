#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"


/* Funkce načítá data ze souboru obsahující matici definující graf.
** Ukázkové soubory jsou umístěny v adresáři /input a lze je načíst
** zadáním celého názvu souboru včetně koncovky (.csv).
*/
void readMatrix() 
{
	char buffer[MAX];
	char* record, *line;
	char file_name[20];
	char path[32];

	/* Výzva k zadání jména souboru. */
	printf("\nInsert file name [example01.csv]: ");
	scanf("%s", file_name);
	
	/* Definice proměnné path a vytvoření celé cesty k soboru. */
	strcpy(path, "input/");
	strcat(path, file_name);

	/* Otevře soubor s matící a ověří. */
	FILE* in = fopen(path, "r");
	/* Pokud došlo k chybě, program tuto skutečnost oznámí uživateli
	** a ukončí se s kodem 1. */
	if (in == NULL)
	{
		perror("\n Error: file opening failed!");
		exit(1);
	}
	/* Vykreslí uživateli načtenou matici a uloží ji do proměnné Matrix.
	** Ta je dvourozměrným polem. */
	printf("\n\nLoaded matrix from file %s\n\n", file_name);
	for (int i = 0; (line = fgets(buffer, sizeof(buffer), in)) != NULL; i++)
	{
		record = strtok(line, ",");
		for (int j = 0; record != NULL; j++)
		{
			/* Do matice jsou ukládána data typu int. Proto je nutné je
			** přetypovat za pomocí funkce atoi(). */
			Matrix[i][j] = atoi(record);
			record = strtok(NULL, ",");
			printf("%d \t", Matrix[i][j]);
		}
		printf("\n");
		/* Inkrementuje počet vrcholů o jedna v každém kroku. */
		numberOfNodes = i + 1;
	}
	printf("\n\n");
}

/* Funkce, která naplní strukturu grafu listem hran a jejich váhami. */
void fillGraph() {
	/* Inicializuje počet hran v grafu na nula. */
	graph.numberOfEdges = 0;
	/* Prochází zadanou matici. */
	for(int i = 1; i < numberOfNodes; i++) {
		for(int j = 0; j < i; j++)
		{
			/* Pokud je nalezena hodnota 0, znamená to nalezení diagonály 
			** v matici a tento krok je přeskočen. */
			if(Matrix[i][j] != 0)
			{
				/* Zde je vytvořena hrana s počátečním uzlem, koncovým
				** uzlem a váhou udávanou v matici Matrix. */
				graph.arrOfEdges[graph.numberOfEdges].source = i;
				graph.arrOfEdges[graph.numberOfEdges].destination = j;
				graph.arrOfEdges[graph.numberOfEdges].weight = Matrix[i][j];
				graph.numberOfEdges++;
			}
		}
	}	
}

/* Funkce, jenž seřadí všechny hrany dle váhy. */
void sort() 
{
	for (int i = 0; i < graph.numberOfEdges; i++)
	{
		Edge temporary = graph.arrOfEdges[i];

		int j = i - 1;
		while (j >= 0 && temporary.weight < graph.arrOfEdges[j].weight)
		{
			graph.arrOfEdges[j + 1] = graph.arrOfEdges[j];
			j--;
		}
		graph.arrOfEdges[j + 1] = temporary;
	}
}

/* Funkce, která nalezne číslo skupiny daného uzlu grafu. */
int find(int groups[], int groupNum) 
{
	return(groups[groupNum]);
}

/* Funkce, jenž najde v poli skupin koncový bod hrany a přiřadí
** jej do stejné skupiny (podstromu) jako počáteční uzel. */
void merge(int groups[],int source,int destination)
{
	for(int i = 0; i < numberOfNodes; i++) {
		if(groups[i] == destination) {
			groups[i] = source;
		}		
	}	
}

/* Funkce zajišťující výpis hran, které náleží minimální kostře
** grafu a celková cena (cost). */
void printResult()
{
	int cost = 0;
	
	printf("\nSource\tDestination\tCost");
	for(int i = 0; i < result.numberOfEdges; i++)
	{
		printf("\n%d\t|\t%d\t|\t%d",result.arrOfEdges[i].source, result.arrOfEdges[i].destination, result.arrOfEdges[i].weight);
		cost=cost+result.arrOfEdges[i].weight;
	}
 
	printf("\n\nCombined cost = %d", cost);
}

/* Funkce tvořící tělo celého algoritmu. */
void kruskalAlgorithm()
{
	readMatrix();
	fillGraph();
	sort();

	/* Inicializuje počet hran ve výsledném grafu na nula. */
	result.numberOfEdges = 0;
	/* Pole onsahující čísla všech uzlů grafu. */
	int groups[MAX];
	/* Inicializace tohoto pole. př. [0,1,2...(numberOfNodes-1)] */
	for(int i = 0; i < numberOfNodes; i++){
		groups[i] = i;
	}
	
	/* Cyklus procházející všechny hrany v grafu. */
	for(int i = 0; i < graph.numberOfEdges; i++)
	{
		/* Najdeme, zda-li koncový, nebo počáteční uzel již náleží
		** nějaké skupině uzlů. (podstromu) */
		int source = find(groups, graph.arrOfEdges[i].source);
		int destination = find(groups, graph.arrOfEdges[i].destination);
		
		/* Pokud nenáleží stejné skupině. (podstromu) */
		if(source != destination)
		{
			/* Je tato hrana zapsána do výsledného grafu (min. kostry),
			** zvýšen počet hran ve výsledném grafu o jedna a připojen
			** počáteční a koncový uzel do jedné skupiny. */
			result.arrOfEdges[result.numberOfEdges] = graph.arrOfEdges[i];
			result.numberOfEdges = result.numberOfEdges + 1;
			merge(groups, source, destination);
		}
	}
	/* Je zavolána funkce pro výpis výsledků. */
	printResult();
}

void printLogo() 
{
	printf("##    ## ########  ##     ##  ######  ##    ##    ###    ##       ####  ######  \n");
	printf("##   ##  ##     ## ##     ## ##    ## ##   ##    ## ##   ##       #### ##    ## \n");
	printf("##  ##   ##     ## ##     ## ##       ##  ##    ##   ##  ##        ##  ##       \n");
	printf("#####    ########  ##     ##  ######  #####    ##     ## ##       ##    ######  \n");
	printf("##  ##   ##   ##   ##     ##       ## ##  ##   ######### ##                  ## \n");
	printf("##   ##  ##    ##  ##     ## ##    ## ##   ##  ##     ## ##            ##    ## \n");
	printf("##    ## ##     ##  #######   ######  ##    ## ##     ## ########       ######  \n");
	printf("\n");
	printf("   ###    ##        ######    #######  ########  #### ########  ##    ##  ##     ## \n");
	printf("  ## ##   ##       ##    ##  ##     ## ##     ##  ##     ##     ##    ##  ###   ### \n");
	printf(" ##   ##  ##       ##        ##     ## ##     ##  ##     ##     ##    ##  #### #### \n");
	printf("##     ## ##       ##   #### ##     ## ########   ##     ##     ########  ## ### ## \n");
	printf("######### ##       ##    ##  ##     ## ##   ##    ##     ##     ##    ##  ##     ## \n");
	printf("##     ## ##       ##    ##  ##     ## ##    ##   ##     ##     ##    ##  ##     ## \n");
	printf("##     ## ########  ######    #######  ##     ## ####    ##     ##    ##  ##     ## \n");
}

int main() 
{
	printLogo();
	kruskalAlgorithm();
	return 0;
}