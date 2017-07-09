// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2016.pdf

#include <iostream>

using namespace std;

// @todo merge, dar trebuie sa-nteleg de ce fac ++r de 2 ori
// Triunghiul lui Pascal
void subI_1(int r, int v[32])
{
    // pentru ca indexarea, in problema, incepe de la 0
    ++r;

    for (int k = 1; k < r; ++k)
    {
        int linie[32] = {};
        linie[0] = linie[k - 1] = 1;
        for (int i = 1; i < k - 1; ++i)
            linie[i] = v[i - 1] + v[i];

        for (int i = 0; i < k; ++i)
            v[i] = linie[i];
    }
}

// Virusi
void subI_2(int n, int k, int &nrOre)
{
    nrOre = 0;
    while (n >= k)
    {
        if (n % 2 == 0)
        {
            ++nrOre;
            n /= 2;
        }
        else
        {
            ++nrOre;
            ++n;
        }
    }
}

// Produs maxim
void subI_3(int n, int v[10000], int &a, int &b, int &c)
{
    // ordonam sirul in mod descrescator
    int j, tmp;
    for (int i = 1; i < n; ++i)
    {
        j = i - 1;
        tmp = v[i];
        while (j >= 0 && tmp > v[j])
        {
            v[j + 1] = v[j];
            --j;
        }

        v[j + 1] = tmp;
    }

    a = v[2];
    b = v[1];
    c = v[0];

    if (v[n - 1] * v[n - 2] > b * c)
    {
        b = v[n - 2];
        c = v[n - 1];
    }
}

int main()
{
    int r, v[32] = {};
    cin >> r;
    ++r;
    subI_1(r, v);
    for (int i = 0; i < r; ++i)
        cout << v[i] << ' ';


    /*
    int n, k, nrOre;
    cin >> n >> k;
    subI_2(n, k, nrOre);
    cout << nrOre;
    */

    /*
    int n, v[10000], a, b, c;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    subI_3(n, v, a, b, c);
    cout << a << ' ' << b << ' ' << c;
    */

    return 0;
}

