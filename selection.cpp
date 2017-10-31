# sort
#include<sstream>
#include<iostream>
using namespace std;
int n;
int main()
{
	string str;	
	cin >> n;
	cin.ignore(1, '\n');
	getline(cin, str);
	istringstream stream(str);
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		if (!(stream >> a[i])) {
			cout << "An error has occuried while reading input data.";
		}
	}
	int l = 0;
	for (int j = 0; j<n - 1; j++) {
		l = j;
		for (int i = l; i<n; i++) {
			if (a[l]>a[i]) {
				l = i;
			}
			swap(a[l], a[j]);
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cin.get();
	return 0;
}
