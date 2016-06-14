#include <iostream>
#include <cassert>
using std::cout;
using std::endl;

typedef struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;	
}BinaryTreeNode;

void DeleteTree(BinaryTreeNode *node){
	if(node != NULL){
		DeleteTree(node->m_pLeft);
		DeleteTree(node->m_pRight);
		delete node;
	}

}

void FrontPrintTree(BinaryTreeNode *node){
	if(node != NULL){
		cout<<node->m_nValue<<" ";
		FrontPrintTree(node->m_pLeft);
		FrontPrintTree(node->m_pRight);
	}	
}

int FindMiddle(int MiddleArray[],int left,int right,int value){
	int returnValue = -1;
	for(int i=left;i<=right;i++){
		if(MiddleArray[i] == value){
			returnValue = i;
			break;
		}
	}

	return returnValue;
}

BinaryTreeNode *BuildTree(int FrontArray[],int MiddleArray[],int left,int right,int &current){
	if(left>right){
		return NULL;
	}

	BinaryTreeNode *node = new BinaryTreeNode;
	node->m_nValue = FrontArray[current];
	int middle = FindMiddle(MiddleArray,left,right,FrontArray[current]);
	assert(middle != -1);
	current++;
	node->m_pLeft = BuildTree(FrontArray,MiddleArray,left,middle-1,current);
	node->m_pRight = BuildTree(FrontArray,MiddleArray,middle+1,right,current);
	return node;
}

BinaryTreeNode *MakeBinaryTree(int FrontArray[],int MiddleArray[],int length){
	int current = 0;
	return BuildTree(FrontArray,MiddleArray,0,length-1,current);
}


int main(){
	//int FrontArray[] = {1,2,4,7,3,5,6,8};
	//int MiddleArray[] = {4,7,2,1,5,3,8,6};
	int FrontArray[] = {1};
	int MiddleArray[] = {1};
	BinaryTreeNode *root = MakeBinaryTree(FrontArray,MiddleArray,1);
	FrontPrintTree(root);
	DeleteTree(root);
}