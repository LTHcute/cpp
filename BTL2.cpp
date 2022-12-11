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
    cout << left << setw(10) << sv.lop.maLop;
    cout << left << setw(10) << sv.lop.tenLop;
}
// 5. thêm sinh vien vào đầu danh sách
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
// 6.Thêm sinh vien vao cuối danh sách
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

// so sinh vien trong dssv
int Size(ListSV dssv) {
    int cnt = 0;
    while(dssv.Head != NULL) {
        ++cnt;
        dssv.Head = dssv.Head->next;
    }
    return cnt;
}


void InsertAfter(ListSV &dssv, nodeSV *q, nodeSV *new_element ) {
    if(q != NULL) {
        new_element->next = q->next;
        q->next = new_element;
        if(q == dssv.Tail) {
            dssv.Tail = new_element;
        }
    }
}

// them sinh vien vao giua danh sach
void themVaoGiuaDSSV(ListSV &dssv) {//, nodeSV *p, char msv) {
    SinhVien sv;
    nhap1SV(sv);
    nodeSV* p = getnode(sv);

    char msv[20];
    cout<<"Nhap ma sv ban muon them sv dang sau: ";
    gets(msv);
    cout<<msv<<endl;

    nodeSV* a;
    for (a = dssv.Head; a != NULL; a = a->next)
    {
        if (strcmp(a->data.maSinhVien, msv) == 0)
        {
            cout<<"tim dc"<<endl;
            InsertAfter(dssv,a,p);
            break;
        }
    }

}


// 7. Thêm sinh viên vào sau một sinh viên
// void themSinhVienSau1SV(ListSV &dssv,nodeSV*p)
// {
//     char maSV[100];
//     cout << "Nhap ma phieu truoc do:";
//     gets(maSV);

// }
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
    cout << left << setw(10) << "Ma lop";
    cout << left << setw(10) << "Ten lop";
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
    cout << "Doc file sinhvien.dat thanh cong!!!" << endl;
}

// xoa phan tu dau
void removeHead(ListSV &dssv) {
    nodeSV *p;
    if(dssv.Head != NULL) {
        p = dssv.Head;
        dssv.Head = dssv.Head->next;
        delete p;
        if( dssv.Head == NULL) {
            dssv.Tail = NULL;
        }
    }
}

// xoa cuoi
void removeTail(ListSV &dssv) {
    if(dssv.Head == NULL) return;
    nodeSV *p;

    if (dssv.Head->next == NULL) {
        delete dssv.Head;
        return;
    }
 
    nodeSV *second_last = dssv.Head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
 
    delete (second_last->next);
 
    second_last->next = NULL;

}


// tach ra 3 cai
void xoaSinhVienTheoMa(ListSV &dssv)
{
    char msv[50];
    cin.ignore();
    cout<<"Nhap ma sinh vien ban muon xoa: ";
    gets(msv);

    //tao node p de luu tru phan tu truoc node k can xoa
    nodeSV *p = new nodeSV();
    //neu data dau vao bang voi pHead->data thi xoa dau
    if(strcmp(dssv.Head->data.maSinhVien,msv) == 0){
        //goi ham xoa dau
        removeHead(dssv);
        //ket thuc ham
        return;
    }
    //neu data bang voi pTail->data thi xoa cuoi
    if(strcmp(dssv.Tail->data.maSinhVien,msv) == 0){
        //goi ham xoa cuoi
        removeTail(dssv);
        //ket thuc ham
        return;
    }

    //duyet qua cac phan tu co trong danh sach
    for(nodeSV *k = dssv.Head; k != NULL; k=k->next){
        //neu tim thay data trung voi k->data dang duyet
        if(strcmp(k->data.maSinhVien,msv) == 0){
            //gan con tro next cua node p bang con tro next cua node k
            p->next = k->next;
            //xoa di node k
            delete k;
            //ket thuc ham
            return;
        }
        //gan node p bang node k de node p luon la node dung truoc node k
        p = k;
    }
}

