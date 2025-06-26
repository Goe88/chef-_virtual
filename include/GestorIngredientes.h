#ifndef GESTOR_INGREDIENTES_H
#define GESTOR_INGREDIENTES_H

#include <map>      // Para guardar ingredientes con sus cantidades
#include <string>   // Para manejar los nombres de los ingredientes

// Esta clase sirve para gestionar los ingredientes que va escribiendo el usuario
class GestorIngredientes {
private:
    // Mapa que guarda cada ingrediente con su cantidad
    std::map<std::string, float> ingredientes;

public:
    // Agrega un ingrediente (si ya existe, suma la cantidad)
    void agregarIngrediente(const std::string& nombre, float cantidad);

    // Limpia todos los ingredientes guardados hasta el momento
    void limpiar();

    // Devuelve la lista de ingredientes para consultarlos
    const std::map<std::string, float>& obtenerIngredientes() const;

    // Muestra en pantalla los ingredientes guardados
    void mostrarIngredientes() const;
};

#endif
