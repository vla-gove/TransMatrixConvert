#include <math.h>
#include <iostream>

void matrix_to_xyzrpy(double matrix[4][4], double &x, double &y, double &z, double &roll, double &pitch, double &yaw) {
    x = matrix[0][3];
    y = matrix[1][3];
    z = matrix[2][3];

    double sy = sqrt(matrix[0][0] * matrix[0][0] + matrix[1][0] * matrix[1][0]);
    if (sy > 1e-6) {
        roll = atan2(matrix[2][1], matrix[2][2]);
        pitch = atan2(-matrix[2][0], sy);
        yaw = atan2(matrix[1][0], matrix[0][0]);
    } else {
        roll = atan2(-matrix[1][2], matrix[1][1]);
        pitch = atan2(-matrix[2][0], sy);
        yaw = 0;
    }
}

int main(){

    double mat[4][4];
    double x, y, z, roll, yaw, pitch;

    std::cout << "input transformation matrix parameters:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << "element [" << i << "][" << j << "]:";
            std::cin >> mat[i][j];
        }
    }
    matrix_to_xyzrpy(mat,x,y,z,roll,pitch,yaw);

    std::cout << "x y z roll pitch yaw parameters are:\n";
    std::cout << x << ", " << y << ", " << z << ", " << roll << ", " << pitch << ", " << yaw;


};
