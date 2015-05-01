.. highlight:: cpp

.. _external-interrupts:

External Interrupts
===================

External interrupts can be used to make a voltage change on a
:ref:`pin <gpio>` (the pin going from :ref:`LOW <lang-constants-low>`
to :ref:`HIGH <lang-constants-high>`, or vice-versa) to cause a
function to be called.  This can be used to avoid checking for changes
on a pin "manually" by waiting in a loop until the pin changes.

.. _contents: Contents
   :local:

Overview
--------

External interrupts are often used to detect when events happen
outside of the Maple.  Example events include when a sensor has data
ready to be read, or when a button has been pushed.  When such an
event happens, an interrupt is raised, and the Maple stops whatever it
was doing (it is "interrupted"), and reacts to the event by calling a
function (called an *interrupt handler*) which you specify using
:ref:`lang-attachinterrupt`.

.. _external-interrupts-exti-line:

Any pin can be used for external interrupts, but there are some
restrictions.  At most 16 different external interrupts can be used at
one time.  Further, you can't just pick any 16 pins to use.  This is
because every pin on the Maple connects to what is called an *EXTI
line*, and only one pin per EXTI line can be used for external
interrupts at a time [#fextisports]_.

The EXTI Line Pin Map for your board lists which pins connect to which
EXTI lines:

* :ref:`Maple <maple-exti-map>`
* :ref:`Maple RET6 Edition <maple-ret6-exti-map>`
* :ref:`Maple Mini <maple-mini-exti-map>`
* :ref:`Maple Native Beta <maple-native-b-exti-map>`

Function Reference
------------------

- :ref:`attachInterrupt() <lang-attachinterrupt>`
- :ref:`detachInterrupt() <lang-detachinterrupt>`
- :ref:`libmaple-exti`

Recommended Reading
-------------------

* ST manual `RM0008
  <http://www.st.com/stonline/products/literature/rm/13902.pdf>`_
  (PDF), Chapter 9, "General-purpose and alternate-function I/Os", and
  Chapter 10, "Interrupts and Events".

.. rubric:: Footnotes

.. [#fextisports] The underlying reason for this restriction is that
   the external interrupt lines on the STM32 are shared between
   :ref:`GPIO ports <gpio-ports>`.  There can be only one external
   interrupt on each GPIO bit, out of all of the ports.  That is, if
   PA4 has an external interrupt on it, then PB4 can't have one, too.
   Since the GPIO bit numbers only go from 0 to 15, there can only be
   16 external interrupts at a time.
