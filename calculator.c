#include<stdio.h>
#include<string.h>
void main (){
    printf("----------------------------\n");
    printf("            Welcome to Matrix Calculator\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|choose the Operation would you like to perform:            |\n");
    printf("|1)Addition='+'                2)Subtraction='-'            |\n");
    printf("|3)Multiplication='*'          4)Transpose='a'              |\n");
    printf("|5)Determinent='b'             6)Inverse='c'                |\n");
    printf("|7)Rank='d'                    8)Trivial and Non-Trivial='e'|\n");
    printf("|9)Cayley Hamilton='f'        10)Eigen Values and Vector='g'|\n");
    printf("|-----------------------------------------------------------|\n");
    int r,c;
    printf("Enter the number of row : ");
    scanf("%d", &r);
    getchar();
    printf("Enter the number of colum : ");
    scanf("%d", &c);
    int arr1[50][50],brr1[50][50],crr1[50][50],i,j,k,mul[50][50],det=0,determinant=0,rank;
    printf("\nEnter Operation Symbol given above:\n");
        char opt;
        getchar();
        scanf("%c", &opt);
        if(opt == '+' || opt == '*' || opt == '-'){
            printf("Input elements in the first matrix :\n");
            for (int i  = 0; i < c; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    printf("element - [%d],[%d] : ", i, j);
                    getchar();
                    scanf("%d", &arr1[i][j]);
                }
            }
            printf("Input elements in the second matrix :\n");
            for (int i = 0; i < c; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    printf("element - [%d],[%d] : ", i, j);
                    getchar();
                    scanf("%d", &brr1[i][j]);
                }
            }
            printf("\nThe First matrix is :\n");
            for (int i = 0; i < c; i++)
            {
                printf("\n");
                for (int j = 0; j < r; j++)
                    printf("%d\t", arr1[i][j]);
            }
            printf("\nThe Second matrix is :\n");
            for (int i = 0; i < c; i++)
            {
                printf("\n");
                for (int j = 0; j < r; j++)
                    printf("%d\t", brr1[i][j]);
            }
        } else{
                        printf("Input elements of the matrix :\n");
            for (int i  = 0; i < c; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    printf("element - [%d],[%d] : ", i, j);
                    getchar();
                    scanf("%d", &arr1[i][j]);
                }
            }
            printf("\nThe matrix is :\n");
            for (int i = 0; i < c; i++)
            {
                printf("\n");
                for (int j = 0; j < r; j++)
                    printf("%d\t", arr1[i][j]);
            }
        }
switch(opt){
    case '+':
    for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    crr1[i][j] = arr1[i][j] + brr1[i][j];
            printf("\nThe Addition of two matrix is : \n");
            for (int i = 0; i < r; i++)
            {
                printf("\n");
                for (int j = 0; j < c; j++)
                    printf("%d\t", crr1[i][j]);
            }
            break;
    case '-':
                for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    crr1[i][j] = arr1[i][j] - brr1[i][j];
            printf("\nThe Subtraction of two matrix is : \n");
            for (int i = 0; i < r; i++)
            {
                printf("\n");
                for (int j = 0; j < c; j++)
                    printf("%d\t", crr1[i][j]);
            }
            break;
    case '*':
    printf("\nMultiply of the Matrix=\n");
            for (i = 0; i < r; i++)
            {
                for (j = 0; j < c; j++)
                {
                    mul[i][j] = 0;
                    for (k = 0; k < c; k++)
                    {
                        mul[i][j] += arr1[i][k] * brr1[k][j];
                    }
                }
            }
            //for printing result
            for (i = 0; i < r; i++)
            {
                for (j = 0; j < c; j++)
                {
                    printf("%d\t", mul[i][j]);
                }
                printf("\n");
            }
            break;
    case 'a':
                printf("\nTranspose of the matrix=\n");
            for (i = 0; i < c; i++)
            {
                for (j = 0; j < r; j++)
                {
                    printf("%d\t", arr1[j][i]);
                }
                printf("\n");
            }
            break;
    case 'b':
            for (i = 0; i < r; i++)
                det = det + (arr1[0][i] * (arr1[1][(i + 1) % r] * arr1[2][(i + 2) % r] - arr1[1][(i + 2) % r] * arr1[2][(i + 1) % r]));
            printf("\nThe Determinant of the matrix is|A|: %d\n\n", det);
            break;
    case 'c':
    for (i = 0; i < 3; i++)
                determinant = determinant + (arr1[0][i] * (arr1[1][(i + 1) % r] * arr1[2][(i + 2) % r] - arr1[1][(i + 2) % r] * arr1[2][(i + 1) % r]));
            printf("\nInverse of matrix is: \n\n");
            for (i = 0; i < r; i++)
            {
                for (j = 0; j < c; j++)
                    printf("%.2f\t", ((arr1[(i + 1) % c][(j + 1) % c] * arr1[(i + 2) % c][(j + 2) % c]) - (arr1[(i + 1) % c][(j + 2) % c] * arr1[(i + 2) % 3][(j + 1) % c])) / determinant);
                printf("\n");
            }
            break;
    case 'd':
    for (c = 0; c < rank; c++) {
        if (arr1[c][c]) {
            for (r = 0; r < c; r++) {
                if (r != c) {
                    float ratio = (float)arr1[r][c] / arr1[c][c];
                    for (k = 0; k < rank; k++)
                        arr1[r][k] -= ratio * arr1[c][k];
                }
            }
        } else {
            int reduce = 1;

            for (i = c + 1; i < c; i++) {
                if (arr1[i][c]) {
                    for (j = 0; j < rank; j++) {
                        int temp = arr1[c][j];
                        arr1[c][j] = arr1[i][j];
                        arr1[i][j] = temp;
                    }
                    reduce = 0;
                    break;
                }
            }

            if (reduce) {
                rank--;

                for (i = 0; i < c; i++)
                    arr1[i][c] = arr1[i][rank];
            }
            c--;
        }
    }

    printf("\nRank of the matrix is: %d\n", rank);

                break;
    case 'e':
                for (i = 0; i < r; i++)
                det = det + (arr1[0][i] * (arr1[1][(i + 1) % r] * arr1[2][(i + 2) % r] - arr1[1][(i + 2) % r] * arr1[2][(i + 1) % r]));
            printf("\nThe Determinant of the matrix is|A|: %d\n\n", det);
            if (det == 0)
            {
                printf("-------------------------------\n");
                printf("Matrix has Non-Trivial Solution\n");
                printf("-------------------------------\n");
            }
            else
            {
                printf("---------------------------\n");
                printf("Matrix has Trivial Solution\n");
                printf("---------------------------\n");
            }
            break;
    case 'f':
                printf("Under Construction");
                break;
    case 'g':
                printf("Under Construction");
                break;
    default :
    printf("Enter valid value");


    }
}
