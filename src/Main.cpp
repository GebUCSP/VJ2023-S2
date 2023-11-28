//#include "clases/juego/juego.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


using namespace std;
using namespace sf;

void animacion(sf::Sprite &image, sf::Texture &textura) {

    sf::IntRect rectangulo_imagen = image.getTextureRect(); // se obtiene la info sobre las coordenadas de la imagen actual
    rectangulo_imagen.left += 256;  // se incrementa el ancho de cada imagen a la actual

    if (rectangulo_imagen.left + rectangulo_imagen.width > textura.getSize().x) { // verificamos si el siguiente cuadro excede al ancho total
        rectangulo_imagen.left = 0; // si cumple, se restablece a la posicion inicial (0)
        cout <<"hola" << endl;
    }

    image.setTextureRect(rectangulo_imagen);
}


int main()
{
    RenderWindow window(VideoMode(1920,1080), "prueba");
    window.setFramerateLimit(20);

    sf::Texture textura;
    sf::Sprite image;
    if (!textura.loadFromFile("../../src/boxing.png"))
        std::cout << "error" << std::endl;


    image.setTexture(textura);
    image.setTextureRect(IntRect(0,0, 256, 256));
    //image.setScale(static_cast<float> (1792) / textura.getSize().x, static_cast<float> (452) / textura.getSize().y);
    //image.scale(sf::Vector2f(4,4));
    image.setScale(4,4);

    // Musica
    sf::Music musica;
    musica.openFromFile("../../src/sara.ogg");
    musica.setVolume(5.0f);
    musica.play();

    // Efectos de sonido
    sf::SoundBuffer sonido;
    sonido.loadFromFile("../../src/punch.ogg");
    sf::Sound s;
    s.setBuffer(sonido);

    //sf:Vector2f velocity;
    sf::Clock clock;
    float dt = 0.06;

    bool proceso = false;
    int do_an = 7;

    while (window.isOpen() && !Keyboard::isKeyPressed(Keyboard::Escape)) {
        sf::Event evento;

        while (window.pollEvent(evento)) {

            dt = clock.restart().asSeconds();
            std::cout << dt << std::endl;



            if (evento.type == Event:: Closed)
                window.close();
        }


        if (do_an) {
            animacion(image, textura);
            do_an --;
        }
        if (do_an == 0) {
            proceso = false;
        }




        if (Keyboard::isKeyPressed(Keyboard::J) && !proceso) {
            proceso = true;
            do_an = 7.0;
            s.play();
        }

        //sf::Time time = clock.getElapsedTime();
        //clock.restart().asSeconds();

        //image.move(sf::Vector2f(0,.1));
        window.clear(Color::White);
        window.draw(image);
        window.display();
    }


}
