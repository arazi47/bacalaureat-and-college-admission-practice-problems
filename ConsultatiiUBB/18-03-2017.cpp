// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-18.03.2017.pdf

#include <iostream>

using namespace std;

void afiseaza(int n, int a[21][21])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    cout << endl << endl;
}

bool eNula(int n, int a[21][21])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j] != 0)
                return false;

    return true;
}

void citire(int &n, int &m)
{
    cin >> n >> m;
}

int nrDivProprii(int n)
{
    int cnt = 0;
    for (int d = 2; d <= (n / 2) + 1; ++d)
        if (n % d == 0)
            ++cnt;

    return cnt;
}

void matriceInitiala(int n, int a[21][21], int m)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i + j == n + 1)
                a[i][j] = m;
            else
                a[i][j] = 0;

    a[1][1] = a[1][n] - n + 1;

    for (int i = 2; i <= n; ++i)
        a[i][1] = a[i - 1][1] + 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 2; j <= n; ++j)
            if (a[i][j] == 0)
                a[i][j] = a[i][j - 1] + 1;
}

void matriceDivizori(int n, int a[21][21])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = nrDivProprii(a[i][j]);
}

int main()
{
    int n, m, a[21][21];
    citire(n, m);
    matriceInitiala(n, a, m);
    afiseaza(n, a);

    do
    {
        matriceDivizori(n, a);
        afiseaza(n, a);
    } while (!eNula(n, a));

    return 0;
}