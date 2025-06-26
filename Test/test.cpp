#include <iostream>
#include "../include/GestorIngredientes.h"
#include "../include/GestorRecetas.h"
#include "../include/Recetas.h"

int main() {
    std::cout << "=== TEST DE CHEF VIRTUAL ===\n";

    // Crear gestores
    GestorIngredientes gestorIng;
    GestorRecetas gestorRec;

    // Agregar ingredientes de prueba
    gestorIng.agregarIngrediente("huevo", 2);
    gestorIng.agregarIngrediente("aceite", 1);
    gestorIng.agregarIngrediente("sal", 1);

    // Cargar recetas desde el archivo
    cargarRecetasDesdeArchivo("recetas.txt", gestorRec);

    // Buscar recetas disponibles
    auto posibles = gestorRec.buscarDisponibles(gestorIng.obtenerIngredientes());

    // Mostrar resultados
    std::cout << "\nRecetas disponibles con los ingredientes cargados:\n";
    for (const auto& r : posibles) {
        std::cout << "- " << r.getNombre() << "\n";
    }

    return 0;
}
