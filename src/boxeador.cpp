#include "../header/boxeador.h"

Boxeador::Boxeador(std::string _nombre, int _vida, int _energia, int _dmg, bool npc):nombre{_nombre}, vida{_vida}, energia{_energia}, dmg{_dmg}{
    this->nombre = _nombre;
    this->dmg = _dmg;
    this->vida = _vida < 0 ? 100 : _vida;
    this->energia = _energia < 0 ? 100 : _energia;
    this->lastAction = 0.0;
    clock1.restart();


    textures.resize(3);
    std::string temp = npc ? "e" : "p";
    for(int i = 0; i < textures.size(); i++){
        if(!texture.loadFromFile("../../resource/"+ temp + "_img("+std::to_string(i+1)+").png")){
            std::cout << "error cargar" << std::endl;
        }
        textures[i] = texture;
    }

    if (!font.loadFromFile("../../resource/font.ttf"))
    {
        std::cout << "fallo carga fuente" << std::endl;
    }

    for(auto i: textures){
        i.setSmooth(true);
    }

    sprite.setTexture(textures[0]);
    sprite.setOrigin(sprite.getLocalBounds().width,sprite.getLocalBounds().height);
    sprite.setTextureRect(sf::IntRect (0,0,256,256));
    sprite.setScale(1.7,1.7);


    vida_f.setFont(font);
    energia_f.setFont(font);
    nombre_f.setFont(font);
}

Boxeador::~Boxeador()=default;

void Boxeador::setVida(int _vida) {
    this->vida = _vida;
}

void Boxeador::setEnergia(int _energia) {
    this->energia = _energia;
}


void Boxeador::changeStates(int index, bool boolean) {
    states[index] = boolean;
}

void Boxeador::changeDirections(int index, bool boolean) {
    directions[index] = boolean;
}

sf::Sprite Boxeador::getSprite(){
    return this->sprite;
}

sf::Texture Boxeador::getTexture() {
    return this->texture;
}

int Boxeador::getVida() const {
    return vida;
}

int Boxeador::getEnergia() const {
    return energia;
}

int Boxeador::getDmg() const {
    return dmg;
}


bool Boxeador::getStates(int index) const {
    return states[index];
}

bool Boxeador::getDirections(int index) const{
    return directions[index];
}


void Boxeador::attack(Boxeador* objetivo) {
    if(objetivo->getStates(0) && this->getStates(0)){
        objetivo->setVida(objetivo->getVida()-10);
        this->setVida(this->getVida()-10);
    }else if(!objetivo->getStates(1)){
        objetivo->setVida(objetivo->getVida()-this->getDmg());
    }else if(objetivo->getStates(1) && this->directions == objetivo->directions){
        objetivo->setEnergia(objetivo->getEnergia()-10);
    }else if(objetivo->getStates(1)){
        objetivo->setEnergia(objetivo->getEnergia()-20);
    }
}


void Boxeador::updateIu() {
    vida_f.setString("VIDA: " + std::to_string(this->vida));
    energia_f.setString("ENERGIA: " + std::to_string(this->energia));
    nombre_f.setString(this->nombre);
}

void Boxeador::iu(sf::RenderWindow* window){
    window->draw(vida_f);
    window->draw(energia_f);
    window->draw(nombre_f);
}
