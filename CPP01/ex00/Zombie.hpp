#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
private:
    std::string name;

public:
    Zombie();
    Zombie(const std::string &name);
    ~Zombie();

    void        announce(void) const;
    void        setName(const std::string &name);
};

Zombie* newZombie(const std::string &name);
void    randomChump(const std::string &name);

#endif
