// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2014.pdf

#include <iostream>

using namespace std;

#define MAX 50

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

bool superprim(int n)
{
    if (!prim(n))
        return false;

    while (n / 10 != 0)
    {
        if (!prim(n / 10))
            return false;
        n /= 10;
    }

    return true;
}

// verifica daca valoarea val se afla in sirul X
bool exista(int k, int X[MAX * MAX], int val)
{
    for (int i = 0; i < k; ++i)
        if (X[i] == val)
            return true;

    return false;
}

// insereaza valoarea val in sirul X in ordine descrescatoare
void insereazaDescrescator(int &k, int X[MAX * MAX], int val)
{
    // numerele din sir trebuie sa fie distincte
    if (exista(k, X, val))
        return;

    int j = k - 1;
    while (j >= 0 && val > X[j])
    {
        X[j + 1] = X[j];
        --j;
    }

    X[j + 1] = val;
    ++k;
}

void tiparesteSir(int k, int X[MAX * MAX])
{
    if (k == 0)
        cout << "Sirul este vid";
    else
    {
        for (int i = 0; i < k; ++i)
            cout << X[i] << ' ';
    }
}

void citire(int &n, int A[MAX][MAX])
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];
}

void determinaSuperprime(int n, int A[MAX][MAX], int &k, int X[MAX * MAX])
{
    k = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // triunghiul stang
            if (i > j && i + j < n + 1 && superprim(A[i][j]))
                insereazaDescrescator(k, X, A[i][j]);
            else if (i < j && i + j > n + 1 && superprim(A[i][j]))
                insereazaDescrescator(k, X, A[i][j]);
        }
    }
}

int main()
{
    int A[MAX][MAX], n;
    // sirul X de lungime k ce va contine numerele superprime, ordonate descrescator
    int X[MAX * MAX], k;

    citire(n, A);
    determinaSuperprime(n, A, k, X);
    tiparesteSir(k, X);

    return 0;
}

