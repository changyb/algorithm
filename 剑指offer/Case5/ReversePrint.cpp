#include <stack>
#include <iostream>
using std::stack;
using std::cout;
using std::endl;

typedef struct ListNode
{
	int m_nKey;
	ListNode *m_pNext;
}ListNode;

void ReversePrint(ListNode *pHead){
	if(NULL != pHead){
		stack<int> stackList;
		ListNode *node = pHead;
		while(NULL != node){
			stackList.push(node->m_nKey);
			node = node->m_pNext;
		}

		while(stackList.size() > 0){
			cout<<stackList.top()<<" ";
			stackList.pop();
		}
		cout<<endl;
	}
}

void ReversePrint_Recursively(ListNode *pHead){
	if(NULL != pHead){
		ReversePrint_Recursively(pHead->m_pNext);
		cout<<pHead->m_nKey<<" ";
	}
}



int main(){
	ListNode pHead;
	ListNode p1;
	ListNode p2;
	ListNode p3;
	pHead.m_nKey=10;
	p1.m_nKey=3;
	p2.m_nKey=5;
	p3.m_nKey=30;
	pHead.m_pNext=&p1;
	p1.m_pNext=&p2;
	p2.m_pNext=&p3;
	p3.m_pNext=NULL;

	ReversePrint(&pHead);
	ReversePrint(NULL);

	ReversePrint_Recursively(&pHead);
	ReversePrint_Recursively(NULL);
	return 0;
}