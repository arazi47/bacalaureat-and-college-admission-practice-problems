// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_054.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n, v[100];
    ifstream f("date.in");
    f >> n;
    for (int i = 0; i < n; ++i)
        f >> v[i];

    int cnt = 0;
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                if (v[i] + v[j] == v[k])
                {
                    cout << v[i] << " + " << v[j] << " = " << v[k] << endl;
                    ++cnt;
                }
    }

    cout << cnt;

    return 0;
}
