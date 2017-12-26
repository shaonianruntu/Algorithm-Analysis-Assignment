#include "iostream"
using namespace std;

//存储Huffman树
typedef struct {
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode, *HuffmanTree;

void createHuffmanTree(HuffmanTree ht, int n);
void Select(HuffmanTree ht, int k, int &min1, int &min2);
int min(HuffmanTree ht, int k);

//创建Huffman树
void createHuffmanTree(HuffmanTree ht, int n) {
	int compTime = 0;
	//初始化
	for (int i = 0; i < 2 * n - 1; i++) {
		ht[i].parent = -1;
		ht[i].lchild = -1;
		ht[i].rchild = -1;
	}
	int min1 , min2;
	for (int i = n; i < 2 * n - 1; i++) {
		Select(ht, i, min1, min2);	//选择出没有双亲且权值最小的两个节点的序列
		ht[min1].parent = i;
		ht[min2].parent = i;
		ht[i].lchild = min1;
		ht[i].rchild = min2;
		ht[i].weight = ht[min1].weight + ht[min2].weight;
		compTime += ht[i].weight - 1;
	}
	cout << compTime << endl;	//输出中的比较次数
}


//查找权值最小的两个点
void Select(HuffmanTree ht, int k, int &min1, int &min2) {
	min1 = min(ht, k);
	min2 = min(ht, k);
}

//查找权值最小的一个点
int min(HuffmanTree ht, int k) {
	int i = 0;
	int minIndex;
	int minWeight;

	while (ht[i].parent != -1) {
		i++;
	}
	minIndex = i;
	minWeight = ht[minIndex].weight;

	for (; i < k; i++) {
		if (ht[i].weight < minWeight && ht[i].parent == -1) {
			minIndex = i;
			minWeight = ht[minIndex].weight;
		}
	}

	ht[minIndex].parent = -2;
	return minIndex;
}

int main() {
	int n;
	cin >> n;
	HTNode ht[100];
	for (int i = 0; i < n; i++) {
		cin >> ht[i].weight;
	}
	createHuffmanTree(ht, n);
	return 0;
}