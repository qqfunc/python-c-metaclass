# python-c-metaclass
Python C extension metaclass test.

## problems
On macOS, the following program in `src/cmeta/cmeta.c` line 78 causes a segmentation fault.

```c
((MetaObject*) &MyObjectType)->value = 0;
```

If I change the `int` in line 6 to `long`, `ThirdObject.value` disappears. (Raises `AttributeError`.)
Its sample is in the `long` branch.
