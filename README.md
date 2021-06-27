# Test task: parsing cli calculator
This is a project of a natural math notation parsing calculator with
command-line interface

## Details
For more details please see `doc/task.pdf`. Notes, side thoughts and sources
can be found in `doc/notes`

## Assumptions
* all operations are binary, i.e. every operator __always__ has __two__
  operands
* allowed input symbols are:
  * digits 0-9
  * operators +, -, \*, /
  * parenthesis (, )
  * floating point separator is both . and ,
  * an opening parenthesis is __always__ followed by an operand or a closing
    parenthesis, otherwise the expression is incorrect
