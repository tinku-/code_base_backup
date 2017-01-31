#include <thrust/version.h>
#include <iostream>

int main(void)
{
  int major = THRUST_MAJOR_VERSION;
  int minor = THRUST_MINOR_VERSION;

  std::cout << "Thrust v" << major << "." << minor << std::endl;

  return 0;
}

//https://solarianprogrammer.com/2012/05/31/matrix-multiplication-cuda-cublas-curand-thrust/
//http://stackoverflow.com/questions/7663343/simplest-possible-example-to-show-gpu-outperform-cpu-using-cuda
//https://www.google.co.in/webhp?sourceid=chrome-instant&ion=1&espv=2&ie=UTF-8#q=cuda%20libraries