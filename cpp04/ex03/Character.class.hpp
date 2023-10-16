#ifndef CHARACTER_CLASS_HPP
#define CHARACTER_CLASS_HPP

#include "ICharacter.class.hpp"

class Character : public ICharacter
{
    public :
            Character(void);
            Character(std::string name);
            Character(Character const &src);
            ~Character(void);

            Character &operator=(Character const &rhs);

    private :
            std::string _name;
            
}


#endif