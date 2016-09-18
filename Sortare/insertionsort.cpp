#include <iostream>

using namespace std;

int v[100];
int n; // size

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int j, tmp;

    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        tmp = v[i];

        while (j >= 0 && tmp < v[j])
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = tmp;
    }

    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';

    return 0;
}
