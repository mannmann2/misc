# Some examples and utility functions to work with the Mandelbrot set
# by Mario dos Reis. -- October 2003

# First lets load these complementary functions, they will be used later on

# plot zooming function
zoom <- function(col = c(heat.colors(49), "black"),
                 nx = 600, ny = 600, iter = 0, plot = TRUE, inv = TRUE)
{

  coo <- locator(2)

  coo$y[2] = coo$y[1] + diff(range(coo$x))

  if(iter == 0) # not working well yet!
    iter <- 50 + 1 / diff(range(coo$x))

  frac <- mandelbrot(x = coo$x, y = coo$y, nx = nx, ny = ny, iter = iter)

  rect(coo$x[1], coo$y[1], coo$x[2], coo$y[2], lwd = 2, border = 'red')

  if(inv) image(x = frac$x, y = frac$y, z = -1/frac$z, col = col)
  else    image(frac, col = col)

  invisible(frac)
}

# this is for coloring persp plots
surf.colors <- function(x, col = terrain.colors(20)) {

  if(is.list(x)) x = x$z

  # First we drop the 'borders' and average the facet corners
  # we need (nx - 1)(ny - 1) facet colours!
  x.avg <- (x[-1, -1] + x[-1, -(ncol(x) - 1)] +
             x[-(nrow(x) -1), -1] + x[-(nrow(x) -1), -(ncol(x) - 1)]) / 4

  # Now we construct the actual colours matrix
  colors = col[cut(x.avg, breaks = length(col), include.lowest = T)]

  return(colors)
}

# now lets do some warming up
frac <- mandelbrot(iter = 50)
fcol <- c(heat.colors(49), "black")
image(frac, col = fcol)

# now some impressive stuff
fcol <- surf.colors(frac, col = c(gray(seq(.5, 1, len = 49)), "black"))
frac$z <- -1/frac$z # nicer for plotting and coloring
persp(frac, col = fcol, border = NA, theta = 225, phi = 45, shade = .5)

# now lets see how the zooming function works
par(mfrow = c(2, 2))

gr <- gray(seq(1, 0, len = 255))
fcol.gr <- c(rep(c(gr, rev(gr)), 2), "black")

image(frac, col = fcol.gr)
zoom(col = fcol.gr) # Now click with your mouse two opposite corners of the
                    # area you wish to enlarge
zoom(col = fcol.gr) # do it again!
zoom(col = fcol.gr) # and again ... !

dev.off()

# and finally
frac <- mandelbrot(x = c(-0.8438146, -0.8226294),
                   y = c(0.1963144, 0.2174996), iter = 500)

image(frac, col = fcol.gr)
image(-1/frac$z, col = fcol.gr) # you can also try log(frac$z), etc.

# and this is all ...! I hope you have enjoyed it. Now let your imagination
# fly, designing nice color vectors to be feeded into 'image' is a
# challenging issue. You might want to check the documentation for
# functions like 'rgb' or 'hsv' from the 'base' package.
#
# comments to Mario dos Reis -- mario.res@ucl.ac.uk
