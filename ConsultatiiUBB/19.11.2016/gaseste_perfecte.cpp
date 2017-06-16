// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-19.11.2016.pdf

#include <iostream>

using namespace std;

void citire(int &n, int v[])
{
    n = 0;
    int val;
    do
    {
        cin >> val;
        if (val == 0)
            break;

        v[n++] = val;
    } while (true);
}

int sumaDiv(int n)
{
    if (n == 1)
        return 0;

    int s = 0;
    for (int d = 1; d <= (n / 2) + 1; ++d)
        if (n % d == 0)
            s += d;

    return s;
}

bool perfect(int n)
{
    return n == sumaDiv(n);
}

void determinaPerfecte(int n, int v[], int &m, int a[])
{
    m = 0;
    bool existaPerfect = false;
    for (int i = 0; i < n; ++i)
        if (perfect(v[i]))
        {
            a[m++] = v[i];

            if (!existaPerfect)
                existaPerfect = true;
        }
}

void afiseazaPerfecte(int m, int a[])
{
    if (m == 0)
        cout << "Nu exista numere perfecte in acest sir.";
    else
        for (int i = 0; i < m; ++i)
            cout << a[i] << ' ';
}

int main()
{
    int n, v[100], m, a[100];
    citire(n, v);
    determinaPerfecte(n, v, m, a);
    afiseazaPerfecte(m, a);

    return 0;
}
