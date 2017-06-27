// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_018.pdf

#include <iostream>

using namespace std;

int count(float v[100], int n)
{
    int cnt = 0;
    float sum = 0;

    for (int i = 0; i < n; ++i)
        sum += v[i];

    sum /= n;

    for (int i = 0; i < n; ++i)
        if (v[i] >= sum)
            ++cnt;

    return cnt;
}

int main()
{
    int n;
    float v[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << count(v, n);

    return 0;
}

