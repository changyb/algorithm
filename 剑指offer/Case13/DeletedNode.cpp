#include <iostream>
using std::cout;
using std::endl;

typedef struct ListNode
{
	int value;
	ListNode *next;
}ListNode;

void DeleteNode(ListNode **pHead,ListNode *pDeletedNode){
	if(pHead == NULL || pDeletedNode == NULL)
		return;

	if(pDeletedNode->next == NULL && pDeletedNode == *pHead){
		delete pDeletedNode;
		*pHead = NULL;
		pDeletedNode = NULL;
	}
	else if(pDeletedNode->next == NULL){
		ListNode *pNext = *pHead;
		while(pNext->next!=pDeletedNode){
			pNext = pNext->next;
		}
		pNext->next = pDeletedNode->next;
		delete pDeletedNode;
		pDeletedNode = NULL;
	}
	else{
		ListNode *pNext = pDeletedNode->next;
		pDeletedNode->value = pNext->value;
		pDeletedNode->next = pNext->next;
		delete pNext;
	}
}

void PrintList(ListNode *pHead){
	if(pHead == NULL)
		return;

	while(pHead != NULL){
		cout<<pHead->value<<",";
		pHead = pHead->next;
	}
	cout<<endl;
}


int main(int argc, char const *argv[])
{
	ListNode *pHead = new ListNode;
	pHead->value = 1;
	ListNode *node1 = new ListNode;
	node1->value = 2;
	ListNode *node2 = new ListNode;
	node2->value = 3;
	ListNode *node3 = new ListNode;
	node3->value = 4;
	pHead->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;


    PrintList(pHead);
	DeleteNode(&pHead,node3);
	PrintList(pHead);
	DeleteNode(&pHead,node1);
	PrintList(pHead);
	DeleteNode(&pHead,pHead);
	PrintList(pHead);
	DeleteNode(&pHead,pHead);
	PrintList(pHead);
	return 0;
}