REPORT.DEFINE
=============

Equivalent to clicking the Report Manager command on the View menu and
then clicking the Add option in the Report Manager dialog box. Creates
or replaces a report definition. If this function is not available, you
must install the Report Manager add-in.

**Syntax**

**REPORT.DEFINE**(**report\_name, sections\_array**, pages\_logical)

Report\_name    specifies the name of the report. If the workbook
already contains a report with report\_name, the new report replaces the
existing one.

Sections\_array    is an array that contains one or more rows of view,
scenario, and sheet name that define the report. The sheet name is the
sheet on which the view and scenario are defined. If the sheet name is
not specified, the current sheet is used when REPORT.DEFINE is run.

Pages\_logical    is a logical value that, if TRUE or omitted, specifies
continuous page numbers for multiple sections or, if FALSE, resets page
numbers to 1 for each new section.

**Remarks**

-   REPORT.DEFINE returns the \#VALUE error value if report\_name is
    > invalid or if the workbook is protected.

-   If there are no reports defined, this function will bring up the Add
    > Report dialog box.

**Related Functions**

REPORT.DELETE   Removes a report from the active workbook

REPORT.PRINT   Prints a report

REPORT.GET   Returns information about reports defined for the active
workbook

Return to [top](#Q)

REPORT.DELETE