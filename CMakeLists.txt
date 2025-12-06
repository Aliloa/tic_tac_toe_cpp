# Version minimale de CMake
cmake_minimum_required(VERSION 3.20)

# Nom du projet
project(TIC_TAC_TOE)

# Crée l'exécutable
add_executable(${PROJECT_NAME})

# Utiliser C++20
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# Dossier de sortie pour l'exécutable
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}
)

# Ajouter tous les fichiers sources du dossier src
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS src/*)
target_sources(${PROJECT_NAME} PRIVATE ${MY_SOURCES})

# Ajouter le dossier src comme include
target_include_directories(${PROJECT_NAME} PRIVATE src)
