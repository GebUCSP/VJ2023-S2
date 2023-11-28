#include "../header/juego.h"
#include "../header/jugador.h"

Juego::Juego(): mWindow(sf::VideoMode(1000,650),"SFML"), menu(&mWindow){
    player = new Jugador("Yo",100,100,10);
    enemigo = new Enemigo("Arnold",100,100,10,1,4);
}

Juego::~Juego(){
    delete player;
    delete enemigo;
}

void Juego::run() {
    while (mWindow.isOpen()) {
        eventos();
        render();

        if (menu.a_play){
            enemigo->timer(player);
        }
        
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
    if(!menu.getDelete()){
        menu.dibujarFondo();
    }else{
        mWindow.draw(player->getSprite());
        mWindow.draw(enemigo->getSprite());
        player->iu(&mWindow);
        enemigo->iu(&mWindow);
    }
    mWindow.display();
}

void Juego::eventos() {
    sf::Event evento{};
    while(mWindow.pollEvent(evento)){
        switch (evento.type) {
            case sf::Event::KeyPressed:
                player->inputs(evento.key.code, true);
                if(player->getStates(0)){
                    player->attack(enemigo);
                }
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
    player->updateIu();
    enemigo->updateIu();

}


void Juego::datos() {
    std::cout << player->getVida() << std::endl;
    std::cout << player->getEnergia() << std::endl;
    std::cout << enemigo->getVida() << std::endl;
    std::cout << player->getEnergia() << std::endl;

}