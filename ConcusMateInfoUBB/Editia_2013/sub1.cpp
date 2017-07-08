// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-2013.pdf

#include <iostream>

using namespace std;

// ordonarea sirului v in mod crescator prin metoda bulelor
void subI_B(int n, int v[])
{
    bool schimbare;
    do
    {
        schimbare = false;
        for (int i = 0; i < n- 1; ++i)
            if (v[i] > v[i + 1])
            {
                int t = v[i];
                v[i] = v[i + 1];
                v[i + 1] = t;

                schimbare = true;
            }
    } while (schimbare);
}

// verifica daca numerele a si b sunt prime intre ele
// adica, cel mai mare divizor comun al lor este 1
bool subI_C(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    // daca cmmdc este 1, atunci numerele sunt prime intre ele
    return a == 1;
}

int main()
{
    /*
    int n = 5, v[5];
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    subI_B(n, v);
    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';
    */

    int a, b;
    cin >> a >> b;
    cout << subI_C(a, b);

    return 0;
}

