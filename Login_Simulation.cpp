#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 300), "Login Screen");

    sf::Font font;
    if (!font.loadFromFile("Assets/Font/Noto_Serif_Khitan_Small_Script/NotoSerifKhitanSmallScript-Regular.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
        return -1;
    }

    sf::Text usernameText("Username:", font, 20);
    usernameText.setPosition(30, 50);

    sf::Text passwordText("Password:", font, 20);
    passwordText.setPosition(30, 100);

    sf::RectangleShape usernameBox(sf::Vector2f(200, 30));
    usernameBox.setPosition(150, 50);
    usernameBox.setFillColor(sf::Color::White);
    usernameBox.setOutlineThickness(2);
    usernameBox.setOutlineColor(sf::Color::Black);

    sf::RectangleShape passwordBox(sf::Vector2f(200, 30));
    passwordBox.setPosition(150, 100);
    passwordBox.setFillColor(sf::Color::White);
    passwordBox.setOutlineThickness(2);
    passwordBox.setOutlineColor(sf::Color::Black);

    sf::Text loginText("Login", font, 20);
    loginText.setPosition(180, 200);

    sf::Text usernameInputText("", font, 20);
    usernameInputText.setPosition(160, 55);
    usernameInputText.setFillColor(sf::Color::Black); // Set the text color to black

    sf::Text passwordInputText("", font, 20);
    passwordInputText.setPosition(160, 105);
    passwordInputText.setFillColor(sf::Color::Black); // Set the text color to black

    std::string usernameInput = "";
    std::string passwordInput = "";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode == 8) // Check for the backspace character explicitly
                {
                    if (usernameInput.size() > 0 && usernameBox.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                    {
                        usernameInput.erase(usernameInput.end() - 1); // Remove the last character from the input string
                        usernameInputText.setString(usernameInput); // Update the input text object with the new input string
                    }

                    if (passwordInput.size() > 0 && passwordBox.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                    {
                        passwordInput.erase(passwordInput.end() - 1); // Remove the last character from the input string
                        passwordInputText.setString(std::string(passwordInput.size(), '*')); // Update the input text object with a string of asterisks
                    }
                }
                else if (event.text.unicode >= 32 && event.text.unicode < 127) // Check for printable ASCII characters
                {
                    if (usernameBox.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                    {
                        usernameInput += static_cast<char>(event.text.unicode);
                        usernameInputText.setString(usernameInput); // Update the input text object with the new input string
                    }

                    if (passwordBox.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                    {
                        passwordInput += static_cast<char>(event.text.unicode);
                        passwordInputText.setString(std::string(passwordInput.size(), '*')); // Update the input text object with a string of asterisks
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Return)
                {
                    if (usernameInput == "username" && passwordInput == "password")
                    {
                        std::cout << "Login successful" << std::endl;
                    }
                    else
                    {
                        std::cout << "Incorrect username or password" << std::endl;
                    }
                }
            }
        }

        usernameBox.setOutlineColor(sf::Color::Black);
        passwordBox.setOutlineColor(sf::Color::Black);

        if (usernameBox.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        {
            usernameBox.setOutlineColor(sf::Color::Blue);
        }

        if (passwordBox.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        {
            passwordBox.setOutlineColor(sf::Color::Blue);
        }

        loginText.setFillColor(sf::Color::Black);

        if (loginText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        {
            loginText.setFillColor(sf::Color::Blue);
        }

        window.clear(sf::Color::White);
        window.draw(usernameText);
        window.draw(passwordText);
        window.draw(usernameBox);
        window.draw(passwordBox);

        window.draw(usernameInputText);
        window.draw(passwordInputText);

        window.draw(loginText);
        window.display();
    }
    return 0;
}
