# Brainfuck - a programming language


## Introduction :

**Brainfuck** is one of the most insane languages I have come across. With just 8 operators which specify different movements and actions over the memory, we can code up a pleotra of programs. 
<br/>

Brainfuck, by itself is a **Turing complete language** originally created by Urban Muller. The rationale behind creating such a simplistic language is to breakdown each line of high level code into microscopic chuncks that allows the programmer to optimize the code right down to the architecture stages. 

According to wikipedia, Muller designed this language with the goal of implementing the smallest possible compiler. 

To explore and use this language one must need - 
- an interpreter or a compiler. (a very basic one is attached with this repo) (written in C++)
- an ASCII chart with all the characters and their decimal equivalents
- finally, an immense amount of patience

## BASICS:

**Brainfuck** is a language based on the concept of `memory manipulation` and has a very simple premise. The language consists of 8 commands, `+-<>[].,`. A brainfuck program is a sequence of these 8 commands. 

This language used a simple machine model consisting of program and instruction pointer and a 1-dimensional array of around 30,000 cells each of 1 byte initialised to 0.

There are 2 pointers which are at play during the running of a brainfuck program -
1. Data pointer - a data pointer points to a memory location (a byte in the memory array)
1. Instruction pointer - which points to the current runnning instruction. In most cases, the instruction pointer runs sequentially. 

The 8 operators and their functions - 

```brainfuck
> = increases memory pointer, or moves the pointer to the right 1 block.
< = decreases memory pointer, or moves the pointer to the left 1 block.
+ = increases value stored at the block pointed to by the memory pointer
- = decreases value stored at the block pointed to by the memory pointer
[ = like c while(cur_block_value != 0) loop.
] = if block currently pointed to's value is not zero, jump back to '['
, = like c getchar(). input 1 character.
. = like c putchar(). print 1 character to the console
```

#### Some important things to consider

- The interpreter does not accept any arbitrary character except for the 8 commands.
- all memory blocks are assigned the number zero at the beginning of the program and the data pointer moved from the left most memory block.
- multiple loops can be created, but every "[" requires a corresponding "]".


**One example of a program in brainfuck**

### Add 2 numbers 

```brainfuck
    ,       // read character into cell #0 
    >       // move to cell #1
    ,       // read character into cell #1 
    [
        <       // move back to cell #0
        +       // increment
        >       // move to cell #1
        -       // decrement
    ]
    <       // back to cell #0
    ------------------------------------------------  // subtract 48 (ie ASCII char code of '0')
    .       // print output to stdout
```

#### Overall code

```brainfuck
    ,>,[<+>-]<------------------------------------------------.
```

### Print Hello world!

Stores the ascii value of each character in each byte.. and finally all the bytes are printed in sequence. 

```brainfuck
    >++++++++[<+++++++++>-]<. // stores 72 - ascii value of "H".
    >++++[<+++++++>-]<+.
    +++++++..
    +++.
    >>++++++[<+++++++>-]<++.
    ------------.
    >++++++[<+++++++++>-]<+.
    <.
    +++.
    ------.
    --------.
    >>>++++[<++++++++>-]<+.
```

**Attached C++ interpreter for brainfuck**

### Do raise issues when you come across an anomaly in the code attached...

