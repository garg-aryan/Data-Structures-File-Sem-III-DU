#include <iostream>
using namespace std;

class Prac_08_Queue
{
public:
    int *arr;
    int front, rear, size;
    Prac_08_Queue(int arrSize = 10)
    {
        size = arrSize;
        arr = new int(size);
        front = rear = -1;
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    // function for insertion in circular queue
    void enqueue(int value)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is Full\n";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % size;
            arr[rear] = value;
        }
    }

    // function for removal from circular queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    // function to show the first element in the queue
    void show_front()
    {
        if (isEmpty())
            cout << "Queue is Empty\n";
        else
            cout << "Element at front is: " << arr[front] << endl;
    }
    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "\nQueue: ";
            cout << "The queue is empty" << endl;
        }
        else
        {
            cout << "\nQueue has: ";
            int i;
            if (front <= rear)
            {
                for (i = front; i <= rear; i++)
                    cout << arr[i] << " ";
            }
            else
            {
                i = front;
                while (i < size)
                {
                    cout << arr[i] << " ";
                    i++;
                }
                i = 0;
                while (i <= rear)
                {
                    cout << arr[i] << " ";
                    i++;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Prac_08_Queue obj(6);
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