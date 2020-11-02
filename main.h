#define MAX 50

// Definujeme strukturu hrana typu Hrana
// int source - promenna pro pocatecni bod hrany
// int dest - promenna pro koncovy bod hrany
// int weight - promenna pro vahu hrany
struct Hrana {
	int source, dest, weigth;
} hrana;

// Definujeme struktury seznam a vysledek typu SeznamHran
// Struktura se sklada z poctu hran a pole informace o hranach
// Seznam - mnozina obsahujici vsechny hrany grafu
// Vysledek - mnozina stromu, kde kazdy uzel je samostatnym podstromem
struct SeznamHran {
	hrana info[MAX];
	int pocet;
} seznam, vysledek;

// Definujme dvojrozmerne pole Graf pro nasi matici a promennu int pocet pro pocet vrcholu
char Graf[MAX][MAX];
int pocet;

void readMatrix();
void sort();
void KruskalAlgorithm();
void printResult();
void spojPodsromy();