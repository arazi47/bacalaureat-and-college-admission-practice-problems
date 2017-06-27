// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_014.pdf

#include <iostream>
#include <fstream>

using namespace std;

int sumCif(int n)
{
    int s = 0;
    while (n)
    {
        s += (n % 10);
        n /= 10;
    }

    return s;
}

int main()
{
    ifstream f("bac.txt");
    int x, cnt = 0, cntSumCifPara = 0;
    while (f >> x)
    {
        if (sumCif(x) % 2 == 0)
            ++cntSumCifPara;

        cout << x << ' ';
        ++cnt;

        if (cnt == 5)
        {
            cnt = 0;
            cout << endl;
        }
    }

    // Sa nu punem de doua ori endl :D
    if (cnt != 0)
        cout << endl;

    cout << cntSumCifPara;

    return 0;
}

