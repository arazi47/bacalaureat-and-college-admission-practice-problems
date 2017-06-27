// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_014.pdf

#include <iostream>

using namespace std;

int main()
{
    int v[10] = {}, n, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        ++v[x];
    }

    for (int i = 0; i < 10; ++i)
    {
        while (v[i])
        {
            cout << i << ' ';
            --v[i];
        }
    }

    return 0;
}

