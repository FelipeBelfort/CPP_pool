#include "Serializer.hpp"

int	main(void)
{
	Data		test;

	std::cout << "test1 address: " << &test << "\ntest2 address: ";
	std::cout << Serializer::deserialize(Serializer::serialize(&test)) << std::endl;

	return 0;
}
