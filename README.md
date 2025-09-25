# The Fighting Game (C++ / SFML)

> Final project for **Object-Oriented Programming** — my first programming course at university.
> This was my **first real project** beyond classroom practice exercises.

![MainMenu](docs/screenshot-main-menu.png)

## 🎮 Overview

A **2D fighting game** built in C++ with **SFML** featuring:

* Main menu (New Game / Options / Quit)
* Character selection
* HUD / health bars, rounds, and sound effects
* Animated sprites (idle, walk, attack, jump, get hit, win/lose)
* Music/SFX for menus and battles

The core learning goals were practicing **classes**, **encapsulation**, **state/scene management**, and **resource loading** (images, fonts, audio) in a graphical application.

---

## 🧱 Tech Stack & Requirements

* **Language:** C++17
* **Library:** [SFML 2.5+](https://www.sfml-dev.org/) (graphics, window, system, audio)
* **Build system:** CMake
* **Recommended IDE:** Visual Studio Code (with CMake Tools)

**Ubuntu/Debian setup:**

```bash
sudo apt update
sudo apt install -y build-essential cmake gdb libsfml-dev
```

---

## 📦 Project Structure

```
.
├─ assets/
│  ├─ audio/
│  │  ├─ music/
│  │  └─ sfx/
│  ├─ backgrounds/
│  ├─ fonts/
│  ├─ sprites/
│  └─ data/                # .poo / .txt files for persisted state
├─ include/
│  ├─ Assets.h             # path helper: asset("subfolder/file")
│  └─ …                    # game headers
├─ src/                    # game sources
├─ .vscode/                # F5 run/debug config (optional)
├─ CMakeLists.txt
└─ README.md
```

> The game uses `include/Assets.h` to load resources from `assets/...`.
> At runtime, CMake copies `assets/` into `build/assets`, so relative paths work when running from `build/`.

---

## 🛠️ Build & Run

### Option 1 — VS Code

1. Install extensions: **C/C++**, **CMake**, **CMake Tools**.
2. Open the repo folder in VS Code and trust the workspace.
3. Bottom status bar: **Select a Kit** → GCC.
4. **Configure** → **Build**.
5. **Run and Debug** → *Run TheFightingGame (GDB)* → **F5**.

### Option 2 — Terminal

```bash
# from the project root
mkdir -p build
cd build
cmake ..
cmake --build .
./TheFightingGame
```

---

## ⌨️ Controls

Controls are shown in-game (Options menu) and/or in `assets/data/Menu_Referencia_Botones.txt`.

> Note: some bindings are read/written under `assets/data/*.poo`.

---

## 🗂️ Persisted Data

The game reads/writes data under `assets/data/`:

* `Controles_p1.poo`, `Controles_p2.poo` (per-player controls)
* `Historial.poo` (results/history)
* `InfoPublicaJugadores.txt` (values shown on screen)

Files are created automatically if missing.

---

## 📸 Screenshots


![Character selection](docs/screenshot-pj-choosing.png)
![Fight](docs/screenshot-fight.png)
![Controls menu](docs/controls-menu.png)

---

## 🧭 Code Status

This repository **preserves the original logic** from my first-year OOP final project, with only minimal organization to build and run smoothly today:

* Folder layout (`assets/`, `src/`, `include/`)
* CMake + VS Code configuration
* Asset path helper (`Assets.h`)
* Safe handling of data files (auto-create if missing)

---


## 🏷️ License / Credits

Academic, non-commercial project.
Some assets (images/fonts/audio) may be third-party and are used for educational/demo purposes only.

