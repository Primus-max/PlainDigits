//  Написать функцию, возвращающую количество простых чисел в передаваемом ей массиве.


#include <iostream>
#include <windows.h>
#include <random>

using namespace std;


template <typename T>
void FillArray(T arr[], int size);

template <typename T>
void PrintArray(T arr[], int size);


template <typename T>
int CountPlainsInArray(T arr[], int size);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int sizze = 30;
	int Array[sizze];

	FillArray(Array, sizze);
	cout << "Массив до предобразования :" << endl;
	PrintArray(Array, sizze);
		
	cout << "В массиве простых чисел  : " << CountPlainsInArray(Array, sizze) << endl;	
}


template <typename T>
void FillArray(T arr[], int size) {
	random_device Random;

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = Random() % (100 + 50) - 50;
	}
}

template <typename T>
void PrintArray(T arr[], int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

template <typename T>
int CountPlainsInArray(T arr[], int size) {
	int count = 0;

	for (int i = 0; i < size; ++i) {
		bool isPlane = true;
		for (int j = 2; j <= sqrt(arr[i]); ++j) {
			if (arr[i] % j == 0) {
				isPlane = false;
				break;
			}
		}

		if (isPlane) {
			++count;
		}
	}

	return count;
}