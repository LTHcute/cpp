#include <bits/stdc++.h>
using namespace std;
// khai báo struct lop
struct Lop
{
    char maLop[50], tenLop[50];
    int soSinhVien;
};
// khai bao struct khoa
struct Khoa
{
    char maKhoa[50], tenKhoa[50];
};

// khai bao struct sinh vien
struct SinhVien
{
    char maSinhVien[20], hoTen[50], SDT[15], diaChi[50];
    int tuoi, gioiTinh;
    float diemTrungBinh;
    Lop lop;
    Khoa khoa;
};

struct nodeSV
{
    SinhVien data;
    struct nodeSV *next;
};
struct ListSV
{
    nodeSV *Head;
    nodeSV *Tail;
};
ListSV dssv;
void initSV(ListSV &dssv)
{
    dssv.Head = NULL;
    dssv.Tail = NULL;
}

// cấp phát động một node với dữ liệu sinh viên
nodeSV *getnode(SinhVien sv)
{
    nodeSV *p;
    p = new nodeSV();
    if (p == NULL)
    {
        cout << "Khong du bo nho";
        exit(1);
    }
    p->data = sv;
    p->next = NULL;
    return p;
}
void nhap1SV(SinhVien &sv)
{
    cin.ignore();
    cout << "Nhap ma sinh vien:";
    gets(sv.maSinhVien);
    cout << "Nhap ho ten sinh vien:";
    gets(sv.hoTen);
    cout << "Nhap gioi tinh:  0-nam    1-nu ";
    cin >> sv.gioiTinh;
    cout << "Nhap tuoi sinh vien:";
    cin >> sv.tuoi;
    cin.ignore();
    cout << "Nhap so dien thoai:";
    gets(sv.SDT);
    cout << "Nhap dia chi:";
    gets(sv.diaChi);
    cout << "Nhap diem trung binh:";
    cin >> sv.diemTrungBinh;

    cin.ignore();
    cout << "Nhap ma khoa sinh vien:";
    gets(sv.khoa.maKhoa);
    cout << "Nhap ten khoa sinh vien:";
    gets(sv.khoa.tenKhoa);
    cout << "Nhap ma lop:";
    gets(sv.lop.maLop);
    cout << "Nhap ten lop:";
    gets(sv.lop.tenLop);
    sv.lop.soSinhVien++;
    cin.ignore();
}
void hien1SV(SinhVien sv)
{
    cout << left << setw(15) << sv.maSinhVien;
    cout << left << setw(20) << sv.hoTen;
    if (sv.gioiTinh == 0)
    {
        cout << left << setw(12) << "Nam";
    }
    else
    {
        cout << left << setw(12) << "Nu";
    }

    cout << left << setw(8) << sv.tuoi;
    cout << left << setw(15) << sv.SDT;
    cout << left << setw(15) << sv.diaChi;
    cout << left << setw(18) << sv.diemTrungBinh;
    cout << left << setw(15) << sv.khoa.maKhoa;
    cout << left << setw(15) << sv.khoa.tenKhoa;
    cout << left << setw(15) << sv.lop.maLop;
    cout << left << setw(15) << sv.lop.tenLop;
}
void themVaoDauDSSV(ListSV &dssv, nodeSV *p)
{
    if (dssv.Head == NULL)
    {
        dssv.Head = p;
        dssv.Tail = dssv.Head;
    }
    else
    {
        p->next = dssv.Head;
        dssv.Head = p;
    }
}
void themVaoCuoiDSSV(ListSV &dssv, nodeSV *p)
{
    if (dssv.Head == NULL)
    {
        dssv.Head = p;
        dssv.Tail = dssv.Head;
    }
    else
    {
        dssv.Tail->next = p;
        dssv.Tail = p;
    }
}
void nhapDSSV(ListSV &dssv)
{
    SinhVien sv;
    nodeSV *p;
    int n;
    cout << "Nhap so luong sinh vien:";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap sinh vien thu " << i + 1 << ":" << endl;
        nhap1SV(sv);
        p = getnode(sv);
        themVaoCuoiDSSV(dssv, p);
    }
}
void tieuDeSV()
{
    cout << left << setw(15) << "Ma Sinh Vien";
    cout << left << setw(20) << "Ho Ten";
    cout << left << setw(12) << "Gioi Tinh";
    cout << left << setw(8) << "Tuoi";
    cout << left << setw(15) << "SDT";
    cout << left << setw(15) << "Dia Chi";
    cout << left << setw(18) << "Diem Trung Binh";
    cout << left << setw(15) << "Ma khoa";
    cout << left << setw(15) << "Ten khoa";
    cout << left << setw(15) << "Ma lop";
    cout << left << setw(15) << "Ten lop";
    cout << endl;
}
void hienDSSV(ListSV dssv)
{
    cout << "----------- Danh sach sinh vien -----------" << endl;
    tieuDeSV();
    nodeSV *p;
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        hien1SV(p->data);
        cout << endl;
    }
}
void ghiFileSV(ListSV &dssv, FILE *f)
{
    SinhVien sv;
    nodeSV *p;
    int n = 0;
    f = fopen("sinhvien.dat", "wb");
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        n = n + 1;
    }
    fwrite(&n, sizeof(int), 1, f);
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        fwrite(&p->data, sizeof(SinhVien), 1, f);
    }
    fclose(f);
    cout << "Ghi file thanh cong!" << endl;
}
void docFileSV(ListSV &dssv, FILE *f)
{
    nodeSV *p;
    SinhVien sv;
    int i, n = 0;
    f = fopen("sinhvien.dat", "rb");
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        n = n + 1;
    }
    fread(&n, sizeof(int), 1, f);
    for (int i = 0; i < n; i++)
    {
        fread(&sv, sizeof(SinhVien), 1, f);
        p = getnode(sv);
        themVaoCuoiDSSV(dssv, p);
    }
    fclose(f);
    cout << "Doc file khachhang.dat thanh cong!!!" << endl;
}
void xoaSinhVienTheoMa(ListSV &dssv)
{
    char ma[50];
    cout << "Nhap ma sinh vien ma ban muon xoa:";
    cin.ignore();
    gets(ma);
    // trường hợp mã cần xóa ở đầu danh sách
    nodeSV *p;
    p = new nodeSV();
    if (dssv.Head->data.maSinhVien == ma)
    {
        p = dssv.Head;
        dssv.Head = dssv.Head->next;
        p->next = NULL;
        delete p;
    }
    // trường hợp mã cần xóa ở cuối danh sách

    if (dssv.Tail->data.maSinhVien == ma)
    {
        for (p = dssv.Tail; p != NULL; p = p->next)
        {
            if (p->next == dssv.Tail)
            {
                delete dssv.Tail;
                p->next = NULL;
                dssv.Tail = p;
            }
        }
    }
    for (nodeSV *k = dssv.Head; k != NULL; k = k->next)
    {
        if (k->data.maSinhVien == ma)
        {
            // gan con tro next cua node p bang con tro next cua node k
            p->next = k->next;
            // xoa di node k
            delete k;
            // ket thuc ham
            return;
        }
        // gan node p bang node k de node p luon la node dung truoc node k
        p = k;
    }
}
nodeSV *searchMSV(ListSV dssv)
{
    cout << "Nhap ma sinh vien ban muon tim:";
    string msv;
    cin.ignore();
    getline(cin, msv);
    nodeSV *p;
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        if (p->data.maSinhVien == msv)
        {
            tieuDeSV();
            hien1SV(p->data);
            break;
        }
        else
        {
            cout << "Khong tim thay sinh vien nao" << endl;
        }
    }
}
void sapXepDiemTB(ListSV dssv)
{
    nodeSV *p, *q;
    SinhVien tg;
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data.diemTrungBinh < q->data.diemTrungBinh)
            {
                tg = p->data;
                p->data = q->data;
                q->data = tg;
            }
        }
    }
    hienDSSV(dssv);
}
void tinhDiemTrungBinh(ListSV dssv)
{
    nodeSV *p;
    float sum = 0;
    int count = 0;
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        sum = sum + p->data.diemTrungBinh;
        count++;
    }
    cout << "Diem trung binh cua sinh vien :" << sum / count;
    cout << endl;
}
void lietKeSinhVienNu(ListSV dssv)
{
    nodeSV *p;
    cout << "\n ------- Danh sach sinh vien nu ------" << endl;
    tieuDeSV();
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        if (p->data.gioiTinh == 1)
        {
            hien1SV(p->data);
            cout << endl;
        }
    }
}
void lietKeSinhVienNam(ListSV dssv)
{
    nodeSV *p;
    cout << "\n -------- Danh sach sinh vien nam --------" << endl;
    tieuDeSV();
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        if (p->data.gioiTinh == 0)
        {
            hien1SV(p->data);
            cout << endl;
        }
    }
}
void danhSachTheoKhoa(ListSV dssv)
{
    nodeSV *p;
    char khoaCanTim[20];
    cout << "Nhap ten khoa muon tim danh sach:";
    cin.ignore();
    gets(khoaCanTim);
    cout << "-------- Danh sach khoa " << khoaCanTim << " --------" << endl;
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        if (strcmp(p->data.khoa.tenKhoa, khoaCanTim) == 0)
        {
            hien1SV(p->data);
            cout << endl;
        }
    }
}

