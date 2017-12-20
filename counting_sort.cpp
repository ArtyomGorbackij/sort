#include<sstream>
#include<iostream>
using namespace std;
int n;
int main()
{ int r[256]={0},k=0;
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
        k=a[i];
        r[k]++;
        }
    for (int i = 0; i <255; i++){
        if (r[i]!=0){
            while(r[i]>0) {
                cout<< i<<" ";
                r[i]--;
            }
        }
    }
    cin.get();
    return 0;
}
