# SFML + ImGui Example

This project demonstrates the integration of **SFML 2.6.2** and **ImGui v1.87** to create a simple graphical application. The program includes an interactive circle that can be controlled through an ImGui graphical user interface (GUI).

## Features

- **Interactive Circle:**
  - Modify the circle's radius and number of segments.
  - Change the circle's color in real-time using a color picker.
  - Toggle circle visibility with a checkbox.

- **Movement Control:**
  - Adjust the circle's horizontal and vertical speeds.
  - The circle bounces off the window edges automatically.

- **ImGui GUI:**
  - Provides an intuitive interface for real-time adjustments.

## Getting Started

### Prerequisites

- **SFML 2.6.2**
- **ImGui v1.87**
- **ImGui-SFML binding v2.6**

### Building the Project

1. Clone the repository or copy the source code.

2. Install the required dependencies:
   - SFML 2.6.2
   - ImGui v1.87
   - ImGui-SFML binding

3. Compile the source code. Example using `g++`:
   ```bash
   g++ main.cpp -o sfml_imgui_app -lsfml-graphics -lsfml-window -lsfml-system -limgui-sfml
   ```

4. Run the compiled executable:
   ```bash
   ./sfml_imgui_app
   ```

### Project Structure

- **main.cpp:** The main source file containing the SFML and ImGui integration code.

## Controls

1. Open the "Control Panel" window from the ImGui GUI.
2. Use the sliders and checkboxes to:
   - Change the circle's radius.
   - Adjust the number of segments (sides of the circle).
   - Modify the circle's color.
   - Control the circle's horizontal and vertical speeds.
   - Toggle the circle's visibility.

## Libraries Used

- [SFML 2.6.2](https://www.sfml-dev.org/download/sfml/2.6.2/)
- [ImGui](https://github.com/ocornut/imgui/releases/tag/v1.87)
- [ImGui-SFML](https://github.com/SFML/imgui-sfml/releases/tag/v2.6)


## Acknowledgments

Special thanks to the developers of SFML, ImGui, and ImGui-SFML for their incredible libraries that made this project possible.

