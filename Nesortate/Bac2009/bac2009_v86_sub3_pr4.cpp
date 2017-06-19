// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_086.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    ifstream f("bac.txt");
    int max1 = -1, max2 = -1;
    while (f >> n)
    {
        if (!(n % 2))
        {
            if (max1 == -1)
                max1 = n;
            else if (max2 == -1)
                max2 = n;
            else if (n > max1)
            {
                max2 = max1;
                max1 = n;
            }

            if (max1 != -1 && max2 != -1 && max2 > max1)
            {
                int t = max1;
                max1 = max2;
                max2 = t;
            }
        }
    }

    cout << max1 << ' ' << max2;

    return 0;
}
