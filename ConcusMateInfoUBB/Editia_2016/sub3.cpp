// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2016.pdf

#include <iostream>

using namespace std;

#define MAX 1000

void citire(int &n, int a[MAX])
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

bool palindrom(int n, int a[MAX])
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] != a[j])
            return false;

        ++i;
        --j;
    }

    return true;
}

int determinaPermutari(int n, int a[MAX])
{
    int nrPerm = 0;
    while (!palindrom(n, a) && nrPerm <= n)
    {
        ++nrPerm;

        // primul element
        int pe = a[0];
        for (int i = 0; i < n - 1; ++i)
            a[i] = a[i + 1];

        a[n - 1] = pe;
    }

    return nrPerm > n ? -1 : nrPerm;
}

void afiseaza(int nrPerm)
{
    if (nrPerm == -1)
        cout << "Nu";
    else
        cout << "Da. Sunt necesare " << nrPerm << " permutari.";
}

int main()
{
    int n, a[MAX];
    citire(n, a);
    int nrPerm = determinaPermutari(n, a);
    afiseaza(nrPerm);

    return 0;
}

