#include "GestorRecetas.h"
#include <fstream>    // Para abrir y leer el archivo de recetas
#include <sstream>    // Para dividir cadenas de texto
#include <iostream>   // Para mostrar mensajes de error

// Esta función agrega una nueva receta al vector de recetas
void GestorRecetas::agregarReceta(const Recetas& receta) {
    recetas.push_back(receta); // La agregamos al final del vector
}

// Esta función devuelve las recetas que se pueden hacer con los ingredientes actuales del usuario
std::vector<Recetas> GestorRecetas::buscarDisponibles(const std::map<std::string, float>& ingredientes) const {
    std::vector<Recetas> disponibles;

    // Recorremos todas las recetas que tenemos guardadas
    for (const auto& r : recetas) {
        // Usamos la función sePuedePrepararCon para ver si se puede hacer con los ingredientes actuales
        if (r.sePuedePrepararCon(ingredientes)) {
            disponibles.push_back(r); // Si se puede, la agregamos a las disponibles
        }
    }

    return disponibles; // Devolvemos la lista final
}

// Esta función carga las recetas desde un archivo como recetas.txt
void cargarRecetasDesdeArchivo(const std::string& nombreArchivo, GestorRecetas& gestor) {
    std::ifstream archivo(nombreArchivo); // Abrimos el archivo

    // Verificamos si se pudo abrir correctamente
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo de recetas: " << nombreArchivo << "\n";
        return;
    }

    std::string linea;

    // Leemos el archivo línea por línea
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string nombreReceta;

        // Obtenemos el nombre de la receta antes de los dos puntos (:)
        if (!std::getline(iss, nombreReceta, ':')) continue;

        // Obtenemos el resto de la línea, que son los ingredientes
        std::string ingredientesTexto;
        if (!std::getline(iss, ingredientesTexto)) continue;

        std::istringstream ingredientesStream(ingredientesTexto);
        std::string item;
        std::vector<IngredienteCantidad> ingredientes;

        // Separamos los ingredientes por comas y los leemos uno a uno
        while (std::getline(ingredientesStream, item, ',')) {
            std::istringstream parte(item);
            std::string nombre;
            float cantidad;
            std::string unidad; // Aunque no lo usemos, lo leemos porque está en el archivo

            // Leemos nombre, cantidad y unidad
            parte >> nombre >> cantidad >> unidad;

            // Si el nombre no está vacío y la cantidad es válida, lo añadimos
            if (!nombre.empty() && cantidad > 0) {
                ingredientes.push_back({nombre, cantidad});
            }
        }

        // Creamos una nueva receta con los datos que acabamos de leer
        Recetas receta(nombreReceta, ingredientes);
        gestor.agregarReceta(receta); // Agregamos la receta al gestor
    }
}