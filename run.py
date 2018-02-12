
import subprocess
import shutil
import os

subprocess.call("gcc ./lib/index.c -o index.go",shell=True)
subprocess.call("gcc ./lib/api.c -o api.go",shell=True)

dist = './js/'
pRoute = dist + 'route.js'
pComponent = dist + 'component.js'

if not os.path.exists(dist):
    os.makedirs(dist)

if os.path.isfile (pComponent): 
    os.remove(pComponent)

if os.path.isfile (pRoute): 
    os.remove(pRoute)

subprocess.call("emcc ./core_c/component.c -o {0} -s EXPORTED_FUNCTIONS=\"['_component']\"  -s RESERVED_FUNCTION_POINTERS=1".format(pComponent),shell=True);
shutil.copyfile('./core_c/route.js', pRoute)

#shutil.copyfile('./core_js/component.js', pComponent)
#shutil.copyfile('./core_js/route.js', pRoute)