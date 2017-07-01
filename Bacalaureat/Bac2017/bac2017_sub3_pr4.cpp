#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // secv - lungimea secventei curente
    // secvmax - lungimea secventei maxime
    // num - numarul secventelor de lungime maxima
    // x - variabila in care se va citi fiecare element al sirului
    int secv = 0, secvmax = 0, num = 0, x;
    ifstream f("bac.txt");

    while (f >> x)
    {
        if (x % 2 == 0)
            ++secv;
        else
            secv = 0;

        // secv >= 2, pentru ca o secventa are minim 2 elemente
        if (secv > secvmax && secv >= 2)
        {
            secvmax = secv;
            num = 1;
        }
        else if (secv == secvmax && secv >= 2)
            ++num;
    }

    cout << num;

    return 0;
}

