#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using sf::CircleShape;
using sf::Color;
using sf::Event;
using sf::FloatRect;
using sf::Font;
using sf::Keyboard;
using sf::RectangleShape;
using sf::RenderWindow;
using sf::Text;
using sf::Vector2f;
using sf::VideoMode;

class Ball
{
    Vector2f velocity;
    CircleShape ball;

public:
    Ball(int size, int x, int y) : ball(size), velocity(2, 2)
    {
        ball.setFillColor(Color::White);
        ball.setPosition(x, y);
    }

    Vector2f getPosition()
    {
        return ball.getPosition();
    }

    float getRadius()
    {
        return ball.getRadius();
    }

    FloatRect getRect()
    {
        return ball.getGlobalBounds();
    }

    void bounceX()
    {
        velocity.x = -velocity.x;
    }

    void BounceDown()
    {
        velocity.y = abs(velocity.y);
    }

    void BounceUp()
    {
        velocity.y = -abs(velocity.y);
    }

    void move()
    {
        ball.move(velocity);
    }

    void draw(RenderWindow &window)
    {
        window.draw(ball);
    }

    void resetPosition(int x, int y)
    {
        ball.setPosition(x, y);
        velocity = Vector2f(abs(velocity.x), abs(velocity.y));
    }
};

class Paddle
{
    RectangleShape paddle;
    const unsigned int windowWidth;

public:
    Paddle(int width, int height, int x, int y, unsigned int windowWidth) : paddle(Vector2f(width, height)), windowWidth(windowWidth)
    {
        paddle.setFillColor(Color::Green);
        paddle.setPosition(x, y);
    }

    void moveLeft()
    {
        paddle.move(-3, 0);
        if (paddle.getPosition().x + paddle.getSize().x < 0)
        {
            paddle.setPosition(windowWidth, paddle.getPosition().y);
        }
    }

    void moveRight()
    {
        paddle.move(3, 0);
        if (paddle.getPosition().x > windowWidth)
        {
            paddle.setPosition(-paddle.getSize().x, paddle.getPosition().y);
        }
    }

    void draw(RenderWindow &window)
    {
        window.draw(paddle);
    }

    FloatRect getRect()
    {
        return paddle.getGlobalBounds();
    }

    void resetPosition(int x, int y)
    {
        paddle.setPosition(x, y);
    }
};

class PaddleBallGame
{
    const unsigned int windowWidth;
    const unsigned int windowHeight;
    const unsigned int paddleWidth;
    const unsigned int paddleHeight;
    const unsigned int ballR;
    const unsigned int ballX;
    const unsigned int ballY;
    RenderWindow window;
    Ball ball;
    Paddle paddle;
    Font font;
    Text gameOverText;
    bool isGameOver;

    inline bool collisionWithWalls()
    {
        const float x = ball.getPosition().x;
        return x <= 0 || x + ball.getRadius() * 2 >= windowWidth;
    }

    inline bool collisionWithTop()
    {
        return ball.getPosition().y <= 0;
    }

    inline bool collisionWithBottom()
    {
        return ball.getPosition().y + ball.getRadius() * 2 >= windowHeight;
    }

    inline bool leftKeyPressed() { return Keyboard::isKeyPressed(sf::Keyboard::Left); }
    inline bool rightKeyPressed() { return Keyboard::isKeyPressed(sf::Keyboard::Right); }

    void updateAndRender()
    {
        window.clear();
        paddle.draw(window);
        ball.draw(window);
        if (isGameOver)
        {
            window.draw(gameOverText);
        }
        window.display();
    }

    bool collissionWithPaddle()
    {
        FloatRect ballRect = ball.getRect();
        FloatRect paddleRect = paddle.getRect();
        return ballRect.intersects(paddleRect);
    }

    void gameOver()
    {
        isGameOver = true;
    }

    void resetGame()
    {
        ball.resetPosition(ballX, ballY);
        paddle.resetPosition(windowWidth / 2, windowHeight - paddleHeight);
        isGameOver = false;
    }

public:
    PaddleBallGame(
        const unsigned int windowWidth,
        const unsigned int windowHeight) : windowWidth(400),
                                           windowHeight(300),
                                           paddleWidth(80),
                                           paddleHeight(20),
                                           ballR(20),
                                           ballX(100),
                                           ballY(100),
                                           window(VideoMode(windowWidth, windowHeight), "Bouncing Ball"),
                                           ball(ballR, ballX, ballY),
                                           paddle(paddleWidth, paddleHeight, windowWidth / 2, windowHeight - paddleHeight, windowWidth),
                                           isGameOver(false)
    {
        window.setFramerateLimit(60);

        font.loadFromFile("Arial.ttf");
        gameOverText.setFont(font);
        gameOverText.setString("Game Over! Press Space to Continue");
        gameOverText.setCharacterSize(20);
        gameOverText.setFillColor(Color::Red);
        gameOverText.setPosition(windowWidth / 2 - gameOverText.getGlobalBounds().width / 2, windowHeight / 2);

        ball.draw(window);
        paddle.draw(window);
        window.display();
    }

    void play()
    {
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }

            if (isGameOver)
            {
                if (Keyboard::isKeyPressed(Keyboard::Space))
                {
                    resetGame();
                }
            }
            else
            {
                if (collisionWithWalls())
                    ball.bounceX();

                else if (collisionWithTop())
                    ball.BounceDown();

                else if (collissionWithPaddle())
                    ball.BounceUp();

                else if (collisionWithBottom())
                {
                    ball.BounceUp();
                    gameOver();
                }

                ball.move();

                if (leftKeyPressed())
                    paddle.moveLeft();

                if (rightKeyPressed())
                    paddle.moveRight();
            }

            updateAndRender();
        }
    }
};

int main()
{
    PaddleBallGame game(400, 300);
    game.play();
    return 0;
}
