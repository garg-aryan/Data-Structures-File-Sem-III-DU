/*Since we are not provided with data type of array and search function I will take int data type and will use Linear Search*/

#include <iostream>
#include <string>
using namespace std;

class Prac_01
{
public:
    int N;
    int *arr;

    // function to create array
    void createArray()
    {
        cout << "Enter the length of array: ";
        cin >> N;
        arr = new int[N];

        cout << "Enter array Elements: " << endl;
        for (int i = 0; i < N; i++)
        {
            cout << "Enter element at index " << i << " : ";
            cin >> arr[i];
        }
        cout << "Printing the array....." << endl;
        for (int i = 0; i < N; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

    // function for linear search
    int Linear_search()
    {
        int x;
        cout << "Enter the element to be searched: ";
        cin >> x;

        for (int i = 0; i < N; i++)
        {
            if (arr[i] == x)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    int result;
    Prac_01 obj; // object of Prac_01 class
    obj.createArray();
    result = obj.Linear_search();

    if (result == -1)
        cout << "Element is not present in the list" << endl;
    else
        cout << "Element is present in the list at index: " << result << endl;
    return 0;
}
