// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_069.pdf
// Problema 3

#include <iostream>

using namespace std;

int calcul(int n)
{
    int pare = 0, impare = 0;
    while (n)
    {
        if ((n % 10) % 2)
            ++impare;
        else
            ++pare;

        n /= 10;
    }

    if (pare >= impare)
        return pare - impare;
    else
        return impare - pare;
}

int main()
{
    int n;
    cin >> n;
    int m = n + 1;
    while (calcul(m))
        ++m;

    cout << m;

    return 0;
}
