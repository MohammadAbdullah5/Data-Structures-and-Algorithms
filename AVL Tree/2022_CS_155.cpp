#include <iostream>
#include <queue>
using namespace std;
class Problem1
{
	/*
	class Solution {
	public:
		int heightDiffernece(TreeNode* node)
		{
			int leftHeight = height(node->left);
			int rightHeight = height(node->right);
			return leftHeight - rightHeight;
		}

		void leftRotate(TreeNode*& node)
		{
			TreeNode* right = node->right;
			TreeNode* leftToRight = right->left;
			right->left = node;
			node->right = leftToRight;
			node = right;
		}

		void rightRotate(TreeNode*& node)
		{
			TreeNode* left = node->left;
			TreeNode* rightToLeft = left->right;
			left->right = node;
			node->left = rightToLeft;
			node = left;
		}

		int height(TreeNode* node)
		{
			if (node == nullptr)
			{
				return 0;
			}
			return 1 + max(height(node->left), height(node->right));
		}

		TreeNode* balanceBST(TreeNode* root) {
			vector<int> vctr;
			inorder(vctr, root);
			TreeNode* rt = new TreeNode(vctr[0]);
			int size = vctr.size();
			for (int i = 1; i < size; i++)
			{
				insertInAVLTree(vctr[i], rt);
			}
			return rt;
		}

		void inorder(vector<int>& vctr, TreeNode* root)
		{
			if (root != nullptr)
			{
				inorder(vctr, root->left);
				vctr.push_back(root->val);
				inorder(vctr, root->right);
			}
		}

		void insertInAVLTree(int value, TreeNode*& root) {
			if (root == nullptr)
			{
				root = new TreeNode(value);
				return;
			}

			if (root->val > value)
			{
				insertInAVLTree(value, root->left);
			}

			else if (root->val < value)
			{
				insertInAVLTree(value, root->right);
			}

			else
			{
				return;
			}

			int balancingFactor = heightDiffernece(root);

			if (balancingFactor > 1 && value < root->left->val)
			{
				rightRotate(root);
			}

			else if (balancingFactor < -1 && value > root->right->val)
			{
				leftRotate(root);
			}

			else if (balancingFactor > 1 && value > root->left->val)
			{
				leftRotate(root->left);
				rightRotate(root);
			}

			else if (balancingFactor < -1 && value < root->right->val)
			{
				rightRotate(root->right);
				leftRotate(root);
			}
		}
	};
	*/
};

class Problem2
{
	/*
	class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }
        int diff = heightDiffernece(root);

        if (abs(diff) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        {
            return true;
        }
        return false;
    }

    int height(TreeNode* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		return 1 + max(height(node->left), height(node->right));
	}

	int heightDiffernece(TreeNode* node)
	{
        if(node != nullptr)
        {
		    int leftHeight = height(node->left);
		    int rightHeight = height(node->right);
		    return leftHeight - rightHeight;
        }
        return 0;
	}
};
	*/
};

class AVLTree
{
	class Node
	{
		public:
		int data;
		Node* leftSubtree;
		Node* rightSubtree;

		Node(int val)
		{
			data = val;
			leftSubtree = nullptr;
			rightSubtree = nullptr;
		}
	};
	Node* root;
	public:
	AVLTree()
	{
		root = nullptr;
	}

	int height(Node*& node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		return 1 + max(height(node->leftSubtree), height(node->rightSubtree));
	}

	int heightDiffernece(Node*& node)
	{
		int leftHeight = height(node->leftSubtree);
		int rightHeight = height(node->rightSubtree);
		return leftHeight - rightHeight;
	}

	bool isBalanced(Node* node)
	{
		int diff = heightDiffernece(node);
		if (abs(diff) <= 1)
		{
			return true;
		}
		return false;
	}

