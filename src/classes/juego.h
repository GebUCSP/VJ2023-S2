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
            jugador("Gabriel", 100, 100),
            enemigo("Neymi",100,100)
    {}

    void run()
    {
        while (mWindow.isOpen())
        {
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
            block = isPressed;
        }

        if (key == Keyboard::A)
        {
            cout << "Ubicacion es izquierda" << endl;
            izq = isPressed;
        }
        else if (key == Keyboard::D)
        {
            cout << "Ubicacion es derecha" << endl;
            der = isPressed;
        }
        else if (key == Keyboard::S)
        {
            cout << "Ubicacion es atras" << endl;
            back = isPressed;
        }

        //ATTACK
        if (isPressed) {
            if (key == Keyboard::J) {
                if (enemigo.getRange()) {
                    jugador.setVida(jugador.getVida() - 10);
                } else {
                    enemigo.setVida(enemigo.getVida() - 10);
                }
                /*
                if (der && block)
                {
                    cout << "Golpe Derecha con bloqueo" << endl;
                }
                else if (izq && block)
                {
                    cout << "Golpe Izquierda con bloqueo" << endl;
                }
                 */
                if (der) {
                    cout << "Atacando der" << endl;
                } else if (back) {
                    cout << "Atacando atras" << endl;
                } else if (izq) {
                    cout << "Atacando izq" << endl;
                } else {
                    cout << "Atacando" << endl;
                }
            }

            //BLOCK
            if (key == Keyboard::K) {
                if (der) {
                    cout << "Bloqueando der" << endl;
                } else if (izq) {
                    cout << "Bloqueando izq" << endl;
                } else if (back) {
                    cout << "Parry !!" << endl;
                } else {
                    cout << "Bloqueando" << endl;
                }
            }
            //DODGE
            if (key == Keyboard::L) {
                /*
                if (der && block)
                {
                    cout << "Esquivando bloqueando der" << endl;
                }
                else if (izq && block)
                {
                    cout << "Esquivando bloqueando izq" << endl;
                }
                 */
                if (back) {
                    cout << "Esquivando atras" << endl;
                } else if (der) {
                    cout << "Esquivando der" << endl;
                } else if (izq) {
                    cout << "Esquivando izq" << endl;
                }
            }
        }
        cout << "Vida: " << jugador.getVida() << endl;
        cout << "Energia: " << jugador.getEnergia() << endl;
        cout << "Vida: " << jugador.getStatus() << endl;
        cout << "isPressed: " << isPressed << endl;
        cout << endl;

        //cout << "Izquierda: " << izq << " Derecha: " << der << " Arriba: " << up << " Atras: " << back << endl;
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
    bool block = false;
    bool attack = false;
    bool dodge = false;
    bool izq=false, der=false, up=false, back=false;
    Boxeador jugador;
    Bot enemigo;
};


#endif //CMAKESFMLPROJECT_BOXER_H
