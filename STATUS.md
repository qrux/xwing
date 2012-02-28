Status
=

----

*This project was started 12 years old.  This is just a translation of an old HTML file which was like a project blog.  It's probably laughably out of date by now.*

----

18 Jun 2001
-
Hello, again. It's been a while. I've done some work lately with the code in the base directory. I've changed the Object interface, the container classes, and shifted to a pointer-based paradigm. I've also adapted all the classes to the new Object interface (which is borrowed from the project jgrind Object interface). The new interface obviates the need for the MoonBeam sources...The Xwing code is more independent (of course, the Boehm GC code is still crucial!).

My friend JL has decided to help the effort out. He'll be sorting out the non-GUI-related code, which includes things like re-implementing the container code to make use of the STL. Oh, we'll still hang on to the Java2-library-like interfaces, but the implementation could really leverage all the cool features of the STL. Also, this work could really use some namespace management (namespaces were really an afterthought once the project began).

As far as I go, I'll be working on adding new features to Xwing, now that I've gotten the code to compile and run again in its new state. I'll be working on popup windows, which are unique in that their parents are always the same--the root window. The popup window is weird in that sometimes they are attached to the main application window, but don't share anything with it. This includes components like menu bars and combo boxes.

The compilation is less of a hassle now...However, it's about to change again, so I won't post any more info on the compilation page until this actually happens.


3 Aug 2000
-
Funny--it's been a year since I've added the last bit of work. Here's what I've done to bring this a little more up-to-date. I've learned a little autoconf, so now the build is autoconfiscated. Thanks to my friend JL for providing this impetus.

Secondly, I've removed the distribution of the Boehm GC code; you'll have to get this on your own. To help you out, I'll provide the following link. I've also removed some utility code which I distribute with another of my WIPs (Work in Progress). This you'll have to get in order to be able to build the Xwing project. Find it here: the MoonBeam project.


31 Aug 1999
-
I've finished implementing the BoundedRangeModel and DefaultBoundedRangeModel classes. These are to support scroll bars, which use this model. Unfortunately, this has been rather slow going for practical and not technical reasons (e.g., there are only 24 hours each day, and some actually have to get spent on sleep!). I don't think it should take long to implement the paint() method for XScrollBar, but it's all the model/listener/event code that makes it all time-consuming.


19 Aug 1999
-
Also, my first thanks goes to friend KAM for pointing out a mistake in the JDK1.2 documentation on Sun's site: In the java.awt.Component.update() method description, it looks as if it is saying:

> The AWT calls the update method in response to a call to
>  repaintupdate [sic] or paint.

However, it is really saying:

>  The AWT calls the update method in response to a call to
>  repaint. The appearance of the component on the screen has not
>  changed since the last call to update or paint.

A quick look at the frame source reveals this rather embarrassing bug on the doc site. I've changed the code to reflect this enlightening discovery.

Fixed a minor problem (well, actually it was functionally large, but the fix was quite small) with the NativeGraphics (X Graphics Context) code. The clip wasn't being copied in Graphics::create(), so components were being able to draw outside of their bounding boxes. Oops. Also, I'm avoiding some needless copying of the Graphics object (which really involved some same-pointer aliasing reduction). She seems a little quicker now (those pesky X resources).

Have introduced small problem with my FlowLayout; since the objects aren't resized dynamically when their image changes without the container changing size, calls to Component::repaint() aren't drawing beyond the size. This may not be a problem; will have to write some Swing code to test this behavior. UPDATE! This isn't a problem. In fact, IMHO, my app performs more consistently with drawing beyond the clip than the JDK.


9 Aug 1999
-
New tarball.

I've added FlowLayout. However, there is one glaring problem, which FlowLayout brought to my attention (I don't understand entirely why this is so, which leads to think that this isn't really the reason the problem arose...), which is that Component::paint() is called by Component::update(), which is wrong. In the JDK API docs (JavaSoft web docs), it states that Component::update() is called by the AWT when Component::paint() gets called. I've got it backwards!

Also, I've added Component::getPreferredSize() to the mix, and XLabel and XPanel implement them, I think correctly. (I need to change these names, since, e.g., EventObject & EventListener aren't really different from the AWT naming--if Sun's gonna sue me, an 'X' instead of a 'J' isn't gonna make the difference!).