// danh sach sinh vien co diem trung binh cao nhat
void dtbCaoNhat(ListSV &dssv) {
   
	nodeSV* p = new nodeSV();

	float max = dssv.Head->data.diemTrungBinh;

    for(nodeSV *k = dssv.Head; k != NULL; k=k->next){
        //neu tim thay data trung voi k->data dang duyet
        if(k->data.diemTrungBinh > max){
            max = k->data.diemTrungBinh;
        }
    }
    cout<<"Danh sach sinh vien co diem trung binh cao nhat la"<<endl;
    tieuDeSV();
    for(nodeSV *k = dssv.Head; k != NULL; k=k->next){
        //neu tim thay data trung voi k->data dang duyet
        if(k->data.diemTrungBinh == max){
            hien1SV(k->data);
        }
    }
    cout<<endl;
}


// danh sach sinh vien co diem trung binh thap nhat
void dtbThapNhat(ListSV &dssv) {
	nodeSV* p = new nodeSV();

	float min = dssv.Head->data.diemTrungBinh;

    for(nodeSV *k = dssv.Head; k != NULL; k=k->next){
        //neu tim thay data trung voi k->data dang duyet
        if(k->data.diemTrungBinh < min){
            min = k->data.diemTrungBinh;
        }
    }
    cout<<"Danh sach sinh vien co diem trung binh thap nhat la"<<endl;
    tieuDeSV();
    for(nodeSV *k = dssv.Head; k != NULL; k=k->next){
        //neu tim thay data trung voi k->data dang duyet
        if(k->data.diemTrungBinh == min){
            hien1SV(k->data);
        }
    }
    cout<<endl;
}



// tìm theo mã sinh viên
nodeSV *searchMSV(ListSV dssv)
{
    cin.ignore();
    int cnt = 0;
    cout << "Nhap ma sinh vien ban muon tim:";
    char msv[20];
    gets(msv);
    nodeSV *p;
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        if (strcmp(p->data.maSinhVien, msv) == 0)
        {
            tieuDeSV();
            hien1SV(p->data);
            cnt++;
            cout<<endl;
            break;
        }
    }
    if(cnt == 0) {
        cout<<"Khong tim thay sinh vien"<<endl;
    }
}
// tìm theo tên sinh viên
nodeSV *searchTenSV(ListSV dssv)
{
    cin.ignore();
    cout << "Nhap ten sinh vien ban muon tim:";
    char tenSV[50];
    gets(tenSV);
    int cnt = 0;
    nodeSV *p;
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        if (strcmp(p->data.hoTen, tenSV) == 0)
        {
            tieuDeSV();
            hien1SV(p->data);
            cnt++;
            cout<<endl;
            break;
        }
    }
    if(cnt == 0) {
        cout<<"Khong tim thay sinh vien"<<endl;                 
    }
}
// giảm dần
void sapXepDiemTBGiam(ListSV dssv)
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
// tăng dần
void sapXepDiemTBTang(ListSV dssv)
{
    nodeSV *p, *q;
    SinhVien tg;
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data.diemTrungBinh > q->data.diemTrungBinh)
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
    cout << "Nhap ma khoa muon tim danh sach:";
    cin.ignore();
    gets(khoaCanTim);
    cout << "-------- Danh sach khoa " << khoaCanTim << " --------" << endl;
    tieuDeSV();
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        if (strcmp(p->data.khoa.maKhoa, khoaCanTim) == 0)
        {
            hien1SV(p->data);
            cout << endl;
        }
    }
}
void danhSachtheoLop(ListSV dssv)
{
    nodeSV *p;
    char lopCanTim[20];
    cout << "Nhap ten lop can tim:" << endl;
    cin.ignore();
    gets(lopCanTim);
    cout << "-------- Danh sach khoa " << lopCanTim << " --------" << endl;
    tieuDeSV();
    for (p = dssv.Head; p != NULL; p = p->next)
    {
        if (strcmp(p->data.lop.tenLop, lopCanTim) == 0)
        {
            hien1SV(p->data);
            cout << endl;
        }
    }
}

