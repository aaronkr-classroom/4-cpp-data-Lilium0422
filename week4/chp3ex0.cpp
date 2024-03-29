// chp3ex0.cpp
// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고
// 마지막 평균 결과 점수를 계산하기.
#include <ios>
#include <iomanip>
#include <iostream>
#include <string>

using std::cin;	using std::setprecision; // 실수 숫자 길이 정의(자릿수,정확도)
using std::cout; using std::string;
using std::endl; using std::streamsize;

int main() {
	// 학생의 이름을 묻고 입력받기
	cout << "Your name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// 중간고사와 기말고사 점수를 묻고 입력받기
	cout << "Midterm & Final scores: ";
	double midterm, final; // double = 최소 10자리까지, 보통 15자리까지
	cin >> midterm >> final;

	// 과제 점수를 물음
	cout << "Enter all homework grades "
		"followed by EOF: "; // End-Of-File

	// 지금까지 입력된 과제 점수의 개수와 합
	int count = 0; // 과제 몇개? 
	double sum = 0; // 합 결과 - 0.0 = double, 0 = int 자동 변경함

	// 입력을 위한 변수
	double x; // cin에서 사용하기 

	// 불변성: 지금까지 count개 점수를 입력받았으며
	// 입력받은 점수의 합은 sum
	while (cin >> x) {
		++count; // 과제 1, 2, 3, 4, 5, 6, ...
		sum += x; // 0 + 99 + 98 + 85 + 71 ...
	}

	// 결과를 출력
	streamsize prec = cout.precision(); // 지금 cout precision
	cout << "Final grade: " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * sum / count
		<< setprecision(prec) << endl;

	return 0;
} // main 끝