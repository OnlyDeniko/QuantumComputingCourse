[![Build application](https://github.com/OnlyDeniko/QuantumComputingCourse/actions/workflows/main.yml/badge.svg?branch=main)](https://github.com/OnlyDeniko/QuantumComputingCourse/actions/workflows/main.yml)
# QuantumComputingCourse

## 1. Build the project with `CMake`
Navigate to a source code folder.

1) Configure the build:

  ```
  mkdir build
  cd build
  cmake ..
  ```

2) Build the project:
  ```
  cmake --build . --config RELEASE
  ```
  To build only your project, you need to do the following:
  ```
  cmake --build . --target <task's name> --config RELEASE
  ```
  Example:
  ```
  cmake --build . --target kulandin_d --config RELEASE
  ```
3) Check the task
  * Run `<project's folder>/build/bin`