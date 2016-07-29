
typedef struct BinaryTree
{
	int m_nValue;
	BinaryTree *pLeft;
	BinaryTree *pRight;
}BinaryTree;

bool IsBalancedTree(BinaryTree *node,int &depth){
	if(NULL == node){
		depth = 0;
		return true;
	}

	int left;
	int right;

	if(IsBalancedTree(node->pLeft,left)&&IsBalancedTree(node->pRight,right)){
		depth = (left>right?left:right)+1;
		int diff = left-right;
		if(diff >1 || diff <-1)
			return false;
		else
			return true;
	}

	return false;
}