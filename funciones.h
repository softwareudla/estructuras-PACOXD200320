struct Libro {
    int id;
    char titulo[100];
    char autor[50];
    int ano;
    char estado[20];
};

void registrarLibros(struct Libro libros[20], int i);
void mostrarLibros(struct Libro libros[20], int n);
void buscarLibroId(struct Libro libros[20], int busqueda, int n);
void cambiarEstado(struct Libro libros[20], int n);
void eliminarLibro(struct Libro libros[20], int *n);
int menu();