#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;


void swap(int arr[],int a, int b)
{
	arr[a] = arr[a] ^ arr[b];
	arr[b] = arr[a] ^ arr[b];
	arr[a] = arr[a] ^ arr[b];
}
void swap1(int arr[], int a, int b)
{
	int temp= arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int compare1(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

bool compare2(int a, int b)
{
	return a < b;
}

void comparator(int arr[],int len)
{
	sort(arr, arr + len, compare2);
	//qsort(arr, len, sizeof(int), compare1);
}

int* generateRandomArray(int maxSize, int maxValue,int& len)
{
	srand((unsigned)time(NULL));
	len= (int)(rand() % maxSize + 1);
	int* arr = new int[len];
	for (int i = 0;i < len;i++)
	{
		arr[i] = (int)(rand() % maxValue + 1) - (int)(rand() % maxValue);
	}
	return arr;
}

int* copyArray(int arr[], int len)
{
	if (arr == NULL)
	{
		return NULL;
	}
	int* narr = new int[len];
	memcpy(narr, arr, sizeof(int)*len);
	return narr;
}

bool isEqual(int arr1[], int len1, int arr2[], int len2)
{
	if (len1 != len2||(arr1==NULL&&arr2!=NULL)|| (arr2 == NULL && arr1 != NULL))
	{
		return false;
	}
	if (arr1 == NULL && arr2 == NULL)
	{
		return true;
	}
	for (int i = 0;i < len1;i++)
	{
		if (arr1[i] != arr2[i])
		{
			return false;
		}
	}
	return true;
}

void printArray(int arr[], int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubbleSort(int arr[], int len)
{
	if (arr == NULL || len < 2) {
		return;
	}
	for (int i = len-1;i > 0;i--)
	{
		for (int j =0;j < i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr,j,j+1);
			}
		}
	}
}

void selectionSort(int arr[], int len)
{
	if (arr == NULL || len < 2)
	{
		return;
	}
	for (int i = 0;i < len-1;i++)
	{
		int minIndex = i;
		for (int j = i + 1;j < len;j++)
		{
			minIndex = arr[minIndex] > arr[j] ? j : minIndex;
		}
		if (minIndex != i)
		{
			swap(arr, i, minIndex);
		}
	}
}

void insertSort(int* arr, int len)
{
	if (arr == NULL || len < 2)
	{
		return;
	}
	for (int i = 0;i < len-1;i++)
	{
		int j = i + 1;
		int k = i;
		while (j > 0)
		{
			if (arr[j] < arr[k])
			{
				swap(arr, k, j);
				j--;
				k--;
			}
			else
			{
				break;
			}
		}
	}
}

void mergeP(int* arr, int L, int mid, int R);
void process(int arr[], int L, int R)
{
	if (L == R)
	{
		return;
	}
	int mid = L + ((R - L) >> 2);
	process(arr, L, mid);
	process(arr, mid + 1, R);
	mergeP(arr, L, mid, R);
}
void mergeP(int* arr, int L,int mid,int R)
{
	int* help = new int[R - L + 1];
	int p1 = L;
	int p2 = mid+1;
	int i = 0;
	while (p1 <= mid && p2 <= R)
	{
		help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1 <= mid)
	{
		help[i++] = arr[p1++];
	}
	while (p2 <= R)
	{
		help[i++] = arr[p2++];
	}
	for (int i = L;i <= R;i++)
	{
		arr[i] = help[i - L];
	}
	delete[] help;
}
void mergeSort(int* arr, int len)
{
	int L = 0;
	int R = len - 1;
	process(arr, L, R);
}


int* partition(int* arr,int L,int R)
{
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if (arr[L] < arr[R])
		{
			swap1(arr, ++less, L++);
		}
		else if (arr[L] > arr[R])
		{
			swap1(arr, L, --more);
		}
		else
		{
			L++;
		}
	}
	swap1(arr, L, R);
	return new int[2] { less, more+1 };
}
void quickSort(int* arr, int L, int R)
{
	if (R > L)
	{
		srand((unsigned)time(NULL));
		int random = rand() % (R - L+1)+L;
		swap1(arr, random, R);
		int* p = partition(arr, L, R);
		quickSort(arr, L, p[0]);
		quickSort(arr, p[1], R);
	}
}
void quickSort(int* arr, int len)
{
	if (arr == NULL || len < 2)
	{
		return;
	}
	int L = 0;
	int R = len - 1;
	quickSort(arr, L, R);
}

