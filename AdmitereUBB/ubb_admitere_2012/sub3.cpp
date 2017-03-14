// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2012-informatica.pdf

// cred ca la asta mai trebuie lucrat

#include <iostream>

using namespace std;

bool asemenea(int a, int b)
{
    int v[10] = {};
    while (a)
    {
        v[a % 10] = 1;
        a /= 10;
    }

    while (b)
    {
        ++v[b % 10];
        b /= 10;
    }

    for (int i = 0; i < 10; ++i)
        if (v[i] == 1)
            return false;

    return true;
}

void citire(int &n, int *v)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}

void tiparire(int n, int *v)
{
    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';
}

void determina_secventa_maxima(int n, int *x, int start, int &fin)
{
    for (int i = start; i < n; ++i)
        if (asemenea(x[i], x[i + 1]))
            ++fin;
        else
            break;

    // fin va fi mai mare cu 1 decat indexul final al secventei
    --fin;
}

// verificam daca valoarea "val" apartine sirului r
bool este_in_r(int m, int *r, int val)
{
    for (int i = 0; i < m; ++i)
        if (r[i] == val)
            return true;

    return false;
}

void insereaza_in_r(int *x, int &m, int *r, int start, int fin)
{
    while (start <= fin)
    {
        if (!este_in_r(m, r, x[start]))
            r[m++] = x[start];
        ++start;
    }
}

void elimina_din_x(int &n, int *x, int start, int fin)
{
    // inlocuim elementele situate intre start si fin cu elementele de dupa
    for (int i = 1; i < n - fin; ++i)
        x[start++] = x[fin + i];
}

void determina_secvente(int &n, int *x, int &m, int *r)
{
    int fin; // finalul secventei curente
    for (int i = 0; i < n - 1; ++i)
    {
        if (asemenea(x[i], x[i + 1]))
        {
            fin = i + 1;
            determina_secventa_maxima(n, x, i, fin);
            if (i != fin)
            {
                // intai inseram in r elementele ce apartin secventei
                insereaza_in_r(x, m, r, i, fin);

                // doar apoi le putem elimina din x
                elimina_din_x(n, x, i, fin);

                // scade marimea sirului x
                n -= (fin - i);
            }
        }
    }
}

int main()
{
    int n, x[100];
    int m = 0, r[100];
    citire(n, x);

    determina_secvente(n, x, m, r);

    tiparire(n, x);

    cout << endl;

    if (m == 0)
        cout << "R este sirul vid";
    else
        tiparire(m, r);

    return 0;
}
