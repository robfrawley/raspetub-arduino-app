
##
## This file is part of the `src-run/raspetub-arduino-app` package.
##
## (c) Rob Frawley 2nd <rmf@src.run>
##
## For the full copyright and license information, view the LICENSE.md
## file distributed with this source code.
##

Import("env")
Import("projenv")

# output banner
print("\n###\n###\n### [BEGIN] builder_post-append-build-flags.py\n###\n###\n\n")

# append to ccflags and cxx flags
#env.Append(CCFLAGS=["-std=c++17", "-std=gnu++17"])
env.Append(CXXFLAGS=["-std=c++17", "-std=gnu++17"])

# access to global construction environment
#print(env)

# access to project construction environment
#print(projenv)

# Dump construction environments (for debug purpose)
#print(env.Dump())
#print(projenv.Dump())

# output banner
print("\n###\n###\n### [CLOSE] builder_post-append-build-flags.py\n###\n###\n\n")
