#include <bits/stdc++.h>
using namespace std;
// khai báo struct lop
struct Lop
{
    char maLop[50], tenLop[50];
    int soSinhVien;
};
// struct node lớp
struct nodeLop
{
    Lop data;
    struct nodeLop *next;
};
struct ListLop
{
    nodeLop *Head;
    nodeLop *Tail;
};
ListLop dsl;
void initLop(ListLop &dsl)
{
    dsl.Head = NULL;
    dsl.Tail = NULL;
}
nodeLop *getNode(Lop l)
{
    nodeLop *p;
    p = new nodeLop();
    if (p == NULL)
    {
        cout << "Khong du bo nho";
        exit(1);
    }
    p->data = l;
    p->next = NULL;
    return p;
}
void themVaoDauDSLop(ListLop &dsl, nodeLop *p)
{
    if (dsl.Head == NULL)
    {
        dsl.Head = p;
        dsl.Head = dsl.Tail;
    }
    else
    {
        p->next = dsl.Head;
        dsl.Head = p;
    }
}
void themVaoCuoiDSLop(ListLop &dsl, nodeLop *p)
{
    if (dsl.Head == NULL)
    {
        dsl.Head = p;
        dsl.Head = dsl.Tail;
    }
    else
    {
        dsl.Tail->next = p;
        dsl.Tail = p;
    }
}
void nhap1Lop(Lop &l)
{
    cin.ignore();
    cout << "Nhap ma lop:";
    gets(l.maLop);
    cout << "Nhap ten lop:";
    gets(l.tenLop);
    cout << "Nhap so sinh vien:";
    cin >> l.soSinhVien;
}
void hien1Lop(Lop l)
{
    cout << left << setw(15) << l.maLop;
    cout << left << setw(15) << l.tenLop;
    cout << left << setw(15) << l.soSinhVien;
}
void nhapDSLop(ListLop &dsl)
{
    Lop l;
    nodeLop *p;
    int n;
    cout << "Nhap so luong lop:";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Lop thu " << i + 1 << ":" << endl;
        nhap1Lop(l);
        p = getNode(l);
        themVaoCuoiDSLop(dsl, p);
    }
}
void tieuDe()
{
    cout << left << setw(15) << "Ma Lop";
    cout << left << setw(15) << "Ten Lop";
    cout << left << setw(15) << "So Sinh Vien";
    cout << endl;
}
void hienDSLop(ListLop dsl)
{
    nodeLop *p;
    cout << "-------- Danh sach lop -------" << endl;
    tieuDe();
    for (p = dsl.Head; p != NULL; p = p->next)
    {
        hien1Lop(p->data);
        cout << endl;
    }
}
// khai báo struct khoa

struct SinhVien
{
    char maSinhVien[20], hoTen[50], SDT[15], diaChi[50];
    int tuoi, gioiTinh;
    float diemTrungBinh;
    // Lop l;
    // Khoa k;
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
    // cout << "Nhap khoa sinh vien:";
    // cin>> sv.k;
    cin.ignore();
    cout << "Nhap so dien thoai:";
    gets(sv.SDT);
    cout << "Nhap dia chi:";
    gets(sv.diaChi);
    cout << "Nhap diem trung binh:";
    cin >> sv.diemTrungBinh;
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

    cout << left << setw(15) << sv.tuoi;
    // cout << left<< setw(12)<< sv.l;
    // cout << left<< setw(12)<< sv.k;
    cout << left << setw(15) << sv.SDT;
    cout << left << setw(15) << sv.diaChi;
    cout << left << setw(15) << sv.diemTrungBinh;
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
    cout << left << setw(15) << "Tuoi";
    cout << left << setw(15) << "SDT";
    cout << left << setw(15) << "Dia Chi";
    cout << left << setw(15) << "Diem Trung Binh";
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
    float sum;
    int count = 0;
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        sum = sum + p->data.diemTrungBinh;
        count++;
    }
    cout << "Diem trung binh cua sinh vien :" << sum / count;
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

