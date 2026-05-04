*This project has been created as part of the 42 curriculum by [Hamediter] and [@mlavry].*

# 🏰 Cub3D - Raycasting Engine

<p align="center">
  <img src="https://img.shields.io/badge/Score-125%2F125-success?style=for-the-badge&logo=42" alt="Score">
  <img src="https://img.shields.io/badge/Library-MiniLibX-orange?style=for-the-badge" alt="MiniLibX">
  <img src="https://img.shields.io/badge/Collaboration-Group_Project-blueviolet?style=for-the-badge" alt="Group Project">
</p>

## 📝 Description
**Cub3D** is a 3D graphical project inspired by the world-famous 90's game *Wolfenstein 3D*. The goal was to build a first-person view raycasting engine from scratch using the MiniLibX.

This project focuses on trigonometry, 2D/3D projections, and strict data parsing to create an immersive environment.

### Key Features
- **3D Raycasting:** Real-time rendering of a 3D environment based on a 2D map.
- **Dynamic Movement:** Smooth walking and rotation using the keyboard and mouse.
- **Texture Mapping:** Different textures for North, South, East, and West walls.
- **Bonus Implementation:**
  - 🗺️ **Minimap:** Real-time 2D radar.
  - 🚪 **Doors:** Interactive doors that open and close.
  - 🔫 **Sprites & Animations:** Animated sprites (e.g., weapons or enemies).
  - 🐭 **Mouse Control:** Rotation handled by mouse movement.

---

## 🏗️ Architecture & Collaboration
To ensure the best performance and a clean codebase, we divided the work into two specialized modules:

- **The Parsing (My Responsibility):** 
  - Implementation of a strict `.cub` file analyzer. 
  - Validation of map boundaries (flood-fill algorithm for wall enclosure).
  - Texture and color data extraction with comprehensive error management.
  - Efficient storage of map data for the raycaster.
- **The Raycasting (Partner's Responsibility):**
  - Calculation of wall hits using the DDA (Digital Differential Analyzer) algorithm.
  - Calculation of wall height and texture coordinates for 3D projection.
  - Integration of bonus features like floors/ceilings textures and sprites.

---

## 🛠️ Design Choices
*   **Performance:** All images are pre-loaded to avoid frame drops. We used an image buffer to render the entire frame at once before pushing it to the window.
*   **Mathematical Accuracy:** Use of trigonometry to fix the "fish-eye" effect, ensuring a realistic perspective.
*   **Error Handling:** Precise detection of map errors (leaks, invalid characters, missing textures) to prevent engine crashes.

---

## 🚀 Instructions

### Installation
```bash
make
./cub3D maps/map.cub
