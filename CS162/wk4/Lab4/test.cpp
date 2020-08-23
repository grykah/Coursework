#include <string>
using namespace std; 

class Building
{
public:
Person();
Person(string n, string a)
string getName();
string getAddress();
virtual string whatami() {

private:
string name;
string address;
};




class Person
{
public:

Person();
Person(string n, string a, string r)
string getName();
string getAge();
string getRating();
virtual string whatami() {

private:
string name;
string age;
string rating;
};

Person::Person()
{
name = "default_name";
age = "default_age";
rating = "default_rating";
}

Person::Person(string n, string a, string t)
{
name = n;
age = a;
rating = r;
}

string Person::getName()
{
return name;
}

string Person::getAddress()
{
return age;
}

string Person::getTelephone()
{
return rating;
}

class Student : public Person
{ 
public:
Student();
Student(string n, string a, string t, string s);
string do_work();
private:
string do_work;
};

Student::Student()
:Person()
{
do_work = "default_do_work";
}

Student::Student(string n, string a, string t, string s)
:Person(n,a,t)
{
status = s;
}

string Student::getStatus()
{
return status;
}

class Instructor : public Person
{
public:
Instructor();
Instructor(string n, string a, string t, string s, string o);
string getOffice();

private:
string office;
};

}