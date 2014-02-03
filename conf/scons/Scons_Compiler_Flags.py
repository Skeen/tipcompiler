# Default flags for Joos2Compiler's build, per architecture
# C++ compiler flags
cxx_flags = ' --std=c++11 -Og -g3 '

# Warning flags (that force us to write betterish code)
warning_flags = ' -Wfatal-errors -Wall -Wextra -Werror -Wpointer-arith -Wcast-align \
                  -Wwrite-strings -Wno-long-long -Wno-variadic-macros -Wno-unused \
                  -Wno-unused-variable -Wno-conversion -Wno-format -Wno-empty-body '

# Language-specific warnings
warning_flags_c = '-Wnested-externs '
warning_flags_cxx = '-Wold-style-cast '

# OUTPUT FLAGS
CFLAGS = warning_flags + warning_flags_c
CXXFLAGS = cxx_flags + warning_flags + warning_flags_cxx
