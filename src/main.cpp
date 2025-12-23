#include <iostream>
#include "headers/Game.h"

int main()
{
    try
    {
        Game game;
        game.run();
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}