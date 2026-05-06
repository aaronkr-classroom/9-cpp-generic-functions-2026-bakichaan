#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "student_info.h"
#include "median.h"

using namespace std;

int main(void) {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while (record.read(cin)) { 
		maxlen = max(maxlen, record.getName().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0;
		i != students.size(); i++) {
		cout << students[i].getName()
			<< string(maxlen + 1
				- students[i].getName().size(), ' ');
	
		try {
			double final_grade = students[i].grade();

			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}


// 필요한 파일
// - student_info.cpp
// - median.h
// - median.cpp
// - grade.h
// - grade.cpp
