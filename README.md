Aquí tienes un **README.md** pensado para GitHub y para enlazar en tu CV. Está escrito en tono profesional, explica el contexto académico, y deja claras las instrucciones de build/ejecución.

---

# The Fighting Game (C++ / SFML)

> Proyecto final de la asignatura **Programación Orientada a Objetos** (mi primera materia de programación en la carrera).
> Este fue **mi primer proyecto “real”**: lo primero que construí en código fuera de los ejercicios de clase.

![Main menu](docs/screenshot-main-menu.png)


---

## 🎮 Descripción

Un **juego de pelea 2D** hecho en C++ con **SFML**. Incluye:

* Menú principal (New Game / Options / Quit)
* Selección de personajes
* HUD/health bars, rounds y efectos de sonido
* Sprites animados (idle, walk, attack, jump, get hit, win/lose)
* Música/FX en menús y en combate

El objetivo principal del proyecto fue practicar **clases**, **encapsulamiento**, **estados/escenas**, y el manejo de **recursos** (imágenes, fuentes, audio) en una aplicación gráfica.

---

## 🧱 Stack & requisitos

* **Lenguaje:** C++17
* **Librería:** [SFML 2.5+](https://www.sfml-dev.org/) (graphics, window, system, audio)
* **Build system:** CMake
* **IDE recomendado:** Visual Studio Code (con CMake Tools)

**Ubuntu/Debian (paquetes):**

```bash
sudo apt update
sudo apt install -y build-essential cmake gdb libsfml-dev
```

---

## 📦 Estructura del proyecto

```
.
├─ assets/
│  ├─ audio/
│  │  ├─ music/
│  │  └─ sfx/
│  ├─ backgrounds/
│  ├─ fonts/
│  ├─ sprites/
│  └─ data/                # archivos .poo / .txt que persisten estado
├─ include/
│  ├─ Assets.h             # helper de rutas: asset("subcarpeta/archivo")
│  └─ …                    # headers del juego
├─ src/                    # código fuente del juego
├─ .vscode/                # config para F5 (opcional)
├─ CMakeLists.txt
└─ README.md
```

> El juego usa un helper (`include/Assets.h`) para cargar recursos desde `assets/...`.
> En runtime, CMake copia `assets/` a `build/assets`, por lo que las rutas funcionan al ejecutar desde `build/`.

---

## 🛠️ Compilar y ejecutar

### Opción 1 — VS Code

1. Instalar extensiones: **C/C++**, **CMake**, **CMake Tools**.
2. Abrir la carpeta del repo en VSCode y confiar en el workspace.
3. En la barra inferior: **Select a Kit** → GCC.
4. **Configure** → **Build**.
5. **Run and Debug** → *Run TheFightingGame (GDB)* → **F5**.

### Opción 2 — Terminal

```bash
# desde la raíz del proyecto
mkdir -p build
cd build
cmake ..
cmake --build .
./TheFightingGame
```

---

## ⌨️ Controles

Los controles se pueden ver dentro del juego (menú Options) y/o en `assets/data/Menu_Referencia_Botones.txt`.

> Nota: algunos bindings se leen/guardan en `assets/data/*.poo`.

---

## 🗂️ Datos persistentes

El juego lee/escribe archivos en `assets/data/`:

* `Controles_p1.poo`, `Controles_p2.poo` (controles por jugador)
* `Historial.poo` (resultados)
* `InfoPublicaJugadores.txt` (datos visibles en pantalla)

Se crean automáticamente si no existen.

---

## 📸 Capturas (opcional)

* `docs/screenshot-pj-choosing.png`
* `docs/screenshot-fight.png`
* `docs/controls-menu.png`

> Sube tus propias capturas a la carpeta `docs/` y se verán en el README.

---

## 🧭 Estado del código

Este repo **preserva la lógica original** del proyecto (primer trabajo de la carrera) y organiza solo lo necesario para compilar y ejecutar de forma moderna:

* Estructura de carpetas (`assets/`, `src/`, `include/`)
* CMake + configuración de VSCode
* Helper de rutas para recursos (`Assets.h`)


---


## 🏷️ Licencia / Créditos

Proyecto académico sin fines comerciales.
Algunos recursos (imágenes/fuentes/audio) podrían ser de terceros y se usan únicamente con fines educativos/demostrativos.

