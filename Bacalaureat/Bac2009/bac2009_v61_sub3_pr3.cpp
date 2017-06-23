// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_061.pdf
// Problema 3

#include <iostream>

using namespace std;

void cifra(float x, int &y)
{
    y = x;
    y %= 10;
}

int main()
{
    float n1, n2;
    int i1, i2;

    cin >> n1 >> n2;
    cifra(n1, i1);
    cifra(n2, i2);

    if (i1 == i2)
        cout << "Da";
    else
        cout << "Nu";

    return 0;
}
