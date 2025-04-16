#include "Task3.hpp"
#include "Animals.hpp"

int main()
{
	Mammal* pDog = new Dog;

	pDog->Move();

	pDog->Speak();

	//Dog *pDog2 = new Dog;
	//pDog2->Move();
	//pDog2->Speak();

	return 0;
}
