#include "DB.h"

void DB::new_unit(std::string UN, std::string HN, int PGS, int Staff, std::map<int, std::pair<std::string, int>> map) {
	u.push_back(new EduUnit(UN, HN, PGS, Staff, map));
}

void DB::new_unit(std::string UN, std::string HN, int PGS, int Staff, std::map<int, std::pair<int, int>> map) {
	u.push_back(new SciUnit(UN, HN, PGS, Staff, map));
}

struct {
	bool operator()(Unit* a, Unit* b) const {
		std::string t = a->get_unit_name(), t2 = b->get_unit_name();
		if (t.length() < t2.length())
			return true;
		if (t.length() > t2.length())
			return false;
		else
			if (t < t2)
				return true;
			else
				return false;
	}
} customAlph;

std::string DB::sort_unit() {
	std::sort(u.begin(), u.end(), customAlph);
	return u[0]->get_unit_name();
}

int DB::clear(std::string s) {
	for (size_t i = 0; i < u.size();)
		if (u[i]->get_unit_name() == s) {
			u.erase(u.begin() + i);		// well, i didn't find any other way to iterate
			return 1;
		}
		else
			i++;
	return -1;
}

void DB::print_all_name() {
	for (size_t i = 0; i < DB::u.size(); i++) {
		u[i]->print_name();
		std::cout << std::endl;
	}
}

void DB::print_unit_name_by_unit(std::string arg) {
	bool exist = false;
	for (int i = 0; i < u.size(); i++) {
		if (u[i]->get_unit_name() == arg) {
			u[i]->print_name();
			exist = true;
		}
	}
	if (exist == false)
		std::cout << " Unit not found\n";
}

void DB::print_unit_name_by_head(std::string arg) {
	for (int i = 0; i < u.size(); i++)
		if (u[i]->get_head_name() == arg) {
			u[i]->print_name();
			std::cout << std::endl;
		}

}

int DB::print_unit_name_by_staff(int arg) {
	bool check = false;
	for (int i = 0; i < u.size(); i++)
		if (u[i]->get_staff() > arg) {
			u[i]->print_name();
			std::cout << std::endl;
			check = true;
		}
	if (check == true)
		return 1;
	else
		return -1;
}

int DB::print_unit_by_unit(std::string arg) {
	bool check = false;
	for (int i = 0; i < u.size(); i++) {
		if (u[i]->get_unit_name() == arg) {
			u[i]->print();
			check = true;
		}
		std::cout << std::endl;

	}
	if (check == true)
		return 1;
	else
		return -1;
}


void DB::clear() {
	u.clear();
	std::cout << " All Units were deleted\n";
}

std::string DB::get_unit_name_by_iter(int i) {
	return u[i]->get_unit_name();
}

std::string DB::get_unit_head(int i) {
	return u[i]->get_head_name();
}

int DB::get_unit_pgs(int i) {
	return u[i]->get_pgs();
}

int DB::get_unit_staff(int i) {
	return u[i]->get_staff();
}

int DB::get_DB_staff() {
	int temp = 0;
	for (size_t i = 0; i < u.size(); i++) {
		temp += u[i]->get_staff();
	}
	return temp;
}
void DB::input(std::ofstream &out) {
	for (size_t i = 0; i < u.size(); i++) {
		if (out.is_open()) {
			out << "\n \nUnit name : " << u[i]->get_unit_name() << "\nType of unit : " << get_unit_type(i) << "\nHead name : " << u[i]->get_head_name() << "\nPGS amount = " << u[i]->get_pgs() << "\nStaff amount = " << u[i]->get_staff();
			u[i]->input(out);
			out << std::endl << unsigned char(7);
		}
	}
}

std::string DB::get_unit_type(int i) {
	if (u[i]->type() == 'e')
		return "Educational";
	else
		return "Scientific";
}

int DB::get_unit_amount() {
	return u.size();
}


int DB::get_student_amount() {
	int temp = 0;
	for (size_t i = 0; i < u.size(); i++)
		temp += u[i]->get_student_amount();
	return temp;
}

int DB::unit_student_amount(std::string arg) {
	for (size_t i = 0; i < u.size(); i++)
		if (u[i]->get_unit_name() == arg)
			return	u[i]->get_student_amount();
	return -2;
}

bool DB::unit_name(std::string s) {
	for (size_t i = 0; i < u.size(); i++)
		if (u[i]->get_unit_name() == s)
			return true;
	return false;
}

bool DB::head_name(std::string s) {
	for (size_t i = 0; i < u.size(); i++)
		if (u[i]->get_head_name() == s)
			return true;
	return false;
}

bool DB::name_check(std::string s, char x) {
	for (size_t i = 0; i < u.size(); i++)
		if (u[i]->get_unit_name() == s && u[i]->type() == x)
			return false;
	return true;
}


DB::DB() {
}

DB::~DB() {
}
