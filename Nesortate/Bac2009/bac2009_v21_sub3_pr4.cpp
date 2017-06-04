// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_021.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.txt");

    int n, k, v[10000];
    f >> n >> k;
    int sum = 0;
    // calculam suma primelor k cifre
    for (int i = 0; i < k; ++i)
    {
        f >> v[i];
        sum += v[i];
    }

    int imax = 0, summax = sum, i = 0;
    for (int j = k; j < n; ++j)
    {
        f >> v[j];
        // scoatem primul termen si il bagam pe al patrulea in suma
        // apoi scoatem al doilea termen si il bagam pe al cincilea
        // si tot asa
        sum = sum - v[i] + v[j];
        ++i;
        if (sum > summax)
        {
            summax = sum;
            imax = i;
        }
    }

    // + 1 pentru ca am inceput indexarea de la 0
    cout << imax + 1;

    return 0;
}

