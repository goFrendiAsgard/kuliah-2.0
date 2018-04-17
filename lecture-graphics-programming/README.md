# Outline

* Coordinate System
* Transformation
* Circle
* Animation
* Texture
* Lighting

# Install OpenGL

* `sudo apt-get install g++ mesa-common-dev freeglut3-dev`
* `g++ <your-file.cpp> -o <executable-name> -lglut -lGL -lGLU`

# Matrix Multiplication

```
|a b c|  |g j|  =  |ag+bh+ci  aj+bk+cl|
|d e f|  |h k|     |dg+dh+di  dj+ek+fl|
         |i l|
```

# 3D Transformation Matrix

## Translation (l,m,n)

```
1 0 0 l
0 1 0 m
0 0 1 n
0 0 0 1
```

## Rotation (angle, l, m, n)

```
ll (1-cos(angle)) + cos(angle)    ml (1-cos(angle)) - sin(angle)    nl (1-cos(angle)) + m sin(angle)  0
lm (1-cos(angle)) + n sin(angle)  mm (1-cos(angle)) + cos(angle)    nm (1-cos(angle)) - l sin(angle)  0
ln (1-cos(angle)) - m sin(angle)  mn (1-cos(angle)) + l sin(angle)  nn (1-cos(angle)) + cos(angle)    0
0                                 0                                 0                                 1
```

## Rotation-x(angle)

```
1  0           0            0
0  cos(angle)  -sin(angle)  0
0  sin(angle)  cos(angle)   0
0  0           0            1
```

## Rotation-y(angle)

```
cos(angle)   0  sin(angle)  0
0            1  0           0
-sin(angle)  0  cos(angle)  0
0            0              1
```

## Rotation-z(angle)

```
cos(angle)  -sin(angle)  0  0
sin(angle)  cos(angle)   0  0
0           0            1  0
0           0            0  1
```

# Trigonometry

```
      0       30      45      60      90
sin   0       1/2     1/2 V2  1/2 V3  1
cos   1       1/2 V3  1/2 V2  1/2     0
tan   0       1/3 V3  1       V3      undefined
```

## Formulas

```
y^2 + x^2 = r^2
sin(angle) = y/r
cos(angle) = x/r
tan(angle) = y/x = sin(angle)/cos(angle)
sin(angle) = cos(180-angle)
cos(angle) = sin(180-angle)
```

### For 90 <= angle <= 180

```
sin(180-angle) = sin (angle)
cos(180-angle) = -cos (angle)
tan(180-angle) = -tan (angle)
```

### For 180 <= angle <= 270

```
sin(180+angle) = -sin (angle)
cos(180+angle) = -cos (angle)
tan(180+angle) = tan (angle)
```

### For 270 <= angle <= 360

```
sin(360-angle) = -sin (angle)
cos(360-angle) = cos (angle)
tan(360-angle) = -tan (angle)
```

# Links

* [https://www.codeproject.com/articles/182109/setting-up-an-opengl-development-environment-in-ub](https://www.codeproject.com/articles/182109/setting-up-an-opengl-development-environment-in-ub)
* [https://stackoverflow.com/questions/17766420/linker-error-undefined-reference-to-symbol-glortho#17766529](https://stackoverflow.com/questions/17766420/linker-error-undefined-reference-to-symbol-glortho#17766529)
* [https://www.opengl.org/archives/resources/code/samples/glut_examples/examples/examples.html](https://www.opengl.org/archives/resources/code/samples/glut_examples/examples/examples.html)
* [http://www.glprogramming.com/red/](http://www.glprogramming.com/red/)
* [http://www.opengl-tutorial.org/beginners-tutorials/tutorial-1-opening-a-window/](http://www.opengl-tutorial.org/beginners-tutorials/tutorial-1-opening-a-window/)
* [https://stackoverflow.com/questions/17957325/how-do-i-install-a-current-version-of-opengl-for-windows-c](https://stackoverflow.com/questions/17957325/how-do-i-install-a-current-version-of-opengl-for-windows-c)
* [https://www.ntu.edu.sg/home/ehchua/programming/opengl/CG_Examples.html](https://www.ntu.edu.sg/home/ehchua/programming/opengl/CG_Examples.html)
* [https://en.wikipedia.org/wiki/Transformation_matrix](https://en.wikipedia.org/wiki/Transformation_matrix)
