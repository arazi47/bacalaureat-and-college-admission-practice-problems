// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2010-informatica.pdf

#include <iostream>

using namespace std;

// a) Pentru n = 1, se afiseaza 0; pentru n = 10, se afiseaza 7
// b) pentru(k = 2, n, 1) - k = 2, k se incrementeaza cu 1 pana la n
// c) Varianta optimizata a algoritmului

// subpunctul c
int SubIIEficient(int n)
{
    int sum = 0;
    for (int d = 2; d * d <= n; ++d)
    {
        if (n % d == 0)
        {
            sum += d;

            if (n / d != d)
                sum += (n / d);
        }
    }

    return sum;
}

int SubII(int n)
{
    int s = 0, k = 2;
    while (k < n)
    {
        if (n % k == 0)
            s += k;
        ++k;
    }

    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << SubII(n) << ' ' << SubIIEficient(n);

    return 0;
}

