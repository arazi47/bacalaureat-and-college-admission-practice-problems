// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_053.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.txt");
    int n, v[100];
    f >> n;
    for (int i = 0; i < n; ++i)
        f >> v[i];

    cout << n << endl;

    int pe; // primul element
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
            cout << v[i] << ' ';

        cout << endl;

        pe = v[0];
        for (int i = 0; i < n - 1; ++i)
            v[i] = v[i + 1];

        v[n - 1] = pe;
    }

    return 0;
}
