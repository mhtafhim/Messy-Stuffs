def det(matrix):
    global dett
    if len(matrix) == 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    else:
        for i in range(0, len(matrix)):
            matrix2 = []
            for j in range(1, len(matrix)):
                row = []
                for k in range(len(matrix[0])):
                    if k != i:
                        row.append(matrix[j][k])
                matrix2.append(row)
            dett += (-1) ** i * matrix[0][i] * det(matrix2)


def main():
    global dett
    dim = int(input("Enter the dimension of the matrix: "))
    matrix = []

    for i in range(dim):
        row = []
        for j in range(dim):
            row.append(int(input()))
        matrix.append(row)

    print("Matrix:")
    print(matrix)

    dett = 0
    det(matrix)

    print("Determinant:", dett)


if __name__ == "__main__":
    main()
