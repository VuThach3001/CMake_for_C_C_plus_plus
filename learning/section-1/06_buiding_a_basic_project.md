# Section 1: A Basic Starting Point

## Topic: Building a Basic Project

## Date: 14/10/2025

---

### Cue Column (Questions, Keywords, or Prompts)

- Where do I start with CMake? This step will provide an introduction to some of CMake's basic syntax, commands, and variables. As these concepts are introduced, we will work through three exercises and create a simple CMake project.

- Each exercise in this step will start with some background information. Then, a goal and list of helpful resources are provided. Each file in the `Files to Edit` section is in the `Step1` directory and contains one or more `TODO` comments. Each `TODO` represents a line or two of code to change or add. The `TODO` s are intended to be completed in numerical order, first complete `TODO` 1 then `TODO` 2, etc. The `Getting Started` section will give some helpful hints and guide you through the exercise. Then the `Build and Run` section will walk step-by-step through how to build and test the exercise. Finally, at the end of each exercise the intended solution is discussed.

---

### Notes Section (Main Notes)

**1. Building a Basic Project**

- The most basic CMake project is an executable built from a single source code file. For simple projects like this, a `CMakeLists.txt` file with three commands is all that is required.

- *Note: Although upper, lower and mixed case commands are supported by CMake, lower case commands are preferred and will be used throughout the tutorial.*

- Any project's top most `CMakeLists.txt` must start by specifying a minimum CMake version using the `cmake_minimum_required()` command. This establishes policy settings and ensures that the following CMake functions are run with a compatible version of CMake.

- To start a project, we use the `project()` command to set the project name. This call is required with every project and should be called soon after `cmake_minimum_required()`. As we will see later, this command can also be used to specify other project level information such as the language or version number.

- Finally, the add_`executable()` command tells CMake to create an executable using the specified source code files.

- To sum up:
  - `TODO 1`: **cmake_minimum_required()**
  - `TODO 2`: **project()**
  - `TODO 3`: **add_executable()**

```cmake
# TODO 1
cmake_minimum_required(VERSION 3.28.3)

# TODO 2
project(main)

# TODO 3
add_executable(main ./sources/main.c ./sources/other.c)
```

**2. Goal**
- Understand how to create a simple CMake project.

**3. Helpful Resources**
- [add_executable()](https://cmake.org/cmake/help/latest/command/add_executable.html#command:add_executable)
- [cmake_minimum_required()](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command:cmake_minimum_required)
- [project()](https://cmake.org/cmake/help/latest/command/project.html#command:project)

**4. Files to Edit**

- `CMakeLists.txt`

**5. Getting Started**
- The source code for `main.c` is provided and can be used to compute the square root of a number. This file does not need to be edited in this step.

- In the same directory is a `CMakeLists.txt` file which you will complete. Start with **TODO 1** and work through **TODO 3**

**6. Build and Run**

Once **TODO 1** through **TODO 3** have been completed, we are ready to build and run our project! First, run the cmake executable or the **cmake-gui** to configure the project and then build it with your chosen build tool.

For example, from the command line we could navigate to the `./CMakeLists.txt` directory of the CMake source code tree and create a build directory:
```bash
mkdir build
```
- Next, navigate to that build directory and run `make` to configure the project and generate a native build system
```bash
cd build
cmake ..
```
- Then call that build system to actually compile/link the project
```bash
cmake --build .
OR
make
```
- For multi-config generators (e.g. Visual Studio), first navigate to the appropriate subdirectory, for example:
```bash
cd Debug
```
---

### Summary Section (Summary of Notes)

[Insert a brief summary of the key ideas and takeaways]
