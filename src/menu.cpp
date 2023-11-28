#include "../header/menu.h"

Menu::Menu(sf::RenderWindow *_window): window{_window}{

    //Comprobacion si el achivo llego a cargar o no
    if(!background.loadFromFile("resource/menu.jpg")){
        std::cerr << "Error al cargar texturas";
    }
    backgroundImage.setTexture(background);

    //Set del fondo
    sf::Vector2u sizeW = window->getSize();
    backgroundImage.setScale(static_cast<float> (sizeW.x) / background.getSize().x, static_cast<float> (sizeW.y) / background.getSize().y);

    //boton play *posicion , tamaño y transparencia
    play.setPosition(static_cast<float>(sizeW.x)-180,static_cast<double>(sizeW.y)-200);
    play.setSize(sf::Vector2f (300,100));
    play.setFillColor(sf::Color::Transparent);

    //boton options *posicion , tamaño y transparencia
    options.setPosition(static_cast<float>(sizeW.x)-180,static_cast<double>(sizeW.y)-100);
    options.setSize(sf::Vector2f (550,100));
    options.setFillColor(sf::Color::Transparent);

    back.setPosition(static_cast<float>(sizeW.x)-180,static_cast<double>(sizeW.y));
    back.setSize(sf::Vector2f (300,100));

    options.setFillColor(sf::Color::Transparent);
}


void Menu::checkMouseClick1() {

    sf::Vector2i mousePos = sf::Mouse::getPosition();
    sf::Vector2f mousePosCoords = window->mapPixelToCoords(mousePos);
    //Cambiar el estado del a_back
    a_back = false;
    //Detectar si se ha oprimido el boton play
    if (play.getGlobalBounds().contains(mousePosCoords)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            a_play= true;
            deleteSprites = true;
            std::cout << "Play presionado" << std::endl;
        }
    }

    //Detectar si se ha oprimido el boton options
    if (options.getGlobalBounds().contains(mousePosCoords)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            a_options= true;
            std::cout << "Options presionado" << std::endl;
        }
    }
}

void Menu::checkMouseClick2() {
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    sf::Vector2f mousePosCoords = window->mapPixelToCoords(mousePos);
    if (back.getGlobalBounds().contains(mousePosCoords) && a_options){
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            a_back = true;
            std::cout << "Back presionado"<< std::endl;
        }
    }
}


void Menu::dibujarFondo() {
    window->draw(backgroundImage);
    window->draw(play);
    window->draw(options);
    window->draw(back);
}

bool Menu::getDelete() {
    return deleteSprites;
}