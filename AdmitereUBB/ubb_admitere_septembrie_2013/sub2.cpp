// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2013-septembrie-informatica.pdf
#include <iostream>

using namespace std;

// a) Se afiseaza 13
// b) 4 9 9 9 9
// c) 3 52 1 0
void SubII()
{
    int n, v, a, x, s = 0;
    cin >> n >> v;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> a;
        x = a * v;
        while (x > 9)
            x /= 10;
        s += x;
        v = a;
    }
    cout << s;
}

int main()
{
    SubII();
    return 0;
}
