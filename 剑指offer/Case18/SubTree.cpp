#include <iostream>
using std::cout;
using std::endl;

typedef struct Tree
{
	int value;
	Tree *left;
	Tree *right;
}Tree;

bool IsSubTreeCompare(Tree *A,Tree *B){
	if(NULL ==B)
		return true;

	if(A!=NULL && B != NULL && A->value == B->value)
		return IsSubTreeCompare(A->left,B->left)&&IsSubTreeCompare(A->right,B->right);
	else
		return false;
}

bool IsSubTree(Tree *A,Tree *B){
	if(B == NULL)
		return true;

	if(NULL == A && B != NULL)
		return false;
	
	return IsSubTreeCompare(A,B) || IsSubTree(A->left,B) || IsSubTree(A->right,B);
}

int main(int argc, char const *argv[])
{
	Tree root1;
	root1.value = 1;
	Tree node2;
	node2.value = 2;
	Tree node3;
	node3.value = 3;
	Tree node4;
	node4.value = 4;
	Tree node5;
	node5.value = 5;
	Tree node6;
	node6.value = 6;
	Tree node7;
	node7.value = 7;
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

	Tree root2;
	root2.value=5;
	Tree node21;
	node21.value = 6;
	Tree node22;
	node22.value = 7;
	root2.left = &node21;
	root2.right = NULL;
	node21.left = NULL;
	node21.right = NULL;
	node22.left = NULL;
	node22.right = NULL;

	cout<<IsSubTree(&root1,&root2);


	return 0;
}