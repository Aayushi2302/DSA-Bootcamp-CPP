#include <iostream>
using namespace std;
int& Return_ref(int &x) {
return (x);
}
int main() {
int a = 10, b;
b = Return_ref(a);
cout << "a = " << a << " and b = "
<< b << endl;
Return_ref(a) = 3; // Changes
// reference
cout << "a = " << a;
cout << "b = " << b;
return 0;
}