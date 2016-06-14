#include <iostream>

void ReplaceBlank(char a[],int len){
	if(NULL != a && len > 0){
		int length = 0;
		int blankCount = 0;
		while(a[length] != '\0'){
			if(a[length] == ' '){
				blankCount++;
			}
			length++;
		}

		int size=length+blankCount*2;

		if(size > len){
			return;
		}

		for(int i=length;i>=0;i--){
			if(a[i] == ' '){
				a[size--]='0';
				a[size--]='2';
				a[size--]='%';
			}
			else{
				a[size--]=a[i];
			}
		}
	}
}

int main(){
	using std::cout;
	using std::endl;
	char a[30] = "We are happy.";
	for(int i=0;a[i] != '\0';i++){
		cout<<a[i];
	}
	cout<<endl;

	ReplaceBlank(a,30);

	for(int i=0;a[i] != '\0';i++){
		cout<<a[i];
	}
	cout<<endl;

	return 1;
}
