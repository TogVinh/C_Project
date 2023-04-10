#include <stdio.h>

#define N 256 // Định nghĩa N là số ký tự lớn nhất có thể đọc từ một dòng
#define ROW 3 // Định nghĩa số dòng sẽ đọc trong file

// Khai báo cấu trúc mảng để lưu chuỗi và số trích xuất từ dòng
typedef struct str
{
    char str[16];
    float f_data[5];
} data;

int main(void)
{
    FILE *fp; //
    char fname[] = "test.csv";
    char line[N];
    char str[16];
    float f1, f2, f3, f4, f5;
    int i = 0;

    // Khởi tạo thực thể từ kiểu cấu trúc data
    data data[ROW];

    fp = fopen(fname, "r"); // Mở file bằng hàm fopen, trả về NULL khi thất bại
    if (fp == NULL)
    {
        printf("%s file not open!\n", fname);
        return -1;
    }
    // Đọc từng dòng trong file bằng hàm fgets
    while (fgets(line, N, fp) != NULL)
    {
        // Trích xuất thông tin từ nội dung file bằng hàm sscanf
        sscanf(line, "%[^,],%f,%f,%f,%f,%f", str, &f1, &f2, &f3, &f4, &f5);

        // Gán các nội dung trích xuất được lần lượt vào trong thực thể của cấu trúc
        for (int j = 0; j < sizeof(data[i].str) / sizeof(data[i].str[0]); j++)
        {
            data[i].str[j] = str[j];
        }
        float tmp[] = {f1, f2, f3, f4, f5};
        for (int j = 0; j < sizeof(data[i].f_data) / sizeof(data[i].f_data[0]); j++)
        {
            data[i].f_data[j] = tmp[j];
        }

        // Xuất giá trị các thành viên trong thực thể của cấu trúc
        printf("%s,%.1f,%.1f,%.1f,%.1f,%.1f\n", data[i].str, data[i].f_data[0], data[i].f_data[1], data[i].f_data[2], data[i].f_data[3], data[i].f_data[4]);
        i++;
    }

    fclose(fp); // Đóng file

    return 0;
}
