// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_013.pdf

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int nivel = 1, cnt = 0, nr;
	while (cnt < n)
	{
        nr = nivel;
        while (nr)
        {
            ++cnt;

            if (cnt == n)
                break;

            --nr;
        }
        ++nivel;
	}

    cout << nr;

	return 0;
}