void menuSV()
{
    cout << "|------------------------- SINH VIEN ----------------------|" << endl;
    cout << "|1.Nhap danh sach sinh vien                                |" << endl;
    cout << "|2.Hien danh sach sinh vien                                |" << endl;
    cout << "|3.Ghi file sinh vien                                      |" << endl;
    cout << "|4.Doc file sinh vien                                      |" << endl;
    cout << "|5.Them sinh vien vao dau danh sach                        |" << endl; // done
    cout << "|6.Them sinh vien vao cuoi danh sach                       |" << endl; // done
    cout << "|7.Sap xep danh sach sinh vien giam dan theo diem          |" << endl; // done
    cout << "|8.Sap xep danh sach sinh vien tang dan theo diem          |" << endl; // done
    cout << "|9.Tim kiem sinh vien theo ma sinh vien                    |" << endl;
    cout << "|10.Tim kiem sinh vien theo ten sinh vien                  |" << endl;
    cout << "|11.Xoa sinh vien theo ma sinh vien                        |" << endl; // done
    cout << "|12.Tinh diem trung binh cua sinh vien                     |" << endl; // done
    cout << "|13.Liet ke danh sach sinh vien nu                         |" << endl; // done
    cout << "|14.Liet ke danh sach sinh vien nam                        |" << endl; // done
    cout << "|15.Danh sach sinh vien cua ma khoa nhap vao               |" << endl; // done
    cout << "|16.Danh sach vien cua lop nhap vao                        |" << endl; // done
    cout << "|17.Danh sach sinh vien co diem trung binh cao nhat        |" << endl; // done
    cout << "|18.Danh sach sinh vien co diem trung binh thap nhat       |" << endl; // done
    cout << "|19.Them sinh vien vao sau sinh vien khac trong danh sach  |"<<endl;   // done
    cout << "|20.Xoa sinh vien dau danh sach                            |"<<endl;
    cout << "|21.Xoa sinh vien cuoi danh sach                           |"<<endl;
    cout << "|0.Thoat                                                   |" << endl;
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
            themVaoDauDSSV(dssv, p);
            hienDSSV(dssv);
            break;
        case 6:
            nhap1SV(sv);
            p = getnode(sv);
            themVaoCuoiDSSV(dssv, p);
            hienDSSV(dssv);
            break;
        case 7:
            sapXepDiemTBGiam(dssv);
            break;
        case 8:
            sapXepDiemTBTang(dssv);
            break;
        case 9:
            searchMSV(dssv);
            break;
        case 10:
            searchTenSV(dssv);
            break;
        case 11:
            xoaSinhVienTheoMa(dssv);
            break;
        case 12:
            tinhDiemTrungBinh(dssv);
            break;
        case 13:
            lietKeSinhVienNu(dssv);
            break;
        case 14:
            lietKeSinhVienNam(dssv);
            break;
        case 15:
            danhSachTheoKhoa(dssv);
            break;
        case 16:
            danhSachtheoLop(dssv);
            break;
        case 17:
            dtbCaoNhat(dssv);
            break;
        case 18:
            dtbThapNhat(dssv);
            break;
        case 19:
            themVaoGiuaDSSV(dssv);
            hienDSSV(dssv);
            break;
        case 20:
            removeTail(dssv);
            hienDSSV(dssv);
            break;
        case 21:
            removeHead(dssv);
            hienDSSV(dssv);
            break;
        case 0:
            exit(1);
            break;
        default:
            cout << "Chon Lai";
            break;
        }
    }
}

int main()
{
    chucNangSV();
}

// thanhkute sua dong nay