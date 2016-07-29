
void ReverseStr(char *begin,char *end){
	while(begin<=end){
		char temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
}

char *LeftRotateString(char *str, int n){
	if(str != NULL){
		int length = static_cast<int>(strlen(str));
		if(length > 0 && n > 0 && n< length){
			char *pfirstStart = str;
			char *pfirstEnd = str+n-1;
			char *psecondStart = str+n;
			char *psecondEnd = str+length-1;

			ReverseStr(pfirstStart,pfirstEnd);
			ReverseStr(psecondStart,psecondEnd);
			ReverseStr(pfirstStart,psecondEnd);
		}
	}

	return str;
}