#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Demo by Tuan k67 - IT2

// Email của Đại học Bách Khoa có dạng như sau:
// Họ tên: Từ Minh Tuân
// MSSV: 20225422
// Email sẽ là: tuan.tm225422@sis.hust.edu.vn

// Gồm: Tên + . + Lần lượt các ký tự đầu tiên của họ và tên đệm + 6 chữ số cuối MSSV + @hust.edu.vn

void main(void) {
    printf("Nhap ho va ten (viet khong dau): ");
    char s[100];
    fgets(s, 100, stdin); // fgets đọc cả ký tự xuống dòng nên cẩn thận lỗi ở đây
    // Loại bỏ ký tự newline khi dùng fgets()
    int del = strlen(s) - 1;
    s[del] = '\0';
    printf("Nhap MSSV: ");
    int MSSV;
    scanf("%d", &MSSV);
    for (int i = 0; i < strlen(s); i++) {
        s[i] = tolower(s[i]);
    }
    char a[20][20]; // ở đây tạo bất kỳ, thấy hợp lí là okayy
    int n = 0;
    char *token = strtok(s, " ");
    while ( token != NULL) {
        strcpy(a[n], token);
        ++n;
        token = strtok(NULL, " ");
    }
    // ở đây màu mè thui
    for(int i = 0; i < 25; i++) {
        printf("-");
    }
    printf("\n");
    printf("Email Hust cua ban la:\n");
    // In ra tên 
    printf("%s", a[n - 1]);
    // In ra dấu .
    printf(".");
    // In ra lần lượt từng chữ cái đầu của họ và tên đệm
    for (int i = 0; i < n - 1; i++) {
        printf("%c", a[i][0]);
    }
    // In ra 6 chữ số cuối của MSSV 
    printf("%d", MSSV % (1000000));
    // In ra @hust.edu.vn
    printf("@hust.edu.vn");
}