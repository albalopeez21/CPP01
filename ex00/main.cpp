#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    Zombie* z1 = newZombie("Foo");
    z1->announce();
    delete z1;

    randomChump("Bar");

    return 0;
}
