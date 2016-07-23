# Purpose

This was a résumé test question given to someone else, who had brought
it to the August 7th, 2015 Beer && Coding, in the hopes that we would
help him solve it.  We were not successful, although I did get pretty
far on my own with a solution written in Scheme.

# Status

This code is **complete**.  It is not being maintained.

The problem stated was:

    Given a number (assume base 10) less than 10,000, write a program in
    C++ that will reverse the digits of that number, calculate the
    original number to the power of the new number, and print it out.
    You may not use Boost, GMP, or any library other than that provided
    by the C++ Standard Library.

I don't know C++.  I haven't ever written C++ profesionally, and I
haven't actually *looked* at C++ since 1999 or so.  As a professional,
I'm aware of what's going on in the zeitgeist, and at my job at Spiral
Genetics I interacted with two very talented C++ developers a lot, so I
was aware of things like the emerging C++ Standard Library and RAII and
so forth.  I didn't know what they *meant*, but I had heard of them.
I've also been aware of the emerging standards in C++11 and C++14,
mostly thanks to Slashdot, Hacker News, and their ilk (don't read the
comments, don't **ever** read the comments), so I'd *heard* about
auto_ptr and C++11 lambdas and the like.

It took about an hour of googling to get up to speed on things like
namespaces, containers, for_each, lambdas, and the like.  I really like
the new unique\_ptr construction.  That's very nice.

My basic solution degrades to 4th-grade mathematics: Break the
multiplicand up into a list of single digits, multiply each digit
with the multiplier, then redistribute the values up the tens, hundreds,
etc., etc.  This solution is not particularly fast or space-efficient,
but it has the virtue of being comprehensible by any ten-year-old.

As usual, I've provided a test suite, as well as a pair of utility
functions for converting the list to a string, or an unsigned long.  The
latter only works with very small results.  The executable, "cheapgmp",
works as specified in the problem statement.

