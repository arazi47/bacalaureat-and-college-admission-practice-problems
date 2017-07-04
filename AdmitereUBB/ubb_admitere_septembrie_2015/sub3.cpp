// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2015-septembrie-informatica.pdf

#include <iostream>

using namespace std;

// numarul maxim de numere din sir
#define MAX 200

void citire(int &n, int X[MAX])
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> X[i];
}

bool cifraComuna(int a, int b)
{
    // vectorul de frecventa al numarului a
    bool v[10] = {};
    while (a)
    {
        if (!v[a % 10])
            v[a % 10] = true;

        a /= 10;
    }

    while (b)
    {
        if (v[b % 10])
            return true;

        b /= 10;
    }

    return false;
}

// verifica daca elementul de index k din sirul X este perfect
bool perfect(int n, int X[MAX], int k)
{
    for (int i = k + 1; i < n; ++i)
        if (!cifraComuna(X[k], X[i]))
            return false;

    return true;
}

// insereaza in sirul X valoarea val la indexul k
void insereaza(int &n, int X[MAX], int k, int val)
{
    for (int i = n; i > k; --i)
        X[i] = X[i - 1];

    X[k] = val;
    ++n;
}

// adauga in sirul X, divizorii elementului aflat pe indexul k dupa acest element
void adaugaDivizori(int k, int &n, int X[MAX])
{
    for (int d = 2; d <= X[k] / 2; ++d)
        if (X[k] % d == 0)
            insereaza(n, X, k + 1, d);
}

// determina sirul O, ce va contine ordinea fiecarui element din X
// astfel incat sirul sa fie afisat in ordine descrescatoare
void determinaOrdineaElementelor(int n, int X[MAX], int O[MAX])
{
    for (int i = 0; i < n; ++i)
        O[i] = i;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (X[O[i]] < X[O[j]])
            {
                int tmp = O[i];
                O[i] = O[j];
                O[j] = tmp;
            }
        }
    }
}

// tipareste sirul X in functie de sirul O
void tipareste(int n, int X[MAX], int O[MAX])
{
    for (int i = 0; i < n; ++i)
        cout << X[O[i]] << ' ';
}

int numarDivizori(int n)
{
    int cnt = 0, d;
    for (d = 2; d * d < n; d++)
        if (n % d == 0)
            cnt += 2;

    if (d * d == n)
        ++cnt;

    return cnt;
}

void determinaElementelePerfecte(int &n, int X[MAX])
{
    // n - 1 pentru ca ultimul element nu poate fi perfect
    for (int i = 0; i < n - 1; ++i)
        if (perfect(n, X, i))
        {
            adaugaDivizori(i, n, X);

            // nu-s sigur ca trebuie si asta
            // sarim peste divizorii introdusi in sir
            i += numarDivizori(X[i]);
        }
}

int main()
{
    int n, X[MAX], O[MAX];
    citire(n, X);
    determinaElementelePerfecte(n, X);
    determinaOrdineaElementelor(n, X, O);
    tipareste(n, X, O);

    return 0;
}

