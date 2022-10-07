# SierpinskiTriangles
Computing IV Small Project

This project simulates a Sierpinski recursive triangle by taking two command line arguments, side length and recursion depth, and then defining a drawable Triangle class that constructs an sf::Circle shape with three points sets the side length that is
given. The program recursively draws the triangles by calling function fTree() three
times, changing the center position to the points of the triangle drawn in the current call.
The program draws each triangle to the window, but I had to add a centerX and centerY
offset of 1⁄8 to the length when passing it to the recursive calls, because SFML draws
shapes off from the window edges by about 1⁄8 of the shape’s center. After I got the
function working, I added a color feature, which produces a gradient color effect,
because I set the color elements of each triangle to a proportion of its position.
However, the greatest centerX and centerY that can successfully create a color is 510
and 510, because the RGB elements of the pixel cannot exceed 255, and the
setFillColor() function sets the RGB elements to half of centerX and centerY.