void menuSV()
{
    cout << "|-------------------- SINH VIEN -------------------|" << endl;
    cout << "|1.Nhap danh sach sinh vien                        |" << endl;
    cout << "|2.Hien danh sach sinh vien                        |" << endl;
    cout << "|3.Ghi file sinh vien                              |" << endl;
    cout << "|4.Doc file sinh vien                              |" << endl;
    cout << "|5.Them sinh vien vao danh sach                    |" << endl;
    cout << "|6.Sap xep danh sach sinh vien                     |" << endl;
    cout << "|7.Tim kiem sinh vien theo ma sinh vien            |" << endl;
    cout << "|8.Xoa sinh vien theo ma sinh vien                 |" << endl; // k xóa được
    cout << "|9.Tinh diem trung binh cua sinh vien              |" << endl;
    cout << "|10.Liet ke danh sach sinh vien nu                 |" << endl;
    cout << "|11.Liet ke danh sach sinh vien nam                |" << endl;
    cout << "|12.Danh sach sinh vien cua khoa nhap vao          |" << endl; // chưa hiện
    cout << "|0.Thoat                                           |" << endl;
}
void chucNangSV()
{
    FILE *f;
    SinhVien sv;
    nodeSV *p;
    initSV(dssv);
    int option;

    while (true)
    {
        menuSV();
        cout << "Nhap su lua chon cua ban:";
        cin >> option;
        switch (option)
        {
        case 1:
            nhapDSSV(dssv);
            break;
        case 2:
            hienDSSV(dssv);
            break;
        case 3:
            ghiFileSV(dssv, f);
            break;
        case 4:
            docFileSV(dssv, f);
            hienDSSV(dssv);
            break;
        case 5:
            nhap1SV(sv);
            p = getnode(sv);
            themVaoCuoiDSSV(dssv, p);
            hienDSSV(dssv);
            cout << endl;
            break;
        case 6:
            sapXepDiemTB(dssv);
            break;
        case 7:
            searchMSV(dssv);
            break;
        case 8:
            xoaSinhVienTheoMa(dssv);
            hienDSSV(dssv);
            break;
        case 9:
            tinhDiemTrungBinh(dssv);
            break;
        case 10:
            lietKeSinhVienNu(dssv);
            break;
        case 11:
            lietKeSinhVienNam(dssv);
            break;
        case 12:
            danhSachTheoKhoa(dssv);
            break;
        case 0:
            exit(1);
        default:
            cout << "Moi ban chon lai !" << endl;
            break;
        }
    }
}

int main()
{
    chucNangSV();
}

// thanhkute sua dong nay