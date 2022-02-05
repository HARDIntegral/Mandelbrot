import py_mand
import png
import sys

width = int(sys.argv[1])
height = int(sys.argv[2])

png.from_array(py_mand.plot(width, height, 50), 'L').save("test.png")
