struct estudiante {
  unsigned int matr;
  char* pe;
  unsigned int c; // access counter
};

typedef struct estudiante alumno;

void imprime(alumno*); // it now uses a pointer
