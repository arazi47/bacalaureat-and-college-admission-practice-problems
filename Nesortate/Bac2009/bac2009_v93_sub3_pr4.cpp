// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_093.pdf
// Problema 4

#include <iostream>

using namespace std;

int dcm(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

// Nu stiu cum se face
int main()
{
    int a, b;
    cin >> a >> b;
    cout << dcm(a, b);

    return 0;
}
