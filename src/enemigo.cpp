#include "../header/enemigo.h"


Enemigo::Enemigo(std::string _nombre, int _vida, int _energia, int _dmg, int _frecuenciaMin, int _frecuenciaMax, bool npc): Boxeador(_nombre,_vida,_energia,_dmg, npc){

    numRandom = static_cast<int>(random(frecuenciaMin, frecuenciaMax));
    frecuenciaMin =_frecuenciaMin;
    frecuenciaMax = _frecuenciaMax;

    posInitial.x = 800.0f;
    posInitial.y = 450.0f;

    sprite.setPosition(posInitial);
    vida_f.setPosition(770,10);
    energia_f.setPosition(770,40);
    nombre_f.setPosition(650,20);
}

void Enemigo::inputs(sf::Keyboard::Key key, bool isPressed) {
    std::vector<sf::Keyboard::Key>teclas = {sf::Keyboard::A,sf::Keyboard::D,sf::Keyboard::J,sf::Keyboard::K};
    isPressed = random(0,2);
    key = teclas[random(0,3)];
    lastAction = clock1.getElapsedTime().asSeconds();
    if(isPressed && lastAction >= numRandom){
        switch (key) {
            case sf::Keyboard::A:
                changeDirections(0, isPressed);
                break;
            case sf::Keyboard::W:
                changeDirections(1, isPressed);
                break;
            case sf::Keyboard::D:
                changeDirections(2, isPressed);
                break;
            case sf::Keyboard::S:
                changeDirections(3, isPressed);
                break;
            default:
                break;
        }

        switch (key) {
            case sf::Keyboard::J:
                changeStates(0, isPressed);
                break;
            case sf::Keyboard::K:
                changeStates(1, isPressed);
                break;
            default:
                break;
        }
        clock1.restart();
    }

    if(!isPressed){
        std::fill(directions.begin(), directions.end(),false);
        std::fill(states.begin(), states.end(),false);
    }

    this->sprite.setPosition(posInitial);
    this->sprite.setScale(1.7f,1.7f);
    this->sprite.setTexture(textures[0]);

    if(states[0] || states[1]){
        movement();
    }

    numRandom = random(frecuenciaMin,frecuenciaMax);
}

int Enemigo::random(int a, int b){
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(a,b);
    return distribution(generator);
}

void Enemigo::movement(){
    dirImg = 0;
    float x= 1.8f;
    if (directions[0]){
        dirImg = 1;
    }else if(directions[2]){
        dirImg = -1;
    }else{
        dirImg = 0;
        x = 1.9f;
    }

    if(states[0]){
        this->sprite.setTexture(textures[2]);
        this->sprite.move(50.0f*dirImg,50.0f);
        this->sprite.setScale(x, x);

    }else if(states[1]){
        this->sprite.setTexture(textures[1]);
        if(directions[0] || directions[2]){
            this->sprite.move(50.0f*dirImg,50.0f);
        }
    }else{
        this->sprite.setTexture(textures[0]);
    }
}
