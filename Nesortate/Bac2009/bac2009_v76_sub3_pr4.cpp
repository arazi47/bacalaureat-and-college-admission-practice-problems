// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_076.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int cautareBinara(int n, int v[], int val)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] == val)
            return mid;
        else if (v[mid] < val)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    ifstream f("bac.txt");
    int m, n, v[1000];
    f >> m >> n;

    // citim primul sir
    for (int i = 0; i < m; ++i)
        f >> v[i];

    // citim al doilea sir
    // nici nu-l mai bagam intr-un vector
    while (f >> n)
    {
        if (cautareBinara(m, v, n) != -1)
            cout << n << ' ';
    }

    return 0;
}
