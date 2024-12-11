#include <stdio.h>
#include <string.h>
#include "funciones.h"

void registrarLibros(struct Libro libros[20], int i) {
    int len;
    libros[i].id = i + 1;
    printf("La ID del libro es %d\n", libros[i].id);
    printf("Ingrese el titulo del libro: ");
    fflush(stdin);
    fgets(libros[i].titulo, 100, stdin);
    len = strlen(libros[i].titulo) - 1;
    libros[i].titulo[len] = '\0';
    printf("Ingrese el autor del libro: ");
    fflush(stdin);
    fgets(libros[i].autor, 50, stdin);
    len = strlen(libros[i].autor) - 1;
    libros[i].autor[len] = '\0';
    printf("Ingrese el ano del libro: ");
    scanf("%d", &libros[i].ano);
    strcpy(libros[i].estado, "Disponible");
}

void mostrarLibros(struct Libro libros[20], int n) {
    printf("ID\tTitulo\t\t\tAutor\t\t\tAno\tEstado\n");
    for (int i = 0; i < n; i++) {
        if (libros[i].id != 0) {
            printf("%d\t%-20s\t%-20s\t%d\t%s\n", libros[i].id,
                   libros[i].titulo,
                   libros[i].autor,
                   libros[i].ano,
                   libros[i].estado);
        }
    }
}

void buscarLibroId(struct Libro libros[20], int busqueda, int n) {
    char busquedan[100];
    int len, id, encontrado = 0;

    if (busqueda == 1) {
        printf("Ingrese el titulo del libro que desea buscar: ");
        fflush(stdin);
        fgets(busquedan, 100, stdin);
        len = strlen(busquedan) - 1;
        busquedan[len] = '\0';

        for (int i = 0; i < n; i++) {
            if (strcasecmp(libros[i].titulo, busquedan) == 0) {
                printf("ID: %d\tTitulo: %s\tAutor: %s\tAno: %d\tEstado: %s\n",
                       libros[i].id, libros[i].titulo, libros[i].autor,
                       libros[i].ano, libros[i].estado);
                encontrado = 1;
            }
        }
    } else if (busqueda == 2) {
        printf("Ingrese la ID del libro que desea buscar: ");
        scanf("%d", &id);

        for (int i = 0; i < n; i++) {
            if (libros[i].id == id) {
                printf("ID: %d\tTitulo: %s\tAutor: %s\tAno: %d\tEstado: %s\n",
                       libros[i].id, libros[i].titulo, libros[i].autor,
                       libros[i].ano, libros[i].estado);
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("El libro no se encuentra.\n");
    }
}

void cambiarEstado(struct Libro libros[20], int n) {
    int id, encontrado = 0;

    printf("Ingrese la ID del libro que desea cambiar el estado: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (libros[i].id == id) {
            printf("Estado actual: %s\n", libros[i].estado);
            printf("Seleccione el nuevo estado: 1. Disponible, 2. Ocupado\n");
            int nuevoEstado;
            scanf("%d", &nuevoEstado);

            if (nuevoEstado == 1) {
                strcpy(libros[i].estado, "Disponible");
            } else if (nuevoEstado == 2) {
                strcpy(libros[i].estado, "Ocupado");
            } else {
                printf("Estado no válido.\n");
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("El libro no se encuentra.\n");
    }
}

void eliminarLibro(struct Libro libros[20], int *n) {
    int id, encontrado = 0;

    printf("Ingrese la ID del libro que desea eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < *n; i++) {
        if (libros[i].id == id) {
            libros[i].id = 0; // Marcar como eliminado
            printf("Libro eliminado con exito.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("El libro no se encuentra.\n");
    }
}

int menu() {
    int opcion;
    printf("\n--- Menu ---\n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro\n");
    printf("4. Cambiar estado de libro\n");
    printf("5. Eliminar libro\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}