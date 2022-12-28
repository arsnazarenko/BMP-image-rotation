# Assignment: Image rotation

## Requipments:

- clang
- make
- clang-tidy


```
./image-transformer <source-image> <transformed-image>
```

## Build and tests
1. Build
```shell
$ make SANITIZER=<sanitizer>
```
Binary file located in `build` directory 
The following values for sanitizers are supported:
* asan
* msan 
* usan 
* none
* all

For each sanitizer, separate subdirectories are created in the `build` directory
You can override the build flags by setting the `CFALGS` environment variable or by editing `compile_flags.txt` file

2. Clang-tidy checks
```shell
$ make check
```
You can override the checks by setting the `CLANG_TIDY_CHECKS` environment variable or by editing `clang-tidy-checks.txt` file

3. Tests
```shell
$ make -k test-<name>
```
You can use `make -k test` to execute all tests for one binary all `make -k test SANITIZER=all` to run all tests for all build versions

