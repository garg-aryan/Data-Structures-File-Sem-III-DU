#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class Prac_04_DLL
{
private:
    Node *head;

public:
    Node *flag = new Node();
    Prac_04_DLL()
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
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The Singly Linked List is EMPTY!!!" << endl;
        }
    }

    // function to insert at the begnning of the list
    void insertAtBeginning(int newele)
    {
        Node *newNode = new Node;
        newNode->data = newele;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            head->prev = newNode;
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
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    // function to insert at the location in the list
    void insertAtIndex(int newele, int pos)
    {
        Node *newNode = new Node();
        newNode->data = newele;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (pos < 1)
        {
            cout << "Position should be greater than 1 " << endl;
        }
        else if (pos == 1)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < pos - 1; i++)
            {
                if (temp != NULL)
                {
                    temp = temp->next;
                }
            }

            if (temp != NULL)
            {
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                if (newNode->next != NULL)
                {
                    newNode->next->prev = newNode;
                }
            }
            else
            {
                cout << "The previous Node is NULL" << endl;
            }
        }
    }

    // Function for deletion at beginning
    void deleteAtBeginning()
    {
        if (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete (temp);
            if (head != NULL)
            {
                head->prev = NULL;
            }
        }
    }

    // function for deletion at a specific location
    void deleteAtIndex(int pos)
    {
        if (pos < 1)
        {
            cout << "Position should be >=1.." << endl;
        }
        else if (pos = 1 && head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete (temp);
            if (head != NULL)
            {
                head->prev = NULL;
            }
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < pos - 1; i++)
            {
                if (temp != NULL)
                {
                    temp = temp->next;
                }
            }
            if (temp != NULL && temp->next != NULL)
            {
                Node *nodetoDel = temp->next;
                temp->next = temp->next->next;
                if (temp->next->next != NULL)
                {
                    temp->next->next->prev = temp->next;
                }
                delete (nodetoDel);
            }
            else
            {
                cout << "The node is already full" << endl;
            }
        }
    }

    // function to delete from end
    void deleteAtEnd()
    {
        if (head != NULL)
        {
            if (head->next == NULL)
            {
                head = NULL;
            }
            else
            {
                Node *temp = head;
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                Node *lastNode = temp->next;
                temp->next = NULL;
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
            while (temp != NULL)
            {
                pos++;
                if (temp->data == x)
                {
                    flag->data = pos;
                    return temp;
                }
                temp = temp->next;
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
            node->prev = NULL;

            if (hd == NULL)
            {
                hd = node;
            }
            else
            {
                Node *temp = hd;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                node->prev = temp;
                temp->next = node;
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
        if (node1->next == NULL)
        {
            node1->next = node2;
            node2->prev = node1;
        }
        else
        {
            concatenate(node1->next, node2);
        }
        return node1;
    }
    void runConcatenate()
    {
        cout << "\nMAking new lists..." << endl;
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
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The Doubly Linked List is EMPTY!!!" << endl;
        }
    }
};

int main()
{
    Prac_04_DLL obj;
    int option;
    do
    {
        cout << "\nEnter 1 to Insert an element at the beginning of the DLL" << endl;
        cout << "Enter 2 to Insert an element at any position of the DLL" << endl;
        cout << "Enter 3 to Insert an element at End of the DLL" << endl;
        cout << "Enter 4 to Remove an element from the beginning of the DLL" << endl;
        cout << "Enter 5 to Remove an element from any position of the DLL" << endl;
        cout << "Enter 6 to Remove an element from End of the DLL" << endl;
        cout << "Enter 7 to Search an element in the DLL" << endl;
        cout << "Enter 8 to Concatenate two Doubly Linked Lists" << endl;
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
            int val, pos;
            cout << "Enter an element: ";
            cin >> val;
            cout << "Enter position at which " << val << " to be inserted: ";
            cin >> pos;
            obj.insertAtIndex(val, pos);
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
            int pos;
            cout << "Enter Position from which element has to be deleted: ";
            cin >> pos;
            obj.deleteAtIndex(pos);
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