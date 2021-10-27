# Vstat

NEW SPOOKY EDITION WITH GPU SUPPORT!!

![Vstat3](https://user-images.githubusercontent.com/88514898/138978494-7e39b3a9-9b52-40f9-a017-b7627287dba9.png)

Vstat is a simple program I made for mostly myself on my Arch linux system. I made Vstat because the idea of having your system information displayed when you open the terminal is just nice, I would say I tried to challenge myself with this but I really didn't, I overestimated the difficulty of this by a lot, the longest part was probably going through a bunch of system files to try and find where certain info was. 


# NOTE: 
this is definatly a prototype that I made for my own system.

This my not work on your system. for example the "timezone" file may not work on all arch systems. I may update this in the future with a nicer looks and more info, I will probably make a(n) update soon that allows it to still run if it failes to grab a file like "timezone".

this is made only for arch distros.


# Run
To run program, open a terminal of your choice, go to the Vstat directory, and run

```./stat```

if this does not work then try to recompile with:

```gcc stat.c -o stat```

If you want it to open with terminal then open the ".bashrc" file in your home directory and at the bottom add:

```cd && cd (your directory) && ./stat && cd```

If it says "Permission denied" then run:

```su```

Enter the root password, then run:

```chmod u+x stat```

