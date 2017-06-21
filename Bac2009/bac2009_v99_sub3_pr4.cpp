// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_099.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n = 0, v[10000], x;
    ifstream f("date.txt");
    while (f >> x)
        v[n++] = x;

    int imax = 0, jmax = 0, ist = 0, jfin = 0;
    bool trebuiePar = false;
    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i] % 2)
            trebuiePar = true;
        else
            trebuiePar = false;

            ist = i;
            jfin = i + 1;
            while (true)
            {
                if (trebuiePar)
                {
                    if (v[jfin] % 2 != 0)
                        break;
                    else
                        ++jfin;
                    trebuiePar = !trebuiePar;
                }
                else
                {
                    if (v[jfin] % 2 == 0)
                        break;
                    else
                        ++jfin;
                    trebuiePar = !trebuiePar;
                }

                if (jfin - ist > jmax - imax)
                {
                    imax = ist;
                    jmax = jfin;
                }

                i = jfin;
            }
    }

    cout << jmax - imax << endl;
    for (int i = imax; i < jmax; ++i)
        cout << v[i] << ' ';

    return 0;
}

