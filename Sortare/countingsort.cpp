#include <iostream>

using namespace std;

int v[100], vCopy[100], vIndex[100];
int n; // size

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        vCopy[i] = v[i];
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] > v[j])
                vIndex[i]++;
            else
                vIndex[j]++;

    for (int i = 0; i < n; i++)
        v[vIndex[i]] = vCopy[i];

    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';

    return 0;
}
