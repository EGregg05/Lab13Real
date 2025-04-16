#include "Template.hpp"

int main(void)
{
	std::string data = "The Data";
	
	List<std::string> newList();

	std::cout << "Is the list empty: " << newList().isEmpty() << std::endl;

	newList().insertAtFront(data);

	std::cout << "Is the list empty: " << newList().isEmpty() << std::endl;

	if (!newList().isEmpty())
	{
		newList().print();
	}
	

}