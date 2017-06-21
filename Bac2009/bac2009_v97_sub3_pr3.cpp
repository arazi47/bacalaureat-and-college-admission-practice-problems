// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_097.pdf
// Problema 3

#include <iostream>

using namespace std;

int v[51];

void Calcul(int k, int &S)
{
    S = 0;
    for (int i = k; i <= 50; ++i)
        if (v[i] > 0)
            S += v[i];
}

int main()
{
    int x, y;
    cin >> x >> y;

    int s2, s1;
    Calcul(x, s1);
    Calcul(y, s2);

    cout << s2 - s1;

    return 0;
}
