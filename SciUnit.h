#pragma once
#include"Unit.h"

class SciUnit :public Unit {
	std::map<int, std::pair<int, int>> student;
public:
	//SciUnit(std::string UN, std::string HN, int PGS, int Staff, int kurs, int amount, int cost);
	SciUnit(std::string UN, std::string HN, int PGS, int Staff, std::map<int, std::pair<int, int>> map);

	std::string unit_find(std::string Name);
	int get_student_amount();
	char type();
	void print();
	void print_name();
	void input(std::ofstream &out);
};

