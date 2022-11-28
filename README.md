# bfck
Minimal Brainfuck interpreter written in C

## Quick Brainfuck overview

Brainfuck offers only 8 instructions to build your program from. In originalBrainfuck size of the memory was limited to 30 000 bytes. With possibility to increment/decrement values stored inside 'infinitely' long array of bytes,loops and input/output it meets the bare minimum to pride itself as a Turin complete language. 

## Instructions 

`+` increment on location specified by the pointer

`-` decrement on location specified by the pointer

`>` increment pointer value if possible

`<` decrement pointer value if possible

`.` output value stored on the current position of the pointer

`,` get user input on the current position

`[]` loop annotation

