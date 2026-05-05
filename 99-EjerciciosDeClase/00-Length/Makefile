# ─────────────────────────────────────────────
# Makefile para my_strlen rancio
# Uso:
#   make            → compila
#   make run        → compila y ejecuta
#   make debug      → compila con símbolos de debug
#   make clean      → elimina archivos generados
# ─────────────────────────────────────────────

CC      = gcc
CFLAGS  = -Wall -Wextra -O2 -std=c11
TARGET  = my_strlen
SRC     = my_strlen.c

# ── Compilación normal ────────────────────────

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
	@echo "Compilado querido querido: ./$(TARGET)"

# ── Ejecutar tests ────────────────────────────

run: $(TARGET)
	@echo "=== Ejecutando tests ===\n"
	@./$(TARGET)

# ── Debug (incluye símbolos para gdb) ─────────

debug: CFLAGS = -Wall -Wextra -g -std=c11
debug: clean $(TARGET)
	@echo "Binario listo para depurar con: gdb ./$(TARGET)"

# ── Limpieza ──────────────────────────────────

clean:
	rm -f $(TARGET)
	@echo "Ya limpie, Pa"
