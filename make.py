#!/usr/bin/env python
import sys
sys.path.append('conf/scons/')

from Scons_Make_Helper import *

scons_executeable = "scons"

# Remove the first arg (./make.py)
passed_arguments = sys.argv[1:]
# Make a string of the arguments list
passed_arguments_string = " ".join(passed_arguments)
# Run scons without building anything, in order to generate a dependency tree
# execute(scons_executeable + " --tree=prune,derived -Q --dry-run -j %d %s > depends.log" % (cores(), passed_arguments_string))
# Execute scons with our arguments
# We cannot run this multicore, due to issues with scons
execute(scons_executeable + " -j %d %s" % (cores(), passed_arguments_string))

