![CODING]()
# 3D_Shooter 🎮
![SHOOTER](https://user-images.githubusercontent.com/88714347/171422634-8adc8811-2559-4ba1-967f-4caf909c3f22.gif)

## Table of Contents

- [Background Context](#background-context)
- [Environment](#environment)
- [Installation](#installation)
- [How to play the game](#how-to-play-the-game)
- [Controls](#controls)
- [References](#references)
- [Future Enhancements](#future-enhancements)
- [Authors](#authors)
- [License](#license)

# Background Context

- The 3D_Shooter is a 3D maze game that uses ray casting to render a 2D map into a 3D navigable world. The game was developed in C using the SDL2 library. Development was performed on Ubuntu 22.04 LTS.

- The Maze is compatible with both Mac OS X and Linux/Ubuntu. It employs ray casting to create the illusion of a 3D environment within the maze.

## About SDL2 💻

- Simple DirectMedia Layer (SDL2) is a cross-platform development library designed to provide low-level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is widely used in video playback software, emulators, and popular games, including Valve's award-winning catalog and many Humble Bundle games. For more information on SDL2, visit the <a href="https://www.libsdl.org/" target="_blank" rel="noopener noreferrer">official SDL2 website</a>.

## Environment

- Language: C

- Library: SDL2 (Simple DirectMedia Layer)

- Operating System: Ubuntu 22.04 LTS

- Compiler: gcc

## Installation

  - Mac OS X or Linux/Ubuntu
  - SDL2 Installation

- If you don't have SDL2 installed, you can download the installation script here. After downloading, locate the script and run it in your terminal:

    $ ls
    install_SDL2.sh
    $ chmod 755 install_SDL2.sh
    $ sudo ./install_SDL2.sh

## How to play the game

Step 1: Clone the repository:

    git clone https://github.com/Brendon45/3D_Shooter.git

Step 2: Compile All .c Files
To compile all .c files in the src directory and generate an executable file called maze, run the following command:

    make all
    
Step 3: Run the Executable
To play the game, run the executable with a specified map option. The available map options are level_1 to level_7, and demo_00 and demo_01.

Example Commands:

To play the first level, use:

    ./maze maps/level_1

To play the first demo, use:

    ./maze maps/demo_00

## Controls

## References

- [lodev.org](#lodev.org)
- [cplusplus.com](#cplusplus.com)
- [pikuma.com](#pikum.com)
- [3DSage/OpenGL-Raycaster](#3DSage/OpenGL-Raycaster)
- [permadi.com](#permadi.com)

## Future Enhancements

🚧This project is still a work in progress!Stay tuned for more 
            updates coming soon. 🍿📺🍿 

- Additional Levels: Plan to introduce more complex and challenging maze levels.

- Enhanced Graphics: Explore advanced graphical techniques to further improve the visual appeal.

- Expanded Compatibility: Aim to extend compatibility to more platforms, including Windows.

## AUTHORS

1. Brendon Jeje  [Github](https://github.com/Brendon45) | [Linkedin](https://www.linkedin.com/in/brendonjeje/) | [Twitter](https://twitter.com/brendon4545)

2. Tafara Nyamhunaga  [Github](https://github.com/Tafara-N) | [Linkedin](https://www.linkedin.com/in/tafaranyamhunga/) | [Twitter](https://twitter.com/tafaranyamhunga)

## License

- This project is licensed under the MIT License. See the [LICENSE.md](LICENSE.md) file for details.





