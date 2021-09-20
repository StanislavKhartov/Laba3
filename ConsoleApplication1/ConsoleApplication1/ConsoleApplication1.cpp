#include <iostream>
#include <algorithm>

#define MAX 100

using namespace std;

void printArray(double array[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Please enter number of members <" << MAX << endl;
    int n = 0;
    cin >> n;
    double array[MAX];
    int state = 0;
    cout << "If you want to fill array with random numbers, enter 1, else enter 2\n";
    cin >> state;
    switch (state)
    {
    case 1:
        cout << "Please enter the lower bound and upper bound of random numbers\n";
        int lower_bound;
        int upper_bound;
        cin >> lower_bound;
        cin >> upper_bound;
        if (upper_bound < lower_bound)
        {
            cout << "wrong data\n";
            return 1;
        }
        for (int i = 0; i < n; i++)
        {
            array[i] = (rand() % (upper_bound - lower_bound + 1) + lower_bound);
        }
        break;
    case 2:
        cout << "PLease enter members of array\n";
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        break;
    default:
        return 1;
    }
    printArray(array, n);
    int positionMin = 0;
    int positionMax = 0;
    int positionMinLast = 0;
    for (int i = 0; i < n; i++)
    {
        if (fabs(array[positionMin]) > fabs(array[i]))
        {
            positionMin = i;
        }
        if (fabs(array[positionMax]) < fabs(array[i]))
        {
            positionMax = i;
        }
    }
    swap(array[positionMin], array[positionMax]);
    printArray(array, n);
    for (int i = 0; i < n; i++)
    {
        if (fabs(array[positionMinLast]) >= fabs(array[i]))
        {
            positionMinLast = i;
        }
    }
    double answerSum = 0;
    for (int i = positionMinLast + 1; i < n; i++)
    {
        answerSum = answerSum + array[i];
    }
    cout << answerSum << "\n";
    for (int i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            array[i] = array[i] * array[i];
        }
    }
    printArray(array, n);
    sort(array, array + n);
    printArray(array, +n);
    return 0;
}