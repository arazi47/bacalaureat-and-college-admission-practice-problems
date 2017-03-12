// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2014-septembrie-informatica.pdf

#include <iostream>

using namespace std;

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
    if (prim(n))
        return true;

    int c = n, nrcif = 0;
    while (c)
    {
        ++nrcif;
        c /= 10;
    }

    --nrcif;

    int putere = 1;
    while (nrcif)
    {
        putere *= 10;
        --nrcif;
    }

    c = n;
    c = (c % putere) * 10 + c / putere;
    while (c != n)
    {
        if (prim(c))
            return true;
        c = (c % putere) * 10 + c / putere;
    }

    return false;
}

void interschimba(int a[51][51], int i1, int j1, int i2, int j2)
{
    int tmp = a[i1][j1];
    a[i1][j1] = a[i2][j2];
    a[i2][j2] = tmp;
}

void citire(int &n, int a[51][51])
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
}

void afisare(int n, int a[51][51])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}

void interschimba_superior_inferior(int n, int a[51][51])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i < j && i + j < n + 1)
                interschimba(a, i, j, n + 1 - i, j);
}

void interschimba_superprime(int n, int a[51][51])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i > j && i + j < n + 1)
                if (superprim(a[i][j]) && superprim(a[i][n + 1 - j]))
                    interschimba(a, i, j, i, n + 1 - j);
}

int main()
{
    int n, a[51][51];
    citire(n, a);
    interschimba_superior_inferior(n, a);
    interschimba_superprime(n, a);
    afisare(n, a);
    return 0;
}
