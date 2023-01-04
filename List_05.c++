#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Prac_05_CLL
{
private:
    Node *head;

public:
    Node *flag = new Node();
    Prac_05_CLL()
    {
        head = NULL;
    }

    // Display function
    void display()
    {
        Node *temp = head;
        if (temp != NULL)
        {
            cout << "The list contains: ";
            while (true)
            {
                cout << temp->data << " ";
                temp = temp->next;
                if (temp == head)
                    break;
            }
            cout << endl;
        }
        else
        {
            cout << "The Circular Linked List is EMPTY!!!" << endl;
        }
    }

    // function to insert at the begnning of the list
    void insertAtBeginning(int newele)
    {
        Node *newNode = new Node;
        newNode->data = newele;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // function to insert at end
    void insertAtEnd(int newele)
    {
        Node *newNode = new Node;
        newNode->data = newele;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    // function to insert an element x after an element y
    void insertAfterElement(int eleX, int eleY)
    {
        Node *res = searchInList(eleY);
        if (res == flag)
        {
            cout << "Element " << eleX << " cannot be inserted as element " << eleY << " is not found in the list" << endl;
        }
        else
        {
            Node *nodeX = new Node();
            nodeX->data = eleX;
            nodeX->next = NULL;

            if (res->next == head)
            {
                res->next = nodeX;
                nodeX->next = head;
            }
            else
            {
                nodeX->next = res->next;
                res->next = nodeX;
            }
        }
    }

    // Function for deletion at beginning
    void deleteAtBeginning()
    {
        if (head != NULL)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                Node *temp = head;
                Node *firstNode = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                head = head->next;
                temp->next = head;
                delete (firstNode);
            }
        }
    }

    // function for deletion of an element x
    void deleteElement(int x)
    {
        Node *res = searchInList(x);
        if (res == flag)
        {
            cout << "Element " << x << " is not found in the list" << endl;
        }
        else
        {
            if (head == res)
            {
                Node *temp = res;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                if (head == head->next)
                {
                    head = NULL;
                }
                else
                {
                    head = res->next;
                    temp->next = head;
                }
                delete (res);
            }
            else
            {
                Node *temp = head;
                while (temp->next != res)
                {
                    temp = temp->next;
                }
                if (res->next != head)
                {
                    temp->next = res->next;
                    delete (res);
                }
                else
                {
                    temp->next = head;
                    delete (res);
                }
            }
        }
    }

    // function to delete from end
    void
    deleteAtEnd()
    {
        if (head != NULL)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                Node *temp = head;
                while (temp->next->next != head)
                {
                    temp = temp->next;
                }
                Node *lastNode = temp->next;
                temp->next = head;
                delete (lastNode);
            }
        }
    }

    // function to search in the list
    Node *searchInList(int x)
    {
        Node *temp = head;
        int pos = -1;
        if (temp != NULL)
        {
            while (true)
            {
                pos++;
                if (temp->data == x)
                {
                    flag->data = pos;
                    return temp;
                }
                temp = temp->next;
                if (temp == head)
                {
                    break;
                }
            }
        }
        return flag;
    }

    void runSearch(int x)
    {
        Node *res = searchInList(x);
        if (res == flag)
        {
            cout << "Element " << x << " is not found in the list " << endl;
        }
        else
        {
            cout << "Element " << x << " is found in the list at position " << flag->data << " in the list address " << endl;
        }
    }
    // function to create new list
    Node *newList()
    {
        Node *hd = NULL;
        int elem;
        int run = 1;
        do
        {
            cout << "Enter the element: ";
            cin >> elem;

            Node *node = new Node();
            node->data = elem;
            node->next = NULL;

            if (hd == NULL)
            {
                hd = node;
                node->next = hd;
            }
            else
            {
                Node *temp = hd;
                while (temp->next != hd)
                {
                    temp = temp->next;
                }
                temp->next = node;
                node->next = hd;
            }

            cout << "To continue.... Enter 1(to Exit: Enter any integer except 1): ";
            cin >> run;
            if (run != 1)
            {
                break;
            }

        } while (run == 1);
        return hd;
    }
    // function to concatenate 2 lists
    Node *concatenate(Node *node1, Node *node2)
    {
        Node *temp = node1;
        while (temp->next != node1)
        {
            temp = temp->next;
        }
        temp->next = node2;

        Node *temp2 = node2;
        while (temp2->next != node2)
        {
            temp2 = temp2->next;
        }
        temp2->next = node1;
        return node1;
    }
    void runConcatenate()
    {
        cout << "\nMaking new lists..." << endl;
        cout << "\nEnter values for list 1 " << endl;
        Node *list1 = newList();
        cout << "\nEnter values for list 2 " << endl;
        Node *list2 = newList();

        cout << "List 1: ";
        display(list1);
        cout << "List 2: ";
        display(list2);

        Node *concatenateList = concatenate(list1, list2);

        cout << "Concatenated list is: ";
        display(concatenateList);
    }
    // Display function overloaded
    void display(Node *list)
    {
        Node *temp = list;
        if (temp != NULL)
        {
            cout << "The list contains: ";
            while (true)
            {
                cout << temp->data << " ";
                temp = temp->next;
                if (temp == list)
                    break;
            }
            cout << endl;
        }
        else
        {
            cout << "The Circular Linked List is EMPTY!!!" << endl;
        }
    }
};

