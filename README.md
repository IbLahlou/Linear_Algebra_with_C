# Matrix Multiplication C Program

This repository contains a simple C program to perform matrix multiplication. The program multiplies two rectangular matrices and prints the resulting matrix.

## Prerequisites

To compile and run this C program locally, you need to have GCC (GNU Compiler Collection) installed on your system.

## Local Usage

1. Clone this repository to your local machine using `git clone`.

```bash
git clone https://github.com/IbLahlou/matrix-multiplication-c.git
```

2. Change into the project directory.

```bash
cd matrix-multiplication-c
```

3. Compile the C program using GCC.

```bash
gcc -o program main.c
```

4. Run the compiled program.

```bash
./program
```

The program will multiply two predefined matrices and print the resulting matrix in the terminal.

## Customization

You can modify the `main.c` file to perform matrix multiplication with your custom input matrices. Just update the `mat1` and `mat2` arrays with your desired matrices and adjust the dimensions `m1`, `m2`, `n1`, and `n2` accordingly.

## Using Docker

Alternatively, you can use Docker to run the C program without installing GCC locally.

1. Make sure you have Docker installed on your system.

2. Build the Docker image.

```bash
docker build -t matrix-multiplication-c .
```

3. Run the Docker container.

```bash
docker run matrix-multiplication-c
```

The program will run inside the Docker container, and the resulting matrix will be printed in the terminal.

## License

This project is licensed under the MIT License. Feel free to use and modify it as needed.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or create a pull request.

## Acknowledgments

The code in this repository is a simple implementation of matrix multiplication in C for educational purposes.

```
