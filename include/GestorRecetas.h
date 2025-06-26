#ifndef GESTOR_RECETAS_H
#define GESTOR_RECETAS_H

// Incluimos bibliotecas que necesitamos
#include <vector>   // Para guardar las recetas
#include <string>   // Para usar nombres de recetas
#include <map>      // Para comparar con los ingredientes del usuario

#include "Recetas.h" // Incluimos la clase que define qué es una receta

// Esta clase gestiona todas las recetas del sistema
class GestorRecetas {
private:
    // Guardamos todas las recetas en un vector (lista ordenada)
    std::vector<Recetas> recetas;

public:
    // Agrega una nueva receta a la lista
    void agregarReceta(const Recetas& receta);

    // Devuelve las recetas que se pueden hacer con los ingredientes del usuario
    std::vector<Recetas> buscarDisponibles(const std::map<std::string, float>& ingredientes) const;
};

// Esta función externa carga las recetas desde un archivo de texto (como recetas.txt)
void cargarRecetasDesdeArchivo(const std::string& nombreArchivo, GestorRecetas& gestor);

#endif
