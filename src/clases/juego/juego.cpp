#include "juego.h"

void Juego::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::K)
    {
        jugador.states[1] = isPressed;
    }

    if (key == sf::Keyboard::A)
    {
        std::cout << "Ubicacion es izquierda" << std::endl;
        jugador.directions[3] = isPressed;
    }
    else if (key == sf::Keyboard::D)
    {
        std::cout << "Ubicacion es derecha" << std::endl;
        jugador.directions[1] = isPressed;
    }
    else if (key == sf::Keyboard::S)
    {
        std::cout << "Ubicacion es atras" << std::endl;
        jugador.directions[2] = isPressed;
    }

    //ATTACK
    if (isPressed) {
        if (key == sf::Keyboard::J) {
            /*
            if (jugador.directions[1] && jugador.states[1])
            {
                std::cout << "Golpe Derecha con bloqueo" << std::endl;
            }
            else if (jugador.directions[3] && jugador.states[1])
            {
                std::cout << "Golpe Izquierda con bloqueo" << std::endl;
            }
             */
            if (jugador.directions[1]) {
                std::cout << "Atacando der" << std::endl;
            } else if (jugador.directions[2]) {
                std::cout << "Atacando atras" << std::endl;
            } else if (jugador.directions[3]) {
                std::cout << "Atacando izq" << std::endl;
            } else {
                std::cout << "Atacando" << std::endl;
            }
        }

        //jugador.states[1]
        if (key == sf::Keyboard::K) {
            if (jugador.directions[1]) {
                std::cout << "Bloqueando der" << std::endl;
            } else if (jugador.directions[3]) {
                std::cout << "Bloqueando izq" << std::endl;
            } else if (jugador.directions[2]) {
                std::cout << "Parry !!" << std::endl;
            } else {
                std::cout << "Bloqueando" << std::endl;
            }
        }
        //DODGE
        if (key == sf::Keyboard::L) {
            /*
            if (jugador.directions[1] && jugador.states[1])
            {
                std::cout << "Esquivando bloqueando jugador.directions[1]" << std::endl;
            }
            else if (jugador.directions[3] && jugador.states[1])
            {
                std::cout << "Esquivando bloqueando jugador.directions[3]" << std::endl;
            }
             */
            if (jugador.directions[2]) {
                std::cout << "Esquivando atras" << std::endl;
            } else if (jugador.directions[1]) {
                std::cout << "Esquivando der" << std::endl;
            } else if (jugador.directions[3]) {
                std::cout << "Esquivando izq" << std::endl;
            }
        }
    }


    std::cout << "Vida: " << jugador.vida << std::endl;
    std::cout << "Energia: " << jugador.energia << std::endl;
    std::cout << "isPressed: " << isPressed << std::endl;
    std::cout << std::endl;
}

void Juego::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
}

void Juego::update() {}

void Juego::render() {
    mWindow.clear();
    mWindow.display();
}

Juego::Juego(): mWindow(sf::VideoMode(640, 480), "SFML Application"),jugador("Gabriel", 100, 100, 10), enemigo(&jugador, "Neymi", 100, 100, 10, 10,1){}

void Juego::run()
{
    while (mWindow.isOpen())
    {
        enemigo.timer();
        processEvents();
        update();
        render();
    }
}
