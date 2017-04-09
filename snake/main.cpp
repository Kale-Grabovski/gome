#include <memory>
#include "Game.h"

int main(int argc, char* argv[]) {
    std::shared_ptr<Game> game(new Game());
    game->Setup();

    while (!game->GetWindow()->IsDone()) {
        game->HandleInput();
        game->Update();
        game->Render();
        game->RestartClock();
    }

    return 0;
}
