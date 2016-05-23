#include <iostream>

using namespace std;

bool prim(int x)
{
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0)
            return false;

    return true;
}

bool magic(int x)
{
    int x2 = x;
    int nr = 0;

    while (x2)
    {
        x2 /= 10;
        nr++;
    }

    int mult = 10;
    x2 = x;

    for (int i = 0; i < nr; i++)
    {
        if (!prim(x2))
            return false;

        x2 = x % mult;
        mult *= 10;
    }

    return true;

}

int main()
{
    int x;

    cin >> x;

    cout << magic(x);
}