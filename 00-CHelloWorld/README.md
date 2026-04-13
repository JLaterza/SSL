# Entrega Trabajo Práctico 0 - Hello World en C

## 🪄🪄🪄 Introducción 🪄🪄🪄

En este trabajo práctico se puede observar la implementación de un programa simple en lenguaje C que imprime 3 mensajes por pantalla, donde uno de ellos muestra la versión del lenguaje utilizada; posteriormente, los mensajes se guardan en un archivo llamado output.txt

---

## 🛠️🛠️🛠️ Compilador utilizado 🛠️🛠️🛠️

Utilicé el compilador **GCC (GNU Compiler Collection)** provisto por el entorno MSYS2 (MinGW64) en Windows.

---

## 🔢🔢🔢 Versión del compilador 🔢🔢🔢

La versión del compilador utilizada se obtiene ejecutando el siguiente comando:

```bash
gcc --version
```

Particularmente, obtuve la siguiente salida:

```text
gcc (Rev2, Built by MSYS2 project) 15.2.0
```

---

## 🔄️🔄️🔄️ Versión del lenguaje C 🔄️🔄️🔄️

Compilé el programa utilizando el estándar **C23**, lo cual esta explícitamente indicado con el flag:

```bash
-std=c23
```

Para verificar la versión del estándar, utilice el macro:

```c
__STDC_VERSION__
```

Finalmente, el programa imprimió el valor:

```text
202311
```

Lo que demuestra que corresponde al estándar **C23**.

---

## ⚙️⚙️⚙️ Proceso de compilación ⚙️⚙️⚙️

La compilación se realiza mediante la herramienta `make`, a través el siguiente comando:

```bash
make
```

Internamente, esto ejecuta:

```bash
C:/msys64/mingw64/bin/gcc -std=c23 -Wall -Wextra -pedantic hello.c -o hello.exe
```

---

## ▶️▶️▶️ Ejecución del programa ▶️▶️▶️

Para ejecutar el programa se utiliza:

```bash
make run
```

Este comando:

* Ejecuta el programa compilado (`hello.exe`)
* Muestra la salida en consola
* Guarda simultáneamente la salida en un archivo `output.txt`

Esto se logra mediante el uso de:

```bash
./hello.exe | tee output.txt
```

---

## 📄📄📄 Redirección de salida 📄📄📄

El archivo `output.txt` contiene la salida del programa, lo cual permite verificar los resultados sin necesidad de volver a ejecutar el binario.

---

## 📂📂📂 Estructura del proyecto 📂📂📂

```text
00-CHelloWorld/
│── hello.c
│── hello.exe
│── output.txt
│── Makefile
```

---

## ✅✅✅ Conclusión ✅✅✅

Entonces, puedo concluir que puedo...

* compilar un programa en C utilizando GCC
* utilizar el estándar C23
* verificar la versión del compilador y del lenguaje de forma simple
* automatizar la compilación y ejecución mediante `make`
* redirigir la salida del programa a un archivo
