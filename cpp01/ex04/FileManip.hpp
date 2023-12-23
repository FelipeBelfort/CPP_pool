#ifndef FILEMANIP_HPP
# define FILEMANIP_HPP

# include <fstream>
# include <iostream>

class FileManip
{
private:
	std::ifstream	_infile;
	std::ofstream	_outfile;
	std::string		_line;

public:
	FileManip(void);
	~FileManip(void);

	bool	rw_file(std::string path);
	void	replace(std::string old_word, std::string new_word);

};

#endif
