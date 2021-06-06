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
  
  cin.get();
	return 0;
}
