# Use the official gcc image as the base image
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the source code into the container's working directory
COPY . /app

# Compile the C program using gcc
RUN gcc -o main main.c
RUN gcc -o Determinant Determinant.c
RUN gcc -o regression regression.c

# Set the default command to run the compiled program
CMD ["./main"]
CMD ["./Determinant"]
CMD ["./regression"]
