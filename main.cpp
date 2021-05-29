#include <iostream>
#include "SortBucketList.h"

using namespace std;

double fastExponent(int, int, int);

int main()
{
    cout << "** RadixSort / CountingSort ** " << endl << endl;

    cout << "Enter the number of elements in your list: ";
    int sz;
    cin >> sz;

    SortBucketList sortbucket(sz);
    int max = 0;

    for(int temp, a = 0; a < sz; a++)
    {
        cout << "Enter element # " << a+1 << ": ";
        cin >> temp;

        sortbucket.insertElement(temp);
    }

    int digits = 0;
    for(int temp = max; temp > 0; temp /= 10)
        digits++;

    cout << "Testing digits: " << digits << endl << endl;

    for(int exponent = 0; exponent < digits; exponent++)
    {
        CountSort(arr, sizeof(int), fastExponent(10, exponent, 1) );
        cout << endl << "Sorted Array: [" << arr[0];
        for(int i = 1; i < sz; i++)
            cout << ", " << arr[i];

        cout << endl;
    }

    cout << endl << "Sorted Array: [" << arr[0];
    for(int i = 1; i < sz; i++)
        cout << ", " << arr[i];

    cout << "]" << endl;

    return 0;
}

double fastExponent(double base, int exponent, int accumulator)
{
    if(exponent == 0)
        return accumulator;
    else if(exponent % 2 == 0)
        return fastExponent(base * base, exponent/2, accumulator);

    return fastExponent(base, exponent-1, base * accumulator);
}
