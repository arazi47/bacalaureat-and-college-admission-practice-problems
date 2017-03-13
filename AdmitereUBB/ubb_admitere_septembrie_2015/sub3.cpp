// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2015-septembrie-informatica.pdf

#include <iostream>

using namespace std;

void citire(int &n, int *x)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
}

// verifica daca a si b au cel putin o cifra comuna
bool cif_comuna(int a, int b)
{
    bool v[10] = {};
    while (a)
    {
        v[a % 10] = true;
        a /= 10;
    }

    while (b)
    {
        if (v[b % 10] == true)
            return true;
        b /= 10;
    }

    return false;
}

// insereaza pe pozitia "poz" valoarea "val"
void insereaza(int &n, int *x, int poz, int val)
{
    for (int i = n; i >= poz; --i)
        x[i] = x[i - 1];

    x[poz] = val;
    ++n;
}

// verifica daca elementul de pe pozitia "poz" este perfect
bool perfect(int n, int *x, int poz)
{
    int i = poz + 1;
    while (i < n)
    {
        if (!cif_comuna(x[poz], x[i]))
            return false;
        ++i;
    }

    return true;
}

void adauga_divizori(int &n, int *x)
{
    for (int i = 0; i < n - 1; ++i)
    {
        if (perfect(n, x, i))
        {
            for (int d = x[i] / 2; d >= 2; --d)
                if (x[i] % d == 0)
                    insereaza(n, x, i + 1, d);
        }
    }
}

void construieste_o(int n, int *x, int *o)
{
    for (int i = 0; i < n; ++i)
        o[i] = i;

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (x[o[i]] < x[o[j]])
            {
                int t = o[i];
                o[i] = o[j];
                o[j] = t;
            }
}

void afiseaza(int n, int *x, int *o)
{
    for (int i = 0; i < n; ++i)
        cout << x[o[i]] << ' ';
}

int main()
{
    int n, x[200];
    citire(n, x);

    adauga_divizori(n, x);

    int o[200];
    construieste_o(n, x, o);
    afiseaza(n, x, o);

    return 0;
}
