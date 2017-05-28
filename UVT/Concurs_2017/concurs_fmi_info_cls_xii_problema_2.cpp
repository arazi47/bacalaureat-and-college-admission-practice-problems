// https://drive.google.com/file/d/0B0NnkrRhUimbcFFmM05yT21QOFk/view
// Problema 2

#include <iostream>

using namespace std;

void gaseste(int n, int v[], int st)
{
    if (v[st] == -1)
        return;

    int el = v[st];
    v[st] = -1;
    cout << el << ' ';
    for (int i = st + 1; i < n; ++i)
        if (v[i] > el && v[i] != -1) // v[i] != -1 nu trebuie
        {
            cout << v[i] << ' ';
            el = v[i];
            v[i] = -1;
        }

    cout << '\n';
}

// ex: 7 13 4 21 16 18 5 3
int main()
{
    int n, v[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n; ++i)
        gaseste(n, v, i);

    return 0;
}
