
import subprocess

subprocess.call("gcc index.c -o index.go",shell=True)
subprocess.call("gcc api.c -o api.go",shell=True)

#subprocess.call("emcc ./js/state.c -Os -s WASM=1 -s SIDE_MODULE=1 -o state.wasm ",shell=True);