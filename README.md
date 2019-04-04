# csx730-more-paging Another Paging Activity

Most modern systems support a large virtual address space (e.g., `1ul << 64`).
In such an environment, the page table itself becomes excessively large.
One way to deal with this scenario is to use a multi-level paging algorithm,
sometimes referred to as **hierarchical paging**.

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

1. Under "Questions" in `SUBMISSION.md`, provide answers to the following
   questions, assuming you are on a 64 bit system with a 4096 byte page size:

   1. What is the size of the set of all virtual addresses?
      Show your work. You may express the solution in pseudo-C code.

   1. Assuming a single page table, how many pages are theoretically possible?
      Show your work. You may express the solution in pseudo-C code.

   1. Assuming a single page table, how big would that table need to be,
	  in the following units: B, KB, MB, and GB?
      Show your work. You may express the solution in pseudo-C code.

   1. Assume that each virtual address is broken up in to three parts:

      ```
	  |-------------------------------------------------------|
	  | table0 page number | table1 page number | page offset |
	  |-------------------------------------------------------|
	  ```

	  If the number of bits reserved for `table0` and `table1` are
	  equal, then how big would `table0` need to be, in the
	  following units: B and KB?
      Show your work. You may express the solution in pseudo-C code.

   1. Assume that each virtual address is broken up in to five parts:

      ```
	  |-------------------------------------------------------|
	  | table0 PN | table1 PN | table2 PN | table3 PN | PO    |
	  |-------------------------------------------------------|
	  ```

	  If the number of bits reserved for each table is equal,
	  then how big would `table0` need to be, in the following
	  units: B and KB?
      Show your work. You may express the solution in pseudo-C code.

1. In `paging.c`, create a `struct` for an `addr_type` that uses
   [bit fields](https://en.cppreference.com/w/c/language/bit_field)
   to define the various parts of the address:

   * Each field should be of type `unsigned long`.
     This is allowed by GCC even in strictly conforming code.

   * The variable for each page number should be `pn0`, `pn1`, etc.,
     and the page offset variable should be called `off`.

1. For convenience, also create a typedef for an `addr_t` type based
   on `struct addr_type`.

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
