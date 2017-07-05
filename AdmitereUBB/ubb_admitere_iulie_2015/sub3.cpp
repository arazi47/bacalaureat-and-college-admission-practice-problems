// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2015-iulie-informatica.pdf

#include <iostream>

using namespace std;

// + 1 pentru ca incep indexarea matricei de la 1
#define MAX 100 + 1

bool prim(int n)
{
    if (n < 2)
        return false;
    if (n % 2 == 0 && n != 2)
        return false;
    for (int d = 3; d * d <= n; d += 2)
        if (n % d == 0)
            return false;

    return true;
}

// returneaza 10 ^ (numarul de cifre ale lui n - 1)
int putere(int n)
{
    int p = 1;
    while (n > 9)
    {
        p *= 10;
        n /= 10;
    }

    return p;
}

bool magic(int n)
{
    if (!prim(n))
        return false;

    int p = putere(n);

    // prima cifra
    if (!prim(n / p))
        return false;

    // eliminam prima cifra, desi nu e neaparat
    // de exemplu: 3547
    // 3547 % 100 = 547
    // oricum nu mai avem treaba cu prima cifra, deci e totuna
    n %= p;

    while (n % p != 0)
    {
        if (!prim(n % p))
            return false;

        n %= p;
        p /= 10;
    }

    return true;
}

void citire(int &n, int &m, int A[MAX][MAX])
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> A[i][j];
}

void construiesteSir(int n, int m, int A[MAX][MAX], int &k, int X[MAX * MAX])
{
    k = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            X[k++] = A[j][i];
}

void determinaSecventaMaxima(int k, int X[MAX * MAX], int &start, int &stop)
{
    int startMax = 0, stopMax = 0;

    for (int i = 0; i < k - 1; ++i)
    {
        if (magic(X[i] + X[i + 1]))
        {
            start = i;
            stop = i + 1;

            while (magic(X[stop] + X[stop + 1] && stop < k - 1))
                ++stop;

            if (stop - start > stopMax - startMax)
            {
                startMax = start;
                stopMax = stop;
            }
        }
    }

    start = startMax;
    stop = stopMax;
}

void tiparesteSecventaMaxima(int X[MAX * MAX], int start, int stop)
{
    if (start == 0 && stop == 0)
        cout << "Nu exista secventa";
    else
    {
        while (start <= stop)
        {
            cout << X[start] << ' ';
            ++start;
        }
    }
}

int main()
{
    // n, m - dimensiunile matricei A
    // k - lungimea sirului X (X poate avea maxim n * m elemente, adica MAX * MAX)
    // start, stop - indexul inceputului si sfarsitului secventei de lungime maxima
    int n, m, A[MAX][MAX], X[MAX * MAX], k, start, stop;
    citire(n, m, A);
    construiesteSir(n, m, A, k, X);
    determinaSecventaMaxima(k, X, start, stop);
    tiparesteSecventaMaxima(X, start, stop);

    return 0;
}

