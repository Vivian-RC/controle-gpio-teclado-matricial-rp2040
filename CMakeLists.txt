# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Minimum CMake version
cmake_minimum_required(VERSION 3.13)

# Set the C standard and C++ standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialize Pico SDK
# Do not edit the following lines for the Raspberry Pi Pico VS Code extension to work
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

# Define the Pico board type
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Include the Pico SDK import file
include(pico_sdk_import.cmake)

# Set the project name
project(main C CXX ASM)

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Define the executable and add source files
add_executable(main
    src/main.c
    src/lcd.c
    src/teclado.c
    src/leds_buzzer.c
    src/componentes.c
)

# Set program name and version
pico_set_program_name(main "Teclado_LCD_Projeto")
pico_set_program_version(main "0.1")

# Enable or disable UART/USB output (modify as needed)
pico_enable_stdio_uart(main 0)  # UART disabled
pico_enable_stdio_usb(main 1)   # USB enabled

# Link necessary libraries
target_link_libraries(main
    pico_stdlib
    hardware_i2c   # I2C library
)

# Include directories for header files
target_include_directories(main PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
)

# Add extra outputs such as .uf2 files
pico_add_extra_outputs(main)

# Additional libraries can be added here
