# Mandelbrot-Set-Img
> ### My attempt at writing a programme that generates an image of the Mandelbrot Set.

#### This code will generate an image (in .ppm format) of the Mandelbrot Set. The size of the image, and all other parameters can be modified directly in the source code or type in while the programme is running. Command line arguments are being added.

## What is the Mandelbrot Set?
 According to [Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set):
> *The Mandelbrot set is the set of complex numbers c for which the function f_{c}(z)=z^2 + c does not diverge when iterated from z = 0, i.e., for which the sequence f_{c}(0), f_{c}(f_{c}(0)), etc., remains bounded in absolute value.*

## How to plot the Mandelbrot Set?
[Wiki how](https://www.wikihow.com/Plot-the-Mandelbrot-Set-By-Hand) has good examples of this.

Basically:
* You __take one pixel__ in the image and __convert__ the coordinate of that pixel (an image is a matrix of pixels) __into__ the __complex coordinate plane__.
* And then pass those complex coordinates to a function that __checks__ whether __that position__ in the complex coordinate plane __belongs to the Mandelbrot Set__.
  * If __it does__, __return black value__ of the pixel.
  * If __it doesn't__, __return white value__ of the pixel.
> *(it doesn't matter which colour value to return, the choice is up to you, as long as it's two distinguishable colour values, one for value in the Mandelbrot set and one for the one that isn't)*.
>
> * And then just __repeat__ all the __above steps__ for __all the pixels__ in the image.
> (Hope I explained it clear enough)

About the __function__ that __checks__ whether a position in the complex plane __belongs to the Mandelbrot Set__, it just __does__ a lot of __iterations__ to __check if__ the given coordinates __satisfy__
> the function f_{c}(z)=z^2 + c does not diverge when iterated from z = 0

and we can specify the number of iteration. The __more__ the number of __iteration__. the __more detail__ the Mandelbrot is and the __more time__ it'll take __to render__ the image.

Do some __researches__ yourself on how to __convert pixel coordinates to complex coordinate__.

## Some of the Mandelbrot Set images
__*Note: The image generated by this code might not be as beautiful as in these images below... yet*__

![](https://upload.wikimedia.org/wikipedia/commons/2/21/Mandel_zoom_00_mandelbrot_set.jpg)

![](https://1.bp.blogspot.com/-6TyE_n-7w28/TtdyiumCmLI/AAAAAAAAA5Q/0ZXOG44qsuk/s1600/Mandel_zoom_07_satellite.jpg)

![](https://i.pinimg.com/originals/6e/e5/68/6ee568e2dac803d223338b77d4542151.jpg)

![](https://i.redd.it/12z4i9t8l1f11.png)

You can search on Youtube for "Mandelbrot zoom" videos. Those are really satisfying to watch. :smile:

## What is the .PPM format?
It's the __simplest__, __lossless__ image format. Basically, it's just a file that __stores pixel__ data __using texts__ rather than binary. Therefore, the __file size__ is much __larger__, and it __doesn't provide__ any __compression__ so the bigger the image size, the greater the file size. As a result, the file will __take longer to write__ to storage device if it gets too big. However, because it's using text to encode pixel data, it's much more __readable to human__. You could just simply open a .PPM file with Notepad and modify any pixels you want. Read more about .PPM format [here on Wikipedia](https://en.wikipedia.org/wiki/Netpbm).

I chose this format because it's simple, easy to implement and I don't have to use any other librabies, which I'm not good at using.
