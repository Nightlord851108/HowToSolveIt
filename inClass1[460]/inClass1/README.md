This is the Gauss-Jordan program written for the C++ class in spring 2017.
to build the program in bash:
make
to run the program in bash:
./utgj

used the following packages:
1. iamdone-atom for the task board that reflecting README.me
type cmd+shift+t to get a new terminal
2. the platformio-ide-terminal for the embedded terminal in Atom (invoke through the package menu)

In the README.md file, you'll put in the problem statement, tasks (#TODO), current tasks (#DOING), and tasks done (#DONE). This is great for HTSI: you need to breakdown a problem into tasks, and do each task until all tasks are done.

You can drag and drop a task to an adjacent lane. The number after ':' changes according to the order a task appears in the lane.

You journal after each entry:
#TASK:0 Gauss-Jordan
Gauss-Jordan and matrix inversion, making use of Vector and Matrix class defined in the project.
#TASK:10 2017-04-28 setup the project
write up the makefile, write up the test driver
#TASK:20 develop and test the Vector class
#TASK:30 Matrix
#TASK:40 x 2017-04-27 set up the the test harness
This only need to be done once. Following the instructions on (or investigate google results): http://ysonggit.github.io/system/2015/01/01/install-gtest-on-mac-os-yosemite.html

time to experiment journaling for before the class: you can also put images and other stuff in README.md. see https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet#images

The following entries are tasks for the problem Polygon.

#Problem: x 2017-04-30 (235m) Find the area and perimeter of a convex polygon in the plane.
#DONE:0 x 2017-04-29 2017-04-29 (20m) set up test harness and modify the makefile
put completed date before the created date
#DONE:90 x 2017-04-29 2017-04-29 (10m) test case for polygon - constructor and getters - vertices correctly ordered
#DONE:60 x 2017-04-29 2017-04-29 (20m) Polygon constructor and getters
#DONE:10 x 2017-04-29 2017-04-29 (20m) perimeter of triangle
added dist(Vector, Vector), first in Polygon.h and then moved to Vector.h
#DONE:20 x 2017-04-29 2017-04-29 (30m) area for triangle
EXPECT_EQ does not work on doubles: change to EXPECT_NEAR
added areaTriangle for area enclosed by three vectors in Vector.h
also added areaSquare with area 1

#DONE:30 x 2017-04-30 2017-04-29 (30m) create polygon from vectors, not necessarily sorted
test, and then creational method

#DONE:70 x 2017-04-30 2017-04-29 (60m) sort vertices around the centroid
and composition: compute centroid; compute angle around centroid wrt a ref vector (innerproduct, length of vector); crossProduct of two vectors; sorting a vector of pointers to Vector; comparator object using centroid and ref vector.

#DONE:80 x 2017-04-29 (20m) compute centroid for vectors
test and method
#DONE:50 x 2017-04-30 2017-04-30 (15m) cleanup Vector
method for gj has been moved to Matrix.

summary of experience 2017-04-30
Yes, HTSI works well with Atom with iamdone-atom and patformio-ide-terminal. The tasks are derived on the go: you have problem, then tasks, and then some tasks required further decomposition, for example, in creating a polygon from a set of vertices not necessarily sorted, we had to add methods to Vector (length, subtraction, angle, pointingOut, etc.) and Matrix (for example, getVecs [later replaced by moving sorting to Matrix, and make Polygon a client]). We also deleted some alternatives: for example, in the cleanup vector task, we removed code for computing Gauss-Jordan using system of vectors because the same functions were duplicated in Matrix.

In all, the problem solving process is seen as an AND/OR tree, the root is the problem, and AND node is a subproblem with further decomposition, and OR-node is an alternative solution. This means that we could keep an AND/OR tree of tasks: using color code for representing the state of the task (TODO, DOING, DONE). It could be useful to have a tool for this, or simply use a white board to draw the AND/OR tree of tasks.

Note that the successors of an AND node have dependencies. Use the tower of hanoi analogy for the Polygon creation, perimeter, and area. The latter two tasks can be coded up only after the first task is sufficiently completed. The Polygon creation is the largest disk, while perimeter and area are smaller and of the same size (mutually independent). By breaking up Polygon creation in two twi incremental tasks (vertices order and vertices unordered), we could quick get a whole picture by solving vertices ordered, perimeter, and area for the first iteration; then solving the vertices unordered as an increment iteration.

#DONE:40 x 2017-04-30 2017-04-30 (10m) cleanup Polygon and Matrix

#TASK:0 test imdone
sorting vertices is in Polygon, but it should be moved to Matrix.  

notes: use rm -f in make clean;
use wc -l *.cpp *.h to count locs.

linter-clang: lint tool for c++ (checks language rule conformances).
