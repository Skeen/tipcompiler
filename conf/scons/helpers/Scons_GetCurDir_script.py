import os

Import(['env'])

def GetCurDir(env, sources):
    current_dir = Dir('.').srcnode().abspath
    return current_dir

env.AddMethod(GetCurDir, "GetCurDir")
