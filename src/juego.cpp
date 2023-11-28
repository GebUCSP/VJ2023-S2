#include "../header/juego.h"
#include "../header/jugador.h"

Juego::Juego(): mWindow(sf::VideoMode(1000,650),"SFML"), menu(&mWindow){
    player = new Jugador("string",100,100,10);
    enemigo = new Enemigo("string",100,100,10);
}

Juego::~Juego(){
    delete player;
    delete enemigo;
}

void Juego::run() {
    while (mWindow.isOpen()) {
        eventos();
        enemigo->timer(player);
        render();
        if (!menu.a_play && !menu.a_options){
            menu.checkMouseClick1();
        }

        if (menu.a_options){
            menu.checkMouseClick2();
            if (menu.a_back){
                menu.a_options = false;
            }
        }
    }
}

void Juego::render() {
    mWindow.clear();
    menu.dibujarFondo();
    mWindow.display();
}

void Juego::eventos() {
    sf::Event evento{};
    while(mWindow.pollEvent(evento)){
        switch (evento.type) {
            case sf::Event::KeyPressed:
                player->inputs(evento.key.code, true);
                player->print();
                datos();
                break;
            case sf::Event::KeyReleased:
                player->inputs(evento.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
}

void Juego::datos() {
    std::cout << player->getVida() << std::endl;
    std::cout << player->getEnergia() << std::endl;
    std::cout << enemigo->getVida() << std::endl;
    std::cout << player->getEnergia() << std::endl;

}