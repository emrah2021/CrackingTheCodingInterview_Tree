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
	sortedTree->printInOrder(sortedTree);
	sortedTree->printPreOrder(sortedTree);
	TreeNode* foundNode1 = sortedTree->findNode(sortedTree, 4);
	TreeNode* foundNode2 = sortedTree->findNode(sortedTree, 3);
	TreeNode* foundNode3 = sortedTree->findNode(sortedTree, 9);
	cout << "foundNode data: " << foundNode3->getData() << endl;
	TreeNode* successorNode = sortedTree->findSuccessor(foundNode2);
	cout << "successorNode data: " << successorNode->getData() << endl;
  
  cin.get();
	return 0;
}
