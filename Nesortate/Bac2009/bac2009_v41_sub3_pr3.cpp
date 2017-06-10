// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_041.pdf
// Problema 3

#include <iostream>

using namespace std;

bool DIST(int a[100], int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            if (a[i] == a[j])
                return false;
            else
            {
                if (a[i] > a[j])
                {
                    if (a[i] - a[j] == 1)
                        return false;
                }
                else
                {
                    if (a[j] - a[i] == 1)
                        return false;
                }
            }
        }

    return true;
}

int main()
{
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << DIST(a, n);

    return 0;
}
