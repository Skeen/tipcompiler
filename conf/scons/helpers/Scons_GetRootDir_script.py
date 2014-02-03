import os

Import(['env'])

root_dir = Dir('#').srcnode().abspath

def GetRootDir(env, sources):
    return root_dir

env.AddMethod(GetRootDir, "GetRootDir")
