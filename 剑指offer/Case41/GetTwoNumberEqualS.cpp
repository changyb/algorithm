bool GetTwoNumberEquals(int *array,int length,int s,int &num1,int &num2){
	if(NULL == array || length <=0)
		return false;

	bool isFind = false;

	int begin = 0;
	int end = length-1;

	while(begin<end){
		int sum = array[begin]+array[end];
		if(sum>s)
			end--;
		else if(sum < s)
			begin++;
		else{
			num1 = array[begin];
			num2 = array[end];
			isFind = true;
			break;
		}
	}

	return isFind;
}