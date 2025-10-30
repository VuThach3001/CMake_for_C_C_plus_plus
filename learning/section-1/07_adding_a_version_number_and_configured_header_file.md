# Section 1: Getting Started with CMake

## Topic: Building a Library

## Date: 19/10/2025

---

### Cue Column (Questions, Keywords, or Prompts)

**1. Build a Library**

- We only need to introduce one more command to build a library, `add_library()`. This works exactly like `add_executable()`, but for libraries.

```cmake
add_library(MyLibrary)
```
- However, now is a good time to introduce header files. Header files are not directly built as translation units, which is to say they are not a build requirement. They are a usage requirement. We need to know about header files in order to build other parts of a given target.

- As such, header files are described slightly differently than implementation files like `example.c`. They're also going to need different scope keywords than the `PRIVATE` keyword we have used so far.

- To describe a collection of header files, we're going to use what's known as a `FILE_SET`.
```cmake
target_sources(MyLibrary
  PRIVATE
    library_implementation.cxx

  PUBLIC
    FILE_SET myHeaders
    TYPE HEADERS
    BASE_DIRS
      include
    FILES
      include/library_header.h
)
```
- This is a lot of complexity, but we'll go through it point by point. First, note that we have our implementation file as a `PRIVATE` source, same as with the executable previously. However, we now use `PUBLIC` for our header file. This allows consumers of our library to "see" the library's header files.

*Note: We're not quite ready to discuss the full semantics of scope keywords. We'll cover them more completely in Exercise 3.*

- Following the scope keyword is a `FILE_SET`, a collection of files to be described as a single unit. A `FILE_SET` consists of the following parts:
  - `FILE_SET <name>` is the name of the `FILE_SET`. This is a handle which we can use to describe the collection in other contexts.
  - `TYPE <type>` is the kind of files we are describing. Most commonly this will be headers, but newer versions of CMake support other types like C++20 modules.
  - `BASE_DIRS` is the "base" locations for the files. This can be most easily understood as the locations that will be described to compilers for header discovery via -I flags.
  - `FILES` is the list of files, same as with the implementation sources list earlier.
- This is a lot of information to describe, so there are some useful shortcuts we can take. Notably, if the `FILE_SET` name is the same as the type, we don't need to provide the `TYPE` field.
```cmake
target_sources(MyLibrary
  PRIVATE
    library_implementation.cxx

  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS
      include
    FILES
      include/library_header.h
)
```
- There are other shortcuts we can take, but we'll discuss those more in later steps.

**2. Goal**
- Build a library.

**3, Helpful resources**
- [add_library()](https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library)
- [target_sources()](https://cmake.org/cmake/help/latest/command/target_sources.html#command:target_sources)

**4. Files to Edit**
- `CMakeLists.txt`

**5. Getting Started**
- Continue editing files in the Step1 directory. Start with `TODO 5` and complete through `TODO 6`.

**6. Build and Run**
- Let's build our project again. Since we already created a build directory and ran `CMake` for Exercise 1, we can skip to the build step:
```cmake
cmake --build build
```
- We should be able to see our library created alongside the Tutorial executable.

---

### Summary Section (Summary of Notes)

[Insert a brief summary of the key ideas and takeaways]
