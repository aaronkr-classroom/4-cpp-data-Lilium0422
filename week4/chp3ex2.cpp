//chp3ex2.cpp
#include <ios>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using std::cin;	
using std::cout; 
using std::endl;
using std::sort; 
using std::vector;

int main() {
	vector<int> a;
	int b;
	cout << "정수를 입력하시오.";
	while (cin >> b) {
		a.push_back(b);
	}

	typedef vector<double>::size_type vec_sz;
	vec_sz size = a.size();
	if (size == 0) {
		cout << endl << "You must enter your grades. "
			"Please try again." << endl;
		return 1;
	}
	sort(a.begin(), a.end());
	vec_sz q1 = size / 4;
	vec_sz q2 = size / 2;
	vec_sz q3 = 3* size / 4;
	int q1_val,q2_val,q3_val;
	q1_val = size % 4 == 0 ? (a[q1] + a[q1 - 1]) / 2 : a[q1];
	q2_val = size % 2 == 0 ? (a[q2] + a[q2 - 1]) / 2 : a[q2];
	q3_val = (3 * size) % 4 == 0 ? (a[q3] + a[q3 - 1]) / 2 : a[q3];

	cout << "제 1 사분위수 : " << q1_val << endl;
	cout << "제 2 사분위수 : " << q2_val << endl;
	cout << "제 3 사분위수 : " << q3_val << endl;

	return 0;
}