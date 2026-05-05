#include <stdio.h>
#include <string.h>
#include <assert.h>

/* ─────────────────────────────────────────────────────────────
 * my_strlen: cuenta los caracteres de una cadena de forma
 * recursiva. Retorna 0 si la cadena es NULL o está vacía.
 * ───────────────────────────────────────────────────────────── */
size_t my_strlen(const char *s)
{
    if (s == NULL || *s == '\0')
        return 0;
    return 1 + my_strlen(s + 1);
}

/* ─────────────────────────────────────────────────────────────
 * check: verifica que my_strlen devuelve el resultado correcto.
 * Si falla, assert detiene el programa indicando la línea exacta.
 * ───────────────────────────────────────────────────────────── */
static void check(const char *s, const char *desc)
{
    size_t expected = s ? strlen(s) : 0;
    size_t got      = my_strlen(s);

    assert(got == expected);
    printf("  OK  %-30s --> %zu caracteres\n", desc, got);
}

/* ─────────────────────────────────────────────────────────────
 * main: ejecuta todos los casos de prueba.
 * ───────────────────────────────────────────────────────────── */
int main(void)
{
    printf("=== Pruebas de my_strlen ===\n\n");

    check("Hola mundo",    "cadena normal");
    check("",              "cadena vacía");
    check("A",             "un solo carácter");
    check("\t\n\r",        "caracteres de control");
    check("¿Cómo estás?",  "UTF-8 con acentos");
    check(NULL,            "puntero NULL");

    printf("\n Se completaron todas las pruebas.\n");
    return 0;
}