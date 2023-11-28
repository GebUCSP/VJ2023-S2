#include "../header/boxeador.h"

Boxeador::Boxeador(std::string _nombre, int _vida, int _energia, int _dmg):nombre{_nombre}, vida{_vida}, energia{_energia}, dmg{_dmg}{
    this->nombre = _nombre;
    this->dmg = _dmg;
    this->vida = _vida < 0 ? 100 : _vida;
    this->energia = _energia < 0 ? 100 : _energia;
    this->lastAction = 0.0;
    clock1.restart();
}

Boxeador::~Boxeador()=default;

//FUNCIONES

void Boxeador::drawMe(sf::Sprite &image, sf::Texture &textura) {
    sf::IntRect rectangulo_imagen = image.getTextureRect(); // se obtiene la info sobre las coordenadas de la imagen actual
    
    rectangulo_imagen.left += 256;  // se incrementa el ancho de cada imagen a la actual

    if (rectangulo_imagen.left + rectangulo_imagen.width > textura.getSize().x) { // verificamos si el siguiente cuadro excede al ancho total
        rectangulo_imagen.left = 0; // si cumple, se restablece a la posicion inicial (0)
    }

    image.setTextureRect(rectangulo_imagen);
}

//FUNCIONES SET

void Boxeador::setNombre(std::string _nombre) {
    this->nombre = _nombre;
}

void Boxeador::setVida(int _vida) {
    this->vida = _vida;
}

void Boxeador::setEnergia(int _energia) {
    this->energia = _energia;
}

void Boxeador::setDmg(int _dmg){
    this->dmg = _dmg;
}

void Boxeador::changeStates(int index, bool boolean) {
    states[index] = boolean;
}

void Boxeador::changeDirections(int index, bool boolean) {
    directions[index] = boolean;
}

//FUNCIONES GET

sf::Sprite &Boxeador::getSprite() {
    return s_golpes;
}

std::string Boxeador::getNombre(){
    return nombre;
}

int Boxeador::getVida() {
    return vida;
}

int Boxeador::getEnergia() {
    return energia;
}

int Boxeador::getDmg() {
    return dmg;
}

bool Boxeador::getStates(int index) {
    return states[index];
}

bool Boxeador::getDirections(int index) {
    return directions[index];
}


//BORRAR
void Boxeador::print() {
    for(auto state: states){
        std::cout << state << " ";
    }
    std::cout << std::endl;

    for(auto direction: directions){
        std::cout << direction << " ";
    }
    std::cout << std::endl;

}

void Boxeador::attack(Boxeador* objetivo) {
    if(!objetivo->getStates(1) && !objetivo->getStates(2)){
        objetivo->setVida(objetivo->getVida()-this->getDmg());
    }else if(objetivo->getStates(2) || objetivo->getStates(1)){
        objetivo->setEnergia(objetivo->getEnergia()-20);
    }
}
