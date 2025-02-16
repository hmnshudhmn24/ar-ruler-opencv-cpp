# Augmented Reality (AR) Ruler

## Overview
This C++ application uses OpenCV and ArUco markers to measure real-world objects through a webcam. Useful for virtual measuring tools and AR applications.

## Requirements
- OpenCV with ArUco module
- CMake
- Webcam

## How to Build and Run
1. Install OpenCV and CMake.
2. Compile using CMake:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
3. Run the program:
   ```bash
   ./ar_ruler
   ```

## How It Works
- Detects two ArUco markers in the camera feed.
- Computes the real-world distance between them.
- Displays the measurement in centimeters on the screen.

## Future Enhancements
- Extend to measure objects of irregular shapes.
- Improve accuracy with camera calibration.
