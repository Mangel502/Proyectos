#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;

	cout << "Ingrese la cantidad de alumnos para evaluar: " << endl;
	cin >> n;

	vector<int> arr(n);

	for (int i = 1; i <= n; i++) {
		cout << i << endl;
	}

	return 0;
}