FlowLayout is implemented correctly per spec, as far as I can tell, but behaves somewhat differently than the SwingApplication demo. Don't know why this is--will read further.... BTW, the picture below is what happened when the app pictured above (I was clicking the button as the grab occured!) was horizontally lengthened:


5 Aug 1999
-
New tarball.

        cd src
        make clean demo
        xwing/frametest

I've sutured the skull (i.e., memory leaks). There were two main causes--well, acutally, there's only ONE main cause: X. Since X requires you to call their functions to allocate & deallocate data structures, the memory allocated is not allocated in the collectable heap. This causes the leak. So, the test application pictured below now resizes and respondes to button clicks without sucking down tens-of-megs of VM.

If you really want to know, the two major causes were not calling XFreeGC(3X11) and XFreeFontInfo(3X11). This caused ::GC & ::XFontStruct allocations to run amuck (since I was pretending the garbage collector would know how to do this). Of course, the stinking problem is that to free the font information, I have to explicitly delete heap-allocated FontMetrics objects, even though the call to XFreeFontInfo(3X11) is in the dtor (which I assumed was being called by the GC). Oh well. Another problem for the next rainy day...Oh wait--I live in the SF Bay Area…


2 Aug 1999
-
I have added enough event infrastructure to make a functional demo as described below. I've sorta found a solution to Component::getGraphics(); on Component::update(), I take the object passed as the argument and copy it to the component. On each update (since potentially the translation & clip could have changed), the arg is again copied to the component. However, on repaint(), the Graphics object (in the component) is up-to-date, so I just go ahead and paint with it.

Oh boy. This app leaks memory like a skull with multiple gunshot wounds. I haven't yet found the source of the gushing, but everytime you do a resize or a button click (of course, lots of resource allocation takes place during those events), the amount of memory, as reported by KDE's process manager, allocated to the app just rises and rises. Of course, I believe that most of the leakage is just due to bad programming on my part. =( Test programs written with GCable objects are just fine, and do not endlesly consume memory like the Cookie Monster(TM).

I'm going to bundle this up in a new tarball: One note: I'm only using a GridLayout, but that should be trivial to change. Run the demo:

	cd src
	make testers
	xwing/frametest 2> /dev/null

Having a friend--TSG-test my app, it became apparent that libraries are going to be a problem. I have libstdc++-2.9.0 which is what builds with egcs-1.1.x & higher. He has RH5.2 (as do I) but the stock libstdc++ is at 2.8.0. Oops. Therefore, I've included my copy of libstdc++. Back to the project home page for the gzipped copy. It's just best if you install the right compiler; I've had to defect because of deficiencies in egcs-1.0.3: covariant returns were not supported.

If you run without redirecting STDERR to /dev/null, you'll be faced with lots of GC debugging output. The other solution would be to simply edit gui/etc/Makefile, and remove the -DDEBUG_GC flag. Trust me; you don't want it--the app has enough debugging that's not -DDEFINED...I'll have to change this later, of course.


1 Aug 1999
-
Now, I am integrating events into the model, enough to run a simple program that has a button, a label, a FlowLayout Manager, and an action which ties the text of the label to button presses. However, the event work is going slowly, as there is a lot to implement. Secondly, now that I have to call repaint() from within the component (i.e., not from the root container, XFrame), I have to find a way to correctly impl Component::getGraphics().

As a solution to the willy-nilly pointer problem (see below), I'm using the Boehm Garbage Collector from Xerox Parc. See the README for their original copyright plus details of the collector.

The code has been temporarily adapted to use the GC; Object now inherits from Collectable (typedef gc Collectable, where 'gc' is the class from which GC-collectable types are to be derived). I've only made some minor changes to variable names (unscoped clash) and to the Makefile so that it fits into my build system.


28 July 1999
-
There is a prototype demo. It draws a frame, puts two buttons a label, and a panel inside. The panel contains four buttons. A window resize will cause the frame to repaint all the components with their new size as given by the frame's new size.
I've recently changed from using references and stack-instantiated objects to using pointers and new. This has the more Java-like code appearance:

	XFrame frame = new XFrame();
    
Instead of this:

	XFrame frame;
    
However, this has created a large problem with memory management; objects are created willy-nilly with operator new, and pointers are getting trampled. This is causing, of course, memory to leak for each instantiation of the application.


Systems where the code compiles:
-
	Intel Linux 2.0.36, egcs-2.95
	Intel Linux 2.0.36, egcs-1.1.2
	Intel Linux 2.0.36, egcs-1.1.1

