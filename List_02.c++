/*Since we are not provided with data type of array I will take int data type and since array is in ascending order I will use Binary Search*/

#include <iostream>
#include <string>
using namespace std;

class Prac_02
{
public:
    int N;
    int *arr;

    // function to create an array
    void createArray()
    {
        cout << "Enter the length of array: ";
        cin >> N;
        arr = new int[N];

        cout << "Enter array Elements: " << endl;
        for (int i = 0; i < N; i++)
        {
            cout << "Element at index " << i << " : ";
            cin >> arr[i];
        }
        cout << "Printing the array....." << endl;
        for (int i = 0; i < N; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

    // function for Binary Search
    int Binary_search()
    {
        int x;
        cout << "Enter the element to be searched: ";
        cin >> x;

        int start = 0;
        int end = N - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] == x)
                return mid;
            else if (arr[mid] < x)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};
int main()
{
    int result;
    Prac_02 obj;
    obj.createArray();
    result = obj.Binary_search();

    if (result == -1)
        cout << "Element is not present in the list" << endl;
    else
        cout << "Element is present in the list at index " << result << endl;
    return 0;
}
