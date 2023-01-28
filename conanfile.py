from conans import ConanFile, tools  # type: ignore
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout  # type: ignore


class LibTmplConan(ConanFile):
    name = "libtmpl"
    url = "https://github.com/ryanmaguire/libtmpl"
    description = """This project is a collection of code written in C89/C90 (commonly called ANSI C) for mathematicians
     and physicists to use on various types of projects. It started with rss_ringoccs, a suite of tools written for
     processing the Cassini radio science data, which is written mostly in C (but also Python), but eventually grew
     beyond the scope of just astronomy.

     There are no dependencies other than a C compiler and the C standard library. The library is written entirely in
     ISO C89/C90 compliant code, and no C99/C11 or GCC extensions are used. It compiles with C99 and C11/C18 compilers,
     so it is more fitting to say it is written in the intersection of these standards."""

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "use_openmp": [True, False],
        "use_inline": [True, False],
        "use_tmpl_math": [True, False],
        "use_ieee_float": [True, False],
        "use_asm": [True, False],
        "use_builtin": [True, False],
        "use_fasm": [True, False],
        "use_longlong": [True, False],
        "use_int": [True, False],
        "c_standard": ["c89", "c99", "c11", "c17"]
    }
    default_options = {
        "use_openmp": True,
        "use_inline": True,
        "use_tmpl_math": True,
        "use_ieee_float": True,
        "use_asm": True,
        "use_builtin": True,
        "use_fasm": True,
        "use_longlong": True,
        "use_int": True,
        "c_standard": "c11"
    }

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def set_version(self):
        """
        Set the package version to the tag name, if available. Otherwise set to <branch>_<revision>.
        :return:
        """
        git = tools.Git(folder=self.recipe_folder)
        value = git.get_tag()
        if value is None:
            value = f"{git.get_branch()}_{git.get_revision()}"

        self.version = value

    def config_options(self):
        pass

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.definitions["LIBTMPL_USE_OMP"] = LibTmplConan.to_cmake_boolean(self.options.use_openmp)
        cmake.definitions["LIBTMPL_USE_INLINE"] = LibTmplConan.to_cmake_boolean(self.options.use_inline)
        cmake.definitions["LIBTMPL_USE_MATH"] = LibTmplConan.to_cmake_boolean(self.options.use_tmpl_math)
        cmake.definitions["LIBTMPL_USE_IEEE"] = LibTmplConan.to_cmake_boolean(self.options.use_ieee_float)
        cmake.definitions["LIBTMPL_USE_ASM"] = LibTmplConan.to_cmake_boolean(self.options.use_asm)
        cmake.definitions["LIBTMPL_USE_BUILTIN"] = LibTmplConan.to_cmake_boolean(self.options.use_builtin)
        cmake.definitions["LIBTMPL_USE_FASM"] = LibTmplConan.to_cmake_boolean(self.options.use_fasm)
        cmake.definitions["LIBTMPL_USE_LONGLONG"] = LibTmplConan.to_cmake_boolean(self.options.use_longlong)
        cmake.definitions["LIBTMPL_USE_INT"] = LibTmplConan.to_cmake_boolean(self.options.use_int)
        cmake.definitions["LIBTMPL_STDVER"] = "-std=" + self.options.c_standard
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["tmpl"]
        self.cpp_info.set_property("cmake_find_mode", "both")
        self.cpp_info.set_property("cmake_file_name", "Tmpl")
        self.cpp_info.set_property("cmake_target_name", "tmpl::tmpl")
        self.cpp_info.set_property("pkg_config_name", "tmpl")

    @classmethod
    def to_cmake_boolean(cls, value: bool) -> str:
        return "TRUE" if value else "FALSE"
