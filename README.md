# Inventory Management System

This project is a simple inventory management system built in C++.

## Features

- Manage a list of products (add, update, delete)
- Notify suppliers when stock is low
- Support for multiple supplier types (local, global)

## Build Instructions

1. Create a `build` directory:

```bash
mkdir build
cd build
```

2. Run CMake: (note: install cmake if you have not installed)

```bash
cmake ..
```

3. Build project:

```bash
make
```

4. Run the executable:

```bash
./inventory-management
```

Note: Step 2, 3 and 4 has been simplied in makefile so we can skip them and simply run

```bash
make run
```
