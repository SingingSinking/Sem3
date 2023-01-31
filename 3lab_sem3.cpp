#include <iostream> 
using namespace std;
const int N = 50;
int vavd(int mas[N])
{
	for (int i = 0; i < N; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl << endl;
	return 0;
}
int insertion_sort(int a[N])
{
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && a[j - 1] > a[j]; j--)
			swap(a[j - 1], a[j]);
	cout << endl << "Insertion sort: " << endl;
	vavd(a);
	return 0;
}
int Selection_sort(int a[N])
{
	for (int i = 0; i < N - 1; i++)
	{
		int imin = i;
		for (int j = i + 1; j < N; j++)
			if (a[j] < a[imin])
				imin = j;
		int b = a[i];
		a[i] = a[imin];
		a[imin] = b;
	}
	cout << endl << "Selection sort: " << endl;
	vavd(a);
	return 0;
}
int Bubble_sort(int a[N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
	}
	cout << endl << "Bubble sort: " << endl;
	vavd(a);
	return 0;
}
void Merge_sort(int* a, int l, int r)
{
	if (l == r) return; //the borders have closed
	int mid = (l + r) / 2; //we define the middle of the sequence
	// and recursively call the sorting function for each half
	Merge_sort(a, l, mid);
	Merge_sort(a, mid + 1, r);
	int i = l; //the beginning of the first path
	int j = mid + 1; //the beginning of the second path
	int* tmp = (int*)malloc(r * sizeof(int)); //additinaly array
	for (int step = 0; step < r - l + 1; step++) //for all elements of the additional array
	{
		// we write the smaller of the elements of the two paths into the generated sequence
		// or the remainder of the first path if j > r
		if ((j > r) || ((i <= mid) && (a[i] < a[j])))
		{
			tmp[step] = a[i];
			i++;
		}
		else
		{
			tmp[step] = a[j];
			j++;
		}
	}
	// rewriting the generated sequence into the source array
	for (int step = 0; step < r - l + 1; step++)
		a[l + step] = tmp[step];
}
void Shell_sort(int* num)
{
	int increment = 3;
	while (increment > 0)
	{
		for (int i = 0; i < N; i++)
		{
			int j = i;
			int temp = num[i];
			while ((j >= increment) && (num[j - increment] > temp))
			{
				num[j] = num[j - increment];
				j = j - increment;
			}
			num[j] = temp;
		}
		if (increment > 1)
			increment = increment / 2;
		else if (increment == 1)
			break;
	}
	cout << endl << "Shell sort:" << endl;
	vavd(num);
}
void quicksort(int* mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) //перестановка элементов
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}
int main()
{
	int mas[N];
	int vabr = 0;
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		mas[i] = rand() % 100;
	}
	vavd(mas);
	cout << "Select the sort from bottom list: " << endl <<
		"Press 1 to Insertion sort" << endl <<
		"Press 2 to Selection sort" << endl <<
		"Press 3 to Bubble sort" << endl <<
		"Press 4 to Merge sort" << endl <<
		"Press 5 to Shell sort" << endl <<
		"Press 6 to Quick sort" << endl;
	while (flag == 0)
	{
		cin >> vabr;
		if ((vabr < 0) || (vabr > 6))
			cout << "error" << endl;

		else
			flag = 1;
	}
	switch (vabr)
	{
	case 1: insertion_sort(mas);
		break;
	case 2: Selection_sort(mas);
		break;
	case 3: Bubble_sort(mas);
	case 4: Merge_sort(mas, 0, N - 1);
		cout << endl << "Merge sort:" << endl;
		vavd(mas);
		break;
	case 5: Shell_sort(mas);
		break;
	case 6: quicksort(mas, 0, N - 1);
		cout << endl << "quick sort:" << endl;
		vavd(mas);
		break;
	}
	return 0;
}
