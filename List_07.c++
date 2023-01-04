#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Prac_07_Stack
{
private:
    Node *head;

public:
    Prac_07_Stack()
    {
        head = NULL;
    }
    // function for insertion in stack
    void push(int element)
    {
        Node *node = new Node();
        node->data = element;
        node->next = NULL;

        cout << "\nElement pushed in Stack " << element << endl;

        if (head == NULL)
        {
            head = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
        display();
    }

    // function for deletion of elements from stack
    void pop()
    {
        int x = -1;
        if (head == NULL)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            Node *temp = head;
            head = temp->next;
            x = temp->data;
            cout << "\n"
                 << x << " popped from stack" << endl;
        }
        display();
    }

    // function to display top element
    int top()
    {
        return head->data;
    }

    // display function to print stack
    void display()
    {
        if (head != NULL)
        {
            Node *temp = head;
            cout << "Stack contains: ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty" << endl;
        }
    }
};

int main()
{
    Prac_07_Stack stk;
    int ch, val;

    do
    {
        cout << "Enter 1 to push elemnts in the stack" << endl;
        cout << "Enter 2 to pop elements from the stack" << endl;
        cout << "Enter 3 to find element at the top of stack" << endl;
        cout << "Enter 4 to display elemnts in the stack" << endl;
        cout << "Enter 5 to exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "\nEnter the value to be pushed: " << endl;
            cin >> val;
            stk.push(val);
            break;
        }
        case 2:
        {
            stk.pop();
            break;
        }
        case 3:
        {
            cout << "Element at the top of stack: " << stk.top() << endl;
            break;
        }
        case 4:
        {
            stk.display();
            break;
        }
        case 5:
        {
            cout << "Exiting..." << endl;
            exit(0);
            break;
        }
        default:
            cout << "Invalid Choice!!" << endl;
        }
    } while (ch != 5);
    return 0;
}