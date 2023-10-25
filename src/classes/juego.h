#ifndef CMAKESFMLPROJECT_JUEGO_H
#define CMAKESFMLPROJECT_JUEGO_H

#include "boxer.h"
#include "enemy.h"
#include <iostream>

class Game
{
public:
    Game() :
            mWindow(VideoMode(640, 480), "SFML Application"),
            jugador("Gabriel", 100, 100, 10),
            enemigo(&jugador,"Neymi",100,100, 10, 10)
    {}

    void run()
    {
        while (mWindow.isOpen())
        {
            enemigo.timer();
            processEvents();
            update();
            render();
        }
    }

    void handlePlayerInput(Keyboard::Key key, bool isPressed)
    {
        //ACCIONES MANTENIBLES
        if (key == Keyboard::K)
        {
            jugador.block = isPressed;
        }

        if (key == Keyboard::A)
        {
            cout << "Ubicacion es izquierda" << endl;
            jugador.izq = isPressed;
        }
        else if (key == Keyboard::D)
        {
            cout << "Ubicacion es derecha" << endl;
            jugador.der = isPressed;
        }
        else if (key == Keyboard::S)
        {
            cout << "Ubicacion es atras" << endl;
            jugador.back = isPressed;
        }

        //ATTACK
        if (isPressed) {
            if (key == Keyboard::J) {
                /*
                if (jugador.der && jugador.block)
                {
                    cout << "Golpe Derecha con bloqueo" << endl;
                }
                else if (jugador.izq && jugador.block)
                {
                    cout << "Golpe Izquierda con bloqueo" << endl;
                }
                 */
                if (jugador.der) {
                    cout << "Atacando der" << endl;
                } else if (jugador.back) {
                    cout << "Atacando atras" << endl;
                } else if (jugador.izq) {
                    cout << "Atacando izq" << endl;
                } else {
                    cout << "Atacando" << endl;
                }
            }

            //jugador.block
            if (key == Keyboard::K) {
                if (jugador.der) {
                    cout << "Bloqueando der" << endl;
                } else if (jugador.izq) {
                    cout << "Bloqueando izq" << endl;
                } else if (jugador.back) {
                    cout << "Parry !!" << endl;
                } else {
                    cout << "Bloqueando" << endl;
                }
            }
            //DODGE
            if (key == Keyboard::L) {
                /*
                if (jugador.der && jugador.block)
                {
                    cout << "Esquivando bloqueando jugador.der" << endl;
                }
                else if (jugador.izq && jugador.block)
                {
                    cout << "Esquivando bloqueando jugador.izq" << endl;
                }
                 */
                if (jugador.back) {
                    cout << "Esquivando atras" << endl;
                } else if (jugador.der) {
                    cout << "Esquivando der" << endl;
                } else if (jugador.izq) {
                    cout << "Esquivando izq" << endl;
                }
            }
        }


        cout << "Vida: " << jugador.getVida() << endl;
        cout << "Energia: " << jugador.getEnergia() << endl;
        cout << "isPressed: " << isPressed << endl;
        cout << endl;



        //cout << "Izquierda: " << jugador.izq << " Derecha: " << jugador.der << " Arriba: " << up << " Atras: " << jugador.back << endl;
    }

    void processEvents()
    {
        Event event;
        while (mWindow.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::KeyPressed:
                    handlePlayerInput(event.key.code, true);
                    break;
                case Event::KeyReleased:
                    handlePlayerInput(event.key.code, false);
                    break;
                case Event::Closed:
                    mWindow.close();
                    break;
                default:
                    break;
            }
        }
    }

    void update() {};

    void render()
    {
        mWindow.clear();
        //mWindow.draw(mPlayer);
        mWindow.display();
    };

private:
    RenderWindow mWindow;
    CircleShape mPlayer;


    Boxeador jugador;
    Bot enemigo;
};


#endif //CMAKESFMLPROJECT_BOXER_H
