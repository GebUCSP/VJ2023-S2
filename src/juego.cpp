#include "../header/juego.h"
#include "../header/jugador.h"

Juego::Juego(): mWindow(sf::VideoMode(1000,650),"SFML"), menu(&mWindow){
    player = new Jugador("YO",100,100,10);
    enemigo = new Enemigo("NEYLIZ",100,100,10,1,2);

    mWindow.setFramerateLimit(10);

    if(!background.loadFromFile("../../resource/fondoo.png")){
        std::cerr << "Error al cargar texturas";
    }
    if(!cuerdas.loadFromFile("../../resource/cuerdas.png")){
        std::cerr << "Error al cargar texturas";
    }
    s_background.setTexture(background);
    s_cuerdas.setTexture(cuerdas);

    //Set del fondo
    sf::Vector2u sizeW = mWindow.getSize();
    s_background.setScale(static_cast<float> (sizeW.x) / s_background.getLocalBounds().width, static_cast<float> (sizeW.y) / s_background.getLocalBounds().height);
   // s_background.scale(sf::Vector2f(0,0));
    s_cuerdas.setScale(650, static_cast<float> (sizeW.y) / background.getSize().y);

    s_cuerdas.setPosition(0,250);

}

Juego::~Juego(){
    delete player;
    delete enemigo;
}

void Juego::run() {
    while (mWindow.isOpen()) {
        eventos();
        if (menu.a_play){
            //enemigo->timer(player);
        }

        render();
        if (!menu.a_play && !menu.a_exit){
            menu.checkMouseClick1();
        }

        if (menu.a_exit){
            mWindow.close();
        }
    }
}

void Juego::render() {
    mWindow.clear();
    if(!menu.getDelete()){
        menu.dibujarFondo();
    }else{
        mWindow.draw(s_background);
        mWindow.draw(enemigo->getSprite());
        mWindow.draw(player->getSprite());
        mWindow.draw(s_cuerdas);
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
    enemigo->inputs(evento.key.code,false);
    if(enemigo->getStates(0)){
        enemigo->attack(player);
    }
    enemigo->updateIu();

}


void Juego::datos() {
    std::cout << player->getVida() << std::endl;
    std::cout << player->getEnergia() << std::endl;
    std::cout << enemigo->getVida() << std::endl;
    std::cout << player->getEnergia() << std::endl;

}