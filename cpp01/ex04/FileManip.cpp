#include "FileManip.hpp"

FileManip::FileManip(void)
{
}

FileManip::~FileManip(void)
{
	if (_infile.is_open())
		_infile.close();
	if (_outfile.is_open())
		_outfile.close();
}

bool	FileManip::rw_file(std::string path)
{
	this->_infile.open(path.c_str());
	if (!this->_infile.is_open())
	{
		std::cerr << "error opening the file" << std::endl;
		return false;
	}
	this->_outfile.open((path + ".replace").c_str());
	if (!this->_outfile.is_open())
	{
		std::cerr << "error creating the output file" << std::endl;
		return false;
	}
	return true;
}

void	FileManip::replace(std::string old_word, std::string new_word)
{
	std::size_t	found;
	std::size_t	index;

	if (old_word.empty())
	{
		old_word = "\n";
	}
	while (std::getline(this->_infile, this->_line))
	{
		index = 0;
		found = this->_line.find(old_word);
		this->_outfile << this->_line.substr(index, found - index);
		if (found == std::string::npos)
		{
			this->_outfile << std::endl;
			continue ;
		}
		while (found != std::string::npos)
		{
		this->_outfile << new_word;
			index = found + old_word.length();
			found = this->_line.find(old_word, index);
			this->_outfile << this->_line.substr(index, found - index);
		}
		this->_outfile << std::endl;
	}

}
