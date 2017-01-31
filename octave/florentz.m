function [vyd] = florenz (vt, vy)
   vyd = [10 * (vy(2) - vy(1));
          vy(1) * (28 - vy(3));
          vy(1) * vy(2) - 8/3 * vy(3)];
 endfunction