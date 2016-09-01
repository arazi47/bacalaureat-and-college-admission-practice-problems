// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2013-informatica.pdf

#include <iostream>

using namespace std;

int n = 1; // marime X
int X[100];

int m = 0; // marime Y
struct sirY
{
    int nr;
    int aparitii;
} Y[100];

bool ARE_ELEMENTE = false;

void citire()
{
    cin >> X[n];
    while (X[n] != 0)
    {
        ++n;
        cin >> X[n];
    }
}

bool prim(int x)
{
    for (int d = 2; d * d <= x; ++d)
        if (x % d == 0)
            return false;

    return true;
}

int suma(int x)
{
    int s = 0;

    while (x)
    {
        s += x % 10;
        x /= 10;
    }

    return s;
}

void tiparire()
{
    if (!ARE_ELEMENTE)
    {
        cout << "Sirul Y este vid";
        return;
    }

    for (int i = 1; i <= m; ++i)
        cout << Y[i].nr << ' ' << Y[i].aparitii << endl;
}

void insereaza(int val1, int val2)
{
    if (!ARE_ELEMENTE)
        ARE_ELEMENTE = true;

    ++m;
    Y[m].nr = val1;
    Y[m].aparitii = val2;
}

void construiesteY()
{
    int vdf[10001] = {};

    for (int i = 1; i <= n; ++i)
        if (prim(suma(X[i])))
            vdf[X[i]]++;

    for (int i = 1; i <= 10000; ++i)
        if(vdf[i] > 0)
            insereaza(i, vdf[i]);
}

int main()
{
    citire();
    construiesteY();
    tiparire();

    return 0;
}
