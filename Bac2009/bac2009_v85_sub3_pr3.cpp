// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_085.pdf
// Problema 3

#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    int sumPare = 0, cntPare = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (!(x  % 2))
        {
            sumPare += x;
            ++cntPare;
        }
    }

    int ma = sumPare / cntPare;
    int rez = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (x < ma)
            rez += x;
    }

    cout << rez;

    return 0;
}
