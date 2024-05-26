#ifndef LABEL_HPP_
#define LABEL_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

class Label{
    private:
        sf::Text text;

    public:
        Label(int x, int y, std::string label
            , sf::Font& font, unsigned int charSize = 24){
                text.setString(label);

                //float textWidth = text.getGlobalBounds().width;
                //float textHeight = text.getGlobalBounds().height;
                //float xPos = x + (width - textWidth) / 2;
                //float yPos = y + (height - textHeight) / 2 - text.getCharacterSize() / 4;  // Adjust for text baseline
                //text.setPosition(xPos, yPos);

                text.setFont(font);
                text.setPosition(x, y);
                text.setCharacterSize(charSize);
                text.setFillColor(sf::Color::White);
            }

        void draw(sf::RenderWindow& window){
            window.draw(text);
        }

        void set_text(std::string text){
            this->text.setString(text);
        }

        void set_pos(int x, int y){
            this->text.setPosition(x, y);
        }

};

#endif