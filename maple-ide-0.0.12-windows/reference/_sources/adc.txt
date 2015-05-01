.. _adc:

=====
 ADC
=====

Analog to digital conversion is the process of reading a physical
voltage as a number.  Maple can convert voltages between 0 and 3.3V to
numbers between 0 and 4095.

.. contents:: Contents
   :local:

ADC On Maple
------------

Doing analog-to-digital conversion on the Maple is simple.
:ref:`Maple IDE <ide>` contains a basic example.  To see it, choose
Analog > AnalogInSerial from the :ref:`examples menu <ide-examples>`.

In order to set up your board for conversion, first connect the wire
(potentiometer, etc.)  with the voltage you want to measure to a
:ref:`pin <gpio>` which can perform ADC.  Each pin which can do ADC
has "AIN" (or "ain") written next to the the pin number.  Then, as in
the example program, set the chosen pin's :ref:`pin mode
<lang-pinmode>` to ``INPUT_ANALOG`` by calling ``pinMode(<your_pin>,
INPUT_ANALOG)``.  You will usually do this in your :ref:`lang-setup`
function.  Now you can use :ref:`lang-analogread` to perform an ADC
reading.

.. _adc-function-reference:

Function Reference
------------------

* :ref:`lang-analogread`
* :ref:`lang-pinmode`
* :ref:`libmaple-adc` (low-level ADC support)

.. _adc-noise-bias:

Noise and Bias
--------------

Maple has a large number of pins which are capable of taking 12-bit
ADC measurements, which means that voltages from 0 to 3.3V are read as
numbers from 0 to 4095.  In theory, this means that a change in
voltage of about 1 millivolt should change the numeric voltage reading
by 1.  In reality, however, a number of issues introduce noise and
bias into this reading, and a number of techniques must be used to get
good precision and accuracy.

In order to allow for good readings, LeafLabs has tried to isolate at
least some of each board's ADC pins and traces from strong noise
sources.  However, there are always trade-offs between noise,
additional functionality, cost, and package size.  More information on
these isolated pins is available in each board's hardware
documentation:

* :ref:`Maple <maple-adc-bank>`
* :ref:`Maple RET6 Edition <maple-ret6-adc-bank>`
* :ref:`Maple Mini <maple-mini-adc-bank>`
* :ref:`Maple Native Beta <maple-native-b-adc-bank>`

That said, there are a number of more general things you can do to try
to get good readings.  If your input voltage changes relatively
slowly, a number of samples can be taken in succession and averaged
together, or the same voltage can even be sampled by multiple ADC pins
at the same time.

Another important factor when taking a voltage reading is the
reference voltages that the sample is being compared against.  For
Maple, the high reference is |vdda| and the low reference is ground.
This means that noise or fluctuations on either |vdda| or ground will
affect the measurement. It also means that the voltage you are trying
to sample must be between ground and 3.3 V.

.. _adc-range:

In the case of a variable reading, it is best if the voltage varies
over the entire range of 0 through 3.3 V; otherwise, only a fraction
of the sensitivity is being used.  Some basic tools to accomplish this
are `resistor dividers
<http://en.wikipedia.org/wiki/Voltage_divider>`_ and `Zener diodes
<http://en.wikipedia.org/wiki/Voltage_source#Zener_voltage_source>`_\
.  However, `operational amplifiers
<http://en.wikipedia.org/wiki/Operational_amplifier>`_ and other
powered components can also be used if greater precision is required.

.. _adc-recommended-reading:

Recommended Reading
-------------------

* `Wikipedia: Analog-to-Digital Converter
  <http://en.wikipedia.org/wiki/Analog-to-digital_converter>`_
* `Arduino Analog Input Tutorial
  <http://arduino.cc/en/Tutorial/AnalogInputPins>`_
* ST documentation:

  * `Application Note on ADC Modes
    <http://www.st.com/stonline/products/literature/an/16840.pdf>`_ (PDF)
  * `Application Note on ADC Oversampling
    <http://www.st.com/stonline/products/literature/an/14183.pdf>`_ (PDF)
