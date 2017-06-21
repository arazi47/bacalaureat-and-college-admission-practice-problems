// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2017.pdf

#include <iostream>

#define MAX 100 + 1

using namespace std;

int sumaCifre(int n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }

    return s;
}

int cifraDeControl(int n)
{
    while (n > 9)
        n = sumaCifre(n);

    return n;
}

void citire(int &nr, int &m, int &n, int A[MAX][MAX])
{
    cin >> nr;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];
}

void determinaVectorulDeCifreDeControl(int m, int n, int A[MAX][MAX], bool c[10])
{
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            c[cifraDeControl(A[i][j])] = true;
}

int determinaCelMaiLungPrefix(int nr, bool c[10])
{
    // Punem numarul intr-un vector
    int v[5], n = 0;
    while (nr)
    {
        v[n++] = nr % 10;
        nr /= 10;
    }

    // Inversam vectorul, ca sa obtinem de la 0 la n cifrele numarului initial
    // De la stanga la dreapta
    for (int i = 0; i < n / 2; ++i)
    {
        int t = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = t;
    }

    // Cel mai lung prefix
    int rez = 0;
    bool areMacarOCifra = false;

    // Construim cel mai lung prefix
    for (int i = 0; i < n; ++i)
    {
        if (c[v[i]])
        {
            rez = rez * 10 + v[i];

            if (!areMacarOCifra)
                areMacarOCifra = true;
        }
        else
            break;
    }

    return areMacarOCifra ? rez : -1;
}

void afiseazaCelMaiLungPrefix(int p)
{
    if (p == -1)
        cout << "nu exista prefix";
    else
        cout << p;
}

// Date de intrare:
// 12319
// 3 4
// 182 12 274 22 22 1 98 56 5 301 51 94
int main()
{
    int nr, m, n, A[MAX][MAX], prefix;
    bool c[10] = {};

    citire(nr, m, n, A);
    determinaVectorulDeCifreDeControl(m, n, A, c);
    prefix = determinaCelMaiLungPrefix(nr, c);
    afiseazaCelMaiLungPrefix(prefix);

    return 0;
}
