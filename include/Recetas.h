// Recetas.h - Aquí se define qué es una receta y qué ingredientes necesita

#ifndef RECETAS_H
#define RECETAS_H

#include <string>   // Para los nombres
#include <vector>   // Para guardar varios ingredientes
#include <map>      // Para comparar con los ingredientes disponibles

// Esta estructura representa un ingrediente con nombre, cantidad y unidad
struct IngredienteCantidad {
    std::string nombre;   // Ejemplo: "huevo"
    float cantidad;       // Ejemplo: 2.0
    std::string unidad;   // Ejemplo: "uds" o "g" (aunque no la usemos en cálculos)
};

// Esta clase representa una receta que tiene un nombre y una lista de ingredientes
class Recetas {
private:
    std::string nombre;   // Nombre de la receta, por ejemplo: "Tortilla"
    std::vector<IngredienteCantidad> ingredientes; // Ingredientes que necesita

public:
    // Constructor: se usa para crear una receta con nombre e ingredientes
    Recetas(std::string n, std::vector<IngredienteCantidad> ing);

    // Devuelve el nombre de la receta (para mostrarlo)
    std::string getNombre() const;

    // Revisa si se puede preparar esta receta con los ingredientes disponibles del usuario
    bool sePuedePrepararCon(const std::map<std::string, float>& disponibles) const;
};

#endif
