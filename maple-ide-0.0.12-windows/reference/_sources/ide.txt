.. _ide:

Maple IDE
=========

This page documents the basic functionality of the Maple IDE.
Specifically, it describes the operation of the buttons on the main
toolbar.  It is expected to become more comprehensive over time.

If you're new to Maple, you should begin with the :ref:`Maple
Quickstart <maple-quickstart>`.

If you need to install the IDE for the first time, see the
:ref:`maple-ide-install` page.

.. contents:: Contents
   :local:

IDE Windows
-----------

The following screenshot shows the appearance of a Maple IDE window:

.. figure:: /_static/img/ide-blinky.png
   :align: center
   :alt: Maple IDE

Note the toolbar buttons at the top; they're the icons with circles or
squares around them.  You can program your board mostly through the
use of these buttons, which are described in the next section.

Toolbar Buttons
---------------

.. _ide-verify:

Verify
~~~~~~

.. image:: /_static/img/button-verify.png
   :align: left

Click Verify to compile the current sketch.  This will process your
program and produce an executable which can run on your board.

.. _ide-stop:

Stop
~~~~

.. image:: /_static/img/button-stop.png
   :align: left

Click Stop to cancel a compilation.  Longer programs may take a while
to compile.  Clicking Stop will let you go back to writing code
without having to wait for compilation to finish.

.. _ide-new:

New
~~~

.. image:: /_static/img/button-new.png
   :align: left

Click New to make a fresh sketch.

.. _ide-open:

Open
~~~~

.. image:: /_static/img/button-open.png
   :align: left

Click Open to open an existing sketch.  Maple IDE will first look for
the sketch in your *sketchbook*, which is a folder on your computer
that contains your sketches.  The sketchbook is stored in different
places depending on your operating system.  You can change its
location in the IDE's preferences.

.. _ide-save:

Save
~~~~

.. image:: /_static/img/button-save.png
   :align: left

Click Save to save the currently opened sketch.  This will save all
open tabs, not just the one you're currently looking at.

.. _ide-upload:

Upload
~~~~~~

.. image:: /_static/img/button-upload.png
   :align: left

Click Upload to send the compiled sketch to your Maple to run.  Before
you click Upload, you must have a memory location and serial port
selected.

The memory location, either Flash or RAM, determines whether the
compiled sketch binary will be stored on the Maple.  You can choose
this using the Tools > Board menu.

The serial port corresponds to the :ref:`SerialUSB <lang-serialusb>`
connection the Maple establishes with your computer.  This looks like
"COM1", "COM2", etc. on Windows, "/dev/tty.usbmodemXXX" on Mac (where
"XXX" is some sequence of letters and numbers), or "/dev/ttyACMXXX" on
Linux (again, where "XXX" is some sequence of letters and numbers).
You can choose a serial port using the Tools > Serial Port menu.

If you're trying to upload and are unsuccessful, make sure you've made
choices for both board and serial port.  More help on uploading
(including screenshots) is available in the :ref:`quickstart
<maple-quickstart-upload>`.

If all else fails, try putting your Maple in :ref:`perpetual
bootloader mode <troubleshooting-perpetual-bootloader>` before
uploading.  You can always find us on the `forum`_ or `contact us
directly`_ for help on any problems you're having.

.. _ide-serial-monitor:

Serial Monitor
~~~~~~~~~~~~~~

.. image:: /_static/img/button-serial-monitor.png
   :align: left

Click Serial Monitor to open up a communication channel between your
PC and the Maple's :ref:`SerialUSB <lang-serialusb>` virtual serial
port.

If the serial monitor is open, any information sent to the computer
(for example, using :ref:`SerialUSB.println()
<lang-serialusb-println>`) will be displayed in the large text area.
You can send data to the Maple by typing into the small text box and
either hitting the Enter key or pressing the Send button.  (The Maple
can read the data you send with :ref:`SerialUSB.read()
<lang-serialusb-read>`).

Here is an example serial monitor session with the InteractiveTest
sketch (which you can load in the IDE by choosing menu item File >
Examples > Maple > InteractiveTest):

.. image:: /_static/img/serial-monitor.png

This is the result of typing "?" in the text box and clicking Send.

.. note:: You cannot upload a sketch while the serial monitor is open.
   If you click :ref:`Upload <ide-upload>` while the serial monitor is
   open, the IDE will close it for you before proceeding with the
   upload.

.. _ide-examples:

Example Code
------------

Maple IDE comes with a variety of sample code you can use to help you
get started writing your own programs.  To load an example in a new
Maple IDE window, choose one from the submenus under File > Examples.
