function s = geoSum(r,n)
% geoSum.m sums the first n terms of a
% geometric series with common ratio r.
if r == 1
    s = n;
else
    s = (1-r^n)/(1-r);
end
end
