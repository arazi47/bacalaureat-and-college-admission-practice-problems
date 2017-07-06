// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2013-informatica.pdf

#include <iostream>

using namespace std;

#define MAX 500

struct sir
{
    int valoare;
    int nrAparitii;
};

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

int sumaCifre(int n)
{
    int s = 0;
    while (n)
    {
        s += (n % 10);
        n /= 10;
    }

    return s;
}

void citire(int &n, int X[MAX])
{
    n = 0;
    int x;
    cin >> x;
    while (x != 0)
    {
        X[n++] = x;
        cin >> x;
    }
}

void tiparesteSir(int m, sir Y[MAX])
{
    if (m == 0)
        cout << "Sirul Y este vid";
    else
    {
        for (int i = 0; i < m; ++i)
            cout << Y[i].valoare << ' ' << Y[i].nrAparitii << endl;
    }
}

void insereazaInSirulY(int &m, sir Y[MAX], int val)
{
    for (int i = 0; i < m; ++i)
    {
        // am mai gasit acest numar deja
        // doar crestem numarul de aparitii
        if (Y[i].valoare == val)
        {
            ++Y[i].nrAparitii;
            return;
        }
    }

    int j = m - 1;
    while (j >= 0 && val < Y[j].valoare)
    {
        Y[j + 1] = Y[j];
        --j;
    }

    Y[j + 1].valoare = val;
    // suntem la prima aparitie
    Y[j + 1].nrAparitii = 1;
    ++m;
}

void construiesteSirulY(int n, int X[MAX], int &m, sir Y[MAX])
{
    m = 0;
    for (int i = 0; i < n; ++i)
    {
        if (prim(sumaCifre(X[i])))
            insereazaInSirulY(m, Y, X[i]);
    }
}

int main()
{
    int n, X[MAX];


    sir Y[MAX];
    // lungimea sirului Y
    int m;

    citire(n, X);
    construiesteSirulY(n, X, m, Y);
    tiparesteSir(m, Y);



    return 0;
}

