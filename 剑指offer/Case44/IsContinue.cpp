
int compare(const void *arg1, const void *arg2){
	return *(int*)arg1 - *(int*)arg2;
}

bool IsContinue(int *number,int length){
	if(NULL == number || length<1)
		return false;
	qsort(number,length,sizeof(int),compare);
	int numofZero = 0;
	for(int i=0;i<length;i++){
		if(number[i] == 0)
			numofZero++;
	}

	int small = numofZero;
	int big = small+1;
	int offset = 0;
	while(big<length){
		if(number[small]==number[big])
			return false;
		offset+= number[big]-number[small]-1;
		small=big;
		big++;
	}

	if(offset>numofZero)
		return false;
	else
		return true;
}