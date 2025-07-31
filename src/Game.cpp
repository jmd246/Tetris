#include	"Game.hpp"

Game::Game()
{
    window  = sf::RenderWindow(sf::VideoMode({ 1200, 800 }), "Tetris!");

	active = TetrominoFactory::getInstance().randomTetromino();

}

void Game::play()
{

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (!active.has_value()) return;


        // === Gravity Logic ===
        if (fallTimer.getElapsedTime().asSeconds() >= fallDelay) {

            if (board.canMove(active.value(), {0, dy})) {
                active.value().position.y += dy;

            }
            else   if (active.value().position.y != 0) {
                board.lockTetromino(active.value());
                std::cout << active.value().position.x << "   " << active.value().position.y << std::endl;
                active = TetrominoFactory::getInstance().randomTetromino(); // Next piece

            }
            else {
                board.reset();
            }


            fallTimer.restart();
        }
        draw();
        
        // === Render ===
        /*
        window.clear();
        board.draw(window, blockSize);
        active.value().draw(window, blockSize); // draw active piece above board
        window.display();
        */
    }
}

void Game::draw()
{
    // === Render ===
    window.clear();
    board.draw(window, blockSize);
    active.value().draw(window, blockSize); // draw active piece above board
    window.display();
}
void Game::handleInput(const sf::Event& event) {}
void Game::spawnNewPiece()
{
	
}

void Game::lockPiece()
{

}
