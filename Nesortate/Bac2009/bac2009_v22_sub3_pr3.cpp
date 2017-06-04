// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_022.pdf
// Problema 3

#include <iostream>

using namespace std;

// returneaza numarul de zerouri de la sfarsitul numarului n! (n factorial)
int nrZero(int n)
{
    int t, cnt = 0;
    for (int i = 5; i <= n; i += 5)
    {
        t = i;
        while (t % 5 == 0)
        {
            ++cnt;
            t /= 5;
        }
    }

    return cnt;
}

int main()
{
    int k;
    cin >> k;
    int nr = 5;
    while (nrZero(nr) < k)
        nr += 5;

    cout << nr;

    return 0;
}

