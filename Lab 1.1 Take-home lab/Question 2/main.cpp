#include <iostream>
#include <cstdio>
using namespace std;

int main()
{

    int a, b;

    cin >> a;
    cin >> b;

    string numberName[9] =  {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if (a<=9 && b<=9)
    {
        for (int i=a; i<=b; i++)
            cout << numberName[i-1] << endl;
    }
    else if (a<=9 && b>9)
    {
        for (int i=a; i<=9; i++)
            cout << numberName[i-1] << endl;
        for (int j=10; j<=b; j++)
        {
            if (!(j%2))
                cout << "even" << endl;
            else
                cout << "odd" << endl;
        }
    }
    else
    {
        for (int i=a; i<=b; i++)
        {
            if (!(i%2))
                cout << "even" << endl;
            else
                cout << "odd" << endl;
        }
    }

    return 0;
}
