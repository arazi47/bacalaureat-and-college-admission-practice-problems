// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_011.pdf
// Problema 4

#include <iostream>

using namespace std;

// Varianta eficienta
int sumaDiv(int n)
{
    int s = 0;
    int d;

    for (d = 1; d * d < n; ++d)
        if (n % d == 0)
        {
            s += d;
            s += (n / d);
        }

    if (d * d == n)
        s += d;

    return s;
}

int sumaDivIneficient(int n)
{
    int s = n;
    for (int d = 1; d <= (n / 2); ++d)
        if (n % d == 0)
            s += d;

    return s;
}

// ex:
// n = 5
// v[] = 12 3 9 7 1
int main()
{
    int n, val;
    cin >> n;
    int cntPrime = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        if (sumaDiv(val) == val + 1)
            ++cntPrime;
    }

    cout << cntPrime;

    return 0;
}

