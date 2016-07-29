#include <iostream>
using std::cout;
using std::endl;

typedef struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
}ListNode;

ListNode *Merge(ListNode *list1,ListNode *list2){
	if(NULL == list1)
		return list2;

	if(NULL == list2)
		return list1;

	ListNode *pMergeHead = NULL;

	if(list1->m_nValue < list2->m_nValue){
		pMergeHead = list1;
		pMergeHead->m_pNext = Merge(list1->m_pNext,list2);
	}
	else{
		pMergeHead = list2;
		pMergeHead->m_pNext = Merge(list2->m_pNext,list1);
	}

	return pMergeHead;
}

ListNode* MergeNotRecursively(ListNode *list1,ListNode *list2){
	if(NULL == list1)
		return list2;
	if(NULL == list2)
		return list1;

	ListNode *node1 = list1;
	ListNode *pre1 = list1;
	ListNode *node2 = list2;
	ListNode *pre2 = list2;

	while(node1 != NULL && node2 != NULL){
		while(node1 != NULL && node1->m_nValue<node2->m_nValue){
			pre1 = node1;
			node1 = node1->m_pNext;
		}
		if(pre1->m_nValue < node2->m_nValue){
			pre1->m_pNext = node2;
		}

		if(node1 != NULL){
			while(node2 != NULL && node2->m_nValue<node1->m_nValue){
				pre2 = node2;
				node2 = node2->m_pNext;
			}
			if(pre2->m_nValue < node1->m_nValue){
			pre2->m_pNext = node1;
		   }
	    }
    }

    if(list1->m_nValue < list2->m_nValue)
    	return list1;
    else
    	return list2;
 }

void PrintList(ListNode *list){
	while(list!=NULL){
		cout<<list->m_nValue<<'\t';
		list = list->m_pNext;
	}
	cout<<endl;
}


int main(int argc, char const *argv[])
{
	ListNode node1;
	node1.m_nValue=4;
	ListNode node2;
	node2.m_nValue=5;
	ListNode node3;
	node3.m_nValue=6;
	ListNode node4;
	node4.m_nValue=9;
	node1.m_pNext = &node2;
	node2.m_pNext = &node3;
	node3.m_pNext = &node4;
	node4.m_pNext = NULL;
	PrintList(&node1);

	ListNode node5;
	node5.m_nValue=3;
	ListNode node6;
	node6.m_nValue=7;
	ListNode node7;
	node7.m_nValue=8;
	node5.m_pNext = &node6;
	node6.m_pNext = &node7;
	node7.m_pNext = NULL;
	PrintList(&node5);

	//ListNode *node = Merge(&node1,&node5);
	ListNode *node = MergeNotRecursively(&node1,&node5);
	PrintList(node);

	return 0;
}