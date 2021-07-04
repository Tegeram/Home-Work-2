#include <iostream>

using namespace std;

//==EXERCISE 1=========================================================================================

class Person {
protected:
	string m_name;
	int m_age;
	char m_gender;
	int m_weight;
public:
	Person(string name, int age, char gender, int weight) : m_name(name), m_age(age), m_gender(gender), m_weight(weight) {

	}

	string getName() const {
		return m_name;
	}
	int getAge() const {
		return m_age;
	}
	char getGender() const {
		return m_gender;
	}
	int getWeight() const {
		return m_weight;
	}
};

class Student : Person {
private:
	int EdYear;
	static int counter;
public:	

	Student(string name, int age, char gender, int weight, int year): Person(name, age, gender, weight),EdYear(year) {
		counter++;
	}
	~Student() {
		counter--;
	}

	static int getCount() {
		return counter;
	}
	int getEdYear() const {
		return EdYear;
	}
	void print() const {
		cout << " Name: " << m_name << " Age: " << m_age << " Gender: " << m_gender << " Weight: " << m_weight << " Year of education: " << EdYear << endl;
	}

};

int Student::counter = 0;

//==EXERCISE 2=========================================================================================

class Fruit {
protected:
	string m_name;
	string m_color;
public:
	Fruit(string name, string color) : m_name(name), m_color(color) {

	}

	string getName() const{
		return m_name;
	}

	string getColor() const{
		return m_color;
	}
};

class Apple : public Fruit {
public:
	Apple(string color, string name = "apple") : Fruit(name, color) {

	}
};

class Banana : public Fruit{
public:
	Banana(string name = "banana", string color = "yellow") : Fruit(name, color) {

	}
};

class GrannySmith : public Apple {
public:
	GrannySmith(string name = "Granny Smith apple",string color = "green") : Apple(color,name) {

	}
};


//==EXERCISE 3=========================================================================================

class Player {

};

class Cards{

};

class Turn {

};

class Game : Player, Cards, Turn {

};

//=====================================================================================================

int main()
{
	cout << " Ex 1" << endl;
	Student st1("Ivan", 23, 'M', 75, 4);
	Student st2("Masha", 19, 'F', 53, 2);
	Student st3("Petya", 18, 'M', 90, 1);
	st1.print();
	st2.print();
	st3.print();
	cout << " Number of students: "<<Student::getCount() << endl;

	//================================================================================================

	cout << endl << " Ex 2" << endl;
	Apple a("red");
	Banana b;
	GrannySmith c;

	cout << " My " << a.getName() << " is " << a.getColor() << endl;
	cout << " My " << b.getName() << " is " << b.getColor() << endl;
	cout << " My " << c.getName() << " is " << c.getColor() << endl;

	return 0;
}
