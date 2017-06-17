// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_071.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

bool palindrom(int n)
{
    if (n % 10 == 0)
        return false;

    int m = 0;
    while (n)
    {
        m = m * 10 + n % 10;
        if (m == n)
            return true;
        n /= 10;
        if (m == n)
            return true;
        else if (m > n)
            return false;
    }

    return false;
}

int main()
{
    ifstream f("numere.in");
    int n;
    int palmax = -1;
    int cnt;
    while (f >> n)
    {
        if (palindrom(n))
        {
            if (palmax == -1)
            {
                palmax = n;
                cnt = 1;
            }
            else if (n > palmax)
            {
                palmax = n;
                cnt = 1;
            }
            else if (n == palmax)
                ++cnt;
        }
    }

    ofstream g("numere.out");
    g << palmax << endl << cnt;

    return 0;
}
