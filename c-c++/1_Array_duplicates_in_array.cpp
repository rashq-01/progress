#include <iostream>
using namespace std;

int printArray(int array1[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array1[i] << " ";
    }
    cout << endl;
}

int unique(int arr[], int size)
{
    int result[100];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            if ((arr[j] ^ arr[i]) == 0)
            {
                result[k] = arr[j];
                k++;
                break;
            }
        }
    }

    for (int l = 0; l < k; l++)
    {
        cout << result[l] << ", ";
    }
}

int main()
{
    int arr[100];
    int s;
    cout << "Enter size: ";
    cin >> s;
    cout << "Enter elements: ";
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }
    cout << "Your array is: ";
    printArray(arr, s);
    cout << endl;
    unique(arr, s);
}