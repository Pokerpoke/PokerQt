from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.scm import Git
from conan.tools.build import check_max_cppstd, check_min_cppstd
import os
from conan.tools.files import copy


class recipe(ConanFile):
    name = "PokerQt"
    version = "1.0.0"

    # Optional metadata
    license = ""
    author = "pokerpoke@qq.com"
    url = "https://github.com/Pokerpoke/PokerQt.git"
    description = "Base modules of autopilot integration"
    topics = ("<Put some tag here>", "<here>", "<and here>")

    # Binary configuration
    settings = ["os", "compiler", "build_type", "arch"]
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": True, "fPIC": True}

    def config_options(self):
        # self.settings.append("compiler.cppstd")
        if self.settings.os == "Windows":
            del self.options.fPIC

        self.options["qt"].qtsvg = True
        # self.options["qt"].compiler.cppstd = 17

    # def validate(self):
    # check_min_cppstd(self, "11")
    # check_min_cppstd(self, "20")

    def requirements(self):
        self.requires(
            "fmt/11.0.2",
            options={"shared": True},
        )
        self.requires(
            "spdlog/[>=1.15.0]",
            options={"shared": True},
        )
        self.tool_requires("ninja/[>=1.12.1]")
        self.tool_requires("cmake/[>=3.31.3]")
        self.test_requires("gtest/[>=1.15.0]")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self, generator="Ninja")
        tc.cache_variables["CMAKE_EXPORT_COMPILE_COMMANDS"] = "ON"
        tc.generate()

        # dep_pkgs = self.dependencies.host["spdlog"]
        # dep_pkgs.build_envinfo["SPDLOG_FMT_EXTERNAL"] = "ON"

        # print("dep_pkgs.build_envinfo: {}".format(dep_pkgs.build_envinfo))

    def source(self):
        git = Git(self)
        git.clone(url=self.url, target=".")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = []

    # def compatibility(self):
    #     if self.settings.build_type == "RelWithDebInfo":
    #         return [
    #             {
    #                 "settings": [
    #                     ("build_type", "Release"),
    #                     ("build_type", "RelWithDebInfo"),
    #                 ]
    #             }
    #         ]

    def deploy(self):
        copy(self, "*.dll", src=self.package_folder, dst=self.deploy_folder)
