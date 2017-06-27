// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_012.pdf

#include <iostream>
#include <fstream>

using namespace std;

void insereazaCrescator(int &n, int v[200], int x)
{
	int j = n - 1;
	while (j >= 0 && x < v[j])
	{
		v[j + 1] = v[j];
		--j;
	}

	v[j + 1] = x;
	++n;
}

int main()
{
    ifstream f1("nr1.txt");
    ifstream f2("nr2.txt");
    int a[100], n = 0, b[100], m = 0, x;

    while (f1 >> x)
    {
    	if (!(x % 5))
    		a[n++] = x;
    }

    while (f2 >> x)
    {
    	if (!(x % 5))
    		b[m++] = x;
    }

    int c[200], k = 0;
    bool insereazaElementul;
    for (int i = 0; i < n; ++i)
    {
    	insereazaElementul = true;
    	for (int j = 0; j < m; ++j)
    	{
    		if (a[i] == b[j])
    		{
    			insereazaElementul = false;
    			break;
    		}
    	}

    	if (insereazaElementul)
    		insereazaCrescator(k, c, a[i]);
    }

    for (int i = 0; i < m; ++i)
    {
    	insereazaElementul = true;
    	for (int j = 0; j < n; ++j)
    	{
    		if (b[i] == a[j])
    		{
    			insereazaElementul = false;
    			break;
    		}
    	}

    	if (insereazaElementul)
    		insereazaCrescator(k, c, b[i]);
    }

    for (int i = 0; i < k; ++i)
    	cout << c[i] << ' ';

    return 0;
}

