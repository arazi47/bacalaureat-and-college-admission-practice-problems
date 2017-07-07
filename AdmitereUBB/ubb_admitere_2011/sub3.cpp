// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2011-informatica.pdf

#include <iostream>

using namespace std;

// numarul maxim de elemente nu este specificat in enuntul problemei
#define MAX 100

bool palindrom(int n)
{
    if (n % 10 == 0)
        return false;
    int m = 0;
    while (n)
    {
        m = m * 10 + n % 10;
        if (m == n)
            return true;
        n /= 10;
        if (m == n)
            return true;
        if (m > n)
            return false;
    }

    return false;
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

void tiparesteSir(int k, int Y[MAX])
{
    if (k == 0)
        cout << "Sirul Y e vid";
    else
    {
        for (int i = 0; i < k; ++i)
            cout << Y[i] << ' ';
    }
}

// verifica daca numarul x se gaseste in sirul Y
bool exista(int k, int Y[MAX], int x)
{
    for (int i = 0; i < k; ++i)
        if (Y[i] == x)
            return true;
    return false;
}

// insereaza valoarea x in sirul Y de lungime k in mod descrescator
void insereazaInSirulY(int &k, int Y[MAX], int x)
{
    // elementele sirului Y trebuie sa fie distincte
    if (exista(k, Y, x))
        return;

    int j = k - 1;
    while (j >= 0 && x > Y[j])
    {
        Y[j + 1] = Y[j];
        --j;
    }

    Y[j + 1] = x;
    ++k;
}

void determinaPalindroame(int n, int X[MAX], int &k, int Y[MAX])
{
    k = 0;
    for (int i = 0; i < n; ++i)
    {
        if (palindrom(X[i]))
            insereazaInSirulY(k, Y, X[i]);
    }
}

int main()
{
    int n, X[MAX];
    int k, Y[MAX];

    citire(n, X);
    determinaPalindroame(n, X, k, Y);
    tiparesteSir(k, Y);

    return 0;
}

