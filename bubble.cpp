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
            cout << "An error has occuried while reading input data.\n";
            cin.get();
            return 0;
        }
    }
    for (int i=0;i<n;i++){
            for (int j = 1; j < n; j++) {
                    if (a[j] < a[j - 1]) {
                        swap(a[j], a[j - 1]);
                    }
                }
        }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cin.get();
    return 0;
}
