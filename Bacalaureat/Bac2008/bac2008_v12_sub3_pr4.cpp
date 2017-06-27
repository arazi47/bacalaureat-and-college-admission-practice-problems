// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_012.pdf

#include <iostream>

using namespace std;

bool areCifreleEgale(int n)
{
	if (n < 10)
		return true;

    int uc;
	do
	{
        uc = n % 10;
        n /= 10;

        if (uc != n % 10)
            return false;
	} while (n > 9);

    // verificam prima cu a doua cifra (de la stanga la dreapta)
	return n == uc;
}

int main()
{
	int n, x, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if (areCifreleEgale(x))
			++cnt;
	}

	cout << cnt;

	return 0;
}

