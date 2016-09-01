// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2011-informatica.pdf

#include <iostream>

using namespace std;

// a) Pentru valorile citite, se afiseaza 22222
// b) 2, 1, 1
void SubII()
{
    int n, s = 0, nr, x;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        nr = 1;
        cin >> x;
        while (x > 9)
        {
            nr = nr * 10;
            x = x / 10;
        }
        s = s + x * nr;
    }
    cout << s;
}

void SubII_C()
{
    int n, s = 0, nr, x;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        nr = 1;
        cin >> x;

        if (x > 9)
        {
            do
            {
                nr = nr * 10;
                x = x / 10;
            } while (x > 9); //! Aici ar trebui repeta...pana cand, insa in C++ nu avem asa ceva
        }
        s = s + x * nr;
    }
    cout << s;
}

int main()
{
    return 0;
}
