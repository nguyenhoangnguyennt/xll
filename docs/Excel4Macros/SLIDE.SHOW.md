SLIDE.SHOW
==========

This function should not be used in Microsoft Excel 95 or later because
the Slide Show add-in is available only in Microsoft Excel version 5.0
or earlier versions.

Equivalent to clicking the Start Show button on a slide show sheet.
Starts the slide show in the active sheet.

If this function is not available, you must install the Slide Show
add-in.

**Syntax**

**SLIDE.SHOW**(initialslide\_num, repeat\_logical, dialogtitle\_text,
allownav\_logical, allowcontrol\_logical)

**SLIDE.SHOW**?(initialslide\_num, repeat\_logical, dialogtitle\_text,
allownav\_logical, allowcontrol\_logical)

All arguments except dialogtitle\_text correspond to options and
settings in the Start Show dialog box.

Initialslide\_num    is a number from 1 to the number of slides in the
slide show and specifies which slide to display first. If omitted, it is
assumed to be 1.

Repeat\_logical    is a logical value specifying whether to repeat or
end the slide show after displaying the last slide. If repeat\_logical
is TRUE, the slide show repeats; if FALSE or omitted, the slide show
ends.

Dialogtitle\_text    is text enclosed in quotation marks that specifies
the title of the dialog boxes displayed during the slide show. If
dialogtitle\_text is omitted, it is assumed to be \"Slide Show\".

Allownav\_logical    is a logical value specifying whether to enable or
disable navigational keys (arrow keys, PAGE UP, PAGE DOWN, and so on) or
the mouse during the slide show. If allownav\_logical is TRUE or
omitted, you can press navigational keys or use the mouse to move
between slides; if FALSE, all movement is controlled by the slide show
sheet settings.

Allowcontrol\_logical    is a logical value specifying whether to enable
or disable the Slide Show Options dialog box during the slide show. If
allowcontrol\_logical is TRUE or omitted, you can press ESC to interrupt
the slide show and display the dialog box; if FALSE, pressing ESC stops
the slide show but does not display the dialog box.

**Tip   **If you want to display the last slide in a show but don\'t
know its number, use SLIDE.GET(1) as the initialslide\_num argument.

**Remarks**

SLIDE.SHOW returns the values shown in the following table:

+----------------------------------------------+----------------------+
| > **Situation**                              | > **Returned value** |
+----------------------------------------------+----------------------+
| > The slide show ends normally.              | > TRUE               |
+----------------------------------------------+----------------------+
| > You press the Cancel button when using the | > FALSE              |
| > dialog-box form.                           |                      |
+----------------------------------------------+----------------------+
| > The active sheet is not a slide show or is | > \#N/A              |
| > protected.                                 |                      |
+----------------------------------------------+----------------------+
| > You interrupt the slide show, and then     | > 1                  |
| > stop it.                                   |                      |
+----------------------------------------------+----------------------+

Return to [top](#Q)

SOLVER.ADD