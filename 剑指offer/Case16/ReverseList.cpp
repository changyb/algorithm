#include <iostream>
using std::cout;
using std::endl;

typedef struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
}ListNode;

ListNode* ReverseListRecursively(ListNode *list,ListNode **head){
	if(list->m_pNext == NULL){
		*head = list;
		return list;
	}

	ListNode *node = ReverseListRecursively(list->m_pNext,head);
	node->m_pNext = list;
	return list;
}

ListNode *ReverseList(ListNode *list){
	if(list == NULL || list->m_pNext == NULL)
		return list;
	ListNode *head = NULL;
	ReverseListRecursively(list,&head);
	list->m_pNext = NULL;
	return head;
}

void PrintList(ListNode *list){
	if(list == NULL)
		return;
	ListNode *plist = list;
	while(plist!=NULL){
		cout<<plist->m_nValue<<"\t";
		plist = plist->m_pNext;
	}
	cout<<endl;
}

ListNode * ReverseListNotRecursively(ListNode *list){
	if(NULL == list)
		return list;
	ListNode *preList = list;
	ListNode *currentlist = list->m_pNext;
	list->m_pNext = NULL;

	while(currentlist!=NULL){
		ListNode *nextList = currentlist->m_pNext;
		currentlist->m_pNext = preList;
	    preList = currentlist;
	    currentlist = nextList;
	}

	return preList;
}

int main(int argc, char const *argv[])
{
	ListNode node1;
	node1.m_nValue=1;
	ListNode node2;
	node2.m_nValue=2;
	ListNode node3;
	node3.m_nValue=3;
	ListNode node4;
	node4.m_nValue=4;
    node1.m_pNext = &node2;
    node2.m_pNext = &node3;
    node3.m_pNext = &node4;
    node4.m_pNext = NULL;
    PrintList(&node1);

    //ListNode *head = ReverseList(&node1);
    ListNode *head = ReverseListNotRecursively(&node1);
    PrintList(head);

	return 0;
}


