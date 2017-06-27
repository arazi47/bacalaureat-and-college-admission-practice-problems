// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_016.pdf

#include <iostream>

using namespace std;

int multiplu(int a[100], int n, int k)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] % k == 0 && a[i] % 10 == k)
            ++cnt;
    }

    return cnt;
}

int main()
{
    int n, a[100], k;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> k;

    cout << multiplu(a, n, k);

    return 0;
}

