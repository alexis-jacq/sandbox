cmake_minimum_required(VERSION 2.8)

#Déclaration du projet
project(TestProject)

#Déclaration de l'exécutable
add_executable(test_executable	src/hello_main.cpp)
install(TARGETS test_executable	RUNTIME DESTINATION bin)