void heapInsert(int* arr, int index)
{
	while (arr[index] > arr[(index - 1) / 2])
	{
		swap(arr, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}
void heapfy(int* arr, int index,int len)
{
	int left = 2 * index + 1;
	while (left<len)
	{
		int max = left+1<len && arr[left] < arr[left+1] ? left+1 : left;
		if (arr[index] < arr[max])
		{
			swap(arr, index, max);
			index = max;
			left = 2 * index + 1;
		}
		else
		{
			break;
		}
	}
}
void heapSort(int* arr, int len)
{
	if (arr == NULL || len < 2)
	{
		return;
	}
	int heapSize = len;
	/*for (int i = 0;i < len;i++)
	{
		heapInsert(arr, i);
	}*/
	for (int i = len - 1;i >= 0;i--)
	{
		heapfy(arr, i,len);
	}
	while (heapSize != 0)
	{
		swap1(arr, 0, --heapSize);
		heapfy(arr, 0, heapSize);
	}
}

void bucketSort(int* arr, int begin, int end, int bit);
void bucketSort(int* arr, int len)
{
	if (arr == NULL || len < 2)
	{
		return;
	}
	int max = INT_MIN;
	for (int i = 0;i < len;i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	int ret = 0;
	while (max > 0)
	{
		max /= 10;
		ret++;
	}
	int begin = 0;
	int end = len - 1;
	bucketSort(arr, begin, end, ret);
}
int getDigit(int data, int bit)
{
	return (data / (int)(pow(10, bit - 1)) % 10);
}
void bucketSort(int* arr,int begin,int end,int bit)
{
	const int radix = 10;
	int* bucket = new int[end - begin + 1];
	for (int digit = 1;digit <= bit;digit++)
	{
		int* count = new int[radix];
		for (int i = 0;i < radix;i++)
		{
			count[i] = 0;
		}
		for (int i = begin; i <= end; i++)
		{
			int num = getDigit(arr[i], digit);
			count[num]++;
		}
		for (int i = 1; i < radix; i++) {
			count[i] = count[i] + count[i - 1];
		}
		for (int i = end;i >=begin;i--)
		{
			int j = getDigit(arr[i], digit);
			bucket[count[j]-1] = arr[i];
			count[j]--;
		}
		for (int i = begin;i <= end;i++)
		{
			arr[i] = bucket[i];
		}
	}
}
int main2()
{
	cout << "计时开始" << endl;
	clock_t start = clock();
	
	
	int testTime = 500000;
	int maxSize = 100;
	int maxValue = 100;
	bool succeed = true;

	int len1 = 0;
	for (int i = 0; i < testTime; i++) {
		int* arr1 = generateRandomArray(maxSize, maxValue,len1);
		int* arr2 = copyArray(arr1,len1);
		//bubbleSort(arr1,len1);
		//selectionSort(arr1, len1);
		//insertSort(arr1, len1);
		//mergeSort(arr1, len1);
		//quickSort(arr1, len1);
		//heapSort(arr1, len1);
		//bucketSort(arr1, len1);
		comparator(arr2,len1);
		if (!isEqual(arr1,len1, arr2,len1)) {
			succeed = false;
			break;
		}
	}
	cout << (succeed ? "Nice!" : "Fucking fucked!") << endl;


	int len;
	int* arr = generateRandomArray(maxSize, maxValue,len);
	printArray(arr,len);
	//bubbleSort(arr,len);
	//selectionSort(arr, len);
	//insertSort(arr, len);
	//mergeSort(arr, len);
	//quickSort(arr, len);
	//heapSort(arr, len);
	//bucketSort(arr, len);
	printArray(arr,len);
	clock_t end = clock();
	cout << "计时结束,总用时: "<<(double)((end-start)/ CLOCKS_PER_SEC) << "秒" << endl;
	return 0;
}