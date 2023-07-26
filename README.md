# SFML-Findings
This repository will house all my findings in SFML as to make developing future GUI projects using SFML more efficient and faster.

# Files
- [A login simulation](Login_Simulation.cpp). [Description](#login-simulation)

. as

. as

. aa

. aa
 
. aa

. aa

. aa

. aa

.aa 

.aa 

# Login Simulation

This code is a simple login screen created using the SFML (Simple and Fast Multimedia Library) graphics library. The login screen contains two input fields for username and password, as well as a login button. When the user enters their username and password and presses the login button or the enter key, the program checks if the entered username and password are correct, and displays a message accordingly.

<details>

<summary>In Details</summary>

The program first creates a window using sf::RenderWindow, sets its size to 400x300 and sets its title to "Login Screen". It also loads a font from a file using sf::Font, and creates several sf::Text objects to display text on the screen.

Two sf::RectangleShape objects are created to represent the input fields for username and password. These objects are positioned and sized appropriately, and their color and outline are set using setFillColor() and setOutlineColor() methods.

The program enters a loop where it waits for user input using window.pollEvent(). If the user closes the window, the program exits the loop and terminates. If the user types a printable ASCII character in one of the input fields, that character is appended to the corresponding input string, and the sf::Text object representing that input field is updated with the new input string.

If the user presses the backspace key, the last character from the corresponding input string is removed, and the sf::Text object representing that input field is updated with the new input string.

If the user presses the enter key, the program checks if the entered username and password are correct (in this case, the correct values are hard-coded to be "username" and "password"), and displays a message accordingly.

The program also changes the color of the input fields and the login button when the mouse is over them, to provide visual feedback to the user.

Finally, the program clears the window, draws all the graphical elements, and displays the window using window.display().

</details>
