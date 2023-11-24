#include "../header/enemigo.h"


Enemigo::Enemigo(std::string _nombre, int _vida, int _energia, int _dmg): Boxeador(_nombre,_vida,_energia,_dmg){
    numRandom = static_cast<int>(random());
}

void Enemigo::drawMe() {
    return;
}

void Enemigo::inputs(sf::Keyboard::Key, bool) {
    return;
}

int Enemigo::random(){
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(3,7);
    return distribution(generator);
}

void Enemigo::timer(Boxeador* boxeador) {
    lastAction = clock1.getElapsedTime().asSeconds();
    if(lastAction >= numRandom){
        this->attack(boxeador);
        std::cout << lastAction << std::endl;
        clock1.restart();
        numRandom = random();
    }
}

