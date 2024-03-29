//chp3ex4.cpp
// chp3ex0-2.cpp
// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고
// 마지막 평균 결과 점수를 계산하기.
#include <iostream>
#include <string>

using std::cin;	
using std::cout; using std::string;
using std::endl; 

int main() {
	string max = "";
	string min = "";
	string word;
	while (cin >> word) {
		//초기화
		if (min.size() == 0) min = word;
		if (max.size() == 0) max = word;
		//크기 확인
		if (word.size() < min.size()) min = word;
		else if (word.size() > max.size()) max = word;
	}

	cout << "Max : " << max << endl;
	cout << "Min : " << min << endl;
	return 0;
} // main 끝