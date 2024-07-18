"""setup.py: Set configurations of setuptools."""

from setuptools import Extension, setup

setup(
    ext_modules=[
        Extension(
            name="cmeta",
            sources=[
                "src/cmeta/cmeta.c",
            ],
        ),
    ],
)
