// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_100.pdf
// Problema 3

#include <iostream>

using namespace std;

int divizor(int a, int b, int c)
{
    if (a > b)
    {
        int t = a;
        a = b;
        b = t;
    }

    if (a > c)
    {
        int t = a;
        a = c;
        c = t;
    }

    if (b > c)
    {
        int t = b;
        b = c;
        c = t;
    }

    int cnt = 0;
    for (int d = 1; d <= a; ++d)
        if (a % d == 0 && b % d == 0 && c % d == 0)
            ++cnt;

    return cnt;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << divizor(a, b, c);

    return 0;
}
