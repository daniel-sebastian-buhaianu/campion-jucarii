#include <fstream>
#include <iostream>
using namespace std;
int N, K, P, NS;
void citesteDateleDeIntrare();
void genereazaPermutari();
int main()
{
	citesteDateleDeIntrare();
	genereazaPermutari();
	return 0;
}
bool esteSolutie(int* v)
{
	// verifica daca exista un subsir crescator
	// de lungime K in vectorul v
	// TODO	
}
void afiseazaSolutie(int* v)
{
	ofstream g("jucarii.out");
	for (int i = 0; i < N; i++)
		g << v[i] << ' ';
	g.close();
}
void genereazaPermutari()
{
	int a[N], i, j;
	for (i = 0; i < N; i++) a[i] = i+1;
	while (1)
	{
		if (esteSolutie(a))
		{
			NS++;
			if (NS == P)
			{
				afiseazaSolutie(a);
				return;
			}
		}
		for (i = N-1; i > 0 && a[i] < a[i-1]; i--);
		if (i == 0) break;
		for (j = i-1, i = N-1; a[i] < a[j]; i--);
		swap(a[i], a[j]);
		for (i = j+1, j = N-1; i < j; i++, j--)
			swap(a[i], a[j]);
	}
}
void citesteDateleDeIntrare()
{
	ifstream f("jucarii.in");
	f >> N >> K >> P;
	f.close();
}
