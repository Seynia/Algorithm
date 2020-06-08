#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
#include <windows.h>

using namespace std;

template<class T>
class Sort {
public:
	Sort(vector<T> data) {
		list.assign(data.begin(), data.end());
		size = (__int32)list.size();
	}

	void operator = (vector<T> data) {
		list.assign(data.begin(), data.end());
	}

	void print(int left = -1, int right = -1, bool single = false) {
		int tmp = left;
		left = left < right ? left : right;
		right = left < right ? right : tmp;
		printf("list: [ ");
		for (int i = 0; i < size; i++) {
			if (!single && i == left) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			if (single && (i == left || i == right)) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			printf("%2d", list[i]);
			printf((i == size - 1) ? "" : ", ");
			if (!single && i == right) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			if (single && (i == size - 1 || i == left || i == right)) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		cout << " ]" << endl;
	}

	void bubble() {
		cout << "----------------------bubble----------------------" << endl;
		int i, j;
		bool flag = false;
		for (i = 1; i < size; i++) {
			for (j = 1; j < size; j++) {
				if (list[j] < list[(__int64)j - 1]) {
					flag = true;
					swap(j, j - 1);
					print(j, j - 1);
				}
			}
			if (!flag) break;
		}
	}

	void insertion() {
		cout << "----------------------insertion sort---------------------" << endl;
		int i, j = 1;
		for (i = 1; i < size; i++, j = i) {
			while (list[j] < list[(__int64)j - 1]) {
				swap(j, j - 1);
				print(j, j - 1, 1);
				if (j < 2) break;
				j--;

			}
			print(i, j, true);
		}
		cout << endl;
	}

	void quick() {
		cout << "----------------------quick sort----------------------" << endl;
		qpartition(0, size - 1);
		cout << endl;
	}

	void merge() {
		cout << endl << "----------------------merge sort----------------------" << endl;
		mpartition(0, size - 1);
		cout << endl;
	}

	//void radix() {
	//	vector<queue<T>> digitList(10, queue<T>());
	//	float pow = 1;
	//	int i;
	//	for (i = 0; i < 10; i++) {
	//		digitList[i].push(3);
	//	}
	//	

	//}

	/*void heap() {

	}*/
private:
	vector<T> list;
	int size;
	queue<T> que;

	void swap(int i, int j) {
		T tmp = list[i];
		list[i] = list[j];
		list[j] = tmp;
	}
	void qpartition(int start, int end) {
		int s = start, e = end, pivot = list[(__int64)start + (end - start) / 2];
		while (s <= e) {
			while (list[s] < pivot) s++;
			while (list[e] > pivot) e--;
			if (s < e) {
				printf("pivot: %2d ->", pivot);
				swap(s, e);
				print(s, e, true);
			}
			s++;
			e--;
		}
		if (e <= start || s >= end) return;
		qpartition(0, e);
		qpartition(s, end);
	}

	void mpartition(int left, int right) {
		if (left < right) {
			int mid = left + (right - left) / 2;
			mpartition(left, mid);
			mpartition(mid + 1, right);
			mergeSort(left, mid, right);
		}
	}

	void mergeSort(int left, int mid, int right) {
		vector<T> tmp;
		int p = left;
		int q = mid + 1;
		while (p <= mid && q <= right) {
			if (list[p] <= list[q]) {
				tmp.push_back(list[p]);
				p++;
			}
			else {
				tmp.push_back(list[q]);
				q++;
			}
		}
		for (int i = p; i <= mid; i++) {
			tmp.push_back(list[i]);
		}
		for (int i = q; i <= right; i++) {
			tmp.push_back(list[i]);
		}
		for (int i = left; i <= right; i++) list[i] = tmp[(__int64)i - left];

		print(left, right);

	}
};



int main() {
	vector<int> array{ 5, 7, 6, 9, 4, 8, 1, 2, 3, 10 };
	Sort<int> S(array);
	S.print();
	cout << endl;

	long start = clock();
	S.bubble();
	cout << "time is elapsed " << clock() - start << " ms\n\n";

	S = array;
	start = clock();
	S.insertion();
	cout << "time is elapsed " << clock() - start << " ms\n\n";

	S = array;
	start = clock();
	S.quick();
	cout << "time is elapsed " << clock() - start << " ms\n\n";

	S = array;
	start = clock();
	S.merge();
	cout << "time is elapsed " << clock() - start << " ms\n";
}