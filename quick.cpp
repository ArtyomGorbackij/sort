# sort

#include <iostream>
#include <sstream>
using namespace std;
bool vvod(float * &a, int n)
{
    string str;
    int over;
    getline(cin, str);
    float *tmp = new float [n];
    for (string str; getline(cin, str); ) {
        istringstream stream(str);
        for (unsigned int j = 0; j < n; ++j) {
            if(!(stream >> tmp[j])) {
                return false;
            }
        }
        if(stream >> over)
            return false;
        break;
    }
    a = tmp;
    return true;
}
void quick_sort(float *a, int lp, int rp)
{
    int x, i = lp, j = rp;
    x = a[(lp+rp)/2];
    do {
        while((a[i] < x) && (i < rp)) i++;
        while((x < a[j]) && (j > lp)) j--;
        if(i <= j) {
            swap(a[i],a[j]);
            i++; j--;
        }
    } while (i <= j);
    if(lp < j) quick_sort(a, lp, j);
    if(i < rp) quick_sort(a, i, rp);
}
int main() {
    float *a;
    int n;
    if (!(cin >> n)|| (n <= 0))
    {
        cout << "An error has occured while reading vvod data.\n";
        return 0;
    }
    if (!(vvod(a, n)))
    {
        cout << "An error has occured while reading vvod data.\n";
        return 0;
    }
    quick_sort(a, 0, n-1);
    for (unsigned int i = 0; i < n; i++) cout << a[i] << " ";
    cout<< "\n";
    delete[] a;
    cin.get();
    return 0;
}
