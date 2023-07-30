# SFML-Findings
This repository will house all my findings in SFML as to make developing future GUI projects using SFML more efficient and faster.

# Files
- [A login simulation](Login_Simulation.cpp). [Description](#login-simulation)
- [Scene Manager](Scene_Manager.cpp). [Description](#scene-manager)

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


# Scene Manager

This code provides a basic framework for a game engine or interactive fiction engine. 

It uses a loop to repeatedly call functions for each scene until the end of the game is reached. The current scene is tracked using a pointer to an integer, and the code for each scene is executed using a switch statement. 

The loop continues until the current scene is set to -1, at which point the program exits the loop and returns 0 from the main() function. To create a fully functional game, you would need to define the different scenes and their corresponding functions, and set up the logic to advance the player from one scene to the next.

<details>

<summary>In Details</summary>

Let's go through the code step by step:

1. The main() function is the starting point of the program.

2. The int* scene = 0; line creates a pointer to an integer and initializes it to zero. This pointer will be used to keep track of the current scene.

3. The while (*scene != -1) line creates a loop that will continue until the current scene is set to -1. This is typically used as a signal to end the game.

4. The switch (*scene) line checks the value of the current scene and executes the code for that scene. The case statements represent different scenes in the game, and the corresponding code for each scene is executed when the current scene matches the case value.

5. The break statements at the end of each case block are used to exit the switch statement and continue with the loop.

6. The loop continues until the current scene is set to -1, at which point the program exits the loop and returns 0 from the main() function.

Overall, this code provides a basic framework for a game or interactive fiction engine, but it doesn't actually do anything useful on its own. To create a fully functional game, you would need to define the different scenes and their corresponding functions, and set up the logic to advance the player from one scene to the next.
 
</details>
