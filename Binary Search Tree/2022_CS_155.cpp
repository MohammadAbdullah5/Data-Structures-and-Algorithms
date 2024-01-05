#include <iostream>
#include <queue>
#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;

// ------------- BST Question 1 Part (a) ------------- 
template <typename T>
class BinarySearchTree
{
    public:
    class Node
    {
        public:
        T data;
        Node* left;
        Node* right;

        Node(T value)
        {
            left = nullptr;
            right = nullptr;
            data = value;
        }
    };


    Node* root;
    BinarySearchTree()
    {
        root = nullptr;
    }
    void insertinTrree(T value)
    {
        if (root == nullptr)
        {
            root = new Node(value);
        }

        else
        {
            Node* current = root;
            Node* parent = nullptr;
            bool flag = false;
            Node* newNode = new Node(value);
            while (current != nullptr)
            {
                parent = current;
                if (current->data > value)
                {
                    current = current->left;
                    flag = true;
                }

                else
                {
                    current = current->right;
                    flag = false;
                }
            }

            if (flag)
            {
                parent->left = newNode;
            }

            else
            {
                parent->right = newNode;
            }
        }

    }

    Node* searchinBST(T value)
    {
        Node* current = root;
        while(current->data != value && current != nullptr)
        {
            if (value > current->data)
            {
                current = current->right;
            }

            else
            {
                current = current->left;
            }
        }
       return current;
    }

    void recursivePrint(Node* current)
    {
        if (current != nullptr)
        {
            recursivePrint(current->left);
            cout << current->data << " ";
            recursivePrint(current->right);
        }
    }

    Node* start()
    {
        Node* current = root;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node* end()
    {
        Node* current = root;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }

    void visualize()
    {
        if (root == nullptr)
        {
            std::cout << "Tree is empty." << std::endl;
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                Node* current = q.front();
                q.pop();

                if (current != nullptr) {
                    std::cout << current->data << " ";

                    q.push(current->left);
                    q.push(current->right);
                }
                else {
                    std::cout << "null ";
                }
            }

            std::cout << std::endl;
        }
    }
};

// ------------- BST Question 1 Part (a) -------------
template <typename T>
class RandomBinaryTree
{
    class Node
    {
        public:
        T data;
        Node* left;
        Node* right;

        Node(T value)
        {
            left = nullptr;
            right = nullptr;
            data = value;
        }
    };


public:
    Node* root;
    RandomBinaryTree()
    {
        root = nullptr;
    }
    void insertinTrree(T value)
    {
        if (root == nullptr)
        {
            root = new Node(value);
        }

        else
        {
            Node* current = root;
            Node* parent = nullptr;
            bool flag = false;
            Node* newNode = new Node(value);
            while (current != nullptr)
            {
                parent = current;
                if (rand() % 2 == 0)
                {
                    current = current->left;
                    flag = true;
                }

                else
                {
                    current = current->right;
                    flag = false;
                }
            }

            if (flag)
            {
                parent->left = newNode;
            }

            else
            {
                parent->right = newNode;
            }
        }

    }

    Node* searchinBST(T value)
    {
        Node* current = root;
        while (current->data != value && current != nullptr)
        {
            if (rand() % 2 == 0)
            {
                current = current->right;
            }

            else
            {
                current = current->left;
            }
        }
        return current;
    }

    void recursivePrint(Node* current)
    {
        if (current != nullptr)
        {
            recursivePrint(current->left);
            cout << current->data << " ";
            recursivePrint(current->right);
        }
    }

    Node* start()
    {
        Node* current = root;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node* end()
    {
        Node* current = root;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }

    void visualize()
    {
        if (root == nullptr)
        {
            std::cout << "Tree is empty." << std::endl;
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                Node* current = q.front();
                q.pop();

                if (current != nullptr) {
                    std::cout << current->data << " ";

                    q.push(current->left);
                    q.push(current->right);
                }
                else {
                    std::cout << "null ";
                }
            }

            std::cout << std::endl;
        }
    }
};


// ------------ Question 2 ----------------
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }

        TreeNode* current = root;
        TreeNode* parent = root;
        bool flag;
        TreeNode* newNode = new TreeNode(val);
        while (current != nullptr)
        {
            parent = current;
            if (current->val > val)
            {
                current = current->left;
                flag = true;
            }

            else
            {
                current = current->right;
                flag = false;
            }
        }

        if (flag)
        {
            parent->left = newNode;
        }

        else
        {
            parent->right = newNode;
        }
        return root;
    }
};

// ------------ Question 3 ----------------
bool identicalTrees(BinarySearchTree<int>::Node* tree1, BinarySearchTree<int>::Node* tree2)
{
    if (tree1 == nullptr && tree2 == nullptr)
    {
        return true;
    }

    if (tree1->data == tree2->data)
    {
        return true;
    }

    if (tree1 != nullptr && tree2 == nullptr)
    {
        return false;
    }

    if (tree1 == nullptr && tree2 != nullptr)
    {
        return false;
    }

    if (tree1->data != tree2->data)
    {
        return false;
    }

    return identicalTrees(tree1->left, tree2->left) && identicalTrees(tree1->right, tree2->right);
}

