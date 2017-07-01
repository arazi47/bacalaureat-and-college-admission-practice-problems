#include <iostream>

using namespace std;

void duplicare(int &n)
{
    int r = 0, p = 1, uc;

    while (n)
    {
        uc = n % 10;

        if (uc % 2 == 0)
        {
            r = r + p * (uc / 2);
            p *= 10;
        }

        r = r + p * uc;
        p *= 10;

        n /= 10;
    }

    n = r;
}

int main()
{
    int n;
    cin >> n;
    duplicare(n);
    cout << n;

    return 0;
}

