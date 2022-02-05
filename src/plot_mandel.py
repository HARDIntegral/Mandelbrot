import py_mand
import png

png.from_array(py_mand.plot(60000, 40000, 50), 'L').save("test.png")
