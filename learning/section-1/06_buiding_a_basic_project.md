# Section 1: A Basic Starting Point

## Topic: Building a Basic Project

## Date: 14/10/2025

---

### Cue Column (Questions, Keywords, or Prompts)

- Where do I start with CMake? This step will provide an introduction to some of CMake's basic syntax, commands, and variables. As these concepts are introduced, we will work through three exercises and create a simple CMake project.

- Each exercise in this step will start with some background information. Then, a goal and list of helpful resources are provided. Each file in the `Files to Edit` section is in the `Step1` directory and contains one or more `TODO` comments. Each `TODO` represents a line or two of code to change or add. The `TODO` s are intended to be completed in numerical order, first complete `TODO` 1 then `TODO` 2, etc. The `Getting Started` section will give some helpful hints and guide you through the exercise. Then the `Build and Run` section will walk step-by-step through how to build and test the exercise. Finally, at the end of each exercise the intended solution is discussed.

---

### Notes Section (Main Notes)


**1. Background**
- Typical usage of `CMake` revolves around one or more files named `CMakeLists.txt`. This file is sometimes referred to as a "`lists file`" or "`CML`". Within a given software project, a `CMakeLists.txt` will exist within any directory where we want to provide instructions to CMake on how to handle files and operations local to that directory or subdirectories. Each consists of a set of commands which describe some information or actions relevant to building the software project.

- Not every directory in a software project needs a `CML`, but it's strongly recommended that the project root contains one. This will serve as the entry point for `CMake` for its initial setup during configuration. This root `CML` should always contain the same two commands at or near the top the file.
```cmake
cmake_minimum_required(VERSION 3.23)
project(MyProjectName)
```
- The `cmake_minimum_required()` is a compatibility guarantee provided by `CMake` to the project developer. When called, it ensures that `CMake` will adopt the behavior of the listed version. If a later version of `CMake` is invoked on a `CML` containing the above code, it will act exactly as if it were `CMake` 3.23.

- The `project()` command is a conceptually simple command which provides a complex function. It informs `CMake` that what follows is the description of a distinct software project of a given name (as opposed to a shell-like script). When `CMake` sees the `project()` command it performs various checks to ensure the environment is suitable for building software; such as checking for compilers and other build tooling, and discovering properties like the **endianness of the host and target machines**.

*Note: While links to complete documentation are provided for every command, it is not intended the reader understand the full semantics of each `CMake` command they use. Effectively learning `CMake`, like any piece of software, is an incremental process.*

- The rest of this tutorial step will be chiefly concerned with the usage of four more commands. The `add_executable()` and `add_library()` commands for describing output artifacts the software project wants to produce, the `target_sources()` command for associating input files with their respective output artifacts, and the `target_link_libraries()` command for associating output artifacts with one another.

- These four commands are the backbone of most `CMake` usage. As we'll learn, they are sufficient for describing the majority of a typical project's requirements.

**1. Building an Executable**

- The most basic CMake project is an executable built from a single source code file. For simple projects like this, a `CMakeLists.txt` file with three commands is all that is required.

- *Note: Although upper, lower and mixed case commands are supported by CMake, lower case commands are preferred and will be used throughout the tutorial.*

- The first two commands we have already introduced, `cmake_minimum_required()` and `project()`. There is no usage of CMake where the first command in a root CML will be anything other than `cmake_minimum_required()`. There are some advanced usages where `project()` might not be the second command in a `CML`, but for our purposes it always will be.

- The next command we need is `add_executable()`. This command creates a **target**. In `CMake` lingo, a **target** is a name the developer gives to a collection of properties.

- Some examples of properties a **target** might want to keep track of are:
  - The artifact kind (executable, library, header collection, etc)
  - Source files
  - Include directories
  - Output name of an executable or library
  - Dependencies
  - Compiler and linker flags
- The mechanisms of CMake are often best understood as describing and manipulating targets and their properties. There are many more properties than those listed here. Documentation of CMake commands will often discuss their function in terms of the target properties they operate on.
- Targets themselves are simply names, a handle to this collection of properties. Using the `add_executable()` command is as easy as specifying the name we want to use for the target.

```cmake
add_executable(MyProgram)
```
- Now that we have a name for our **target**, we can start associating properties with it like source files we want to build and link. The primary command for this is `target_sources()`, which takes as arguments a target name followed by one or more collections of files.

```cmake
target_sources(MyProgram
  PRIVATE
    main.cxx
)
```
*Note: Paths in `CMake` are generally either absolute, or relative to the `CMAKE_CURRENT_SOURCE_DIR`. We haven't talked about variables like that yet, so you can read this as "relative to the location of the current CML".*

- Each collection of files is prefixed by a scope keyword. We'll discuss the complete semantics of these keywords when we talk about linking targets together, but the quick explanation is these describe how a property should be inherited by dependents of our target.

- Typically, **nothing depends on an executable**. Other programs and libraries don't need to link to an executable, or inherit headers, or anything of that nature. So the appropriate scope to use here is `PRIVATE`, which informs `CMake` that this property only belongs to MyProgram and is not inheritable.

*Note: This rule is true almost everywhere. Outside advanced and esoteric usages, the scope keyword for executables should always be `PRIVATE`. The same holds for implementation files generally, regardless of whether the target is an executable or a library. The only target which needs to "see" the .cxx files is the target building them.*

**2. Goal**
- Understand how to create a simple CMake project.

**3. Helpful Resources**
- [add_executable()](https://cmake.org/cmake/help/latest/command/add_executable.html#command:add_executable)
- [cmake_minimum_required()](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command:cmake_minimum_required)
- [project()](https://cmake.org/cmake/help/latest/command/project.html#command:project)
- [target_sources()](https://cmake.org/cmake/help/latest/command/target_sources.html#command:target_sources)

**4. Files to Edit**

- `CMakeLists.txt`

**5. Getting Started**
- The source code for `main.c` is provided and can be used to compute the square root of a number. This file does not need to be edited in this step.

- In the same directory is a `CMakeLists.txt` file which you will complete. Start with **TODO 1** and work through **TODO 4**

**6. Build and Run**

- Once `TODO 1` through `TODO 4` have been completed, we are ready to build and run our project! First, run the cmake executable or the cmake-gui to configure the project and then build it with your chosen build tool.
- Invoke CMake for configuration as follows:
```cmake
cmake -B build
```
- The `-B` flag tells CMake to use the given relative path as the location to generate files and store artifacts during the build process. If it is omitted, the current working directory is used. It is generally considered bad practice to do "in-source" builds, placing these generated files in the source tree itself.

- Next, tell CMake to build the project with `cmake --build`, passing it the same relative path we did with the `-B` flag.
```cmake
cmake --build build
```
- The `example` executable will be built into the `build` directory.

---

### Summary Section (Summary of Notes)

[Insert a brief summary of the key ideas and takeaways]
