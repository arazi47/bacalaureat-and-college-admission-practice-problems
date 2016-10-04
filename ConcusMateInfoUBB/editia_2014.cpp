// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2014.pdf

#include <iostream>

using namespace std;

void citeste(int &n, int A[][100])
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j= 1; j <= n; ++j)
            cin >> A[i][j];
}

bool prim(int n)
{
    for (int d = 2; d * d <= n; ++d)
        if (n % d == 0)
            return false;
    return true;
}

bool superPrim(int n)
{
    while (n)
    {
        if (!prim(n))
            return false;

        n /= 10;
    }

    return true;
}

void tiparesteSir(int marime, int sir[])
{
    for (int i = 0; i < marime; ++i)
        cout << sir[i] << ' ';
}

// Inseram val in X in mod descrescator
void insereaza(int &m, int X[], int val)
{
    for (int i = 0; i < m; ++i)
        if (X[i] == val)
            return;

    int i = 0;
    while (val < X[i])
        ++i;

    if (i < m)
    {
        for (int j = m; j > i; --j)
            X[j] = X[j - 1];
        X[i] = val;
        ++m;
    }
    else // i == m; i > m e imposibil
    {
        X[m++] = val;
    }
}

int main()
{
    int n, A[100][100];
    citeste(n, A);

    int m = 0, X[100] = {};

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            // Sub diagonala principala
            // Si deasupra diagonalei secundare
            if (i > j && i + j < n + 1)
                if (superPrim(A[i][j]))
                    insereaza(m, X, A[i][j]);

            // Deasupra diagonalei principale
            // Si sub diagonala secundara
            if (i < j && i + j > n + 1)
                if (superPrim(A[i][j]))
                    insereaza(m, X, A[i][j]);
        }

    if (m == 0)
        cout << "Sirul este vid" << endl;
    else
        tiparesteSir(m, X);

    return 0;
}
