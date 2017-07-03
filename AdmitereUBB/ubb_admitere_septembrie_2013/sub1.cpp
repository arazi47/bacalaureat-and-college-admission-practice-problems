// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2013-septembrie-informatica.pdf

#include <iostream>

using namespace std;

void subI_B(int n, int v[])
{
    int j, tmp;
    for (int i = 1; i < n; ++i)
    {
        j = i - 1;
        tmp = v[i];
        while (j >= 0 && tmp < v[j])
        {
            v[j + 1] = v[j];
            --j;
        }

        v[j + 1] = tmp;
    }
}

int subI_C(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    // Subiectul I, b
    /*
    int n, v[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    subI_B(n, v);

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';
    */

    // Subiectul I, c
    /*
    int a, b;
    cin >> a >> b;
    cout << subI_C(a, b);
    */

    return 0;
}

