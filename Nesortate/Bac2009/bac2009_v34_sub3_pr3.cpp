// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_034.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

int max(int x[], int n)
{
    if (x[0] > x[n - 1])
        return x[0];
    else
        return x[n - 1];
}

int main()
{
    int n, x[100];
    ifstream f("numere.txt");
    f >> n;
    int termenMax = -9999; // numarul maxim intreg de 4 cifre
    bool progresie;
    for (int k = 0; k < n; ++k)
    {
        progresie = true;
        for (int i = 0; i < n; ++i)
            f >> x[i];


        for (int i = 1; i < n - 1; ++i)
            if (x[i] != (x[i - 1] + x[i + 1]) / 2)
            {
                progresie = false;
                break;
            }

        if (progresie && max(x, n) > termenMax)
            termenMax = max(x, n);
    }

    cout << termenMax;

    return 0;
}
