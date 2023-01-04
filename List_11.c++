#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Prac_11_BST
{
private:
    Node *root;

public:
    Prac_11_BST()
    {
        root = nullptr;
    }

    // Function to insert in BST
    void insert(int x)
    {
        Node *newNode = new Node();
        newNode->data = x;
        newNode->right = nullptr;
        newNode->left = nullptr;
        Node *temp, *ptr = root;
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            while (ptr != nullptr)
            {
                temp = ptr;
                if (x >>= ptr->data)
                {
                    ptr = ptr->right;
                }
                else
                {
                    ptr = ptr->left;
                }
            }
            if (x >= temp->data)
            {
                temp->right = newNode;
            }
            else
            {
                temp->left = newNode;
            }
        }
        cout << "Inserted Node<>" << endl;
        
    }

    // function for Inorder Traversal
    void inorder(Node *ptr)
    {
        if (ptr == nullptr)
            return;
        else
        {
            inorder(ptr->left);
            cout << ptr->data << " ";
            inorder(ptr->right);
        }
    }
    // function for Preorder Traversal
    void preorder(Node *ptr)
    {
        if (ptr == nullptr)
            return;
        else
        {
            cout << ptr->data << " ";
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }
    // function for Postorder Traversal
    void postorder(Node *ptr)
    {
        if (ptr == nullptr)
            return;
        else
        {
            postorder(ptr->left);
            postorder(ptr->right);
            cout << ptr->data << " ";
        }
    }

    // function to get root
    Node *getroot()
    {
        return root;
    }

    void delc(Node *&temp)
    {
        Node *prev, *tmp = temp;
        if (temp->right == NULL)
        {
            temp = temp->left;
        }
        else if (temp->left == NULL)
        {
            temp = temp->right;
        }
        else
        {
            tmp = temp->left;
            prev = temp;
            while (tmp->right != NULL)
            {
                prev = tmp;
                tmp = tmp->right;
            }
            temp->data = temp->data;
            if (prev == temp)
            {
                prev->left = tmp->left;
            }
            else
            {
                prev->right = tmp->right;
            }
        }
        delete tmp;
    }

    void del_copy(int el)
    {
        Node *prev;
        Node *ptr = root;
        while (ptr != nullptr)
        {
            if (ptr->data == el)
                break;
            prev = ptr;
            if (ptr->data < el)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        if (ptr != nullptr && ptr->data == el)
        {
            if (ptr == root)
                delc(root);
            else if (prev->left == ptr)
                delc(prev->left);
            else
                delc(prev->right);
        }
        else if (root != 0)
            cout << "\nNode not found in the tree!";
        else
            cout << "\n\tThe tree is Empty!";
    }

    // function to find element x and change with y
    void search_change()
    {
        int key, newKey;
        cout << "\nEnter the key to be searched : ";
        cin >> key;
        Node *ptr = root;
        if (ptr == nullptr)
        {
            cout << "The tree is Empty!" << endl;
        }
        else
        {
            cout << "Enter the new key: ";
            cin >> newKey;

            int flag = 0;
            while (ptr != nullptr)
            {
                if (key == ptr->data)
                {
                    flag = 1;
                    break;
                }
                else if (key > ptr->data)
                    ptr = ptr->right;
                else
                    ptr = ptr->left;
            }
            if (flag == 0)
                cout << "Node not found in the tree!" << endl;
            else
            {
                del_copy(key);
                insert(newKey);
            }
        }
    }

    // function to find height of tree
    int height_helper(Node *temp)
    {
        int hleft = 0;
        int hright = 0;
        if (temp != nullptr)
        {
            hleft = height_helper(temp->left);
            hright = height_helper(temp->right);
            if (hleft > hright)
                return hleft + 1;
            else
                return hright + 1;
        }
        return -1;
    }

    int height()
    {
        return height_helper(root);
    }

    void printGivenLevel(Node *rootNode, int level)
    {
        if (rootNode == NULL)
        {
            return;
        }
        if (level == 1)
        {
            cout << rootNode->data << " ";
        }
        else if (level > 1)
        {
            printGivenLevel(rootNode->left, level - 1);
            printGivenLevel(rootNode->right, level - 1);
        }
    }

    // function to print level order
    void printLevelOrder()
    {
        int h = height();
        for (int i = 1; i <= h + 1; i++)
        {
            cout << "Level " << i << " : ";
            printGivenLevel(root, i);
            cout << endl;
        }
    }
};

int main()
{
    Prac_11_BST obj;
    int option, temp;
    do
    {
        cout << "\nEnter 1 to Insert an element in BST" << endl;
        cout << "Enter 2 to Delete an element from BST" << endl;
        cout << "Enter 3 Search for an element x and change its value to y and then place the node with value y at its appropriate position in the BST" << endl;
        cout << "Enter 4 to display elements of BST in inorder,preorder and postorder travesals " << endl;
        cout << "Enter 5 to Display the elements of BST in level-by-level travesal" << endl;
        cout << "Enter 6 to Display the height of BST" << endl;
        cout << "Enter 7 to exit" << endl;
        cout << "\nNow enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << "Enter an element x: ";
            cin >> temp;
            obj.insert(temp);
            break;
        }
        case 2:
        {
            cout << "Enter an element you want to delete: ";
            cin >> temp;
            obj.del_copy(temp);
            cout << "Deleted Node<" << temp << ">" << endl;
            break;
        }
        case 3:
        {
            obj.search_change();
            break;
        }
        case 4:
        {
            cout << "Inorder: ";
            obj.inorder(obj.getroot());
            cout << endl;
            cout << "Preorder: ";
            obj.preorder(obj.getroot());
            cout << endl;
            cout << "Postorder: ";
            obj.postorder(obj.getroot());
            cout << endl;
            break;
        }
        case 5:
        {
            obj.printLevelOrder();
            break;
        }
        case 6:
        {
            cout << "Height of tree: " << obj.height();
            cout << endl;
            break;
        }
        case 7:
        {
            cout << "Exiting..." << endl;
            exit(0);
            break;
        }

        default:
            cout << "Invalid choice!!!" << endl;
        }
    } while (option != 7);

    return 0;
}