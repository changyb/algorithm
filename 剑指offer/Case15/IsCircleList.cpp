#include <iostream>
using std::endl;
using std::cout;

typedef struct ListNode{
	int m_nValue;
	ListNode *m_pNext;
}ListNode;

bool IsCircleList(ListNode *list){
	if(list==NULL)
		return false;

	ListNode *lbegin = list;
	ListNode *lend = list;
	while(lend->m_pNext != NULL && lbegin->m_pNext != NULL &&
		lbegin->m_pNext->m_pNext != NULL){
		lend = lend->m_pNext;
	    lbegin = lbegin->m_pNext->m_pNext;
	    if(lbegin == lend)
	    	return true;
	}

	return false;
}

int main(int argc, char const *argv[])
{
	ListNode *node1 = new ListNode;
	ListNode *node2 = new ListNode;
	ListNode *node3 = new ListNode;
	node1->m_pNext = node2;
	node2->m_pNext = node3;
	node3->m_pNext = NULL;
	cout<<"Is CircleList:"<<IsCircleList(node1)<<endl;
	delete node1;
	delete node2;
	delete node3;

	ListNode *node11 = new ListNode;
	ListNode *node12 = new ListNode;
	ListNode *node13 = new ListNode;
	ListNode *node14 = new ListNode;
	ListNode *node15 = new ListNode;
	node11->m_pNext = node12;
	node12->m_pNext = node13;
	node13->m_pNext = node14;
	node14->m_pNext = node15;
	node15->m_pNext = node13;
	cout<<"Is CircleList:"<<IsCircleList(node11)<<endl;
	delete node11;
	delete node12;
	delete node13;
	delete node14;
	delete node15;
    return 0;
}