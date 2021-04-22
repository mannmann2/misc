#######################################################################
# Function to calculate the Mandelbrot set. This function calls a     #
# C routine in order to perform the calculations faster.              #
#                                                                     #
# Written by Mario dos Reis. September 2003                           #
# Modified: added if(is.list(x)){...} at start to check if co-ords    #
#           are from locator() or similar - Jason Turner oct 2 2003   #
#######################################################################

mandelbrot <- function(x = c(-3, 1),        # x limits
                       y = c(-1.8, 1.8),    # y limits
                       nx = 600,            # x resolution
                       ny = 600,            # y resolution
                       iter = 20)           # maximun number of iterations
{
  if(is.list(x)) {
     y <- range(x$y)
     x <- range(x$x)
   }

  xcoo <- seq(x[1], x[2], len = nx) # x coordinates
  ycoo <- seq(y[1], y[2], len = ny) # y coordinates
  set = numeric(nx*ny)              # this will store the output of
                                    # the C routine

  # This is the call to the C function itself
  the.set = .C("mandelbrot",
    xcoo = as.double(xcoo),
    ycoo = as.double(ycoo),
    nx = as.integer(nx),
    ny = as.integer(ny),
    set = as.integer(set),
    iter = as.integer(iter))$set

  # Create a list with elements x, y and z,
  # suitable for image(), persp(), etc. and return it.
  return(list(x = xcoo, y = ycoo, z = matrix(the.set, ncol = ny, byrow = T)));
}
