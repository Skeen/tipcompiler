import os
import sys
import string

Import(['env'])

def get_immediate_subdirectories(dir):
    return [name for name in os.listdir(dir)
            if os.path.isdir(os.path.join(dir, name))]

def GetSubDirs(env, sources):
    subdirs = get_immediate_subdirectories(sources)
    return subdirs

env.AddMethod(GetSubDirs, "GetSubDirs")
