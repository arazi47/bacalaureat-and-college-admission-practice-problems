// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2012-informatica.pdf

#include <iostream>

using namespace std;

// nu se da maximul in enuntul problemei
#define MAX 100

void citire(int &n, int X[MAX])
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> X[i];
}

void tiparesteSir(int k, int R[MAX])
{
    for (int i = 0; i < k; ++i)
        cout << R[i] << ' ';

    cout << endl;
}

int configureazaCifre(int n)
{
    int r = 0;
    while (n)
    {
        r |= 1 << (n % 10);
        n /= 10;
    }

    return r;
}

bool asemenea(int a, int b)
{
    a = configureazaCifre(a);
    b = configureazaCifre(b);

    return a == b;
}

// verifica daca x se gaseste in sirul R
bool existaInR(int k, int R[MAX], int x)
{
    for (int i = 0; i < k; ++i)
        if (R[i] == x)
            return true;

    return false;
}

// insereaza in R elementele sirului X cuprinse intre indexurile start si stop
void insereazaInR(int X[MAX], int &k, int R[MAX], int start, int stop)
{
    while (start <= stop)
    {
        if (!existaInR(k, R, X[start]))
            R[k++] = X[start];

        ++start;
    }
}

void eliminaDinX(int &n, int X[MAX], int start, int stop)
{
    for (int i = 0; i + stop + 1 < n; ++i)
        X[start + i] = X[i + stop + 1];

    n -= (stop - start + 1);
}

// determina secventele de numere asemenea din sirul X
void determinaSecvente(int &n, int X[MAX], int &k, int R[MAX])
{
    k = 0;

    // indexul inceputului si sfarsitului secventei
    int start, stop;

    for (int i = 0; i < n - 1; ++i)
    {
        if (asemenea(X[i], X[i + 1]))
        {
            start = i;
            stop = i + 1;

            while (asemenea(X[stop], X[stop + 1]) && stop < n - 1)
                ++stop;

            insereazaInR(X, k, R, start, stop);
            eliminaDinX(n, X, start, stop);
        }
    }
}

int main()
{
    int n, X[MAX], k, R[MAX];
    citire(n, X);
    determinaSecvente(n, X, k, R);

    if (n > 0)
    {
        cout << "X = ";
        tiparesteSir(n, X);
    }
    else
        cout << "X este sirul vid" << endl;

    if (k > 0)
    {
        cout << "R = ";
        tiparesteSir(k, R);
    }
    else
        cout << "R este sirul vid" << endl;

    return 0;
}

