#include <iostream>
#include <deque>
using std::cout;
using std::endl;
using std::deque;

void AllPermutation(deque<char> &deqArray,char outPut[],int start){
	if(deqArray.size()==0){
		for(int i=0;i<start;i++)
			cout<<outPut[i]<<'\t';
		cout<<endl;
		return;
	}

	int n = deqArray.size();
	for(int i=0;i<n;i++){
		char c = deqArray.front();
		deqArray.pop_front();
		outPut[start] = c;
		AllPermutation(deqArray,outPut,start+1);
		deqArray.push_back(c);
	}
}


void Permutation(char array[],int n){
	if(array==NULL || n<=0)
		return;

	char *outPut = new char[n];
	deque<char> deqArray;
	for(int i=0;i<n;i++){
		outPut[i] = array[i];
		deqArray.push_back(array[i]);
	}

	AllPermutation(deqArray,outPut,0);
	delete[] outPut;
}

void PermutationShort(char *pStr,char *pBegin){
	if(*pBegin == '\0'){
		cout<<pStr<<endl;
	}
	else{
		for(char *ch=pBegin;*ch!='\0';ch++){
			char temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;

			PermutationShort(pStr,pBegin+1);

			temp = *pBegin;
			*pBegin = *ch;
			*ch = temp;
		}
		
	}
}


void PermutationShort(char *pStr){
	if(NULL == pStr)
		return;
	PermutationShort(pStr,pStr);
}

int main(int argc, char const *argv[])
{
	char a[]={'a','b','c','d','\0'};
	PermutationShort(a);
	return 0;
}