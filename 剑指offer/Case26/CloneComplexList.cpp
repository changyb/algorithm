typedef struct ComplexListNode
{
	int m_nValue;
	ComplexListNode *m_pNext;
	ComplexListNode *m_pSibling;
};

void CloneComplexListNode(ComplexListNode *head){
	if(NULL == head)
		return;
	ComplexListNode *node = head;
	while(node != NULL){
		ComplexListNode *cloneNode = new ComplexListNode;
		cloneNode->m_nValue = node->m_nValue;
		cloneNode->m_pSibling = NULL;
		cloneNode->m_pNext = node->m_pNext;
		node->m_pNext = cloneNode;
		node = cloneNode->m_pNext;
	}
}

void SetSibling(ComplexListNode *head){
	if(NULL == head)
		return;

	ComplexListNode *node = head;
	ComplexListNode *cloneNode = head->m_pNext;
	while(NULL != node){
		if(node->m_pSibling != NULL){
			cloneNode->m_pSibling = node->m_pSibling->m_pNext;
		}

		node = cloneNode->m_pNext;
		cloneNode = node->m_pNext;
	}
}


ComplexListNode* SplitComplexList(ComplexListNode *head){
	if(NULL == head)
		return NULL;

	ComplexListNode *node = head;
	ComplexListNode *rhead = head->m_pNext;
	ComplexListNode *cloneNode = rhead;

	while(NULL != cloneNode->m_pNext){
		node->m_pNext = cloneNode->m_pNext;
		node = cloneNode->m_pNext;
		cloneNode->m_pNext = node->m_pNext;
		cloneNode = node->m_pNext;
	}

	node->m_pNext = NULL;

	return rhead;
}



ComplexListNode* Clone(ComplexListNode *head){
	CloneComplexListNode(head);
	SetSibling(head);
	return SplitComplexList(head);
}