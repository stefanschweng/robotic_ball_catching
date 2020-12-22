function R = quaternion2rotation(q)
    q = double(q);
    s = q(1);
    x = q(2);
    y = q(3);
    z = q(4);

    R = [   1-2*(y^2+z^2)   2*(x*y-s*z) 2*(x*z+s*y)
        2*(x*y+s*z) 1-2*(x^2+z^2)   2*(y*z-s*x)
        2*(x*z-s*y) 2*(y*z+s*x) 1-2*(x^2+y^2)   ];
end
