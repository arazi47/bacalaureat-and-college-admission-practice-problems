// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-2013.pdf

#include <iostream>

using namespace std;

void determina_cifre(int &n, int *v, int a)
{
    n = 0;
    while (a)
    {
        v[n++] = a % 10;
        a /= 10;
    }

    // inversam vectorul, sa obtinem numarul initial, nu cel oglindit
    for (int i = 0; i < n / 2; ++i)
    {
        int t = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = t;
    }
}

bool prefix(int p, int n)
{
    int cp; // cifre p
    int cn; // cifre n;

    int v1[5], v2[5]; // cifrele numerelor p si n;

    determina_cifre(cp, v1, p);
    determina_cifre(cn, v2, n);

    // daca numarul de cifre este egal sau n are mai putine cifre decat p
    if (cn <= cp)
        return false;

    for (int i = 0; i < cp; ++i)
        if (v1[i] != v2[i])
            return false;

    return true;
}

// mult mai eficient
bool prefix2(int a, int b)
{
    while (b > a)
    {
        if (b / 10 == a)
            return true;
        b /= 10;
    }
    return false;
}

void citire(int &n, int *X)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> X[i];
}

void tipareste_secventa(int st, int fin, int *X)
{
    if (st == -1 && fin == -1)
    {
        cout << "Secventa este vida";
        return;
    }

    while (st <= fin)
        cout << X[st++] << ' ';
}

void determina(int n, int *X, int &st, int &fin)
{
    int stmax = 0, finmax = 0;
    for (int i = 0; i < n; ++i)
    {
        if (prefix(X[i], X[i + 1]))
        {
            st = i;
            fin = i + 1;
            while (prefix(X[st], X[fin]))
                ++fin;

            i = fin; // sarim peste secventa
            --fin; // merge pana la capat + 1
            if (fin - st > finmax - stmax)
            {
                stmax = st;
                finmax = fin;
            }
        }
    }
}

// 9 523 742 7421 742 12 123 1234 87 875
int main()
{
    int n, X[100];
    citire(n, X);

    int st = -1, fin = -1;
    determina(n, X, st, fin);

    tipareste_secventa(st, fin, X);
    return 0;
}
