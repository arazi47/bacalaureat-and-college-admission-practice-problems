// https://drive.google.com/file/d/0B0NnkrRhUimbU0Ntb3IyYnhGVkk/view
// Problema 4

#include <iostream>

using namespace std;

void histograma(int n, int A[51][51], int H[256])
{
    for (int i = 0; i < 256; ++i)
        H[i] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ++H[A[i][j]];
}

int nivelMediuDeGri(int n, int A[51][51], int H[256])
{
    int prod = 0;
    int suma = 0;
    for (int i = 0; i < 256; ++i)
    {
        prod += (H[i] * i);
        suma += H[i];
    }
    prod /= suma;

    return prod;
}

void construiesteB(int n, int A[51][51], int B[51][51], int NMG)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (A[i][j] >= NMG)
                B[i][j] = 1;
            else
                B[i][j] = 0;
}

int main()
{
    int n, A[51][51];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];

    int H[256];
    histograma(n, A, H);

    int NMG = nivelMediuDeGri(n, A, H);

    int B[51][51];
    construiesteB(n, A, B, NMG);
    cout << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << B[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
