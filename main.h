#define MAX 50

/* Definována struktura hrana (Edge). Její vlastnosti jsou
** čísla zdrojového (source), koncového (destination) uzlu
** a váha (weight) jejich spojení. */
typedef struct Edge {
	int source, destination, weight;
} Edge;

/* Definována struktura graf (Graph), je množinou všech hran
** (arrOfEdges) a udržuje informaci o jejich počtu (numberOfEdges). */
typedef struct Graph {
	Edge arrOfEdges[MAX];
	int numberOfEdges;
} Graph;

/* Definováno dvojrozměrné pole Matrix do něhož vstupuje matice 
** definující graf. Dále definujeme proměnnou která udržuje 
** informace o počtu uzlů (numberOfNodes) a jak zadaný, tak 
** výsledný graf. */
int Matrix[MAX][MAX];
int numberOfNodes;
Graph graph;
Graph result;