// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_087.pdf
// Problema 3

#include <iostream>

using namespace std;

int reduce(int a, int b)
{
    int s = 0;
    while (a)
    {
        if (a % 10 != 0)
        {
            if (b % (a % 10) != 0)
                s += a % 10;
        }
        a /= 10;
    }

    return s;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << reduce(a, b);

    return 0;
}
