#include <stdio.h>
#include <stdint.h>

typedef enum 
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING
} DataType;

typedef union 
{
    int i;
    float f;
    char str[20];
} SensorData;

typedef struct 
{
    uint8_t id;       // ID sensor
    DataType type;    // Loại dữ liệu
    SensorData data;  // Dữ liệu sensor
} Packet;

/*
typedef struct 
{
    // data 
    char name[50];
    int age;
    __int8_t gender; // 1 byte
    double salary;   // 8 bytes
    __int16_t Heso; // 2 bytes
    char address[100];
    
} NhanVien;
*/
void main()
{
    /*
    NhanVien NV_PE[10];
    NV_PE[0] = (NhanVien){"Kieu Anh Dung", 42, 1, 20.505, 80,"Gia Lam, Ha Noi"};
    NV_PE[1] = (NhanVien){"Nguyen Dang Nghia", 40, 1, 20.501, 80,"Cau Giay, Ha Noi"};
    NV_PE[2] = (NhanVien){"Trinh Thi Yen", 36, 0, 15.505, 60,"Soc Son, Ha Noi"};
    for(int i = 0; i < 3; i++)
    {
        printf("Name: %s\n", NV_PE[i].name);
        printf("Age: %d\n", NV_PE[i].age);  
        printf("Gender: %d\n", NV_PE[i].gender);
        printf("Salary: %.3f\n", NV_PE[i].salary);
        printf("Heso: %d\n", NV_PE[i].Heso);
        printf("Address: %s\n", NV_PE[i].address);
        printf("\n");
    }
    printf("Test structure memory layout\n");
    for(int i = 0; i < 3; i++)
    {
        printf("Address of NV_PE[%d]: %p\n", i, (void*)&NV_PE[i]);
        printf("  Address of name: %p\n", (void*)&NV_PE[i].name);
        printf("  Address of age: %p\n", (void*)&NV_PE[i].age);
        printf("  Address of gender: %p\n", (void*)&NV_PE[i].gender);
        printf("  Address of salary: %p\n", (void*)&NV_PE[i].salary);
        printf("  Address of Heso: %p\n", (void*)&NV_PE[i].Heso);
        printf("  Address of address: %p\n", (void*)&NV_PE[i].address);
        printf("\n");
    }
    */
    // Sử dụng union và struct để mô phỏng gói dữ liệu từ cảm biến
    Packet p;

    // Sensor gửi int
    p.id = 1;
    p.type = TYPE_INT;
    p.data.i = 123;

    if (p.type == TYPE_INT) {
        printf("Sensor %d sent int: %d\n", p.id, p.data.i);
    }

    // Sensor gửi float
    p.id = 2;
    p.type = TYPE_FLOAT;
    p.data.f = 3.14;

    if (p.type == TYPE_FLOAT) {
        printf("Sensor %d sent float: %.2f\n", p.id, p.data.f);
    }

    // Sensor gửi string
    p.id = 3;
    p.type = TYPE_STRING;
    snprintf(p.data.str, sizeof(p.data.str), "OK");

    if (p.type == TYPE_STRING) {
        printf("Sensor %d sent string: %s\n", p.id, p.data.str);
    }
}