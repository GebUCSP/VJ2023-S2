#include "../header/juego.h"

Juego::Juego(): mWindow(sf::VideoMode(1000,650),"SFML"), menu(&mWindow){
    mWindow.setFramerateLimit(10);

    player = new Jugador("YO",100,100,10,false);
    enemigo = new Enemigo("NEYLIZ",100,100,10,3,5,true);


    if(!background.loadFromFile("../../resource/fondoo.png")){
        std::cerr << "Error al cargar texturas";
    }
    if(!cuerdas.loadFromFile("../../resource/cuerdas.png")){
        std::cerr << "Error al cargar texturas";
    }

    if(!over.loadFromFile("../../resource/over.png")){
        std::cerr << "Error al cargar texturas";
    }
    if(!win.loadFromFile("../../resource/win.png")){
        std::cerr << "Error al cargar texturas";
    }



    sf::Vector2u sizeW = mWindow.getSize();

    s_background.setTexture(background);
    s_background.setScale(static_cast<float> (sizeW.x) / s_background.getLocalBounds().width, static_cast<float> (sizeW.y) / s_background.getLocalBounds().height);

    s_cuerdas.setTexture(cuerdas);
    s_cuerdas.setScale(650, static_cast<float> (sizeW.y) / background.getSize().y);
    s_cuerdas.setPosition(0,250);

    s_win.setTexture(win);
    s_win.scale(1.6f,1.6f);

    s_gameOver.setTexture(over);
    s_gameOver.scale(3.6f,4.0f);

}

Juego::~Juego(){
    delete player;
    delete enemigo;
}

void Juego::run() {
    while (mWindow.isOpen()) {
        eventos();
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

    if(player->getVida() <= 0){
        mWindow.draw(s_gameOver);
    }else if (enemigo->getVida() <= 0){
        mWindow.draw(s_win);
    }


    mWindow.display();
}

void Juego::eventos() {
    sf::Event evento{};

    while(mWindow.pollEvent(evento)){
        switch (evento.type) {
            case sf::Event::KeyPressed:
                player->inputs(evento.key.code, true);
                if(player->getStates(0))
                    player->attack(enemigo);

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

    enemigo->inputs(evento.key.code,false);

    if(enemigo->getStates(0))
        enemigo->attack(player);

}