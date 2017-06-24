// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_009.pdf

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    bool v[999 + 1] = {};
    int n;

    ifstream f("bac.txt");
    while (f >> n)
    {
    	if (n >= 100 && n <= 999)
    	{
    		if (!v[n])
    			v[n] = true;
    	}
    }

    int cnt = 0;
   	for (int i = 999; i >= 100 && cnt < 2; --i)
   	{
   		if (!v[i])
   		{
   			cout << i << ' ';
   			++cnt;
   		}
   	}

    return 0;
}

