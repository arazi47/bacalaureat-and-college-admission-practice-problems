// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_095.pdf
// Problema 4

#include <iostream>

using namespace std;

// Nu e metoda corecta, e foarte ineficienta
// Si nici nu merge pentru toate cazurile
int main()
{
    int S = 0;
    cin >> S;
    int a, b, c;
    int m1 = 0, m2 = 0, m3 = 0;
    for (a = 1; a <= 300-3; ++a)
        for (b = 1; b <= 300-3; ++b)
            for (c = 1; ; ++c)
            {
                if (a + b + c == S)
                {
                    if (a * b * c > m1 * m2 * m3)
                    {
                        m1 = a;
                        m2 = b;
                        m3 = c;
                    }
                }
                else if (a + b + c > S)
                    break;
            }

    cout << m1 << ' ' << m2 << ' ' << m3;

    return 0;
}
