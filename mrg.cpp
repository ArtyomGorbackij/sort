#include <iostream>
#include <sstream>
using namespace std;
bool vvod(int * array,int & n)
{
    string string;
    getline(cin, string);
    istringstream stream(string);
    bool success = true;
    for (int i = 0; i < n; ++i) {
        if (!(stream >> array[i])) {
            success = false;
            break;
        }
    }
    return success;
}
void mrg(int * a, int left, int right) {
    int m = (right + left) / 2;
    if (right == left) {
        return;
    }
    if (right - left == 1) {
        if (a[right] < a[left])
            swap(a[right], a[left]);
        return;
    }
    mrg(a, left, m);
    mrg(a, m + 1, right);
    int * tmp = new int [right - left + 1] ;
    int left_t = left, right_t = m + 1, j = 0;
    while (right - left + 1 != j) {
        if (left_t > m){
            tmp[j++] = a[right_t++];
        }
        else if (right_t > right) {
            tmp[j++] = a[left_t++];
        }
        else if (a[left_t] > a[right_t]) {
            tmp[j++] = a[right_t++];
        }
        else tmp[j++] = a[left_t++];
    }
    for (int i = 0; i < j; i++)
        a[i + left] = tmp[i];
    delete[] tmp;
}
int main() {
    int n;
    string str;
    getline(cin, str);
    istringstream stream(str);
    if (stream >> n && n > 0) {
        int * a = new int[n];
        if (vvod(a,n)) {
            mrg(a, 0, n - 1);
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            delete[] a;
        }
        else {
            cout << "An error has occured while reading input data.";
            delete[] a;
        }
    }
    else {
        cout << "An error has occured while reading input data.";
    }
    cin.get();
    return 0;
}
