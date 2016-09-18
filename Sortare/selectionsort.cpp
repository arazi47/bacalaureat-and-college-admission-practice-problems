#include <iostream>

using namespace std;

int main()
{
    const int n = 5;
    int v[n] = { 30, 50, 20, 10, 40 };
    int tmp;

    for (int i = 0; i < n - 1; ++i)
    {
        /// indexul celui mai mic element
        int indexMin = i;

        /// cauta cel mai mic element din sir
        for (int j = i + 1; j < n; ++j)
            if (v[j] < v[indexMin])
                indexMin = j;

        /// interschimbare
        tmp = v[i];
        v[i] = v[indexMin];
        v[indexMin] = tmp;
    }

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';

    return 0;
}
