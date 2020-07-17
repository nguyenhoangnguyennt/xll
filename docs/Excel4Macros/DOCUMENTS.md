DOCUMENTS
=========

Returns, as a horizontal array in text form, the names of the specified
open workbooks. Use DOCUMENTS to retrieve the names of open workbooks to
use in other functions that manipulate open workbooks.

**Syntax**

**DOCUMENTS**(type\_num, match\_text)

Type\_num    is a number specifying whether to include add-in workbooks
in the array of workbooks, according to the following table.

  --------------- -----------------------------------------------------
  **Type\_num**   **Returns**
  1 or omitted    Names of all open workbooks except add-in workbooks
  2               Names of add-in workbooks only
  3               Names of all open workbooks
  --------------- -----------------------------------------------------

Match\_text    specifies the workbooks whose names you want returned and
can include wildcard characters. If match\_text is omitted, DOCUMENTS
returns the names of all open workbooks.

**Remarks**

-   Use the INDEX function to select individual workbook names from the
    > array to use in other functions that take workbook names as
    > arguments.

-   Use COLUMNS to count the number of entries in the horizontal array.

-   Use TRANSPOSE to change a horizontal array to a vertical one.

-   Since the DOCUMENTS function only returns actual workbook names, it
    > ignores any changes made by the WINDOW.TITLE function.

>  

**Examples**

In Microsoft Excel for Windows, if your workspace contains windows named
BUDGET.XLS, CHART1, ACTUAL.XLS:1, ACTUAL.XLS:2, and BOOK.XLS, then:

DOCUMENTS (1) equals the four-cell array {\"ACTUAL.XLS\", \"BOOK.XLS\",\
\"BUDGET.XLS\", \"CHART1\"}

SET.NAME(\"Document\_array\", DOCUMENTS()) defines the name,
Document\_array, as {\"ACTUAL.XLS\", \"BOOK.XLS\", \"BUDGET.XLS\",
\"CHART1\"}

In Microsoft Excel for the Macintosh, if your workspace contains windows
named BUDGET CHART1, ACTUALS, ACTUALS:2, and BOOK then:

DOCUMENTS(1) equals the four-cell array {\"ACTUALS\", \"BOOK\",
\"BUDGET\", \"CHART1\"}

**Related Functions**

FILES   Returns the filenames in the specified directory or folder

GET.DOCUMENT   Returns information about a workbook

GET.WINDOW   Returns information about a window

WINDOWS   Returns the names of all open windows

Return to [top](#A)

DUPLICATE