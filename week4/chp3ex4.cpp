//chp3ex4.cpp
// chp3ex0-2.cpp
// �߰����, �⸻���, �׸��� ���� ���� ��� �ް�
// ������ ��� ��� ������ ����ϱ�.
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
		//�ʱ�ȭ
		if (min.size() == 0) min = word;
		if (max.size() == 0) max = word;
		//ũ�� Ȯ��
		if (word.size() < min.size()) min = word;
		else if (word.size() > max.size()) max = word;
	}

	cout << "Max : " << max << endl;
	cout << "Min : " << min << endl;
	return 0;
} // main ��