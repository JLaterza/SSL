# =========================
# Compilador
# =========================
# Defino el compilador que voy a usar: GCC de MSYS2
CC = C:/msys64/mingw64/bin/gcc

# =========================
# Flags de compilación
# =========================
# Defino los flags que le paso al compilador para controlar el proceso de compilación
# -std=c23     → usar estándar C23
# -Wall        → warnings básicos
# -Wextra      → warnings adicionales
# -pedantic    → cumplimiento estricto del estándar
CFLAGS = -std=c23 -Wall -Wextra -pedantic

# =========================
# Nombre del ejecutable
# =========================
TARGET = hello

# =========================
# Regla por defecto
# =========================
# 'make' sin argumentos ejecuta esta regla
all: $(TARGET)

# =========================
# Regla de compilación
# =========================
# $<  → primer archivo dependiente (hello.c)
# $@  → nombre del target (hello)
# $hello: hello.c
# 	$C:/msys64/mingw64/bin/gcc -std=c23 -Wall -Wextra -pedantic hello.c -o hello.exe $< -o $hello.exe
$(TARGET): hello.c
	$(CC) $(CFLAGS) $< -o $(TARGET).exe

# =========================
# Ejecutar el programa
# =========================
# Depende de que el binario exista, también uso 'tee' para mostrar la salida en consola y guardarla en un archivo
run: $(TARGET)
	./$(TARGET).exe | tee output.txt

# =========================
# Forzar ejecución
# =========================
# Evito conflictos, si llegan a existir archivos con el mismo nombre...
.PHONY: all run clean run_to_file