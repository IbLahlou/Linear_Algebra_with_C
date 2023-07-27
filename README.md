# Linear Algebra C Programs

This repository contains three simple C programs for linear algebra operations. The programs included are:

1. **Matrix Multiplication**: This program performs matrix multiplication of two rectangular matrices and prints the resulting matrix.

2. **Determinant**: This program calculates the determinant of a square matrix.

3. **Regression**: This program demonstrates linear regression using C, performing a simple linear regression on a given dataset.

## Prerequisites

To compile and run these C programs locally, you need to have GCC (GNU Compiler Collection) installed on your system.

## Local Usage

1. Clone this repository to your local machine using `git clone`.

```bash
git clone https://github.com/IbLahlou/linear-algebra-c.git
```

2. Change into the project directory.

```bash
cd linear-algebra-c
```

3. Compile the C programs using GCC.

```bash
gcc -o matrix_multiplication matrix_multiplication.c
gcc -o determinant determinant.c
gcc -o regression regression.c
```

4. Run the compiled programs.

```bash
./matrix_multiplication
./determinant
./regression
```

The respective programs will be executed, and the results will be printed in the terminal.

## Using Docker

Alternatively, you can use Docker to run the C programs without installing GCC locally.

1. Make sure you have Docker installed on your system.

2. Build the Docker image.

```bash
docker build -t linear_algebra-c .
```

3. Run the Docker container.

```bash
docker run linear_algebra-c
```

The programs will run inside the Docker container, and the results will be printed in the terminal.

## License

This project is licensed under the MIT License. Feel free to use and modify it as needed.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or create a pull request.

## Acknowledgments

The code in this repository provides simple implementations of linear algebra operations in C for educational purposes.
