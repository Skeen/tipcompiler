import os

# Get an instance to our environment
env = Environment()

# Enable automatic help generation
SConscript('conf/scons/Scons_Help_script.py', exports = ['env'])
# Help header and footer
env.jHelpHead("The following targets are supported;")
env.jHelpFoot("For additional information refer to the webpage.")

# Import the helpers
SConscript('conf/scons/helpers/Scons_GetSubDirs_script.py',   exports = ['env'])
SConscript('conf/scons/helpers/Scons_GetRootDir_script.py',   exports = ['env'])
SConscript('conf/scons/helpers/Scons_GetCurDir_script.py',   exports = ['env'])

# Import the targets
SConscript('conf/scons/Scons_Build_Src_script.py', exports = ['env'])
SConscript('tests/SConscript', exports = ['env'])

# Set the default target (compile the kernel, make image, run it)
env.Default('BuildCompiler')

# Generate the help target
env.jGenHelp()
