#include "../header/enemigo.h"


Enemigo::Enemigo(std::string _nombre, int _vida, int _energia, int _dmg, int _frecuenciaMin, int _frecuenciaMax): Boxeador(_nombre,_vida,_energia,_dmg){
    numRandom = static_cast<int>(random(frecuenciaMin, frecuenciaMax));
    frecuenciaMin =_frecuenciaMin;
    frecuenciaMax = _frecuenciaMax;

    if(!texture.loadFromFile("../../resource/menu.jpg",sf::IntRect(20,20,20,20))){
        std::cout << "error cargar" << std::endl;
    }

    posInitial.x = 450.0f;
    posInitial.y = 100.0f;

    sprite.setTexture(texture);
    sprite.setScale(6,6);
    sprite.setPosition(posInitial);

    if (!font.loadFromFile("../../resource/arial.ttf"))
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

int Enemigo::random(int a, int b){
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(a,b);
    return distribution(generator);
}

void Enemigo::timer(Boxeador* boxeador) {
    lastAction = clock1.getElapsedTime().asSeconds();
    sprite.setPosition(posInitial); //cambiable
    if(lastAction >= numRandom){
        move(randomDirection()); // cambiable
        this->attack(boxeador);
        clock1.restart();
        std::cout << lastAction <<std::endl;
        numRandom = random(frecuenciaMin,frecuenciaMax);
        this->changeStates(1, false);
    }else if (lastAction*2 >= numRandom){
        this->changeStates(1, true);
    }
    std::fill(this->directions.begin(), this->directions.end(), false);
}

std::string Enemigo::randomDirection() {
    int randomNum = random(0,2);
    if (randomNum == 0){
        this->changeDirections(1, true);
        return "izq";
    }else if(randomNum == 1){
        this->changeDirections(3,true);
        return "der";
    }
    return "none";
}

void Enemigo::move( std::string dir = "none"){
    int x;
    if (dir == "der"){
        x = 1;
    }else if(dir == "izq"){
        x = -1;
    }else{
        x = 0;
    }
    this->sprite.move(100*x,100);
}
