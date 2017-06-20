// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_013.pdf
// Problema 3

#include <iostream>

using namespace std;

// sir:
// 1, 2 1, 3 2 1...
// Afiseaza al n-lea element al sirului dat
int main()
{
    int n;
    cin >> n;
    int cntElem = 0;
    int nivel = 1;
    int element = 1;
    while (cntElem < n)
    {
        element = nivel;
        while (element > 1)
        {
            --element;
            ++cntElem;
            if (cntElem == n)
                break;
        }
        ++nivel;
    }

    cout << element;

    return 0;
}

