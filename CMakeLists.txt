# Versión mínima de CMake que vamos a usar
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto y lenguaje que usaremos
project(ChefVirtual VERSION 1.0 LANGUAGES CXX)

# Especificamos el estándar de C++ que vamos a usar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Le decimos a CMake dónde están los archivos .h (cabeceras)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Archivos fuente del programa principal
set(SOURCES
    src/main.cpp
    src/Recetas.cpp
    src/GestorIngredientes.cpp
    src/GestorRecetas.cpp
)

# Creamos el ejecutable principal del proyecto
add_executable(ChefVirtual ${SOURCES})

# Copiamos el archivo recetas.txt al directorio de compilación para que el programa lo encuentre
if(EXISTS "${CMAKE_SOURCE_DIR}/recetas.txt")
    configure_file(${CMAKE_SOURCE_DIR}/recetas.txt
                   ${CMAKE_BINARY_DIR}/recetas.txt
                   COPYONLY)
endif()


# TEST 1: TestChefVirtual

add_executable(TestChefVirtual
    Test/test.cpp
    src/GestorIngredientes.cpp
    src/GestorRecetas.cpp
    src/Recetas.cpp
)

# Le decimos dónde están las cabeceras para los tests
target_include_directories(TestChefVirtual PRIVATE include)

# También copiamos recetas.txt para los tests
if(EXISTS "${CMAKE_SOURCE_DIR}/recetas.txt")
    configure_file(${CMAKE_SOURCE_DIR}/recetas.txt
                   ${CMAKE_BINARY_DIR}/recetas.txt
                   COPYONLY)
endif()

# TEST 2: TestChefVirtual2 (opcional)

add_executable(TestChefVirtual2
    Test/test2.cpp
    src/GestorIngredientes.cpp
    src/GestorRecetas.cpp
    src/Recetas.cpp
)

# También le decimos dónde están las cabeceras
target_include_directories(TestChefVirtual2 PRIVATE include)

# Y copiamos recetas.txt para este test también
if(EXISTS "${CMAKE_SOURCE_DIR}/recetas.txt")
    configure_file(${CMAKE_SOURCE_DIR}/recetas.txt
                   ${CMAKE_BINARY_DIR}/recetas.txt
                   COPYONLY)
endif()



            