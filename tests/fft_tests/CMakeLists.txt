cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${TMPL_PARENT_DIR}/cmake")

find_package(FFTW3 REQUIRED)

project(fft_tests)

file(GLOB sources CONFIGURE_DEPENDS *.c)

foreach(source ${sources})
    cmake_path(GET source STEM app)
    list(APPEND test_apps ${app})
    add_executable(${app} ${source})
    set_target_properties(${app} PROPERTIES INTERPROCEDURAL_OPTIMIZATION ${IPO_SUPPORTED} C_STANDARD 11)
    target_include_directories(
        ${app} PUBLIC "${TMPL_PARENT_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}"
                      "$<TARGET_PROPERTY:FFTW3::fftw3,INTERFACE_INCLUDE_DIRECTORIES>"
    )
    target_link_libraries(${app} PRIVATE tmpl::tmpl FFTW3::fftw3)
    if(UNIX)
        target_link_libraries(${app} PRIVATE m)
    endif()

    add_test(NAME test_${app} COMMAND ${app})
endforeach()

include(GNUInstallDirs)
install(
    TARGETS ${test_apps}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
