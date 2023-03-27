#ifndef VARIABLES_INCLUDED
#define VARIABLES_INCLUDED

#define MAX     100

unsigned long int nodes;
int maxDepht;
int sized;
int solSize;
int solFound;

char Goal[2*('z'-'a'+1)+1];//Toma en cuenta que la meta es todo el abecedario de minusculas y mayusculas
int actSol[MAX];
int bestSol[MAX];
int bestSolSize;

void Voltear(char *, int);
void disorder(char *, int);
void BPI(char *, int);

#endif // VARIABLES_INCLUDED
