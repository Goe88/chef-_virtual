// Recetas.cpp - Aquí se implementa cómo funciona cada función de la clase Recetas
#include "Recetas.h"

// Este es el constructor: guarda el nombre y los ingredientes de la receta
Recetas::Recetas(std::string n, std::vector<IngredienteCantidad> ing)
    : nombre(n), ingredientes(ing) {}  // Usamos inicialización directa

// Esta función devuelve el nombre de la receta para mostrarlo en pantalla
std::string Recetas::getNombre() const {
    return nombre;
}

// Esta función revisa si con los ingredientes que tiene el usuario se puede preparar esta receta
bool Recetas::sePuedePrepararCon(const std::map<std::string, float>& disponibles) const {
    for (const auto& ing : ingredientes) {
        auto it = disponibles.find(ing.nombre); // Buscamos el ingrediente en la lista del usuario

        // Si no está, o si no tiene suficiente cantidad, no se puede hacer la receta
        if (it == disponibles.end() || it->second < ing.cantidad) {
            return false;
        }
    }

    // Si todos los ingredientes están y hay cantidad suficiente, sí se puede hacer
    return true;
}
// Esta función devuelve una lista de los ingredientes que faltan para preparar la receta