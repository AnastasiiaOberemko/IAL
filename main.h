#define MAX 50

// Definujeme strukturu hrana typu Hrana
// int source - promenna pro pocatecni bod hrany
// int dest - promenna pro koncovy bod hrany
// int weight - promenna pro vahu hrany
typedef struct Hrana {
	int source, dest, weight;
} hrana;

// Definujeme struktury seznam a vysledek typu SeznamHran
// Struktura se sklada z poctu hran a pole informace o hranach
// Seznam - mnozina obsahujici vsechny hrany grafu
// Vysledek - mnozina stromu, kde kazdy uzel je samostatnym podstromem
typedef struct SeznamHran {
	hrana info[MAX];
	int pocet;
};
struct SeznamHran seznam, vysledek;

// Definujme dvojrozmerne pole Graf pro nasi matici, promennu int pocet pro pocet vrcholu a promennu weight pro vahu minimalni kostry grafu
int Graf[MAX][MAX];
int pocet;
int weight;

void readMatrix();
void sort();
void KruskalAlgorithm();
void printResult();
void spojPodsromy(char vrcholy[], int val1, int val2);