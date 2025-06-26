#include <iostream>
#include "../include/GestorIngredientes.h"
#include "../include/GestorRecetas.h"
#include "../include/Recetas.h"

int main() {
    std::cout << "=== TEST 2: SIN INGREDIENTES SUFICIENTES ===\n";

    GestorIngredientes gestorIng;
    GestorRecetas gestorRec;

    // Solo agregamos un ingrediente
    gestorIng.agregarIngrediente("azúcar", 1);

    // Cargar recetas
    cargarRecetasDesdeArchivo("recetas.txt", gestorRec);

    // Buscar recetas posibles
    auto posibles = gestorRec.buscarDisponibles(gestorIng.obtenerIngredientes());

    if (posibles.empty()) {
        std::cout << "No hay recetas disponibles (como se esperaba).\n";
    } else {
        std::cout << "ERROR: Se encontraron recetas, pero no debería haber ninguna.\n";
        for (const auto& r : posibles) {
            std::cout << "- " << r.getNombre() << "\n";
        }
    }

    return 0;
}
