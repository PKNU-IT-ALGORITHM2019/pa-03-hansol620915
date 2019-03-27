#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define MAX 100001
int data[MAX];

void swap(int a, int b);
void print_table();
void make_random(int N);
void make_reverse(int N);
void start_bubble_sort();
void bubble_sort(int N);
void start_selection_sort();
void selection_sort(int N);
void start_insertion_sort();
void insertion_sort(int N);
void start_merge_sort();
void merge_sort(int p, int r);
void merge(int p, int q, int r);
void start_quick();
void quick1(int p, int r);
void quick2(int p, int r);
void quick3(int p, int r);
int partition_1(int p, int r);
int partition_2(int p, int r);
int partition_3(int p, int r);


int main() {
	print_table();
	srand((unsigned int)time(NULL));
	start_bubble_sort();
	start_selection_sort();
	start_insertion_sort();
	start_merge_sort();
	start_quick();
	int x;
	scanf("%d", &x);
	//for (int i = 0; i < 10; i++) printf("%d ", data[i]);
	
	return 0;
}
void start_quick()
{
	float start, end, timer = 0;
	int x = 1000;
	printf("\nquick1		");

	for (int i = 0; i < 3; i++)
	{
		timer = 0;
		for (int j = 0; j < 10; j++) {
			make_random(x);
			start = clock();
			quick1(0, x - 1);
			end = clock();
			timer += end - start;
		}
		printf("%.3f		", timer / 10000);
		timer = 0;
		make_reverse(x);
		start = clock();
		quick1(0, x - 1);
		end = clock();
		timer = end - start;
		printf("%.3f		", timer / 1000);
		x *= 10;
	}


	printf("\nquick2		");
	x = 1000;
	for (int i = 0; i < 3; i++)
	{
		timer = 0;
		for (int j = 0; j < 10; j++) {
			make_random(x);
			start = clock();
			quick2(0, x - 1);
			end = clock();
			timer += end - start;
		}
		printf("%.3f		", timer / 10000);
		timer = 0;
		make_reverse(x);
		start = clock();
		quick2(0, x - 1);
		end = clock();
		timer = end - start;
		printf("%.3f		", timer / 1000);
		x *= 10;
	}
	printf("\nquick3		");
	x = 1000;
	for (int i = 0; i < 3; i++)
	{
		timer = 0;
		for (int j = 0; j < 10; j++) {
			make_random(x);
			start = clock();
			quick3(0, x - 1);
			end = clock();
			timer += end - start;
		}
		printf("%.3f		", timer / 10000);
		timer = 0;
		make_reverse(x);
		start = clock();
		quick3(0, x - 1);
		end = clock();
		timer = end - start;
		printf("%.3f		", timer / 1000);
		x *= 10;
	}
}

void quick3(int p, int r)
{
	if (p < r) {
		int q = partition_3(p, r);
		quick3(p, q - 1);
		quick3(q + 1, r);
	}
}
int partition_3(int p, int r)
{
	int q = rand() % (r - p) + p;
	swap(q, r);
	int x = data[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (data[j] <= x) {
			i++;
			swap(i, j);
		}
	}
	swap(i + 1, r);
	return (i + 1);
}

void quick2(int p, int r)
{
	if (p < r) {
		int q = partition_2(p, r);
		quick2(p, q - 1);
		quick2(q + 1, r);
	}
}
int partition_2(int p, int r)
{
	int q = (p + r) / 2;
	swap(q, r);
	int x = data[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (data[j] <= x) {
			i++;
			swap(i, j);
		}
	}
	swap(i + 1, r);
	return (i + 1);
}

void quick1(int p, int r)
{
	r--;
	if (p < r) {
		int q = partition_1(p, r);
		quick1(p, q - 1);
		quick1(q + 1, r);
	}
}
int partition_1(int p, int r)
{
	int x = data[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (data[j] <= x) {
			i++;
			swap(i, j);
		}
	}
	swap(i + 1, r);
	return (i + 1);
}

