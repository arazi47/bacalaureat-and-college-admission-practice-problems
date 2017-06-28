// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_023.pdf

#include <iostream>
#include <fstream>

using namespace std;

struct interval
{
    int a, b;
};

bool valid(int a1, int b1, int a2, int b2)
{
    if (a1 < a2 && b1 < b2)
    {
        swap(a1, a2);
        swap(b1, b2);
    }

    if (b2 >= a1 && b2 <= b1)
        return false;
    else if (a2 >= a1 && a2 <= b1)
        return false;

    return true;
}

int main()
{
    ifstream f("bac.txt");
    int n;
    interval x[1000];
    f >> n;
    for (int i = 0; i < n; ++i)
    {
        f >> x[i].a;
        f >> x[i].b;
        ++i;
    }

    for (int i = 0; i < n; ++i)
    {
        bool afiseaza = true;
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;

            if (!valid(x[i].a, x[i].b, x[j].a, x[j].b))
            {
                afiseaza = false;
                break;
            }
        }

        if (afiseaza)
            cout << x[i].a << ' ' << x[i].b << endl;
    }

    return 0;
}

