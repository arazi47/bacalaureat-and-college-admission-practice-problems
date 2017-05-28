// https://drive.google.com/file/d/0B0NnkrRhUimbLW5DUTZtUTlvWVk/view
// Problema 3

#include <iostream>

using namespace std;

// returneaza numarul de cifre ale numarului n
int nrc(int n)
{
    int s = 0;
    while (n)
    {
        ++s;
        n /= 10;
    }

    return s;
}

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

int maxDiagPrincipala(int a[10][10], int n)
{
    int max = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i < j && a[i][j] > max)
                max = a[i][j];

    return max;
}

int main()
{
    int n, nrcif, a[10][10];
    cin >> n;
    nrcif = nrc(n);
    for (int i = 1; i <= nrcif; ++i)
    {
        a[i][1] = n % 10;
        n /= 10;
    }

    for (int i = 1; i <= nrcif; ++i)
        for (int j = 2; j <= nrcif; ++j)
            a[i][j] = a[i][j - 1] + i;

    for (int i = 1; i <= nrcif; ++i)
    {
        for (int j = 1; j <= nrcif; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }

    cout << '\n' << maxDiagPrincipala(a, nrcif);

    cout << endl << endl;

    int k;
    for (int i = 1; i < nrcif; ++i)
    {
        k = 1;
        while (k < nrcif)
        {
            cout << a[i][k] << ' ' << a[i][k + 1] << endl;
            cout << a[i + 1][k] << ' ' << a[i + 1][k + 1] << endl;

            if (prim(a[i][k] * a[i + 1][k + 1] - a[i + 1][k] * a[i][k + 1]))
                cout << "Determinantul este prim: " << a[i][k] * a[i + 1][k + 1] - a[i + 1][k] * a[i][k + 1];

            ++k;
            cout << endl << endl;
        }
    }

    return 0;
}
