roots([3, 2, -6])

roots([1, 2, 2])

syms a b c x
y = a*x^2 + b*x + c;

soln = solve(y == 0, x)

ysoln = subs(soln, [a,b,c], [3,2,-6])

simplified_ysoln = simplify(ysoln)

vpa(simplified_ysoln, 9)

% Finding integrals: int(exp, var, a, b).
g = int(cos(x)^2,x)

gdef = int(cos(x)^2,x,0,2*pi)

% Series expansion.
taylor(exp(x))

% Plotting equations.
syms x y
f(x,y) = sin(x^2 + y^2);
% ezsurf(f(x,y), [-pi/2, pi/2, -pi/2, pi/2]);
fsurf(f(x,y), [-pi/2, pi/2, -pi/2, pi/2]);