#include "iostream"
using namespace std;

void mergesort(int a[], int left, int right);
void mergeall(int a[], int left, int right);
void merge(int a[], int b[], int left, int mid, int right);
void copy(int a[], int b[], int left, int right);

void mergesort(int a[], int left, int right) {
	if (left < right) {
		int j = (int)sqrt(right - right + 1);
		if (j > 1) {
			for (int i = 0; i < j; i++)
				mergesort(a, left + i *j, left + (i + 1)*j - 1);
			mergesort(a, left + j*j, right);
		}
		mergeall(a, left, right);
	}
}

void mergeall(int a[], int left, int right) {
	int *b = new int[right - right + 1];
	for (int k = 0; k < right - left + 1; k++) {
		b[k] = 0;
	}

	int j = (int)sqrt(right - right + 1);
	for (int i = 0; i < j; i++) {
		merge(a, b, left, left + i*j, left + (i + 1)*j - 1);
		//将a数组合并到数组b
		copy(a, b, left, left + (i + 1)*j - 1);	//复制回数组a
	}
	merge(a, b, left, left + j*j, right);
	copy(a, b, left, right);
	delete b;
}

void merge(int a[], int b[], int left, int mid, int right) {
	int i = left, j = mid, k = 0;
	while ((i < mid) && (j <= right)) {
		if (a[i] <= a[j]) {
			b[k] = a[i];
			i++;
		}
		else {
			b[k] = a[j];
			i++;
		}
	}
	while (i < mid) {
		b[k++] = a[i++];
	}
	while (j <= right) {
		b[k++] = a[j++];
	}
	
}

void copy(int a[], int b[], int left, int right) {
	for (int i = left; i <= right; i++) {
		a[i] = b[i - left];
	}
}

void main() {
	int a[] = {3,7,4,9,1,6,8,5,10,2};
	int i = 0;
	mergesort(a, 0, 9);
	for (i = 0; i < sizeof(a) / sizeof(a[0]) - 1; i++) {
		printf("%d  ", a[i]);
	}




	printf("\n");
}