// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_024.pdf
// Problema 3

#include <iostream>
#include <iomanip>

using namespace std;

void p(int n, int x[100], int &mini, int &maxi, int &sum)
{
    mini = maxi = sum = x[0];
    for (int i = 1; i < n; ++i)
    {
        if (x[i] < mini)
            mini = x[i];
        if (x[i] > maxi)
            maxi = x[i];
        sum += x[i];
    }
}


int main()
{
    int n, x[100], mini, maxi, sum;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    p(n, x, mini, maxi, sum);

    sum -= (mini + maxi);
    float ma = (float) sum / (n - 2);
    cout << fixed << setprecision(3) << ma;

    return 0;
}

