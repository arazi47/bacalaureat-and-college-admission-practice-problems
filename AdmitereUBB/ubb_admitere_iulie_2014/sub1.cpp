// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2014-iulie-informatica.pdf

#include <iostream>

using namespace std;

void subI_A_Valoare(int n)
{
    ++n;
}

void subI_A_Referinta(int &n)
{
    ++n;
}

int subI_B(int n, int X[20])
{
    // vectorul de frecventa al tuturor cifrelor
    int v[10] = {};

    for (int i = 0; i < n; ++i)
    {
        // vectorul de frecventa al unui numar
        // avem nevoie de el pentru ca daca numarul are de mai multe ori
        // aceeasi cifra (ex: 5282), sa nu il ia pe 2 de doua ori
        bool v1[10] = {};

        while (X[i])
        {
            if (!v1[X[i] % 10])
                v1[X[i] % 10] = true;
            X[i] /= 10;
        }

        // dupa ce am determinat toate cifrele din care este format numarul
        // adaugam 1 la vectorul de frecventa destinat tuturor numerelor
        for (int k = 0; k < 10; ++k)
            if (v1[k])
                ++v[k];
    }

    // numarul maxim de aparitii al unei cifre
    int cntMaxCif = 0;
    for (int i = 1; i < 10; ++i)
        if (v[i] > v[cntMaxCif])
            cntMaxCif = i;

    return cntMaxCif;
}

// Varianta ce utilizeaza tablouri
int SubI_C1(int n)
{
    // vectorul in care vom introduce cifrele numarului
    // variabila m este marimea vectorului (numarul de cifre al lui n)
    int v[10], m = 0;

    while (n)
    {
        v[m++] = n % 10;
        n /= 10;
    }

    // n este 0 acum, putem sa construim numarul invers tot in variabila aceasta
    // cu i vom parcurge vectorul de cifre
    int i = 0;
    while (i < m)
    {
        n = n * 10 + v[i];
        ++i;
    }

    return n;
}

// Varianta ce nu utilizeaza tablouri sau tipul string
int SubI_C2(int n)
{
    int r = 0;
    while (n)
    {
        r = r * 10 + n % 10;
        n /= 10;
    }

    return r;
}

int main()
{
    // Subiectul I, a
    /*
    int n;
    cin >> n;

    // Nu se schimba valoarea lui n in functia main
    subI_A_Valoare(n);
    cout << n << endl;

    // Se schimba valoarea lui n in functia main
    subI_A_Referinta(n);
    cout << n << endl;
    */

    // Subiectul I, b
    /*
    int n, X[20];

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> X[i];

    cout << subI_B(n, X);
    */

    // Subiectul I, c
    /*
    int n;
    cin >> n;

    cout << SubI_C1(n) << ' ' << SubI_C2(n);
    */

    return 0;
}