void menuSV()
{
    cout << "|------------- SINH VIEN --------------|" << endl;
    cout << "|1.Nhap danh sach sinh vien            |" << endl;
    cout << "|2.Hien danh sach sinh vien            |" << endl;
    cout << "|3.Ghi file sinh vien                  |" << endl;
    cout << "|4.Doc file sinh vien                  |" << endl;
    cout << "|5.Them sinh vien vao danh sach        |" << endl;
    cout << "|6.Sap xep danh sach sinh vien         |" << endl;
    cout << "|7.Tim kiem sinh vien theo ma sinh vien|" << endl;
    cout << "|8.Xoa sinh vien theo ma sinh vien     |" << endl;
    cout << "|9.Tinh diem trung binh cua sinh vien  |" << endl;
    cout << "|10.Liet ke danh sach sinh vien nu     |" << endl;
    cout << "|0.Thoat                               |" << endl;
}
void chucNangSV()
{
    FILE *f;
    SinhVien sv;
    nodeSV *p;
    initSV(dssv);
    int option;

    while (option != 0)
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
        default:
            cout << "Moi ban chon lai !" << endl;
            break;
        }
    }
}
struct Khoa
{
    char maKhoa[50], tenKhoa[50];
};
struct nodeKhoa
{
    Khoa data;
    struct nodeKhoa *next;
};
struct ListKhoa
{
    nodeKhoa *Head;
    nodeKhoa *Tail;
};
ListKhoa dsk;
void initKhoa(ListKhoa &dsk)
{
    dsk.Head = NULL;
    dsk.Tail = NULL;
}
nodeKhoa *getNode(Khoa k)
{
    nodeKhoa *p;
    p = new nodeKhoa();
    if (p == NULL)
    {
        cout << "Khong du bo nho";
        exit(1);
    }
    p->data = k;
    p->next = NULL;
    return p;
}
void themVaoDauDSKhoa(ListKhoa &dsk, nodeKhoa *p)
{
    if (dsk.Head == NULL)
    {
        dsk.Head = p;
        dsk.Tail = dsk.Head;
    }
    else
    {
        p->next = dsk.Head;
        dsk.Head = p;
    }
}
void themVaoCuoiDSKhoa(ListKhoa &dsk, nodeKhoa *p)
{
    if (dsk.Head == NULL)
    {
        dsk.Head = p;
        dsk.Tail = dsk.Head;
    }
    else
    {
        dsk.Tail->next = p;
        dsk.Tail = p;
    }
}
void nhap1Khoa(Khoa &k)
{
    cin.ignore();
    cout << "Nhap ma khoa:";
    gets(k.maKhoa);
    cout << "Nhap ten khoa:";
    gets(k.tenKhoa);
}
void hien1Khoa(Khoa k)
{
    cout << left << setw(15) << k.maKhoa;
    cout << left << setw(15) << k.tenKhoa;
}
void nhapDSKhoa(ListKhoa &dsk)
{
    Khoa k;
    nodeKhoa *p;
    cout << "Nhap so luong khoa:";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap khoa thu " << i + 1 << ":" << endl;
        nhap1Khoa(k);
        p = getNode(k);
        themVaoCuoiDSKhoa(dsk, p);
    }
}
void tieuDeKhoa()
{
    cout << left << setw(15) << "Ma Khoa";
    cout << left << setw(15) << "Ten Khoa";
    cout << endl;
}
void hienDSKhoa(ListKhoa dsk)
{
    nodeKhoa *p;
    cout << "----- Danh sach khoa -----" << endl;
    tieuDeKhoa();
    for (p = dsk.Head; p != NULL; p = p->next)
    {
        hien1Khoa(p->data);
        cout << endl;
    }
}

int main()
{
    // chucNangSV();
    Lop l;
    nodeLop*p;
    initLop(dsl);
    nhapDSLop(dsl);
    hienDSLop(dsl);
    // Khoa k;
    // Khoa them;
    // nodeKhoa*p;
    // initKhoa(dsk);
    // nhapDSKhoa(dsk);
    // hienDSKhoa(dsk);
    // nhap1Khoa(them);
    // p=getNode(them);
    // themVaoCuoiDSKhoa(dsk,p);
    // hienDSKhoa(dsk);
    // nhapDSSV(dssv);
    // ghiFileSV(dssv,f);
    // sapXepDiemTB(dssv);
    // searchMSV(dssv);
    // tinhDiemTrungBinh(dssv);
    // lietKeSinhVienNu(dssv);
}



// thanhkute sua dong nay