#include <iostream>
using namespace std;

class Prac_06_Stack
{
    int *stack;
    int n, top;

public:
    Prac_06_Stack(int maxSize = 100)
    {
        stack = new int(maxSize);
        n = maxSize;
        top = -1;
    }
    // push function for insertion
    void push(int val)
    {
        if (top >= n - 1)
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            stack[top] = val;
            cout << "Element pushed in stack: " << val << endl;
        }
    }
    // pop function for deletion
    void pop()
    {
        int x = -1;
        if (top <= -1)
            cout << "Stack Underflow" << endl;
        else
        {
            x = stack[top];
            top--;
            cout << "\n"
                 << x << " popped from stack: " << endl;
        }
    }
    // function to display stack
    void display()
    {
        if (top >= 0)
        {
            cout << "\nStack : ";
            for (int i = top; i >= 0; i--)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
        else
            cout << "The stack is empty" << endl;
    }
};

int main()
{
    Prac_06_Stack stk;
    int ch, val;

    do
    {
        cout << "Enter 1 to push elemnts in the stack" << endl;
        cout << "Enter 2 to pop elements from the stack" << endl;
        cout << "Enter 3 to display elemnts in the stack" << endl;
        cout << "Enter 4 to exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "\nEnter the value to be pushed: " << endl;
            cin >> val;
            stk.push(val);
            stk.display();
            break;
        }
        case 2:
        {
            stk.pop();
            stk.display();
            break;
        }
        case 3:
        {
            stk.display();
            break;
        }
        case 4:
        {
            cout << "Exiting..." << endl;
            exit(0);
            break;
        }
        default:
            cout << "Invalid Choice!!" << endl;
        }
    } while (ch != 4);
    return 0;
}