	Node* insertInAVLTree(Node*& node, int value)
	{
		if (node == nullptr)
		{
			node = new Node(value);
			return node;
		}

		if (value < node->data)
		{
			node->leftSubtree = insertInAVLTree(node->leftSubtree, value);
		}

		else if (value > node->data)
		{
			node->rightSubtree = insertInAVLTree(node->rightSubtree, value);
		}

		else
		{
			return node;
		}

		int balancingFactor = heightDiffernece(node);

		if (balancingFactor > 1 && value < node->leftSubtree->data)
		{
			return rightRotate(node);
		}

		else if (balancingFactor < -1 && value > node->rightSubtree->data)
		{
			return leftRotate(node);
		}
		
		else if (balancingFactor > 1 && value > node->leftSubtree->data)
		{
			node->leftSubtree = leftRotate(node->leftSubtree);
			return rightRotate(node);
		}
			
		else if (balancingFactor < -1 && value < node->rightSubtree->data)
		{
			node->rightSubtree = rightRotate(node->rightSubtree);
			return leftRotate(node);
		}
		return node;
	}

	Node* leftRotate(Node*& node)
	{
		Node* right = node->rightSubtree;
		Node* leftToRight = right->leftSubtree;
		right->leftSubtree = node;
		node->rightSubtree = leftToRight;
		node = right;
		return right;
	}

	Node* rightRotate(Node*& node)
	{
		Node* left = node->leftSubtree;
		Node* rightToLeft = left->rightSubtree;
		left->rightSubtree = node;
		node->leftSubtree = rightToLeft;
		node = left;
		return left;
	}

	void insert(int value)
	{
		if (root == nullptr)
		{
			root = new Node(value);
		}

		else
		{
			insertInAVLTree(root, value);
		}
	}

	Node* delet(Node*& node, int value)
	{
		if (node == nullptr)
		{
			return node;
		}

		if (value < node->data)
		{
			node->leftSubtree = delet(node->leftSubtree, value);
		}

		else if (value > node->data)
		{
			node->rightSubtree = delet(node->rightSubtree, value);
		}

		else
		{
			if (node->leftSubtree == nullptr || node->rightSubtree == nullptr)
			{
				Node* temp = nullptr;
				if (node->leftSubtree != nullptr)
				{
					temp = node->leftSubtree;
				}

				else
				{
					temp == node->rightSubtree;
				}

				if (temp == nullptr)
				{
					temp = node;
					node = nullptr;
				}

				else 
				{
					*node = *temp; 
				}

				delete temp;
			}

			else
			{
				Node* temp = next(node->rightSubtree);

				node->data = temp->data;

				node->rightSubtree = delet(node->rightSubtree, temp->data);
			}
		}

		if (node == nullptr)
		{
			return node;
		}

		int balancingFactor = heightDiffernece(node);

		if (balancingFactor > 1 && value < node->leftSubtree->data)
		{
			return rightRotate(node);
		}

		else if (balancingFactor < -1 && value > node->rightSubtree->data)
		{
			return leftRotate(node);
		}

		else if (balancingFactor > 1 && value > node->leftSubtree->data)
		{
			node->leftSubtree = leftRotate(node->leftSubtree);
			return rightRotate(node);
		}

		else if (balancingFactor < -1 && value < node->rightSubtree->data)
		{
			node->rightSubtree = rightRotate(node->rightSubtree);
			return leftRotate(node);
		}
		return node;
	}

	Node* next(Node* node)
	{
		while (node->leftSubtree != nullptr)
		{
			node = node->leftSubtree;
		}
		return node;
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

					q.push(current->leftSubtree);
					q.push(current->rightSubtree);
				}
				else {
					std::cout << "null ";
				}
			}

			std::cout << std::endl;
		}
	}

	void inorder(Node* node)
	{
		if (node != nullptr)
		{
			inorder(node->leftSubtree);
			cout << node->data;
			inorder(node->rightSubtree);
		}
	}

	void in()
	{
		inorder(root);
	}
	
	void remove(int value)
	{
		delet(root, value);
	}
};

int main()
{
	AVLTree avlTree;

	avlTree.insert(50);
	avlTree.insert(30);
	avlTree.insert(70);
	avlTree.insert(20);
	avlTree.insert(60);
	avlTree.insert(100);
	avlTree.insert(90);

	avlTree.remove(30);
	avlTree.remove(100);
	avlTree.remove(50);

	return 0;
}