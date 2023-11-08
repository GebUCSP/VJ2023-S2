#include "juego.h"

//detecta los controles del jugador
void Juego::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {

    //estos son los controles mantenibles, para crear combinaciones de movimientos
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

    //Botones presionables y no mantenibles
    //ATTACK
    if (isPressed && !jugador.getRange()) {
        if (key == sf::Keyboard::J) {
            if (jugador.directions[1]) {
                std::cout << "Atacando der" << std::endl;
            } else if (jugador.directions[2]) {
                std::cout << "Atacando atras" << std::endl;
            } else if (jugador.directions[3]) {
                std::cout << "Atacando izq" << std::endl;
            } else {
                std::cout << "Atacando" << std::endl;
            }
            jugador.changeRange();
            jugador.stun();
        }
        //BLOQUEANDO
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

    // Monitoreo en consola (Hasta que se dibuje el videojuego en la pantalla)
    std::cout << "Vida: " << jugador.vida << std::endl;
    std::cout << "Energia: " << jugador.energia << std::endl;
    std::cout << "isPressed: " << isPressed << std::endl;
    std::cout << std::endl;
}

//Bucle procesador de eventos
void Juego::processEvents() {
    sf::Event event;
    //Bucle de events detectados
    while (mWindow.pollEvent(event))
    {
        //comparador de tipos de eventos
        switch (event.type)
        {
                //evento boton presionado
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
                //evento boton levantado
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
                //evento ventana cerrada
            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
}

//Actualizacion de pantalla
void Juego::update() {}

//renderizado en pantalla
void Juego::render() {
    mWindow.clear();

    menu.dibujarFondo();

    mWindow.display();
}

//contructor de clase Juego que inicia la pantalla el jugador y el enemigo
Juego::Juego(): mWindow(sf::VideoMode(1000, 650), "SFML Application"),jugador("Gabriel", 100, 100, 10), enemigo(&jugador, "Neymi", 100, 100, 10,1),
                menu(&mWindow){}

//bucle principal del juego encargado de todos los procesos
void Juego::run()
{
    while (mWindow.isOpen())
    {
        jugador.stun();
        enemigo.timer();
        processEvents();
        update();
        render();
    }
}
