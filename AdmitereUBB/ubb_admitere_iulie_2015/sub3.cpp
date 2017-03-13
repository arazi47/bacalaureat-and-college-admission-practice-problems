// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2015-iulie-informatica.pdf

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

// va retuna 10 la puterea numarului de cifre ale lui n
int putere(int n)
{
    int p = 1;
    while (n)
    {
        p *= 10;
        n /= 10;
    }

    return p;
}

bool magic(int n)
{
    int n_initial = n;
    int p = 1;
    int putere_max = putere(n);
    while (p != putere_max)
    {
        p *= 10;
        if (!prim(n))
            return false;
        n = n_initial % p;
    }

    putere_max /= 10;
    // prima cifra
    if (!prim(n_initial / putere_max))
        return false;

    return true;
}

void citire(int &n, int &m, int a[101][101])
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
}

void determina_x(int n, int m, int a[101][101], int &l, int *x)
{
    l = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            x[l++] = a[j][i];
}

void determina_secventa_maxima(int l, int *x, int st, int &fin)
{
    for (int i = st; i <= l; ++i)
        if (magic(x[i] + x[i + 1]))
            ++fin;
        else
            break;

    // fin se va duce cu o pozitie mai incolo decat trebuie, trebuie sa scadem 1
    --fin;
}

void determina_secvente(int l, int *x, int &max_st, int &max_fin)
{
    max_st = max_fin = 0; // inceputul si finalul secventei maxime
    int fin; // finalul secventei curente

    for (int i = 1; i < l; ++i)
    {
        if (magic(x[i] + x[i + 1]))
        {
            fin = i + 1;
            determina_secventa_maxima(l, x, i, fin);

            if (fin - i > max_fin - max_st)
            {
                max_st = i;
                max_fin = fin;
            }
        }
    }
}

void afiseaza_secventa(int *x, int start, int fin)
{
    if (start == 0 || fin == 0)
    {
        cout << "Nu exista secventa";
        return;
    }

    for (int i = start; i <= fin; ++i)
        cout << x[i] << ' ';
}

int main()
{
    int n, m, a[101][101];
    int l, x[101*101]; // l = lungimea sirului x

    citire(n, m, a);
    determina_x(n, m, a, l, x);

    int start, fin;
    determina_secvente(l, x, start, fin);

    afiseaza_secventa(x, start, fin);

    return 0;
}
