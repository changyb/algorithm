#include <iostream>
#include <cmath>
using std::endl;
using std::cout;

int g_MaxValue = 6;

void PrintProbability(int number){
	if(number<1)
		return;

	int *pProbalities[2];
	pProbalities[0] = new int[g_MaxValue*number + 1];
	pProbalities[1] = new int[g_MaxValue*number + 1];
	for(int i=0; i<g_MaxValue*number +1;++i){
		pProbalities[0] = 0;
		pProbalities[1] = 0;
	}

	int flag = 0;
	for(int i=1;i<g_MaxValue;i++)
		pProbalities[flag][i] = 1;

	for(int k=2; k<= number; ++k){
		for(int i=0;i<k;i++)
			pProbalities[1-flag][i] = 0;

		for(int i=k;i<=g_MaxValue*k;++i){
			pProbalities[1-flag][i] = 0;
			for(int j=1;j<=i&&j<=g_MaxValue;j++)
				pProbalities[1-flag][i] += pProbalities[flag][i-j];
		}
		flag = 1-flag;
	}

	double total = pow((double)g_MaxValue, number);
	for(int i=number; i<=g_MaxValue*number;++i){
		double ratio = (double)pProbalities[flag][i]/total;
		cout<<i<<":"<<ratio<<endl;
	}

	delete[] pProbalities[0];
	delete[] pProbalities[1];
}

int main(int argc, char const *argv[])
{
	PrintProbability(6);
	return 0;
}