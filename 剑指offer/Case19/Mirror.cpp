#include <iostream>
#include <stack>
using std::cout;
using std::endl;

typedef struct TreeNode
{
	int m_nValue;
	TreeNode *left;
	TreeNode *right;
}TreeNode;

TreeNode* Mirror(TreeNode *tree){
	if(tree == NULL)
		return NULL;

	if(tree->left==NULL&&tree->right==NULL)
		return tree;

	TreeNode *right = Mirror(tree->left);
	TreeNode *left = Mirror(tree->right);
	tree->left = left;
	tree->right = right;
	return tree;
}

void PrintList(TreeNode *tree){
	if(tree != NULL)
	{
		cout<<tree->m_nValue<<'\t';
		PrintList(tree->left);
	    PrintList(tree->right);
	}

    /*using std::stack;
	if(tree == NULL)
		return;
	stack<TreeNode *> treeList;
	treeList.push(tree);
	while(treeList.size()>0){
		TreeNode *node = treeList.top();
		treeList.pop();
		cout<<node->m_nValue<<'\t';
		if(node->right != NULL)
			treeList.push(node->right);
		if(node->left != NULL)
			treeList.push(node->left);
	}*/
	
}

int main(int argc, char const *argv[])
{
	TreeNode root1;
	root1.m_nValue = 1;
	TreeNode node2;
	node2.m_nValue = 2;
	TreeNode node3;
	node3.m_nValue = 3;
	TreeNode node4;
	node4.m_nValue = 4;
	TreeNode node5;
	node5.m_nValue = 5;
	TreeNode node6;
	node6.m_nValue = 6;
	TreeNode node7;
	node7.m_nValue = 7;
	root1.left = &node2;
	root1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node5.left = &node6;
	node5.right = &node7;

	node3.left = NULL;
	node3.right = NULL;
	node4.left = NULL;
	node4.right = NULL;
	node6.left = NULL;
	node6.right = NULL;
	node7.left = NULL;
	node7.right = NULL;

	TreeNode *root = Mirror(&root1);
	PrintList(root);

	return 0;
}