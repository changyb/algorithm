typedef struct ListNode{
	int m_nValue;
	ListNode *m_pNext;
}ListNode;


ListNode* FindKthToTail(ListNode *list,int k){
	if(list == NULL || k <=0){
		return NULL;
	}

	ListNode *lbegin = list;
	ListNode *lend = list;
	for(int i=0;i<k-1;i++){
		if(lend->m_pNext != NULL){
			lend = lend->m_pNext;
		}
		else
			return NULL;
	}

	while(lend->m_pNext != NULL){
		lend = lend->m_pNext;
		lbegin = lbegin->m_pNext;
	}

	return lend;
}