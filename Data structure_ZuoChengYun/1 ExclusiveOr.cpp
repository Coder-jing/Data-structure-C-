#include<iostream>
using namespace std;

void changeAandB(int &a,int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int getOddOne(const int arr[],int len)
{
	int num=0;
	for (int i = 0;i < len;i++)
	{
		num = num ^ arr[i];
	}
	return num;
}

void getOddTwo(const int arr[], int len,int num[])
{
	int eor = 0;
	for (int i = 0;i < len;i++)
	{
		eor ^= arr[i];
	}
	int eor2 = eor & (~eor + 1);
	int eor3 = 0;
	for (int i = 0;i < len;i++)
	{
		if ((eor2 & arr[i]) != 0)
		{
			eor3 ^= arr[i];
		}
	}
	num[0] = eor3;
	num[1] = eor3^eor;
}

int main1()
{

	//getOddTwo 
	/*int arr[] = { 1,1,2,3,4,5,6,6,5,4,3,7 };
	int len = sizeof(arr) / sizeof(int);
	int num[2] = { 0 };
	getOddTwo(arr, len,num);
	cout << "num[0] =" << num[0] << endl;
	cout << "num[1] =" << num[1] << endl;*/
	


	//getOddOne
	/*int arr[] = { 1,1,2,3,4,5,6,6,5,4,3 };
	int len = sizeof(arr) / sizeof(int);
	int num=getOddOne(arr,len);
	cout << "num = " << num << endl;*/

	//changeAandB
	/*int a = 10, b = 20;
	cout << "before:a = " << a << endl;
	cout << "before:b = " << b << endl;
	changeAandB(a, b);
	cout << "after:a = " << a << endl;
	cout << "after:b = " << b << endl;*/
	return 0;
}