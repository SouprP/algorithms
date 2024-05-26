#ifndef BUTTOH_HPP_
#define BUTTON_HPP_

#include <SFML/Graphics.hpp>
#include <functional>

class Button{
    private:
        sf::RectangleShape shape;
        sf::Text text;
        std::function<void(sf::RenderWindow&)> callback;

    public:
        Button(const sf::Vector2f& position, const sf::Vector2f& size, const sf::String& text, sf::Font& font) {
        //Button(int x, int y, const sf::Vector2f& size, const sf::String& text, sf::Font& font) {
            // Initialize the shape of the button
            shape.setPosition(position);
            shape.setSize(size);
            shape.setFillColor(sf::Color::White);

            // Initialize the text of the button
            this->text.setFont(font);
            this->text.setString(text);
            this->text.setCharacterSize(24);
            this->text.setFillColor(sf::Color::Black);

            // Center the text within the button
            sf::FloatRect textRect = this->text.getLocalBounds();
            this->text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
            this->text.setPosition(position + size / 2.0f);
        }

        void draw(sf::RenderWindow& window) {
            //shape.setFillColor(sf::Color::White);
            window.draw(shape);
            window.draw(text);
        }

        void setCallback(std::function<void(sf::RenderWindow&)> callback) {
            this->callback = callback;
        }

        void handleEvent(const sf::Event& event, sf::RenderWindow& window) {
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                    if (shape.getGlobalBounds().contains(mousePos)) {
                        if (callback) {
                            shape.setFillColor(sf::Color::Red);
                            callback(window);
                        }
                    }
                }
            }
        }
};

#endif