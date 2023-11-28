#include <SFML/Graphics.hpp>
#include "../header/juego.h"

bool operator==(const std::vector<bool> &v1, const std::vector<bool> &v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    if (std::all_of(v1.begin(), v1.end(), [](bool val) { return !val; }) && std::all_of(v2.begin(), v2.end(), [](bool val) { return !val; })) {
        return false;
    }

    return std::equal(v1.begin(), v1.end(), v2.begin());
}

int main(){

    Juego Game;

    Game.run();

    return 0;
}