#ifndef TEXTBOX_HPP_
#define TEXTBOX_HPP_

#include <SFML/Graphics.hpp>
#include <string>

class TextBox {
public:
    TextBox(int x, int y, int width, int height, sf::Font& font, unsigned int charSize = 24)    : isSelected(false), showCursor(true) {
        box.setPosition(x, y);
        box.setSize(sf::Vector2f(width, height));
        box.setFillColor(sf::Color::White);
        box.setOutlineColor(sf::Color::Black);
        box.setOutlineThickness(2);

        text.setFont(font);
        text.setCharacterSize(charSize);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + 5, y + (height - charSize) / 2);  // Center text vertically
    }

    void handleEvent(const sf::Event& event){
        if (event.type == sf::Event::MouseButtonPressed) {
            if (box.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                isSelected = true;
            } else {
                isSelected = false;
            }
        }

        if (isSelected) {
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    if (event.text.unicode == 8) { // Backspace
                        if (!inputText.empty()) {
                            inputText.pop_back();
                        }
                    } else if (event.text.unicode == 13) { // Enter
                        // Handle enter key if needed
                    } else {
                        if(event.text.unicode >= 48 
                            && event.text.unicode <= 57)
                            inputText += static_cast<char>(event.text.unicode);
                    }
                }
            }
        }

        text.setString(inputText);
        centerText();
        updateCursor();
    }

    void draw(sf::RenderWindow& window){
        window.draw(box);
        window.draw(text);

        if (isSelected && showCursor) {
            sf::RectangleShape cursor(sf::Vector2f(2, text.getCharacterSize()));
            cursor.setFillColor(sf::Color::Black);
            cursor.setPosition(text.getPosition().x + text.getGlobalBounds().width + 2, text.getPosition().y);
            window.draw(cursor);
        }
    }
    void setText(const std::string& text){
        inputText = text;
        this->text.setString(inputText);
    }
    std::string getText() const{
        return inputText;
    }

private:
    sf::RectangleShape box;
    sf::Text text;
    std::string inputText;
    bool isSelected;
    sf::Clock cursorClock;
    bool showCursor;

    void updateCursor(){
        if (cursorClock.getElapsedTime().asSeconds() >= 0.5f) {
            showCursor = !showCursor;
            cursorClock.restart();
        }
    }

    void centerText() {
        float boxWidth = box.getSize().x;
        float textWidth = text.getGlobalBounds().width;
        float textHeight = text.getGlobalBounds().height;
        float xPos = box.getPosition().x + (boxWidth - textWidth) / 2;
        float yPos = box.getPosition().y + (box.getSize().y - textHeight) / 2 - text.getCharacterSize() / 4;  // Adjust for text baseline
        text.setPosition(xPos, yPos);
    }
};

#endif
