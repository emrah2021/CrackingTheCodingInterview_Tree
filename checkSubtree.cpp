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
	int sortedArr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	TreeNode* sortedTree = new TreeNode();
	sortedTree = sortedTree->createMinimalBST(sortedArr, 10);
	int sortedArr2[5] = { 5,6,7,8,9 };
	TreeNode* sortedTree2 = new TreeNode();
	sortedTree2 = sortedTree2->createMinimalBST(sortedArr2, 5);
	sortedTree->printInOrder(sortedTree);
	sortedTree->printPreOrder(sortedTree);
  
	cout << "subtree : " << sortedTree->isSubTree(sortedTree, sortedTree2) << endl;
  
  cin.get();
	return 0;
}
