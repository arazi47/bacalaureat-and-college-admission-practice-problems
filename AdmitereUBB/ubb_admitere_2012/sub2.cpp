// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2012-informatica.pdf

#include <iostream>

using namespace std;

// a) Se afiseaza 2
// b) Se afiseaza -23
// c) Pentru 3 0 0 0 0 0 se afiseaza 0
void SubII()
{
    int n, x, v = 0, i = 0, a;
    cin >> n >> x;

    while (i <= n)
    {
        cin >> a;
        v = v * x + a;
        ++i;
    }
    cout << v;
}

int main()
{
    SubII();
    return 0;
}
