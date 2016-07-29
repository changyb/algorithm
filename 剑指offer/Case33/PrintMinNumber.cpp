#include <iostream>
#include <algorithm>
#include <cstring>
using std::cout;
using std::endl;

const int g_MaxNumberLength = 10;

char *g_str1 = new char[g_MaxNumberLength*2+1];
char *g_str2 = new char[g_MaxNumberLength*2+1];

int compare(const void* snumber1, const void * snumber2){
	strcpy(g_str1,*(const char **)snumber1);
	strcat(g_str1,*(const char **)snumber2);

	strcpy(g_str2,*(const char **)snumber2);
	strcat(g_str2,*(const char **)snumber1);

	return strcmp(g_str1,g_str2);
}


void PrintMinNumber(int array[],int length){
	if(NULL==array || length<=0)
		return;

	//char **snumber = (char **)(new int[length]);
	char **snumber = new char*[length];
	for(int i=0;i<length;i++){
		snumber[i] = new char[g_MaxNumberLength+1];
		sprintf(snumber[i],"%d",array[i]);
	}

	qsort(snumber,length,sizeof(char*),compare);

	for(int i=0;i<length;i++){
		cout<<snumber[i];
	}
	cout<<endl;

	for(int i=0;i<length;i++)
		delete[] snumber[i];
	delete[] snumber;
}


int main(int argc, char const *argv[])
{
	int array[] = {3,32,321};
	PrintMinNumber(array,3);
	return 0;
}