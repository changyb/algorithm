#include <iostream>
using std::cout;
using std::endl;

typedef struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
}BinaryTreeNode;


void ConvertNode(BinaryTreeNode *node,BinaryTreeNode **pLastNode){
	if(NULL == node)
		return;

	if(NULL != node->left)
		ConvertNode(node->left,pLastNode);

	node->left = *pLastNode;
	if((*pLastNode) != NULL)
		(*pLastNode)->right = node;

	*pLastNode = node;

	if(NULL != node->right)
		ConvertNode(node->right,pLastNode);
}


BinaryTreeNode* ConvertTreeToDoubleLinkedList(BinaryTreeNode *node){
	if(NULL == node)
		return NULL;

	BinaryTreeNode *pLastNode = NULL;

	ConvertNode(node,&pLastNode);

	BinaryTreeNode *head = pLastNode;
	while(head != NULL && head->left != NULL){
		head = head->left;
	}

	return head;
}



BinaryTreeNode* ConvertTree(BinaryTreeNode *node,bool isleft){
	if(node->left == NULL && node->right == NULL)
		return node;
	BinaryTreeNode *left = NULL;
	BinaryTreeNode *right = NULL;

	if(node->left != NULL)
		left = ConvertTree(node->left,true);
	if(node->right != NULL)
		right = ConvertTree(node->right,false);

	if(left != NULL){
		left->right = node;
		node->left = left;
	}

	if(right != NULL){
		right->left = node;
		node->right = right;
	}

	if(isleft)
		return right!=NULL?right:node;
	else
		return left != NULL?left:node;

}

BinaryTreeNode* ConvertTreeToDoubleLinkedList1(BinaryTreeNode *node){
	if(NULL == node)
		return NULL;


	BinaryTreeNode *head = ConvertTree(node,false);
	while(head != NULL && head->left != NULL){
		head = head->left;
	}

	return head;
}


void PrintLinkList(BinaryTreeNode *head){
	BinaryTreeNode *begin = head;
	while(begin->right!= NULL){
		cout<<begin->m_nValue<<'\t';
		begin = begin->right;
	}

	cout<<begin->m_nValue<<endl;

	while(begin->left != NULL){
		cout<<begin->m_nValue<<'\t';
		begin = begin->left;
	}

	cout<<begin->m_nValue<<endl;
}


int main(){
	BinaryTreeNode node;
	node.m_nValue = 10;

	BinaryTreeNode node1;
	node1.m_nValue = 6;

	BinaryTreeNode node2;
	node2.m_nValue = 4;

	BinaryTreeNode node3;
	node3.m_nValue = 14;

	BinaryTreeNode node4;
	node4.m_nValue = 12;

	BinaryTreeNode node5;
	node5.m_nValue = 16;

	node.left = &node1;
	node.right = &node3;

	node1.left = &node2;
	node1.right = NULL;

	node2.right = NULL;
	node2.left = NULL;

	node3.left = &node4;
	node3.right = &node5;

	node4.left = NULL;
	node4.right = NULL;

	node5.left = NULL;
	node5.right = NULL;

	BinaryTreeNode *head = ConvertTreeToDoubleLinkedList1(&node);
	PrintLinkList(head);

	return 0;
}