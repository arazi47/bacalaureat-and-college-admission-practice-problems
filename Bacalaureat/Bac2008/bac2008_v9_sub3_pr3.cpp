// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_009.pdf

#include <iostream>

using namespace std;

void sub(int n, int k)
{
	while (n)
	{
		cout << n * k << ' ';
		--n;
	}
}

int main()
{
    int n, k;
    cin >> n >> k;
    sub(n, k);

    return 0;
}

