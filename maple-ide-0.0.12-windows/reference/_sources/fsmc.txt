.. _fsmc:

FSMC
====

The Flexible Static Memory Controller (FSMC) is a peripheral which an
be configured to control a variety of external memory chips.

Normally, any variables in your program will be allocated space in RAM
(notable exceptions are variables marked with ``const`` or
:ref:`__FLASH__ <arm-gcc-attribute-flash>`).  Without the FSMC, this
space is limited to the amount that comes built-in to the chip's
*internal* SRAM.

The addition of the FSMC peripheral allows addtional memory to be
used.  For example, it is used on the Maple Native to interface with
the board's built-in external SRAM chip.  However, this extra memory
comes at a cost: the FSMC uses a fairly large number of GPIOs.

The FSMC peripheral is currently only available on the Maple Native.
On that board, we have broken out a wide variety of the FSMC lines, so
that experienced users can add additional external memory chips to
suit their own applications' purposes.

.. TODO Find some tutorials on SRAM or write one on FSMC, specifically
.. ones that cover: address, data, chip-select etc. pins, memory bank
.. organization

Recommended Reading
-------------------

- Wikipedia article on `SRAM <http://en.wikipedia.org/wiki/Static_random-access_memory>`_
- :ref:`ST RM0008 <maple-native-b-stdocs>` chapter on FSMC.
