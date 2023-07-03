#include<iostream>
#include<string>
#include <iomanip>
#include<fstream>
using namespace std;
void menu(){
    system("cls");
    cout<<"=========================================="<<"\n";
    cout<<"                 MENU "<<"\n";
    cout<<"=========================================="<<"\n";
    cout<<" 1. Nhap danh sach sinh vien"<<"\n";
    cout<<" 2. Hien thi danh sach sinh vien"<<"\n";
    cout<<" 3. Sap xep theo ten"<<"\n";
    cout<<" 4. Sap xep them diem giam dan"<<"\n";
    cout<<" 5. Tim sinh vien theo ten"<<"\n";
    cout<<" 6. Ghi thong tin sinh vien ra file"<<"\n";
    cout<<" 7. Xoa man hinh (clear screen)\n"; 
    cout<<" 0. Thoat"<<endl;    
}
void taocot(){
    cout<<"-----------------------------------------------------"
	"--------------------------------------------------------------------------\n";
    std::cout << std::left << std::setw(20) << "id"
              << std::left << std::setw(20) << "Ten"
              << std::left << std::setw(20) << "Tuoi"
              << std::left << std::setw(20) << "Gioi Tinh"
              << std::left << std::setw(20) << "Diem Toan"
              << std::left << std::setw(20) << "Diem Van"
              << std::left << std::setw(20) << "Diem Anh"
              << std::left << std::setw(20) << "Diem TBC"
              << std::endl;
}
struct sinhvien
{
    /* data */
    int id;
    string ten;
    string tuoi;
    string gioitinh;
    float toan, van, anh,tbc;
    /*----------------------------------------------------------------*/
     void nhapthongtinsinhvien(){
        cout<<"-----------------------------"<<endl;
        cout<<"Nhap ma sinh vien: ";
        cin>>id;
        cout<<"Nhap ten sinh vien: ";
        fflush(stdin); 
        getline(cin,ten);
        cout<<"Nhap gioi tinh sinh vien: ";
        fflush(stdin);
        getline(cin,gioitinh);
        cout<<"Nhap tuoi sinh vien: ";
        fflush(stdin);
        cin>>tuoi;
        fflush(stdin);
        cout<<"Nhap diem toan: ";
        cin>>toan;
        cout<<"Nhap diem van: ";
        cin>>van;
        cout<<"Nhap diem tieng anh: ";
        cin>>anh;
        tbc=(toan + van + anh) / 3;
        system("cls");
   } 
   /*-------------------------------------------------------------------*/
    void inthongtinsinhvien(){
        std::cout << std::left << std::setw(20) << id
              << std::left << std::setw(20) << ten
              << std::left << std::setw(20) << tuoi
              << std::left << std::setw(20) << gioitinh
              << std::left << std::setw(20) << toan
              << std::left << std::setw(20) << van
              << std::left << std::setw(20) << anh
              << std::left << std::setw(20) << tbc
              << std::endl;
    }
};
void dssv(int n, sinhvien A[]){
    taocot();
    for (int i=1;i<=n;i++){
        A[i].inthongtinsinhvien();
    }
    cout<<"-----------------------------------------------------"
	"--------------------------------------------------------------------------\n";
}
void sapxeptheoten(int n, sinhvien A[]) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (A[i].ten[0] > A[j].ten[0]) {
                sinhvien temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}
void giamdan(int n, sinhvien A[]) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (A[i].tbc < A[j].tbc) {
                sinhvien temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

void timkiemtheoten(int n, sinhvien A[], string timkiem){
    int check=0;
    taocot();
     for(int i = 1; i <= n; ++i)
        if (A[i].ten.find(timkiem) != std::string::npos){
            
            A[i].inthongtinsinhvien();
            check++;
        }
    if (check == 0){
        cout<<"Khong co sinh vien nao co tu khoa "<<timkiem<<endl;
        cout<<"Vui long thu lai! ";
    }
    if (check!=0) cout<<"-----------------------------------------------------"
	"--------------------------------------------------------------------------\n";

}
void ghirafile(int n,sinhvien A[]){
    ofstream text;
    text.open("Sinhvien.txt");
    text<<"-----------------------------------------------------"
	"--------------------------------------------------------------------------\n";
   text<< std::left << std::setw(20) << "id"
              << left << setw(20) << "Ten"
              << left << setw(20) << "Tuoi"
              << left << setw(20) << "Gioi Tinh"
              << left << setw(20) << "Diem Toan"
              << left << setw(20) << "Diem Van"
              << left << setw(20) << "Diem Anh"
              << left << setw(20) << "Diem TBC"
              << endl;
    for (int i=1; i<=n;i++){
        text << std::left << setw(20) << A[i].id
              << left << setw(20) << A[i].ten
              << left << setw(20) << A[i].tuoi
              << left << setw(20) << A[i].gioitinh
              << left << setw(20) << A[i].toan
              << left << setw(20) << A[i].van
              << left << setw(20) << A[i].anh
              << left << setw(20) << A[i].tbc
              << endl;

    }
    text<<"-----------------------------------------------------"
	"--------------------------------------------------------------------------\n";
}
int n;
sinhvien A[10000];


int main(){
    int x;
    string timkiem;
    do {
        menu();
        cout<<"Nhap tuy chon ban muon: ";
        cin>>x;
        system("cls");
        switch(x){
            case 0:
                break;
            case 1:
        
                n++;
                A[n].nhapthongtinsinhvien();
                break;
            case 2:
    
                dssv(n,A);
                system("pause");
                break; 
            case 3:
 
                sapxeptheoten(n,A);
                dssv(n,A);
                system("pause");
                break;
            case 4:
                giamdan(n,A);
                dssv(n,A);
                system("pause");
                break;
            case 5:
                cout<<"Nhap ten ban muon tim kiem: ";
                cin>>timkiem;
                timkiemtheoten(n,A,timkiem);
                system("pause");
                break;
            case 6:
                ghirafile(n,A);
            case 7:
                system("cls");
                break;
    } 
    } while(x);

    
    return 0;
}
