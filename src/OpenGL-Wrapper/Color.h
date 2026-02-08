#pragma once

struct Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    
    Color(unsigned char r, unsigned char g, unsigned char b):
        r(r), g(g), b(b), a(255)
    {

    }
    
    Color(unsigned char r, unsigned char g, unsigned  char b, unsigned char a):
        r(r), g(g), b(b), a(a)
    {

    }
};
