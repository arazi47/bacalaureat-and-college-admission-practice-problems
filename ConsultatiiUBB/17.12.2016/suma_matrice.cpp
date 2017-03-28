// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-17.12.2016.pdf

#include <iostream>

using namespace std;

void citire(int &n, int &m, int a[101][101])
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
}

void initializeazaCuZero(int n, int m, int a[101][101])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = 0;
}

void afiseaza(int n, int m, int a[101][101])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}

void sumaMatrice(int n, int m, int a[101][101], int suma[101][101])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            suma[i][j] += a[i][j];
}

bool eNula(int n, int m, int a[101][101])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j])
                return false;

    return true;
}

int main()
{
    int n, m, a[101][101], suma[101][101];
    citire(n, m, a);
    initializeazaCuZero(n, m, suma);

    while (!eNula(n, m, a))
    {
        sumaMatrice(n, m, a, suma);
        citire(n, m, a);
    }

    afiseaza(n, m, suma);

    return 0;
}
