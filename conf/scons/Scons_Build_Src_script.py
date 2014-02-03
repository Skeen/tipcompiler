# -*- coding: utf-8 -*-
Import(['env'])

env['BUILDDIR'] = "#build/src"

from Scons_Compiler_Flags import *

env.Append(CFLAGS=CFLAGS)
env.Append(CXXFLAGS=CXXFLAGS)

# Recursive build all
SConscript('#src/SConscript', variant_dir = env['BUILDDIR'], exports = ['env'], duplicate = 0)
