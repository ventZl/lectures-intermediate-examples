#pragma once

struct Point2D {
    Point2D(int _x, int _y): x{_x}, y{_y} {}


    int x, y;
};

struct ColorRGB {
    ColorRGB(unsigned _r, unsigned _g, unsigned _b): r{_r}, g{_g}, b{_b} {}

    unsigned r, g, b;
};

inline void rect(Point2D corner1, Point2D corner2, ColorRGB fill) {}
