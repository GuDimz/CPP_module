#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {};

HumanB::~HumanB(void) {};

void HumanB::attack(void) {
	std::cout << this->_name << " attacks with his " << _Weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& Weapon) {
	this->_Weapon = &Weapon;
}