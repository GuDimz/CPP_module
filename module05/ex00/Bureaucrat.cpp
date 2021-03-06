#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	_grade = grade;
	checkGrade();
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(Bureaucrat const& object) : _name(object._name) {
	*this = object;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& object) {
	this->_grade = object.getGrade();
	checkGrade();
	return *this;
}

std::string const& Bureaucrat::getName(void) const {
	return this->_name;
}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void Bureaucrat::checkGrade(void) {
	if (getGrade() > 150) {
		throw GradeTooLowException();
	} else if (getGrade() < 1) {
		throw GradeTooHighException();
	}
}

void  Bureaucrat::increment(void) {
	--this->_grade;
	checkGrade();
}

void Bureaucrat::decrement(void) {
	++this->_grade;
	checkGrade();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "\x1b[1;31mSorry, '1' is the maximum grade!\x1b[0m";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "\x1b[1;31mSorry, '150' is the minimum grade!\x1b[0m";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& object) {
	os << GREEN << object.getName() << REST ", bureaucrat grade " CYAN << object.getGrade() << REST ".";
	return os;
}