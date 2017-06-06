// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_039.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n, v[1000];
    ifstream f("bac.in");
    f >> n;
    int x;
    int prev = 0;
    for (int i = 0; i < n; ++i)
    {
        f >> x;
        if (x % 2 == 0 && x > prev)
            prev = x;
        else if (x % 2 == 0 && x <= prev)
        {
            cout << "NU";
            return 0;
        }
    }

    cout << "DA";

    return 0;
}
