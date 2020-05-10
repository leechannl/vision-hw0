#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    // clamp padding strategy
    if (x > im.w)
    {
        x = im.w;
    }
    if (x < 0)
    {
        x = 0;
    }
    if (y > im.h)
    {
        y = im.h;
    }
    if (y < 0)
    {
        y = 0;
    }
    if (c > im.c)
    {
        c = im.c;
    }
    if (c < 0)
    {
        c = 0;
    }

    return im.data[x + im.w * y + im.w * im.h * c];
}

void set_pixel(image im, int x, int y, int c, float v)
{
    // checking bounds
    if (x > im.w || x < 0 || y > im.h || y < 0 || c > im.c || c < 0)
    {
        return;
    }

    im.data[x + im.w * y + im.w * im.h * c] = v;
}

image copy_image_bounds(image im, int width, int height)
{
    image copy = make_image(width, height, im.c);

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            for (int k = 0; k < im.c; k++)
            {
                set_pixel(copy, i, j, k, get_pixel(im, i, j, k));
            }
        }
    }

    return copy;
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);

    for (int i = 0; i < im.w; i++)
    {
        for (int j = 0; j < im.h; j++)
        {
            for (int k = 0; k < im.c; k++)
            {
                set_pixel(copy, i, j, k, get_pixel(im, i, j, k));
            }
        }
    }

    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    // TODO Fill this in
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
}

void clamp_image(image im)
{
    // TODO Fill this in
}

// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
