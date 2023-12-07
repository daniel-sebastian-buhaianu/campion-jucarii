#include <fstream>
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
bool esteSolutie(int* a)
{
    // verifica daca exista un subsir crescator
    // de lungime K in vectorul a
    int lgmax[N], nrmin[N];
    lgmax[0] = 1, nrmin[0] = a[0];
    for (int i = 1; i < N; i++)
    {
        if (a[i] > nrmin[i-1])
        {
            lgmax[i] = lgmax[i-1]+1;
            nrmin[i] = a[i];
        }
        else
        {
            int j;
            for (j = i-1; j >= 0 && nrmin[j] > a[i]; j--);
            if (j >= 0 && lgmax[j]+1 >= lgmax[i-1])
            {
                lgmax[i] = lgmax[j]+1;
                nrmin[i] = a[i];
            }
            else
            {
                lgmax[i] = lgmax[i-1];
                nrmin[i] = nrmin[i-1];
            }
        }
    }
    return lgmax[N-1] >= K;
}
void afiseazaSolutie(int* a)
{
    ofstream g("jucarii.out");
    for (int i = 0; i < N; i++)
        g << a[i] << ' ';
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
