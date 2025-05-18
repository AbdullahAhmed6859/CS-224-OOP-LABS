#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>

// Forward declarations
class GameObject;
class Ball;
class Paddle;

// Constants
namespace GameConfig {
constexpr unsigned int WINDOW_WIDTH = 800;
constexpr unsigned int WINDOW_HEIGHT = 600;
constexpr unsigned int PADDLE_WIDTH = 80;
constexpr unsigned int PADDLE_HEIGHT = 20;
constexpr unsigned int BALL_RADIUS = 2;
constexpr float BALL_SPEED = 3;
constexpr float PADDLE_SPEED = 6;
const sf::Color BALL_COLOR = sf::Color::White;
const sf::Color PADDLE_COLOR = sf::Color::Green;
const std::string WINDOW_TITLE = "Paddle Ball Game";
} // namespace GameConfig

// Base class for game objects
class GameObject {
protected:
    sf::Vector2f position;
    sf::Vector2f velocity;

public:
    virtual ~GameObject() = default;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow &window) const = 0;
    virtual sf::FloatRect getBounds() const = 0;

    void setPosition(const sf::Vector2f &pos) {
        position = pos;
    }
    const sf::Vector2f &getPosition() const {
        return position;
    }
    void setVelocity(const sf::Vector2f &vel) {
        velocity = vel;
    }
    const sf::Vector2f &getVelocity() const {
        return velocity;
    }
};

class Ball : public GameObject {
private:
    sf::CircleShape shape;
    float radius;

public:
    explicit Ball(float radius) : radius(radius), shape(radius) {
        shape.setFillColor(GameConfig::BALL_COLOR);
        velocity = sf::Vector2f(GameConfig::BALL_SPEED, GameConfig::BALL_SPEED);
    }

    void update() override {
        position += velocity;
        shape.setPosition(position);
    }

    void draw(sf::RenderWindow &window) const override {
        window.draw(shape);
    }

    sf::FloatRect getBounds() const override {
        return shape.getGlobalBounds();
    }

    void reverseX() {
        velocity.x = -velocity.x;
    }
    void moveUp() {
        velocity.y = -abs(velocity.y);
    }
    void moveDown() {
        velocity.y = abs(velocity.y);
    }
};

class Paddle : public GameObject {
private:
    sf::RectangleShape shape;

public:
    Paddle(float width, float height) : shape(sf::Vector2f(width, height)) {
        shape.setFillColor(GameConfig::PADDLE_COLOR);
        velocity = sf::Vector2f(GameConfig::PADDLE_SPEED, 0);
    }

    void update() override {
        shape.setPosition(position);
    }

    void draw(sf::RenderWindow &window) const override {
        window.draw(shape);
    }

    sf::FloatRect getBounds() const override {
        return shape.getGlobalBounds();
    }

    void moveLeft() {
        if (position.x > 0) {
            position.x -= velocity.x;
        }
    }

    void moveRight() {
        if (position.x + shape.getSize().x < GameConfig::WINDOW_WIDTH) {
            position.x += velocity.x;
        }
    }
};

class GameState {
public:
    enum class State {
        Playing,
        GameOver,
        Paused
    };

private:
    State currentState;
    unsigned int score;

public:
    GameState() : currentState(State::Playing), score(0) {
    }

    void setState(State state) {
        currentState = state;
    }
    State getState() const {
        return currentState;
    }
    void incrementScore() {
        ++score;
    }
    unsigned int getScore() const {
        return score;
    }
    void reset() {
        score = 0;
        currentState = State::Playing;
    }
};

class Game {
private:
    sf::RenderWindow window;
    Ball ball;
    Paddle paddle;
    sf::Font font;
    sf::Text gameOverText;
    sf::Text scoreText;
    GameState gameState;

    void initializeText() {
        if (!font.loadFromFile("Arial.ttf")) {
            throw std::runtime_error("Could not load font!");
        }

        gameOverText.setFont(font);
        gameOverText.setString("Game Over! Press Space to Continue");
        gameOverText.setCharacterSize(24);
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setPosition(GameConfig::WINDOW_WIDTH / 2 - gameOverText.getGlobalBounds().width / 2,
                                 GameConfig::WINDOW_HEIGHT / 2);

        scoreText.setFont(font);
        scoreText.setCharacterSize(20);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(10, 10);
    }

    void handleInput() {
        if (gameState.getState() == GameState::State::Playing) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                paddle.moveLeft();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                paddle.moveRight();
        } else if (gameState.getState() == GameState::State::GameOver) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                resetGame();
        }
    }

    void updateGame() {
        if (gameState.getState() != GameState::State::Playing)
            return;

        ball.update();
        paddle.update();

        // Ball collision with walls
        if (ball.getPosition().x <= 0 || ball.getPosition().x + ball.getBounds().width >= GameConfig::WINDOW_WIDTH) {
            ball.reverseX();
        }

        // Ball collision with ceiling
        if (ball.getPosition().y <= 0)
            ball.moveDown();

        // Ball collision with paddle
        if (ball.getBounds().intersects(paddle.getBounds())) {
            ball.moveUp();
            gameState.incrementScore();
        }

        // Ball below paddle
        if (ball.getPosition().y + ball.getBounds().height >= GameConfig::WINDOW_HEIGHT) {
            gameState.setState(GameState::State::GameOver);
        }

        // Update score text
        scoreText.setString("Score: " + std::to_string(gameState.getScore()));
    }

    void render() {
        window.clear(sf::Color::Black);

        ball.draw(window);
        paddle.draw(window);
        window.draw(scoreText);

        if (gameState.getState() == GameState::State::GameOver) {
            window.draw(gameOverText);
        }

        window.display();
    }

    void resetGame() {
        ball.setPosition(sf::Vector2f(GameConfig::WINDOW_WIDTH / 2, GameConfig::WINDOW_HEIGHT / 2));
        paddle.setPosition(sf::Vector2f(GameConfig::WINDOW_WIDTH / 2 - GameConfig::PADDLE_WIDTH / 2,
                                        GameConfig::WINDOW_HEIGHT - GameConfig::PADDLE_HEIGHT * 2));
        gameState.reset();
    }

public:
    Game()
        : window(sf::VideoMode(GameConfig::WINDOW_WIDTH, GameConfig::WINDOW_HEIGHT), GameConfig::WINDOW_TITLE),
          ball(GameConfig::BALL_RADIUS), paddle(GameConfig::PADDLE_WIDTH, GameConfig::PADDLE_HEIGHT) {
        window.setFramerateLimit(60);
        initializeText();
        resetGame();
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            handleInput();
            updateGame();
            render();
        }
    }
};

int main() {
    try {
        Game game;
        game.run();

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}