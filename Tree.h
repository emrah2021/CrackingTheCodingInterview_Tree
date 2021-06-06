#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include "Node.h"

using namespace std;

class TreeNode
{
	int data;
	std::string content;
public:
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	std::vector<TreeNode *> children;
	TreeNode();
	TreeNode(int d);
	TreeNode(int d, std::string con);
	void appendChild(TreeNode *child);
	void setParent(TreeNode *parent);
	std::string getContent();
	int getData();
	TreeNode* TreeNode::findNode(TreeNode* root, int findData);
	void printInOrder(TreeNode* root);
	void printPreOrder(TreeNode* root);
	void printPostOrder(TreeNode* root);
	bool isBalanced(TreeNode *root, int *height);
	bool isSubTree(TreeNode *t1, TreeNode *t2);
	bool subTree(TreeNode * t1, TreeNode * t2);
	bool matchTree(TreeNode * t1, TreeNode * t2);
	int getDepth(TreeNode* node);
	TreeNode* createMinimalBST(int arr[], int size);
	TreeNode* addToBST(int arr[], int start, int end, TreeNode* parent);
	list<list<TreeNode*>> findLevelLinkedList(TreeNode* root);
	TreeNode* findSuccessor(TreeNode* node);
	TreeNode* commonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2);
};

