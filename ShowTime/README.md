# ShowTime
A SideCMake example demonstrating how to:
- **Bootstrap a C++ CMake project using SideCMake**
- **Add an executable target**
- **Add a library target**
- **Add tests**
- **Generate documentation**

## Project Overview
This project contains an executable target, `console`, which displays the date and time by calling the library target `libtime`.

### Source Layout
```
project_root/
├── src/
│   ├── console
│   │   └── main.cpp
│   └── libtime
│       └── my_time.cpp
├── include/
│   └── libtime
│       └── my_time.h
└── test
    └── main.cpp
```

### Prerequisites
- External Dependencies
  - [fmt](https://github.com/fmtlib/fmt)
  - [spdlog](https://github.com/gabime/spdlog)
  - [doctest](https://github.com/doctest/doctest) (optional)
- Package Management Tools (optional)
  - [vcpkg](https://github.com/microsoft/vcpkg)
- Documentation Tools (optional)
  - Python 3
  - [Doxygen](https://www.doxygen.org)
  - [Sphinx](https://www.sphinx-doc.org) and extensions:
    - [breathe](https://github.com/breathe-doc/breathe.git)
    - [exhale](https://github.com/svenevs/exhale)

> [!TIP]
> Sphinx and its extensions can be installed in your Python environment with:
> ```sh
> pip install Sphinx breathe exhale
> ```

## Project Setup
Below is a demonstration of how to set up the CMake project `ShowTime` from scratch.

### Clone SideCMake
Clone SideCMake to a path aside with SideCMakeExamples;
```
git clone https://www.github.com/imlinkzuz/SideCMake \path\to\SideCMake
```

### Install External Dependencies
Make sure you have installed `vcpkg` and set the environment variable `VCPKG_ROOT` correctly. Then, install all dependencies:
```
vcpkg install fmt
vcpkg install spdlog
vcpkg install doctest
```

### Bootstrap from Boilerplate Files
```sh
cp -r /path/to/SideCMake/bootstrap/. ./
```

### Customize Settings
- `LocalPresets.json`: In the `cacheVariables` section, set `SIDECMAKE_DIR` to `\path\to\SideCMake`.
  - To use `vcpkg`, set `CMAKE_TOOLCHAIN_FILE` to `$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake`.
  > [!TIP]
  > You can also set `-DCMAKE_TOOLCHAIN_FILE=$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake` as a command-line argument to `cmake`, but using presets is more convenient when working in IDEs like VS Code.
- `ProjectPresets.json`: Set `SC_PROJECT_NAME` to `ShowTime`, and feel free to change other settings as needed.

### Find External Dependencies
SideCMake provides the function `sc_find_package` to improve searching for external dependencies.
> [!TIP]
> For clarity, keep all `sc_find_package` calls in `Dependencies.cmake`.
Add the following to `Dependencies.cmake`:
```cmake
# Searching for library `fmt`
sc_find_package(PKG_TARGET fmt::fmt 
  PKG_OPTIONS 
    REQUIRED CONFIG
)  

# Searching for library `spdlog`
add_compile_definitions(SPDLOG_FMT_EXTERNAL)
sc_find_package(PKG_TARGET spdlog::spdlog 
  PKG_OPTIONS 
    REQUIRED CONFIG
)
```
> [!TIP]
> Although it's best to pair `sc_find_package` with `sc_install_executable` and `sc_install_library`, a fallback to `find_package` is also supported.

### Add Targets
SideCMake provides `sc_install_executable` and `sc_install_library` to make building and installing targets easier.
There are two targets here: `libtime` and `console`. A `CMakeLists.txt` should be created under `src` so CMake can detect them. The contents are very simple:
```cmake
add_subdirectory(libtime)
add_subdirectory(console)
```
#### libtime
Add `CMakeLists.txt` in `src/libtime` with the following contents:
```cmake
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
include(${SIDECMAKE_DIR}/SCInstall.cmake)

sc_install_library(
  TARGET_NAME "libTime"
  PROJECT_NAME ${PROJECT_NAME}
  LINK_TYPE STATIC
  TARGET_PROPERTIES 
    VERSION ${PROJECT_VERSION}
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
  PRIVATE_SOURCES
    my_time.cpp
  PUBLIC_DEPENDENCIES
    fmt 
  PUBLIC_INCLUDE_DIRS
    "include/sample/libtime"
)
```
#### console
Add `CMakeLists.txt` in `src/console` with the following contents:
```cmake
include(${SIDECMAKE_DIR}/SCInstall.cmake)

sc_install_executable(
  TARGET_NAME console
  PRIVATE_SOURCES
    main.cpp
  PRIVATE_DEPENDENCIES
    ShowTime::libTime
    spdlog
)
```

### Building and Installation
You can now configure and build the project in your IDE or from the command line:
```sh
cmake /path/to/SideCMakeExamples/ShowTime --preset default
cd /path/to/SideCMakeExamples/ShowTime/_build/default
# For release
cmake --build . --target install --config Release
# For debug
cmake --build . --target install --config Debug 
```

## Testing
SideCMake uses doctest as the testing framework and provides the function `sc_add_unit_test` for easy test construction. Create a `CMakeLists.txt` under the `test` directory and add the following contents:
```cmake
include(${SIDECMAKE_DIR}/SCTest.cmake)

sc_add_unit_test(
  TEST_NAME unit_test 
  VERSION_MATCHES
  TARGETS
      console
      libTime    
  TEST_SOURCES
      main.cpp
)
```
You can now run tests with `ctest -T test`.
> [!TIP]
> You can also run tests using the Testing Explorer in VS Code.

## Documentation
To enable documentation generation, simply set `SC_ENABLE_DOC` to `ON`.






