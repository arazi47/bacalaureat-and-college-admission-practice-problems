// https://drive.google.com/file/d/0B0NnkrRhUimbcFFmM05yT21QOFk/view
// Problema 4

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[256];
    cin >> s;
    int n = strlen(s) + 1;
    int v[256];

    for (int i = 1; i <= n; ++i)
        v[i] = i;

    int l = 0; // pentru parcurgerea sirului de caractere
    int a[256], k = 1; // vectorul final
    int i = 1, j = n;

    while (l < n)
    {
        if (s[l] == '<')
            a[k++] = v[i++];
        // Daca scriem else if... se strica
        else //if (s[l] == '>')
            a[k++] = v[j--];

        ++l;
    }

    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ' << s[i - 1] << ' ';


    /*
    int n, v[101];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int a[101];

    int i = 0, j = n - 1, k = 0;
    while (i <= j)
    {
        a[k++] = v[i++];
        a[k++] = v[j--];
    }

    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    */


    return 0;
}
