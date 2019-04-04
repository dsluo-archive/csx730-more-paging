# csx730-more-paging Another Paging Activity

**Paging** is a common memory management scheme that avoids external fragmentation
by splitting physical memory into fixed-sized frames and logical memory into blocks
of the same size called pages. In this activity, you will implement some functions
for basic page-based address translation using a page table.

### Getting Started

1. Form into **small groups of two or three** people. These instructions assume that at least one group
   member is logged into the Nike.

1. Use Git to clone the repository for this exercise onto Nike into a subdirectory called 
   `csx730-morepaging`:

   ```
   $ git clone https://github.com/cs1730/csx730-more-paging.git
   ```

1. Change into the `csx730-more-paging` directory that was just created and look around.
   There should be a couple different files already present, including a magic `Makefile`
   that will compile, assemble, and link stand-alone C files individually.

### Activity Questions

This activity is open book, open notes, and asking your instructor questions is allowed.
You may find Ch. 9 of _Operating System Concepts_ by Silberschatz, Gagne, and Galvin
useful as a reference.

1. Modify `SUBMISSION.md` to include the name, UGA ID number, course number (4730 or 6730)
   for each group member. Then, **sign the piece of paper that your instructor has at the front
   of the room.**

1. Under "Definitions" in `SUBMISSION.md`, provide the definition for each term
   listed, according to Silberschatz, Gagne, and Galvin.

1. In `paging.c`, create a [typedef declaration] for an `addr_t` type based on
   an `unsigned long`, then define the following constants:

   * `M` -- a number such that `1ul << M` denotes the number of logical addresses
     available using an `addr_t` type. Recall that bitwise left shifting of an integer
     is similar to multiplying by a power of two.

   * `N` -- a number such that `1ul << N` denotes the page size in bytes. As a
     start, we will assume a page size of `4` bytes. Recall that bitwise left shifting 
     of an integer is similar to multiplying by a power of two.

   * `PO_MASK` -- an `addr_t` bit [mask](https://en.wikipedia.org/wiki/Mask_(computing))
      that masks the lower `N` bits of a virtual / logical memory address, denoting the 
      region used for the page offset. Like the others, this is also a constant value.
      We're not asking you to write a function-like macro.

   * `PN_MASK` -- an `addr_t` bit [mask](https://en.wikipedia.org/wiki/Mask_(computing))
     that masks the higher `M - N` bits of a virtual / logical memory address, denoting 
     the region used for the page number. Like the others, this is also a constant value.
      We're not asking you to write a function-like macro.

   * `PG_SIZE` -- the page size, calculated using `N`.

1. Check your masks against the following virtual addresses:

   | Virtual Address    | DEC  | PN  | PO  |
   |--------------------|------|-----|-----|
   | `0000000000000001` | `1`  | `0` | `1` |
   | `000000000000000b` | `11` | `2` | `3` |
   | `0000000000000000` | `0`  | `0` | `0` |
   | `0000000000000006` | `6`  | `1` | `2` |
   | `000000000000000f` | `15` | `3` | `3` |
   | `0000000000000009` | `9`  | `2` | `1` |
   | `0000000000000007` | `7`  | `1` | `3` |
   | `000000000000000d` | `13` | `3` | `1` |
   | `0000000000000003` | `3`  | `0` | `3` |
   | `000000000000000f` | `15` | `3` | `3` |
   
   where DEC denotes the decimal representation of the address,
   PN denotes the page number, and
   PO denotes the page offset.

**CHECKPOINT**

1. In `paging.c`, declare a page table with four entries:

   ```c
   addr_t page_table [4] = { 5, 6, 1, 2 };
   ```
   
   Here, each index in the page table refers to a page number in virtual memory. 
   Each value in the page table holds that page's corresponding frame number in physical
   memory. An alternative approach might use frame addresses instead of frame
   numbers.

1. Next, implement the following functions:

   * `addr_t virt_to_phys(addr_t virt);` -- returns the physical address for a
     given virtual address based on the page table.

   * `addr_t phys_to_virt(addr_t phys);` -- returns the virtual address for a
     given physical address based on the page table.

1. Verify that your functions work against the following addresses:

   | Virtual Address    | Physical Address   |
   |--------------------|--------------------|
   | `0000000000000001` | `0000000000000015` |
   | `000000000000000b` | `0000000000000007` |
   | `0000000000000000` | `0000000000000014` |
   | `0000000000000006` | `000000000000001a` |
   | `000000000000000f` | `000000000000000b` |
   | `0000000000000009` | `0000000000000005` |
   | `0000000000000007` | `000000000000001b` |
   | `000000000000000d` | `0000000000000009` |
   | `0000000000000003` | `0000000000000017` |
   | `000000000000000f` | `000000000000000b` |

**CHECKPOINT**

1. In `paging.c`, declare some global variables to represent a virtual memory
   space and a physical memory space:

   ```c
   char virt_mem [PG_SIZE * 4]; // four virtual pages
   char phys_mem [PG_SIZE * 8]; // eight physical pages
   ```

1. In your `main` funtion, initialize both memory spaces to `' '` (i.e., the
   whitespace character).

1. Next, reinitalize the virtual memory space to contain the alphabet
   characters `a`, `b`, ..., etc. As you initialize each space, use your
   `virt_to_phys` function to also place the character in the appropriate
   location within the physical memory space.

1. Finally, print out all addresses in each space along with their stored
   values. If done correctly, it should match up with Figure 9.10 in
   Silberschatz, Gagne, and Galvin.

**SUBMISSION**

1. **Before 11:55 PM on WED**, double check that your group member names are listed
   in `SUBMISSION.md` as well as the piece of paper that your instructor has at the
   front of the room, then submit your activity attempt using the `submit` command.
   From the parent directory:

   ```
   $ submit csx730-paging csx730
   ```

1. Remember to share this directory with your group members!

<hr/>

[![License: CC BY-NC-ND 4.0](https://img.shields.io/badge/License-CC%20BY--NC--ND%204.0-lightgrey.svg)](http://creativecommons.org/licenses/by-nc-nd/4.0/)

<small>
Copyright &copy; Michael E. Cotterell and the University of Georgia.
This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/">Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License</a> to students and the public.
The content and opinions expressed on this Web page do not necessarily reflect the views of nor are they endorsed by the University of Georgia or the University System of Georgia.
</small>
