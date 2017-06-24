// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_010.pdf

#include <iostream>

using namespace std;

void sub(int n, int &a, int &b)
{
	--n;
	a = b = -1;
	bool prim;
	while (n > 1)
	{
		prim = true;
		if (n < 2)
			prim = false;
		if (n % 2 == 0 && n != 2)
			prim = false;
		for (int d = 3; d * d <= n; d += 2)
			if (n % d == 0)
			{
				prim = false;
				break;
			}

		if (prim && a == -1)
			a = n;
		else if (prim && b == -1)
		{
			b = n;
			break;
        }

        --n;
	}
}

int main()
{
    int n, a, b;
    cin >> n;
    sub(n, a, b);
    cout << a << ' ' << b;

    return 0;
}

