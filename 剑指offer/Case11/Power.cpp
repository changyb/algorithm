#include <iostream>
using namespace std;

bool b_InvaildInput;

double PowerWithUnexponent(double base,unsigned int exponent){
	if(exponent == 0)
		return 1.0f;
	else if(exponent == 1)
		return base;

	double r = PowerWithUnexponent(base,exponent>>1);
	r*=r;
	if(exponent&0x1)
		r*=base;

	return r;
}


double Power(double base,int exponent){

	b_InvaildInput = false;
	if((base<0.0000001 && base > -0.0000001)&&exponent<0){
		b_InvaildInput = true;
		return 0.0f;
	}
	b_InvaildInput = false;
	bool isnagative = false;
	unsigned int unexponent;
	if(exponent<0){
		isnagative = true;
		unexponent = -exponent;
	}
	else
		unexponent = exponent;

	double r = PowerWithUnexponent(base,unexponent);

	if(isnagative)
		r = 1/r;

	return r;
}


int main(int argc, char const *argv[])
{
	cout<<Power(2.0,6);
	cout<<" "<<b_InvaildInput<<endl;
	cout<<Power(0,-4);
	cout<<" "<<b_InvaildInput<<endl;
	cout<<Power(0,5);
	cout<<" "<<b_InvaildInput<<endl;
	cout<<Power(2.0,-2);
	cout<<" "<<b_InvaildInput<<endl;

	return 0;
}