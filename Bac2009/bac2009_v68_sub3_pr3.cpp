// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_068.pdf
// Problema 3

#include <iostream>

using namespace std;

int calcul(int n, int k)
{
    int c = n, nrcif = 0;
    while (c)
    {
        ++nrcif;
        c /= 10;
    }

    if (k > nrcif)
        return -1;

    int cnt = 1;
    while (cnt < k)
    {
        n /= 10;
        ++cnt;
    }

     return n % 10;
}

int main()
{
    int n, nrcif = 0;
    cin >> n;
    int c = n;
    while (c)
    {
        ++nrcif;
        c /= 10;
    }

    bool conditie = true;
    for (int i = 1; i <= nrcif; ++i)
        if (i < calcul(n, i))
        {
            conditie = false;
            break;
        }

    if (conditie)
        cout << "Da";
    else
        cout << "Nu";

    return 0;
}
