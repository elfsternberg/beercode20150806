# Purpose

Prove I'm not an idiot.

As an exercise, I decided to do this homework in C++.  As I haven't
written any C++ in 15 years, this was... entertaining.

# Task #1

   Write a function which computes the some [sic] of q, q^2, q^3, … q^n,
   where "^" denotes power or exponent.  For example, the sum of
   2,4,8,16 is 30.  What is the complexity?

The complexity is linear.  This is a basic sigma function, once you know
the underlying formula, production is simple.  The requirements for the
code (that you determine both the base of your exponent collection, and
know how many you want) are difficult to discern from a simple reading
of the instructions.  

If I'd allowed myself to use boost(), I've written this using the
accumulate() function, but I'd have to figure out how to create a range
iterator.


# Task #2

   Write a function GetMax(Node list), which finds the maximum integer
   value in the list

In order to make this at all interesting, I set myself the task of
learning how to create function templates, which we didn't have back in
1999.  It turned out to be relatively straightforward, although the
"typename" declarator in the template before std::list<t>::iterator is a
bit of cargo-cult I got from compiler's warnings; I really need to go
back and read some of Alexandrescu's books, especially since I got them
all for free after spotting a typo in one back in 1997 or so.  

I've provided a Makefile and unit tests using the Aeryn C++ Test
Framework.  It was a framework chosen at random from a list I found
after searching for "C++ Test Frameworks," I can't comment on its
quality, but it did the job.  It looked familiar enough compared to
JUnit or Mocha.

# Commentary

It's been a long time since I wrote C++.  The syntactical noise of C++
annoys me a bit since I've started writing in "An elegant language for a
more civilized time," and I'm so far out of experience with it that the
modern paradigm of Resource Allocation Is Initialization and all of the
wonderful new toys like auto, unique_ptr, lambdas and the like would
take me a month or two to catch up.

If I'd written this in Javascript they'd have been one-liners:

    exponentialSum = (base, count) => 
        _.reduce(_.range(1, count + 1), ((m, v) => return m + Math.pow(base, v)), 0);

    largestValue = _.max;

or:

    largestValue = (list) => Math.max.apply(Math, list);

I'm pretty sure that the functions I wrote have simple equivalents in
some library somewhere.  Boost seems to have just about everything.

The Makefile is just something I pulled out of an old project and
cleaned up for the purposes of this exercise.

Total time spent: Approximately 75 minutes.

# Addenda

The [sic] in the original task description is a bit of a snark.  That
and the instruction to "Please use of of [sic] Java/C++/C#/Javascript"
ought to be professionally embarrassing to someone seeking viable,
self-respecting candidates.

