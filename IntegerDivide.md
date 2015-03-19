# Why is there no integer divide routine in the library? #
Because GCC already generates optimal assembly code for dividing by an integer constant.

`x/3`, for instance, is translated to `((x*CONSTANT)>>32)`, where `CONSTANT` is `(1<<32)/3`.