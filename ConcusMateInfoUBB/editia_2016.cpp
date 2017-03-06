// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2016.pdf

#include <iostream>

using namespace std;

int nrOre(int n, int k)
{
    if (n < k)
        return 0;

    if (n % 2 == 0)
        return 1 + nrOre(n / 2, k);
    else
        return 1 + nrOre(n + 1, k);
}

void gasesteMax(int n, int *x, int &a, int &b, int &c)
{
    int j, tmp;
    for (int i = 1; i < n; ++i)
    {
        j = i - 1;
        tmp = x[i];
        while (j >= 0 && tmp > x[j])
        {
            x[j + 1] = x[j];
            --j;
        }

        x[j + 1] = tmp;
    }

    a = x[0];
    b = x[1];
    c = x[2];
}

void citeste(int &n, int *a)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

bool palindrom(int n, int *a)
{
    for (int i = 0, j = n - 1; i < n && j >= 0; ++i, --j)
        if (a[i] != a[j])
            return false;

    return true;
}

int nrPermutari(int n, int *a)
{
    int cnt = 0;
    while (!palindrom(n, a))
    {
        ++cnt;
        if (cnt > n)
            return -1;

        int pe = a[0]; // primul element
        for (int i = 0; i < n - 1; ++i)
            a[i] = a[i + 1];
        a[n - 1] = pe;
    }

    return cnt;
}

void afiseaza(int n, int *a)
{
    int nrPerm = nrPermutari(n, a);
    if (nrPerm == -1)
        cout << "Nu";
    else
        cout << "Da, numarul de permutari ciclice este " << nrPerm;
}

int main()
{
    /*
    int n, v[100] = {};
    cin >> n;
    ++n; // liniile incep de la zero

    v[0] = 1;
    v[n - 1] = 1;
    for (int i = 1; i < n; ++i)
        triunghi(n, v);

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';
    */

    /*
    int n, k;
    cin >> n >> k;
    cout << nrOre(n, k);
    */

    /*
    int n, x[100], a, b, c;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    gasesteMax(n, x, a, b, c);
    cout << a << ' ' << b << ' ' << c;
    */

    int n, a[100];
    citeste(n, a);
    afiseaza(n, a);

    return 0;
}
