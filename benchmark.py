"""
    Build and run all programs. If a program fails to build or run, it is
    discarded.

    Usage:

    $python3 benchmark.py
"""

import os
import subprocess
import pathlib
import shutil

# CPU
os.chdir(os.path.dirname(os.path.abspath(__file__)) + "/cpu")
subprocess.check_call(["cargo", "build", "--release"])
