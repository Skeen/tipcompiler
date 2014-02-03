#!/usr/bin/env python
import os
import shutil
import urllib
import tarfile

from sys import exit

# Configuration variables
scons_url     = "http://prdownloads.sourceforge.net/scons/"
scons_name    = "scons-"
scons_version = "2.2.0"
scons_folder  = scons_name + scons_version
scons_tar     = scons_name + scons_version + ".tar.gz"
scons_tar_url = scons_url + scons_tar

tools_folder = os.getcwd() + '/tools/'
scons_build = tools_folder + 'scons/'

# Welcome
print("---------------------------------")
print("-Welcome to the SCons Setup Util-")
print("--Please Wait - While Building---")
print("---------------------------------")

# if SCons was already build simply return
if os.path.exists(scons_build):
    print("Already Built!")
    exit(1)

# Prepare tools folder
if not os.path.exists(tools_folder):
    os.makedirs(tools_folder)   

# Change to the tools folder
os.chdir(tools_folder)

# Check if we already have the tar
if not os.path.exists(scons_tar):
    print("Downloading Source...")
    urllib.urlretrieve(scons_tar_url, scons_tar)

# Check if we already have unpacked the tar
if not os.path.exists(scons_folder):
    print("Unpacking Source...")
    tarFile = tarfile.open(scons_tar)
    tarFile.extractall(".")

# Prepare SCons build folder
print("Building...")
if not os.path.exists(scons_build):
    os.makedirs(scons_build)

# Build SCons
os.chdir(scons_folder)
os.system("python setup.py install --prefix=" + scons_build + " > scons_build.log")

# Clean up
print("Cleaning up...")
os.chdir(tools_folder)
os.remove(scons_tar)
shutil.rmtree(scons_folder, ignore_errors=True)
# Everything went well
print("Everything went well!")
exit(0)
