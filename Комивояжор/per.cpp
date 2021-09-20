#include <iostream>
#include <vector>
using namespace std;
int fact(int n) {
	if (n == 0) {
		return 1;
	}
	return n * fact(n - 1);
}
void swap(int& a, int& b) {
	int c = 0;
	c = a;
	a = b;
	b = c;
	return;
}
int getAns(int* line, vector<vector<int> >& mtx, int start, int n) {
	int ans = mtx[start][line[0]];
	for (int j = 0; j < n - 1; j++) {
		ans += mtx[line[j]][line[j + 1]];
	}
	ans += mtx[line[n - 1]][start];
	return ans;
}
void FindPath(int start, vector<vector<int> >& mtx, int* line, int n, int& ans, int* ansLine, int val = 0) {
	if (val == n) {
		int tans = getAns(line, mtx, start, n);
		if (ans == -1 || ans > tans) {
			ans = tans;
			for (int i = 0; i < n; i++) {
				ansLine[i] = line[i];
			}
		}
		cout << start << " ";
		for (int i = 0; i < n; i++) {
			cout << line[i] << " ";
		}
		cout << start << " |" << tans << "| " << endl;
		return;
	}
	bool unique;
	for (int i = 0; i < n + 1; i++) {
		unique = true;
		for (int j = 0; j < val; j++) {
			unique &= i != line[j];
		}
		if (unique && i != start) {
			line[val] = i;
			FindPath(start, mtx, line, n, ans, ansLine, val + 1);
		}
	}
}
void getMtx(vector<vector<int> > &mtx, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mtx[i][j];
		}
	}
}
int solutionPer(int n, int start, vector<vector<int> >& mtx) {
	int ans = -1;
	int* line = new int[n - 1];
	int* ansLine = new int[n - 1];

	cout << "\\log per\\" << endl;
	FindPath(start - 1, mtx, line, n - 1, ans, ansLine);
	cout << "\\end log per\\" << endl;

	cout << start << "->";
	for (int i = 0; i < n - 1; i++) {
		cout << ansLine[i] + 1 << "->";
	}
	cout << start << " | ans = " << ans << endl;
	return ans;
}
int main() {
	int n, start;
	cout << "Count towns:";
	cin >> n;
	cout << "Start town:";
	cin >> start;
	cout << "Input matrix:" << endl;
	vector<vector<int> > mtx(n, vector<int>(n));
	getMtx(mtx, n);
	solutionPer(n, start, mtx);
	system("pause");
}