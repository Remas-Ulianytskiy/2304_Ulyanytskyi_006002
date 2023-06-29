#include <iostream>
#include <vector>

using namespace std;

int create_uniq_id(vector<int>& uniq_id) {
	srand(time(0));
	int id = rand() % 900000 + 100000;

	if (uniq_id.empty())
		return id;
	else 
		while (find(uniq_id.begin(), uniq_id.end(), id) != uniq_id.end())
			id = rand() % 900000 + 100000;

	uniq_id.push_back(id);
	return id;
}

class Person {
protected:
	int id;
	int passport_number;
	int birthday;
	string first_name;
	string second_name;
	string information;

public:
	Person(int id, int passport_number, int birthday, const string& first_name, const string& second_name, const string& information)
		: id(id), passport_number(passport_number), birthday(birthday), first_name(first_name), second_name(second_name), information(information)
	{}

	void set_id(int id) { this->id = id; }
	void set_passport_number(int passport_number) { this->passport_number = passport_number; }
	void set_birthday(int birthday) { this->birthday = birthday; }
	void set_first_name(string& first_name) { this->first_name = first_name; }
	void set_second_name(string& second_name) { this->second_name = second_name; }
	void set_information(string& information) { this->information = information; }

	int get_id() const { return id; }
	int get_passport_number() const { return passport_number; }
	int get_birthday() const { return birthday; }
	string get_first_name() const { return first_name; }
	string get_second_name() const { return second_name; }
	string get_information() const { return information; }
};

class Student : public Person {
protected:
	string institution;
	string specialization;
	string group;

public:
	Student(int id, int passport_number, int birthday, const string& first_name, const string& second_name, const string& information,
		const string& institution, const string& specialization, const string& group)
		: Person(id, passport_number, birthday, first_name, second_name, information),
		institution(institution), specialization(specialization), group(group)
	{}

	void set_institution(string& institution) { this->institution = institution; }
	void set_specialization(string& specialization) { this->specialization = specialization; }
	void set_group(string& group) { this->group = group; }

	string get_institution() const { return institution; }
	string get_specialization() const { return specialization; }
	string get_group() const { return group; }
};

int main()
{
	vector<int> uniq_id_array;
	vector<Student> students_array;

	Student student_1(create_uniq_id(uniq_id_array), 5504, 930524, "Remas", "Orca", "Some information",
		"ITEA", "Computer Science", "2304");

	Student student_2(create_uniq_id(uniq_id_array), 1396, 911123, "Barsik", "Kit", "Some information",
		"XVX", "Engineering", "1");

	Student student_3(create_uniq_id(uniq_id_array), 2499, 970102, "Bob", "Bobius", "Some information.",
		"OOW", "Engineering", "2");

	students_array.push_back(student_1);
	students_array.push_back(student_2);
	students_array.push_back(student_3);

	cout << "All " << students_array.size() << " students:\n\n";
	for (int i = 0; i < students_array.size(); ++i) {
		const Student& student = students_array[i];
		cout << "ID: " << student.get_id() << endl;
		cout << "First Name: " << student.get_first_name() << endl;
		cout << "Last Name: " << student.get_second_name() << endl;
		cout << "Birthday: " << student.get_birthday() << endl;
		cout << "Passport Number: " << student.get_passport_number() << endl;		
		cout << "Institution: " << student.get_institution() << endl;
		cout << "Specialization: " << student.get_specialization() << endl;
		cout << "Group: " << student.get_group() << endl;
		cout << "Information: " << student.get_information() << endl;
		cout << endl;
	}

	return 0;
}