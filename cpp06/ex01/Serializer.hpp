#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

typedef unsigned long	uintptr_t;

class Serializer
{
private:
	Serializer(void);
	~Serializer(void);
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &copy);
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
