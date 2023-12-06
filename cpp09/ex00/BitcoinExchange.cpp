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
	this->_gate = false;
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
		// std::cout << "tab[" << i << "] = " << this->_tab[i] << std::endl;
		i++;
	}
	return ;
}


void	Bitcoin::parse_tab_date(std::string tab)
{
	size_t token = tab.find(' ');
	std::string temp = tab.substr(0, token);
	if (temp[4] && temp[7] != '-')
	{
		std::cout << "Error : Bad input => " << temp << std::endl;
		this->_gate = true;
		return ;
	}
	size_t point = temp.find('-');
	std::string tmp = temp.substr(0, point);
	int check = std::atoi(tmp.c_str());
	if ((check < 2009 || check > 2022))
	{
		std::cout << "Error : Bad input => " << temp << std::endl;
		this->_gate = true;
		return ;
	}
	tmp.erase();
	size_t point2 = temp.find('-', point);
	tmp = temp.substr(point + 1, point2 - 2);
	if (tmp[0] == '0')
		tmp.erase(0, 1);
	check = std::atoi(tmp.c_str());
	if ((check < 1 || check > 12))
	{
		std::cout << "Error : Bad input => " << temp << std::endl;
		this->_gate = true;
		return ;
	}
	tmp.erase();
	tmp = temp.substr(point2 + 4, temp.size() - point2);
	if (tmp[0] == '0')
		tmp.erase(0, 1);
	check = std::atoi(tmp.c_str());
	if ((check < 1 || check > 31))
	{
		std::cout << "Error : Bad input => " << temp << std::endl;
		this->_gate = true;
		return ;
	}
	return ;
}

void	Bitcoin::parse_pipe_tab(std::string tab)
{
	if (this->_gate == true)
		return ;
	size_t pipe = tab.find('|');
	if (pipe == std::string::npos)
	{
		std::cout << "Error, wrong format : need '|'" << std::endl;
		this->_gate = true;
		return ;
	
	}else
	{
		const char *tmp = tab.c_str();
		size_t j = 0;
		while (j < pipe)
		{
			if (tmp[j] == ' ')
				break;
			j++;
		}
		if (tmp[j + 1] && tmp[j + 1] != '|')
		{
			std::cout << "Error, wrong format : need ' | '" << std::endl;
			this->_gate = true;
			return ;
		}
		while (tmp[j] != '|')
			j++;
		if (tmp[j + 1] && tmp[j + 1] != ' ')
		{
			std::cout << "Wrong format : need ' ' after pipe" << std::endl;
			this->_gate = true;
			return ;
		}
		j++;
		if (is_digit(tmp[j + 1]) == 0)
		{
			std::cout << "Need digit after one space" << std::endl;
			this->_gate = true;
			return ;
		}
		else if (is_digit(tmp[j + 1]) == 3)
		{
			std::cout << "Error : not a positive number" << std::endl;
			this->_gate = true;
			return ;
		}
		else if (is_digit(tmp[j + 1]) == 2 && (is_digit(tmp[j + 2]) == 0 || is_digit(tmp[j + 2]) == 2))
			std::cout << "Wrong number format : only '+1' and '1' numbers prototype accepted" << std::endl;
	}
	return ;
}

void	Bitcoin::check_number(std::string tab)
{
	if (this->_gate == true)
		return ;
	size_t token = tab.find('|');
	if (token != std::string::npos)
	{
		std::string str = tab.substr(token + 2, std::string::npos);
		double check = std::strtod(str.c_str(), NULL);
		if (check > 1000)
		{
			std::cout << "Error : too large number" << std::endl;
			this->_gate = true;
		}
	}
	return ;
}

void	Bitcoin::do_operation(std::string tab)
{
	if (this->_gate == true)
		return ;
	size_t token = tab.find(' ');
	std::string temp = tab.substr(0, token);
	std::map<std::string, double>::const_iterator it = this->_map.find(temp);
	if (it != this->_map.end())
	{
		token = tab.find('|');
		if (token != std::string::npos)
		{
			std::string str = tab.substr(token + 2);
			double number = std::strtod(str.c_str(), NULL);
			double result = number * it->second;
			std::cout << temp << " = > " << number << " = " << result << std::endl;
		}
	}
	else
	{
		std::map<std::string, double>::const_iterator it = this->_map.lower_bound(tab);
		if (it == this->_map.begin() || it == this->_map.end())
			return ;
		else
			it--;
		std::string str = tab.substr(token + 2);
		double number = std::strtod(str.c_str(), NULL);
		double result = number * it->second;
		std::cout << temp << " = > " << number << " = " << result << std::endl;
	}
	return ;
}

void	Bitcoin::do_program(void)
{
	if (this->_tab[0].compare("date | value") != 0)
	{
		std::cout << "input.txt first line error : 'date | value' needed" << std::endl;
		return ;
	}
	int i = 1;
	while (i < this->_tabLen)
	{
		this->_gate = false;
		parse_tab_date(this->_tab[i]);
		parse_pipe_tab(this->_tab[i]);
		check_number(this->_tab[i]);
		do_operation(this->_tab[i]);
		i++;
	}
	return ;
}


std::map<std::string, double> Bitcoin::getMap(void) const
{
	return (this->_map);
}

int	Bitcoin::is_digit(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else if (c == '+')
		return (2);
	else if (c == '-')
		return (3);
	return (0);
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




// #include <iostream>
// #include <map>
// #include <string>

// // ... (Initialisation de votre std::map)

// // Supposons que vous avez votre std::map rempli ici

// // Fonction pour obtenir la date la plus proche inférieure
// std::string getClosestDate(const std::map<std::string, double>& myMap, const std::string& searchDate) {
//     std::map<std::string, double>::const_iterator it = myMap.lower_bound(searchDate);
//     if (it == myMap.begin() || it == myMap.end()) {
//         // Si la date est inférieure à toutes les entrées ou si le std::map est vide
//         return ""; // Aucune date trouvée
//     } else {
//         --it; // Pour obtenir la date la plus proche inférieure
//         return it->first;
//     }
// }

// // Fonction pour effectuer le calcul si la date correspond
// void calculateIfDateExists(const std::map<std::string, double>& myMap, const std::string& searchDate) {
//     std::map<std::string, double>::const_iterator it = myMap.find(searchDate);
//     if (it != myMap.end()) {
//         // Date trouvée, effectuer le calcul
//         double value = it->second;
//         // Faites votre calcul ici avec la valeur trouvée
//         std::cout << "Date trouvée : " << searchDate << " => " << value << std::endl;
//     } else {
//         // Date non trouvée, recherche de la date la plus proche inférieure
//         std::string closestDate = getClosestDate(myMap, searchDate);
//         if (!closestDate.empty()) {
//             // Date la plus proche inférieure trouvée
//             std::cout << "Date la plus proche inférieure : " << closestDate << std::endl;
//             // Faites ce que vous devez avec la date la plus proche inférieure
//         } else {
//             // Aucune date trouvée
//             std::cout << "Aucune date trouvée." << std::endl;
//         }
//     }
// }

// // Utilisation :
// int main() {
//     // ... (Lecture de votre fichier)

//     std::string searchDate = "2021-05-25"; // Date à rechercher

//     // Exemple d'utilisation avec votre std::map
//     calculateIfDateExists(yourMap, searchDate);

//     return 0;
// }
