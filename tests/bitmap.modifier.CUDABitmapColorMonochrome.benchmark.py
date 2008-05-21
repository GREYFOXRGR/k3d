#python

import testing
import k3d

# benchmark the CUDABitmapColorMonochrome plugin as well as the BitmapColorMonochrome plugin for comparative purposes
testing.bitmap_benchmark("CUDABitmapColorMonochrome", (640,480), 10)
testing.bitmap_benchmark("BitmapColorMonochrome", (640,480), 10)

testing.bitmap_benchmark("CUDABitmapColorMonochrome", (800,600), 10)
testing.bitmap_benchmark("BitmapColorMonochrome", (800,600), 10)

testing.bitmap_benchmark("CUDABitmapColorMonochrome", (1024,768), 10)
testing.bitmap_benchmark("BitmapColorMonochrome", (1024,768), 10)

testing.bitmap_benchmark("CUDABitmapColorMonochrome", (1280,1024), 10)
testing.bitmap_benchmark("BitmapColorMonochrome", (1280,1024), 10)

