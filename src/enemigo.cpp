#include "../header/enemigo.h"


Enemigo::Enemigo(std::string _nombre, int _vida, int _energia, int _dmg, int _frecuenciaMin, int _frecuenciaMax): Boxeador(_nombre,_vida,_energia,_dmg){
    //////////////////////////////
    if(!texture.loadFromFile("../../resource/e_img(1).png")){
        std::cout << "error cargar" << std::endl;
    }
    if(!texture1.loadFromFile("../../resource/e_img(2).png")){
        std::cout << "error fatal" << std::endl;
    }
    if(!texture2.loadFromFile("../../resource/e_img(3).png")){
        std::cout << "error fatal" << std::endl;
    }
    if(!texture3.loadFromFile("../../resource/p_img(3).png")){
        std::cout << "error fatal" << std::endl;
    }

    /////////////////////////

    texture.setSmooth(true);
    texture1.setSmooth(true);
    texture2.setSmooth(true);

    numRandom = static_cast<int>(random(frecuenciaMin, frecuenciaMax));
    frecuenciaMin =_frecuenciaMin;
    frecuenciaMax = _frecuenciaMax;

    sprite.setOrigin(sprite.getLocalBounds().width,sprite.getLocalBounds().height);

    posInitial.x = 300.0f;
    posInitial.y = -20.0f;

    sprite.setTexture(texture);

    sprite.setTextureRect(sf::IntRect (0,0,256,256));
    sprite.setScale(1.7,1.7);
    sprite.setPosition(posInitial);

    if (!font.loadFromFile("../../resource/font.ttf"))
    {
        std::cout << "fallo carga fuente enemigo" << std::endl;
    }
    vida_f.setFont(font);
    energia_f.setFont(font);
    nombre_f.setFont(font);
    vida_f.setPosition(770,10);
    energia_f.setPosition(770,40);
    nombre_f.setPosition(650,20);
}

void Enemigo::inputs(sf::Keyboard::Key key, bool isPressed) {
    std::vector<sf::Keyboard::Key>teclas = {sf::Keyboard::A,sf::Keyboard::D,sf::Keyboard::J,sf::Keyboard::K};
    isPressed = random(0,2);
    key = teclas[random(0,2)];
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
            case sf::Keyboard::L:
                changeStates(2, isPressed);
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
    this->sprite.setTexture(texture);

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

void Enemigo::timer(Boxeador* boxeador) {
    return ;
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

void Enemigo::movement(){
    dirImg = 0;
    float x= 1.8f;
    if (directions[0]){
        dirImg = 1;
    }else if(directions[2]){
        dirImg = -1;
    }else{
        dirImg = 0;
        x = 2.0f;
    }

    if(states[0]){
        this->sprite.setTexture(texture2);
        this->sprite.move(50.0f*dirImg,50.0f);
        this->sprite.setScale(x, x);

    }else if(states[1]){
        if(directions[0] || directions[2]){
            this->sprite.move(50.0f*dirImg,50.0f);
        }
        this->sprite.setTexture(texture1);
    }else{
        this->sprite.setTexture(texture);

    }
}
