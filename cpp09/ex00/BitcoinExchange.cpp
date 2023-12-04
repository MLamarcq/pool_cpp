#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(void) : _tabLen(0)
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		throw (ErrorOpeningFileException());
	}
	std::string input;
	int i = 0;
	while (std::getline(file, input))
	{
		if (i != 0)
		{
			std::string str = input.substr(0, 10);
			std::string db = input.substr(11, input.size() - 11);
			double dbl = std::strtod(db.c_str(), NULL);
			// // std::cout << "str = " << str << std::endl;
			// // std::cout << "db = " << db << std::endl;
			// std::cout << "dbl = " << dbl << std::endl;
			this->_map[str] = dbl;
			// str.erase();
			// db.erase();
		}
		i++;
	}
	// for (std::map<std::string, double>::const_iterator it = this->_map.begin(); it != this->_map.end(); it++)
	// {
	// 	std::string key = it->first;
	// 	double nb = it->second;
	// 	std::cout << key << "  " << nb << std::endl;
	// }
	this->_tab = NULL;
	return ;
}

Bitcoin::Bitcoin(Bitcoin const & src)
{
	*this = src;
	return ;
}

Bitcoin::~Bitcoin(void)
{
	if (this->_tab)
		delete [] this->_tab;
	return ;
}

Bitcoin & Bitcoin::operator=(Bitcoin const &rhs)
{
	if (this != &rhs)
	{
		this->_map = rhs.getMap();
	}
	return (*this);
}

void	Bitcoin::open_and_save_input(std::string argv)
{
	if (argv.compare("input.txt") != 0)
	{
		throw(WrongFileFormatException());
	}
	std::ifstream file(argv.c_str());
	if (!file.is_open())
	{
		throw(ErrorOpeningFileException());
	}
	std::string input;
	while (std::getline(file, input))
		this->_tabLen++;
	std::ifstream file_2(argv.c_str());
	if (!file_2.is_open())
	{
		throw(ErrorOpeningFileException());
	}
	std::string new_input;
	this->_tab = new std::string[this->_tabLen];
	int i = 0;
	while (std::getline(file_2, new_input))
	{
		this->_tab[i] = new_input;
		i++;
	}
	return ;
}


void	Bitcoin::parse_tab_date(void)
{
	// for (int i = 0; i < this->_tabLen; i++)
	// 	std::cout << this->_tab[i] << std::endl;
	int i = 1;
	while (i < this->_tabLen)
	{
		size_t token = this->_tab[i].find(' ');
		std::string temp = this->_tab[i].substr(0, token);
		if (temp[4] && temp[7] != '-')
		{
			throw (WrongDateFormatException());
			std::cout << " At line : " << i + 1 << std::endl;
		}
		size_t point = temp.find('-');
		std::string tmp = temp.substr(0, point);
		std::cout << "tmp first time for year = " << tmp << std::endl;
		int check = std::atoi(tmp.c_str());
		if (check < 2009 || check > 2022)
		{
			throw(WrongDateFormatException());
		}
		tmp.erase();
		size_t point2 = temp.find('-', point);
		tmp = temp.substr(point + 1, point2 - 2);
		if (tmp[0] == '0')
			tmp.erase(0, 1);
		std::cout << "tmp second time for month = " << tmp << std::endl;
		check = std::atoi(tmp.c_str());
		if (check < 1 || check > 12)
		{
			throw(WrongDateFormatException());
		}
		tmp.erase();
		tmp = temp.substr(point2 + 4, temp.size() - point2);
		if (tmp[0] == '0')
			tmp.erase(0, 1);
		std::cout << "tmp second time for days = " << tmp << std::endl;
		check = std::atoi(tmp.c_str());
		if (check < 1 || check > 31)
		{
			throw(WrongDateFormatException());
		}
		temp.erase();
		std::cout << std::endl;
		i++;
	}
	return ;
}

std::map<std::string, double> Bitcoin::getMap(void) const
{
	return (this->_map);
}

const char *Bitcoin::ErrorOpeningFileException::what() const throw()
{
	return ("Error during openig file");
}

const char *Bitcoin::WrongFileFormatException::what() const throw()
{
	return ("Wrong file : 'input.txt' needed");
}


const char *Bitcoin::WrongDateFormatException::what() const throw()
{
	return ("Error : Wrong date format");
}