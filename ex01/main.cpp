#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "Horder");

    if (!horde)
        return 1;

    for (int i = 0; i < hordeSize; ++i) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}
