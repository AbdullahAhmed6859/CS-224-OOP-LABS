#include <SFML/Graphics.hpp>
int main()
{
    const short int height = 400;
    const short int width = 300;
    const short int radius = 80;
    const short int outlineThickness = 20;
    const sf::Vector2f postDimensions(30, 200);
    sf::Font Arial;
    Arial.loadFromFile("Arial.ttf");

    // create window
    sf::RenderWindow window(sf::VideoMode(width, height), "STOP Sign");

    // create post
    sf::RectangleShape post(postDimensions);
    post.setFillColor(sf::Color::Black);
    post.setPosition((width - postDimensions.x) / 2, height - postDimensions.y);

    // create sign
    sf::CircleShape sign(radius);
    sign.setFillColor(sf::Color::White);
    sign.setOutlineColor(sf::Color::Red);
    sign.setOutlineThickness(outlineThickness);
    sign.setPosition(width / 2 - radius, height - postDimensions.y - 2 * radius - outlineThickness);

    // sign text
    sf::Text stopText("STOP", Arial, 50);
    stopText.setFillColor(sf::Color::Black);

    const float stopTextWidth = stopText.getLocalBounds().width;
    const float stopTextHeight = stopText.getLocalBounds().height;
    const float stopTextOffsetY = stopText.getLocalBounds().top;

    stopText.setPosition(
        (width - stopTextWidth) / 2,
        height - postDimensions.y - radius - outlineThickness - stopTextHeight / 2 - stopTextOffsetY);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Cyan);
        window.draw(sign); // Draw the circle on the window
        window.draw(post);
        window.draw(stopText);
        window.display(); // Display the contents
    }
    return 0;
}
