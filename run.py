
import subprocess

subprocess.call("gcc index.c -o index.go",shell=True)
subprocess.call("gcc api.c -o api.go",shell=True)
 
subprocess.call("emcc ./js/component.c -o ./js/componentc.js -s EXPORTED_FUNCTIONS=\"['_component']\"  -s RESERVED_FUNCTION_POINTERS=1",shell=True);