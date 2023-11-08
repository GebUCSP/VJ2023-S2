#include "clases/juego/juego.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    //Se crea la clase juego
    Juego juego;

    //Se inicia la funciona run la cual contiene el bucle principal
    juego.run();

    return 0;
}
