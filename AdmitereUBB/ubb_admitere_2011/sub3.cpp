// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2011-informatica.pdf

#include <iostream>

using namespace std;

int oglindit(int n)
{
    int o = 0; // oglinditul (inversul) lui n
    while (n)
    {
        o = o * 10 + n % 10;
        n /= 10;
    }

    return o;
}

bool palindrom(int n)
{
    return n == oglindit(n);
}

void insereaza_descrescator(int &n, int *v, int val)
{
    for (int i = 0; i < n; ++i)
        if (v[i] == val)
            return;

    int j = n - 1;
    while (j >= 0 && val > v[j])
    {
        v[j + 1] = v[j];
        --j;
    }

    v[j + 1] = val;
    ++n;
}

void citire(int &n, int *v)
{
    n = 0;
    int t;
    cin >> t;
    while (t != 0)
    {
        v[n++] = t;
        cin >> t;
    }
}

void tiparire(int n, int *v)
{
    if (n == 0)
    {
        cout << "Sirul Y e vid";
        return;
    }

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';
}

void determina_palindroame(int n, int *X, int &m, int *Y)
{
    for (int i = 0; i < n; ++i)
        if (palindrom(X[i]))
            insereaza_descrescator(m, Y, X[i]);
}

int main()
{
    int n, X[100], m = 0, Y[100];
    citire(n, X);
    determina_palindroame(n, X, m, Y);
    tiparire(m, Y);

    return 0;
}
