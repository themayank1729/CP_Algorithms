#include <bits/stdc++.h>
using namespace std;
void printBinary(int num)
{

    for (int i = 30; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << "\n";
}
int main()
{
    int a = 10;
    printBinary(a);

    int i = 2;
    // to check if above i'th bit is set or not
    if (a & (1 << i))
    {
        cout << i << " bit is set in ";
        printBinary(a);
    }
    else
    {
        cout << i << " bit is not set in ";
        printBinary(a);
    }
    cout << "*************************************************\n";
    // how to set a given i'th bit
    i = 5;
    printBinary((a | (1 << i)));
    // how to unset i'th bit in a=10
    i = 3;
    printBinary(a & (~(1 << i)));
    // how to toggle a bit, if it is 1 make it 0 and vice versa
    i = 8;
    printBinary(a ^ (1 << i));
    // how to count number of set bits in binary number
    int count = 0;
    a = 15;
    for (int i = 0; i <= 31; i++)
    {
        if (a & (1 << i))
            count++;
    }
    cout << count;
}
#include <bits/stdc++.h>
using namespace std;
void printBinary(int num)
{

    for (int i = 30; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << "\n";
}
int main()
{
    int a = 10;
    printBinary(a);

    int i = 2;
    // to check if above i'th bit is set or not
    if (a & (1 << i))
    {
        cout << i << " bit is set in ";
        printBinary(a);
    }
    else
    {
        cout << i << " bit is not set in ";
        printBinary(a);
    }
    cout << "*************************************************\n";
    // how to set a given i'th bit
    i = 5;
    printBinary((a | (1 << i)));
    // how to unset i'th bit in a=10
    i = 3;
    printBinary(a & (~(1 << i)));
    // how to toggle a bit, if it is 1 make it 0 and vice versa
    i = 8;
    printBinary(a ^ (1 << i));
    // how to count number of set bits in binary number
    int count = 0;
    a = 15;
    for (int i = 0; i <= 31; i++)
    {
        if (a & (1 << i))
            count++;
    }
    cout << count;
}