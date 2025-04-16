#include "Animals.hpp"

Mammal::Mammal(void) :itsAge(1)
{
	cout << "Mammal constructor..." << endl;
}

Mammal::~Mammal(void)
{
	cout << "Mammal destructor..." << endl;
}

void Mammal::Move() const
{
	cout << "Mammal moves a step!" << endl;
}

void Mammal::Speak() const
{
	cout << "What does a mammal speak? Mammilian!" << endl;
}
Dog::Dog()
{
	cout << "Dog constructor..." << endl;
}

Dog::~Dog()
{
	cout << "Dog destructor..." << endl;
}

void Dog::Move() const
{
	cout << "Dog moves a step!" << endl;
}

void Dog::Speak() const
{
	cout << "Bark! Bark!" << endl;
}
