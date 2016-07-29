#include <iostream>
using std::endl;
using std::cout;

void ReverseStr(char *begin,char *end){
	while(begin<=end){
		char temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
}

void ReverseString(char *str){
	char *begin = str;
	char *end = str;

	while(*end != '\0'){
		end++;
	}

	end--;

	ReverseStr(begin,end);
    
    end = begin;

	while(*begin!='\0'){
		if(*begin == ' '){
			begin++;
			end++;
		}
		else if(*end =='\0' || *end == ' '){
			--end;
			ReverseStr(begin,end);
			begin = ++end;
		}
		else
			end++;
	}
}

int main(int argc, char const *argv[])
{
	char str[] = "I am a student. ";
	cout<<str<<endl;
	ReverseString(str);
	cout<<str<<endl;
	return 0;
}