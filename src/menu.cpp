#include "../header/menu.h"

Menu::Menu(sf::RenderWindow *_window): window{_window}{

    //Comprobacion si el achivo llego a cargar o no
    if(!background.loadFromFile("../../resource/menu.png")){
        std::cerr << "Error al cargar texturas";
    }
    backgroundImage.setTexture(background);

    //Set del fondo
    sf::Vector2u sizeW = window->getSize();
    backgroundImage.setScale(static_cast<float> (sizeW.x) / background.getSize().x, static_cast<float> (sizeW.y) / background.getSize().y);

    //boton play *posicion , tamaño y transparencia
    play.setPosition(static_cast<float>(sizeW.x-200),static_cast<float>(sizeW.y-140));
    play.setSize(sf::Vector2f (350,90));
    play.setFillColor(sf::Color::Transparent);

    //boton exit *posicion , tamaño y transparencia
    exit.setPosition(static_cast<float>(sizeW.x-170),static_cast<float>(sizeW.y+30));
    exit.setSize(sf::Vector2f (280,70));
    exit.setFillColor(sf::Color::Transparent);
}


void Menu::checkMouseClick1() {
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    sf::Vector2f mousePosCoords = window->mapPixelToCoords(mousePos);
    //Detectar si se ha oprimido el boton play
    if (play.getGlobalBounds().contains(mousePosCoords)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            a_play = true;
            deleteSprites = true;
        }
    }
    //Detectar si se ha oprimido el boton exit
    if (exit.getGlobalBounds().contains(mousePosCoords)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            a_exit = true;
        }
    }
}
void Menu::dibujarFondo() {
    window->draw(backgroundImage);
    window->draw(play);
    window->draw(exit);
}

bool Menu::getDelete() const {
    return deleteSprites;
}
