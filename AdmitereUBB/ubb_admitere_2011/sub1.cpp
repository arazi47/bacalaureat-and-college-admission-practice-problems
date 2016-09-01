// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2011-informatica.pdf

#include <iostream>

using namespace std;

// Bubblesort
void SubI_C(int marime, int v[])
{
    int tmp;
    bool schimbare;

    do
    {
        schimbare = false;

        for (int i = 0; i < marime - 1; ++i)
            if (v[i] > v[i + 1])
            {
                tmp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tmp;

                schimbare = true;
            }
    } while (schimbare);
}

int main()
{
    return 0;
}
