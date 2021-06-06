#include "Tree.h"

using namespace std;

TreeNode::TreeNode():
	data(0), content("")
{
}

TreeNode::TreeNode(int d, std::string con):
	data(d), content(con)
{
	left = NULL;
	right = NULL;
}

TreeNode::TreeNode(int d):
	data(d)
{
	left = NULL;
	right = NULL;
}

void TreeNode::appendChild(TreeNode * child)
{
	children.push_back(child);
}

void TreeNode::setParent(TreeNode * parent)
{
	parent = parent;
}

std::string TreeNode::getContent()
{
	return content;
}

int TreeNode::getData()
{
	return data;
}

TreeNode* TreeNode::findNode(TreeNode* root, int findData)
{
	if (root == NULL || root->getData() == findData)
		return root;

	if(root->getData() < findData)
		return findNode(root->right, findData);
	
	return findNode(root->left, findData);
}

void TreeNode::printInOrder(TreeNode * root)
{
	if (root == NULL)
		return;

	printInOrder(root->left);
	cout << "data: " << root->getData() << endl;
	printInOrder(root->right);
}

void TreeNode::printPreOrder(TreeNode * root)
{
	if (root == NULL)
		return;

	cout << "data: " << root->getData() << endl;
	printPreOrder(root->left);
	printPreOrder(root->right);
}

void TreeNode::printPostOrder(TreeNode * root)
{
	if (root == NULL)
		return;

	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << "data: " << root->getData() << endl;
}

bool TreeNode::isBalanced(TreeNode * root, int* height)
{
	bool isBalanced = false;
	int rightDepth = 0;
	int leftDepth = 0;
	bool rightBalanced = false;
	bool leftBalanced = false;

	if (root == NULL)
	{
		return 0;
	}

	rightBalanced = TreeNode::isBalanced(root->right, &rightDepth);
	leftBalanced = TreeNode::isBalanced(root->left, &leftDepth);

	//cout << "rightDepth: " << rightDepth << endl;
	//cout << "leftDepth: " << leftDepth << endl;

	if (rightDepth > leftDepth)
		*height = rightDepth + 1;
	else
		*height = leftDepth + 1;

	if (abs(rightDepth - leftDepth) >= 2)
		return false;
	else
		rightBalanced && leftBalanced;
}

bool TreeNode::isSubTree(TreeNode * t1, TreeNode * t2)
{
	if (t2 == NULL)
		return true;
	
	return subTree(t1, t2);
}

bool TreeNode::subTree(TreeNode * t1, TreeNode * t2)
{
	while (t1 == NULL) return false;

	if (t1->getData() == t2->getData())
	{
		if (matchTree(t1, t2))
			return true;
	}
	
	bool leftSearch = subTree(t1->left, t2);
	bool rightSearch = subTree(t1->right, t2);

	return leftSearch || rightSearch;
}

bool TreeNode::matchTree(TreeNode * t1, TreeNode * t2)
{
	if (t1 == NULL && t2 != NULL)
		return false;
	else if (t1 != NULL && t2 == NULL)
		return false;
	else if (t1 == NULL && t2 == NULL)
		return true;
	else if (t1->getData() != t2->getData())
		return false;
	else
	{
		bool leftSearch = matchTree(t1->left, t2->left);
		bool rightSearch = matchTree(t2->right, t2->right);

		return leftSearch && rightSearch;
	}
}

int TreeNode::getDepth(TreeNode * node)
{
	int depthCounter = 0;

	while (node->parent != NULL)
	{
		node = node->parent;
		++depthCounter;
	}

	return depthCounter;
}

TreeNode * TreeNode::createMinimalBST(int arr[], int size)
{
	return addToBST(arr, 0, size-1, NULL);
}

TreeNode* TreeNode::addToBST(int arr[], int start, int end, TreeNode* parent)
{
	if (start > end)
		return NULL;

	int mid_index = (end + start) / 2;
	TreeNode* node = new TreeNode(arr[mid_index]);
	node->parent = parent;
	TreeNode* lChild = addToBST(arr, start, mid_index - 1, node);
	
	if (lChild != NULL)
	{
		node->left = lChild;
		lChild->parent = node;
	}
		
	TreeNode* rChild = addToBST(arr, mid_index + 1, end, node);

	if (rChild != NULL)
	{
		node->right = rChild;
		rChild->parent = node;
	}

	return node;
}

list<list<TreeNode*>> TreeNode::findLevelLinkedList(TreeNode * root)
{
	list<list<TreeNode*>> returnList;
	list<TreeNode*> rootList;
	list<TreeNode*>::iterator iter;
	rootList.push_back(root);
	returnList.push_back(rootList);

	while (true)
	{
		list<TreeNode*> tempList;
		for (iter = returnList.back().begin(); iter != returnList.back().end(); iter++)
		{
			if((*iter)->left != NULL)
				tempList.push_back((*iter)->left);
			if ((*iter)->right != NULL)
				tempList.push_back((*iter)->right);
		}

		if (tempList.size() != 0)
			returnList.push_back(tempList);
		else
			break;
	}

	return returnList;
}

TreeNode * TreeNode::findSuccessor(TreeNode * node)
{
	TreeNode* successorNode = node;

	if (node->right != NULL)
	{
		successorNode = node->right;
		while (successorNode->left != NULL)
		{
			successorNode = successorNode->left;
		}
	}
	else
	{
		if(node->parent->left == node)
			successorNode = node->parent;
		else if (node->parent->right == node)
		{
			while (true)
			{
				if (node->parent->left == node)
				{
					successorNode = node->parent;
					break;
				}
				node = node->parent;
			}
		}
	}

	return successorNode;
}

TreeNode * TreeNode::commonAncestor(TreeNode * root, TreeNode * node1, TreeNode * node2)
{
	int node1Depth = root->getDepth(node1);
	int node2Depth = root->getDepth(node2);

	while (node1Depth != node2Depth)
	{
		if (node1Depth > node2Depth)
		{
			node1 = node1->parent;
			--node1Depth;
		}
		else
		{
			node2 = node2->parent;
			--node2Depth;
		}
	}

	while (node1->parent != NULL && node2->parent != NULL)
	{
		if (node1 == node2)
			return node1;
		else if (node1->parent == node2->parent)
			return node1->parent;
		else
		{
			node1 = node1->parent;
			node2 = node2->parent;
		}
	}

	return NULL;
}
