#include <SFML/Graphics.hpp>

int main()
{
    // Create a video mode object (window size 800x600)
    sf::VideoMode videoMode(800, 600);
    // Create a render window
    sf::RenderWindow window(videoMode, "Move Rectangle with Arrow Keys");
    // Set the frame rate limit to make movement smoother
    window.setFramerateLimit(60);

    sf::RectangleShape rectangle1(sf::Vector2f(100.f, 50.f));

    sf::Vector2f zero(0.f, 0.f);

    sf::RectangleShape rectangle2(sf::Vector2f(100.f, 50.f));
    rectangle1.setFillColor(sf::Color::Green);

    rectangle1.setPosition(350.f, 275.f); // Center of the window
    rectangle1.setFillColor(sf::Color::Green);
    // Movement speed (pixels per frame)
    float movementSpeed = 5.0f;
    // Main game loop
    while (window.isOpen())
    {
        // Event polling (for handling window close, etc.)
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Real-time input for moving the rectangle
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            rectangle1.move(0.f, -movementSpeed); // Move up
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            rectangle1.move(0.f, movementSpeed); // Move down
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            rectangle1.move(-movementSpeed, 0.f); // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            rectangle1.move(movementSpeed, 0.f); // Move right
        }

        // Boundary checks to make the rectangle re-emerge on the other side
        sf::Vector2f position = rectangle1.getPosition();
        if (position.x + rectangle1.getSize().x < 0) // left overlfow
        {
            rectangle1.setPosition(window.getSize().x, position.y);
            rectangle2.setSize(zero);
        }
        else if (position.x > window.getSize().x) // right overflow
        {
            rectangle1.setPosition(-rectangle1.getSize().x, position.y);
            rectangle2.setSize(zero);
        }
        if (position.y + rectangle1.getSize().y < 0) // top overflow
        {
            rectangle1.setPosition(position.x, window.getSize().y);
            rectangle2.setSize(zero);
        }
        else if (position.y > window.getSize().y) // bottom overflow
        {
            rectangle1.setPosition(position.x, -rectangle1.getSize().y);
            rectangle2.setSize(zero);
        }

        // Clear the window
        window.clear();
        // Draw the rectangle
        window.draw(rectangle1);
        // Display the rendered frame
        window.display();
    }
    return 0;
}