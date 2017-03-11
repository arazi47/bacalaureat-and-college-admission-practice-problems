// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2013-informatica.pdf

#include <iostream>

using namespace std;

struct sir
{
    int val;
    int aparitii;
};

void citire(int &n, int *x)
{
    n = 0;
    int val;
    cin >> val;
    while (val != 0)
    {
        x[n++] = val;
        cin >> val;
    }
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

// calculeaza suma cifrelor unui numar
int sc(int n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }

    return s;
}

void inserare(int &m, sir Y[], int val)
{
    for (int i = 0; i < m; ++i)
        if (Y[i].val == val)
        {
            ++Y[i].aparitii;
            return;
        }

    int j = m - 1;
    while (j >= 0 && val < Y[j].val)
    {
        Y[j + 1] = Y[j];
        --j;
    }

    Y[j + 1].val = val;
    Y[j + 1].aparitii = 1;
    ++m;
}

void tiparire(int n, sir Y[])
{
    if (n == 0)
    {
        cout << "Sirul Y este vid";
        return;
    }

    for (int i = 0; i < n; ++i)
        cout << Y[i].val << ' ' << Y[i].aparitii << endl;
}

void construieste(int n, int *x, int &m, sir Y[])
{
    for (int i = 0; i < n; ++i)
        if (prim(sc(x[i])))
            inserare(m, Y, x[i]);
}

int main()
{
    int n, m = 0, X[100];
    sir Y[100];

    citire(n, X);
    construieste(n, X, m, Y);
    tiparire(m, Y);

    return 0;
}
