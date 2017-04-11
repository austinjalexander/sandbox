learntoprogram
==============

Intro
-----------------

The point of this tutorial is to *learn how to program*. This topic is really separate from any particular form of expression (e.g., the programming language Python) or implementation (e.g., making apps for iPhones). Thus, we could simply use pen and paper! 

However, since most of us find it easier to use concrete programming languages in order to think about and create programs that solve specific problems in distinct domains, in this tutorial, we will focus on a particular language, the ubiquitous programming language C **[0]**, and we'll design simple command-line input/output programs, all of which will prepare us for working with other languages (e.g., Javascript) involving applications in other domains (e.g., user interaction with web pages).

Our emphasis, therefore, will not be on learning idioms or applications unique to C. For example, for a number of reasons, I won't show you #define statements or dig too deep into the intricacies of memory management **[1]**.


Why Learn How to Program?
-------------------------
The art and science of programming is related to the current buzz surrounding so-called *computational thinking*. If you're familiar with this phrase, you may have wondered what is means, and you'd be in good company. I think a clearer expression, at least for the purposes of intial explanation, might be *instructional thinking*.

*Instructional thinking* is exactly what it sounds like: we think about concepts/problems in terms of instructions **[2]**, and we break those concepts/problems down into a set of instructions (and appropriate informational items **[3]**). Moreover, since we end up with lists of instructions (much like lists of our favorite recipes), we're compelled to develop ways to process those instructions, ensuring that they're completed successfully. As a result of this development process, we naturally learn to think abstractly about our concepts/problems, which essentially means that we become able to focus on more or less or our instructional and informational details, depending on our current needs (e.g., we can focus on a given step 2 and how it relates to steps 1 and 3, or we can focus on the components of which step 2 is composed, for example, parts a, b, and c). And all of this is just the beginning.

If the above description doesn't have you sold, you'll simply have to trust me: computational/instructional thinking is extremely powerful, and I'm confident you'll find that as you become better at it, you'll become a better thinker/doer in almost any domain.

Get Started!
------------
Alright, enough gab; fire up your terminal **[4]**.

Here's what we're going to do:

1. use the terminal to enter your desktop
2. create a directory called *learntoprogram* on your desktop
3. move into that directory
4. create a file called main.c in that directory

Here's how to do it; type the following in your terminal (*$* stands for the terminal prompt):

1. $ cd ~/Desktop
2. $ mkdir learntoprogram 
3. $ cd learntoprogram
4. $ touch main.c

Now open up main.c in a (plain) text editor (I recommend [Sublime Text](http://www.sublimetext.com/)).

And visit your [first lesson](https://github.com/austinjalexander/learntoprogram/tree/master/week0)!


Footnotes
------------
**[0]** C is a great and powerful language. Oddly enough, it's also very simple. And boy is it fast! It helped to spawn the programming scene as we know it, including the languages on which we all regularly depend. It is the language most commonly used for controlling the various machines all around us, from our laptops to our mars rovers. Moreover, C's syntax, in my opinion, easily prepares new programmers for learning most other languages (it's place in the programming-language family tree makes this point easy to understand). Also, since it demands use of *compilers* that are happy to inform you of grammar and syntax errors (albeit somewhat cryptically at times), C requires an initial safety net for new programmers, something which cannot be said for langauges like Python, Ruby, and Javascript (although interactive shells/interpreters and wonderful tools like Firebug exist, their use is not required, which must mean that most new programmers fail to make use of them---caution tends to come with wisdom from experience, after all).

**[1]** If you're curious about these topics, or any others you hear/read about, you can always make use of Google or simply ask me about it.

**[2]** In programming, instructions tend to be implemented as *functions*, which may be described as relationships between sets of inputs and their particular sets of outputs, where each input has exactly one output.

**[3]** In programming, informational items tend to be implemented as simple *data elements* or, more often, as complicated and programmer-defined, *data structures*.

**[4]** This tutorial assumes you're using a Mac; if you're using Windows, you can either download and install something like [Visual Studio](http://www.visualstudio.com/en-US/products/visual-studio-express-vs), or you can simply try [programming/compiling online](http://www.compileonline.com/compile_c_online.php). If you happen to be a new Linux user who doesn't know how to program, the Mac instructions should work pretty well for you (I tend to do most of my development in Debian), but let me know if you have any issues.
