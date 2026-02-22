# 2D Partile Simulation Engine (SFML)

![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![SFML](https://img.shields.io/badge/Library-SFML-green.svg)
![Physics](https://img.shields.io/badge/Physics-Kinematics-red.svg)

A lightweight, real-time 2D particle physics engine written in C++ using the SFML framework. This simulation handles elastic collisions, boundary constraints, and kinematic movement.

## 🚀 Features

- **Elastic Collisions:** Implements circle-to-circle collision detection and response.
- **Boundary Management:** Particles realistically bounce off window edges with position correction to prevent "clipping."
- **Velocity & Acceleration:** Support for independent particle vectors for smooth movement.
- **Efficient Render Loop:** Optimized for high frame rates even with multiple active entities.

---

## 🛠 Technical Implementation

### Collision Detection
The simulation uses the **Euclidean Distance Formula** to check for overlaps between particles:
$$distance^2 = (x_2 - x_1)^2 + (y_2 - y_1)^2$$
If the distance is less than the sum of the $$radii^2$$, a collision is triggered.

### Boundary Logic
The `Simulation::boundaryCheck` function monitors particle coordinates against the window dimensions:
- **X-axis:** If $x \le 0$ or $x + diameter \ge width$, the horizontal velocity is inverted.
- **Y-axis:** If $y \le 0$ or $y + diameter \ge height$, the vertical velocity is inverted.

---

## 📂 Project Files

- `Particle.h/cpp`: Defines the particle object (mass, radius, position, velocity, and SFML `CircleShape`).
- `Simulation.h/cpp`: The engine that manages the collection of particles and runs the physics calculations.
- `main.cpp`: The driver file that initializes the SFML window and the simulation loop.

---

## ⚙️ Installation & Build

### 1. Prerequisites
You must have the SFML development libraries installed on your Linux system:
```bash
sudo apt update
sudo apt install build-essential libsfml-dev
```
### 2. Compilation
```bash
make
```
### 3. Execution
```bash
./app
```
