# elastic-collision-physics-simulation

In physics, an elastic collision is an encounter (collision) between two bodies in which the total kinetic energy of the two bodies remains the same. In an ideal, perfectly elastic collision, there is no net conversion of kinetic energy into other forms such as heat, noise, or potential energy.

This C++ project implements an elastic collision physics simulation using the SFML (Simple and Fast Multimedia Library). The simulation includes balls bouncing within a confined space, and users can manipulate gravity, restitution, and restart the simulation. This project was coded and tested with Ubuntu 22.04 LTS. 

<div align="left">
  <img src="./res/example.gif" alt="gif">
</div>

## Getting Started

### Prerequisites
- C++ Compiler
- SFML library (Simple and Fast Multimedia Library)
- optional Makefile (for much easier compilation)

### Installation (with Makefile)

1. Clone the repository:
```js
git clone 
```

2. Install SFML by following the instructions on the official SFML website.

```js
https://www.sfml-dev.org/tutorials/2.6/start-linux.php (linux)
https://www.sfml-dev.org/tutorials/2.6/start-osx.php (macOS)
https://www.sfml-dev.org/tutorials/2.6/start-vc.php (windows)
```

3. Compile the project:
```
make
```

4. Run the executable:
```js
./main
```
### Installation (without Makefile)
1. Clone the repository:
```js
git clone 
```

2. Install SFML by following the instructions on the official SFML website. Just download SFML folder and put it into this folder.
```js
https://www.sfml-dev.org/tutorials/2.6/start-linux.php (linux)
https://www.sfml-dev.org/tutorials/2.6/start-osx.php (macOS)
https://www.sfml-dev.org/tutorials/2.6/start-vc.php (windows)
```

3. Create the build directory:
```js
mkdir -p build
```

4. Compile the project:
```js
g++ -std=c++11 -Wall -Wextra -pedantic -c src/ball.cpp -o build/ball.o -Iinclude
g++ -std=c++11 -Wall -Wextra -pedantic -c src/button.cpp -o build/button.o -Iinclude
g++ -std=c++11 -Wall -Wextra -pedantic -c src/main.cpp -o build/main.o -Iinclude
g++ -std=c++11 -Wall -Wextra -pedantic -c src/random.cpp -o build/random.o -Iinclude
g++ -std=c++11 -Wall -Wextra -pedantic -c src/sandbox.cpp -o build/sandbox.o -Iinclude
g++ -std=c++11 -Wall -Wextra -pedantic -c src/slider.cpp -o build/slider.o -Iinclude
g++ -std=c++11 -Wall -Wextra -pedantic -c src/vector2.cpp -o build/vector2.o -Iinclude
```

4. Linking (dont forget the sfml flags!)
 ```js
g++ -std=c++11 -Wall -Wextra -pedantic -o main build/ball.o build/button.o build/main.o build/random.o build/sandbox.o build/slider.o build/vector2.o -lsfml-graphics -lsfml-window -lsfml-system
```

5. Run the executable
```js
./main 
```

### Code structure
- **`vector2.h` and `vector2.cpp`:** Define and implement the `Vector2` class, providing vector operations.

- **`sandbox.h` and `sandbox.cpp`:** Manage the physics simulation using the `SandBox` class.

- **`ball.h` and `ball.cpp`:** Define and implement the `Ball` class, representing bouncing balls in the simulation.

- **`random.h` and `random.cpp`:** Implement utility functions for generating random values used in the simulation.
- **`slider.h` and `slider.cpp`:** Handle slider UI elements with the `Slider` class.

- **`button.h` and `button.cpp`:** Handle UI elements with the `Button` class.

- **`main.cpp`:** Serve as the entry point for the program.
