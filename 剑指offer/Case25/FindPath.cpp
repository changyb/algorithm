#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

typedef struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
}BinaryTreeNode;




void FindPath(BinaryTreeNode *root,vector<int> &pathValue,int sum,int value){
	value += root->m_nValue;
	pathValue.push_back(root->m_nValue);
	if(value == sum && root->left == NULL && root->right == NULL){
		for(unsigned int i=0;i<pathValue.size();i++){
			cout<<pathValue[i]<<'\t';
		}
		cout<<endl;
	}

	if(root->left != NULL)
		FindPath(root->left,pathValue,sum,value);
	if(root->right != NULL)
		FindPath(root->right,pathValue,sum,value);

	pathValue.pop_back();
}

int FindPath(BinaryTreeNode *root,int sum){
	if(root == NULL)
		return -1;
	vector<int> pathValue;
	int value = 0;
	FindPath(root,pathValue,sum,value);
	return 0;
}


int main(int argc, char const *argv[])
{
	BinaryTreeNode root;
	root.m_nValue = 10;
	BinaryTreeNode tree1;
	tree1.m_nValue = 5;
	BinaryTreeNode tree2;
	tree2.m_nValue = 12;
	BinaryTreeNode tree3;
	tree3.m_nValue = 4;
	BinaryTreeNode tree4;
	tree4.m_nValue = 7;

	root.left = &tree1;
	root.right = &tree2;
	tree1.left = &tree3;
	tree1.right = &tree4;
	tree2.left = NULL;
	tree2.right = NULL;
	tree3.left = NULL;
	tree3.right = NULL;
	tree4.left = NULL;
	tree4.right = NULL;

	FindPath(&root,22);
	return 0;
}