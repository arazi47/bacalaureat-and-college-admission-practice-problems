// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2013-septembrie-informatica.pdf

#include <iostream>

using namespace std;

void citire(int &n, int *x)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
}

void tiparire(int n, int *x)
{
    if (n == 0)
        cout << "Sirul Y e vid.";
    else
        for (int i = 0; i < n; ++i)
            cout << x[i] << ' ';
}

void insereaza(int &m, int *Y, int val)
{
    for (int i = 0; i < m; ++i)
        if (Y[i] == val)
            return;

    Y[m++] = val;
}

void descompune(int n, int &m, int *Y)
{
    int d = 2, p;
    while (n > 1)
    {
        p = 0;
        while (n % d == 0)
        {
            n /= d;
            ++p;
        }

        if (p == 1)
            insereaza(m, Y, d);

        ++d;
    }
}

int main()
{
    int n, m = 0, X[500], Y[500];
    citire(n, X);

    for (int i = 0; i < n; ++i)
        descompune(X[i], m, Y);

    tiparire(m, Y);

    return 0;
}
