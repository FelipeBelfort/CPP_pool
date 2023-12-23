#include "FileManip.hpp"

int	main(int argc, char **argv)
{
	FileManip	sed;

	if (argc != 4)
	{
		std::cerr << "usage: <file> old_word new_word" << std::endl;
		return (1);
	}
	if (!sed.rw_file(argv[1]))
		return (1);
	sed.replace(argv[2], argv[3]);

	return (0);
}
