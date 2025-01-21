#include <iostream>
using namespace std;

int bubble_sort(int arr[], int target, int size)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid == target)
        {
            return mid;
        }
        else if (mid < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 22, 16};
    int target = 16;
    int size = 14;
    cout << "The element is at " << bubble_sort(array, target, size) << " index" << endl;
}