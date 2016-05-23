#include <iostream>
#include <fstream>

using namespace std;

int noduri, muchii;
int a[10][10];
int P[100]; // varfurile vizitate
int G[100];

void citire()
{
    ifstream in("data.in");
    int x, y;

    in >> noduri;

    while (in >> x >> y)
    {
        ++muchii;
        a[x][y] = a[y][x] = 1;
    }
}

void BFS(int s)
{
    int c[10], p, u, v;
    p = u = 1;
    c[p] = s;
    P[s] = 1;

    while (p <= u)
    {
        v = c[p];
        ++p;

        for (int i = 1; i <= noduri; i++)
            if (a[v][i] == 1 && P[i] == 0)
            {
                ++u;
                c[u] = i;
                P[i] = 1;
            }
    }
}

void DFS(int s)
{
    P[s]=1;

    for(int i = 1; i <= noduri; i++)
        if(a[s][i] == 1 && P[i] == 0)
            DFS(i);
}

bool conex()
{
    BFS(1);

    for(int i = 1; i <= noduri; i++)
        if(P[i] == 0)
            return false;

    return true;
}

int grad(int k)
{
    int suma = 0;

    for (int i = 1; i <= noduri; i++)
        suma += a[k][i];

    return suma;
}

bool euler()
{
    if(!conex())
        return false;

    for(int i = 1; i <= noduri; i++)
        if(G[i] % 2 == 1)
            return false;

    return true;
}

int main()
{
    citire();

    if (euler())
        cout << "E eulerian";

    return 0;
}
