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

int countPrimeNumbersOfArr(int arr1[100], int length)
{
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (getPrimeNumber(arr1[i]) == enPrime::Prime)
		{
			counter++;
		}
	}
	return counter;
}

void copyPrimeNumbersOfArr(int arr[100], int primeArr[100], int length)
{
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (getPrimeNumber(arr[i]) == enPrime::Prime)
		{
			primeArr[counter] = arr[i];
			//cout << primeArr[counter] << endl;
			counter++;
		}
	}
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

	int arr[100]; int arr2[100]; int length;

	readArray(arr, length);
	copyPrimeNumbersOfArr(arr, arr2, length);
	int arr2Length = countPrimeNumbersOfArr(arr, length);

	
	cout << "Array 1 Elements : ";
	printArray(arr, length);
	cout << "Prime Numbers in Array2: \n";
	printArray(arr2, arr2Length);
	//copyPrimeNumbersOfArr(arr,arr2, length);

	return main();
}	