// chp4ex0.cpp
// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고
// 마지막 평균 결과 점수를 계산하기.
#include <ios>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::domain_error;
using std::cin;	using std::setprecision; // 실수 숫자 길이 정의(자릿수,정확도)
using std::cout; using std::string;
using std::endl; using std::streamsize;
using std::sort; using std::vector;
using std::istream;

double median(vector<double> vec);
double grade(double mt, double ft, double hw);

double grade(double mt,double ft,double hw) {
	return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}

//중간시험 점수 기말시험 점수 과제 점수의 백터로
//학생의 종합 점수를가함.
//이 함 수는 인수를 복사하지않고 median 함수가 해당작업을실행.
double grade(double mt, double ft, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("No homework!");
	return grade(mt, ft, median(hw));
}

double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if (size == 0) {
		throw domain_error("Median of empty vector");
	}
	//점수
	sort(vec.begin(), vec.end());

	// 중앙값 도출
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

// 입력 스트림에서 과제 점수를 읽어서 vector<double>에 넣음.
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		//이전 내용을 제거
		hw.clear();

		//과제 점수를 읽음
		double x; // cin에서 사용하기 

		//불변성 :  homework는 지금까지 입력받은 과제 점수가 있음.
		while (in >> x) {
			hw.push_back(x);
		}
		//다음 학생의 점수 입력 작업을 고려해 스트리을 지움
		in.clear();
	}
	return in;
}

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
	vector<double> homework;

	//과제 점수를 읽음
	read_hw(cin, homework);

	//종합 점수를 계산해 생성
	try {
		double final_grade = grade(midterm, final, homework);
		// 결과를 출력
		streamsize prec = cout.precision(); // 지금 cout precision
		cout << "Final grade: " << setprecision(3)
			<< final_grade
			<< setprecision(prec) << endl;
	}
	catch(domain_error) {
		cout << endl << "No grades entered. Try again." << endl;
		return 1;
	}
	
	

	return 0;
} // main 끝