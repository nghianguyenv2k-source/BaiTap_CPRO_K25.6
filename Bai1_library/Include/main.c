#include <stdio.h>
#include <string.h>
#include "book.h"

int main() 
{
    Book library[MAX_BOOKS];   // Mảng chứa danh sách sách
    int book_count = 0;        // Biến đếm số lượng sách hiện có

    int choice;

    add_book(library, &book_count, "Thep da toi the day", "Nicolai Ostrovsky", 101);
    add_book(library, &book_count, "Tay Du ky", "Ngo Thua An", 102);
    add_book(library, &book_count, "Tam quoc dien nghia", "La Quan Trung", 103);
    add_book(library, &book_count, "Viet Nam Su Luoc", "Tran Trong Kim", 104);
    add_book(library, &book_count, "The C Programming Language", "Brian Kernighan", 105);
    add_book(library, &book_count, "Clean Code", "Robert C. Martin", 106);
    add_book(library, &book_count, "Truyen Kieu", "Nguyen Du", 107);
    add_book(library, &book_count, "Hoang Le Nhat Thong", "Ngo Gia Van Phai", 108);
    add_book(library, &book_count, "Dai so Tuyen tinh", "Van Nhu Cuong", 109);
    add_book(library, &book_count, "Ky Thuat mach dien tu", "Pham Minh Ha", 110);


    /* Test các hàm đã viết
    display_all_books(library, book_count);
    delete_book(library, &book_count, 104);
    display_all_books(library, book_count);
    
    edit_book(library, book_count, 103, "Tam quoc dien nghia - Edited", NULL);
    display_all_books(library, book_count);
    borrow_book(library, book_count, 102);
    display_all_books(library, book_count);
    */

    
    do {
        printf("=====================================\n");
        printf("     CHUONG TRINH QUAN LY THU VIEN\n");
        printf("=====================================\n");
        printf("1. Them sach moi\n");
        printf("2. Sua thong tin sach\n");
        printf("3. Muon sach\n");
        printf("4. Hien thi tat ca sach\n");
        printf("5. Tim sach theo ID\n");
        printf("6. Tim sach theo ten\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        getchar(); // đọc bỏ ký tự newline sau scanf
        printf("**************************************\n\n");

        switch (choice)     
        {
            case 1: 
            {
                int id;
                char title[100], author[100];
                printf("Nhap ID: "); scanf("%d", &id); getchar();
                printf("Nhap ten sach: "); fgets(title, sizeof(title), stdin);
                printf("Nhap tac gia: "); fgets(author, sizeof(author), stdin);

                // loại bỏ ký tự '\n' cuối chuỗi (do fgets)
                title[strcspn(title, "\n")] = 0;
                author[strcspn(author, "\n")] = 0;

                add_book(library, &book_count, title, author, id);
            }
            break;
            /*-------------------------------------------*/
            case 2:
            {
                int id;
                char title[100], author[100];
                printf("Nhap ID sach can sua: "); scanf("%d", &id); getchar();
                printf("Nhap ten moi (bo trong neu giu nguyen): ");
                fgets(title, sizeof(title), stdin);
                printf("Nhap tac gia moi (bo trong neu giu nguyen): ");
                fgets(author, sizeof(author), stdin);

                title[strcspn(title, "\n")] = 0;
                author[strcspn(author, "\n")] = 0;

                // Nếu người dùng để trống, truyền NULL
                const char *new_title = strlen(title) ? title : NULL;
                const char *new_author = strlen(author) ? author : NULL;

                if (!edit_book(library, book_count, id, new_title, new_author))
                    printf("Khong tim thay sach co ID %d\n", id);
            }
            break;
            /* ------------------------------*/
            case 3:
            {
                int id;
                printf("Nhap ID sach can muon: ");
                scanf("%d", &id);
                if (!borrow_book(library, book_count, id))
                    printf("Khong the muon sach co ID %d\n", id);
            }
            break;
            /*-------------------------*/
            case 4: 
            display_all_books(library, book_count);
            break;
            /*------------------------------------*/
            case 5:
            {
                int id;
                printf("Nhap ID sach: ");
                scanf("%d", &id);
                int idx = find_book_by_id(library, book_count, id);
                if (idx != -1)
                    print_book(&library[idx]);
                else
                    printf("Khong tim thay sach co ID %d\n", id);
            }
        
            default:
            break;
        }

    } while (choice != 0);
    

    printf("Thoat chuong trinh.\n");
    return 0;
}



