#include<iostream>
#include<cstdlib>
using namespace std;



enum enPrime{Prime=1, NotPrime};
enPrime getPrimeNumber(int num)
{
	if (num == 1 || num == 2)
	{
		return enPrime::Prime;
	}

	for (int i = 2; i <= round(num / 2); i++)
	{
		if (num % i == 0)
		{
			return enPrime::NotPrime;
		}
	}

	return enPrime::Prime;
}

int getRandomNumber(int From, int To)
{
	return rand() % (To - From +1) + From;
}

void readArray(int arr[100], int &length)
{
	cout << "Please enter array length?\n";
	cin >> length;

	for (int i = 0; i < length; i++)
	{
		arr[i] =  getRandomNumber(1, 100);
	}
}

//int countPrimeNumbersOfArr(int arr1[100], int length)
//{
//	int counter = 0;
//	for (int i = 0; i < length; i++)
//	{
//		if (getPrimeNumber(arr1[i]) == enPrime::Prime)
//		{
//			counter++;
//		}
//	}
//	return counter;
//}

void copyPrimeNumbersOfArr(int arr[100], int primeArr[100], int length,int &arr2Length)
{
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (getPrimeNumber(arr[i]) == enPrime::Prime)
		{
			primeArr[counter] = arr[i];
			counter++;
		}
	}
	arr2Length = counter;
}

void printArray(int arr[100], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	//int arr[100]; int arr2[100]; int length; int arr2Length;
	//
	//readArray(arr, length);
	//copyPrimeNumbersOfArr(arr, arr2, length, arr2Length);
	////int arr2Length = countPrimeNumbersOfArr(arr, length);
	//
	//
	//cout << "Array 1 Elements : ";
	//printArray(arr, length);
	//cout << "Prime Numbers in Array2: \n";
	//printArray(arr2, arr2Length);

	cout << getPrimeNumber(97)<<"\n";
	cout << getPrimeNumber(93)<<"\n";
	cout << getPrimeNumber(19)<<"\n";
	cout << getPrimeNumber(25)<<"\n";
	cout << getPrimeNumber(73)<<"\n";

	return 0;
}	

/*Array 1 Elements : 17 84 42 19 26
Prime Numbers in Array2:
17

Array 1 Elements : 61 13 43 1 50
Prime Numbers in Array2:
61 13 43

Array 1 Elements : 97 93 19 25 73
Prime Numbers in Array2:
97 19 73

*/