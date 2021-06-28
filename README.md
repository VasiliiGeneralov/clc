# Test task: parsing cli calculator
This is a project of a natural math notation parsing calculator with
command-line interface

## Build
The build is CMake-based, to build and compile run following commands:
```shell
cmake -B build && cmake --build build --target all
```

## Invocation
To use the calculator consider invoking it as:
```shell
./build/clc
```
After start the calculator will wait for your input, one should enter the whole
expression at once:
```shell
./build/clc
1 + 3
4
```

## Unit tests
Tests are implemented as a separate executable and can be found in:
```shell
./build/tests
```

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
