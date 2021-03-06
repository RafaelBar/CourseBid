#pragma hdrstop   
#include "student.h"
#include "Active.h"

Student::Student(int id, string name, vector<string> courses, int points, string pass){
	this->id = id;
	this->name = name;
	this->complete_courses = courses;
	this->points = points;
	this->pass = pass;
	_status = new Active(this);

}
Student::Student(){
	this->id = 0;
	this->name = "d";
	this->points = 0;
	this->pass = "";
	_status = new Active(this);

}
//Getters
int Student::getId(){
	return this->id;
}
string Student::getName(){
	return this->name;
}
vector<string> Student::getCompleteCourses(){
	return this->complete_courses;
}
int Student::getPoints(){
	return this->points;
}
string Student::getPass(){
	return this->pass;
}
string Student::getStatus(){
	return this->_status->getState();
}
//Setters
void Student::setId(int id){
	this->id = id;
}
void Student::setName(string name){
	this->name = name;
}
void Student::setCompleteCourses(vector<string> courses){
	this->complete_courses = courses;
}
void Student::setPoints(int points){
	this->points = points;
}
void Student::setStatus(State* status){
	_status = status;
}

//other functions
void Student::display(){
	cout << "Student ID: " << this->getId() << endl;
	cout << "Name: " << this->getName() << endl;
	cout << "Complete Courses: " ;
	vector<string> list = this->getCompleteCourses();
	for (vector<string>::size_type i = 0; i != list.size(); i++) {
		cout << list[i] << " ";
	}
	cout << "\nPoints: " << this->getPoints()<< endl;
	cout << "Pass: " << this->getPass() << endl;
	this->_status->Handle();
	this->_status->printMyState();
}

void Student::Handle(){
	_status->Handle();
}

void Student::printMyState(){
	_status->printMyState();
}

void Student::operator=(const Student &S)
{
	this->id = S.id;
	this->name = S.name;
	this->complete_courses = S.complete_courses;
	this->points = S.points;
	this->pass = S.pass;
	_status = S._status;
}

#pragma package(smart_init)