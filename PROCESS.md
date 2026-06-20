# TODO

- receive the 3 params.
- Alloc in a double pointer twice. `actual` & `next`.
- read each data from `STD_IN`.
- Execute for each `read` the instructions into `actual`.
- Exec a main loop:

    ```c
        while (iter--)
            for (size_t y = 0; y < h; y++)
                for (size_t x = 0; x < w; x++)
                    ver_cell(y, x, grade);
    ```
