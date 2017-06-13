// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-18.03.2017.pdf

#include <iostream>

using namespace std;

int nrDivProprii(int n)
{
    int cnt = 0;
    for (int d = 2; d <= n / 2 + 1; ++d)
        if (n % d == 0)
            ++cnt;

    return cnt;
}

void citire(int &n, int &m)
{
    cin >> n >> m;
}

void initializeazaMatrice(int n, int a[101][101], int m)
{
    a[1][1] = m - (n - 1);
    for (int i = 2; i <= n; ++i)
    {
        a[i][1] = a[i - 1][1] + 1;
        a[1][i] = a[1][i - 1] + 1;
    }

    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= n; ++j)
            a[i][j] = a[i][j - 1] + 1;
}

void puneDivizoriPeMatrice(int n, int a[101][101])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = nrDivProprii(a[i][j]);
}

void afiseazaMatrice(int n, int a[101][101])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }

    cout << endl << endl;
}

bool eNula(int n, int a[101][101])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j] != 0)
                return false;

    return true;
}

int main()
{
    int n, a[101][101], m;
    citire(n, m);
    initializeazaMatrice(n, a, m);
    afiseazaMatrice(n, a);

    while (!eNula(n, a))
    {
        puneDivizoriPeMatrice(n, a);
        afiseazaMatrice(n, a);
    }

    return 0;
}
