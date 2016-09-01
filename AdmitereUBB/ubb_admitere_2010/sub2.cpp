// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2010-informatica.pdf

#include <iostream>

using namespace std;

// Daca e definita urmatoarea variabila, divizorii proprii
// nu vor fi scazuti din rezultatul final
#define DIVIZORI_PROPRII
void SumaDivizorilor()
{
    int suma = 1, n, copie;
    cin >> n;
    copie = n; // Vom modifica n-ul

	for(int k = 2; k * k <= n; ++k)
	{
		int p = 1;
		while(n % k == 0)
		{
			p = p * k + 1;
			n /= k;
		}

		suma *= p;
	}

	if(n > 1)
		suma *= 1 + n;

#ifndef DIVIZORI_PROPRII
    // Scadem divizorii proprii
    suma = suma - 1 - copie;
#endif

	cout << suma;
}

// a) Pentru n = 1, se afiseaza 0; pentru n = 10, se afiseaza 7
// b) pentru(k = 2, n, 1) - k = 2, k se incrementeaza cu 1 pana la n
// c) Varianta optimizata a algoritmului: @todo (uita-te la functia de mai sus)

void SubII()
{
    int n, s = 0, k = 2;
    cin >> n;

    while (k < n)
    {
        if (n % k == 0)
            s += k;
        ++k;
    }

    cout << s;
}

int main()
{
    //SubII();
    SumaDivizorilor();
    return 0;
}
