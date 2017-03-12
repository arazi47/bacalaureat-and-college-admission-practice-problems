// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2014-iulie-informatica.pdf

#include <iostream>

using namespace std;

int primacif(int n)
{
    while (n > 9)
        n /= 10;

    return n;
}

int ultcif(int n)
{
    return n % 10;
}

int cifmax(int n)
{
    int max = 0;
    while (n)
    {
        if (ultcif(n) > max)
            max = ultcif(n);

        n /= 10;
    }

    return max;
}

// determina numarul maxim format din elementele de pe coloana "col"
int determina_max_coloana(int n, int a[10][10], int col)
{
    int v[10] = {};
    for (int i = 1; i <= n; ++i)
        ++v[a[i][col]];

    int nr = 0;
    for (int i = 9; i >= 0; --i)
        while (v[i] > 0)
        {
            nr = nr * 10 + i;
            --v[i];
        }

    return nr;
}

void determina_sir(int n, int *x)
{
    int cnt = 2 * n * n;
    int m = 1; // pozitia unde am ajuns in x
    int nr = 1;

    while (m <= cnt)
    {
        x[m++] = nr;

        int d = 2;
        while (d <= nr / 2 && m < cnt)
        {
            if (nr % d == 0)
                x[m++] = d;

            ++d;
        }

        ++nr;
    }
}

void construieste_matrice(int n, int a[10][10], int *x)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i + j < n + 1) // deasupra diagonalei secundare
                a[i][j] = ultcif(x[n * n + i + j]);
            else if (i + j > n + 1) // sub diagonala secundara
                a[i][j] = primacif(x[n * n + i + j]);
            else // pe diagonala secundara
                a[i][j] = cifmax(x[n * n + i * i]);
        }
}

void afiseaza_matrice(int n, int a[10][10])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';

        cout << endl;
    }
}

void afiseaza_numere_maxime(int n, int a[10][10])
{
    for (int i = 1; i <= n; ++i)
        cout << determina_max_coloana(n, a, i) << ' ';
}

int main()
{
    // valoarea maxima a lui n poate fi 9 => 2 * 9 * 9 = 162
    int n, x[163];

    cin >> n;
    determina_sir(n, x);

    int a[10][10];
    construieste_matrice(n, a, x);
    afiseaza_matrice(n, a);
    afiseaza_numere_maxime(n, a);

    return 0;
}
