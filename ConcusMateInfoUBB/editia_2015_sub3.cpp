// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2015.pdf

#include <iostream>

using namespace std;

struct triplet
{
    int i;  // linie
    int j;  // coloana
    int val; // valoare
};

struct matrice_rara
{
    int n; // nr linii
    int m; // nr coloane
    triplet tr[100];
    int nr_el; // numarul elementelor

    matrice_rara()
    {
        nr_el = 0;
    }
};

bool mai_mic_lexicografic(triplet t1, triplet t2)
{
    return (t1.i < t2.j || (t1.i == t2.i && t1.j < t2.j));
}

void citeste_matrice(matrice_rara &m)
{
    cin >> m.n >> m.m;
    int l, c, v; // linie, coloana, valoare
    cin >> l >> c >> v;
    while (l != -1 && c != -1 && v != -1)
    {
        m.tr[m.nr_el].i = l - 1;
        m.tr[m.nr_el].j = c - 1;
        m.tr[m.nr_el].val = v;
        ++m.nr_el;
        cin >> l >> c >> v;
    }
}

int gaseste_element(matrice_rara m, int i, int j)
{
    for (int k = 0; k < m.nr_el; ++k)
        if (m.tr[k].i == i && m.tr[k].j == j)
            return m.tr[k].val;
    return 0;
}

void tipareste_matrice_rara(matrice_rara m)
{
    for (int i = 0; i < m.n; ++i)
    {
        for (int j = 0; j < m.m; ++j)
            cout << gaseste_element(m, i, j) << ' ';
        cout << endl;
    }
}

void determina_matrice(matrice_rara A, matrice_rara B, matrice_rara &C)
{
    C.m = A.m;
    C.n = A.n;

    for (int i = 0; i < C.m; ++i)
    {
        for (int j = 0; j < C.n; ++j)
        {
            if (gaseste_element(A, i, j) + gaseste_element(B, i, j) != 0)
            {
                C.tr[C.nr_el].i = i;
                C.tr[C.nr_el].j = j;
                C.tr[C.nr_el].val = gaseste_element(A, i, j) + gaseste_element(B, i, j);
                ++C.nr_el;
            }
        }
    }
}

int main()
{
    matrice_rara A, B, C;
    citeste_matrice(A);
    citeste_matrice(B);
    determina_matrice(A, B, C);
    tipareste_matrice_rara(C);
    return 0;
}
