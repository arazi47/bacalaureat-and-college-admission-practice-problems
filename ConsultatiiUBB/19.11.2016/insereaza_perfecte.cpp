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

int urmatorulNumarPerfect(int n)
{
    ++n;
    while (!perfect(n))
        ++n;

    return n;
}

void insereazaPerfecte(int &n, int v[])
{
    for (int i = n - 1; i >= 0; --i)
    {
        v[2 * i] = v[i];
        v[2 * i + 1] = urmatorulNumarPerfect(v[i]);
    }

    n *= 2;
}

void afisare(int n, int v[])
{
    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';
}

int main()
{
    int n, v[100];
    citire(n, v);
    insereazaPerfecte(n, v);
    afisare(n, v);

    return 0;
}
