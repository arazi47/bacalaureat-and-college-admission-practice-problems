// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2015.pdf

#include <iostream>

using namespace std;

struct triplet
{
    // linie, coloana, valoare
    int i, j, val;
};

struct matrice_rara
{
    int n, m; // numarul de linii si coloane ale matricei
    triplet tr[100];
    int nr_el; // numarul de elemente

    matrice_rara()
    {
        nr_el = 0;
    }
};

bool mai_mic_lexicografic(triplet t1, triplet t2)
{
    return (t1.i < t2.i) || (t1.i == t2.i && t1.j < t2.j);
}

void inserare(matrice_rara &m, int l, int c, int v)
{
    m.tr[m.nr_el].i = l;
    m.tr[m.nr_el].j = c;
    m.tr[m.nr_el].val = v;
    ++m.nr_el;
}

int gaseste_element(matrice_rara &m, int l, int c)
{
    for (int i = 0; i < m.nr_el; ++i)
        if (m.tr[i].i == l && m.tr[i].j == c)
            return m.tr[i].val;

    return 0;
}

void citeste(matrice_rara &m)
{
    cin >> m.n >> m.m;
    int l, c, v;
    cin >> l >> c >> v;
    while (l != -1 && c != -1 && v != -1)
    {
        if (gaseste_element(m, l, c) == 0)
            inserare(m, l, c, v);
        cin >> l >> c >> v;
    }
}

void suma(matrice_rara a, matrice_rara b, matrice_rara &c)
{
    c.n = a.n;
    c.m = a.m;

    for (int i = 1; i <= a.n; ++i)
        for (int j = 1; j <= a.m; ++j)
        {
            c.tr[c.nr_el].i = i;
            c.tr[c.nr_el].j = j;
            c.tr[c.nr_el].val = gaseste_element(a, i, j) + gaseste_element(b, i, j);
            ++c.nr_el;
        }
}

void tipareste(matrice_rara &m)
{
    for (int i = 1; i <= m.n; ++i)
    {
        for (int j = 1; j <= m.m; ++j)
            cout << gaseste_element(m, i, j) << ' ';
        cout << endl;
    }
}

int main()
{
    matrice_rara a, b, c;
    citeste(a);
    citeste(b);
    suma(a, b, c);
    tipareste(c);

    return 0;
}
