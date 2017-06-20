// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_092.pdf
// Problema 4

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    ofstream g("sir.txt");
    for (char i = 'A'; i <= 'Y'; ++i)
        for (char j = i + 1; j <= 'Z'; ++j)
            if (!(strchr("AEIOU", i) && strchr("AEIOU", j)))
                g << i << j << endl;

    return 0;
}
