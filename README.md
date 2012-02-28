C++ Native Swing Implementation: Xwing
=
This is an attempt to port the Java(TM) Swing(TM?) API to C++. I'm using an X-windows backend on a Linux machine. With sufficient adjustment of Makefile options, the code will compile on any Unix(TM) system with X11R5. Please drop a line on the wiki if you are able to compile the code.

Motivations
-
* Swing is a good library.
* Swing is something a lot of people know.
* Swing has a clean L&amp;F.
* X-windows programming is hard.

Goals
-
* Provide a good-looking UI lib for X.
* Provide a UI lib with a low learning-curve.
* Provide a UI lib that leverages existing knowledge.


Compiling
-
To get started, run ./configure --help. You'll need these options:

* --with-boehm-gc-dir=DIR
* --with-base-dir=DIR
* --with-gxx-include-dir=DIR
* --with-gxx-sysinc-dir=DIR

'boehm-gc-dir' should point to the installed location of the Boehm GC code. Under this directory should be the lib and include dirs, respectively containing gc.a and gc.h (along with other headers).

'base-dir' should point to the installed location of the MoonBeam code.

'gxx-include-dir' should point to the location of your Standard C++ library includes (STL, etc.). Since I don't use the stock compiler with my Linux distro, I have to give this so that makedepend isn't so loud. Even if you don't have this, or if your compiler is in the default places, the build should work.

'gxx-sysinc-dir' should point to the location of your C++ system includes (typeinfo (for g++), etc.). Again, since I don't use the stock compiler with my Linux distro, I have to give this so that makedepend isn't so loud. Even if you don't have this, or if your compiler is in the default places, the build should work.

Once you've got that set, run configure.  Here's my configuration:

	./configure \
	--prefix=/home/app/Xwing-0.0 \
	--with-base-dir=/home/app/MoonBeam \
	--with-boehm-gc-dir=/home/app/gc \
	--with-html-dir=~/html \
	--with-gxx-include-dir=/app/gcc/include/g++ \
	--with-gxx-sysinc-dir=/app/gcc/lib/gcc-lib/i686-pc-linux-gnu/2.95.2/include \
	--with-x

Then, build it:

	make demo

This should get the stuff compiled. If it doesn't, please send me the output, including the config.status file, the command you typed in, and the environment:

* bash:
	make demo > make.out 2>&1
	printenv > make.env

* csh:
	make demo >& make.out
	printenv > make.env

If you have a more clever way of getting this info (e.g., expect), let me know.

Running It
-
Just do this:

	./xwing/frametest
    
Of course this is contingent on the stuff getting compiled. Otherwise, you're on your own (until I get time to look at it--not that I could necessarily help).

Then, look around. If you see something you'd like to contribute, fix, or say sucks (or for that matter, is-good), then please let me know:

For your reference, I'm using gcc-2.95-2, gmake-3.77, and autoconf-2.13. My gmake and autoconf are installed in /usr/bin, and my g++ is installed in /app/gcc. I'm also using CVS; that explains the CVS directories. I've realized that this code doesn't compile with egcs-1.0.x (2.90.x), because I use covariant returns, and that isn't supported yet in the compilers.

This version of egcs, unfortunately, is the stock compiler of RedHat 5.2. I don't know about 6.0 yet, but chances are if you're using RedHat linux you'll have to upgrade your compiler.

