#include <iostream>
#include <map>
#include <functional>
#include <sstream>
#include <algorithm>
#include <limits>
#include <vector>
#include <cctype>

// Incluimos nuestros propios archivos con las clases del proyecto
#include "GestorIngredientes.h"
#include "GestorRecetas.h"
#include "Recetas.h"

// Función para convertir un string a minúsculas
std::string toLower(const std::string& str) {
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(),
        [](unsigned char c){ return std::tolower(c); }); // Usamos una lambda para mayor claridad
    return lower;
}

// Función para dividir una cadena de ingredientes en un vector de strings
std::vector<std::string> dividirIngredientes(const std::string& linea) {
    std::vector<std::string> resultado;
    std::istringstream ss(linea);
    std::string item;

    while (std::getline(ss, item, ',')) {
        // Eliminar espacios en blanco al inicio y al final
        item.erase(0, item.find_first_not_of(" \t"));
        item.erase(item.find_last_not_of(" \t") + 1);

        // Convertir a minúsculas
        item = toLower(item);

        // Añadir al vector de resultados
        resultado.push_back(item);
    }

    return resultado;
}

// Función para leer una opción válida del usuario
int leerOpcion(int min, int max) {
    int opcion;
    while (true) {
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (std::cin.fail() || opcion < min || opcion > max) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar entrada incorrecta
            std::cout << "Opción no válida. Intente nuevamente: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
            return opcion;
        }
    }
}

int main() {
    // Creamos los objetos que gestionan los ingredientes y las recetas
    GestorIngredientes gestorIng;
    GestorRecetas gestorRec;

    // Cargamos las recetas desde el archivo de texto
    cargarRecetasDesdeArchivo("recetas.txt", gestorRec);

    // Creamos un mapa para asociar opciones del menú con funciones
    std::map<int, std::function<void()>> menu;

    // Opción 1: Agregar ingredientes
    menu[1] = [&]() {
        std::cout << "Ingrese ingredientes separados por coma: ";
        std::string linea;
        std::getline(std::cin, linea);

        // Dividimos los ingredientes y los guardamos
        auto ingredientes = dividirIngredientes(linea);
        for (const auto& ing : ingredientes) {
            gestorIng.agregarIngrediente(ing, 1); // Ponemos cantidad 1 por simplicidad
        }
        std::cout << "Ingredientes agregados.\n";
    };

    // Opción 2: Ver recetas disponibles según lo que tenemos
    menu[2] = [&]() {
        const auto& ingUsuario = gestorIng.obtenerIngredientes();
        auto recetas = gestorRec.buscarDisponibles(ingUsuario);

        std::cout << "\nRecetas disponibles:\n";
        if (recetas.empty()) {
            std::cout << "- No hay recetas disponibles con los ingredientes actuales.\n";
        } else {
            for (const auto& r : recetas) {
                std::cout << "- " << r.getNombre() << "\n";
            }
        }
    };

    // Opción 3: Borrar todos los ingredientes que habíamos guardado
    menu[3] = [&]() {
        gestorIng.limpiar();
        std::cout << "Lista de ingredientes limpiada.\n";
    };

    // Opción 4: Ver los ingredientes que tenemos guardados ahora mismo
    menu[4] = [&]() {
        const auto& ing = gestorIng.obtenerIngredientes();
        if (ing.empty()) {
            std::cout << "No hay ingredientes agregados.\n";
        } else {
            std::cout << "Ingredientes actuales:\n";
            for (const auto& par : ing) {
                std::cout << "- " << par.first << ": " << par.second << "\n";
            }
        }
    };

    // Aquí empieza el menú del programa
    int opcion;
    do {
        std::cout << "\n=== CHEF VIRTUAL ===\n"
                  << "1. Agregar ingredientes\n"
                  << "2. Ver recetas disponibles\n"
                  << "3. Limpiar lista de ingredientes\n"
                  << "4. Ver ingredientes actuales\n"
                  << "5. Salir\n"
                  << "Seleccione una opción: ";

        opcion = leerOpcion(1, 5); // Leemos la opción que elige el usuario

        if (opcion != 5) {
            menu[opcion](); // Ejecutamos la función correspondiente
        }
    } while (opcion != 5); // Salimos si elige 5

    std::cout << "Gracias por usar Chef Virtual. ¡Hasta pronto!\n";
    return 0;
}