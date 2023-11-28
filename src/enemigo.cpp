#include "../header/enemigo.h"


Enemigo::Enemigo(std::string _nombre, int _vida, int _energia, int _dmg, int _frecuenciaMin, int _frecuenciaMax): Boxeador(_nombre,_vida,_energia,_dmg){
    numRandom = static_cast<int>(random());
    frecuenciaMin =_frecuenciaMin;
    frecuenciaMax = _frecuenciaMax;

    if (!font.loadFromFile("resource/arial.ttf"))
    {
        std::cout << "fallo carga fuente enemigo" << std::endl;
    }
    vida_f.setFont(font);
    energia_f.setFont(font);
    nombre_f.setFont(font);
    vida_f.setPosition(800,10);
    energia_f.setPosition(800,40);
    nombre_f.setPosition(700,20);
}

void Enemigo::inputs(sf::Keyboard::Key, bool) {
    return;
}

int Enemigo::random(){
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(frecuenciaMin,frecuenciaMax);
    return distribution(generator);
}

void Enemigo::timer(Boxeador* boxeador) {
    lastAction = clock1.getElapsedTime().asSeconds();
    if(lastAction >= numRandom){
        this->attack(boxeador);
        clock1.restart();
        numRandom = random();
        this->states[1] = false;
    }else if (lastAction*2 >= numRandom){
        this->states[1] = true;
    }
}

