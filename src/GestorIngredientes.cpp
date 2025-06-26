#include "GestorIngredientes.h"
#include <iostream>  // Para mostrar texto por pantalla

// Agrega un ingrediente a la lista. Si ya estaba, suma la nueva cantidad.
void GestorIngredientes::agregarIngrediente(const std::string& nombre, float cantidad) {
    ingredientes[nombre] += cantidad;  // suma si ya existe
}

// Limpia todos los ingredientes de la lista
void GestorIngredientes::limpiar() {
    ingredientes.clear();  // Borra todo
}

// Devuelve los ingredientes actuales (para leerlos desde otras partes del programa)
const std::map<std::string, float>& GestorIngredientes::obtenerIngredientes() const {
    return ingredientes;
}

// Muestra en pantalla todos los ingredientes que hay ahora mismo
void GestorIngredientes::mostrarIngredientes() const {
    if (ingredientes.empty()) {
        std::cout << "\nNo ha agregado ningún ingrediente todavía.\n";
    } else {
        std::cout << "\nIngredientes actuales:\n";
        for (const auto& [nombre, cantidad] : ingredientes) {
            std::cout << "- " << nombre << ": " << cantidad << "\n";
        }
    }
}
