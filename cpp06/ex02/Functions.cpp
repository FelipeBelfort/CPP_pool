#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// "It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation."
Base * generate(void)
{
	int		rand;
	Base	*ptr = NULL;

	rand = std::rand() % 3;
	switch (rand)
	{
	case 0:
		ptr = new A();
		break;
	case 1:
		ptr = new B();
		break;
	case 2:
		ptr = new C();
		break;
	default:
		std::cout << "Error : Could not generate" << std::endl;
		break;
	}
	return ptr;
}

// "It prints the actual type of the object pointed to by p: "A", "B" or "C"."
void identify(Base* p)
{
	A	*testA = dynamic_cast<A*>(p);
	B	*testB = dynamic_cast<B*>(p);
	C	*testC = dynamic_cast<C*>(p);

	if (testA)
		std::cout << "This pointer is an instance of a A class" << std::endl;
	else if (testB)
		std::cout << "This pointer is an instance of a B class" << std::endl;
	else if (testC)
		std::cout << "This pointer is an instance of a C class" << std::endl;
	else
		std::cout << "This pointer is an instance of an unknown class" << std::endl;
}

// "It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
// inside this function is forbidden."
void identify(Base& p)
{
	try
	{
		A	&testA = dynamic_cast<A&>(p);
		(void)testA;
		std::cout << "This address is an instance of a A class" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B	&testB = dynamic_cast<B&>(p);
			(void)testB;
			std::cout << "This address is an instance of a B class" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C	&testC = dynamic_cast<C&>(p);
				(void)testC;
				std::cout << "This address is an instance of a C class" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "This address is an instance of an unknown class" << std::endl;
			}
		}
	}
}
