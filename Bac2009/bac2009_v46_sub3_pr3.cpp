// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_046.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

bool areCelPutinKDivizori(int n, int k)
{
    int cnt = 0, d;
    for (d = 1; d * d < n; ++d)
        if (n % d == 0)
        {
            cnt += 2;
            if (cnt >= k)
                return true;
        }

    if (d * d == n)
        ++cnt;

    return cnt >= k;
}

int main()
{
    ifstream f("bac.txt");
    int n, k;
    cin >> k;
    // numarul de numere ce vor fi citite
    f >> n;
    int m = 0, v[100];
    while (f >> n)
    {
        if (areCelPutinKDivizori(n, k))
            v[m++] = n;
    }

    for (int i = 0; i < m; ++i)
        cout << v[i] << ' ';

    return 0;
}
