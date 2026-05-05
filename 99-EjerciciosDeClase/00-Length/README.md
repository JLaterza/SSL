# Resumen Matemático de la función `strlen()` en C

## Definición Formal

La función `strlen` se define matemáticamente como:

$$
\text{strlen} : D \longrightarrow C
$$

---

## Dominio (Domain)

**Dominio** $D$:

$$
D = \{ \, s \in (\text{const char}^*) \mid s \text{ es una cadena válida terminada en } '\backslash 0' \,\}
$$

Es decir, todos los punteros a cadenas de caracteres **bien formadas** (con terminador nulo).

> **Nota**: Si la cadena no termina en `'\0'`, el puntero **no pertenece** al dominio y el comportamiento es indefinido.

---

## Codominio (Codomain)

**Codominio** $C$:

$$
C = \mathbb{N}_0 = \{0, 1, 2, 3, \dots \}
$$

En C está representado por el tipo **`size_t`** (entero sin signo).

---

## Definición Matemática

$$
\text{strlen}(s) = \min \{ k \in \mathbb{N}_0 \mid s_k = '\backslash 0' \}
$$

**Interpretación**: Devuelve el índice más pequeño $k$ donde aparece el carácter nulo.

### Definición Recursiva

$$
\text{strlen}(s) =
\begin{cases}
0 & \text{si } s_0 = '\backslash 0' \\
1 + \text{strlen}(s + 1) & \text{en otro caso}
\end{cases}
$$

---

## Propiedades Matemáticas

### 1. No negatividad

$$
\forall s \in D : \text{strlen}(s) \geq 0
$$

La longitud de una cadena nunca puede ser negativa. El caso mínimo es la cadena vacía.

### 2. Cadena vacía como elemento neutro de la longitud

$$
\text{strlen}(\texttt{""}) = 0
$$

La cadena vacía `""` tiene longitud 0. Es el único elemento del dominio con esta propiedad.

### 3. Monotonía bajo concatenación

Si $s = s_1 \| s_2$ (concatenación de dos cadenas), entonces:

$$
\text{strlen}(s) = \text{strlen}(s_1) + \text{strlen}(s_2)
$$

Esto refleja que la longitud es **aditiva**: concatenar dos cadenas suma sus longitudes.

> **Ejemplo**: `"Ga"` + `"to"` = `"Gato"` → $2 + 2 = 4$ ✓

### 4. Relación con el tamaño en memoria

$$
\text{sizeof\_en\_memoria}(s) = \text{strlen}(s) + 1
$$

El `+1` corresponde al carácter terminador `'\0'`, que **no** es contado por `strlen` pero **sí** ocupa espacio en memoria.

### 5. Inyectividad parcial (no es inyectiva)

`strlen` **no es inyectiva**: distintas cadenas pueden tener la misma longitud.

$$
\text{strlen}(\texttt{"Gato"}) = \text{strlen}(\texttt{"Perr"}) = 4
$$

Sin embargo, sí es posible agrupar cadenas por su longitud (clases de equivalencia).

---

## Casos Borde

### Caso 1: Cadena vacía `""`

```c
char str[] = "";
printf("%zu\n", strlen(str)); // 0
```

| Índice $k$ | 0    |
|------------|------|
| $s_k$      | `\0` |

El terminador nulo aparece en $k = 0$, por lo tanto $\text{strlen}(\texttt{""}) = 0$.

> ✅ Este es un caso **válido y bien definido**.

---

### Caso 2: Cadena con un solo carácter

```c
char str[] = "A";
printf("%zu\n", strlen(str)); // 1
```

| Índice $k$ | 0   | 1    |
|------------|-----|------|
| $s_k$      | `A` | `\0` |

$\text{strlen}(\texttt{"A"}) = 1$

---

### Caso 3: Puntero nulo (`NULL`)

```c
strlen(NULL); // ¡Comportamiento indefinido!
```

`NULL` **no pertenece al dominio** $D$. Pasar un puntero nulo a `strlen` provoca **comportamiento indefinido** (UB — *Undefined Behavior*), lo que en la práctica suele causar una violación de segmento (*segmentation fault*).

> ❌ **Nunca** llamar a `strlen(NULL)`. Si el puntero puede ser nulo, verificar antes:

```c
if (str != NULL) {
    size_t len = strlen(str);
}
```

---

### Caso 4: Cadena sin terminador nulo

```c
char str[3] = {'a', 'b', 'c'}; // Sin '\0'
strlen(str); // ¡Comportamiento indefinido!
```

Si la cadena no tiene `'\0'`, `strlen` sigue leyendo memoria más allá del arreglo hasta encontrar un byte nulo por casualidad. El resultado es impredecible.

> ❌ Este caso también está **fuera del dominio** y produce UB.

---

## Resumen en Tabla

| Elemento              | Notación Matemática                                              | Tipo en C         | Descripción                          |
|-----------------------|------------------------------------------------------------------|-------------------|--------------------------------------|
| **Dominio**           | $D \subseteq \text{const char*}$                                | `const char*`     | Cadenas terminadas en `'\0'`         |
| **Codominio**         | $\mathbb{N}_0$                                                  | `size_t`          | Enteros no negativos                 |
| **Definición**        | $\min\{k \in \mathbb{N}_0 \mid s_k = '\backslash 0'\}$         | Bucle `while`     | Posición del primer nulo             |
| **Valor máximo**      | $\leq \text{SIZE\_MAX}$                                         | `SIZE_MAX`        | Límite según arquitectura            |
| **Cadena vacía**      | $\text{strlen}(\texttt{""}) = 0$                                | `0`               | Caso mínimo válido                   |
| **Puntero nulo**      | $\text{NULL} \notin D$                                          | UB                | Comportamiento indefinido            |

---

## Ejemplo práctico: Cadena `"Gato"`

Consideremos la cadena:

```c
char str[] = "Gato";
```

Sus caracteres indexados son:

| Índice $k$ | 0   | 1   | 2   | 3   | 4    |
|------------|-----|-----|-----|-----|------|
| $s_k$      | `G` | `a` | `t` | `o` | `\0` |

El carácter nulo aparece en $k = 4$, por lo tanto:

$$
\text{strlen}(\texttt{"Gato"}) = 4
$$

---

## Propiedades Generales

- **Tiempo de ejecución**: $O(n)$ (lineal en la longitud de la cadena)
- **No cuenta** el carácter nulo `'\0'`
- El tamaño en memoria necesario es `strlen(s) + 1`
- Definida en la biblioteca estándar **`<string.h>`**

---

**Fuente**: Análisis matemático de la función estándar de la biblioteca `<string.h>`