// ------------ Question 4 Part (a)----------------
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vctr;
        inorder(root, vctr);
        return vctr;
    }

    void inorder(TreeNode* current, vector<int>& vctr)
    {
        if (current != nullptr)
        {
            inorder(current->left, vctr);
            vctr.push_back(current->val);
            inorder(current->right, vctr);
        }
    }
};

// ------------ Question 4 Part (b)----------------
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vctr;
        postorder(root, vctr);
        return vctr;
    }

    void postorder(TreeNode* current, vector<int>& vctr)
    {
        if (current != nullptr)
        {
            postorder(current->left, vctr);
            postorder(current->right, vctr);
            vctr.push_back(current->val);
        }
    }
};

// ------------ Question 4 Part (c)----------------
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vctr;
        preorder(root, vctr);
        return vctr;
    }

    void preorder(TreeNode* current, vector<int>& vctr)
    {
        if (current != nullptr)
        {
            vctr.push_back(current->val);
            preorder(current->left, vctr);
            preorder(current->right, vctr);
        }
    }
};

// ----------------- Question 5 ------------------
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vctr;
        queue<TreeNode*> q;
        if (root == nullptr)
        {
            return vctr;
        }
        TreeNode* current = root;
        q.push(root);

        while (!q.empty())
        {
            vector<int> temp;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                current = q.front();
                q.pop();
                if (current->left != nullptr) {
                    q.push(current->left);
                }

                if (current->right != nullptr) {
                    q.push(current->right);
                }
                temp.push_back(current->val);
            }
            vctr.push_back(temp);
        }
        return vctr;
    }

};

// ----------------- Question 6 ------------------
int evenCountInBST(BinarySearchTree<int>::Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int evenInLeftSubTree = evenCountInBST(root->left);
    int evenInRightSubTree = evenCountInBST(root->right);
    if (root->data % 2 == 0)
    {
        return evenInLeftSubTree + evenInRightSubTree + 1;
    }

    else
    {
        return evenInLeftSubTree + evenInRightSubTree;
    }

}

// ----------------- Question 7 ------------------
int heightOfBT(BinarySearchTree<int>::Node* tree)
{
    if (tree == nullptr)
    {
        return 0;
    }

    return max(heightOfBT(tree->left), heightOfBT(tree->right)) + 1;
}

// ----------------- Question 8 ------------------
bool Validation(BinarySearchTree<int>::Node* rooot)
{
    if (rooot == nullptr)
    {
        return true;
    }
    BinarySearchTree<int>::Node* current = rooot;
    int prev = INT_MIN;
    stack<BinarySearchTree<int>::Node*> st;

    while (current != nullptr || !st.empty())
    {
        while (current != nullptr)
        {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();
        
        if (current->data < prev)
        {
            return false;
        }

        prev = current->data;
        current = current->right;
    }
    return true;
}

// ----------------- Question 9 ------------------
void inorderForSort(BinarySearchTree<int>::Node* current)
{
    if (current == nullptr)
    {
        return;
    }

    inorderForSort(current->left);
    cout << current->data << "  ";
    inorderForSort(current->right);
}

void BSTSorting(int arr[], int size)
{
    BinarySearchTree<int> tree;
    for (int i = 0; i < size; i++)
    {
        tree.insertinTrree(arr[i]);
    }

    inorderForSort(tree.root);
}

// ----------------- Question 10 ------------------
int countOneLeaves(BinarySearchTree<int>::Node* rooot)
{
    if (rooot == nullptr)
    {
        return 0;
    }

    else if ((rooot->left == nullptr && rooot->right != nullptr) || (rooot->right == nullptr && rooot->left != nullptr))
    {
        return 1;
    }

    return countOneLeaves(rooot->left) + countOneLeaves(rooot->right);
}

// ----------------- Question 11 ------------------
void printRow(BinarySearchTree<int>::Node* root, int depth, int level) {
    if (root == nullptr || depth < 0) {
        return;
    }

    if (depth == 0) {
        for (int i = 0; i < level; ++i) {
            cout << "    ";
        }
        cout << root->data << endl;
    }
    else {
        printRow(root->left, depth - 1, level);
        printRow(root->right, depth - 1, level);
    }
}
void printTreeRec(BinarySearchTree<int>::Node* rooot)
{
    int height = heightOfBT(rooot);
    for (int i = 0; i < height; i++)
    {
        printRow(rooot, i, i);
    }
}

// ----------------- Question 12 ------------------
int countLeaves(BinarySearchTree<int>::Node* rooot)
{
    if (rooot == nullptr)
    {
        return 0;
    }

    else if (rooot->left == nullptr && rooot->right == nullptr)
    {
        return 1;
    }

    return countLeaves(rooot->left) + countLeaves(rooot->right);
}

int main()
{
    BinarySearchTree<int> bst;
}