// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_047.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.txt");
    int k;
    cin >> k;
    int n;
    f >> n;
    while (f >> n)
    {
        if (n == 1)
            cout << n << ' ';
        else
        {
            int nr = 1;
            while (nr < n)
            {
                nr *= 2;
                if (nr == n)
                    cout << n << ' ';
                else if (nr > n)
                    break;
            }
        }
    }

    return 0;
}
