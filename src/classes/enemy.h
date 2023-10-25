#ifndef CMAKESFMLPROJECT_ENEMY_H
#define CMAKESFMLPROJECT_ENEMY_H

#include <cstdlib>
#include <ctime>
#include "boxer.h"



class Bot: public Boxeador{
public:
    Bot(string _nombre, int _vida, int _energia, int _fataque = 5.0, int _fbloque = 5.0, int _fesquive = 5.0): fataque{_fataque},fbloqueo{_fbloque}, fesquive{_fesquive},Boxeador(_nombre,_vida,_energia){
        std::srand(static_cast<unsigned>(std::time(nullptr)));

        clock.restart();
    }

    bool getRange(){
        return range;
    }

    void random(){
        int random = std::rand() % 3;
        cout << random << endl;
    }

    void timer(){
        ultimaAccion = clock.getElapsedTime().asSeconds();
        if(ultimaAccion > fataque){
            random();
            clock.restart();
        }
    }

private:
    bool range = true;
    int fataque, fbloqueo, fesquive;
    int ultimaAccion = 0.0;
    Clock clock;
};


#endif //CMAKESFMLPROJECT_ENEMY_H
