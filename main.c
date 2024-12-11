#include <stdio.h>
#include "funciones.h"

int main() {
    struct Libro libros[20];
    int opc, i = 0;

    do {
        opc = menu();
        switch (opc) {
            case 1:
                registrarLibros(libros, i);
                i++;
                break;
            case 2:
                mostrarLibros(libros, i);
                break;
            case 3:
                {
                    int busq;
                    printf("Ingrese la opcion de busqueda: 1. Titulo, 2. ID\n");
                    scanf("%d", &busq);
                    buscarLibroId(libros, busq, i);
                }
                break;
            case 4:
                cambiarEstado(libros, i);
                break;
            case 5:
                eliminarLibro(libros, &i);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida, intente nuevamente.\n");
        }
    } while (opc != 6);

    return 0;
}
