// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_008.pdf

#include <iostream>

using namespace std;

int main()
{
    int n, a[100], m, b[100], prevnum = -1;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    int x1 = 0, x2 = 0;
    while (x1 < n && x2 < m)
    {
        if (a[x1] < b[x2])
        {
            // primul numar
            if (prevnum == -1)
            {
                cout << a[x1] << ' ';
                prevnum = a[x1];
                ++x1;
          	}
          	// numarul curent si cel anterior nu au aceeasi paritate
          	else if (!(a[x1] % 2 && prevnum % 2) &&
          			 !(a[x1] % 2 == 0 && prevnum % 2 == 0))
          	{
          		cout << a[x1] << ' ';
          		prevnum = a[x1];
   				++x1;
         	}
         	// sarim peste numar
         	else
                ++x1;
        }
        else
        {
        	if (prevnum == -1)
        	{
        		cout << b[x2] << ' ';
        		prevnum = b[x2];
        		++x2;
        	}
        	else if (!(b[x2] % 2 && prevnum % 2) &&
          			 !(b[x2] % 2 == 0 && prevnum % 2 == 0))
        	{
        		cout << b[x2] << ' ';
        		prevnum = b[x2];
        		++x2;
        	}
        	else
                ++x2;
        }
    }

    // desi numerele dintr-un sir s-au terminat toate
    // mai este loc pentru un numar
    if (n > m)
    	cout << a[x1];
    else if (n < m)
    	cout << b[x2];


    return 0;
}

