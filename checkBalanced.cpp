#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <bitset>
#include "Node.h"
#include "Stack.h"
#include "Tree.h"

using namespace std;

int main()
{
	TreeNode* root = new TreeNode(1,"1");
	TreeNode* l1 = new TreeNode(2, "2");
	TreeNode* r1 = new TreeNode(3, "3");
	TreeNode* l11 = new TreeNode(4, "4");
	TreeNode* l12 = new TreeNode(5, "5");
	TreeNode* r11 = new TreeNode(6, "6");
	TreeNode* l111 = new TreeNode(7, "7");
	TreeNode* l1111 = new TreeNode(8, "8");

	root->left = l1;
	root->right = r1;
	l1->left = l11;
	l1->right = l12;
	r1->left = r11;
	l11->left = l111;
	l111->right = l1111;
	
	int height;
	bool balanced = root->isBalanced(root, &height);
	cout << "balanced: " << balanced << endl;
  
  cin.get();
	return 0;
}
