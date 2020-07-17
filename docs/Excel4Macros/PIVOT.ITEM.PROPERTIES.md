PIVOT.ITEM.PROPERTIES
=====================

Changes the properties of an item within a header field.

**Syntax**

**PIVOT.ITEM.PROPERTIES**(name, pivot\_field\_name, pivot\_item\_name,
new\_name, position, show, active\_page)

Name    is the name of the PivotTable report containing the item which
the user wants to edit.

Pivot\_field\_name    is the name of a field in the PivotTable report
containing the item which the user would like to edit. If it is omitted,
Microsoft Excel uses the field containing the active cell.

Pivot\_item\_name    is the name of the item which the user would like
to edit. If it is omitted, Microsoft Excel uses the item containing the
active cell.

New\_name    is the name which you would like to rename the current
item. If it is omitted, then the name of the current item will not
change.

Position    is a number representing where in the field the item will
appear. Position 1 is the topmost position within the row field, the
leftmost position within the column field, and the highest position
within the page field. If the position argument is omitted, it will
default to the last position in the field.

Show    is a logical value which if TRUE causes the item to appear in
the PivotTable report. If FALSE, the item will be hidden.

Active\_page    is a logical value specifying whether item\_name will
become the active item in the page field. If TRUE then item\_name will
become the active item in the page field. If FALSE or omitted, the
active item in the page field does not change. Applies to only page
fields.

**Remarks**

-   If name is omitted, Microsoft Excel will use the PivotTable report
    > containing the active cell.

-   If pivot\_field\_name is not a header field, then this function will
    > return the \#VALUE! error value.

**Related Functions**

PIVOT.ADD.DATA   Adds a field to a PivotTable report as a data field

PIVOT.ADD.FIELDS   Adds fields to a PivotTable report

PIVOT.FIELD   Pivots fields within a PivotTable report

PIVOT.FIELD.GROUP   Creates groups within a PivotTable report

PIVOT.FIELD.PROPERTIES   Changes the properties of a field inside a
PivotTable report

PIVOT.FIELD.UNGROUP   Ungroups all selected groups within a PivotTable
report

PIVOT.ITEM   Moves an item within a PivotTable report

PIVOT.REFRESH   Refreshes a PivotTable report

PIVOT.SHOW.PAGES   Creates new sheets in the workbook containing the
active cell

PIVOT.TABLE.WIZARD   Creates an empty PivotTable report

Return to [top](#H)

PIVOT.REFRESH