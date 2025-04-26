#include <iostream>
#include <string>
#include <vector>

using namespace std;

//
class NhanVien {
protected:
    string Ten;
    int SoGioLam;

public:
    
    NhanVien(string ten, int soGioLam) {
        Ten = ten;
        SoGioLam = soGioLam;
    }

    virtual double TinhLuong() = 0;

    
    void XuatThongTin() {
        cout << "Ten: " << Ten << " | So Gio Lam: " << SoGioLam << " | Luong: " << TinhLuong() << " VND" << endl;
    }
};


class NhanVienToanThoiGian : public NhanVien {
public:
    
    NhanVienToanThoiGian(string ten, int soGioLam) : NhanVien(ten, soGioLam) {}

    
    double TinhLuong() override {
        return SoGioLam * 50000; 
    }
};


class NhanVienBanThoiGian : public NhanVien {
public:
    
    NhanVienBanThoiGian(string ten, int soGioLam) : NhanVien(ten, soGioLam) {}

    double TinhLuong() override {
        return SoGioLam * 30000; 
    }
};

int main() {
    vector<NhanVien*> danhSachNhanVien;
    int n;

    
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore();  

    
    for (int i = 0; i < n; ++i) {
        string ten;
        int soGioLam, loaiNhanVien;
        
        cout << "Nhap ten nhan vien #" << i + 1 << ": ";
        getline(cin, ten);
        
        cout << "Nhap so gio lam cua nhan vien #" << i + 1 << ": ";
        cin >> soGioLam;
        
        cout << "Chon loai nhan vien (1 - Toan Thoi Gian, 2 - Ban Thoi Gian): ";
        cin >> loaiNhanVien;
        cin.ignore();  

        if (loaiNhanVien == 1) {
            danhSachNhanVien.push_back(new NhanVienToanThoiGian(ten, soGioLam));
        } else if (loaiNhanVien == 2) {
            danhSachNhanVien.push_back(new NhanVienBanThoiGian(ten, soGioLam));
        } else {
            cout << "Loai nhan vien khong hop le!" << endl;
        }
    }
    
    cout << "\n--- Bang Luong ---\n";
    for (int i = 0; i < danhSachNhanVien.size(); ++i) {
        danhSachNhanVien[i]->XuatThongTin();
    }
    
    for (int i = 0; i < danhSachNhanVien.size(); ++i) {
        delete danhSachNhanVien[i];
    }

    return 0;
}
