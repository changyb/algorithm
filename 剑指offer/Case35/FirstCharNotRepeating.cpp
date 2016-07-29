#include <iostream>
using std::cout;
using std::endl;

char FirstCharNotRepeating(char *str){
	if(NULL == str)
		return '\0';

	unsigned int hashtable[256] = {0};

	for(char *ch=str;*ch!='\0';ch++){
		hashtable[*ch]++;
	}

	for(char *ch=str;*ch!='\0';ch++){
		if(hashtable[*ch] == 1)
			return *ch;
	}

	return '\0';
}



int main(int argc, char const *argv[])
{
	char *str = "abaccdeff";
	cout<<FirstCharNotRepeating(str)<<endl;
	return 0;
}