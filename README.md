# Vstat

### NEW SPOOKY EDITION WITH GPU SUPPORT!!

### Arch linux (x86)
![Vstat4](https://user-images.githubusercontent.com/88514898/139603929-b5bf50ec-f106-4ce4-9473-6b9048fa6ec5.png)

### Raspberry Pi (ARM)
![VstatPI](https://user-images.githubusercontent.com/88514898/141326994-ca13473b-131a-4f97-a4a5-cadaae697978.png)

Vstat is a program written in c. Vstat displays your certain system information in your terminal like CPU, GPU, Memory, and more. I made Vstat because the idea of having your system information displayed when you open the terminal is just nice.


# NOTE: 
this is definatly a prototype that I made for my own system.

This my not work on your system. for example the "timezone" file may not work on all arch systems. I may update this in the future with a nicer looks and more info, I will probably make a(n) update soon that allows it to still run if it failes to grab a file like "timezone".

If you know or think you have the timezone file then you can go into the code and un-comment the cuncks of code int the "info" function.

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

