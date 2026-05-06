//student_info.h
#pragma once

#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student_info {
private:
	string name;
	double midterm, final;
	vector<double> homework;

public:
	Student_info();
	Student_info(istream&); 
	// 윗 생성자가 read_hw() 함수와 비슷

	string getName() const { return name; }
	void setName(string n) { name = n; }

	double getMidterm() const { return midterm; }
	double getFinal() const { return final; }
	vector<double> getHw() const { return homework; }

	bool valid() const { return !homework.empty(); }

	// 9.2.1/ 254p 에서 정의한 함수들
	istream& read(istream&);
	double grade() const;

}; 

// 전역 함수 정의
bool compare(const Student_info&, const Student_info&);

#endif
