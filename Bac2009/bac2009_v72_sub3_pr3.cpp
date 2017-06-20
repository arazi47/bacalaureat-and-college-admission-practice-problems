// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_072.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

// Meh, am facut doar punctul b
int main()
{
    int k;
    cin >> k;

    int cnt = 0;
    for (int i = 1;; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            ++cnt;
            if (cnt == k)
            {
                cout << j;
                return 0;
            }
        }
    }

    return 0;
}
