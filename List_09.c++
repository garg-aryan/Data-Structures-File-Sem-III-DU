#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

class Prac_09_Queue
{
public:
    Node *front = NULL;
    Node *rear = NULL;

    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // function for insertion in circular queue using CLL
    void enqueue(int value)
    {
        Node *ptr = new Node();
        ptr->data = value;
        ptr->link = NULL;

        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
        }
        else
        {
            rear->link = ptr;
            rear = ptr;
        }
    }

    // function for removal from circular queue using CLL
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n"
                 << endl;
        }
        else
        {
            if (front == rear)
            {
                delete (front);
                front = rear = NULL;
            }
            else
            {
                Node *ptr = front;
                front = front->link;
                delete (ptr);
            }
        }
    }

    // function to show the first element in the queue using CLL
    void show_front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n"
                 << endl;
        }
        else
        {
            cout << "Element at front is: " << front->data << endl;
        }
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "\nQueue: ";
            cout << "The queue is empty\n"
                 << endl;
        }
        else
        {
            cout << "\nQueue has: ";
            Node *ptr = front;
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->link;
            }
            cout << endl;
        }
    }
};

int main()
{
    Prac_09_Queue obj;
    int ch, val;
    do
    {
        cout << "\n1. For Enqueu\n2. For dequeue\n3. To show front element\n4. To Display Queue\n5. Exit\n";
        cout << "\nNow Enter your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "\nEnter the Value: ";
            cin >> val;
            obj.enqueue(val);
            obj.displayQueue();
            break;
        }
        case 2:
        {
            obj.dequeue();
            obj.displayQueue();
            break;
        }
        case 3:
        {
            obj.show_front();
            break;
        }
        case 4:
        {
            obj.displayQueue();
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