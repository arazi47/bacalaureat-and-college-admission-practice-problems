// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_051.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("date.in");
    int n, a[100];
    f >> n;
    for (int i = 0; i < n; ++i)
        f >> a[i];

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if ((a[i] % 2 && a[j] % 2) || (!(a[i] % 2 || a[j] % 2)))
                cout << a[i] << ' ' << a[j] << endl;

    return 0;
}
