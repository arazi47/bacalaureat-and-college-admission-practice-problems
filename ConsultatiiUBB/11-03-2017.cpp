// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-11.03.2017.pdf

#include <iostream>

using namespace std;

void multimea_cifrelor(int n, bool *m)
{
    while (n)
    {
        m[n % 10] = true;
        n /= 10;
    }
}

bool apropiate(int a, int b)
{
    bool m1[10] = {}, m2[10] = {};
    multimea_cifrelor(a, m1);
    multimea_cifrelor(b, m2);

    int cnt = 0;
    for (int i = 0; i < 10; ++i)
        if (m1[i] && m2[i])
            ++cnt;

    return cnt >= 2;
}

void citire_matrice(int &n, int &m, int a[101][101])
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
}

// verifica daca maximul si minimul de pe o coloana
// sunt numere apropiate
bool max_min_coloana_apropiate(int n, int col, int a[101][101])
{
    int max = a[1][col], min = a[1][col];
    for (int i = 1; i <= n; ++i)
    {
        if(a[i][col] > max)
            max = a[i][col];

        if (a[i][col] < min)
            min = a[i][col];
    }

    return apropiate(min, max);
}

int cifmax(int n)
{
    int max = n % 10;
    n /= 10;
    while (n)
    {
        if (n % 10 > max)
            max = n % 10;
        n /= 10;
    }

    return max;
}

// verifica daca "val" exista deja in sir
bool exista(int n, int *r, int val)
{
    for (int i = 0; i < n; ++i)
        if (r[i] == val)
            return true;

    return false;
}

void insereaza_sortat(int &n, int *r, int val)
{
    // valorile trebuie sa fie distincte
    if (exista(n, r, val))
        return;

    int j = n - 1;
    while (j >= 0 && cifmax(val) > cifmax(r[j]))
    {
        r[j + 1] = r[j];
        --j;
    }

    r[j + 1] = val;
    ++n;
}

void elimina_coloana(int n, int &m, int col, int a[101][101], int &l, int *r)
{
    for (int i = 1; i <= n; ++i)
    {
        insereaza_sortat(l, r, a[i][col]);
        for (int j = col; j < m; ++j)
            a[i][j] = a[i][j + 1];
    }

    --m;
}

void tiparire_matrice(int n, int m, int a[101][101])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << a[i][j] << ' ';

        cout << endl;
    }
}

void tiparire_sir(int n, int *v)
{
    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';
}

int main()
{
    int n, m, a[101][101], r[100], l = 0;
    citire_matrice(n, m, a);
    for (int j = 1; j <= m; ++j)
        if (max_min_coloana_apropiate(n, j, a))
            elimina_coloana(n, m, j, a, l, r);

    tiparire_matrice(n, m, a);
    cout << endl;
    tiparire_sir(l, r);

    return 0;
}
