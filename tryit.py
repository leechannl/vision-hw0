from uwimg import (
    clamp_image,
    copy_image,
    copy_image_bounds,
    hsv_to_rgb,
    load_image,
    rgb_to_grayscale,
    rgb_to_hsv,
    save_image,
    set_pixel,
    shift_image,
)

# 1. Getting and setting pixels
im = load_image("data/dog.jpg")
for row in range(im.h):
    for col in range(im.w):
        set_pixel(im, col, row, 0, 0)
save_image(im, "dog_no_red")

# 1.1 Showing the clamp padding strategy
im = load_image("data/dog.jpg")
copy_im_exbounds = copy_image_bounds(im, int(im.w * 2), int(im.h * 2))
save_image(copy_im_exbounds, "dog_copy_exbounds")
copy_im_shrink = copy_image_bounds(im, int(im.w * 0.5), int(im.h * 0.5))
save_image(copy_im_shrink, "dog_copy_shrink")

# 2. Copy image
im = load_image("data/dog.jpg")
copy_im = copy_image(im)
save_image(copy_im, "dog_copy")


# 3. Grayscale image
im = load_image("data/colorbar.png")
graybar = rgb_to_grayscale(im)
save_image(graybar, "graybar")

# 4. Shift Image
im = load_image("data/dog.jpg")
shift_image(im, 0, 0.4)
shift_image(im, 1, 0.4)
shift_image(im, 2, 0.4)
save_image(im, "overflow")

# 5. Clamp Image
clamp_image(im)
save_image(im, "doglight_fixed")

# 6-7. Colorspace and saturation
im = load_image("data/dog.jpg")
rgb_to_hsv(im)
shift_image(im, 1, 0.2)
clamp_image(im)
hsv_to_rgb(im)
save_image(im, "dog_saturated")
