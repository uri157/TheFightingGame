cmake_minimum_required(VERSION 3.16)
project(TheFightingGame CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Rutas
set(SRC_DIR     "${CMAKE_SOURCE_DIR}/src")
set(INC_DIR     "${CMAKE_SOURCE_DIR}/include")
set(ASSETS_DIR  "${CMAKE_SOURCE_DIR}/assets")

# Fuentes (TODOS los .cpp)
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")

# ⚠️ Tienes main.cpp y main2.cpp. Si compila y te dice "multiple definition of `main`",
# comenta UNA de estas dos líneas según el que quieras usar.
# list(FILTER SRC_FILES EXCLUDE REGEX ".*/main2\\.cpp$")
# list(FILTER SRC_FILES EXCLUDE REGEX ".*/main\\.cpp$")

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIR})

# SFML
find_package(SFML 2.5 REQUIRED COMPONENTS system window graphics audio)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics sfml-audio)
target_compile_definitions(${PROJECT_NAME} PRIVATE USE_SFML)

# Copia assets al directorio de build (para que las rutas 'assets/...'
# funcionen igual al ejecutar desde build/)
set(OUTPUT_ASSETS_DIR "${CMAKE_CURRENT_BINARY_DIR}/assets")
add_custom_target(copy_assets ALL
  COMMAND ${CMAKE_COMMAND} -E rm -rf "${OUTPUT_ASSETS_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${ASSETS_DIR}" "${OUTPUT_ASSETS_DIR}"
  COMMENT "Copiando assets a la carpeta de build..."
)
add_dependencies(${PROJECT_NAME} copy_assets)
