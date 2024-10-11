#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* p, const int size, const int Low, const int High,int i)
{
	if (i < size) {
		p[i] = Low + rand() % (High - Low + 1);
		Create(p, size, Low, High, i + 1);
	}
		
}
void Print(int* p, const int size, int i)
{
	if (i < size) {
		cout << setw(4) << p[i];
		Print(p, size, i + 1);
	}
	else 
	cout << endl;

}
int Max(int* a, const int size,int i, int max)
{
	
	if (a[i] > max)
		max = a[i];
	if (i < size - 1)
		return Max(a, size, i + 1, max);
	else
		return max;

}
int Min(int* a, const int size, int i, int min)
{

	if (a[i] < min)
		min = a[i];
	if (i < size - 1)
		return Min(a, size, i + 1, min);
	else
		return min;
}
int Sum(int* a, const int size, int i, int max, int min)
{
	if (i < size) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
		return Sum(a, size, i + 1, max, min);  
	}
	else {
		return max + min;  
	}
}
void Replace(int* p, const int size,int i, int maxi, int mini)
{
	if (i < size) {
		if (p[i] > p[maxi])
			maxi = i;
		if (p[i] < p[mini])
			mini = i;
		Replace(p, size, i + 1, maxi, mini);
	}
	else {
		p[maxi] = 0;
		p[mini] = 0;
	}
}
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 20;
	int p[n];

	int Low = 1;
	int High = 100;

	Create(p, n, Low, High, 0);
	Print(p, n, 0);

	cout << "Max = " << Max(p, n,1,p[0]) << endl;
	cout << "Min = " << Min(p, n,1,p[0]) << endl;
	cout << "S = " << Sum(p, n,0,p[0],p[0]) << endl;
	Replace(p, n,0,0,0);
	cout << "Modified mass = " << endl;
	Print(p, n,0);
	return 0;
}