int main()
{
    Prac_05_CLL obj;
    int option;
    do
    {
        cout << "\nEnter 1 to Insert an element at the beginning of the CLL" << endl;
        cout << "Enter 2 to Insert an element x after an element y of the CLL" << endl;
        cout << "Enter 3 to Insert an element at End of the CLL" << endl;
        cout << "Enter 4 to Remove an element from the beginning of the CLL" << endl;
        cout << "Enter 5 to Remove an element x from the CLL" << endl;
        cout << "Enter 6 to Remove an element from End of the CLL" << endl;
        cout << "Enter 7 to Search an element in the CLL" << endl;
        cout << "Enter 8 to Concatenate two Circularly Linked Lists" << endl;
        cout << "Enter 9 to Print the list" << endl;
        cout << "Enter 10 to Exit" << endl;
        cout << "\nNow enter your choice: ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            int val;
            cout << "Enter an element: ";
            cin >> val;
            obj.insertAtBeginning(val);
            cout << "Updated list: ";
            obj.display();
            break;
        }
        case 2:
        {
            int eleX, eleY;
            cout << "Enter element X: ";
            cin >> eleX;
            cout << "Enter element Y: ";
            cin >> eleY;
            obj.insertAfterElement(eleX, eleY);
            cout << "Updated list: ";
            obj.display();
            break;
        }
        case 3:
        {
            int val;
            cout << "Enter an Element: ";
            cin >> val;
            obj.insertAtEnd(val);
            cout << "Updated list: ";
            obj.display();
            break;
        }
        case 4:
        {
            obj.deleteAtBeginning();
            cout << "Updated list: ";
            obj.display();
            break;
        }
        case 5:
        {
            int x;
            cout << "Enter element x: ";
            cin >> x;
            obj.deleteElement(x);
            cout << "Updated list: ";
            obj.display();
            break;
        }
        case 6:
        {
            obj.deleteAtEnd();
            cout << "Updated list: ";
            obj.display();
            break;
        }
        case 7:
        {
            int ele;
            cout << "Enter element to be Searched: ";
            cin >> ele;
            obj.runSearch(ele);
            break;
        }
        case 8:
        {
            obj.runConcatenate();
            break;
        }
        case 9:
        {
            obj.display();
            break;
        }
        case 10:
        {
            cout << "Exiting..." << endl;
            exit(0);
            break;
        }

        default:
            cout << "Invalid Choice!!!" << endl;
        }
    } while (option != 10);

    return 0;
}