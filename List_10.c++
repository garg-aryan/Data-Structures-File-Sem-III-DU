#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class Prac_10_DbQueue
{
public:
    Node *front;
    Node *rear;
    int size;

    Prac_10_DbQueue()
    {
        front = rear = NULL;
        size = 0;
    }
    Node *getNode(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }
    int dbqueueSize()
    {
        return size;
    }

    void insertFront(int data)
    {
        Node *newNode = getNode(data);
        if (newNode == NULL)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            if (front == NULL)
            {
                rear = front = newNode;
            }
            else
            {
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }
            size++;
        }
    }
    void insertRear(int data)
    {
        Node *newNode = getNode(data);
        if (newNode == NULL)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            if (rear == NULL)
            {
                front = rear = newNode;
            }
            else
            {
                newNode->prev = rear;
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }
    }
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Underflow" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;

            if (front == NULL)
            {
                rear = NULL;
            }
            else
            {
                front->prev = NULL;
            }
            delete (temp);
            size--;
        }
    }
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Underflow" << endl;
        }
        else
        {
            Node *temp = rear;
            rear = rear->prev;

            if (rear == NULL)
            {
                front = NULL;
            }
            else
            {
                rear->next = NULL;
            }
            delete (temp);
            size--;
        }
    }
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return front->data;
    }
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return rear->data;
    }
    void displaydbQueue()
    {
        if (isEmpty())
        {
            cout << "\nDouble Queue: " << endl;
            cout << "The double queue is empty\n"
                 << endl;
        }
        else
        {
            cout << "\nDouble Queue: ";
            Node *ptr = front;
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Prac_10_DbQueue dqobj;
    int ch, val;
    do
    {
        cout << "\nPress 1 - Insert element at FRONT " << endl;
        cout << "Press 2 - Insert element at REAR " << endl;
        cout << "Press 3 - Delete element from FRONT " << endl;
        cout << "Press 4 - Delete element from REAR " << endl;
        cout << "Press 5 - Show element at FRONT " << endl;
        cout << "Press 6 - Show element at REAR " << endl;
        cout << "Press 7 - Size of Double Queue " << endl;
        cout << "Press 8 - Display Double Queue " << endl;
        cout << "Press 9 - Exit " << endl;

        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            cout << "Enter element to be inserted at FRONT end of double queue: ";
            cin >> val;
            dqobj.insertFront(val);
            cout << "Inserted at FRONT: " << val << endl;
            dqobj.displaydbQueue();
            break;
        }
        case 2:
        {
            cout << "Enter element to be inserted at REAR end of double queue: ";
            cin >> val;
            dqobj.insertRear(val);
            cout << "Inserted at REAR: " << val << endl;
            dqobj.displaydbQueue();
            break;
        }
        case 3:
        {
            dqobj.deleteFront();
            cout << "Deleted from FRONT: "  << endl;
            dqobj.displaydbQueue();
            break;
        }
        case 4:
        {
            dqobj.deleteRear();
            cout << "Deleted from REAR: " << endl;
            dqobj.displaydbQueue();
            break;
        }
        case 5:
        {
            cout << "Eleement at FRONT: " << dqobj.getFront() << endl;
            break;
        }
        case 6:
        {
            cout << "Eleement at REAR: " << dqobj.getRear() << endl;
            break;
        }
        case 7:
        {
            cout << "Size of Double Queue is: " << dqobj.dbqueueSize() << endl;
            break;
        }
        case 8:
        {
            dqobj.displaydbQueue();
            break;
        }
        case 9:
        {
            cout << "Exiting..." << endl;
            exit(0);
            break;
        }
        default:
            cout << "Invalid Choice!!!" << endl;
        }
    } while (ch != 9);

    return 0;
}