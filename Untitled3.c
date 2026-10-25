#include <stdio.h>

// Dinh nghia cac hang so nghiep vu kho hang
#define TAI_TRONG_TOI_DA 500.0  // Tai trong toi da cho phep tren mot ke kho (kg)
#define NHIET_DO_MIN -18.0      // Nhiet do bao quan toi thieu cho phep (do C)
#define NHIET_DO_MAX 5.0        // Nhiet do bao quan toi da cho phep (do C)

// Ham kiem tra va thuc hien nhap pallet vao ke kho lanh
// Tra ve 1 neu du dieu kien nhap kho, tra ve 0 neu vi pham an toan
int kiem_tra_nhap_kho_lanh(float khoi_luong_pallet, float nhiet_do_bao_quan, float tai_trong_hien_tai) {
    // 1. Kiem tra dieu kien tai trong tich luy cua ke kho
    if (tai_trong_hien_tai + khoi_luong_pallet > TAI_TRONG_TOI_DA) {
        printf("Loi: Tai trong vuot qua muc cho phep (Toi da %.1f kg)!\n", TAI_TRONG_TOI_DA);
        return 0;
    }

    // 2. Kiem tra dieu kien nhiet do an toan kho lanh
    // KHAC PHUC: Thay toan tu || (OR) bang toan tu && (AND)
    // Nhiet do bat buoc phai dong thoi thoa man: >= NHIET_DO_MIN VA <= NHIET_DO_MAX
    // Neu dung toan tu ||, bieu thuc se bao trum toan bo truc so thuc (-oo, +oo) lam lot hang loi
    if (nhiet_do_bao_quan >= NHIET_DO_MIN && nhiet_do_bao_quan <= NHIET_DO_MAX) {
        return 1;
    } else {
        printf("Loi: Nhiet do bao quan %.1f do C khong phu hop kho lanh (Chuan: %.1f do C den %.1f do C)!\n", 
               nhiet_do_bao_quan, NHIET_DO_MIN, NHIET_DO_MAX);
        return 0;
    }
}

int main() {
    float tai_trong_hien_tai = 320.0; // Tai trong hien tai tren ke (kg)
    float khoi_luong_pallet;
    float nhiet_do_bao_quan;

    printf("=== HE THONG KIEM DINH NHAP KHO LANH SMARTLOG ===\n");
    printf("Tai trong hien tai tren ke: %.1f kg / %.1f kg\n\n", tai_trong_hien_tai, TAI_TRONG_TOI_DA);

    printf("Nhap khoi luong pallet (kg): ");
    if (scanf("%f", &khoi_luong_pallet) != 1) {
        printf("Loi: Du lieu khoi luong khong hop le!\n");
        return 1;
    }

    printf("Nhap nhiet do bao quan yeu cau (do C): ");
    if (scanf("%f", &nhiet_do_bao_quan) != 1) {
        printf("Loi: Du lieu nhiet do khong hop le!\n");
        return 1;
    }

    int ket_qua = kiem_tra_nhap_kho_lanh(khoi_luong_pallet, nhiet_do_bao_quan, tai_trong_hien_tai);

    if (ket_qua == 1) {
        tai_trong_hien_tai += khoi_luong_pallet;
        printf("\n=> PHE DUYET: Nhap kho thanh cong!\n");
        printf("Tai trong ke kho sau khi nhap: %.1f kg\n", tai_trong_hien_tai);
    } else {
        printf("\n=> TU CHOI: Kien hang khong du dieu kien vao kho lanh!\n");
        printf("Tai trong ke kho giu nguyen: %.1f kg\n", tai_trong_hien_tai);
    }

    return 0;
}
