#ifndef CMAKESFMLPROJECT_ENEMY_H
#define CMAKESFMLPROJECT_ENEMY_H

#include "boxer.h"

class Bot: public Boxeador{
public:
    Bot(string _nombre, int _vida, int _energia): Boxeador(_nombre,_vida,_energia){}
    bool getRange(){
        return range;
    }
private:
    bool range = true;
};


#endif //CMAKESFMLPROJECT_ENEMY_H
