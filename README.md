# miniRT

A small ray tracer written in **C** for the 1337 (42 Network) curriculum.
It reads a scene file and renders a 3D image with ray tracing.

<!-- TODO: add a screenshot of your best render here:
![miniRT render](images/render.png) -->

---

##  Features

- Ray-object intersections for **sphere**, **plane**, and **cylinder**
- **Phong lighting**: ambient, diffuse, and specular light
- Scene file parsing with error messages for a wrong file
<!-- TODO: keep only what is TRUE for your project, and add the rest:
- Shadows
- Camera with field of view
- Window events (close with ESC and the window cross)
- Bonus: [colors, textures, cone, multiple lights...] -->

---

##  How it works

1. **Parse** the `.rt` scene file (ambient light, camera, lights, objects).
2. For each pixel, **shoot a ray** from the camera through the screen.
3. Find the **closest object** the ray hits (sphere, plane, or cylinder math).
4. Compute the **color** at the hit point with Phong lighting.
5. Draw the pixel in the window.

---

##  Build and run

```bash
git clone https://github.com/Lallasb/_miniRT.git
cd miniRT
make
./miniRT scene/example.rt
```

Other Makefile rules:

```bash
make clean    # remove object files
make fclean   # remove object files and the executable
make re       # rebuild everything
```

<!-- TODO: check these match your Makefile. Add the libraries you need
(example: MiniLibX, math library) and the system you tested on (Linux). -->

---

## 📄 Scene file format

```
A  0.2  255,255,255                      # ambient: ratio, color
C  0,0,-10  0,0,1  70                    # camera: position, direction, FOV
L  -10,10,-10  0.7  255,255,255          # light: position, brightness, color
sp 0,0,20  10  255,0,0                   # sphere: center, diameter, color
pl 0,-5,0  0,1,0  200,200,200            # plane: point, normal, color
cy 5,0,20  0,1,0  8  15  0,0,255         # cylinder: center, axis, diameter, height, color
```

<!-- TODO: change this to match your real format and subject version. -->

---

##  What I learned

- The math behind **ray-sphere and ray-cylinder intersection**
- How **Phong lighting** gives an object its shape and brightness
- Writing a **robust parser**: fixing bugs like memory reallocation per line,
  off-by-one errors, and axis vectors that were not normalized
- Managing memory in C with no leaks

---

