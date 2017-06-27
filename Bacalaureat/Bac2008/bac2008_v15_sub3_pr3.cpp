// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_015.pdf

#include <iostream>

using namespace std;

int nrDiv(int n)
{
    if (n == 1 || n == 2)
        return n;

    int nrd = 2;
    for (int d = 2; d <= n / 2; ++d)
        if (n % d == 0)
            ++nrd;

    return nrd;
}

int main()
{
    int n;
    cin >> n;
    int max = 1;
    for (int i = 2; i <= n; ++i)
        if (nrDiv(i) > nrDiv(max))
            max = i;

    cout << max;

    return 0;
}