void start_merge_sort()
{
	printf("\nMerge		");

	float start, end, timer = 0;
	int x = 1000;
	for (int i = 0; i < 3; i++)
	{
		timer = 0;
		for (int j = 0; j < 10; j++) {
			make_random(x);
			start = clock();
			merge_sort(0, x - 1);
			end = clock();
			timer += end - start;
		}
		printf("%.3f		", timer / 10000);
		timer = 0;
		make_reverse(x);
		start = clock();
		merge_sort(0, x - 1);
		end = clock();
		timer = end - start;
		printf("%.3f		", timer / 1000);
		x *= 10;
	}}
void merge_sort(int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}
void merge(int p, int q, int r) {
	int j = p, k = q + 1;
	int B[MAX];
	for (int i = p; i <= r; i++)
	{
		if (j > q && k > r) break;
		else if (j > q) B[i] = data[k++];
		else if (k > r) B[i] = data[j++];
		else
		{
			if (data[k] > data[j]) B[i] = data[j++];
			else B[i] = data[k++];
		}
	}
	for (int i = p; i <= r; i++)
		data[i] = B[i];
}

void start_insertion_sort()
{
	printf("\nInsertion	");

	float start, end, timer = 0;
	int x = 1000;
	for (int i = 0; i < 3; i++)
	{
		timer = 0;
		for (int j = 0; j < 10; j++) {
			make_random(x);
			start = clock();
			insertion_sort(x);
			end = clock();
			timer += end - start;
		}
		printf("%.3f		", timer / 10000);
		timer = 0;
		make_reverse(x);
		start = clock();
		insertion_sort(x);
		end = clock();
		timer = end - start;
		printf("%.3f		", timer / 1000);
		x *= 10;
	}
}
void insertion_sort(int N)
{// 1 3 5 6 4
	for (int i = 1; i < N; i++) {
		int tmp = data[i];
		int j = i - 1;
		while (data[j] > tmp && j >= 0) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = tmp;
	}
}

void start_selection_sort()
{
	printf("\nSelection	");

	float start, end, timer = 0;
	int x = 1000;
	for (int i = 0; i < 3; i++)
	{
		timer = 0;
		for (int j = 0; j < 10; j++) {
			make_random(x);
			start = clock();
			selection_sort(x);
			end = clock();
			timer += end - start;
		}
		printf("%.3f		", timer / 10000);
		timer = 0;
		make_reverse(x);
		start = clock();
		selection_sort(x);
		end = clock();
		timer = end - start;
		printf("%.3f		", timer / 1000);
		x *= 10;
	}
}
void selection_sort(int N)
{
	int big = 0, index;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			if (data[j] > big) {
				big = data[j];
				index = j;
			}
		}
		int tmp = data[N - i - 1];
		data[N - i - 1] = data[index];
		data[index] = tmp;
	}
}
void start_bubble_sort() {
	printf("Bubble		");
	float start, end, timer = 0;
	int x = 1000;
	for (int i = 0; i < 3; i++)
	{
		timer = 0;
		for (int j = 0; j < 10; j++) {
			make_random(x);
			start = clock();
			bubble_sort(x);
			end = clock();
			timer += end - start;
		}
		printf("%.3f		", timer / 10000);
		timer = 0;
		make_reverse(x);
		start = clock();
		bubble_sort(x);
		end = clock();
		timer = end - start;
		printf("%.3f		", timer / 1000);
		x *= 10;
	}
}
void bubble_sort(int N)
{
	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j < N - i; j++) {
			if (data[j - 1] > data[j]) {
				int tmp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = tmp;
			}
		}
	}
}
void make_reverse(int N)
{
	for (int i = 0; i < N; i++)
		data[i] = N - i;
}
void make_random(int N)
{
	for (int i = 0; i < N; i++) {
		data[i] = rand() % N + 1;
	}
}
void print_table()
{
	printf("		Random1000	Reverse1000	Random10000	Reverse10000	Random100000	Reverse100000\n");
}

void swap(int a, int b)
{
	int tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}