#include "iostream"
#include "string"
using namespace std;

#define MAXNUM 65535

int val[100][100];	//存放最小值
int k;				//空格与其他字符的距离值

string str1, str2;

//计算两个字符之间的ASCII距离
int dist(char a, char b) {
	return abs(a - b);
}

//求最小距离
int mindist() {
	int len1 = str1.length();
	int len2 = str2.length();
	int temp;
	val[0][0] = 0;	//表示空格
	for (int i = 0; i < len1; i++) {	//下标从1开始，便于与上次结果进行操作
		for (int j = 0; j < len2; j++) {
			if (i + j > 0) {	//至少有一个不是空格,应该空格相互比较对于结果没有变换，操作是多余的
				val[i][j] = MAXNUM;
				//情况1
				if (i > 0) {
					temp = val[i - 1][j] + k;
					if (temp < val[i][j]) {
						val[i][j] = temp;
					}
				}
				//情况2
				if (j > 0) {
					temp = val[i][j - 1] + k;
					if (temp < val[i][j]) {
						val[i][j] = temp;
					}
				}
				//情况3
				if (i * j > 0) {
					temp = val[i - 1][j - 1] + dist(str1[i], str2[j]);
					if (temp < val[i][j]) {
						val[i][j] = temp;
					}
				}
			}			
		}
	}
	return val[len1-1][len2-1];
}

int main() {
	cin >> str1 >> str2;
	cin >> k;
	str1 = " " + str1;	//在字符的比较中加入与空格的比较
	str2 = " " + str2;
	cout << mindist() << endl;
	return 0;
}