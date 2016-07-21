// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2015-iulie-informatica.pdf

#include <iostream>

using namespace std;

int subI_B(int n)
{
    int n2 = n;
    int mult = 1;
    int cnt = 1; // cate cifre are numarul; incepem de la 1 pentru ca in while am scris n2 > 9
    int _max = 0;

    while (n2 > 9)
    {
        mult *= 10;
        ++cnt;
        n2 /= 10;
    }

    for (int i = 0; i < cnt; ++i)
    {
        n = (n % mult) * 10 + n / mult;

        if (n > _max)
            _max = n;
    }

    return _max;
}

int main()
{
    return 0;
}
