// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_011.pdf

#include <iostream>

using namespace std;

int sum(int x)
{
	if (x == 1)
		return 0;

	int sdiv = 1;
	for (int d = 2; d < (x / 2) + 1; ++d)
		if (x % d == 0)
			sdiv += d;

	return sdiv;
}

int main()
{
    int n, x, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
    	cin >> x;
    	if (sum(x) == 1)
    		++cnt;
    }

    cout << cnt;

    return 0;
}

