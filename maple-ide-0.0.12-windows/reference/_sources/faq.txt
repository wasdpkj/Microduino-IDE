.. highlight:: cpp

.. _faq:

==================================
 Frequently Asked Questions (FAQ)
==================================

.. contents:: Contents
   :local:

.. _faq-atoi:

How can I use ``atoi()``?
-------------------------

The :ref:`CodeSourcery GCC compiler <arm-gcc>` used to compile your
programs is configured to link against the `newlib
<http://sourceware.org/newlib/>`_ C library, and allows the use of any
of its headers.

.. _faq-dynamic-memory:

Why don't ``malloc()``/``new`` work?
------------------------------------

Due to our newlib configuration, dynamic memory allocation is
currently not available.

.. _faq-flash-tables:

How do I replace ``PROGMEM``/put data into Flash?
-------------------------------------------------

See :ref:`this note <arm-gcc-attribute-flash>`.

How do I write to a pin at high speed?
--------------------------------------

Sometimes, :ref:`lang-digitalwrite` just isn't fast enough.  If that's
your situation, you should first try using fast GPIO writes using the
low-level :ref:`libmaple-gpio` interface.  This FAQ entry explains
how.

You'll need to look up the :ref:`GPIO port and bit <gpio-ports>` which
correspond to the pin you want to write to.  If you don't know what
that means, don't worry.  We'll go through an example here.

Let's say you want to write to pin 4 on the Maple.  In order to find
out the port and bit number, take look at the Maple's :ref:`master pin
map <maple-pin-map-master>` next to "D4".  You'll see that in the
"GPIO" column, there's "PB5".  That's short for "**P**\ ort **B**, bit
**5**".  So the GPIO port is "B", and the bit is "5".  (If you're not
on the Maple, you can find your board's pin map :ref:`from here
<gpio-pin-maps>`).

That's all you need to know.  Now you can use the function
``gpio_write_bit()`` to quickly write to the pin.  The way you call it
is by writing ``gpio_write_bit(GPIO<port>, <bit>, HIGH/LOW)``, where
``<port>`` is the GPIO port, ``<bit>`` is the bit, and ``HIGH`` or
``LOW`` is the level you want to write to the pin.  Here's an example
program which writes pin 4 (GPIOB, bit 5) ``HIGH`` and then ``LOW``
several times in a row each time it :ref:`lang-loop`\ s::

    /*
       Fast pin writing example, for Maple.

       This example works for pin 4 (PB5 on Maple).  If you want to
       use another pin (or are on another board), just change PIN,
       PIN_PORT, and PIN_BIT as described above.
    */

    #define PIN 4
    #define PIN_PORT GPIOB
    #define PIN_BIT 5

    void setup() {
        pinMode(PIN, OUTPUT);
    }

    void loop() {
        gpio_write_bit(PIN_PORT, PIN_BIT, HIGH);
        gpio_write_bit(PIN_PORT, PIN_BIT, LOW);
        gpio_write_bit(PIN_PORT, PIN_BIT, HIGH);
        gpio_write_bit(PIN_PORT, PIN_BIT, LOW);
    }

Now, if you've already tried this and you still can't get enough
speed, there are some threads on the `forum`_ which might help you
squeeze a little extra out of your board.  First, a `general summary
<http://forums.leaflabs.com/topic.php?id=860>`_ of other things to
try, with measurements of the speed you'll get.  Next, a thread
featuring a `detailed discussion on pin capability
<http://forums.leaflabs.com/topic.php?id=774>`_, with a focus on
writes.
