# cpu.c

```
$ gcc ./cpu.c -o cpu
$ ./cpu A & ./cpu B & ./cpu C & ./cpu D
```

If we run multiple instances of cpu, we can see that each is running
at the same time. The OS virtualizes the CPU, making it look like
each process has its own CPU.

# mem.c

```
$ gcc ./mem.c -o mem
$ lldb ./mem
$ run 0
```

If you run two separate instances of mem (using the lldb debugger so that
the OS doesn't obfuscate memory), we can see that each process seems
to have access to the same memory addresses! The OS virtualizes memory
as well, making it seem like each process has full access to the entire
memory address space of the computer.

# threads.v0.c

```
$ gcc ./threads.v0.c -o threads.v0
$ ./threads.v0 10000
Initial value : 0
Final value   : 19867
$ otool -arch x86_64 -fxv threads.v0 > threads.v0.asm
```

Both threads are sharing and incrementing the same counter at the same
time. Incrementing is not atomic. It consists of multiple steps, and
if both one of the threads is interrupted, its increment might not be
correctly completed. otool disassembles the executable to see the machine instructions.

See `threads.v1.c` for a corrected version of the source file.
