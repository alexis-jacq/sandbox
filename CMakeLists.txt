cmake_minimum_required(VERSION 2.8)

#Déclaration du projet
project(SandBox)

find_package(OpenCV REQUIRED )

include_directories(${OpenCV_INCLUDE_DIRS})

#Déclaration de l'exécutable
add_executable(sandbox	src/image.cpp)
target_link_libraries(sandbox ${OpenCV_LIBS})


install(TARGETS sandbox	RUNTIME DESTINATION bin)

file(GLOB_RECURSE images share/*)

install(FILES
        ${images}
        DESTINATION share/${PROJECT}
)
