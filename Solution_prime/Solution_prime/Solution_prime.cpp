#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>

using namespace std;
bool check[1000];
// 소수 개수 구하기
bool Eratos(int count)
{
	for (int i = 2; i * i < count; i++)
	{
		if (check[i])
		{
			for (int j = i * i; j < count; j += i)
			{
				check[j] = false;
			}
		}
	}

}

bool isPrime(int data)
{
	if (data < 2)return false;
	for (int i = 2; i * i <= data; i++)
	{
		if (data % i == 0)return false;
	}
	return true;
}

int main()
{
	const int PrimeNumbers_Before = 100'000'000;
	int hardWareCoreCount = thread::hardware_concurrency();

	cout << hardWareCoreCount << endl;

}