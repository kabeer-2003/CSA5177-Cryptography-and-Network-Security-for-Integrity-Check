#include<stdio.h>
#include<math.h>
float encrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];
void encryption(); 
void getKeyMessage(); 
int main() {
getKeyMessage();
encryption();
}
void encryption() {
int i, j, k;
for(i = 0; i < 3; i++)
for(j = 0; j < 1; j++)
for(k = 0; k < 3; k++)
encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];
printf("\nEncrypted string is: ");
for(i = 0; i < 3; i++)
printf("%c", (char)(fmod(encrypt[i][0], 26) + 97));
}
void getKeyMessage() {
int i, j;
char msg[3];
printf("Enter 3x3 matrix for key:\n");
for(i = 0; i < 3; i++)
for(j = 0; j < 3; j++) {
scanf("%f", &a[i][j]);
c[i][j] = a[i][j];
}
printf("\nEnter a 3 letter string: ");
scanf("%s", msg);
for(i = 0; i < 3; i++)
mes[i][0] = msg[i] - 97;
}