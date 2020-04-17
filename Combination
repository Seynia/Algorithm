#include <iostream>
#include <vector>

using namespace std;

int C(int n, int r) {
	if (n == r || r == 0) return 1;
	return C(n - 1, r) + C(n - 1, r - 1);
}

vector<vector<int>> getAllCombination(int n, int r) {
	vector<vector<int>> result;
	vector<bool> visited(n + 1, 0);
	int i, j;
	for (i = 1; i <= n; i++) {
		visited[i] = true;
		vector<int> tmp;
		tmp.push_back(i);
		for (j = 1; j <= n; j++) {
			if (!visited[j]) {
				visited[j] = true;
				tmp.push_back(j);
				if (tmp.size() == r) {
					result.push_back(tmp);
					tmp.pop_back();
					visited[j] = false;
				}
			}
		}
	}
	return result;
}

int main() {
	vector<vector<int>> result = getAllCombination(9, 3);
	while (!result.empty()) {
		vector<int> tmp = result[0];
		result.erase(result.begin());
		int size = tmp.size();
		for (int i = 0; i < size; i++) {
			cout << tmp[0];
			tmp.erase(tmp.begin());
			if (!tmp.empty()) cout << ", ";
		}
		cout << endl;
	}
}
