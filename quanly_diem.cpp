#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <mylib.h>
#include <Windows.h>
#include <string.h>
#include <string>
#include <math.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
#define MAXLIST 300
#define MAXMA 5000

#define dai_console 1400
#define rong_console 700

#define so_chuc_nang 11
#define so_chuc_nang_con 3

#define dai_khung_main 60
#define rong_khung_main so_chuc_nang * 2 + 4 - 2
#define ngang_main 4

#define rong_khung_main_sv 2 * 2 + 4

#define dai_khung_chuc_nang 60
#define rong_khung_chuc_nang so_chuc_nang_con * 2 + 4
#define ngang_chuc_nang 4

#define dai_khung_chuc_nang_them0 60
#define rong_khung_chuc_nang_them0 7 * 2 + 4
#define ngang_chuc_nang_them0 4
#define doc_chuc_nang_them0 11

#define dai_khung_chuc_nang_them2 60
#define rong_khung_chuc_nang_them2 7 * 2 + 4
#define ngang_chuc_nang_them2 4
#define doc_chuc_nang_them2 11

#define dai_khung_chuc_nang_them4 60
#define rong_khung_chuc_nang_them4 4 * 2 + 4
#define ngang_chuc_nang_them4 4
#define doc_chuc_nang_them4 7

#define dai_khung_chuc_nang_xoa 60
#define rong_khung_chuc_nang_xoa 2 + 4
#define ngang_chuc_nang_xoa 4
#define doc_chuc_nang_xoa 16

#define dai_khung_danh_sach 104
#define rong_khung_danh_sach 40
#define ngang1_danh_sach 2
#define ngang2_danh_sach 4

#define do_rong_o1_danh_sach0 13 + 1
#define do_rong_o2_danh_sach0 16 + do_rong_o1_danh_sach0 + 1
#define do_rong_o3_danh_sach0 15 + do_rong_o2_danh_sach0 + 1
#define do_rong_o4_danh_sach0 7 + do_rong_o3_danh_sach0 + 1

#define do_rong_o1_danh_sach2 17 + 1
#define do_rong_o2_danh_sach2 14 + do_rong_o1_danh_sach2 + 1
#define do_rong_o3_danh_sach2 12 + do_rong_o2_danh_sach2 + 1
#define do_rong_o4_danh_sach2 6 + do_rong_o3_danh_sach2 + 1

#define do_rong_o1_danh_sach4 26
#define do_rong_o2_danh_sach4 26 * 2
#define do_rong_o3_danh_sach4 26 * 3
#define do_rong_o4_danh_sach4 26 * 4

#define Ten_de_tai "QUAN LY DIEM SINH VIEN THEO HE TIN CHI"

#define ma_system "Color 37"

#define khung_ngoai 178
#define khung_trong 205
#define khung_trong_them 177

#define hien_thanh_sang 121
#define an_thanh_sang 62
#define binh_thuong 55
#define noi_bat 62
#define mau_clear 51

#define mui_ten_len 72
#define mui_ten_xuong 80
#define mui_ten_trai 75
#define mui_ten_phai 77
#define enter 13
#define esc 27
#define backspace 8
#define F1 59

#define dinh_dang_ten 0
#define chi_so 1
#define chi_chu_in_hoa 2
#define chi_so_va_chu_in_hoa 3
#define dinh_dang_nien_khoa 4
#define ket_thuc_nien_khoa 5
#define khoang_trang_cuoi 6
#define password 7
#define chi_so_thap_phan 8
#define dinh_dang_ten_mh 9

#define cau_j 100

using namespace std;

string arr[so_chuc_nang_con];
	
string chuc_nang[so_chuc_nang];

string thuoc_tinh_LTC[7][2]; // phuc vu cho giao dien

string thuoc_tinh_sv[7][2]; //phuc vu cho giao dien

string thuoc_tinh_mon_hoc[4][2]; //phuc vu cho giao dien

string chuyen_int_string(int n){
	string tam = "";
	if(n == 0){
		tam = "0";
		return tam;
	}
	while(n > 0){
		int m = n % 10;
		tam = char(m + 48) + tam;
		n = n / 10;
	}
	return tam;
}

string chuyen_float_string(float n){
	string tam = "";
	if(n == 0){
		tam = "0";
		return tam;
	}
	int thay = n * 10;
	int nguyen = int(n);
	int thap_phan = thay - nguyen * 10;
	
	if(thap_phan == 0){
		tam = chuyen_int_string(nguyen);
	}
	else{
		tam = chuyen_int_string(nguyen) + "." + chuyen_int_string(thap_phan);
	}
	return tam;
}

void TextColor(int x){
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void clear_Area(int x1, int y1, int x2, int y2){
	string clear;
	TextColor(mau_clear);
	for (int i = x1; i <= x2; i++){
		clear = clear + " ";
	}
	for (int i = y1; i <= y2; i++){
		gotoxy(x1, i);
		cout << clear;
	}
	TextColor(binh_thuong);
}

void rang_buoc_chuoi(string &chuoi_duoc_rang_buoc, char &kitu_dang_xet, int kieu_rang_buoc){
	if(kieu_rang_buoc == dinh_dang_ten){
		if(chuoi_duoc_rang_buoc.length() == 0){
			if((kitu_dang_xet >= 65) && (kitu_dang_xet <= 90)){
				chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
			}
			else if((kitu_dang_xet >= 97) && (kitu_dang_xet <= 122)){
				chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet - 32);
			}
		}
		else if(chuoi_duoc_rang_buoc.length() != 0){
			if(chuoi_duoc_rang_buoc[chuoi_duoc_rang_buoc.length() - 1] == 32){
				if((kitu_dang_xet >= 65) && (kitu_dang_xet <= 90)){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
				}
				else if((kitu_dang_xet >= 97) && (kitu_dang_xet <= 122)){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet - 32);
				}
			}
			else{
				if((kitu_dang_xet >= 65) && (kitu_dang_xet <= 90)){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet + 32);
				}
				else if((kitu_dang_xet >= 97) && (kitu_dang_xet <= 122)){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
				}
				else if(kitu_dang_xet == 32){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
				}
			}
		}
	}
	else if(kieu_rang_buoc == dinh_dang_ten_mh){
		if(chuoi_duoc_rang_buoc.length() == 0){
			if((kitu_dang_xet >= 65) && (kitu_dang_xet <= 90)){
				chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
			}
			else if((kitu_dang_xet >= 97) && (kitu_dang_xet <= 122)){
				chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet - 32);
			}
			else if((kitu_dang_xet >= 48) && (kitu_dang_xet <= 57)){
				chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
			}
		}
		else if(chuoi_duoc_rang_buoc.length() != 0){
			if(chuoi_duoc_rang_buoc[chuoi_duoc_rang_buoc.length() - 1] == 32){
				if((kitu_dang_xet >= 65) && (kitu_dang_xet <= 90)){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
				}
				else if((kitu_dang_xet >= 97) && (kitu_dang_xet <= 122)){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet - 32);
				}
				else if((kitu_dang_xet >= 48) && (kitu_dang_xet <= 57)){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
				}
			}
			else{
				if((kitu_dang_xet >= 48) && (kitu_dang_xet <= 57)){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
				}
				else if((kitu_dang_xet >= 65) && (kitu_dang_xet <= 90)){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet + 32);
				}
				else if((kitu_dang_xet >= 97) && (kitu_dang_xet <= 122)){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
				}
				else if(kitu_dang_xet == 32){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
				}
			}
		}
	}
	else if(kieu_rang_buoc == chi_so){
		if((kitu_dang_xet >= 48) && (kitu_dang_xet <= 57)){
			chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
		}
	}
	else if(kieu_rang_buoc == chi_so_thap_phan){
		if((kitu_dang_xet >= 48) && (kitu_dang_xet <= 57)){
			chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
		}
		if(kitu_dang_xet == 46){
			int x = 0;
			for(int i = 0; i < chuoi_duoc_rang_buoc.length(); i++){
				if(chuoi_duoc_rang_buoc[i] == 46){
					x = 1;
					break;
				}
			}
			if(x == 0){		
				chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
			}
		}
	}
	else if(kieu_rang_buoc == chi_chu_in_hoa){
		if((kitu_dang_xet >= 65) && (kitu_dang_xet <= 90)){
			chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
		}
		else if((kitu_dang_xet >= 97) && (kitu_dang_xet <= 122)){
			chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet - 32);
		}
	}
	else if((kieu_rang_buoc == chi_so_va_chu_in_hoa) || ((kieu_rang_buoc == password) && (chuoi_duoc_rang_buoc.length() < 6))){
		if((kitu_dang_xet >= 48) && (kitu_dang_xet <= 57)){
			chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
		}
		else if((kitu_dang_xet >= 65) && (kitu_dang_xet <= 90)){
			chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
		}
		else if((kitu_dang_xet >= 97) && (kitu_dang_xet <= 122)){
			chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet - 32);
		}
	}
	else if(kieu_rang_buoc == dinh_dang_nien_khoa){
		if(chuoi_duoc_rang_buoc.length() == 0){
			if((kitu_dang_xet >= 48) && (kitu_dang_xet <= 57)){
				chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
			}
		}
		else if(chuoi_duoc_rang_buoc.length() != 0){
			if((kitu_dang_xet >= 48) && (kitu_dang_xet <= 57)){
				chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(kitu_dang_xet);
			}
			else if(kitu_dang_xet == 32){
				int gach_noi = 0;
				for(int run = 0; run < chuoi_duoc_rang_buoc.length(); run++){
					if(chuoi_duoc_rang_buoc[run] == 45){
						gach_noi = 1;
						break;
					}
				}
				if((gach_noi == 0) && (chuoi_duoc_rang_buoc[chuoi_duoc_rang_buoc.length() - 1] >= 48) && (chuoi_duoc_rang_buoc[chuoi_duoc_rang_buoc.length() - 1] <= 57)){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(45);
				}
			}
			else if(kitu_dang_xet == 45){
				int gach_noi = 0;
				for(int run = 0; run < chuoi_duoc_rang_buoc.length(); run++){
					if(chuoi_duoc_rang_buoc[run] == 45){
						gach_noi = 1;
						break;
					}
				}
				if(gach_noi == 0){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(45);
				}
			}
		}
	}
	else if(kieu_rang_buoc == ket_thuc_nien_khoa){
		int gach_noi = 0;
		for(int run = 0; run < chuoi_duoc_rang_buoc.length(); run++){
			if(chuoi_duoc_rang_buoc[run] == 45){
				gach_noi = 1;
				break;
			}
		}
		if(gach_noi == 0){
			if(atoi(chuoi_duoc_rang_buoc.c_str()) > 2020){
//				cout <<"aweqweqweqwe";
				chuoi_duoc_rang_buoc = "2020-" + chuoi_duoc_rang_buoc;
			}
			else if(atoi(chuoi_duoc_rang_buoc.c_str()) == 2020){
				chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(45) + "2021";
			}
			else{
				chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + char(45) + "2020";
			}
		}
		else{
			if(chuoi_duoc_rang_buoc[chuoi_duoc_rang_buoc.length()- 1] == 45){
				if(atoi(chuoi_duoc_rang_buoc.substr(0, chuoi_duoc_rang_buoc.length() - 1).c_str()) > 2020){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + chuyen_int_string(atoi(chuoi_duoc_rang_buoc.substr(0,chuoi_duoc_rang_buoc.length() - 1).c_str()) + 1);
				}
				else if(atoi(chuoi_duoc_rang_buoc.c_str()) == 2020){
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + "2021";
				}
				else{
					chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc + "2020";
				}
			}
			else{
				string tam[2];
				int jump = 0;
				for(int run = 0; run < chuoi_duoc_rang_buoc.length(); run++){
					if(chuoi_duoc_rang_buoc[run] == 45){
						jump++;
					}
					else{
						tam[jump] = tam[jump] + chuoi_duoc_rang_buoc[run];
					}
				}
				if(atoi(tam[0].c_str()) > atoi(tam[1].c_str())){
					chuoi_duoc_rang_buoc = tam[1] + "-" + tam[0];
				}
			}
		}
	}
	else if(kieu_rang_buoc == khoang_trang_cuoi){
		if(chuoi_duoc_rang_buoc[chuoi_duoc_rang_buoc.length() - 1] == 32){
			chuoi_duoc_rang_buoc = chuoi_duoc_rang_buoc.substr(0, chuoi_duoc_rang_buoc.length() - 1);
		}
	}
}

int do_rong_con_lai(int danh_sach){
	int n;
	if(danh_sach == 0){
		n = dai_khung_danh_sach - (do_rong_o4_danh_sach0);
	}
	if(danh_sach == 2){
		n = dai_khung_danh_sach - (do_rong_o4_danh_sach2);
	}
	return n;
}

//
struct MonHoc{
	char MAMH[11];
	string TENMH;
	float STCLT,STCTH;
};
struct DsMonHoc{
	int n;
	MonHoc *Ds[MAXLIST];
};
struct SVdangky{
	char MASV[13];
	float Diem;
	struct SVdangky *next;
};
struct LOPTC{
	int MALOPTC,HK,Nhom,SvMax,SvMin;
	string NienKhoa;
	char MAMH[11];
};
struct DsLopTC{
	LOPTC LopTC;
	SVdangky *Dsdk=NULL;
	struct DsLopTC *pLeft;
	struct DsLopTC *pRight;
};
typedef struct DsLopTC* TREE;
struct SinhVien{
	char MASV[13];
	char MALOP[16];
	string HO,TEN,PHAI,SODT,pass;
	int NamNH;
};
struct DanhsachSV{
	SinhVien SV;
	struct DanhsachSV *NEXT;
};

string chuoi_voi_n_ki_tu(string s, int n){
	string tam = s;
	while (tam.length() < n){
		tam = tam + " ";
	}
	return tam;
}

void nhap_tung_ki_tu(string &chuoi_cua_o,char &phim_tra_ve_khi_out, int o_duoc_chon, int chuc_nang_duoc_chon, int them_xoa_sua1_sua2){
//	cout << "nhap chuoi: ";

	int dau_tien = 1;
	
	int ngang_chuc_nang_nhap;
	int doc_chuc_nang_nhap;
	int dai_cua_o;
	
	if(them_xoa_sua1_sua2 == 1){
		if((chuc_nang_duoc_chon == 0) || (chuc_nang_duoc_chon == 2) || (chuc_nang_duoc_chon == 4)){
			ngang_chuc_nang_nhap = ngang_chuc_nang_xoa;
			doc_chuc_nang_nhap = doc_chuc_nang_xoa;
			dai_cua_o = dai_khung_chuc_nang_xoa - doc_chuc_nang_xoa;
			if(chuc_nang_duoc_chon == 2){
				o_duoc_chon = o_duoc_chon - 1;
			}
		}
		else{
			ngang_chuc_nang_nhap = ngang_chuc_nang_xoa - (rong_khung_chuc_nang + 2);
			doc_chuc_nang_nhap = doc_chuc_nang_xoa;
			dai_cua_o = dai_khung_chuc_nang_xoa - doc_chuc_nang_xoa;
		}
	}
	else if(them_xoa_sua1_sua2 == 2){
		ngang_chuc_nang_nhap = ngang_chuc_nang_xoa;
		doc_chuc_nang_nhap = doc_chuc_nang_xoa + 7;
		dai_cua_o = dai_khung_chuc_nang_xoa - doc_chuc_nang_xoa - 7;
		if(chuc_nang_duoc_chon == 2){
			o_duoc_chon = o_duoc_chon - 1;
		}
	}
	else if(them_xoa_sua1_sua2 == 4){
		ngang_chuc_nang_nhap = ngang_chuc_nang_xoa;
		doc_chuc_nang_nhap = doc_chuc_nang_xoa + 1;
		dai_cua_o = dai_khung_chuc_nang_xoa - doc_chuc_nang_xoa - 1;
	}
	else if(them_xoa_sua1_sua2 == 5){
		ngang_chuc_nang_nhap = - rong_khung_chuc_nang - 6;
		doc_chuc_nang_nhap = doc_chuc_nang_xoa + 1 + 8;
		dai_cua_o = dai_khung_chuc_nang_xoa - doc_chuc_nang_xoa - 1 - 9;
	}
	else{
		if(chuc_nang_duoc_chon == 0){
			ngang_chuc_nang_nhap = ngang_chuc_nang_them0;
			doc_chuc_nang_nhap = doc_chuc_nang_them0;
			dai_cua_o = dai_khung_chuc_nang_them0 - doc_chuc_nang_them0;
		}
		if(chuc_nang_duoc_chon == 1){
			ngang_chuc_nang_nhap = ngang_chuc_nang_them0 - (rong_khung_chuc_nang + 2) - 2;
			doc_chuc_nang_nhap = doc_chuc_nang_them0;
			dai_cua_o = dai_khung_chuc_nang_them0 - doc_chuc_nang_them0;
		}
		if(chuc_nang_duoc_chon == 2){
			ngang_chuc_nang_nhap = ngang_chuc_nang_them2 + rong_khung_chuc_nang_xoa + 2;
			doc_chuc_nang_nhap = doc_chuc_nang_them2;
			dai_cua_o = dai_khung_chuc_nang_them2 - doc_chuc_nang_them2;
		}
		if(chuc_nang_duoc_chon == 4){
			ngang_chuc_nang_nhap = ngang_chuc_nang_them4;
			doc_chuc_nang_nhap = doc_chuc_nang_them4;
			dai_cua_o = dai_khung_chuc_nang_them4 - doc_chuc_nang_them4;
		}
		if(them_xoa_sua1_sua2 == 3){
			ngang_chuc_nang_nhap = ngang_chuc_nang_nhap + rong_khung_chuc_nang_xoa + 2;
			if(chuc_nang_duoc_chon == 2){
				ngang_chuc_nang_nhap = ngang_chuc_nang_nhap - 8;
			}
		}
	}
	string xoa = "";
	xoa = chuoi_voi_n_ki_tu(xoa, dai_cua_o - 2);
	char key_nhap;
	while (1){
		key_nhap = getch();
		if((key_nhap == -32) || ((key_nhap == 0))){
			//truong hop la cac phim mui ten
			key_nhap = getch();
			if((key_nhap == mui_ten_len) || (key_nhap == mui_ten_xuong) || (key_nhap == F1)){
				phim_tra_ve_khi_out = key_nhap;
				rang_buoc_chuoi(chuoi_cua_o, key_nhap, khoang_trang_cuoi);
				if(((chuc_nang_duoc_chon == 0) || (chuc_nang_duoc_chon == 1)) && (o_duoc_chon == 2) && (chuoi_cua_o.length() != 0)){
					rang_buoc_chuoi(chuoi_cua_o, key_nhap, ket_thuc_nien_khoa);
				}
				if(((chuc_nang_duoc_chon == 2) || (chuc_nang_duoc_chon == 3)) && (o_duoc_chon == 3) && (chuoi_cua_o.length() != 0)){
					if((chuoi_cua_o != "NAM") && (chuoi_cua_o != "NU")){
						chuoi_cua_o = "NAM";
					}
				}
				TextColor(binh_thuong);
				gotoxy(1 + doc_chuc_nang_nhap, rong_khung_chuc_nang + 2 + ngang_chuc_nang_nhap + 2 + o_duoc_chon * 2 - 1);
				cout << xoa;
				TextColor(noi_bat);
				gotoxy(1 + doc_chuc_nang_nhap, rong_khung_chuc_nang + 2 + ngang_chuc_nang_nhap + 2 + o_duoc_chon * 2 - 1);
				cout << chuoi_cua_o;
				TextColor(binh_thuong);
				break;
			}
		}
		else{
			if((key_nhap == enter) || (key_nhap == esc)){
				phim_tra_ve_khi_out = key_nhap;
				rang_buoc_chuoi(chuoi_cua_o, key_nhap, khoang_trang_cuoi);
				if(((chuc_nang_duoc_chon == 0) || (chuc_nang_duoc_chon == 1)) && (o_duoc_chon == 2) && (chuoi_cua_o.length() != 0)){
					rang_buoc_chuoi(chuoi_cua_o, key_nhap, ket_thuc_nien_khoa);
				}
				if(((chuc_nang_duoc_chon == 2) || (chuc_nang_duoc_chon == 3)) && (o_duoc_chon == 3) && (chuoi_cua_o.length() != 0)){
					if((chuoi_cua_o != "NAM") && (chuoi_cua_o != "NU")){
						chuoi_cua_o = "NAM";
					}
				}
				TextColor(binh_thuong);
				gotoxy(1 + doc_chuc_nang_nhap, rong_khung_chuc_nang + 2 + ngang_chuc_nang_nhap + 2 + o_duoc_chon * 2 - 1);
				cout << xoa;
				TextColor(noi_bat);
				gotoxy(1 + doc_chuc_nang_nhap, rong_khung_chuc_nang + 2 + ngang_chuc_nang_nhap + 2 + o_duoc_chon * 2 - 1);
				cout << chuoi_cua_o;
				TextColor(binh_thuong);
				break;
			}	
			else if(key_nhap == backspace){
				chuoi_cua_o = chuoi_cua_o.substr(0, chuoi_cua_o.length() - 1);
			}
			else{
				if(dau_tien == 1){
					chuoi_cua_o = "";
					dau_tien = 0;
				}
//				chuoi_cua_o = chuoi_cua_o + char(key_nhap);
				if(chuoi_cua_o.length() < 16){
					if((chuc_nang_duoc_chon == 0) || (chuc_nang_duoc_chon == 1)){
						if(o_duoc_chon == 0 && chuoi_cua_o.length()<=4){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so);
						}
						if(o_duoc_chon == 4 && chuoi_cua_o.length()<=4){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so);
						}
						if(o_duoc_chon == 5 && chuoi_cua_o.length()<=4){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so);
						}
						if(o_duoc_chon == 6 && chuoi_cua_o.length()<=3){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so);
						}
						if(o_duoc_chon == 3 && chuoi_cua_o.length()<=2){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so);
						}
						if((o_duoc_chon == 1) && chuoi_cua_o.length() < 12){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so_va_chu_in_hoa);
						}
						if(o_duoc_chon == 2 && chuoi_cua_o.length() < 10){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, dinh_dang_nien_khoa);
						}
					}	
					else if((chuc_nang_duoc_chon == 2) || (chuc_nang_duoc_chon == 3)){	
						if((o_duoc_chon == 0) && (chuoi_cua_o.length() < 17)){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so_va_chu_in_hoa);
						}
						if((o_duoc_chon == 1) && (chuoi_cua_o.length() < 14)){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so_va_chu_in_hoa);
						}
						if((o_duoc_chon == 2) && (chuoi_cua_o.length() < 6)){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so);
						}
						if((o_duoc_chon == 3) && (chuoi_cua_o.length() < 4)){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so_va_chu_in_hoa);
						}
						if((o_duoc_chon == 6) && (chuoi_cua_o.length() < 13)){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so);
						}
						if((o_duoc_chon == 4) && (chuoi_cua_o.length() < 16)){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, dinh_dang_ten);
						}
						if((o_duoc_chon == 5) && (chuoi_cua_o.length() < 16)){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, dinh_dang_ten);
						}
					}
					else if(chuc_nang_duoc_chon == 4){
						if(o_duoc_chon == 0 && chuoi_cua_o.length() < 12){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so_va_chu_in_hoa);
						}
						if(o_duoc_chon == 1){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, dinh_dang_ten_mh);
						}
						if(o_duoc_chon >= 2 && chuoi_cua_o.length() <=4){
							rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so_thap_phan);
						}
					}
				}
			}
			TextColor(binh_thuong);
			gotoxy(1 + doc_chuc_nang_nhap, rong_khung_chuc_nang + 2 + ngang_chuc_nang_nhap + 2 + o_duoc_chon * 2 - 1);
			cout << xoa;
			TextColor(noi_bat);
			gotoxy(1 + doc_chuc_nang_nhap, rong_khung_chuc_nang + 2 + ngang_chuc_nang_nhap + 2 + o_duoc_chon * 2 - 1);
			cout << chuoi_cua_o;
			TextColor(binh_thuong);
		}
	}
}

string chuoi_goc(string s){
	string tam;
	int i=0;
	while (s[i] == ' '){
		i++;
	}
	for (i; i< s.length();i++){
		if(s[i] != ' '){
			tam = tam + s[i];
		}
		if((s[i] == ' ') && (s[i + 1] != ' ') && (i != s.length() - 1)){
			tam = tam + s[i];
		}
	}
	return tam;
}

void trung_thuoc_tinh_loptc(TREE t,string nk,string mamh,int hk,int nhom,bool &kt){
	if(t!=NULL){
		if(stricmp(nk.c_str(),t->LopTC.NienKhoa.c_str())==0){
			if(t->LopTC.HK==hk){
				if(t->LopTC.Nhom==nhom){
					if(stricmp(t->LopTC.MAMH,mamh.c_str())==0){
                        kt=true;
					}
				}
			}
		}
		trung_thuoc_tinh_loptc(t->pLeft,nk,mamh,hk,nhom,kt);
		trung_thuoc_tinh_loptc(t->pRight,nk,mamh,hk,nhom,kt);
	}
}

void trung_sua_thuoc_tinh_loptc(TREE t,int ma_ltc,string nk,string mamh,int hk,int nhom,bool &kt){
	if(t!=NULL){
		if(stricmp(nk.c_str(),t->LopTC.NienKhoa.c_str())==0){
			if(t->LopTC.HK==hk){
				if(t->LopTC.Nhom==nhom){
					if(stricmp(t->LopTC.MAMH,mamh.c_str())==0){
                        if(t->LopTC.MALOPTC != ma_ltc){
                        	kt=true;
						}
					}
				}
			}
		}
		trung_sua_thuoc_tinh_loptc(t->pLeft,ma_ltc,nk,mamh,hk,nhom,kt);
		trung_sua_thuoc_tinh_loptc(t->pRight,ma_ltc,nk,mamh,hk,nhom,kt);
	}
}

void show_danh_sach(int chuc_nang_duoc_chon){
//	system(ma_system);
	
	//vtri trai tren khung danh sach (dai_khung_chuc_nang + 1, 0)
	//vtri phai tren khung danh sach (dai_khung_chuc_nang + 1 + dai_khung_danh_sach - 1, 0)
	if(chuc_nang_duoc_chon == 1){
		gotoxy(dai_khung_chuc_nang + 1, 0);
		for (int i = 0; i < 28; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 1; i < rong_khung_danh_sach; i++){
			gotoxy(dai_khung_chuc_nang + 1, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 28 - 1, i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang + 1, rong_khung_danh_sach);
		for (int i = 0; i < 28; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 0; i < 28 - 2; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i, ngang1_danh_sach);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i, ngang2_danh_sach);
			cout << char(khung_ngoai);
		}
	}
	else if(chuc_nang_duoc_chon == 11){
		gotoxy(dai_khung_chuc_nang + 1 + 29, 0);
		for (int i = 0; i < 49; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 1; i < rong_khung_danh_sach; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 29, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 49 - 1 + 29, i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang + 1 + 29, rong_khung_danh_sach);
		for (int i = 0; i < 49; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 0; i < 49 - 2; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i + 29, ngang1_danh_sach);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i + 29, ngang2_danh_sach);
			cout << char(khung_ngoai);
		}
	}
	else if(chuc_nang_duoc_chon == 3){
		gotoxy(dai_khung_chuc_nang + 1, 0);
		for (int i = 0; i < dai_khung_danh_sach - 19; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 1; i < rong_khung_danh_sach; i++){
			gotoxy(dai_khung_chuc_nang + 1, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + dai_khung_danh_sach - 1 - 19, i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang + 1, rong_khung_danh_sach);
		for (int i = 0; i < dai_khung_danh_sach - 19; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 0; i < dai_khung_danh_sach - 2 - 19; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i, ngang1_danh_sach);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i, ngang2_danh_sach);
			cout << char(khung_ngoai);
		}
	}
	else if(chuc_nang_duoc_chon == 31){
		gotoxy(dai_khung_chuc_nang + 1 + dai_khung_danh_sach - 19 + 1, 0);
		for (int i = 0; i < 19; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 1; i < rong_khung_danh_sach; i++){
			gotoxy(dai_khung_chuc_nang + 1 + dai_khung_danh_sach - 19 + 1, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + dai_khung_danh_sach, i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang + 1 + dai_khung_danh_sach - 19 + 1, rong_khung_danh_sach);
		for (int i = 0; i < 19; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 0; i < 19 - 2; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i + dai_khung_danh_sach - 19 + 1, ngang2_danh_sach);
			cout << char(khung_ngoai);
		}
	}
	else{
		gotoxy(dai_khung_chuc_nang + 1, 0);
		for (int i = 0; i < dai_khung_danh_sach; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 1; i < rong_khung_danh_sach; i++){
			gotoxy(dai_khung_chuc_nang + 1, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + dai_khung_danh_sach - 1, i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang + 1, rong_khung_danh_sach);
		for (int i = 0; i < dai_khung_danh_sach; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 0; i < dai_khung_danh_sach - 2; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i, ngang1_danh_sach);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i, ngang2_danh_sach);
			cout << char(khung_ngoai);
		}
	}
	string tam;

	if(chuc_nang_duoc_chon == 0){
		tam = "Danh sach lop tin chi";
		for (int i = ngang2_danh_sach - 1; i < rong_khung_danh_sach; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o1_danh_sach0, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach0, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach0, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach0, i);
			cout << char(khung_ngoai);
			int con_lai = do_rong_con_lai(0);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach0 + con_lai/3*1, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach0 + con_lai/3*2, i);
			cout << char(khung_ngoai);
			if(i == ngang2_danh_sach - 1){
				i++;
			}
		}
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 1 + (do_rong_o1_danh_sach0 - 1)/2 - thuoc_tinh_LTC[0][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_LTC[0][0];
		
		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o1_danh_sach0 + (do_rong_o2_danh_sach0 - 1 - do_rong_o1_danh_sach0)/2 - thuoc_tinh_LTC[1][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_LTC[1][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach0 + (do_rong_o3_danh_sach0 - 1 - (do_rong_o2_danh_sach0))/2 - thuoc_tinh_LTC[2][0].length()/2 + 1, ngang2_danh_sach - 1);
		cout << thuoc_tinh_LTC[2][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach0 + (do_rong_o4_danh_sach0 - 1 - (do_rong_o3_danh_sach0))/2 - thuoc_tinh_LTC[3][0].length()/2 + 1, ngang2_danh_sach - 1);
		cout << thuoc_tinh_LTC[3][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach0 + (do_rong_con_lai(0) / 3)/2 - thuoc_tinh_LTC[4][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_LTC[4][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach0 + do_rong_con_lai(0) / 3 * 1 + (do_rong_con_lai(0) / 3)/2 - thuoc_tinh_LTC[5][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_LTC[5][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach0 + do_rong_con_lai(0) / 3 * 2 + (do_rong_con_lai(0) / 3)/2 - thuoc_tinh_LTC[6][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_LTC[6][0];
	}
	if(chuc_nang_duoc_chon == 1){
		tam = "DSach SV LTC";
		for(int i = 0; i < rong_khung_danh_sach - 3; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 20, ngang1_danh_sach + 1 + i);
			cout << char(khung_ngoai);
		}
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 10 - 2, ngang2_danh_sach - 1);
		cout << "MASV";
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 20 + 3 - 2, ngang2_danh_sach - 1);
		cout << "DIEM";
		gotoxy(dai_khung_chuc_nang + 1 + 13 - 6 , ngang1_danh_sach - 1);
		cout << tam;
		TextColor(binh_thuong);
	}
	if(chuc_nang_duoc_chon == 11){
		tam = "DSach LTC";
		for(int i = 0; i < rong_khung_danh_sach - 3; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 14 + 29, ngang1_danh_sach + 1 + i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 14 + 14 + 29, ngang1_danh_sach + 1 + i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 14 + 14 + 10 + 29, ngang1_danh_sach + 1 + i);
			cout << char(khung_ngoai);
		}
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 7 - 2 + 29, ngang2_danh_sach - 1);
		cout << "MAMH";
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 14 + 7 - 5 + 29, ngang2_danh_sach - 1);
		cout << "NIEN KHOA";
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 14 + 14 + 4 - 3 + 29, ngang2_danh_sach - 1);
		cout << "HOC KI";
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 14 + 14 + 10 + 4 - 2 + 29, ngang2_danh_sach - 1);
		cout << "NHOM";
		gotoxy(dai_khung_chuc_nang + 1 + 29 + 23 - 5, ngang1_danh_sach - 1);
		cout << tam;
		TextColor(binh_thuong);
	}
	if(chuc_nang_duoc_chon == 2){
		tam = "Danh sach sinh vien cua 1 lop";
		for (int i = ngang2_danh_sach - 1; i < rong_khung_danh_sach; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o1_danh_sach2, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach2, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach2, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2, i);
			cout << char(khung_ngoai);
			int con_lai = do_rong_con_lai(2);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + con_lai/3*1, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + con_lai/3*2, i);
			cout << char(khung_ngoai);
			if(i == ngang2_danh_sach - 1){
				i++;
			}
		}
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 1 + (do_rong_o1_danh_sach2 - 1)/2 - thuoc_tinh_sv[0][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[0][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o1_danh_sach2 + (do_rong_o2_danh_sach2 - 1 - do_rong_o1_danh_sach2)/2 - thuoc_tinh_sv[1][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[1][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach2 + (do_rong_o3_danh_sach2 - 1 - (do_rong_o2_danh_sach2))/2 - thuoc_tinh_sv[2][0].length()/2 + 1, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[2][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach2 + (do_rong_o4_danh_sach2 - 1 - (do_rong_o3_danh_sach2))/2 - thuoc_tinh_sv[3][0].length()/2 + 1, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[3][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[4][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[4][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + do_rong_con_lai(2) / 3 * 1 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[5][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[5][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + do_rong_con_lai(2) / 3 * 2 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[6][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[6][0];
	}
	if(chuc_nang_duoc_chon == 3){
		tam = "Danh sach sinh vien cua 1 lop";
		for (int i = ngang2_danh_sach - 1; i < rong_khung_danh_sach; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach2 - do_rong_o1_danh_sach2, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach2 - do_rong_o1_danh_sach2, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 - do_rong_o1_danh_sach2, i);
			cout << char(khung_ngoai);

			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + 15 - do_rong_o1_danh_sach2, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + 15 + 16 - do_rong_o1_danh_sach2, i);
			cout << char(khung_ngoai);
			if(i == ngang2_danh_sach - 1){
				i++;
			}
		}
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 1 + (do_rong_o2_danh_sach2 - 1 - do_rong_o1_danh_sach2)/2 - thuoc_tinh_sv[1][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[1][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach2 - do_rong_o1_danh_sach2 + (do_rong_o3_danh_sach2 - 1 - (do_rong_o2_danh_sach2))/2 - thuoc_tinh_sv[2][0].length()/2 + 1, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[2][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach2 - do_rong_o1_danh_sach2 + (do_rong_o4_danh_sach2 - 1 - (do_rong_o3_danh_sach2))/2 - thuoc_tinh_sv[3][0].length()/2 + 1, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[3][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 - do_rong_o1_danh_sach2 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[4][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[4][0];

		gotoxy(dai_khung_chuc_nang - 2 + 1 + 1 + do_rong_o4_danh_sach2 - do_rong_o1_danh_sach2 + do_rong_con_lai(2) / 3 * 1 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[5][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[5][0];

		gotoxy(dai_khung_chuc_nang - 3 + 1 + 1 + do_rong_o4_danh_sach2 - do_rong_o1_danh_sach2 + do_rong_con_lai(2) / 3 * 2 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[6][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_sv[6][0];
		
		gotoxy(dai_khung_chuc_nang + 1 + (dai_khung_danh_sach - 19)/2 - tam.length()/2 , ngang1_danh_sach - 1);
		cout << tam;
	}
	if(chuc_nang_duoc_chon == 31){
		gotoxy(dai_khung_chuc_nang + 1 + dai_khung_danh_sach - 19 + 1 + 9 - 3,ngang1_danh_sach);
		TextColor(noi_bat);
		cout << thuoc_tinh_sv[0][0];
		TextColor(binh_thuong);
	}
	if((chuc_nang_duoc_chon == 4) || (chuc_nang_duoc_chon == 5)){
		tam = "Danh sach mon hoc";
		for (int i = ngang2_danh_sach - 1; i < rong_khung_danh_sach; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o1_danh_sach4, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach4, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach4, i);
			cout << char(khung_ngoai);
		}
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 1 + (do_rong_o1_danh_sach4 - 1)/2 - thuoc_tinh_mon_hoc[0][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_mon_hoc[0][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o1_danh_sach4 + (do_rong_o2_danh_sach4 - 1 - do_rong_o1_danh_sach4)/2 - thuoc_tinh_mon_hoc[1][0].length()/2, ngang2_danh_sach - 1);
		cout << thuoc_tinh_mon_hoc[1][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach4 + (do_rong_o3_danh_sach4 - 1 - (do_rong_o2_danh_sach4))/2 - thuoc_tinh_mon_hoc[2][0].length()/2 + 1, ngang2_danh_sach - 1);
		cout << thuoc_tinh_mon_hoc[2][0];

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach4 + (do_rong_o4_danh_sach4 - 1 - (do_rong_o3_danh_sach4))/2 - thuoc_tinh_mon_hoc[3][0].length()/2 + 1, ngang2_danh_sach - 1);
		cout << thuoc_tinh_mon_hoc[3][0];
	}
	if((chuc_nang_duoc_chon != 1) && (chuc_nang_duoc_chon != 11) && (chuc_nang_duoc_chon != 3) && (chuc_nang_duoc_chon != 31)){
		gotoxy(dai_khung_chuc_nang + 1 + dai_khung_danh_sach/2 - tam.length()/2 , ngang1_danh_sach - 1);
		cout << tam;
	}
	TextColor(binh_thuong);
}

void Tao_khung_menu_main(){
	
	for (int i = 0; i < dai_khung_main; i++){
		cout << char(khung_ngoai);
	}
	cout << endl;
	for (int i = 1; i < rong_khung_main; i++){
		cout << char(khung_ngoai);
		gotoxy(dai_khung_main - 1, i);
		cout << char(khung_ngoai) <<endl;
	}
	for (int i = 0; i < dai_khung_main; i++){
		cout << char(khung_ngoai);
	}
	
	TextColor(noi_bat);
	gotoxy(dai_khung_main / 2 - 19, ngang_main - 2);
	cout << Ten_de_tai;
	TextColor(binh_thuong);
	
	gotoxy(1, ngang_main);
	for (int i = 0; i < dai_khung_main - 2; i++){
		cout << char(khung_ngoai);
	}
	
	int dem = 0;
	for(int i = ngang_main + 2; i < rong_khung_main + 1; i = i + 2){
		gotoxy(1, i - 1);
		if (dem == 0){
			TextColor(hien_thanh_sang);
			cout << dem + 1 << "." << chuc_nang[dem];
			dem++;
			TextColor(binh_thuong);
		}
		else{
			TextColor(an_thanh_sang);
			cout << dem + 1 << "." << chuc_nang[dem];
			dem++;
			TextColor(binh_thuong);
		}
		
		if (dem != so_chuc_nang - 1){
			for (int j = 1; j < dai_khung_main - 1; j++){
				gotoxy(j, i);
				cout << char(khung_trong);
			}
		}
	}
	gotoxy(dai_khung_main - 1, ngang_main + 1);
}

void Tao_khung_menu_main_sv(){
	
	for (int i = 0; i < dai_khung_main; i++){
		cout << char(khung_ngoai);
	}
	cout << endl;
	for (int i = 1; i < rong_khung_main_sv; i++){
		cout << char(khung_ngoai);
		gotoxy(dai_khung_main - 1, i);
		cout << char(khung_ngoai) <<endl;
	}
	for (int i = 0; i < dai_khung_main; i++){
		cout << char(khung_ngoai);
	}
	
	TextColor(noi_bat);
	gotoxy(dai_khung_main / 2 - 14, ngang_main - 2);
	cout << "CHUC NANG DANH CHO SINH VIEN";
	TextColor(binh_thuong);
	
	gotoxy(1, ngang_main);
	for (int i = 0; i < dai_khung_main - 2; i++){
		cout << char(khung_ngoai);
	}
	
	int dem = so_chuc_nang - 1;
	for(int i = ngang_main + 2; i < rong_khung_main_sv + 1; i = i + 2){
		gotoxy(1, i - 1);
		if (dem == so_chuc_nang - 1){
			TextColor(hien_thanh_sang);
			cout << abs(so_chuc_nang - dem) << "." << chuc_nang[dem] + " ";
			dem--;
			TextColor(binh_thuong);
		}
		else{
			TextColor(an_thanh_sang);
			cout << abs(so_chuc_nang - dem) << "." << chuc_nang[dem];
			dem--;
			TextColor(binh_thuong);
		}
		
		if (dem != so_chuc_nang - 3){
			for (int j = 1; j < dai_khung_main - 1; j++){
				gotoxy(j, i);
				cout << char(khung_trong);
			}
		}
	}
	gotoxy(dai_khung_main - 1, ngang_main + 1);
}

void tao_khung_menu_chuc_nang(int chuc_nang_duoc_chon){
	TextColor(binh_thuong);
	gotoxy(0,0);
	for (int i = 0; i < dai_khung_chuc_nang; i++){
		cout << char(khung_ngoai);
	}
	cout << endl;
	for (int i = 1; i < rong_khung_chuc_nang; i++){
		cout << char(khung_ngoai);
		gotoxy(dai_khung_chuc_nang - 1, i);
		cout << char(khung_ngoai) <<endl;
	}
	for (int i = 0; i < dai_khung_chuc_nang; i++){
		cout << char(khung_ngoai);
	}
	
	TextColor(noi_bat);
	gotoxy(dai_khung_chuc_nang / 2 - chuoi_goc(chuc_nang[chuc_nang_duoc_chon]).length()/2, ngang_chuc_nang - 2);
	cout << chuoi_goc(chuc_nang[chuc_nang_duoc_chon]);
	TextColor(binh_thuong);
	
	gotoxy(1, ngang_chuc_nang);
	for (int i = 0; i < dai_khung_chuc_nang - 2; i++){
		cout << char(khung_ngoai);
	}
	
	int dem = 0;
	
	for(int i = ngang_chuc_nang + 2; i < rong_khung_chuc_nang + 1; i = i + 2){
		gotoxy(1, i - 1);
		if (dem == 0){
			TextColor(hien_thanh_sang);
			cout << dem + 1 << "." << arr[dem];
			dem++;
			TextColor(binh_thuong);
		}
		else{
			TextColor(an_thanh_sang);
			cout << dem + 1 << "." << arr[dem];
			dem++;
			TextColor(binh_thuong);
		}
		
		if (dem != so_chuc_nang_con){
			for (int j = 1; j < dai_khung_chuc_nang - 1; j++){
				gotoxy(j, i);
				cout << char(khung_trong);
			}
		}
	}
}

void xu_li_xac_nhan(int them_xoa_sua, int chuc_nang_duoc_chon, int &xac_nhan_tra_ve){
	int dai_khung_chuc_nang_xac_nhan;
	int rong_khung_chuc_nang_xac_nhan;
	int ngang_chuc_nang_xac_nhan;
	int doc_chuc_nang_xac_nhan;
	
	string chuoi_in;
	
	if(them_xoa_sua == 0){
		if (chuc_nang_duoc_chon == 0){
			dai_khung_chuc_nang_xac_nhan = dai_khung_chuc_nang_them0;
			rong_khung_chuc_nang_xac_nhan = rong_khung_chuc_nang_them0;
			ngang_chuc_nang_xac_nhan = rong_khung_chuc_nang_them0 - 2;
			doc_chuc_nang_xac_nhan = doc_chuc_nang_them0;
		}
		if(chuc_nang_duoc_chon == 2){
			dai_khung_chuc_nang_xac_nhan = dai_khung_chuc_nang_them2;
			rong_khung_chuc_nang_xac_nhan = rong_khung_chuc_nang_them2;
			ngang_chuc_nang_xac_nhan = rong_khung_chuc_nang_them2 - 2 + rong_khung_chuc_nang_xoa + 2;
			doc_chuc_nang_xac_nhan = doc_chuc_nang_them2;
		}
		if(chuc_nang_duoc_chon == 4){
			dai_khung_chuc_nang_xac_nhan = dai_khung_chuc_nang_them4;
			rong_khung_chuc_nang_xac_nhan = rong_khung_chuc_nang_them4;
			ngang_chuc_nang_xac_nhan = rong_khung_chuc_nang_them4 - 2;
			doc_chuc_nang_xac_nhan = doc_chuc_nang_them4;
		}
		chuoi_in = "THEM";
	}
	if(them_xoa_sua == 2){
		if (chuc_nang_duoc_chon == 0){
			dai_khung_chuc_nang_xac_nhan = dai_khung_chuc_nang_them0;
			rong_khung_chuc_nang_xac_nhan = rong_khung_chuc_nang_them0;
			ngang_chuc_nang_xac_nhan = rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them0 - 2;
			doc_chuc_nang_xac_nhan = doc_chuc_nang_them0;
		}
		if(chuc_nang_duoc_chon == 2){
			dai_khung_chuc_nang_xac_nhan = dai_khung_chuc_nang_them2;
			rong_khung_chuc_nang_xac_nhan = rong_khung_chuc_nang_them2;
			ngang_chuc_nang_xac_nhan = rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them2 - 2;
			doc_chuc_nang_xac_nhan = doc_chuc_nang_them2;
		}
		if(chuc_nang_duoc_chon == 4){
			dai_khung_chuc_nang_xac_nhan = dai_khung_chuc_nang_them4;
			rong_khung_chuc_nang_xac_nhan = rong_khung_chuc_nang_them4;
			ngang_chuc_nang_xac_nhan = rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them4 - 2;
			doc_chuc_nang_xac_nhan = doc_chuc_nang_them4;
		}
		chuoi_in = "HIEU CHINH";
	}
	if(them_xoa_sua == 1){
		dai_khung_chuc_nang_xac_nhan = dai_khung_chuc_nang_xoa;
		rong_khung_chuc_nang_xac_nhan = rong_khung_chuc_nang_xoa;
		ngang_chuc_nang_xac_nhan = ngang_chuc_nang_xoa;
		doc_chuc_nang_xac_nhan = doc_chuc_nang_xoa;
		chuoi_in = "XOA";
	}
//	TextColor(binh_thuong);
	gotoxy(0, rong_khung_chuc_nang + 2 + ngang_chuc_nang_xac_nhan + 1 + 2);
	cout << char(khung_ngoai);
	gotoxy(dai_khung_chuc_nang_xac_nhan - 1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_xac_nhan + 1 + 2);
	cout << char(khung_ngoai) << endl;
	for (int i = 0; i < dai_khung_chuc_nang_xac_nhan; i++){
		cout << char(khung_ngoai);
	}
	gotoxy(1 + 20, rong_khung_chuc_nang + 2 + ngang_chuc_nang_xac_nhan + 1 + 2);
	cout << char(khung_ngoai);
	TextColor(hien_thanh_sang);
	cout << chuoi_voi_n_ki_tu("YES", (dai_khung_chuc_nang_xac_nhan - 4 - 20) / 2);
	TextColor(binh_thuong);
	cout << char(khung_ngoai);
	TextColor(noi_bat);
	cout << chuoi_voi_n_ki_tu("NO", (dai_khung_chuc_nang_xac_nhan - 4 - 20) / 2);
	TextColor(binh_thuong);
	int yes_no = 1;
	char phim;
	while (1){
		phim = getch();
		if((phim == mui_ten_trai) || (phim == mui_ten_phai)){
			if(yes_no == 1){
				gotoxy(1 + 20 + 1 , rong_khung_chuc_nang + 2 + ngang_chuc_nang_xac_nhan + 1 + 2);
				TextColor(an_thanh_sang);
				cout << chuoi_voi_n_ki_tu("YES", (dai_khung_chuc_nang_xac_nhan - 4 - 20) / 2);
				TextColor(binh_thuong);
				cout << char(khung_ngoai);
				TextColor(hien_thanh_sang);
				cout << chuoi_voi_n_ki_tu("NO", (dai_khung_chuc_nang_xac_nhan - 4 - 20) / 2);
				TextColor(binh_thuong);
			}
			else{
				gotoxy(1 + 20 + 1 , rong_khung_chuc_nang + 2 + ngang_chuc_nang_xac_nhan + 1 + 2);
				TextColor(hien_thanh_sang);
				cout << chuoi_voi_n_ki_tu("YES", (dai_khung_chuc_nang_xac_nhan - 4 - 20) / 2);
				TextColor(binh_thuong);
				cout << char(khung_ngoai);
				TextColor(an_thanh_sang);
				cout << chuoi_voi_n_ki_tu("NO", (dai_khung_chuc_nang_xac_nhan - 4 - 20) / 2);
				TextColor(binh_thuong);
			}
			yes_no = abs(1 - yes_no);
		}
		if(phim == esc){
			yes_no = 0;
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_xac_nhan + 1 + 2);
			TextColor(noi_bat);
			cout << chuoi_voi_n_ki_tu("DA HUY " + chuoi_in + "!!!", dai_khung_chuc_nang_xac_nhan - 2);
			TextColor(binh_thuong);
			getch();
			xac_nhan_tra_ve = 2;
			break;
		}
		if(phim == enter){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_xac_nhan + 1 + 2);
			TextColor(noi_bat);
			if(yes_no == 1){
				cout << chuoi_voi_n_ki_tu("DA " + chuoi_in + " THANH CONG!!!", dai_khung_chuc_nang_xac_nhan - 2);
				xac_nhan_tra_ve = 0;
			}
			else if(yes_no == 0){
				cout << chuoi_voi_n_ki_tu("DA HUY " + chuoi_in + ", ENTER DE TIEP TUC!!!", dai_khung_chuc_nang_xac_nhan - 2);
				xac_nhan_tra_ve = 1;
			}
			TextColor(binh_thuong);
			break;
		}
	}
}

///////////////////////////
//CHUC NANG 1: CAP NHAT LTC

void tao_khung_them_or_sua2_LTC(int them_or_sua2){	
	int khoang_cach_voi_khung_chuc_nang = 2; //khoang cach voi khung chuc nang la 2
	
	if(them_or_sua2 == 1){
		khoang_cach_voi_khung_chuc_nang = 4 + rong_khung_chuc_nang_xoa;
	}
	
	TextColor(noi_bat);
	if(them_or_sua2 == 0){
		gotoxy(dai_khung_chuc_nang_them0 / 2 - 4, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them0 - 2);
		cout << "THEM LTC";
	}
	else if(them_or_sua2 == 1){
		gotoxy(dai_khung_chuc_nang_them0 / 2 - 6, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them0 - 2);
		cout << "THONG TIN LTC";
	}
	TextColor(binh_thuong);
	
	for (int i = 1; i < dai_khung_chuc_nang_them0 - 1; i++){
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them0);
		cout << char(khung_ngoai);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them0 + 2);
		cout << char(khung_trong_them);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them0 + 2 + 2);
		cout << char(khung_trong_them);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them0 + 2 + 4);
		cout << char(khung_trong_them);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them0 + 2 + 6);
		cout << char(khung_trong_them);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them0 + 2 + 8);
		cout << char(khung_trong_them);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them0 + 2 + 10);
		cout << char(khung_trong_them);
	}
	gotoxy(0,rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang);
	for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
		cout << char(khung_ngoai);
	}
	cout << endl;
	
	for (int i = 1; i < rong_khung_chuc_nang_them0; i++){
		cout << char(khung_ngoai);
		if(i > ngang_chuc_nang_them0){
			gotoxy(doc_chuc_nang_them0, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + i);
		cout << char(khung_ngoai) <<endl;
	}
	for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
		cout << char(khung_ngoai);
	}
	int dem = 0;
	for(int i = ngang_chuc_nang_them0 + 2; i < rong_khung_chuc_nang_them0 + 1; i = i + 2){
		gotoxy(1, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + i - 1);
		if (dem == 1){
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[dem][0], doc_chuc_nang_them0 - 1);
			dem++;
			TextColor(binh_thuong);
		}
		else{
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[dem][0], doc_chuc_nang_them0 - 1);
			dem++;
			TextColor(binh_thuong);
		}
	}
	
	gotoxy(1, rong_khung_chuc_nang + 5 + khoang_cach_voi_khung_chuc_nang);
}

int kt_mamh_trung(DsMonHoc dsmh, string mamh) {
  for (int i =0; i < dsmh.n ; i++)
  if (stricmp(dsmh.Ds[i]->MAMH, mamh.c_str())==0) return i;
  return -1;
}

void xu_li_them_LTC(TREE &t, int &xac_nhan_tra_ve, DsMonHoc dsmh){
	char key_chuc_nang_them;
	int chon_thuoc_tinh = 1;
	
	int so_thuoc_tinh = 7;
	
	gotoxy(doc_chuc_nang_them0, rong_khung_chuc_nang + 2 + 7);
	
	while (1){
		bool ktra = false;
		int xac_nhan_du = so_thuoc_tinh - 1;
		
		for (int i = 1; i < so_thuoc_tinh; i++){
			if(thuoc_tinh_LTC[i][1].length() != 0){
				xac_nhan_du = xac_nhan_du - 1;
			}
		}
		
		if(xac_nhan_du == 0){
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1);
			TextColor(binh_thuong);
			cout << "                                       ";
			TextColor(binh_thuong);
			gotoxy(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1);
			cout << char(khung_ngoai) << endl;
			for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
				cout << char(khung_ngoai);
			}

			trung_thuoc_tinh_loptc(t, thuoc_tinh_LTC[2][1], thuoc_tinh_LTC[1][1], atoi(thuoc_tinh_LTC[3][1].c_str()), atoi(thuoc_tinh_LTC[6][1].c_str()), ktra);
			int ktra_mh = kt_mamh_trung(dsmh, thuoc_tinh_LTC[1][1]);
			if(ktra_mh == -1){
				ktra = true;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1);
			TextColor(noi_bat);
			if(ktra == false){
				cout << "BAM F1 DE THEM!!!";
			}
			else{
				if(ktra_mh == -1){
					cout << "CHUA CO MH NAY";
				}
				else{
					cout << "TRUNG THUOC TINH!";
				}
			}
			TextColor(binh_thuong);
		}
		else{
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1);
			TextColor(binh_thuong);
			cout << "                 ";
		}

		gotoxy(1 + doc_chuc_nang_them0, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1);
		
		nhap_tung_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][1], key_chuc_nang_them, chon_thuoc_tinh, 0 , 0);
		
		if(key_chuc_nang_them == mui_ten_len){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
			if(chon_thuoc_tinh == 1){
				chon_thuoc_tinh = (chon_thuoc_tinh - 1 - 1 + (so_thuoc_tinh + 1)) % (so_thuoc_tinh + 1) - 1;
			}
			else{
				chon_thuoc_tinh = chon_thuoc_tinh - 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
		}
		else if(key_chuc_nang_them == mui_ten_xuong){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1){
				chon_thuoc_tinh = 1;
			}	
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
		}
		else if(key_chuc_nang_them == enter){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1){
				chon_thuoc_tinh = 1;
			}	
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
		}
		else if(key_chuc_nang_them == esc){
			gotoxy(0,0);
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 2);
			system(ma_system);
			tao_khung_menu_chuc_nang(0);
			show_danh_sach(0);
			xac_nhan_tra_ve = 2;
			break;
		}
		else if((key_chuc_nang_them == F1) && (xac_nhan_du == 0) && (ktra == false)){
			//vao them ltc
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + 1 * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[1][0],doc_chuc_nang_them0 - 1);
			
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1);
			TextColor(binh_thuong);
			cout << "                    ";
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1);
			TextColor(noi_bat);
			cout << "XAC NHAN THEM";
			TextColor(binh_thuong);
			xac_nhan_tra_ve = 3;
			break;
		}
		
	}
}

bool kt_ma_loptc_trung(TREE t, int ma)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		if (t->LopTC.MALOPTC == ma)
		{
			return 1;
		}
		else if (t->LopTC.MALOPTC < ma)
		{
			kt_ma_loptc_trung(t->pRight, ma);
		}
		else
		{
			kt_ma_loptc_trung(t->pLeft, ma);
		}
	}
}

int tao_ma_loptc(TREE t)
{
	int ma;//1-MAXMA
	do
	{
		//tao trong khoang 1-maxma
		ma = rand() % MAXMA + 1;
	} while (kt_ma_loptc_trung(t,ma)==true);
	return ma;
}


void Ghi_lop_tin_chi(ofstream &fileout,LOPTC a){
		fileout<<endl<<a.MALOPTC<<","<<a.HK<<","<<a.Nhom<<","<<a.NienKhoa<<","<<a.SvMax<<","<<a.SvMin<<","<<a.MAMH;
}

void Ghi_file_ds_loptc(TREE t,ofstream &fileout)
{
	if(t!=NULL){
		Ghi_lop_tin_chi(fileout,t->LopTC); 
		Ghi_file_ds_loptc(t->pLeft,fileout);
		Ghi_file_ds_loptc(t->pRight,fileout);
	}
}

DsLopTC* khoi_tao_node_Loptc()
{
	DsLopTC *p = new DsLopTC;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

void them_1_Loptc(TREE &t, DsLopTC *p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->LopTC.MALOPTC > t->LopTC.MALOPTC)
		{
			them_1_Loptc(t->pRight, p);
		}
		else if (p->LopTC.MALOPTC < t->LopTC.MALOPTC)
		{
			them_1_Loptc(t->pLeft, p);
		}
	}
}


void xuat_lop_tin_chi(LOPTC a, int row){
		TextColor(noi_bat);
//		int do_ron
		gotoxy(dai_khung_chuc_nang + 1 + 1 + (do_rong_o1_danh_sach0 - 1)/2 - chuyen_int_string(a.MALOPTC).length()/2, ngang2_danh_sach - 1 + row + 1);
//		cout << thuoc_tinh_LTC[0][0];
		cout << a.MALOPTC;
		
		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o1_danh_sach0 + (do_rong_o2_danh_sach0 - 1 - do_rong_o1_danh_sach0)/2 - strlen(a.MAMH)/2, ngang2_danh_sach - 1 + row + 1);
//		cout << thuoc_tinh_LTC[1][0];
		cout << a.MAMH;
		
		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach0 + (do_rong_o3_danh_sach0 - 1 - (do_rong_o2_danh_sach0))/2 - a.NienKhoa.length()/2 + 1, ngang2_danh_sach - 1 + row + 1);
//		cout << thuoc_tinh_LTC[2][0];
		cout << a.NienKhoa;
	
		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach0 + (do_rong_o4_danh_sach0 - 1 - (do_rong_o3_danh_sach0))/2 - chuyen_int_string(a.HK).length()/2 + 1, ngang2_danh_sach - 1 + row + 1);
//		cout << thuoc_tinh_LTC[3][0];
		cout << a.HK;

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach0 + (do_rong_con_lai(0) / 3)/2 - chuyen_int_string(a.SvMax).length()/2, ngang2_danh_sach - 1 + row + 1);
//		cout << thuoc_tinh_LTC[4][0];
		cout << a.SvMin;

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach0 + do_rong_con_lai(0) / 3 * 1 + (do_rong_con_lai(0) / 3)/2 - chuyen_int_string(a.SvMin).length()/2, ngang2_danh_sach - 1 + row + 1);
//		cout << thuoc_tinh_LTC[5][0];
		cout << a.SvMax;

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach0 + do_rong_con_lai(0) / 3 * 2 + (do_rong_con_lai(0) / 3)/2 - chuyen_int_string(a.Nhom).length()/2, ngang2_danh_sach - 1 + row + 1);
//		cout << thuoc_tinh_LTC[6][0];
		cout << a.Nhom;
}

void xuat_ds_lop_tc(TREE t, int &row){
	if (t != NULL)
	{
		row++;
		xuat_lop_tin_chi(t->LopTC, row);
//		cout<<"............................"<<endl;
		xuat_ds_lop_tc(t->pLeft, row); 
		xuat_ds_lop_tc(t->pRight, row); 
	}
}

void xuat_goi_y_lop_tin_chi(LOPTC a, int row, int chuc_nang_duoc_chon){
	int x;
	if(chuc_nang_duoc_chon == 1){
		x = 0;
	}
	else if(chuc_nang_duoc_chon >= 7){
		x = 15 + 13;
	}
	TextColor(noi_bat);
	gotoxy(dai_khung_chuc_nang + 1 + 1 + 7 + x - strlen(a.MAMH)/2 + 29, ngang2_danh_sach - 1 + row + 1);
	cout << a.MAMH;
	gotoxy(dai_khung_chuc_nang + 1 + 1 + 14 + 7 + x - a.NienKhoa.length()/2 + 29, ngang2_danh_sach - 1 + row + 1);
	cout << a.NienKhoa;
	gotoxy(dai_khung_chuc_nang + 1 + 1 + 14 + 14 + 4 + x - chuyen_int_string(a.HK).length()/2 + 29, ngang2_danh_sach - 1 + row + 1);
	cout << a.HK;
	gotoxy(dai_khung_chuc_nang + 1 + 1 + 14 + 14 + 10 + 4 + x - chuyen_int_string(a.Nhom).length()/2 + 29, ngang2_danh_sach - 1 + row + 1);
	cout << a.Nhom;
	TextColor(binh_thuong);
}

void xuat_goi_y_ds_lop_tc(TREE t, int &row, int chuc_nang_duoc_chon){
	if (t != NULL)
	{
		row++;
		xuat_goi_y_lop_tin_chi(t->LopTC, row, chuc_nang_duoc_chon);
//		cout<<"............................"<<endl;
		xuat_goi_y_ds_lop_tc(t->pLeft, row, chuc_nang_duoc_chon); 
		xuat_goi_y_ds_lop_tc(t->pRight, row, chuc_nang_duoc_chon); 
	}
}

void Doc_lop_tin_chi(ifstream &filein,LOPTC &a){
		
		filein>>a.MALOPTC;
        char x;
		filein>>x;
		filein>>a.HK;
		filein>>x;
		filein>>a.Nhom;
		filein>>x;
		getline(filein,a.NienKhoa,',');
		filein>>a.SvMax;
		filein>>x;
		filein>>a.SvMin;
	    filein>>x;
		filein>>a.MAMH;
}

void Doc_file_ds_loptc(TREE &t,ifstream &filein)
{
	filein.seekg(2);
	
	while(!filein.eof()){
	DsLopTC *p=khoi_tao_node_Loptc();
	Doc_lop_tin_chi(filein,p->LopTC);
	them_1_Loptc(t,p);
    }
}

void nhap_Lop_TC(TREE &t, DsMonHoc dsmh)
{	
	for(int i = 1; i < 7; i++){
		thuoc_tinh_LTC[i][1] = "";
	}
	
	tao_khung_them_or_sua2_LTC(0);
	int yes_no_esc_f1 = 2;
	while (1){
		xu_li_them_LTC(t, yes_no_esc_f1, dsmh);
		if(yes_no_esc_f1 == 3){
			xu_li_xac_nhan(0, 0, yes_no_esc_f1);
			if(yes_no_esc_f1 == 0){
				DsLopTC *p = khoi_tao_node_Loptc();
				
				strcpy(p->LopTC.MAMH, thuoc_tinh_LTC[1][1].c_str());
				p->LopTC.NienKhoa = thuoc_tinh_LTC[2][1];
				p->LopTC.HK = atoi(thuoc_tinh_LTC[3][1].c_str());
				p->LopTC.SvMin = atoi(thuoc_tinh_LTC[4][1].c_str());
				p->LopTC.SvMax = atoi(thuoc_tinh_LTC[5][1].c_str());	
				p->LopTC.Nhom = atoi(thuoc_tinh_LTC[6][1].c_str());
				p->LopTC.MALOPTC = atoi(thuoc_tinh_LTC[0][1].c_str());
	
				them_1_Loptc(t, p);
				
				ofstream fileout;
		    	fileout.open("ds_loptc.txt", ios_base::out);
		    	if (fileout.fail() == true){
				   cout << "\nFile cua ban khong ton tai";
				   system("pause");
		        }
				Ghi_file_ds_loptc(t,fileout);
				fileout.close();
				int row = 0;
				clear_Area(dai_khung_chuc_nang + 1, 0, dai_khung_chuc_nang + 1 + dai_khung_danh_sach + 1, rong_khung_danh_sach);
				xuat_ds_lop_tc(t, row);
				show_danh_sach(0);
				getch();
				clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 2);
				break;
			}	
		}
		if(yes_no_esc_f1 == 2){
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 2);
			break;
		}
	}
}

void tao_khung_xoa_or_sua1_LTC(int xoa_or_sua1){
//	system(ma_system);
	int khoang_cach_voi_khung_phia_tren = 2; //khoang cach voi khung chuc nang la 2
	
	string s = "XOA";
	if(xoa_or_sua1 == 1){
		s = "HIEU CHINH";
	}
	TextColor(noi_bat);
	gotoxy(dai_khung_chuc_nang_xoa / 2 - (s.length() + 4)/2, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + ngang_chuc_nang_xoa - 2);
	cout << s << " 1 LTC";
	gotoxy(1, rong_khung_chuc_nang + 5 + khoang_cach_voi_khung_phia_tren);
	TextColor(hien_thanh_sang);
	cout << "MA LTC MUON " << s;
	TextColor(binh_thuong);
	
	for (int i = 1; i < dai_khung_chuc_nang_xoa - 1; i++){
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + ngang_chuc_nang_xoa);
		cout << char(khung_ngoai);
	}
	gotoxy(0,rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren);
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	cout << endl;
	
	for (int i = 1; i < rong_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
		if(i > ngang_chuc_nang_xoa){
			if(xoa_or_sua1 == 1){
				gotoxy(doc_chuc_nang_xoa + 7, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + i);
			}
			else{
				gotoxy(doc_chuc_nang_xoa, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + i);
			}
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + i);
		cout << char(khung_ngoai) <<endl;
	}
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	gotoxy(1, rong_khung_chuc_nang + 5 + khoang_cach_voi_khung_phia_tren);
}

void nhap_xoa_or_sua1_LTC(int xoa_or_sua1, int &dk_tra_ve){
	char phim;
	
	gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
	TextColor(binh_thuong);
	cout << "                                            ";
	TextColor(binh_thuong);
	gotoxy(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
	cout << char(khung_ngoai);
	gotoxy(dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
	cout << char(khung_ngoai) << endl;
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	
//	gotoxy(0,0);
//	cout << chuc_nang_duoc_chon;
	while (1){
		if(xoa_or_sua1 == 0){
			gotoxy(doc_chuc_nang_xoa + 1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_xoa + 1);
			nhap_tung_ki_tu(thuoc_tinh_LTC[0][1], phim, 0, 0, 1);
		}
		else if(xoa_or_sua1 == 1){
			gotoxy(doc_chuc_nang_xoa + 8, rong_khung_chuc_nang + 2 + ngang_chuc_nang_xoa + 1);
			nhap_tung_ki_tu(thuoc_tinh_LTC[0][1], phim, 0, 0, 2);
		}
		
		if(thuoc_tinh_LTC[0][1].length() == 0){
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
			TextColor(noi_bat);
			cout << "                                ";
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
			cout << "ESC de thoat hoac nhap lai";
			TextColor(binh_thuong);
		}
		else{
			TextColor(noi_bat);
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
			cout << "                           ";
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
			if(xoa_or_sua1 == 0){
				cout << "BAM F1 DE XOA!!!";
			}
			else if(xoa_or_sua1 == 1){
				cout << "BAM F1 DE HIEU CHINH!!!";
			}
			TextColor(binh_thuong);
		}
//		phim = getch();
		if(phim == esc){
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
			dk_tra_ve = 2;
			break;
		}
		if(phim == F1){
			dk_tra_ve = 3;
			
			if(xoa_or_sua1 == 0){
				gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
				TextColor(binh_thuong);
				cout << "                        ";
				gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
				TextColor(noi_bat);
				cout << "XAC NHAN XOA";
				TextColor(binh_thuong);
			}
			break;
		}
	}
}

//  TÌM NODE TRÁI NHAT CUA CÂY CON PHAI
void TimNodeTheMang(DsLopTC *&X, DsLopTC *&Y)
{
	if (Y->pLeft != NULL)
	{
		TimNodeTheMang(X, Y->pLeft);
	}
	else
	{
		X->LopTC = Y->LopTC;
		X->Dsdk = Y->Dsdk;
		X = Y;
		Y = Y->pRight;
	}
}
// Hàm xóa node bat ky trong cây
void Xoa_loptc(TREE &t, int data){
	if (t == NULL){
		gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
		cout << "                                          ";
		gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
		TextColor(noi_bat);
		cout<<"Khong co ma lop nay, enter de tiep tuc!!!";
		getch();
		TextColor(binh_thuong);
		thuoc_tinh_LTC[0][1] = "";
		
	}
	else{
		if (data < t->LopTC.MALOPTC){
			Xoa_loptc(t->pLeft, data);
		}
		else if (data > t->LopTC.MALOPTC){
			Xoa_loptc(t->pRight, data);
		}
		else // data == t->LopTC.MALOPTC
		{
			if(t->Dsdk!=NULL){
				gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
				cout << "                                            ";
				gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
				TextColor(noi_bat);
				cout<<"Khong duoc xoa lop nay, enter de tiep tuc!!!";
				getch();
				TextColor(binh_thuong);
				thuoc_tinh_LTC[0][1] = "";
			}
			else{
				DsLopTC *X = t;			
				//  neu nhánh trái cua node t bang NULL <=> node t là node có 1 con chính là con phai
				if (t->pLeft == NULL)
				{
					// cap nhat node cha cua node can xóa voi node con phai cua node can xóa
					t = t->pRight;
				}
				else if (t->pRight == NULL)
				{
					// cap nhat node cha cua node can xóa voi node con trái cua node can xóa
					t = t->pLeft;
				}
				else
				{
					// ÐI TÌM NODE THE MANG CHO NODE t
					// TÌM NODE TRÁI NHAT CUA CÂY CON PHAI
					TimNodeTheMang(X, t->pRight);
				}
				delete X; // chính là xóa di node t
			}
	  }
	}
}

void xu_li_xoa_LTC(TREE &t)
{
	thuoc_tinh_LTC[0][1] = "";
	tao_khung_xoa_or_sua1_LTC(0);
	int yes_or_esc_f1;
	while(1){
		nhap_xoa_or_sua1_LTC(0, yes_or_esc_f1);
		if(yes_or_esc_f1 == 3){
			xu_li_xac_nhan(1, 0, yes_or_esc_f1);
			if(yes_or_esc_f1 == 0){
				Xoa_loptc(t, atoi(thuoc_tinh_LTC[0][1].c_str()));
				if(thuoc_tinh_LTC[0][1].length() != 0){
					ofstream fileout;
					fileout.open("ds_loptc.txt", ios_base::out);
					Ghi_file_ds_loptc(t,fileout);
					fileout.close();
					
					clear_Area(dai_khung_chuc_nang + 2, 0, dai_khung_chuc_nang + 2 + dai_khung_danh_sach, rong_khung_danh_sach);
					show_danh_sach(0);
					int row = 0;
					xuat_ds_lop_tc(t, row);
					getch();
					clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
					break;
				}
			}
		}
		if(yes_or_esc_f1 == 2){
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
			break;
		}
	}
}

void nhap_sua2_LTC(TREE &t, int &xac_nhan_tra_ve, TREE p, DsMonHoc dsmh){
	char key_chuc_nang_them;
	int chon_thuoc_tinh = 1;
	
	int so_thuoc_tinh = 7;
	
	gotoxy(doc_chuc_nang_them0, rong_khung_chuc_nang + 2 + 7 + rong_khung_chuc_nang_xoa + 2);
	while (1){
		bool ktra = false;
		int xac_nhan_du = so_thuoc_tinh - 1;
		
		for (int i = 1; i < so_thuoc_tinh; i++){
			if(thuoc_tinh_LTC[i][1].length() != 0){
				xac_nhan_du = xac_nhan_du - 1;
			}
		}
		
		if(xac_nhan_du == 0){
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(binh_thuong);
			cout << "                                       ";
			TextColor(binh_thuong);
			gotoxy(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1 + rong_khung_chuc_nang_xoa + 2);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1 + rong_khung_chuc_nang_xoa + 2);
			cout << char(khung_ngoai) << endl;
			for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
				cout << char(khung_ngoai);
			}
			trung_sua_thuoc_tinh_loptc(p, atoi(thuoc_tinh_LTC[0][1].c_str()), thuoc_tinh_LTC[2][1], thuoc_tinh_LTC[1][1], atoi(thuoc_tinh_LTC[3][1].c_str()), atoi(thuoc_tinh_LTC[6][1].c_str()), ktra);
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(noi_bat);
			if(ktra == false){
				int kt;
				kt = kt_mamh_trung(dsmh, thuoc_tinh_LTC[1][1]);
				if(kt == -1){
					cout << "MA MH CHUA CO";
				}
				else{
					cout << "BAM F1 DE HIEU CHINH!!!";
				}
			}
			else{
				cout << "TRUNG THUOC TINH!";
			}
			TextColor(binh_thuong);
		}
		else{
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(binh_thuong);
			cout << "                              ";
		}

		gotoxy(1 + doc_chuc_nang_them0, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
		
		nhap_tung_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][1], key_chuc_nang_them, chon_thuoc_tinh, 0 , 3);
		
		if(key_chuc_nang_them == mui_ten_len){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
			if(chon_thuoc_tinh == 1){
				chon_thuoc_tinh = (chon_thuoc_tinh - 1 - 1 + (so_thuoc_tinh + 1)) % (so_thuoc_tinh + 1) - 1;
			}
			else{
				chon_thuoc_tinh = chon_thuoc_tinh - 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
		}
		else if(key_chuc_nang_them == mui_ten_xuong){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1){
				chon_thuoc_tinh = 1;
			}	
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
		}
		else if(key_chuc_nang_them == enter){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1){
				chon_thuoc_tinh = 1;
			}	
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
		}
		else if(key_chuc_nang_them == esc){
			gotoxy(0,0);
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them0 + 2);
			system(ma_system);
			tao_khung_menu_chuc_nang(0);
			show_danh_sach(0);
			xac_nhan_tra_ve = 2;
			break;
		}
		else if((key_chuc_nang_them == F1) && (xac_nhan_du == 0) && (ktra == false)){
			//vao them ltc
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them0 - 1);
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them0 + 2 + 1 * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[1][0],doc_chuc_nang_them0 - 1);
			
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(binh_thuong);
			cout << "                                ";
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(noi_bat);
			cout << "XAC NHAN HIEU CHINH";
			TextColor(binh_thuong);
			xac_nhan_tra_ve = 3;
			break;
		}
		
	}
}

void Sua_loptc(TREE &t,int data, TREE p, DsMonHoc dsmh){
	if((t == NULL)){
		gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
		cout << "                                        ";
		gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
		TextColor(noi_bat);
		cout<<"Khong co ma lop nay, enter de tiep tuc!!!";
		getch();
		TextColor(binh_thuong);
		thuoc_tinh_LTC[0][1] = "";
	}
	else{
		if(atoi(thuoc_tinh_LTC[0][1].c_str()) < t->LopTC.MALOPTC){
			Sua_loptc(t->pLeft,atoi(thuoc_tinh_LTC[0][1].c_str()), p, dsmh);
		}
		else if(atoi(thuoc_tinh_LTC[0][1].c_str()) > t->LopTC.MALOPTC){
			Sua_loptc(t->pRight,atoi(thuoc_tinh_LTC[0][1].c_str()), p, dsmh);
		}
		else{
			clear_Area(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1, dai_khung_chuc_nang_xoa, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
			tao_khung_them_or_sua2_LTC(1);
			
			thuoc_tinh_LTC[1][1] = t->LopTC.MAMH;
			thuoc_tinh_LTC[2][1] = t->LopTC.NienKhoa;
			thuoc_tinh_LTC[3][1] = chuyen_int_string(t->LopTC.HK);
			thuoc_tinh_LTC[4][1] = chuyen_int_string(t->LopTC.SvMin);
			thuoc_tinh_LTC[5][1] = chuyen_int_string(t->LopTC.SvMax);
			thuoc_tinh_LTC[6][1] = chuyen_int_string(t->LopTC.Nhom);
			thuoc_tinh_LTC[0][1] = chuyen_int_string(t->LopTC.MALOPTC);
			int dem = 0;
			for(int i = ngang_chuc_nang_them0 + 2; i < rong_khung_chuc_nang_them0 + 1; i = i + 2){
				gotoxy(doc_chuc_nang_them0 + 1, rong_khung_chuc_nang + rong_khung_chuc_nang_xoa + 4 + i - 1);
				TextColor(noi_bat);
				cout << thuoc_tinh_LTC[dem][1];
				TextColor(binh_thuong);
				dem++;
			}
			
			int yes_no_esc_f1;
			while(1){
				nhap_sua2_LTC(t, yes_no_esc_f1, p, dsmh);
				if(yes_no_esc_f1 == 3){
					xu_li_xac_nhan(2, 0, yes_no_esc_f1);
					if(yes_no_esc_f1 == 0){
						strcpy(t->LopTC.MAMH, thuoc_tinh_LTC[1][1].c_str());
						t->LopTC.NienKhoa = thuoc_tinh_LTC[2][1];
						t->LopTC.HK = atoi(thuoc_tinh_LTC[3][1].c_str());
						t->LopTC.SvMin = atoi(thuoc_tinh_LTC[4][1].c_str());
						t->LopTC.SvMax = atoi(thuoc_tinh_LTC[5][1].c_str());
						t->LopTC.Nhom = atoi(thuoc_tinh_LTC[6][1].c_str());
						t->LopTC.MALOPTC = atoi(thuoc_tinh_LTC[0][1].c_str());
						break;
					}
				}
				if(yes_no_esc_f1 == 2){
//					clear_Area(0, rong_khung_chuc_nang + 1, dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them0 + 2);
					thuoc_tinh_LTC[0][1] = "";
					break;
				}
			}
		}
	}
}

void xu_li_sua_LTC(TREE &t, DsMonHoc dsmh){
	thuoc_tinh_LTC[0][1] = "";
	tao_khung_xoa_or_sua1_LTC(1);
	int yes_or_esc_f1;
	while(1){
		nhap_xoa_or_sua1_LTC(1, yes_or_esc_f1);
		if(yes_or_esc_f1 == 3){
			Sua_loptc(t, atoi(thuoc_tinh_LTC[0][1].c_str()), t, dsmh);
			if(thuoc_tinh_LTC[0][1].length() != 0){				
				ofstream fileout;
		    	fileout.open("ds_loptc.txt", ios_base::out);
		    	if (fileout.fail() == true){
				   cout << "\nFile cua ban khong ton tai";
				   system("pause");
		        }
				Ghi_file_ds_loptc(t,fileout);
				fileout.close();
				int row = 0;
				clear_Area(dai_khung_chuc_nang + 2, 0, dai_khung_chuc_nang + 2 + dai_khung_danh_sach, rong_khung_danh_sach);
				show_danh_sach(0);
				xuat_ds_lop_tc(t, row);
				getch();
				clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them0 + 2);
				break;
			}
			else{
				yes_or_esc_f1 = 2;
			}
		}
		if(yes_or_esc_f1 == 2){
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them0 + 2);
			break;
		}
	}
}

void tao_khung_in_danh_sach(int chuc_nang_duoc_chon){
	TextColor(binh_thuong);
	gotoxy(0,0);
	if(chuc_nang_duoc_chon == 1){
		show_danh_sach(11);
		show_danh_sach(1);
	}
	else if(chuc_nang_duoc_chon == 3){
		show_danh_sach(31);
		show_danh_sach(3);
	}
	else if(chuc_nang_duoc_chon == 5){
//		show_danh_sach(51);
		show_danh_sach(5);
	}
	else{
//		tao_khung_xoa(chuc_nang_duoc_chon - 1, 2);
		show_danh_sach(chuc_nang_duoc_chon);
		getch();
	}
}

////////////////////////////////////
//CHUC NANG 2: IN DSACH SV CUA 1 LTC

SVdangky* khoi_tao_node_SVdangky()
{
	SVdangky *p = new SVdangky;
	p->next = NULL;
	return p;
}

void Doc_sv_dk_loptc(ifstream &filein,SVdangky *&sv){
	char x;
	filein>>sv->Diem;
	filein>>x;
	filein>>sv->MASV;
	
}

void ThemDau(SVdangky *&ds,SVdangky *p)
{
	// neu danh sách rong
	if (ds == NULL)
	{
		ds = p; // node p thêm vào cung chính là node dau 
	}
	else
	{
		p->next = ds; // cho con tro p tro den pHead
		ds = p; // cap nhat lai ds là node p
	}
}

void Them_dssv_vao_loptc(TREE &t, int data,SVdangky *tam)
{
		if (data < t->LopTC.MALOPTC)
		{
			Them_dssv_vao_loptc(t->pLeft, data,tam);
		}
		else if (data > t->LopTC.MALOPTC)
		{
			Them_dssv_vao_loptc(t->pRight, data,tam);
		}
		else // data == t->LopTC.MALOPTC
		{
			t->Dsdk=tam;
		}
}

void Doc_file_dsdk(TREE &t, ifstream &filein){
	filein.seekg(2);
	int data;
	char x;
	while(!filein.eof()){
		filein>>data; 
		SVdangky *tam=NULL;
		while(true){
			filein>>x;
			if(x=='.'){
				break;
			}
			SVdangky *sv=khoi_tao_node_SVdangky();
			Doc_sv_dk_loptc(filein,sv);
			ThemDau(tam,sv);
		}
		Them_dssv_vao_loptc(t,data,tam);
		filein.ignore();
	}
}

void xuat_thong_tin_SVloptc(SVdangky *sv){
	int dem = 0;
	for(SVdangky *s=sv; s!=NULL;s=s->next){
//		gotoxy(dai_khung_chuc_nang + 1 + 10, ngang1_danh_sach + 1 + dem);
//		cout<<s->MASV<<" "<<s->Diem<<endl;

		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 10 - 7, ngang2_danh_sach + 1 + dem);
		cout << s->MASV;
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 20 + 3 - 2, ngang2_danh_sach + 1 + dem);
		cout << s->Diem;
		TextColor(binh_thuong);
		dem++;
	}
}
void xuat_loptc(TREE t){
	if(t!=NULL){
		if(t->Dsdk!=NULL){
//			cout<<"lop :"<<t->LopTC.MALOPTC<<endl;
		    xuat_thong_tin_SVloptc(t->Dsdk);	
		}
		xuat_loptc(t->pLeft);
		xuat_loptc(t->pRight);
	}
}

void timkiem_sv_loptc(TREE t,string nk,string mamh,int hk,int nhom,bool &kt){
	if(t!=NULL){
		if(stricmp(nk.c_str(),t->LopTC.NienKhoa.c_str())==0){
			if(t->LopTC.HK==hk){
				if(t->LopTC.Nhom==nhom){
					if(stricmp(t->LopTC.MAMH,mamh.c_str())==0){
						xuat_thong_tin_SVloptc(t->Dsdk);
                        kt=true;
					}
				}
			}
		}
		timkiem_sv_loptc(t->pLeft,nk,mamh,hk,nhom,kt);
		timkiem_sv_loptc(t->pRight,nk,mamh,hk,nhom,kt);
	}
}

void tao_khung_chuc_nang_2(){	
	TextColor(noi_bat);
	gotoxy(dai_khung_chuc_nang_them0 / 2 - 12, ngang_chuc_nang_them0 - 2);
	cout << "IN DANH SACH SV CUA LTC";
	TextColor(binh_thuong);
	
	for (int i = 1; i < dai_khung_chuc_nang_them0 - 1; i++){
		gotoxy(i, ngang_chuc_nang_them0);
		cout << char(khung_ngoai);
		gotoxy(i, ngang_chuc_nang_them0 + 2);
		cout << char(khung_trong_them);
		gotoxy(i, ngang_chuc_nang_them0 + 2 + 2);
		cout << char(khung_trong_them);
		gotoxy(i, ngang_chuc_nang_them0 + 2 + 4);
		cout << char(khung_trong_them);
	}
	gotoxy(0,0);
	for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
		cout << char(khung_ngoai);
	}
	cout << endl;
	
	for (int i = 1; i < rong_khung_chuc_nang_them0 - 6; i++){
		cout << char(khung_ngoai);
		if(i > ngang_chuc_nang_them0){
			gotoxy(doc_chuc_nang_them0, i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang_them0 - 1, i);
		cout << char(khung_ngoai) <<endl;
	}
	for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
		cout << char(khung_ngoai);
	}
	gotoxy(0, rong_khung_chuc_nang_them0 - 5);
	cout << char(khung_ngoai);
	gotoxy(dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang_them0 - 5);
	cout << char(khung_ngoai) << endl;
	for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
		cout << char(khung_ngoai);
	}
	int dem = 1;
	for(int i = ngang_chuc_nang_them0 + 2; i < rong_khung_chuc_nang_them0 + 1 - 6; i = i + 2){
		gotoxy(1, i - 1);
		if (dem == 1){
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[dem][0], doc_chuc_nang_them0 - 1);
			dem++;
			TextColor(binh_thuong);
		}
		else if(dem == 4){
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[dem + 2][0], doc_chuc_nang_them0 - 1);
			dem++;
			TextColor(binh_thuong);
		}
		else{
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[dem][0], doc_chuc_nang_them0 - 1);
			dem++;
			TextColor(binh_thuong);
		}
	}
	
	gotoxy(1,3);
}

void xu_li_in_dsach_sv_ltc(TREE &t){
	int chuc_nang_duoc_chon = 1;
	char key_chuc_nang_them;
	int chon_thuoc_tinh = 1;
	
	int dai_khung_chuc_nang_them;
	int rong_khung_chuc_nang_them;
	int ngang_chuc_nang_them;
	int doc_chuc_nang_them;
	
	int so_thuoc_tinh = 7;
	
	dai_khung_chuc_nang_them = dai_khung_chuc_nang_them0;
	rong_khung_chuc_nang_them = rong_khung_chuc_nang_them0  - (rong_khung_chuc_nang + 2);
	ngang_chuc_nang_them = ngang_chuc_nang_them0 - (rong_khung_chuc_nang + 2) - 2;
	doc_chuc_nang_them = doc_chuc_nang_them0;
		
	for(int i = 0; i < so_thuoc_tinh; i++){
		thuoc_tinh_LTC[i][1] = "";
	}	
		
	int xac_nhan_du;
	while (1){
		xac_nhan_du = so_thuoc_tinh - 1 - 2;
		
		gotoxy(1 + doc_chuc_nang_them, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
		if(chon_thuoc_tinh == 4){
			nhap_tung_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh + 2][1], key_chuc_nang_them, chon_thuoc_tinh, chuc_nang_duoc_chon, 0);
		}
		else{
			nhap_tung_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][1], key_chuc_nang_them, chon_thuoc_tinh, chuc_nang_duoc_chon, 0);
		}
//		gotoxy(0,0);
//		cout << mang[6][1];
		
		for (int i = 0; i < so_thuoc_tinh; i++){
//			cout << xac_nhan_du;
			if((i == 0) && (thuoc_tinh_LTC[i][1].length() != 0)){
				xac_nhan_du = 0;
				break;
			}
			else{
				if(thuoc_tinh_LTC[i][1].length() != 0){
					xac_nhan_du = xac_nhan_du - 1;
				}
			}
		}
		if(xac_nhan_du == 0){
//			gotoxy(0,0);
			clear_Area(dai_khung_chuc_nang + 1, 0, dai_khung_chuc_nang + 2 + 27, rong_khung_danh_sach);
			show_danh_sach(chuc_nang_duoc_chon);
			bool ktra = false;
			timkiem_sv_loptc(t, thuoc_tinh_LTC[2][1], thuoc_tinh_LTC[1][1], atoi(thuoc_tinh_LTC[3][1].c_str()), atoi(thuoc_tinh_LTC[6][1].c_str()), ktra);
			if(ktra == false){
				gotoxy(1, rong_khung_chuc_nang_them0 - 5);
				TextColor(noi_bat);
				cout << "KHONG TIM THAY LTC PHU HOP!!!";
				TextColor(binh_thuong);
			}
			else{
				gotoxy(1, rong_khung_chuc_nang_them0 - 5);
				cout << "                             ";
			}
		}
//		key_chuc_nang_them = getch();
		if(key_chuc_nang_them == mui_ten_len){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
			
			if(chon_thuoc_tinh == 1){
				chon_thuoc_tinh = so_thuoc_tinh - 1 - 2;
			}
			else{
				chon_thuoc_tinh = chon_thuoc_tinh - 1;
			}
			
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
		}
		
		if(key_chuc_nang_them == mui_ten_xuong){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
				chon_thuoc_tinh = 1;
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
		}
		
		if(key_chuc_nang_them == enter){
//			gotoxy(0,0);
//			cout << "nhap di 3";
			
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
			
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				chon_thuoc_tinh = 1;
			}
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
		}
		if(key_chuc_nang_them == esc){
			gotoxy(0,0);
			clrscr();
			system(ma_system);
			Tao_khung_menu_main();
			break;
		}
	}
}

/////////////////////////////////
//CHUC NANG 3: CAP NHAT SINH VIEN

void tao_khung_them1_SV(){
//	system(ma_system);
	int khoang_cach_voi_khung_phia_tren = 2; //khoang cach voi khung chuc nang la 2
	
	TextColor(noi_bat);
	gotoxy(dai_khung_chuc_nang_xoa / 2 - 7, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + ngang_chuc_nang_xoa - 2);
	cout << "THEM SINH VIEN";
	gotoxy(1, rong_khung_chuc_nang + 5 + khoang_cach_voi_khung_phia_tren);
	TextColor(hien_thanh_sang);
	cout << "MA LOP MUON THEM";
	TextColor(binh_thuong);
	
	for (int i = 1; i < dai_khung_chuc_nang_xoa - 1; i++){
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + ngang_chuc_nang_xoa);
		cout << char(khung_ngoai);
	}
	gotoxy(0,rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren);
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	cout << endl;
	
	for (int i = 1; i < rong_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
		if(i > ngang_chuc_nang_xoa){
			gotoxy(doc_chuc_nang_xoa + 1, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + i);
		cout << char(khung_ngoai) <<endl;
	}
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	
	gotoxy(0, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 2);
	cout << char(khung_ngoai);
	gotoxy(dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 2);
	cout << char(khung_ngoai) << endl;
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	gotoxy(1, rong_khung_chuc_nang + 5 + khoang_cach_voi_khung_phia_tren);
}

void tao_khung_them2_or_sua2_SV(int them2_or_sua2){	
	int khoang_cach_voi_khung_chuc_nang = 2; //khoang cach voi khung chuc nang la 2
	
	khoang_cach_voi_khung_chuc_nang = 4 + rong_khung_chuc_nang_xoa;
	
	TextColor(noi_bat);
	gotoxy(dai_khung_chuc_nang_them2 / 2 - 9, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them2 - 2);
	cout << "THONG TIN SINH VIEN";
	TextColor(binh_thuong);
	
	for (int i = 1; i < dai_khung_chuc_nang_them4 - 1; i++){
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them2);
		cout << char(khung_ngoai);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them2 + 2);
		cout << char(khung_trong_them);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them2 + 2 + 2);
		cout << char(khung_trong_them);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them2 + 2 + 4);
		cout << char(khung_trong_them);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them2 + 2 + 6);
		cout << char(khung_trong_them);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them2 + 2 + 8);
		cout << char(khung_trong_them);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them2 + 2 + 10);
		cout << char(khung_trong_them);
	}
	gotoxy(0,rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang);
	for (int i = 0; i < dai_khung_chuc_nang_them2; i++){
		cout << char(khung_ngoai);
	}
	cout << endl;
	
	for (int i = 1; i < rong_khung_chuc_nang_them2; i++){
		cout << char(khung_ngoai);
		if(i > ngang_chuc_nang_them2){
			gotoxy(doc_chuc_nang_them2, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang_them2 - 1, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + i);
		cout << char(khung_ngoai) <<endl;
	}
	for (int i = 0; i < dai_khung_chuc_nang_them2; i++){
		cout << char(khung_ngoai);
	}
	int dem = 0;
	for(int i = ngang_chuc_nang_them2 + 2; i < rong_khung_chuc_nang_them2 + 1; i = i + 2){
		gotoxy(1, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + i - 1);
		if ((dem == 1) && (them2_or_sua2 == 0)){
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[dem][0], doc_chuc_nang_them2 - 1);
			dem++;
			TextColor(binh_thuong);
		}
		else if ((dem == 2) && (them2_or_sua2 == 1)){
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[dem][0], doc_chuc_nang_them2 - 1);
			dem++;
			TextColor(binh_thuong);
		}
		else{
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[dem][0], doc_chuc_nang_them2 - 1);
			dem++;
			TextColor(binh_thuong);
		}
	}
	
	gotoxy(1, rong_khung_chuc_nang + 3 + khoang_cach_voi_khung_chuc_nang);
}

////////////////////////////////
DanhsachSV* khoi_tao_node_SinhVien()
{
	DanhsachSV *p = new DanhsachSV;
	p->NEXT = NULL;
	return p;
}
//bool kt_malop_trung(DanhsachSV *dssv,char malop){
//    for(DanhsachSV *k=dssv; k!=NULL;k=k->NEXT){
//	    if(stricmp(k->SV.MALOP,malop)==0){
//	    	return 1;
//		}
//	 }
//	 return 0;
//}
void nhap_SinhVien(SinhVien &sv){
	
	strcpy(sv.MASV, thuoc_tinh_sv[1][1].c_str());
	sv.NamNH = atoi(thuoc_tinh_sv[2][1].c_str());
	sv.PHAI = thuoc_tinh_sv[3][1];
	sv.HO = thuoc_tinh_sv[4][1];
	sv.TEN = thuoc_tinh_sv[5][1];
	sv.SODT = thuoc_tinh_sv[6][1];	
	sv.pass="123456";					
}
void them_vao_ds_SinhVien(DanhsachSV *&dssv,DanhsachSV *&pTail,DanhsachSV *p){
	// neu danh sách rong
	if (dssv == NULL)
	{
		dssv = pTail =p;
	}
	//neu ma lop nho hon ma lop dau
	else if(stricmp(dssv->SV.MALOP,p->SV.MALOP)>0){
		p->NEXT=dssv;
		dssv=p;
	}
	// neu ma lop lon hon ma lop cuoi
	else if(stricmp(pTail->SV.MALOP,p->SV.MALOP)<0){
		  pTail->NEXT=p;
		  pTail=p;
	}
	// neu ma lop dau = voi p->2 truoc hop
	else if(stricmp(dssv->SV.MALOP,p->SV.MALOP)==0){
		//neu chi co 1 ma lop->3 truong hop
		 if(stricmp(dssv->SV.MALOP,p->SV.MALOP)==0&&stricmp(pTail->SV.MALOP,p->SV.MALOP)==0){
		 	// neu ma sv chen vao lon hon 
	    	if(stricmp(pTail->SV.MASV,p->SV.MASV)<0){
				pTail->NEXT=p;
				pTail=p;
			}
			// neu ma sv chen vao be hon th dau danh sach	
			else if(stricmp(dssv->SV.MASV,p->SV.MASV)>0){
				p->NEXT=dssv;
				dssv=p;
			}
			// neu ma sv nam giua 
			else{
			for(DanhsachSV *k=dssv;k!=NULL;k=k->NEXT){
				  if(stricmp(k->SV.MASV,p->SV.MASV)<0&&stricmp(k->NEXT->SV.MASV,p->SV.MASV)>0){
				  	DanhsachSV *g=k->NEXT;
				  	p->NEXT=g;
				  	k->NEXT=p;
				  }
				}
			}
		}
		// neu co nhieu ma lop ->2 truong hop
		else{
			//neu ma lop chen vao be hon dau danh sach
			if(stricmp(dssv->SV.MASV,p->SV.MASV)>0){
				p->NEXT=dssv;
				dssv=p;
			}
			// neu ma lop chen vao nam sau (hay nam giua do)
			else{
							DanhsachSV *h;
							DanhsachSV *k=dssv;
							while(stricmp(k->SV.MALOP,k->NEXT->SV.MALOP)==0){
								h=k;
								if(stricmp(k->NEXT->SV.MASV,p->SV.MASV)>0){
									p->NEXT=k->NEXT;
									h->NEXT=p;
									k=k->NEXT;
									break;
								}
								k=k->NEXT;
							}
								if(stricmp(k->SV.MASV,p->SV.MASV)<0){
								h=k;
								p->NEXT=k->NEXT;
								h->NEXT=p;
							}
						}
		}
	}
	// neu ma lop nam giua 
	else
	{
			for (DanhsachSV *k = dssv;k!=NULL ; k = k->NEXT)
			{
			 	DanhsachSV *g=k->NEXT;
			 	//neu ma lop nam giua ma chua co ai(malop)
				if (stricmp(k->SV.MALOP,p->SV.MALOP)<0 && stricmp(k->NEXT->SV.MALOP,p->SV.MALOP)>0)
				{
					p->NEXT=g;
					k->NEXT=p;
					break;
				}
				// neu ma nam gia ma co ai
				else if(stricmp(k->SV.MALOP,p->SV.MALOP)<0&&stricmp(k->NEXT->SV.MALOP,p->SV.MALOP)==0){
					//neu ma sv chen vao be hon h ma sv nam dau trong ma lop do
						if(stricmp(k->NEXT->SV.MASV,p->SV.MASV)>0){
							p->NEXT=g;
							k->NEXT=p;
							break;
						}
						// neu ma sv chen vao lop hon ma sv cuoi (nghia la ma lop nay dang nam cuoi hay la lon nhat)
						else if(stricmp(pTail->SV.MASV,p->SV.MASV)<0&&stricmp(pTail->SV.MALOP,p->SV.MALOP)==0){
							pTail->NEXT=p;
							pTail=p;
							break;
						}
						// neu ma sv nam giua va ma lop nay ko nam cuoi 
						else{
							k=k->NEXT;
							DanhsachSV *h;
							while(stricmp(k->SV.MALOP,k->NEXT->SV.MALOP)==0){
								h=k;
								if(stricmp(k->NEXT->SV.MASV,p->SV.MASV)>0){
									p->NEXT=k->NEXT;
									h->NEXT=p;
									k=k->NEXT;
									break;
								}
								k=k->NEXT;
							}
							if(stricmp(k->SV.MASV,p->SV.MASV)<0){
								h=k;
								p->NEXT=k->NEXT;
								h->NEXT=p;
								break;
							}
						}
				}
		}
	}
}
DanhsachSV* middle(DanhsachSV* start, DanhsachSV* last) 
{ 
	if (start == NULL) 
		return NULL; 
	 DanhsachSV* slow = start; 
	 DanhsachSV* fast = start->NEXT; 
	while (fast != last) 
	{ 
		fast = fast->NEXT; 
		if (fast != last) 
		{ 
			slow = slow->NEXT; 
			fast = fast->NEXT; 
		} 
	} 
	return slow;
} 
bool kt_malop_trung(DanhsachSV *dssv,DanhsachSV *pTail,string malop){
	DanhsachSV *mid;
	DanhsachSV *last=NULL;
	if(dssv==NULL){
		return false;
	}
	else if(stricmp(dssv->SV.MALOP,pTail->SV.MALOP)==0){
		if(stricmp(dssv->SV.MALOP,malop.c_str())==0) return true;
		else {return false;}
	}
	else if(stricmp(dssv->SV.MALOP,malop.c_str())==0) return true;
	else if(stricmp(pTail->SV.MALOP,malop.c_str())==0) return true;
	else {
	do{
        mid=middle(dssv,last);
        if(mid==NULL) return false;
		if(stricmp(mid->SV.MALOP,malop.c_str())==0){
			return true;
		}  
		else if(stricmp(mid->SV.MALOP,malop.c_str())<0){
			dssv=mid->NEXT;
		}
		else
		{
			last=mid;
		}
	} while(last==NULL||last!=dssv);
	return false;
   }
}

DanhsachSV *kt_masv_trung(DanhsachSV *dssv,DanhsachSV *pTail,string masv)
{
	if(dssv==NULL){
		return NULL;
	}
	else if(stricmp(dssv->SV.MASV,masv.c_str())==0) return dssv;
	else if(stricmp(pTail->SV.MASV,masv.c_str())==0) return pTail;
	else{
		for(DanhsachSV *k=dssv->NEXT; k!=NULL; k=k->NEXT )
		{
			if(stricmp(k->SV.MASV, masv.c_str())==0)
			{
				return k;
			}
		}
	}
	return NULL;	
}

void cau_d(DanhsachSV *dssv, string malop)
{	
	int row = 0;
	for(DanhsachSV *k= dssv; k!=NULL; k=k->NEXT )
	{
		if(stricmp(k->SV.MALOP, malop.c_str())==0)
		{
			thuoc_tinh_sv[0][1] = k->SV.MALOP;
			thuoc_tinh_sv[1][1] = k->SV.MASV;
			thuoc_tinh_sv[2][1] = chuyen_int_string(k->SV.NamNH);
			thuoc_tinh_sv[3][1] = k->SV.PHAI;
			thuoc_tinh_sv[4][1] = k->SV.HO;
			thuoc_tinh_sv[5][1] = k->SV.TEN;
			thuoc_tinh_sv[6][1] = k->SV.SODT;
			
			TextColor(noi_bat);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + (do_rong_o1_danh_sach2 - 1)/2 - thuoc_tinh_sv[0][1].length()/2, ngang2_danh_sach - 1 + row + 2);
			cout << thuoc_tinh_sv[0][1];

			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o1_danh_sach2 + (do_rong_o2_danh_sach2 - 1 - do_rong_o1_danh_sach2)/2 - thuoc_tinh_sv[1][1].length()/2, ngang2_danh_sach - 1 + row + 2);
			cout << thuoc_tinh_sv[1][1];
	
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach2 + (do_rong_o3_danh_sach2 - 1 - (do_rong_o2_danh_sach2))/2 - thuoc_tinh_sv[2][1].length()/2 + 1, ngang2_danh_sach - 1 + row + 2);
			cout << thuoc_tinh_sv[2][1];

			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach2 + (do_rong_o4_danh_sach2 - 1 - (do_rong_o3_danh_sach2))/2 - thuoc_tinh_sv[3][1].length()/2 + 1, ngang2_danh_sach - 1 + row + 2);
			cout << thuoc_tinh_sv[3][1];

			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[4][1].length()/2, ngang2_danh_sach - 1 + row + 2);
			cout << thuoc_tinh_sv[4][1];

			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + do_rong_con_lai(2) / 3 * 1 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[5][1].length()/2, ngang2_danh_sach - 1 + row + 2);
			cout << thuoc_tinh_sv[5][1];

			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + do_rong_con_lai(2) / 3 * 2 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[6][1].length()/2, ngang2_danh_sach - 1 + row + 2);
			cout << thuoc_tinh_sv[6][1];
			TextColor(binh_thuong);
			row++;
		}
		if(k->NEXT==NULL)
		{
			break;
		}
		if(stricmp(k->SV.MALOP, malop.c_str())==0&&stricmp(k->NEXT->SV.MALOP, malop.c_str())!=0)	
		break;
	} 
}

void xu_li_them_SV(DanhsachSV *dssv, DanhsachSV *pTail, int &xac_nhan_tra_ve){
	char key_chuc_nang_them;
	int chon_thuoc_tinh = 1;
	
	int so_thuoc_tinh = 7;
	
	gotoxy(doc_chuc_nang_them2 + 1, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 7 + 1);
	TextColor(noi_bat);
	cout << thuoc_tinh_sv[0][1];
	TextColor(binh_thuong);
	
	gotoxy(doc_chuc_nang_them2, rong_khung_chuc_nang + 2 + 7 + rong_khung_chuc_nang_xoa + 2);
	while (1){
		bool ktra = false;
		int xac_nhan_du = so_thuoc_tinh - 1;
		
		for (int i = 1; i < so_thuoc_tinh; i++){
			if(thuoc_tinh_sv[i][1].length() != 0){
				xac_nhan_du = xac_nhan_du - 1;
			}
		}
		
		if(xac_nhan_du == 0){
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(binh_thuong);
			cout << "                                       ";
			TextColor(binh_thuong);
			gotoxy(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang_them2 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
			cout << char(khung_ngoai) << endl;
			for (int i = 0; i < dai_khung_chuc_nang_them2; i++){
				cout << char(khung_ngoai);
			}
			DanhsachSV *ktmasv = kt_masv_trung(dssv,pTail,thuoc_tinh_sv[1][1]);
			if(ktmasv!=NULL){
			   	ktra = true;
			}
			gotoxy(1, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 1 + rong_khung_chuc_nang_them2 + 3);
			TextColor(noi_bat);
			if(ktra == false){
				cout << "BAM F1 DE THEM!!!";
			}
			else{
				cout << "TRUNG MA SV!";
			}
			TextColor(binh_thuong);
		}
		else{
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(binh_thuong);
			cout << "                                         ";
		}

		gotoxy(1 + doc_chuc_nang_them0, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
		
		nhap_tung_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][1], key_chuc_nang_them, chon_thuoc_tinh, 2 , 0);
		
		if(key_chuc_nang_them == mui_ten_len){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
			if(chon_thuoc_tinh == 1){
				chon_thuoc_tinh = (chon_thuoc_tinh - 1 - 1 + (so_thuoc_tinh + 1)) % (so_thuoc_tinh + 1) - 1;
			}
			else{
				chon_thuoc_tinh = chon_thuoc_tinh - 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
		}
		else if(key_chuc_nang_them == mui_ten_xuong){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1){
				chon_thuoc_tinh = 1;
			}	
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
		}
		else if(key_chuc_nang_them == enter){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1){
				chon_thuoc_tinh = 1;
			}	
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
		}
		else if(key_chuc_nang_them == esc){
			gotoxy(0,0);
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them2 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them2 + 2);
			system(ma_system);
			tao_khung_menu_chuc_nang(2);
			show_danh_sach(2);
			xac_nhan_tra_ve = 2;
			break;
		}
		else if((key_chuc_nang_them == F1) && (ktra == false)){
			//vao them ltc
			if(xac_nhan_du != 0){
				if(thuoc_tinh_sv[1][1].length() == 0){
					xac_nhan_tra_ve == 2;
					clear_Area(0, rong_khung_chuc_nang + 1, dai_khung_chuc_nang_them2, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 1 + rong_khung_chuc_nang_them2 + 2);
					break;
				}
				else{
					gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
					TextColor(noi_bat);
					cout << "NHAP THIEU THUOC TINH, ENTER DE TIEP TUC";
					TextColor(binh_thuong);
					char x = getch();
					if(x == esc){
						xac_nhan_tra_ve == 2;
						clear_Area(0, rong_khung_chuc_nang + 1, dai_khung_chuc_nang_them2, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 1 + rong_khung_chuc_nang_them2 + 2);
						break;
					}
				}
			}
			else{
				gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
				TextColor(an_thanh_sang);
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
				gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + 1 * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
				TextColor(hien_thanh_sang);
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[1][0],doc_chuc_nang_them2 - 1);
				
				gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
				TextColor(binh_thuong);
				cout << "                                ";
				gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
				TextColor(noi_bat);
				cout << "XAC NHAN THEM";
				TextColor(binh_thuong);
				xac_nhan_tra_ve = 3;
				break;
			}
		}
	}
}

void doc_sv(ifstream &filein,SinhVien &sv){
	char x;
	getline(filein,sv.HO,',');
	getline(filein,sv.TEN,',');
	getline(filein,sv.PHAI,',');
	getline(filein,sv.SODT,',');
	filein>>sv.NamNH;
	filein>>x;
	getline(filein,sv.pass,',');
	filein>>sv.MALOP;
}
void xuat_Dssv(DanhsachSV *dssv){
	int row = 0;
	for(DanhsachSV *k=dssv;k!=NULL;k=k->NEXT){
//		cout<<"malop: "<<k->SV.MALOP<<"  "<<k->SV.HO<<" "<<k->SV.TEN<<" "<<k->SV.PHAI<<" "<<k->SV.SODT<<" "<<k->SV.NamNH<<" "<<k->SV.pass<<"  "<<k->SV.MASV<<endl;
		thuoc_tinh_sv[0][1] = k->SV.MALOP;
		thuoc_tinh_sv[1][1] = k->SV.MASV;
		thuoc_tinh_sv[2][1] = chuyen_int_string(k->SV.NamNH);
		thuoc_tinh_sv[3][1] = k->SV.PHAI;
		thuoc_tinh_sv[4][1] = k->SV.HO;
		thuoc_tinh_sv[5][1] = k->SV.TEN;
		thuoc_tinh_sv[6][1] = k->SV.SODT;
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 1 + (do_rong_o1_danh_sach2 - 1)/2 - thuoc_tinh_sv[0][1].length()/2, ngang2_danh_sach - 1 + row + 2);
		cout << thuoc_tinh_sv[0][1];
		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o1_danh_sach2 + (do_rong_o2_danh_sach2 - 1 - do_rong_o1_danh_sach2)/2 - thuoc_tinh_sv[1][1].length()/2, ngang2_danh_sach - 1 + row + 2);
		cout << thuoc_tinh_sv[1][1];
		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach2 + (do_rong_o3_danh_sach2 - 1 - (do_rong_o2_danh_sach2))/2 - thuoc_tinh_sv[2][1].length()/2 + 1, ngang2_danh_sach - 1 + row + 2);
		cout << thuoc_tinh_sv[2][1];
		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach2 + (do_rong_o4_danh_sach2 - 1 - (do_rong_o3_danh_sach2))/2 - thuoc_tinh_sv[3][1].length()/2 + 1, ngang2_danh_sach - 1 + row + 2);
		cout << thuoc_tinh_sv[3][1];
		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[4][1].length()/2, ngang2_danh_sach - 1 + row + 2);
		cout << thuoc_tinh_sv[4][1];
		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + do_rong_con_lai(2) / 3 * 1 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[5][1].length()/2, ngang2_danh_sach - 1 + row + 2);
		cout << thuoc_tinh_sv[5][1];
		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 + do_rong_con_lai(2) / 3 * 2 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[6][1].length()/2, ngang2_danh_sach - 1 + row + 2);
		cout << thuoc_tinh_sv[6][1];
		TextColor(binh_thuong);
		row++;
	}
}
void doc_dssv(DanhsachSV *&dssv,DanhsachSV *&pTail,ifstream &filein){
	string tam;
	filein.seekg(2);
	while(!filein.eof()){
		DanhsachSV *p=khoi_tao_node_SinhVien();
		getline(filein,tam,',');
		strcpy(p->SV.MASV,tam.c_str());
		doc_sv(filein,p->SV);
		filein.ignore();
		them_vao_ds_SinhVien(dssv,pTail,p);
	}
}
void Ghi_file_sv(ofstream &fileout,SinhVien sv){
		fileout<<endl<<sv.MASV<<","<<sv.HO<<","<<sv.TEN<<","<<sv.PHAI<<","<<sv.SODT<<","<<sv.NamNH<<","<<sv.pass<<","<<sv.MALOP;
}
void Ghi_file_dssv(DanhsachSV *dssv,ofstream &fileout)
{
	for(DanhsachSV *k=dssv;k!=NULL;k=k->NEXT){
		Ghi_file_sv(fileout,k->SV);		
	}
}

void them_SinhVien(DanhsachSV *&dssv,DanhsachSV *&pTail){
	string malop;
	int yes_no_esc_f1;
	char phim;
//	cout<<"MA LOP THEM";getline(cin,malop);
	gotoxy(doc_chuc_nang_xoa + 2, rong_khung_chuc_nang + 1 + 6);
	nhap_tung_ki_tu(thuoc_tinh_sv[0][1], phim, 0, 2, 4);
	malop = thuoc_tinh_sv[0][1];
	cau_d(dssv, malop);
	for(int i = 1; i< 7; i++){
		thuoc_tinh_sv[i][1] = "";
	}
	bool kt=kt_malop_trung(dssv,pTail,malop);
		if(kt==true){
			int chon;
			gotoxy(1, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(noi_bat);
			cout<<"MA LOP DA CO, CHON:	ENTER.GHI DE	TAP.ESC";
			TextColor(binh_thuong);
			phim = getch();
			if(phim == enter){
				tao_khung_them2_or_sua2_SV(0);
			   while(true){
			   	xu_li_them_SV(dssv, pTail, yes_no_esc_f1);
			   	   if(thuoc_tinh_sv[1][1].length()==0){
					 break;			   	  	
					}
			   	  //goi ham xac nhan
			   	  	if(yes_no_esc_f1 == 3){
						xu_li_xac_nhan(0, 2, yes_no_esc_f1);
						if(yes_no_esc_f1 == 0){
							DanhsachSV *p=khoi_tao_node_SinhVien();
						   	  strcpy(p->SV.MALOP,malop.c_str());
					   	  nhap_SinhVien(p->SV);
					   	  them_vao_ds_SinhVien(dssv,pTail,p);
					   	  ofstream fileout;
					    	fileout.open("dssv.txt", ios_base::out);
					    	if (fileout.fail() == true){
							   cout << "\nFile cua ban khong ton tai";
							   system("pause");
					        }
							Ghi_file_dssv(dssv, fileout);
							fileout.close();
							clear_Area(dai_khung_chuc_nang + 2, 0, dai_khung_chuc_nang + 2 + dai_khung_danh_sach, rong_khung_danh_sach);
							show_danh_sach(2);
							cau_d(dssv, thuoc_tinh_sv[0][1]);
							for(int i = 1; i < 7; i++){
						   		gotoxy(doc_chuc_nang_them2 + 1, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 1 + 7 + i * 2);
						   		thuoc_tinh_sv[i][1] = "";
						   		cout << "                                               ";
						   }
						}
						if(yes_no_esc_f1 == 2){
							clear_Area(0, rong_khung_chuc_nang + 1, dai_khung_chuc_nang_xoa, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 1 + rong_khung_chuc_nang_them2 + 1 + 3);
							break;
						}
					}
			   }
			}
			else{
				clear_Area(0, rong_khung_chuc_nang + 1, dai_khung_chuc_nang_xoa, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 1 + rong_khung_chuc_nang_them2 + 1);
			}
		}
		else if((kt == false) && (malop.length() != 0)){
			tao_khung_them2_or_sua2_SV(0);
			while(true){
				xu_li_them_SV(dssv, pTail, yes_no_esc_f1);
			   	  if(thuoc_tinh_sv[1][1].length()==0){
					 break;			   	  	
					}
			   	  //goi ham xac nhan
			   	  	if(yes_no_esc_f1 == 3){
						xu_li_xac_nhan(0, 2, yes_no_esc_f1);
						if(yes_no_esc_f1 == 0){
							DanhsachSV *p=khoi_tao_node_SinhVien();
						   	  strcpy(p->SV.MALOP,malop.c_str());
					   	  	cin.ignore();
					   	  nhap_SinhVien(p->SV);
					   	  them_vao_ds_SinhVien(dssv,pTail,p);
					   	  ofstream fileout;
					    	fileout.open("dssv.txt", ios_base::out);
					    	if (fileout.fail() == true){
							   cout << "\nFile cua ban khong ton tai";
							   system("pause");
					        }
							Ghi_file_dssv(dssv, fileout);
							fileout.close();
							for(int i = 1; i < 7; i++){
						   		gotoxy(doc_chuc_nang_them2 + 1, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 1 + 7 + i * 2);
						   		thuoc_tinh_sv[i][1] = "";
						   		cout << "                                               ";
						   }
						}
						else if(yes_no_esc_f1 == 2){
							clear_Area(0, rong_khung_chuc_nang + 1, dai_khung_chuc_nang_xoa, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 1 + rong_khung_chuc_nang_them2 + 1 + 3);
							break;
						}
					}
			   }
		}
		else if(malop.length() == 0){
			clear_Area(0, rong_khung_chuc_nang + 1, dai_khung_chuc_nang_xoa, rong_khung_chuc_nang + 1 + rong_khung_chuc_nang_xoa + 3);
		}
}

////////////////////////////////////

void kt_sv_trong_dsdk(SVdangky *svdk,bool &kt,string masv){
	for(SVdangky *k=svdk;k!=NULL;k=k->next){
		if(stricmp(k->MASV,masv.c_str())==0) {
		kt=true;break;
		}
	}
}
void kt_sv_trong_loptc(TREE t,string masv,bool &kt){
	if (t != NULL){
		kt_sv_trong_dsdk(t->Dsdk,kt,masv);
		if(kt==true) return;
		kt_sv_trong_loptc(t->pLeft,masv,kt);
		kt_sv_trong_loptc(t->pRight,masv,kt);
	}
}

void tao_khung_xoa_or_sua1_SV(int xoa_or_sua1){
//	system(ma_system);
	int khoang_cach_voi_khung_phia_tren = 2; //khoang cach voi khung chuc nang la 2
	
	string s = "XOA";
	if(xoa_or_sua1 == 1){
		s = "HIEU CHINH";
	}
	TextColor(noi_bat);
	gotoxy(dai_khung_chuc_nang_xoa / 2 - (s.length() + 10)/2, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + ngang_chuc_nang_xoa - 2);
	cout << s << " 1 SINH VIEN";
	gotoxy(1, rong_khung_chuc_nang + 5 + khoang_cach_voi_khung_phia_tren);
	TextColor(hien_thanh_sang);
	cout << "MA SV MUON " << s + " ";
	TextColor(binh_thuong);
	
	for (int i = 1; i < dai_khung_chuc_nang_xoa - 1; i++){
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + ngang_chuc_nang_xoa);
		cout << char(khung_ngoai);
	}
	gotoxy(0,rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren);
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	cout << endl;
	
	for (int i = 1; i < rong_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
		if(i > ngang_chuc_nang_xoa){
			if(xoa_or_sua1 == 1){
				gotoxy(doc_chuc_nang_xoa + 7, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + i);
			}
			else{
				gotoxy(doc_chuc_nang_xoa, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + i);
			}
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + i);
		cout << char(khung_ngoai) <<endl;
	}
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	gotoxy(1, rong_khung_chuc_nang + 5 + khoang_cach_voi_khung_phia_tren);
}

void nhap_xoa_or_sua1_SV(TREE t, int xoa_or_sua1, int &dk_tra_ve){
	char phim;
	
	gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
	TextColor(binh_thuong);
	cout << "                                          ";
	TextColor(binh_thuong);
	gotoxy(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
	cout << char(khung_ngoai);
	gotoxy(dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
	cout << char(khung_ngoai) << endl;
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	
//	gotoxy(0,0);
//	cout << chuc_nang_duoc_chon;
	while (1){
		if(xoa_or_sua1 == 0){
			gotoxy(doc_chuc_nang_xoa + 1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_xoa + 1);
			nhap_tung_ki_tu(thuoc_tinh_sv[1][1], phim, 1, 2, 1);
		}
		else if(xoa_or_sua1 == 1){
			gotoxy(doc_chuc_nang_xoa + 8, rong_khung_chuc_nang + 2 + ngang_chuc_nang_xoa + 1);
			nhap_tung_ki_tu(thuoc_tinh_sv[1][1], phim, 1, 2, 2);
		}
		
		if(thuoc_tinh_sv[1][1].length() == 0){
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
			TextColor(noi_bat);
			cout << "                                         ";
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
			cout << "ESC de thoat hoac nhap lai";
			TextColor(binh_thuong);
		}
		else{
			TextColor(noi_bat);
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
			cout << "                                     ";
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
			if(xoa_or_sua1 == 0){
				cout << "BAM F1 DE XOA!!!";
			}
			else if(xoa_or_sua1 == 1){
				cout << "BAM F1 DE HIEU CHINH!!!";
			}
			TextColor(binh_thuong);
		}
//		phim = getch();
		if(phim == esc){
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
			dk_tra_ve = 2;
			break;
		}
		if(phim == F1){
			dk_tra_ve = 3;
			
			if(xoa_or_sua1 == 0){
				bool ktra = false;
				kt_sv_trong_loptc(t, thuoc_tinh_sv[1][1], ktra);
				if(ktra == true){
					gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
					TextColor(noi_bat);
					cout << "SV DA CO TRONG LTC, KHONG DUOC XOA!!!";
					TextColor(binh_thuong);
				}
				else{
					gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
					TextColor(binh_thuong);
					cout << "                                       ";
					gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
					TextColor(noi_bat);
					cout << "XAC NHAN XOA";
					TextColor(binh_thuong);
					break;
				}
			}
			if(xoa_or_sua1 == 1){
				break;
			}
		}
	}
}

void XoaDau_dssv(DanhsachSV *&dssv)
{
	if (dssv == NULL)
	{
		return;
	}
	DanhsachSV *p = dssv; 
	dssv = dssv->NEXT;
	delete p;
}
void XoaCuoi_dssv(DanhsachSV *&dssv,DanhsachSV *&pTail)
{
	// neu danh sách rong
	if (dssv == NULL)
	{
		return;
	}
	// truong hop danh sách có 1 phan tu
	if (dssv->NEXT == NULL)
	{
		XoaDau_dssv(dssv);
		return;
	}
	// duyet tu dau danh sách den thang ke cuoi
	for (DanhsachSV *k = dssv; k != NULL; k = k->NEXT)
	{
		// phát hien thang ke cuoi
		if (k->NEXT == pTail)
		{
			delete pTail; // xóa di phan tu cuoi
			k->NEXT = NULL; 
			pTail = k; 
			return;
		}
	}
}
void Xoa_SinhVien(DanhsachSV *&dssv, DanhsachSV *&pTail, string masv)
{
	// neu danh sách rong thì không làm gì het
	if (dssv == NULL) return;
	else if (stricmp(dssv->SV.MASV,masv.c_str())==0)
	{
		XoaDau_dssv(dssv);
		return;
	}
	// neu node can xóa nam o cuoi danh sách
	else if (stricmp(pTail->SV.MASV,masv.c_str())==0)
	{
		XoaCuoi_dssv(dssv,pTail);
		return;
	}
	else{
		  DanhsachSV *g=dssv;
			for(DanhsachSV *k=dssv->NEXT;k!=NULL;k=k->NEXT){
				if (stricmp(k->SV.MASV,masv.c_str())==0){
				    g->NEXT = k->NEXT; 
					delete k; 	
					return;
				}
				g = k; 
			}
		gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
		cout << "                                        ";
		gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
		TextColor(noi_bat);
		cout<<"Khong co ma sv nay, enter de tiep tuc!!!";
		getch();
		TextColor(binh_thuong);
		thuoc_tinh_LTC[0][1] = "";
	}
}

void xu_li_xoa_SV(DanhsachSV *&dssv, DanhsachSV *&pTail, TREE t)
{
	tao_khung_xoa_or_sua1_SV(0);
	xuat_Dssv(dssv);
	thuoc_tinh_sv[1][1] = "";
	int yes_or_esc_f1;
	while(1){
		nhap_xoa_or_sua1_SV(t, 0, yes_or_esc_f1);
		if(yes_or_esc_f1 == 3){
			xu_li_xac_nhan(1, 2, yes_or_esc_f1);
			if(yes_or_esc_f1 == 0){
				Xoa_SinhVien(dssv, pTail, thuoc_tinh_sv[1][1]);
				if(thuoc_tinh_sv[1][1].length() != 0){
					ofstream fileout;
					fileout.open("dssv.txt", ios_base::out);
					Ghi_file_dssv(dssv,fileout);
					fileout.close();
					
					clear_Area(dai_khung_chuc_nang + 2, 0, dai_khung_chuc_nang + 2 + dai_khung_danh_sach, rong_khung_danh_sach);
					show_danh_sach(2);
					xuat_Dssv(dssv);
					getch();
					clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
					break;
				}
			}
		}
		if(yes_or_esc_f1 == 2){
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
			break;
		}
	}
}

void nhap_sua2_SV(DanhsachSV *&dssv, DanhsachSV *&pTail, int &xac_nhan_tra_ve){
	char key_chuc_nang_them;
	int chon_thuoc_tinh = 2;
	
	int so_thuoc_tinh = 7;
	
	gotoxy(doc_chuc_nang_them2, rong_khung_chuc_nang + 2 + 7 + rong_khung_chuc_nang_xoa + 2);
	while (1){
		bool ktra = false;
		int xac_nhan_du = so_thuoc_tinh - 1;
		
		for (int i = 1; i < so_thuoc_tinh; i++){
			if(thuoc_tinh_sv[i][1].length() != 0){
				xac_nhan_du = xac_nhan_du - 1;
			}
		}
		
		if(xac_nhan_du == 0){
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(binh_thuong);
			cout << "                                       ";
			TextColor(binh_thuong);
			gotoxy(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
			cout << char(khung_ngoai) << endl;
			for (int i = 0; i < dai_khung_chuc_nang_them2; i++){
				cout << char(khung_ngoai);
			}
			
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(noi_bat);
			if(ktra == false){
				cout << "BAM F1 DE HIEU CHINH!!!";
			}
//			else{
//				cout << "TRUNG THUOC TINH!";
//			}
			TextColor(binh_thuong);
		}
		else{
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(binh_thuong);
			cout << "                              ";
		}

		gotoxy(1 + doc_chuc_nang_them2, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
		
		nhap_tung_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][1], key_chuc_nang_them, chon_thuoc_tinh, 2 , 3);
		
		if(key_chuc_nang_them == mui_ten_len){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
			if(chon_thuoc_tinh == 2){
				chon_thuoc_tinh = 6;
			}
			else{
				chon_thuoc_tinh = chon_thuoc_tinh - 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
		}
		else if(key_chuc_nang_them == mui_ten_xuong){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1){
				chon_thuoc_tinh = 2;
			}	
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
		}
		else if(key_chuc_nang_them == enter){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1){
				chon_thuoc_tinh = 2;
			}	
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
		}
		else if(key_chuc_nang_them == esc){
			gotoxy(0,0);
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them2 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them2 + 2);
			system(ma_system);
			tao_khung_menu_chuc_nang(2);
			show_danh_sach(2);
			xac_nhan_tra_ve = 2;
			break;
		}
		else if((key_chuc_nang_them == F1) && (xac_nhan_du == 0) && (ktra == false)){
			//vao them ltc
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[chon_thuoc_tinh][0],doc_chuc_nang_them2 - 1);
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them2 + 2 + 2 * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_sv[2][0],doc_chuc_nang_them2 - 1);
			
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(binh_thuong);
			cout << "                                ";
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them2 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(noi_bat);
			cout << "XAC NHAN HIEU CHINH";
			TextColor(binh_thuong);
			xac_nhan_tra_ve = 3;
			break;
		}
		
	}
}

void Sua_SinhVien(DanhsachSV *&dssv, DanhsachSV *&pTail, string masv)
{
	// neu danh sách rong thì không làm gì het
	if (dssv == NULL){
		thuoc_tinh_sv[1][1] = "";
		return;
	}
	else if (stricmp(dssv->SV.MASV,masv.c_str())==0)
	{
//		clear_Area(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1, dai_khung_chuc_nang_xoa, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
		tao_khung_them2_or_sua2_SV(1);
		
		thuoc_tinh_sv[1][1] = dssv->SV.MASV;
		thuoc_tinh_sv[2][1] = chuyen_int_string(dssv->SV.NamNH);
		thuoc_tinh_sv[3][1] = dssv->SV.PHAI;
		thuoc_tinh_sv[4][1] = dssv->SV.HO;
		thuoc_tinh_sv[5][1] = dssv->SV.TEN;
		thuoc_tinh_sv[6][1] = dssv->SV.SODT;
		thuoc_tinh_sv[0][1] = dssv->SV.MALOP;
		int dem = 0;
		for(int i = ngang_chuc_nang_them2 + 2; i < rong_khung_chuc_nang_them2 + 1; i = i + 2){
			gotoxy(doc_chuc_nang_them2 + 1, rong_khung_chuc_nang + rong_khung_chuc_nang_xoa + 4 + i - 1);
			TextColor(noi_bat);
			cout << thuoc_tinh_sv[dem][1];
			TextColor(binh_thuong);
			dem++;
		}
		
		int yes_no_esc_f1;
		while(1){
			nhap_sua2_SV(dssv, pTail, yes_no_esc_f1);
			if(yes_no_esc_f1 == 3){
				xu_li_xac_nhan(2, 2, yes_no_esc_f1);
				if(yes_no_esc_f1 == 0){
					strcpy(dssv->SV.MALOP, thuoc_tinh_sv[0][1].c_str());
					strcpy(dssv->SV.MASV, thuoc_tinh_sv[1][1].c_str());
					dssv->SV.NamNH = atoi(thuoc_tinh_sv[2][1].c_str());
					dssv->SV.PHAI = thuoc_tinh_sv[3][1];
					dssv->SV.HO = thuoc_tinh_sv[4][1];
					dssv->SV.TEN = thuoc_tinh_sv[5][1];
					dssv->SV.SODT = thuoc_tinh_sv[6][1];
					break;
				}
			}
			if(yes_no_esc_f1 == 2){
				clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them2 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them2 + 2);
				thuoc_tinh_sv[0][1] = "";
				break;
			}
		}
		return;
	}
	// neu node can xóa nam o cuoi danh sách
	else if (stricmp(pTail->SV.MASV,masv.c_str())==0)
	{
		tao_khung_them2_or_sua2_SV(1);
		clear_Area(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1, dai_khung_chuc_nang_xoa, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
		tao_khung_them2_or_sua2_SV(1);
		
		thuoc_tinh_sv[1][1] = pTail->SV.MASV;
		thuoc_tinh_sv[2][1] = chuyen_int_string(pTail->SV.NamNH);
		thuoc_tinh_sv[3][1] = pTail->SV.PHAI;
		thuoc_tinh_sv[4][1] = pTail->SV.HO;
		thuoc_tinh_sv[5][1] = pTail->SV.TEN;
		thuoc_tinh_sv[6][1] = pTail->SV.SODT;
		thuoc_tinh_sv[0][1] = pTail->SV.MALOP;
		int dem = 0;
		
		for(int i = ngang_chuc_nang_them2 + 2; i < rong_khung_chuc_nang_them2 + 1; i = i + 2){
			gotoxy(doc_chuc_nang_them2 + 1, rong_khung_chuc_nang + rong_khung_chuc_nang_xoa + 4 + i - 1);
			TextColor(noi_bat);
			cout << thuoc_tinh_sv[dem][1];
			TextColor(binh_thuong);
			dem++;
		}
		
		int yes_no_esc_f1;
		while(1){
			nhap_sua2_SV(dssv, pTail, yes_no_esc_f1);
			if(yes_no_esc_f1 == 3){
				xu_li_xac_nhan(2, 2, yes_no_esc_f1);
				if(yes_no_esc_f1 == 0){
					strcpy(pTail->SV.MALOP, thuoc_tinh_sv[0][1].c_str());
					strcpy(pTail->SV.MASV, thuoc_tinh_sv[1][1].c_str());
					pTail->SV.NamNH = atoi(thuoc_tinh_sv[2][1].c_str());
					pTail->SV.PHAI = thuoc_tinh_sv[3][1];
					pTail->SV.HO = thuoc_tinh_sv[4][1];
					pTail->SV.TEN = thuoc_tinh_sv[5][1];
					pTail->SV.SODT = thuoc_tinh_sv[6][1];
					break;
				}
			}
			if(yes_no_esc_f1 == 2){
				clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them2 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them2 + 2);
				thuoc_tinh_sv[0][1] = "";
				break;
			}
		}
		return;
	}
	else{
		for(DanhsachSV *k=dssv->NEXT;k!=NULL;k=k->NEXT){
			if (stricmp(k->SV.MASV,masv.c_str())==0){
					tao_khung_them2_or_sua2_SV(1);
					clear_Area(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1, dai_khung_chuc_nang_xoa, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
					tao_khung_them2_or_sua2_SV(1);
				
					thuoc_tinh_sv[1][1] = k->SV.MASV;
					thuoc_tinh_sv[2][1] = chuyen_int_string(k->SV.NamNH);
					thuoc_tinh_sv[3][1] = k->SV.PHAI;
					thuoc_tinh_sv[4][1] = k->SV.HO;
					thuoc_tinh_sv[5][1] = k->SV.TEN;
					thuoc_tinh_sv[6][1] = k->SV.SODT;
					thuoc_tinh_sv[0][1] = k->SV.MALOP;
					int dem = 0;
					for(int i = ngang_chuc_nang_them2 + 2; i < rong_khung_chuc_nang_them2 + 1; i = i + 2){
						gotoxy(doc_chuc_nang_them2 + 1, rong_khung_chuc_nang + rong_khung_chuc_nang_xoa + 4 + i - 1);
						TextColor(noi_bat);
						cout << thuoc_tinh_sv[dem][1];
						TextColor(binh_thuong);
						dem++;
					}
					
					int yes_no_esc_f1;
					while(1){
						nhap_sua2_SV(dssv, pTail, yes_no_esc_f1);
						if(yes_no_esc_f1 == 3){
							xu_li_xac_nhan(2, 2, yes_no_esc_f1);
							if(yes_no_esc_f1 == 0){
								strcpy(k->SV.MALOP, thuoc_tinh_sv[0][1].c_str());
								strcpy(k->SV.MASV, thuoc_tinh_sv[1][1].c_str());
								k->SV.NamNH = atoi(thuoc_tinh_sv[2][1].c_str());
								k->SV.PHAI = thuoc_tinh_sv[3][1];
								k->SV.HO = thuoc_tinh_sv[4][1];
								k->SV.TEN = thuoc_tinh_sv[5][1];
								k->SV.SODT = thuoc_tinh_sv[6][1];
								break;
							}
						}
						if(yes_no_esc_f1 == 2){
							clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them2 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them2 + 2);
							thuoc_tinh_sv[0][1] = "";
							break;
						}
					}
					return;
			}
		}
		gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
		cout << "                                        ";
		gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
		TextColor(noi_bat);
		cout<<"Khong co ma sv nay, enter de tiep tuc!!!";
		getch();
		TextColor(binh_thuong);
		thuoc_tinh_sv[1][1] = "";
	}
}

void xu_li_sua_SV(DanhsachSV *&dssv, DanhsachSV *&pTail, TREE t){
	xuat_Dssv(dssv);
	thuoc_tinh_sv[1][1] = "";
	tao_khung_xoa_or_sua1_SV(1);
	int yes_or_esc_f1;
	while(1){
		nhap_xoa_or_sua1_SV(t, 1, yes_or_esc_f1);
		if(yes_or_esc_f1 == 3){
			Sua_SinhVien(dssv, pTail, thuoc_tinh_sv[1][1]);
			if(thuoc_tinh_sv[1][1].length() != 0){				
				ofstream fileout;
		    	fileout.open("dssv.txt", ios_base::out);
		    	if (fileout.fail() == true){
				   cout << "\nFile cua ban khong ton tai";
				   system("pause");
		        }
				Ghi_file_dssv(dssv, fileout);
				fileout.close();
				clear_Area(dai_khung_chuc_nang + 2, 0, dai_khung_chuc_nang + 2 + dai_khung_danh_sach, rong_khung_danh_sach);
				show_danh_sach(2);
				tao_khung_menu_chuc_nang(2);
				xuat_Dssv(dssv);
				getch();
				clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them2 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them2 + 2);
				break;
			}
		}
		if(yes_or_esc_f1 == 2){
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them2 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them2 + 2);
			break;
		}
	}
}

////////////////////////////////////////
//CHUC NANG 4: IN DANH SACH SV CUA 1 LOP

void xuat_goi_y_chuc_nang_4(DanhsachSV *dssv)
{	
	int row = 0;
	string before = "";
	for(DanhsachSV *k= dssv; k!=NULL; k=k->NEXT )
	{
		if(stricmp(k->SV.MALOP, before.c_str())!=0)
		{
			thuoc_tinh_sv[0][1] = k->SV.MALOP;
			TextColor(noi_bat);
			gotoxy(dai_khung_chuc_nang + 1 + 87 + 8 - thuoc_tinh_sv[0][1].length()/2, 5 + row);
			cout << thuoc_tinh_sv[0][1];
			TextColor(binh_thuong);
			row++;
			before = thuoc_tinh_sv[0][1];
		}
		if(k->NEXT==NULL)
		{
			thuoc_tinh_sv[0][1] = "";
			break;
		}
	} 
}

void xuat_dssv_chuc_nang_4(DanhsachSV *dssv, string malop)
{	
	int row = 2;
	for(DanhsachSV *k= dssv; k!=NULL; k=k->NEXT )
	{
		if(stricmp(k->SV.MALOP, malop.c_str())==0)
		{
			thuoc_tinh_sv[1][1] = k->SV.MASV;
			thuoc_tinh_sv[2][1] = chuyen_int_string(k->SV.NamNH);
			thuoc_tinh_sv[3][1] = k->SV.PHAI;
			thuoc_tinh_sv[4][1] = k->SV.HO;
			thuoc_tinh_sv[5][1] = k->SV.TEN;
			thuoc_tinh_sv[6][1] = k->SV.SODT;
			
			TextColor(noi_bat);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + (do_rong_o2_danh_sach2 - 1 - do_rong_o1_danh_sach2)/2 - thuoc_tinh_sv[1][1].length()/2, ngang2_danh_sach - 1 + row);
			cout << thuoc_tinh_sv[1][1];

			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach2 - do_rong_o1_danh_sach2 + (do_rong_o3_danh_sach2 - 1 - (do_rong_o2_danh_sach2))/2 - thuoc_tinh_sv[2][1].length()/2 + 1, ngang2_danh_sach - 1 + row);
			cout << thuoc_tinh_sv[2][1];
	
			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach2 - do_rong_o1_danh_sach2 + (do_rong_o4_danh_sach2 - 1 - (do_rong_o3_danh_sach2))/2 - thuoc_tinh_sv[3][1].length()/2 + 1, ngang2_danh_sach - 1 + row);
			cout << thuoc_tinh_sv[3][1];

			gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o4_danh_sach2 - do_rong_o1_danh_sach2 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[4][1].length()/2, ngang2_danh_sach - 1 + row);
			cout << thuoc_tinh_sv[4][1];
	
			gotoxy(dai_khung_chuc_nang - 2 + 1 + 1 + do_rong_o4_danh_sach2 - do_rong_o1_danh_sach2 + do_rong_con_lai(2) / 3 * 1 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[5][1].length()/2, ngang2_danh_sach - 1 + row);
			cout << thuoc_tinh_sv[5][1];
	
			gotoxy(dai_khung_chuc_nang - 3 + 1 + 1 + do_rong_o4_danh_sach2 - do_rong_o1_danh_sach2 + do_rong_con_lai(2) / 3 * 2 + (do_rong_con_lai(2) / 3)/2 - thuoc_tinh_sv[6][1].length()/2, ngang2_danh_sach - 1 + row);
			cout << thuoc_tinh_sv[6][1];
			TextColor(binh_thuong);
			row++;
		}
		if(k->NEXT==NULL)
		{
			break;
		}
		if(stricmp(k->SV.MALOP, malop.c_str())==0&&stricmp(k->NEXT->SV.MALOP, malop.c_str())!=0)	
		break;
	} 
}

void tao_khung_chuc_nang_4(){
//	system(ma_system);
	TextColor(noi_bat);
	gotoxy(dai_khung_chuc_nang_xoa / 2 - 16, ngang_chuc_nang_xoa - 2);
	cout << "IN DANH SACH SINH VIEN CUA 1 LOP";
	gotoxy(1, 5);
	TextColor(hien_thanh_sang);
	cout << "MA LOP MUON IN DANH SACH";
	TextColor(binh_thuong);
	
	for (int i = 1; i < dai_khung_chuc_nang_xoa - 1; i++){
		gotoxy(i, ngang_chuc_nang_xoa);
		cout << char(khung_ngoai);
	}
	gotoxy(0,0);
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	cout << endl;
	
	for (int i = 1; i < rong_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
		if(i > ngang_chuc_nang_xoa){
			gotoxy(doc_chuc_nang_xoa + 9, i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang_xoa - 1, i);
		cout << char(khung_ngoai) <<endl;
	}
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	gotoxy(1, 5);
}

void xu_li_in_dsach_sv_lop(DanhsachSV *dssv, DanhsachSV *pTail)
{
//	tao_khung_xoa_or_sua1_SV(0);
//	xuat_Dssv(dssv);
	gotoxy(1, rong_khung_chuc_nang_xoa + 1);
	TextColor(binh_thuong);
	cout << "                                          ";
	gotoxy(0, rong_khung_chuc_nang_xoa + 1);
	cout << char(khung_ngoai);
	gotoxy(dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang_xoa + 1);
	cout << char(khung_ngoai) << endl;
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}

	thuoc_tinh_sv[0][1] = "";
	char phim;
	while (1){
		gotoxy(doc_chuc_nang_xoa + 1 + 9, ngang_chuc_nang_xoa + 1);
		nhap_tung_ki_tu(thuoc_tinh_sv[0][1], phim, 0, 3, 5);
	
		gotoxy(1, rong_khung_chuc_nang_xoa + 1);
		TextColor(binh_thuong);
		cout << "                                          ";
	
		if(thuoc_tinh_sv[0][1].length() == 0){
			gotoxy(1, rong_khung_chuc_nang_xoa + 1);
			TextColor(noi_bat);
			cout << "                                ";
			gotoxy(1, rong_khung_chuc_nang_xoa + 1);
			cout << "ESC de thoat hoac nhap lai";
			TextColor(binh_thuong);
		}
		else{
			bool ktra = kt_malop_trung(dssv, pTail, thuoc_tinh_sv[0][1]);
			if(ktra == false){
				gotoxy(1, rong_khung_chuc_nang_xoa + 1);
				TextColor(noi_bat);
				cout << "                                ";
				gotoxy(1, rong_khung_chuc_nang_xoa + 1);
				cout << "KHONG TIM THAY MA LOP NAY!!!";
				TextColor(binh_thuong);
			}
			else{
				clear_Area(dai_khung_chuc_nang + 1, 0, 84 + dai_khung_chuc_nang + 1, rong_khung_danh_sach);
				show_danh_sach(3);
				xuat_dssv_chuc_nang_4(dssv, thuoc_tinh_sv[0][1]);
			}
		}
//		phim = getch();
		if(phim == esc){
			clrscr();
			Tao_khung_menu_main();
			break;
		}
	}
}

///////////////////////////////
//CHUC NANG 5: CAP NHAT MON HOC
void Nhap_mon_hoc(MonHoc *&monhoc)
{
	strcpy(monhoc->MAMH, thuoc_tinh_mon_hoc[0][1].c_str());
	monhoc->TENMH = thuoc_tinh_mon_hoc[1][1];
	monhoc->STCLT = atof(thuoc_tinh_mon_hoc[2][1].c_str());
	monhoc->STCTH = atof(thuoc_tinh_mon_hoc[3][1].c_str());
}

int kt_tenmh_trung(DsMonHoc dsmh, string tenmh) {
  for (int i =0; i < dsmh.n ; i++)
  if (stricmp(dsmh.Ds[i]->TENMH.c_str(), tenmh.c_str())==0) return i;
  return -1;
}

int kt_sua_tenmh_trung(DsMonHoc dsmh, string tenmh, string mamh) {
  for (int i =0; i < dsmh.n ; i++)
  if (stricmp(dsmh.Ds[i]->TENMH.c_str(), tenmh.c_str())==0){
  	if (stricmp(dsmh.Ds[i]->MAMH, mamh.c_str())!=0){
  		return i;
	  }
  }
  return -1;
}

void xuat_mon_hoc(DsMonHoc dsmh)
{
	int row = 2;
	for(int i=0;i<dsmh.n;i++){
//		cout<<dsmh.Ds[i]->MAMH<<" "<<dsmh.Ds[i]->TENMH<<" "<<dsmh.Ds[i]->STCLT<<" "<<dsmh.Ds[i]->STCTH<<endl;
		
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 1 + (do_rong_o1_danh_sach4 - 1)/2 - strlen(dsmh.Ds[i]->MAMH)/2, ngang2_danh_sach - 1 + row);
		cout << dsmh.Ds[i]->MAMH;

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o1_danh_sach4 + (do_rong_o2_danh_sach4 - 1 - do_rong_o1_danh_sach4)/2 - dsmh.Ds[i]->TENMH.length()/2, ngang2_danh_sach - 1 + row);
		cout << dsmh.Ds[i]->TENMH;

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o2_danh_sach4 + (do_rong_o3_danh_sach4 - 1 - (do_rong_o2_danh_sach4))/2 - 2 + 1, ngang2_danh_sach - 1 + row);
		cout << dsmh.Ds[i]->STCLT;

		gotoxy(dai_khung_chuc_nang + 1 + 1 + do_rong_o3_danh_sach4 + (do_rong_o4_danh_sach4 - 1 - (do_rong_o3_danh_sach4))/2 - 2 + 1, ngang2_danh_sach - 1 + row);
		cout << dsmh.Ds[i]->STCTH;
		TextColor(binh_thuong);
		row++;
	}
}
void Doc_file_MonHoc(ifstream &filein,MonHoc *&mh){
	char x;
	filein>>mh->STCLT;filein>>x;
	filein>>mh->STCTH;filein>>x;
	getline(filein,mh->TENMH,',');
	filein>>mh->MAMH;
}
void Doc_file_dsmh(ifstream &filelin,DsMonHoc &dsmh){
	while(!filelin.eof()){
		if(dsmh.n==MAXLIST){
			cout<<"danh sach day";break;
		}
		dsmh.Ds[dsmh.n]=new MonHoc;
		Doc_file_MonHoc(filelin,dsmh.Ds[dsmh.n]);
		filelin.ignore();
		dsmh.n++;
	}
}
void Ghi_file_dsmh(ofstream &fileout,DsMonHoc dsmh){
	for(int i=0;i<dsmh.n;i++){
		fileout<<endl<<dsmh.Ds[i]->STCLT<<","<<dsmh.Ds[i]->STCTH<<","<<dsmh.Ds[i]->TENMH<<","<<dsmh.Ds[i]->MAMH;
	}
}

void tao_khung_them_or_sua2_MH(int them_or_sua2){	
	int khoang_cach_voi_khung_chuc_nang = 2; //khoang cach voi khung chuc nang la 2
	
	if(them_or_sua2 == 1){
		khoang_cach_voi_khung_chuc_nang = 4 + rong_khung_chuc_nang_xoa;
	}
	
	TextColor(noi_bat);
	if(them_or_sua2 == 0){
		gotoxy(dai_khung_chuc_nang_them0 / 2 - 6, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them4 - 2);
		cout << "THEM MON HOC";
	}
	else if(them_or_sua2 == 1){
		gotoxy(dai_khung_chuc_nang_them0 / 2 - 8, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them4 - 2);
		cout << "THONG TIN MON HOC";
	}
	TextColor(binh_thuong);
	
	for (int i = 1; i < dai_khung_chuc_nang_them4 - 1; i++){
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them4);
		cout << char(khung_ngoai);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them4 + 2);
		cout << char(khung_trong_them);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them4 + 2 + 2);
		cout << char(khung_trong_them);
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + ngang_chuc_nang_them4 + 2 + 4);
		cout << char(khung_trong_them);
	}
	gotoxy(0,rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang);
	for (int i = 0; i < dai_khung_chuc_nang_them4; i++){
		cout << char(khung_ngoai);
	}
	cout << endl;
	
	for (int i = 1; i < rong_khung_chuc_nang_them4; i++){
		cout << char(khung_ngoai);
		if(i > ngang_chuc_nang_them4){
			gotoxy(doc_chuc_nang_them4, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang_them4 - 1, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + i);
		cout << char(khung_ngoai) <<endl;
	}
	for (int i = 0; i < dai_khung_chuc_nang_them4; i++){
		cout << char(khung_ngoai);
	}
	int dem = 0;
	for(int i = ngang_chuc_nang_them4 + 2; i < rong_khung_chuc_nang_them4 + 1; i = i + 2){
		gotoxy(1, rong_khung_chuc_nang + khoang_cach_voi_khung_chuc_nang + i - 1);
		if (dem == 0 && them_or_sua2 == 0){
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[dem][0], doc_chuc_nang_them4 - 1);
			dem++;
			TextColor(binh_thuong);
		}
		else if (dem == 1 && them_or_sua2 == 1){
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[dem][0], doc_chuc_nang_them4 - 1);
			dem++;
			TextColor(binh_thuong);
		}
		else{
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[dem][0], doc_chuc_nang_them4 - 1);
			dem++;
			TextColor(binh_thuong);
		}
	}
	
	gotoxy(1, rong_khung_chuc_nang + 3 + khoang_cach_voi_khung_chuc_nang);
}

void xu_li_them_MH(DsMonHoc &dsmh, int &xac_nhan_tra_ve){
	char key_chuc_nang_them;
	int chon_thuoc_tinh = 0;
	
	int so_thuoc_tinh = 4;
	
	for(int i = 0; i < so_thuoc_tinh; i++){
		thuoc_tinh_mon_hoc[i][1] = "";
	}
	
	gotoxy(doc_chuc_nang_them4, rong_khung_chuc_nang + 2 + 7);
	
	while (1){
		 int ktra;
		int xac_nhan_du = so_thuoc_tinh - 1;
		
		for (int i = 1; i < so_thuoc_tinh; i++){
			if(thuoc_tinh_mon_hoc[i][1].length() != 0){
				xac_nhan_du = xac_nhan_du - 1;
			}
		}
		
		if(xac_nhan_du == 0){
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1);
			TextColor(binh_thuong);
			cout << "                                       ";
			TextColor(binh_thuong);
			gotoxy(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang_them4 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1);
			cout << char(khung_ngoai) << endl;
			for (int i = 0; i < dai_khung_chuc_nang_them4; i++){
				cout << char(khung_ngoai);
			}

			ktra=kt_mamh_trung(dsmh, thuoc_tinh_mon_hoc[0][1]);
			ktra=kt_tenmh_trung(dsmh, thuoc_tinh_mon_hoc[1][1]);
			
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1);
			TextColor(noi_bat);
			if(ktra == -1){
				cout << "BAM F1 DE THEM!!!";
			}
			else{
				cout << "TRUNG THUOC TINH!";
			}
			TextColor(binh_thuong);
		}
		else{
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1);
			TextColor(binh_thuong);
			cout << "                 ";
		}

		gotoxy(1 + doc_chuc_nang_them4, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1);
		
		nhap_tung_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][1], key_chuc_nang_them, chon_thuoc_tinh, 4 , 0);
		
		if(key_chuc_nang_them == mui_ten_len){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
			if(chon_thuoc_tinh == 0){
				chon_thuoc_tinh = 3;
			}
			else{
				chon_thuoc_tinh = chon_thuoc_tinh - 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
		}
		else if(key_chuc_nang_them == mui_ten_xuong){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1){
				chon_thuoc_tinh = 0;
			}	
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
		}
		else if(key_chuc_nang_them == enter){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1){
				chon_thuoc_tinh = 0;
			}	
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
		}
		else if(key_chuc_nang_them == esc){
			gotoxy(0,0);
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them4 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 2);
			system(ma_system);
			tao_khung_menu_chuc_nang(4);
			show_danh_sach(4);
			xac_nhan_tra_ve = 2;
			break;
		}
		else if((key_chuc_nang_them == F1) && (xac_nhan_du == 0) && (ktra == -1)){
			//vao them ltc
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 - 1);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[0][0],doc_chuc_nang_them4 - 1);
			
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1);
			TextColor(binh_thuong);
			cout << "                    ";
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1);
			TextColor(noi_bat);
			cout << "XAC NHAN THEM";
			TextColor(binh_thuong);
			xac_nhan_tra_ve = 3;
			break;
		}
		
	}
}

void Them_mon_hoc(DsMonHoc &dsmh)
{
	if(dsmh.n==MAXLIST) {
		cout<<"danh sach day"; return;
	}
	
	for(int i = 1; i < 7; i++){
		thuoc_tinh_LTC[i][1] = "";
	}
	
	tao_khung_them_or_sua2_MH(0);
	int yes_no_esc_f1 = 2;
	while (1){
		xu_li_them_MH(dsmh, yes_no_esc_f1);
		if(yes_no_esc_f1 == 3){
			xu_li_xac_nhan(0, 4, yes_no_esc_f1);
			if(yes_no_esc_f1 == 0){
				dsmh.Ds[dsmh.n] = new MonHoc;
				
				Nhap_mon_hoc(dsmh.Ds[dsmh.n]);
				dsmh.n++;

				ofstream fileout;
		    	fileout.open("dsmh.txt", ios_base::out);
		    	if (fileout.fail() == true){
				   cout << "\nFile cua ban khong ton tai";
				   system("pause");
		        }
				Ghi_file_dsmh(fileout, dsmh);
				fileout.close();
				tao_khung_menu_chuc_nang(4);
				xuat_mon_hoc(dsmh);
				getch();
				clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 2);
				break;
			}	
		}
		if(yes_no_esc_f1 == 2){
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them0 + 2);
			break;
		}
	}
}
void Xoa_mon_hoc(DsMonHoc &dsmh)
{
	string mamh;
	mamh = thuoc_tinh_mon_hoc[0][1];
    int i = kt_mamh_trung(dsmh,mamh);
    if (i==-1){
    	thuoc_tinh_mon_hoc[0][1] = "";
    	gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
		cout << "                                        ";
		gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
		TextColor(noi_bat);
    	cout<<"Ma mon hoc ko ton tai, nhap lai";
    	getch();
    	TextColor(binh_thuong);
	}
    else  
    { delete  dsmh.Ds[i];
       for (int j=i+1; j <dsmh.n; j++)
       dsmh.Ds[j-1]=dsmh.Ds[j];  
       dsmh.n--;  
	}
}

void kt_mamh_ben_loptc(TREE t,string mamh,bool &kt){
	if(t!=NULL){
		if(stricmp(t->LopTC.MAMH,mamh.c_str())==0){
			kt=true;return;
		}
		kt_mamh_ben_loptc(t->pLeft,mamh,kt);
		kt_mamh_ben_loptc(t->pRight,mamh,kt);
	}	
}

void tao_khung_xoa_or_sua1_MH(int xoa_or_sua1){
//	system(ma_system);
	int khoang_cach_voi_khung_phia_tren = 2; //khoang cach voi khung chuc nang la 2
	
	string s = "XOA";
	if(xoa_or_sua1 == 1){
		s = "HIEU CHINH";
	}
	TextColor(noi_bat);
	gotoxy(dai_khung_chuc_nang_xoa / 2 - (s.length() + 8)/2, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + ngang_chuc_nang_xoa - 2);
	cout << s << " 1 MON HOC";
	gotoxy(1, rong_khung_chuc_nang + 5 + khoang_cach_voi_khung_phia_tren);
	TextColor(hien_thanh_sang);
	cout << "MA MH MUON " << s + " ";
	TextColor(binh_thuong);
	
	for (int i = 1; i < dai_khung_chuc_nang_xoa - 1; i++){
		gotoxy(i, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + ngang_chuc_nang_xoa);
		cout << char(khung_ngoai);
	}
	gotoxy(0,rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren);
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	cout << endl;
	
	for (int i = 1; i < rong_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
		if(i > ngang_chuc_nang_xoa){
			if(xoa_or_sua1 == 1){
				gotoxy(doc_chuc_nang_xoa + 7, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + i);
			}
			else{
				gotoxy(doc_chuc_nang_xoa, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + i);
			}
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + khoang_cach_voi_khung_phia_tren + i);
		cout << char(khung_ngoai) <<endl;
	}
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	gotoxy(1, rong_khung_chuc_nang + 5 + khoang_cach_voi_khung_phia_tren);
}

void nhap_xoa_or_sua1_MH(TREE t, int xoa_or_sua1, int &dk_tra_ve){
	char phim;
	
	gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
	TextColor(binh_thuong);
	cout << "                                          ";
	TextColor(binh_thuong);
	gotoxy(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
	cout << char(khung_ngoai);
	gotoxy(dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
	cout << char(khung_ngoai) << endl;
	for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
		cout << char(khung_ngoai);
	}
	
//	gotoxy(0,0);
//	cout << chuc_nang_duoc_chon;
	while (1){
		if(xoa_or_sua1 == 0){
			gotoxy(doc_chuc_nang_xoa + 1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_xoa + 1);
			nhap_tung_ki_tu(thuoc_tinh_mon_hoc[0][1], phim, 0, 4, 1);
		}
		else if(xoa_or_sua1 == 1){
			gotoxy(doc_chuc_nang_xoa + 8, rong_khung_chuc_nang + 2 + ngang_chuc_nang_xoa + 1);
			nhap_tung_ki_tu(thuoc_tinh_mon_hoc[0][1], phim, 0, 4, 2);
		}
		
		if(thuoc_tinh_mon_hoc[0][1].length() == 0){
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
			TextColor(noi_bat);
			cout << "                                           ";
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
			cout << "ESC de thoat hoac nhap lai";
			TextColor(binh_thuong);
		}
		else{
			TextColor(noi_bat);
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
			cout << "                                          ";
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
			if(xoa_or_sua1 == 0){
				cout << "BAM F1 DE XOA!!!";
			}
			else if(xoa_or_sua1 == 1){
				cout << "BAM F1 DE HIEU CHINH!!!";
			}
			TextColor(binh_thuong);
		}
//		phim = getch();
		if(phim == esc){
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
			dk_tra_ve = 2;
			break;
		}
		if(phim == F1){
			dk_tra_ve = 3;
			
			if(xoa_or_sua1 == 0){
				bool ktra = false;
				kt_mamh_ben_loptc(t, thuoc_tinh_mon_hoc[0][1], ktra);
				if(ktra == true){
					gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
					TextColor(noi_bat);
					cout << "MH DA CO TRONG LTC, KHONG DUOC XOA!!!";
					TextColor(binh_thuong);
				}
				else{
					gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
					TextColor(binh_thuong);
					cout << "                                       ";
					gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
					TextColor(noi_bat);
					cout << "XAC NHAN XOA";
					TextColor(binh_thuong);
					break;
				}
			}
			if(xoa_or_sua1 == 1){
				break;
			}
		}
	}
}

void xu_li_xoa_MH(DsMonHoc &dsmh, TREE t)
{
	thuoc_tinh_mon_hoc[0][1] = "";
	tao_khung_xoa_or_sua1_MH(0);
	int yes_or_esc_f1;
	while(1){
		nhap_xoa_or_sua1_MH(t, 0, yes_or_esc_f1);
		if(yes_or_esc_f1 == 3){
			xu_li_xac_nhan(1, 4, yes_or_esc_f1);
			if(yes_or_esc_f1 == 0){
				Xoa_mon_hoc(dsmh);
				if(thuoc_tinh_mon_hoc[0][1].length() != 0){
					ofstream fileout;
					fileout.open("dsmh.txt", ios_base::out);
					Ghi_file_dsmh(fileout, dsmh);
					fileout.close();
					
					clear_Area(dai_khung_chuc_nang + 2, 0, dai_khung_chuc_nang + 2 + dai_khung_danh_sach, rong_khung_danh_sach);
					show_danh_sach(4);
					xuat_mon_hoc(dsmh);
					getch();
					clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
					break;
				}
			}
		}
		if(yes_or_esc_f1 == 2){
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_xoa - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2);
			break;
		}
	}
}

void nhap_sua2_MH(DsMonHoc &dsmh, int &xac_nhan_tra_ve){
	char key_chuc_nang_them;
	int chon_thuoc_tinh = 1;
	
	int so_thuoc_tinh = 4;
	
	gotoxy(doc_chuc_nang_them4, rong_khung_chuc_nang + 2 + 7 + rong_khung_chuc_nang_xoa + 2);
	while (1){
		int ktra;
		int xac_nhan_du = so_thuoc_tinh - 1;
		
		for (int i = 1; i < so_thuoc_tinh; i++){
			if(thuoc_tinh_mon_hoc[i][1].length() != 0){
				xac_nhan_du = xac_nhan_du - 1;
			}
		}
		
		if(xac_nhan_du == 0){
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(binh_thuong);
			cout << "                                       ";
			TextColor(binh_thuong);
			gotoxy(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1 + rong_khung_chuc_nang_xoa + 2);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang_them4 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1 + rong_khung_chuc_nang_xoa + 2);
			cout << char(khung_ngoai) << endl;
			for (int i = 0; i < dai_khung_chuc_nang_them4; i++){
				cout << char(khung_ngoai);
			}
			ktra = kt_sua_tenmh_trung(dsmh, thuoc_tinh_mon_hoc[1][1], thuoc_tinh_mon_hoc[0][1]);
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(noi_bat);
			if(ktra == -1){
				cout << "BAM F1 DE HIEU CHINH!!!";
			}
			else{
				cout << "TRUNG THUOC TINH!";
			}
			TextColor(binh_thuong);
		}
		else{
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(binh_thuong);
			cout << "                              ";
		}

		gotoxy(1 + doc_chuc_nang_them4, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
		
		nhap_tung_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][1], key_chuc_nang_them, chon_thuoc_tinh, 4, 3);
		
		if(key_chuc_nang_them == mui_ten_len){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
			if(chon_thuoc_tinh == 1){
				chon_thuoc_tinh = (chon_thuoc_tinh - 1 - 1 + (so_thuoc_tinh + 1)) % (so_thuoc_tinh + 1) - 1;
			}
			else{
				chon_thuoc_tinh = chon_thuoc_tinh - 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
		}
		else if(key_chuc_nang_them == mui_ten_xuong){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1){
				chon_thuoc_tinh = 1;
			}	
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
		}
		else if(key_chuc_nang_them == enter){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1){
				chon_thuoc_tinh = 1;
			}	
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
		}
		else if(key_chuc_nang_them == esc){
			gotoxy(0,0);
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them4 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them4 + 2);
			system(ma_system);
			tao_khung_menu_chuc_nang(4);
			show_danh_sach(4);
			xac_nhan_tra_ve = 2;
			break;
		}
		else if((key_chuc_nang_them == F1) && (xac_nhan_du == 0) && (ktra == -1)){
			//vao them ltc
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + chon_thuoc_tinh * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(an_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[chon_thuoc_tinh][0],doc_chuc_nang_them4 - 1);
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them4 + 2 + 1 * 2 - 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(hien_thanh_sang);
			cout << chuoi_voi_n_ki_tu(thuoc_tinh_mon_hoc[1][0],doc_chuc_nang_them4 - 1);
			
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(binh_thuong);
			cout << "                                ";
			gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 1 + rong_khung_chuc_nang_xoa + 2);
			TextColor(noi_bat);
			cout << "XAC NHAN HIEU CHINH";
			TextColor(binh_thuong);
			xac_nhan_tra_ve = 3;
			break;
		}
		
	}
}

void Sua_mon_hoc(DsMonHoc &dsmh)
{
	string mamh = thuoc_tinh_mon_hoc[0][1];
    int i = kt_mamh_trung(dsmh,mamh);
    if (i==-1){
    	thuoc_tinh_mon_hoc[0][1] = " ";
    	gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
		cout << "                                        ";
		gotoxy(1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1);
		TextColor(noi_bat);
    	cout<<"Ma mon hoc ko ton tai, enter de tiem tuc";
    	getch();
    	TextColor(binh_thuong);
	}
    else
    {
    	clear_Area(0, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 1, dai_khung_chuc_nang_xoa, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_them4 + 2);
		tao_khung_them_or_sua2_MH(1);
		
		thuoc_tinh_mon_hoc[0][1] = dsmh.Ds[i]->MAMH;
		thuoc_tinh_mon_hoc[1][1] = dsmh.Ds[i]->TENMH;
		thuoc_tinh_mon_hoc[2][1] = chuyen_float_string(dsmh.Ds[i]->STCLT);
		thuoc_tinh_mon_hoc[3][1] = chuyen_float_string(dsmh.Ds[i]->STCTH);
		
		int dem = 0;
		for(int i = ngang_chuc_nang_them4 + 2; i < rong_khung_chuc_nang_them4 + 1; i = i + 2){
			gotoxy(doc_chuc_nang_them4 + 1, rong_khung_chuc_nang + rong_khung_chuc_nang_xoa + 4 + i - 1);
			TextColor(noi_bat);
			cout << thuoc_tinh_mon_hoc[dem][1];
			TextColor(binh_thuong);
			dem++;
		}
		
		int yes_no_esc_f1;
		while(1){
			nhap_sua2_MH(dsmh, yes_no_esc_f1);
			if(yes_no_esc_f1 == 3){
				xu_li_xac_nhan(2, 4, yes_no_esc_f1);
				if(yes_no_esc_f1 == 0){
					MonHoc *monhoc=dsmh.Ds[i];
				   	Nhap_mon_hoc(monhoc);
					break;
				}
			}
			if(yes_no_esc_f1 == 2){
				clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them4 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them4 + 2);
				thuoc_tinh_mon_hoc[0][1] = "";
				break;
			}
		}
	}
}

void xu_li_sua_MH(DsMonHoc &dsmh, TREE t){
	thuoc_tinh_mon_hoc[0][1] = "";
	tao_khung_xoa_or_sua1_MH(1);
	int yes_or_esc_f1;
	while(1){
		nhap_xoa_or_sua1_MH(t, 1, yes_or_esc_f1);
		if(yes_or_esc_f1 == 3){
			Sua_mon_hoc(dsmh);
			if(thuoc_tinh_mon_hoc[0][1] == " "){
			}
			else if(thuoc_tinh_mon_hoc[0][1].length() != 0){				
				ofstream fileout;
		    	fileout.open("dsmh.txt", ios_base::out);
		    	if (fileout.fail() == true){
				   cout << "\nFile cua ban khong ton tai";
				   system("pause");
		        }
				Ghi_file_dsmh(fileout, dsmh);
				fileout.close();
				clear_Area(dai_khung_chuc_nang + 2, 0, dai_khung_chuc_nang + 2 + dai_khung_danh_sach, rong_khung_danh_sach);
				show_danh_sach(4);
				xuat_mon_hoc(dsmh);
				getch();
				clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them0 + 2);
				break;
			}
			else{
				yes_or_esc_f1 = 2;
			}
		}
		if(yes_or_esc_f1 == 2){
			clear_Area(0, rong_khung_chuc_nang + 2, dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang + 2 + rong_khung_chuc_nang_xoa + 2 + rong_khung_chuc_nang_them0 + 2);
			break;
		}
	}
	tao_khung_menu_chuc_nang(4);
}

/////////////////////////////////////
//CHUC NANG 6: XUAT DANH SACH MON HOC
void cau_f(DsMonHoc dsmh)
{
	MonHoc *tg;
    for(int i = 0; i < dsmh.n - 1; i++){
        for(int j = i + 1; j < dsmh.n; j++){
            if(stricmp(dsmh.Ds[i]->TENMH.c_str(),dsmh.Ds[j]->TENMH.c_str())>0){
                tg = dsmh.Ds[i];
                dsmh.Ds[i] = dsmh.Ds[j];
                dsmh.Ds[j] = tg;  
            }
        }
    }
    xuat_mon_hoc(dsmh);
}

/////////////////////////
//CHUC NANG 7: NHAP DIEM
void nhap_gtri_diem(string &chuoi_cua_o, char &phim_tra_ve_khi_out, int hang_tra_ve){
	int dau_tien = 1;
	string xoa = "";
	xoa = chuoi_voi_n_ki_tu(xoa, 4);
//	gotoxy(dai_khung_chuc_nang + 1 + 51, hang_tra_ve + 8);
//	cout << xoa;
	char key_nhap;
	while (1){
		key_nhap = getch();
		if((key_nhap == -32) || ((key_nhap == 0))){
			//truong hop la cac phim mui ten
			key_nhap = getch();
			if((key_nhap == mui_ten_len) || (key_nhap == mui_ten_xuong) || (key_nhap == F1)){
				phim_tra_ve_khi_out = key_nhap;
				rang_buoc_chuoi(chuoi_cua_o, key_nhap, khoang_trang_cuoi);
				TextColor(binh_thuong);
				gotoxy(dai_khung_chuc_nang + 1 + 51, 8 + hang_tra_ve);
				cout << xoa;
				TextColor(noi_bat);
				gotoxy(dai_khung_chuc_nang + 1 + 51, 8 + hang_tra_ve);
				cout << chuoi_cua_o;
				TextColor(binh_thuong);
				break;
			}
		}
		else{
			if((key_nhap == enter) || (key_nhap == esc)){
				phim_tra_ve_khi_out = key_nhap;
				rang_buoc_chuoi(chuoi_cua_o, key_nhap, khoang_trang_cuoi);
				TextColor(binh_thuong);
				gotoxy(dai_khung_chuc_nang + 1 + 51, 8 + hang_tra_ve);
				cout << xoa;
				TextColor(noi_bat);
				gotoxy(dai_khung_chuc_nang + 1 + 51, 8 + hang_tra_ve);
				cout << chuoi_cua_o;
				TextColor(binh_thuong);
				break;
			}	
			else if(key_nhap == backspace){
				chuoi_cua_o = chuoi_cua_o.substr(0, chuoi_cua_o.length() - 1);
			}
			else{
				if(dau_tien == 1){
					chuoi_cua_o = "";
					dau_tien = 0;
				}
				string chuoi_tam = chuoi_cua_o + char(key_nhap);
				if(chuoi_cua_o.length() <= 2 && atof(chuoi_tam.c_str()) <= 10){
					rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so_thap_phan);
				}
			}
			TextColor(binh_thuong);
			gotoxy(dai_khung_chuc_nang + 1 + 51, 8 + hang_tra_ve);
			cout << xoa;
			TextColor(noi_bat);
			gotoxy(dai_khung_chuc_nang + 1 + 51, 8 + hang_tra_ve);
			cout << chuoi_cua_o;
			TextColor(binh_thuong);
		}
	}
}

void xu_li_nhap_diem2(int &row, string &diem){
	char phim;
	string tam = diem;
	nhap_gtri_diem(diem, phim, row);
//	cin_diem(string, row);
//	phim = getch();
	if(diem.length() == 0){
		TextColor(noi_bat);
		cout << tam;
		TextColor(binh_thuong);
	}
	if(phim == mui_ten_xuong){
		row = row + 1;
	}
	else if((phim == mui_ten_len) && (row > 0)){
		row = row - 1;
	}
	else if(phim == enter){
		row++;
	}
	else if(phim == esc){
		row = -1;
		gotoxy(doc_chuc_nang_them0 + 1, 5);
		cout << "                                               ";
		gotoxy(doc_chuc_nang_them0 + 1, 7);
		cout << "                                               ";
		gotoxy(doc_chuc_nang_them0 + 1, 9);
		cout << "                                               ";
		gotoxy(doc_chuc_nang_them0 + 1, 11);
		cout << "                                               ";
		
		thuoc_tinh_LTC[1][1] = "";
		thuoc_tinh_LTC[2][1] = "";
		thuoc_tinh_LTC[3][1] = "";
		thuoc_tinh_LTC[6][1] = "";
	}
	gotoxy(dai_khung_chuc_nang + 1 + 51, row + 8);
}

void Sua_diem(SVdangky *&sv){
	string diem;
	diem = chuyen_float_string(sv->Diem);
	int row = 0;
	gotoxy(dai_khung_chuc_nang + 1 + 51, row + 8);
	SVdangky *s = sv;

	while(1){
//		gotoxy(0,0);
//		cout << s->MASV;
		xu_li_nhap_diem2(row, diem);
		if(diem.length() != 0){
			s->Diem = atof(diem.c_str());
		}
		if(row == -1){
			delete(s);
			break;
		}
		else {
			s = sv;
			int tam = row;
			while(tam > 0){
//				if(tam == 1){
//					cout << " " << s->Diem;
//				}
				if(s->next == NULL){
					tam = row = 0;
					s = sv;
					gotoxy(dai_khung_chuc_nang + 1 + 51, row + 8);
				}
				else{
					s = s->next;
					tam--;
				}
			}
			diem = chuyen_float_string(s->Diem);
		}
	}
}
void xuat_thong_tin_sv_va_diem(SVdangky *sv,DanhsachSV *dssv,DanhsachSV *pTail){
	int row = 0;
	for(SVdangky *s=sv; s!=NULL;s=s->next){
		DanhsachSV *k=kt_masv_trung(dssv,pTail,s->MASV);
		
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 3 - 1 - chuyen_int_string(row + 1).length()/2, ngang1_danh_sach + 1 + 3 + row + 2);
		cout << row + 1;
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 8 - strlen(s->MASV)/2, ngang1_danh_sach + 1 + 3 + row + 2);
		cout << s->MASV;
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 7 - k->SV.HO.length()/2, ngang1_danh_sach + 1 + 3 + row + 2);
		cout << k->SV.HO;
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 7 - k->SV.TEN.length()/2, ngang1_danh_sach + 1 + 3 + row + 2);
		cout << k->SV.TEN;
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 14 + 3 - 1, ngang1_danh_sach + 1 + 3 + row + 2);
		cout << s->Diem;
		row++;
	}
}

void xuat_bang_diem_mh_loptc(TREE t,string nk,string mamh,int hk,int nhom,bool &kt,DanhsachSV *dssv,DanhsachSV *pTail,DsMonHoc dsmh){
	if(t!=NULL){
		if(stricmp(nk.c_str(),t->LopTC.NienKhoa.c_str())==0){
			if(t->LopTC.HK==hk){
				if(t->LopTC.Nhom==nhom){
					if(stricmp(t->LopTC.MAMH,mamh.c_str())==0){
						TextColor(noi_bat);
						int i=kt_mamh_trung(dsmh,mamh);
						gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - 14 + 18, 0);
						cout << "           ";
						gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - 9 - dsmh.Ds[i]->TENMH.length()/2, 0);
						cout << "BANG DIEM MON HOC " << dsmh.Ds[i]->TENMH;
						gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - 27 + 11, 1);
						cout << nk;
						gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - 27 + 11 + 9 + 5 + 8 + 5 + 5 + 6, 1);
						cout << "     ";
						gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - 27 + 11 + 9 + 5 + 8, 1);
						cout << "     ";
						gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - 27 + 11 + 9 + 5 + 8, 1);
						cout << hk;
						gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - 27 + 11 + 9 + 5 + 8 + 5 + 5 + 6, 1);
						cout << nhom;
						TextColor(binh_thuong);
						xuat_thong_tin_sv_va_diem(t->Dsdk,dssv,pTail);
                        kt=true;
                        return;
					}
				}
			}
		}
		xuat_bang_diem_mh_loptc(t->pLeft,nk,mamh,hk,nhom,kt,dssv,pTail,dsmh);
		xuat_bang_diem_mh_loptc(t->pRight,nk,mamh,hk,nhom,kt,dssv,pTail,dsmh);
	}
}

void nhap_bang_diem_mh_loptc(TREE t,string nk,string mamh,int hk,int nhom,bool &kt, DanhsachSV *dssv,DanhsachSV *pTail,DsMonHoc dsmh){
	if(t!=NULL){
		if(stricmp(nk.c_str(),t->LopTC.NienKhoa.c_str())==0){
			if(t->LopTC.HK==hk){
				if(t->LopTC.Nhom==nhom){
					if(stricmp(t->LopTC.MAMH,mamh.c_str())==0){
						xuat_bang_diem_mh_loptc(t, thuoc_tinh_LTC[2][1], thuoc_tinh_LTC[1][1], atoi(thuoc_tinh_LTC[3][1].c_str()), atoi(thuoc_tinh_LTC[6][1].c_str()), kt, dssv, pTail, dsmh);
						Sua_diem(t->Dsdk);
                        kt=true;
                        return;
					}
				}
			}
		}
		nhap_bang_diem_mh_loptc(t->pLeft,nk,mamh,hk,nhom,kt, dssv, pTail, dsmh);
		nhap_bang_diem_mh_loptc(t->pRight,nk,mamh,hk,nhom,kt, dssv, pTail, dsmh);
	}
}

void ghi_dsdk(SVdangky *sv,ofstream &fileout){
	for(SVdangky *k=sv;k!=NULL;k=k->next){
		fileout<<","<<k->Diem<<","<<k->MASV<<endl;
	}
}
void ghi_het_dsdk(TREE t,ofstream &fileout){
	if(t!=NULL){
		if(t->Dsdk!=NULL){
			fileout<<endl<<t->LopTC.MALOPTC<<endl;
			ghi_dsdk(t->Dsdk,fileout);
			fileout<<".";
		}
		ghi_het_dsdk(t->pLeft,fileout);
		ghi_het_dsdk(t->pRight,fileout);
	}
}

void cau_i(TREE t, DsMonHoc dsmh, DanhsachSV *dssv, DanhsachSV *pTail){
	bool kt = false;
	nhap_bang_diem_mh_loptc(t, thuoc_tinh_LTC[2][1], thuoc_tinh_LTC[1][1], atoi(thuoc_tinh_LTC[3][1].c_str()), atoi(thuoc_tinh_LTC[6][1].c_str()), kt, dssv, pTail, dsmh);
	if(kt == true){
		ofstream fileout;
   		fileout.open("dsdk.txt", ios_base::out);
		ghi_het_dsdk(t,fileout);
		fileout.close();
	}
	else{
		gotoxy(1, rong_khung_chuc_nang_them0 - 5);
		TextColor(noi_bat);
		cout << "KHONG TIM THAY LTC PHU HOP!!!";
		TextColor(binh_thuong);
	}
}

void tao_khung_chuc_nang_7(int bang){
	if(bang == 0){
			gotoxy(dai_khung_chuc_nang + 1 + 29 + 15 + 13, 0);
		for (int i = 0; i < 49; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 1; i < rong_khung_danh_sach; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 29 + 15 + 13, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 49 - 1 + 29 + 15 + 13, i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang + 1 + 29 + 15 + 13, rong_khung_danh_sach);
		for (int i = 0; i < 49; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 0; i < 49 - 2; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i + 29 + 15 + 13, ngang1_danh_sach);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i + 29 + 15 + 13, ngang2_danh_sach);
			cout << char(khung_ngoai);
		}

		for(int i = 0; i < rong_khung_danh_sach - 3; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 14 + 29 + 15 + 13, ngang1_danh_sach + 1 + i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 14 + 14 + 29 + 15 + 13, ngang1_danh_sach + 1 + i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 14 + 14 + 10 + 29 + 15 + 13, ngang1_danh_sach + 1 + i);
			cout << char(khung_ngoai);
		}
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 7 - 2 + 29 + 15 + 13, ngang2_danh_sach - 1);
		cout << "MAMH";
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 14 + 7 - 5 + 29 + 15 + 13, ngang2_danh_sach - 1);
		cout << "NIEN KHOA";
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 14 + 14 + 4 - 3 + 29 + 15 + 13, ngang2_danh_sach - 1);
		cout << "HOC KI";
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 14 + 14 + 10 + 4 - 2 + 29 + 15 + 13, ngang2_danh_sach - 1);
		cout << "NHOM";
		gotoxy(dai_khung_chuc_nang + 1 + 29 + 23 - 5 + 15 + 13, ngang1_danh_sach - 1);
		cout << "DSach LTC";
		TextColor(binh_thuong);
		
	}
	/////////////////////////////////////////////////////////////
	else if(bang == 1){
		for (int i = 0; i < rong_khung_danh_sach - 6; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 6, ngang1_danh_sach + 1 + i + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 16, ngang1_danh_sach + 1 + i + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13, ngang1_danh_sach + 1 + i + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 14, ngang1_danh_sach + 1 + i + 3);
			cout << char(khung_ngoai);
		}
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 3 - 1, ngang1_danh_sach + 1 + 3);
		cout << "STT";
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 8 - 2, ngang1_danh_sach + 1 + 3);
		cout << "MASV";
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 7 - 1, ngang1_danh_sach + 1 + 3);
		cout << "HO";
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 7 - 1, ngang1_danh_sach + 1 + 3);
		cout << "TEN";
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 14 + 3 - 2, ngang1_danh_sach + 1 + 3);
		cout << "DIEM";
		gotoxy(dai_khung_chuc_nang + 1 + 28 - 4, ngang1_danh_sach - 1 + 3);
		cout << "BANG DIEM";
		TextColor(binh_thuong);
	}	
	/////////////////////////////////////////////////////////////
	else if(bang == 2){
		gotoxy(dai_khung_chuc_nang + 1, 3);
		for (int i = 0; i < 56; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 1; i < rong_khung_danh_sach - 3; i++){
			gotoxy(dai_khung_chuc_nang + 1, i + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 56 - 1, i + 3);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang + 1, rong_khung_danh_sach);
		for (int i = 0; i < 56; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 0; i < 56 - 2; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i, ngang1_danh_sach + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i, ngang2_danh_sach + 3);
			cout << char(khung_ngoai);
		}
	}
	
	/////////////////////////////////////////////////////////////
	else if(bang == 3){
		
		for (int i = 1; i < dai_khung_chuc_nang_them0 - 1; i++){
			gotoxy(i, ngang_chuc_nang_them0);
			cout << char(khung_ngoai);
			gotoxy(i, ngang_chuc_nang_them0 + 2);
			cout << char(khung_trong_them);
			gotoxy(i, ngang_chuc_nang_them0 + 2 + 2);
			cout << char(khung_trong_them);
			gotoxy(i, ngang_chuc_nang_them0 + 2 + 4);
			cout << char(khung_trong_them);
		}
		gotoxy(0,0);
		for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
			cout << char(khung_ngoai);
		}
		cout << endl;
		
		for (int i = 1; i < rong_khung_chuc_nang_them0 - 6; i++){
			cout << char(khung_ngoai);
			if(i > ngang_chuc_nang_them0){
				gotoxy(doc_chuc_nang_them0, i);
				cout << char(khung_ngoai);
			}
			gotoxy(dai_khung_chuc_nang_them0 - 1, i);
			cout << char(khung_ngoai) <<endl;
		}
		for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
			cout << char(khung_ngoai);
		}
		gotoxy(0, rong_khung_chuc_nang_them0 - 5);
		cout << char(khung_ngoai);
		gotoxy(dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang_them0 - 5);
		cout << char(khung_ngoai) << endl;
		for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
			cout << char(khung_ngoai);
		}
		int dem = 1;
		for(int i = ngang_chuc_nang_them0 + 2; i < rong_khung_chuc_nang_them0 + 1 - 6; i = i + 2){
			gotoxy(1, i - 1);
			if (dem == 1){
				TextColor(hien_thanh_sang);
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[dem][0], doc_chuc_nang_them0 - 1);
				dem++;
				TextColor(binh_thuong);
			}
			else if(dem == 4){
				TextColor(an_thanh_sang);
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[dem + 2][0], doc_chuc_nang_them0 - 1);
				dem++;
				TextColor(binh_thuong);
			}
			else{
				TextColor(an_thanh_sang);
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[dem][0], doc_chuc_nang_them0 - 1);
				dem++;
				TextColor(binh_thuong);
				gotoxy(3,1);
			}
		}
	}
	else if(bang == 4){
		string s1, s2;
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang_them0 / 2 - 11, ngang_chuc_nang_them0 - 2);
		cout << "IN BANG DIEM CUA 1 LTC";
		s1 = "BANG DIEM MON HOC ...........";
		s2 = "Nien khoa: .........     Hoc ky: .....     Nhom: .....";
		gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - s1.length()/2, 0);
		cout << s1;
		gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - s2.length()/2, 1);
		cout << s2;
		TextColor(binh_thuong);
	}
}

void xu_li_nhap_diem(TREE t, DanhsachSV *dssv, DanhsachSV *pTail, DsMonHoc dsmh){
	int row = 0;
	xuat_goi_y_ds_lop_tc(t, row, 7);
	
	char key_chuc_nang_them;
	int chon_thuoc_tinh = 1;
	
	int dai_khung_chuc_nang_them;
	int rong_khung_chuc_nang_them;
	int ngang_chuc_nang_them;
	int doc_chuc_nang_them;
	
	int so_thuoc_tinh = 7;
	
	dai_khung_chuc_nang_them = dai_khung_chuc_nang_them0;
	rong_khung_chuc_nang_them = rong_khung_chuc_nang_them0  - (rong_khung_chuc_nang + 2);
	ngang_chuc_nang_them = ngang_chuc_nang_them0 - (rong_khung_chuc_nang + 2) - 2;
	doc_chuc_nang_them = doc_chuc_nang_them0;
		
	for(int i = 0; i < so_thuoc_tinh; i++){
		thuoc_tinh_LTC[i][1] = "";
	}	
		
	int xac_nhan_du;
	while (1){
		xac_nhan_du = so_thuoc_tinh - 1 - 2;
		
		gotoxy(1 + doc_chuc_nang_them, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
		if(chon_thuoc_tinh == 4){
			nhap_tung_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh + 2][1], key_chuc_nang_them, chon_thuoc_tinh, 1, 0);
		}
		else{
			nhap_tung_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][1], key_chuc_nang_them, chon_thuoc_tinh, 1, 0);
		}
//		gotoxy(0,0);
//		cout << mang[6][1];
		
		for (int i = 0; i < so_thuoc_tinh; i++){
//			cout << xac_nhan_du;
			if(thuoc_tinh_LTC[i][1].length() != 0){
				xac_nhan_du = xac_nhan_du - 1;
			}
		}
		if(xac_nhan_du == 0){
//			gotoxy(0,0);
			clear_Area(dai_khung_chuc_nang + 1, 2, dai_khung_chuc_nang + 2 + 54, rong_khung_danh_sach);
			tao_khung_chuc_nang_7(1);
			tao_khung_chuc_nang_7(2);
			cau_i(t, dsmh, dssv, pTail);
		}
		else{
			clear_Area(dai_khung_chuc_nang + 1, 2, dai_khung_chuc_nang + 2 + 54, rong_khung_danh_sach);
			tao_khung_chuc_nang_7(1);
			tao_khung_chuc_nang_7(2);
			tao_khung_chuc_nang_7(4);
		}
//		key_chuc_nang_them = getch();
		if(key_chuc_nang_them == mui_ten_len){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
			
			if(chon_thuoc_tinh == 1){
				chon_thuoc_tinh = so_thuoc_tinh - 1 - 2;
			}
			else{
				chon_thuoc_tinh = chon_thuoc_tinh - 1;
			}
			
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
		}
		
		if(key_chuc_nang_them == mui_ten_xuong){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
				chon_thuoc_tinh = 1;
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
		}
		
		if(key_chuc_nang_them == enter){
//			gotoxy(0,0);
//			cout << "nhap di 3";
			
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
			
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				chon_thuoc_tinh = 1;
			}
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
		}
		if(key_chuc_nang_them == esc){
			gotoxy(0,0);
			clrscr();
			system(ma_system);
			Tao_khung_menu_main();
			break;
		}
	}
}

///////////////////////////
//CHUC NANG 8: IN BANG DIEM

void cau_h(TREE t,DanhsachSV *dssv,DanhsachSV *pTail, bool &kt,DsMonHoc dsmh){
	xuat_bang_diem_mh_loptc(t, thuoc_tinh_LTC[2][1], thuoc_tinh_LTC[1][1], atoi(thuoc_tinh_LTC[3][1].c_str()), atoi(thuoc_tinh_LTC[6][1].c_str()),kt,dssv,pTail, dsmh);
	if(kt==false){
		gotoxy(1, rong_khung_chuc_nang_them0 - 5);
		TextColor(noi_bat);
		cout << "KHONG TIM THAY LTC PHU HOP!!!";
		TextColor(binh_thuong);
	}
}

void tao_khung_chuc_nang_8(int bang){
		
	if(bang == 0){
			gotoxy(dai_khung_chuc_nang + 1 + 29 + 15 + 13, 0);
		for (int i = 0; i < 49; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 1; i < rong_khung_danh_sach; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 29 + 15 + 13, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 49 - 1 + 29 + 15 + 13, i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang + 1 + 29 + 15 + 13, rong_khung_danh_sach);
		for (int i = 0; i < 49; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 0; i < 49 - 2; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i + 29 + 15 + 13, ngang1_danh_sach);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i + 29 + 15 + 13, ngang2_danh_sach);
			cout << char(khung_ngoai);
		}

		for(int i = 0; i < rong_khung_danh_sach - 3; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 14 + 29 + 15 + 13, ngang1_danh_sach + 1 + i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 14 + 14 + 29 + 15 + 13, ngang1_danh_sach + 1 + i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 14 + 14 + 10 + 29 + 15 + 13, ngang1_danh_sach + 1 + i);
			cout << char(khung_ngoai);
		}
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 7 - 2 + 29 + 15 + 13, ngang2_danh_sach - 1);
		cout << "MAMH";
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 14 + 7 - 5 + 29 + 15 + 13, ngang2_danh_sach - 1);
		cout << "NIEN KHOA";
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 14 + 14 + 4 - 3 + 29 + 15 + 13, ngang2_danh_sach - 1);
		cout << "HOC KI";
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 14 + 14 + 10 + 4 - 2 + 29 + 15 + 13, ngang2_danh_sach - 1);
		cout << "NHOM";
		gotoxy(dai_khung_chuc_nang + 1 + 29 + 23 - 5 + 15 + 13, ngang1_danh_sach - 1);
		cout << "DSach LTC";
		TextColor(binh_thuong);
		
	}
	/////////////////////////////////////////////////////////////
	else if(bang == 1){
		for (int i = 0; i < rong_khung_danh_sach - 6; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 6, ngang1_danh_sach + 1 + i + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 16, ngang1_danh_sach + 1 + i + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13, ngang1_danh_sach + 1 + i + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 14, ngang1_danh_sach + 1 + i + 3);
			cout << char(khung_ngoai);
		}
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 3 - 1, ngang1_danh_sach + 1 + 3);
		cout << "STT";
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 8 - 2, ngang1_danh_sach + 1 + 3);
		cout << "MASV";
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 7 - 1, ngang1_danh_sach + 1 + 3);
		cout << "HO";
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 7 - 1, ngang1_danh_sach + 1 + 3);
		cout << "TEN";
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 14 + 3 - 2, ngang1_danh_sach + 1 + 3);
		cout << "DIEM";
		gotoxy(dai_khung_chuc_nang + 1 + 28 - 4, ngang1_danh_sach - 1 + 3);
		cout << "BANG DIEM";
		TextColor(binh_thuong);
	}	
	/////////////////////////////////////////////////////////////
	else if(bang == 2){
		gotoxy(dai_khung_chuc_nang + 1, 3);
		for (int i = 0; i < 56; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 1; i < rong_khung_danh_sach - 3; i++){
			gotoxy(dai_khung_chuc_nang + 1, i + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 56 - 1, i + 3);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang + 1, rong_khung_danh_sach);
		for (int i = 0; i < 56; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 0; i < 56 - 2; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i, ngang1_danh_sach + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i, ngang2_danh_sach + 3);
			cout << char(khung_ngoai);
		}
	}
	
	/////////////////////////////////////////////////////////////
	else if(bang == 3){
		
		for (int i = 1; i < dai_khung_chuc_nang_them0 - 1; i++){
			gotoxy(i, ngang_chuc_nang_them0);
			cout << char(khung_ngoai);
			gotoxy(i, ngang_chuc_nang_them0 + 2);
			cout << char(khung_trong_them);
			gotoxy(i, ngang_chuc_nang_them0 + 2 + 2);
			cout << char(khung_trong_them);
			gotoxy(i, ngang_chuc_nang_them0 + 2 + 4);
			cout << char(khung_trong_them);
		}
		gotoxy(0,0);
		for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
			cout << char(khung_ngoai);
		}
		cout << endl;
		
		for (int i = 1; i < rong_khung_chuc_nang_them0 - 6; i++){
			cout << char(khung_ngoai);
			if(i > ngang_chuc_nang_them0){
				gotoxy(doc_chuc_nang_them0, i);
				cout << char(khung_ngoai);
			}
			gotoxy(dai_khung_chuc_nang_them0 - 1, i);
			cout << char(khung_ngoai) <<endl;
		}
		for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
			cout << char(khung_ngoai);
		}
		gotoxy(0, rong_khung_chuc_nang_them0 - 5);
		cout << char(khung_ngoai);
		gotoxy(dai_khung_chuc_nang_them0 - 1, rong_khung_chuc_nang_them0 - 5);
		cout << char(khung_ngoai) << endl;
		for (int i = 0; i < dai_khung_chuc_nang_them0; i++){
			cout << char(khung_ngoai);
		}
		int dem = 1;
		for(int i = ngang_chuc_nang_them0 + 2; i < rong_khung_chuc_nang_them0 + 1 - 6; i = i + 2){
			gotoxy(1, i - 1);
			if (dem == 1){
				TextColor(hien_thanh_sang);
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[dem][0], doc_chuc_nang_them0 - 1);
				dem++;
				TextColor(binh_thuong);
			}
			else if(dem == 4){
				TextColor(an_thanh_sang);
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[dem + 2][0], doc_chuc_nang_them0 - 1);
				dem++;
				TextColor(binh_thuong);
			}
			else{
				TextColor(an_thanh_sang);
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[dem][0], doc_chuc_nang_them0 - 1);
				dem++;
				TextColor(binh_thuong);
				gotoxy(3,1);
			}
		}
	}
	else if(bang == 4){
		string s1, s2;
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang_them0 / 2 - 11, ngang_chuc_nang_them0 - 2);
		cout << "IN BANG DIEM CUA 1 LTC";
		s1 = "BANG DIEM MON HOC ...........";
		s2 = "Nien khoa: .........     Hoc ky: .....     Nhom: .....";
		gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - s1.length()/2, 0);
		cout << s1;
		gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - s2.length()/2, 1);
		cout << s2;
		TextColor(binh_thuong);
	}
}

void xu_li_in_diem(TREE t, DanhsachSV *dssv, DanhsachSV *pTail, DsMonHoc dsmh){
	int row = 0;
	xuat_goi_y_ds_lop_tc(t, row, 8);
	
	char key_chuc_nang_them;
	int chon_thuoc_tinh = 1;
	
	int dai_khung_chuc_nang_them;
	int rong_khung_chuc_nang_them;
	int ngang_chuc_nang_them;
	int doc_chuc_nang_them;
	
	int so_thuoc_tinh = 7;
	
	dai_khung_chuc_nang_them = dai_khung_chuc_nang_them0;
	rong_khung_chuc_nang_them = rong_khung_chuc_nang_them0  - (rong_khung_chuc_nang + 2);
	ngang_chuc_nang_them = ngang_chuc_nang_them0 - (rong_khung_chuc_nang + 2) - 2;
	doc_chuc_nang_them = doc_chuc_nang_them0;
		
	for(int i = 0; i < so_thuoc_tinh; i++){
		thuoc_tinh_LTC[i][1] = "";
	}	
		
	int xac_nhan_du;
	while (1){
		xac_nhan_du = so_thuoc_tinh - 1 - 2;
		
		gotoxy(1 + doc_chuc_nang_them, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
		if(chon_thuoc_tinh == 4){
			nhap_tung_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh + 2][1], key_chuc_nang_them, chon_thuoc_tinh, 1, 0);
		}
		else{
			nhap_tung_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][1], key_chuc_nang_them, chon_thuoc_tinh, 1, 0);
		}
//		gotoxy(0,0);
//		cout << mang[6][1];
		
		for (int i = 0; i < so_thuoc_tinh; i++){
//			cout << xac_nhan_du;
			if(thuoc_tinh_LTC[i][1].length() != 0){
				xac_nhan_du = xac_nhan_du - 1;
			}
		}
		if(xac_nhan_du == 0){
//			gotoxy(0,0);
			clear_Area(dai_khung_chuc_nang + 1, 2, dai_khung_chuc_nang + 2 + 54, rong_khung_danh_sach);
			tao_khung_chuc_nang_8(1);
			tao_khung_chuc_nang_8(2);
			bool ktra = false;
			cau_h(t, dssv, pTail, ktra, dsmh);
			if(ktra == true){
				gotoxy(1, rong_khung_chuc_nang_them0 - 5);
				cout << "                             ";
			}
		}
		else{
			clear_Area(dai_khung_chuc_nang + 1, 2, dai_khung_chuc_nang + 2 + 54, rong_khung_danh_sach);
			tao_khung_chuc_nang_8(1);
			tao_khung_chuc_nang_8(2);
			tao_khung_chuc_nang_8(4);
		}
//		key_chuc_nang_them = getch();
		if(key_chuc_nang_them == mui_ten_len){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
			
			if(chon_thuoc_tinh == 1){
				chon_thuoc_tinh = so_thuoc_tinh - 1 - 2;
			}
			else{
				chon_thuoc_tinh = chon_thuoc_tinh - 1;
			}
			
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
		}
		
		if(key_chuc_nang_them == mui_ten_xuong){
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
				chon_thuoc_tinh = 1;
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
		}
		
		if(key_chuc_nang_them == enter){
//			gotoxy(0,0);
//			cout << "nhap di 3";
			
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(an_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
			
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				chon_thuoc_tinh = 1;
			}
			else{
				chon_thuoc_tinh = chon_thuoc_tinh + 1;
			}
			
			gotoxy(1, rong_khung_chuc_nang + 2 + ngang_chuc_nang_them + 2 + chon_thuoc_tinh * 2 - 1);
			TextColor(hien_thanh_sang);
			if(chon_thuoc_tinh == so_thuoc_tinh - 1 - 2){
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[so_thuoc_tinh - 1][0],doc_chuc_nang_them - 1);
			}
			else{
				cout << chuoi_voi_n_ki_tu(thuoc_tinh_LTC[chon_thuoc_tinh][0],doc_chuc_nang_them - 1);
			}
		}
		if(key_chuc_nang_them == esc){
			gotoxy(0,0);
			clrscr();
			system(ma_system);
			Tao_khung_menu_main();
			break;
		}
	}
}

//////////////////////////////
//CHUC NANG 9: IN BANG DIEM TB

void xuat_goi_y_chuc_nang_9(DanhsachSV *dssv)
{	
	int row = 0;
	string before0 = "";
	for(DanhsachSV *k= dssv; k!=NULL; k=k->NEXT )
	{
		if(stricmp(k->SV.MALOP, before0.c_str())!=0)
		{
			thuoc_tinh_sv[0][1] = k->SV.MALOP;
			TextColor(noi_bat);
			gotoxy(dai_khung_chuc_nang + 1 + 58 + 1 + 6 - thuoc_tinh_sv[0][1].length()/2, 5 + row);
			cout << thuoc_tinh_sv[0][1];
			TextColor(binh_thuong);
			row++;
			before0 = thuoc_tinh_sv[0][1];
		}
		if(k->NEXT==NULL)
		{
			thuoc_tinh_sv[0][1] = "";
			break;
		}
	} 
}

void tao_khung_chuc_nang_9(int bang){
	
	if(bang == 0){
		gotoxy(dai_khung_chuc_nang + 1 + 29 + 15 + 13 + 2, 0);
		for (int i = 0; i < 15; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 1; i < rong_khung_danh_sach; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 29 + 15 + 13 + 2, i);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 29 - 2 + 29 + 15 + 2, i);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang + 1 + 29 + 15 + 13 + 2, rong_khung_danh_sach);
		for (int i = 0; i < 15; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 0; i < 15 - 2; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i + 29 + 15 + 13 + 2, ngang1_danh_sach);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i + 29 + 15 + 13 + 2, ngang2_danh_sach);
			cout << char(khung_ngoai);
		}
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 1 + 7 - 3 + 29 + 15 + 13 + 2, ngang2_danh_sach - 1);
		cout << "MA LOP";
		gotoxy(dai_khung_chuc_nang + 1 + 29 + 28 + 7 - 4 + 2, ngang1_danh_sach - 1);
		cout << "DSach LOP";
		TextColor(binh_thuong);
	}
	/////////////////////////////////////////////////////////////
	
	if(bang == 1){
		for (int i = 0; i < rong_khung_danh_sach - 6; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 6, ngang1_danh_sach + 1 + i + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 16, ngang1_danh_sach + 1 + i + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13, ngang1_danh_sach + 1 + i + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 14, ngang1_danh_sach + 1 + i + 3);
			cout << char(khung_ngoai);
		}
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang + 1 + 3 - 1, ngang1_danh_sach + 1 + 3);
		cout << "STT";
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 8 - 2, ngang1_danh_sach + 1 + 3);
		cout << "MASV";
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 7 - 1, ngang1_danh_sach + 1 + 3);
		cout << "HO";
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 7 - 1, ngang1_danh_sach + 1 + 3);
		cout << "TEN";
		gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 14 + 3 + 1 - 2, ngang1_danh_sach + 1 + 3);
		cout << "DIEM";
		gotoxy(dai_khung_chuc_nang + 1 + 28 - 4, ngang1_danh_sach - 1 + 3);
		cout << "BANG DIEM";
		TextColor(binh_thuong);	
	}
	/////////////////////////////////////////////////////////////
	if(bang == 2){
		gotoxy(dai_khung_chuc_nang + 1, 3);
		for (int i = 0; i < 58; i++){
			cout << char(khung_ngoai);
		}
		for (int i = 1; i < rong_khung_danh_sach - 3; i++){
			gotoxy(dai_khung_chuc_nang + 1, i + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 58 - 1, i + 3);
			cout << char(khung_ngoai);
		}
		gotoxy(dai_khung_chuc_nang + 1, rong_khung_danh_sach);
		for (int i = 0; i < 58; i++){
			cout << char(khung_ngoai);
		}
		for(int i = 0; i < 58 - 2; i++){
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i, ngang1_danh_sach + 3);
			cout << char(khung_ngoai);
			gotoxy(dai_khung_chuc_nang + 1 + 1 + i, ngang2_danh_sach + 3);
			cout << char(khung_ngoai);
		}
	}
	
	/////////////////////////////////////////////////////////////
	if(bang == 3){
		TextColor(noi_bat);
		gotoxy(1, 5);
		TextColor(hien_thanh_sang);
		cout << "   MA LOP   ";
		gotoxy(1, 7);
		cout << "NAM NHAP HOC";
		TextColor(binh_thuong);
		for (int i = 1; i < dai_khung_chuc_nang_xoa - 1; i++){
			gotoxy(i, ngang_chuc_nang_xoa + 2);
			cout << char(khung_trong_them);
			gotoxy(i, ngang_chuc_nang_xoa + 4);
			cout << char(khung_ngoai);
		}
		for (int i = 1; i < dai_khung_chuc_nang_xoa - 1; i++){
			gotoxy(i, ngang_chuc_nang_xoa);
			cout << char(khung_ngoai);
		}
		gotoxy(0,0);
		for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
			cout << char(khung_ngoai);
		}
		cout << endl;
		
		for (int i = 1; i < rong_khung_chuc_nang_xoa + 4; i++){
			cout << char(khung_ngoai);
			if((i > ngang_chuc_nang_xoa) && ((i < ngang_chuc_nang_xoa + 4))){
				gotoxy(doc_chuc_nang_xoa - 3, i);
				cout << char(khung_ngoai);
			}
			gotoxy(dai_khung_chuc_nang_xoa - 1, i);
			cout << char(khung_ngoai) <<endl;
		}
		for (int i = 0; i < dai_khung_chuc_nang_xoa; i++){
			cout << char(khung_ngoai);
		}
		gotoxy(1, 5);
	}
	if(bang == 4){
		string s1, s2;
		TextColor(noi_bat);
		gotoxy(dai_khung_chuc_nang_them0 / 2 - 22, ngang_chuc_nang_them0 - 2);
		cout << "IN BANG DIEM TB KET THUC KHOA HOC CUA 1 LOP";
		s1 = "BANG THONG KE DIEM TRUNG BINH KHOA HOC";
		s2 = "Lop: ...............  Nam nhap hoc: xxxx";
		gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - s1.length()/2, 0);
		cout << s1;
		gotoxy(dai_khung_chuc_nang_them0 + 1 + 28 - s2.length()/2, 1);
		cout << s2;
		TextColor(binh_thuong);
	}
}

void nhap_chuc_nang_9(string &chuoi_cua_o, char &phim_tra_ve_khi_out, int hang_tra_ve){
	int dau_tien = 1;
	string xoa = "";
	xoa = chuoi_voi_n_ki_tu(xoa, 45);
	
	char key_nhap;
	while (1){
		key_nhap = getch();
		if((key_nhap == -32) || ((key_nhap == 0))){
			//truong hop la cac phim mui ten
			key_nhap = getch();
			if((key_nhap == mui_ten_len) || (key_nhap == mui_ten_xuong) || (key_nhap == F1)){
				phim_tra_ve_khi_out = key_nhap;
				rang_buoc_chuoi(chuoi_cua_o, key_nhap, khoang_trang_cuoi);
				TextColor(binh_thuong);
				gotoxy(doc_chuc_nang_xoa - 3 + 1, hang_tra_ve * 2 + 5);
				cout << xoa;
				TextColor(noi_bat);
				gotoxy(doc_chuc_nang_xoa - 3 + 1, hang_tra_ve * 2 + 5);
				cout << chuoi_cua_o;
				TextColor(binh_thuong);
				break;
			}
		}
		else{
			if((key_nhap == enter) || (key_nhap == esc)){
				phim_tra_ve_khi_out = key_nhap;
				rang_buoc_chuoi(chuoi_cua_o, key_nhap, khoang_trang_cuoi);
				TextColor(binh_thuong);
				gotoxy(doc_chuc_nang_xoa - 3 + 1, hang_tra_ve * 2 + 5);
				cout << xoa;
				TextColor(noi_bat);
				gotoxy(doc_chuc_nang_xoa - 3 + 1, hang_tra_ve * 2 + 5);
				cout << chuoi_cua_o;
				TextColor(binh_thuong);
				break;
			}	
			else if(key_nhap == backspace){
				chuoi_cua_o = chuoi_cua_o.substr(0, chuoi_cua_o.length() - 1);
			}
			else{
				if(dau_tien == 1){
					chuoi_cua_o = "";
					dau_tien = 0;
				}
//				chuoi_cua_o = chuoi_cua_o + char(key_nhap);
				if(hang_tra_ve == 0 && chuoi_cua_o.length() <= 16){
					rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so_va_chu_in_hoa);
				}
				if(hang_tra_ve == 1 && chuoi_cua_o.length() <= 5){
					rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so);
				}
			}
			TextColor(binh_thuong);
			gotoxy(doc_chuc_nang_xoa - 3 + 1, hang_tra_ve * 2  + 5);
			cout << xoa;
			TextColor(noi_bat);
			gotoxy(doc_chuc_nang_xoa - 3 + 1, hang_tra_ve * 2 + 5);
			cout << chuoi_cua_o;
			TextColor(binh_thuong);
		}
	}
}

//////////////////////////////////////////////
struct Dsloptc_tam{
	string mamh;
	SVdangky *Dssv_tam=NULL;
};
void coppy(TREE t,int &n,Dsloptc_tam *&dstam){
	if(t!=NULL){
		dstam[n].mamh=t->LopTC.MAMH;
		dstam[n].Dssv_tam=t->Dsdk;
		n++;
		coppy(t->pLeft,n,dstam);
		coppy(t->pRight,n,dstam);
	}
}
float tinh_diem_tb(string masv,Dsloptc_tam *dstam,int n,DsMonHoc dsmh){
	float tongchi=0;
	float tongdiem=0;bool kt_coko=false;
	for(int i=0;i<n;i++){
		bool kt=false;
		float diem,tinchi;
		for(SVdangky *k=dstam[i].Dssv_tam;k!=NULL;k=k->next){
			if(stricmp(masv.c_str(),k->MASV)==0){
				int g=kt_mamh_trung(dsmh,dstam[i].mamh);
				diem=k->Diem*(dsmh.Ds[g]->STCLT+dsmh.Ds[g]->STCTH);
				tinchi=dsmh.Ds[g]->STCLT+dsmh.Ds[g]->STCTH;
			    kt=true;kt_coko=true;break;
			}
		}
		if(kt==true){
		tongdiem=tongdiem+diem;
		tongchi=tongchi+tinchi;
	    }
	}
	if(kt_coko==false) return 0;
	return tongdiem/tongchi;
}
void cau_g(TREE t,DanhsachSV *dssv,DsMonHoc dsmh, string malop, int namnh){
	int n=0;
	Dsloptc_tam *dstam=new Dsloptc_tam[MAXMA];
	coppy(t,n,dstam);
	bool ktra = false;
	int row = 0;
	for(DanhsachSV *k=dssv;k!=NULL;k=k->NEXT){
		if(stricmp(k->SV.MALOP,malop.c_str())==0&&k->SV.NamNH==namnh){
			ktra = true;
		    float diemtb=tinh_diem_tb(k->SV.MASV,dstam,n,dsmh);
//		    float diemtb = 0;
		    TextColor(noi_bat);
			gotoxy(dai_khung_chuc_nang + 1 + 3 - 1, ngang1_danh_sach + 1 + 3 + row + 2);
			cout << row + 1;
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 8 - 7, ngang1_danh_sach + 1 + 3 + row + 2);
			cout << k->SV.MASV;
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 7 - k->SV.HO.length()/2, ngang1_danh_sach + 1 + 3 + row + 2);
			cout << k->SV.HO;
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 7 - k->SV.TEN.length()/2, ngang1_danh_sach + 1 + 3 + row + 2);
			cout << k->SV.TEN;
			gotoxy(dai_khung_chuc_nang + 1 + 6 + 16 + 13 + 14 + 3 - 2, ngang1_danh_sach + 1 + 3 + row + 2);
			cout << diemtb;
			TextColor(binh_thuong);
			row++;		
		}
	}
	if(ktra == false){
		gotoxy(1, 9);
		TextColor(noi_bat);
		cout << "KHONG TIM THAY DSACH PHU HOP";
		TextColor(binh_thuong);
	}
	else{
		gotoxy(1, 9);
		TextColor(noi_bat);
		cout << "                            ";
		TextColor(binh_thuong);
	}
	delete[] dstam;
}

void xu_li_in_diem_tb(DanhsachSV *dssv, DanhsachSV *pTail, TREE t, DsMonHoc dsmh){
	xuat_goi_y_chuc_nang_9(dssv);
	int row = 0;
	string s[2];
	while(1){
		char phim;
		gotoxy(doc_chuc_nang_xoa - 3 + 1, row * 2 + 5);
		nhap_chuc_nang_9(s[row], phim, row);
//		gotoxy(0,0);
//		cout << s[0] << " " << atoi(s[1].c_str());
		clear_Area(dai_khung_chuc_nang + 1, 3, dai_khung_chuc_nang + 1 + 58, rong_khung_danh_sach);
		tao_khung_chuc_nang_9(1);
		tao_khung_chuc_nang_9(2);
		cau_g(t, dssv, dsmh, s[0], atoi(s[1].c_str()));
		if((phim == mui_ten_xuong) || (phim == mui_ten_len) || (phim == enter)){
			row = abs(row - 1);
		}
		else if(phim == esc){
			s[0] = s[1] = "";
			clrscr();
			Tao_khung_menu_main();
			break;
		}
	}
}

/////////////////////////
//CHUC NANG DK LTC CUA SV

void tao_khung_dang_ky(int bang){
	if(bang == 0){
		//cot max 168
		int x0 = 168 / 2 - 34;
		int y0 = 0;
		gotoxy(x0, y0);
		
		for (int i = 0; i < 68; i++){
			gotoxy(x0 + i, y0);
			cout << char(khung_ngoai);
			gotoxy(x0 + i, y0 + 10);
			cout << char(khung_ngoai);
			gotoxy(x0 + i, y0 + 4);
			cout << char(khung_ngoai);
			gotoxy(x0 + i, y0 + 8);
			cout << char(khung_ngoai);
			gotoxy(x0 + i, y0 + 6);
			cout << char(khung_trong);
		}
		
		for (int i = 0; i < 10; i++){
			gotoxy(x0, y0 + i);
			cout << char(khung_ngoai);
			gotoxy(x0 + 67, y0 + i);
			cout << char(khung_ngoai);
		}
		
		for (int i = 5; i < 9; i++){
			gotoxy(x0 + 10, y0 + i);
			cout << char(khung_ngoai);
		}
		
		gotoxy(x0 + 34 - 10, y0 + 2);
		TextColor(noi_bat);
		cout << "DANG KY LOP TINH CHI";
		
		TextColor(noi_bat);
		gotoxy(x0 + 1, y0 + 5);
		cout << "NIEN KHOA";
		gotoxy(x0 + 1, y0 + 7);
		cout << "HOC KI";
		TextColor(binh_thuong);
	}
	else if(bang == 1){
		for(int i = 0; i<168/2 + 10; i++){
			gotoxy(i, 12);
			cout << char(khung_ngoai);
			gotoxy(i, rong_khung_danh_sach);
			cout << char(khung_ngoai);
			gotoxy(i, 14);
			cout << char(khung_ngoai);
			gotoxy(i, 16);
			cout << char(khung_ngoai);
		}
		for(int i = 13; i<rong_khung_danh_sach; i++){
			gotoxy(0, i);
			cout << char(khung_ngoai);
			gotoxy(168/2 + 10 - 1, i);
			cout << char(khung_ngoai);
			if(i > 14){
				gotoxy(16, i);
				cout << char(khung_ngoai);
				gotoxy(16 + 33, i);
				cout << char(khung_ngoai);
				gotoxy(16 + 33 + 8, i);
				cout << char(khung_ngoai);
				gotoxy(16 + 33 + 8 + 8, i);
				cout << char(khung_ngoai);
				gotoxy(16 + 33 + 8 + 8 + 9, i);
				cout << char(khung_ngoai);
				gotoxy(16 + 33 + 8 + 8 + 9 + 9, i);
				cout << char(khung_ngoai);
			}
		}
		TextColor(noi_bat);
		gotoxy(8 - 2, 15);
		cout << "MA MH";
		gotoxy(16 + 17 - 3, 15);
		cout << "TEN MH";
		gotoxy(16 + 33 + 4 - 2, 15);
		cout << "NHOM";
		gotoxy(16 + 33 + 8 + 5 - 2, 15);
		cout << "STC";
		gotoxy(16 + 33 + 8 + 8 + 5 - 3, 15);
		cout << "MA LTC";
		gotoxy(16 + 33 + 8 + 8 + 9 + 5 - 3, 15);
		cout << "SV MAX";
		gotoxy(16 + 33 + 8 + 8 + 9 + 9 + 6 - 4, 15);
		cout << "CON LAI";
		TextColor(binh_thuong);
		gotoxy(168 / 4 - 10, 13);
		TextColor(noi_bat);
		cout << "DANH SACH LTC PHU HOP";
		TextColor(binh_thuong);
	}
	else if(bang == 2){
		for(int i = 168/2 + 10 + 1; i<168; i++){
			gotoxy(i, 12);
			cout << char(khung_ngoai);
			gotoxy(i, rong_khung_danh_sach);
			cout << char(khung_ngoai);
			gotoxy(i, 14);
			cout << char(khung_ngoai);
			gotoxy(i, 16);
			cout << char(khung_ngoai);
		}
		for(int i = 13; i<rong_khung_danh_sach; i++){
			gotoxy(168/2 + 10 + 1, i);
			cout << char(khung_ngoai);
			gotoxy(168 - 1, i);
			cout << char(khung_ngoai);
			if(i > 14){
				gotoxy(168/2 + 10 + 1 + 6, i);
				cout << char(khung_ngoai);
				gotoxy(168/2 + 10 + 1 + 6 + 16, i);
				cout << char(khung_ngoai);
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33, i);
				cout << char(khung_ngoai);
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 8, i);
				cout << char(khung_ngoai);
			}
		}
		TextColor(noi_bat);
		gotoxy(168/2 + 10 + 1 + 4 - 2, 15);
		cout << "STT";
		gotoxy(168/2 + 10 + 6 + 9 - 3, 15);
		cout << "MA MH";
		gotoxy(168/2 + 10 + 1 + 6 + 16 + 17 - 3, 15);
		cout << "TEN MH";
		gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 4 - 2, 15);
		cout << "NHOM";
		gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 8 + 5 - 2, 15);
		cout << "STC";
		TextColor(binh_thuong);
		gotoxy(168/2 + 10 + 168 / 4 - 10, 13);
		TextColor(noi_bat);
		cout << "DANH SACH LTC DA CHON";
		TextColor(binh_thuong);
	}
}

void nhap_dki(string &chuoi_cua_o, char &phim_tra_ve_khi_out, int hang_tra_ve){
	int dau_tien = 1;
	if(chuoi_cua_o.length() > 0){
		dau_tien = 0;
	}
	string xoa = "";
	int x0 = 168 / 2 - 34;
	xoa = chuoi_voi_n_ki_tu(xoa, 46);
//	gotoxy(dai_khung_chuc_nang + 1 + 51, hang_tra_ve + 8);
//	cout << xoa;
	char key_nhap;
	gotoxy(x0 + 9 + 2, 5 + hang_tra_ve * 2);
	while (1){
		key_nhap = getch();
		if((key_nhap == -32) || ((key_nhap == 0))){
			//truong hop la cac phim mui ten
			key_nhap = getch();
			if((key_nhap == mui_ten_len) || (key_nhap == mui_ten_xuong) || (key_nhap == F1)){
				phim_tra_ve_khi_out = key_nhap;
				rang_buoc_chuoi(chuoi_cua_o, key_nhap, khoang_trang_cuoi);
				TextColor(binh_thuong);
				gotoxy(x0 + 9 + 2, 5 + hang_tra_ve * 2);
				cout << xoa;
				TextColor(noi_bat);
				gotoxy(x0 + 9 + 2, 5 + hang_tra_ve * 2);
				cout << chuoi_cua_o;
				TextColor(binh_thuong);
				break;
			}
		}
		else{
			if((key_nhap == enter) || (key_nhap == esc)){
				phim_tra_ve_khi_out = key_nhap;
				rang_buoc_chuoi(chuoi_cua_o, key_nhap, khoang_trang_cuoi);
				if(hang_tra_ve == 0){
					rang_buoc_chuoi(chuoi_cua_o, key_nhap, ket_thuc_nien_khoa);
				}
				TextColor(binh_thuong);
				gotoxy(x0 + 9 + 2, 5 + hang_tra_ve * 2);
				cout << xoa;
				TextColor(noi_bat);
				gotoxy(x0 + 9 + 2, 5 + hang_tra_ve * 2);
				cout << chuoi_cua_o;
				TextColor(binh_thuong);
				break;
			}	
			else if(key_nhap == backspace){
				chuoi_cua_o = chuoi_cua_o.substr(0, chuoi_cua_o.length() - 1);
			}
			else{
				if(dau_tien == 1){
					chuoi_cua_o = "";
					dau_tien = 0;
				}
//				chuoi_cua_o = chuoi_cua_o + char(key_nhap);
				if(chuoi_cua_o.length() <= 9 && hang_tra_ve == 0){
					rang_buoc_chuoi(chuoi_cua_o, key_nhap, dinh_dang_nien_khoa);
				}
				if(chuoi_cua_o.length() <= 2 && hang_tra_ve == 1){
					rang_buoc_chuoi(chuoi_cua_o, key_nhap, chi_so);
				}
			}
			TextColor(binh_thuong);
			gotoxy(x0 + 9 + 2, 5 + hang_tra_ve * 2);
			cout << xoa;
			TextColor(noi_bat);
			gotoxy(x0 + 9 + 2, 5 + hang_tra_ve * 2);
			cout << chuoi_cua_o;
			TextColor(binh_thuong);
		}
	}
}

int Sinhvienconlai(SVdangky *dsdk){
	int i=0;
	for(SVdangky *k=dsdk;k!=NULL;k=k->next){
		i++;
	}
	return i;
}
void saochep(TREE t,string nk,int hk,int &n,DsLopTC *&tam,bool &kt){
	if(t!=NULL){
		if(t->LopTC.HK==hk&&stricmp(t->LopTC.NienKhoa.c_str(),nk.c_str())==0){
		    tam[n].Dsdk=t->Dsdk;
		    tam[n].LopTC=t->LopTC;
		    n++;
		    kt=true;
		}
		saochep(t->pLeft,nk,hk,n,tam,kt);
		saochep(t->pRight,nk,hk,n,tam,kt);
	}
}
void xuat_bang_ben_trai(DsLopTC *tam,int n,DsMonHoc dsmh){
	for(int i=0;i<n;i++){
		int j=kt_mamh_trung(dsmh,tam[i].LopTC.MAMH);
		int CL=tam[i].LopTC.SvMax- Sinhvienconlai(tam[i].Dsdk);
		if(i == 0){
			TextColor(hien_thanh_sang);
		}
		else{
			TextColor(noi_bat);
		}
		gotoxy(8 - strlen(tam[i].LopTC.MAMH)/2, 15 + i + 2);
		cout << tam[i].LopTC.MAMH;
		gotoxy(16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + i + 2);
		cout << dsmh.Ds[j]->TENMH;
		gotoxy(16 + 33 + 4 - chuyen_int_string(tam[i].LopTC.Nhom).length()/2, 15 + i + 2);
		cout << tam[i].LopTC.Nhom;
		gotoxy(16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + i + 2);
		cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
		gotoxy(16 + 33 + 8 + 8 + 5 - chuyen_int_string(tam[i].LopTC.MALOPTC).length()/2, 15 + i + 2);
		cout << tam[i].LopTC.MALOPTC;
		gotoxy(16 + 33 + 8 + 8 + 9 + 5 - chuyen_int_string(tam[i].LopTC.SvMax).length()/2, 15 + i + 2);
		cout << tam[i].LopTC.SvMax;
		gotoxy(16 + 33 + 8 + 8 + 9 + 9 + 5 - chuyen_int_string(CL).length()/2, 15 + i + 2);
		cout << CL;
		TextColor(binh_thuong);
	}
}
bool kt_dangky_trung(DsLopTC *chontam,int m,int maloptc){
	for(int i=0;i<m;i++){
		if(maloptc==chontam[i].LopTC.MALOPTC){
			return true;
		}
	}
	return false;
}
void dk(DsLopTC *tam,int n,int maloptc,DsLopTC *&chontam,int &m){
	for(int i=0;i<n;i++){
		if(maloptc==tam[i].LopTC.MALOPTC){
			bool kt=kt_dangky_trung(chontam,m,maloptc);
			if(kt==false){
			chontam[m]=tam[i];
			m++;
		 }
		}
	}
}
void xuat_bang_ben_phai(DsLopTC *tam,int n,DsMonHoc dsmh){
	for(int i=0;i<n;i++){
		int j=kt_mamh_trung(dsmh,tam[i].LopTC.MAMH);
		int CL=tam[i].LopTC.SvMax- Sinhvienconlai(tam[i].Dsdk);

		TextColor(noi_bat);
		gotoxy(168/2 + 10 + 1 + 3 - chuyen_int_string(i+1).length()/2, 15 + i + 2);
		cout << i + 1;
		gotoxy(168/2 + 10 + 6 + 9 - strlen(tam[i].LopTC.MAMH)/2, 15 + i + 2);
		cout << tam[i].LopTC.MAMH;
		gotoxy(168/2 + 10 + 1 + 6 + 16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + i + 2);
		cout << dsmh.Ds[j]->TENMH;
		gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 4 - chuyen_int_string(tam[i].LopTC.Nhom).length()/2, 15 + i + 2);
		cout << tam[i].LopTC.Nhom;
		gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + i + 2);
		cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
		TextColor(binh_thuong);
	}
}
void luu(TREE t,int data,SVdangky *p){
	if (data < t->LopTC.MALOPTC)
	{
		luu(t->pLeft, data,p);
	}
	else if (data > t->LopTC.MALOPTC)
	{
    	luu(t->pRight, data,p);
	}
	else // data == t->LopTC.MALOPTC
	{
		ThemDau(t->Dsdk,p);
	}
}

int kt_chontam(DsLopTC *chontam,int m,int maloptc){
	for(int i=0;i<m;i++){
		if(maloptc==chontam[i].LopTC.MALOPTC) return i;
	}
	return -1;
}
void Xoa_chon_tam(DsLopTC *&chontam,int &m, int maloptc)
{
    int i = kt_chontam(chontam,m,maloptc);
    for (int j=i+1; j <m; j++)
    chontam[j-1]=chontam[j];
	m--;
}

void xu_li_gdien_dky(int &row, int n, int m, char &phim, DsLopTC *tam, DsLopTC *chontam, int &xdinh_trai_phai, DsMonHoc dsmh){
	
	while(1){
		phim = getch();
		int row_truoc = row;
		if (phim == mui_ten_len){
			if(row == 0 && xdinh_trai_phai == 0){
				row = n;
			}
			else if(row == 0 && xdinh_trai_phai == 1){
				row = m;
			}
			else{
				row--;
			}
			if(xdinh_trai_phai == 0){
				int j=kt_mamh_trung(dsmh,tam[row_truoc].LopTC.MAMH);
				int CL=tam[row_truoc].LopTC.SvMax- Sinhvienconlai(tam[row_truoc].Dsdk);
		
				TextColor(an_thanh_sang);
				gotoxy(8 - strlen(tam[row_truoc].LopTC.MAMH)/2, 15 + row_truoc + 2);
				cout << tam[row_truoc].LopTC.MAMH;
				gotoxy(16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row_truoc + 2);
				cout << dsmh.Ds[j]->TENMH;
				gotoxy(16 + 33 + 4 - chuyen_int_string(tam[row_truoc].LopTC.Nhom).length()/2, 15 + row_truoc + 2);
				cout << tam[row_truoc].LopTC.Nhom;
				gotoxy(16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row_truoc + 2);
				cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
				gotoxy(16 + 33 + 8 + 8 + 5 - chuyen_int_string(tam[row_truoc].LopTC.MALOPTC).length()/2, 15 + row_truoc + 2);
				cout << tam[row_truoc].LopTC.MALOPTC;
				gotoxy(16 + 33 + 8 + 8 + 9 + 5 - chuyen_int_string(tam[row_truoc].LopTC.SvMax).length()/2, 15 + row_truoc + 2);
				cout << tam[row_truoc].LopTC.SvMax;
				gotoxy(16 + 33 + 8 + 8 + 9 + 9 + 5 - chuyen_int_string(CL).length()/2, 15 + row_truoc + 2);
				cout << CL;
				TextColor(binh_thuong);
				
				j=kt_mamh_trung(dsmh,tam[row].LopTC.MAMH);
				CL=tam[row].LopTC.SvMax- Sinhvienconlai(tam[row].Dsdk);
		
				TextColor(hien_thanh_sang);
				gotoxy(8 - strlen(tam[row].LopTC.MAMH)/2, 15 + row + 2);
				cout << tam[row].LopTC.MAMH;
				gotoxy(16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row + 2);
				cout << dsmh.Ds[j]->TENMH;
				gotoxy(16 + 33 + 4 - chuyen_int_string(tam[row].LopTC.Nhom).length()/2, 15 + row + 2);
				cout << tam[row].LopTC.Nhom;
				gotoxy(16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row + 2);
				cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
				gotoxy(16 + 33 + 8 + 8 + 5 - chuyen_int_string(tam[row].LopTC.MALOPTC).length()/2, 15 + row + 2);
				cout << tam[row].LopTC.MALOPTC;
				gotoxy(16 + 33 + 8 + 8 + 9 + 5 - chuyen_int_string(tam[row].LopTC.SvMax).length()/2, 15 + row + 2);
				cout << tam[row].LopTC.SvMax;
				gotoxy(16 + 33 + 8 + 8 + 9 + 9 + 5 - chuyen_int_string(CL).length()/2, 15 + row + 2);
				cout << CL;
				TextColor(binh_thuong);
			}
			if(xdinh_trai_phai == 1){
				int j=kt_mamh_trung(dsmh,chontam[row_truoc].LopTC.MAMH);
				int CL=chontam[row_truoc].LopTC.SvMax- Sinhvienconlai(chontam[row_truoc].Dsdk);

				TextColor(an_thanh_sang);
				gotoxy(168/2 + 10 + 1 + 3 - chuyen_int_string(row_truoc+1).length()/2, 15 + row_truoc + 2);
				cout << row_truoc + 1;
				gotoxy(168/2 + 10 + 6 + 9 - strlen(chontam[row_truoc].LopTC.MAMH)/2, 15 + row_truoc + 2);
				cout << chontam[row_truoc].LopTC.MAMH;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row_truoc + 2);
				cout << dsmh.Ds[j]->TENMH;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 4 - chuyen_int_string(chontam[row_truoc].LopTC.Nhom).length()/2, 15 + row_truoc + 2);
				cout << chontam[row_truoc].LopTC.Nhom;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row_truoc + 2);
				cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
				TextColor(binh_thuong);
				
				j=kt_mamh_trung(dsmh,chontam[row].LopTC.MAMH);
				CL=chontam[row].LopTC.SvMax- Sinhvienconlai(chontam[row].Dsdk);

				TextColor(hien_thanh_sang);
				gotoxy(168/2 + 10 + 1 + 3 - chuyen_int_string(row+1).length()/2, 15 + row + 2);
				cout << row + 1;
				gotoxy(168/2 + 10 + 6 + 9 - strlen(chontam[row].LopTC.MAMH)/2, 15 + row + 2);
				cout << chontam[row].LopTC.MAMH;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row + 2);
				cout << dsmh.Ds[j]->TENMH;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 4 - chuyen_int_string(chontam[row].LopTC.Nhom).length()/2, 15 + row + 2);
				cout << chontam[row].LopTC.Nhom;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row + 2);
				cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
				TextColor(binh_thuong);
			}
		}
		else if(phim == mui_ten_xuong){
			if(row == n && xdinh_trai_phai == 0){
				row = 0;
			}
			else if(row == m && xdinh_trai_phai == 1){
				row = 0;
			}
			else{
				row++;
			}
			if(xdinh_trai_phai == 0){
				int j=kt_mamh_trung(dsmh,tam[row_truoc].LopTC.MAMH);
				int CL=tam[row_truoc].LopTC.SvMax- Sinhvienconlai(tam[row_truoc].Dsdk);
		
				TextColor(an_thanh_sang);
				gotoxy(8 - strlen(tam[row_truoc].LopTC.MAMH)/2, 15 + row_truoc + 2);
				cout << tam[row_truoc].LopTC.MAMH;
				gotoxy(16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row_truoc + 2);
				cout << dsmh.Ds[j]->TENMH;
				gotoxy(16 + 33 + 4 - chuyen_int_string(tam[row_truoc].LopTC.Nhom).length()/2, 15 + row_truoc + 2);
				cout << tam[row_truoc].LopTC.Nhom;
				gotoxy(16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row_truoc + 2);
				cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
				gotoxy(16 + 33 + 8 + 8 + 5 - chuyen_int_string(tam[row_truoc].LopTC.MALOPTC).length()/2, 15 + row_truoc + 2);
				cout << tam[row_truoc].LopTC.MALOPTC;
				gotoxy(16 + 33 + 8 + 8 + 9 + 5 - chuyen_int_string(tam[row_truoc].LopTC.SvMax).length()/2, 15 + row_truoc + 2);
				cout << tam[row_truoc].LopTC.SvMax;
				gotoxy(16 + 33 + 8 + 8 + 9 + 9 + 5 - chuyen_int_string(CL).length()/2, 15 + row_truoc + 2);
				cout << CL;
				TextColor(binh_thuong);
				
				j=kt_mamh_trung(dsmh,tam[row].LopTC.MAMH);
				CL=tam[row].LopTC.SvMax- Sinhvienconlai(tam[row].Dsdk);
		
				TextColor(hien_thanh_sang);
				gotoxy(8 - strlen(tam[row].LopTC.MAMH)/2, 15 + row + 2);
				cout << tam[row].LopTC.MAMH;
				gotoxy(16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row + 2);
				cout << dsmh.Ds[j]->TENMH;
				gotoxy(16 + 33 + 4 - chuyen_int_string(tam[row].LopTC.Nhom).length()/2, 15 + row + 2);
				cout << tam[row].LopTC.Nhom;
				gotoxy(16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row + 2);
				cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
				gotoxy(16 + 33 + 8 + 8 + 5 - chuyen_int_string(tam[row].LopTC.MALOPTC).length()/2, 15 + row + 2);
				cout << tam[row].LopTC.MALOPTC;
				gotoxy(16 + 33 + 8 + 8 + 9 + 5 - chuyen_int_string(tam[row].LopTC.SvMax).length()/2, 15 + row + 2);
				cout << tam[row].LopTC.SvMax;
				gotoxy(16 + 33 + 8 + 8 + 9 + 9 + 5 - chuyen_int_string(CL).length()/2, 15 + row + 2);
				cout << CL;
				TextColor(binh_thuong);
			}
			if(xdinh_trai_phai == 1){
				int j=kt_mamh_trung(dsmh,chontam[row_truoc].LopTC.MAMH);
				int CL=chontam[row_truoc].LopTC.SvMax- Sinhvienconlai(chontam[row_truoc].Dsdk);

				TextColor(an_thanh_sang);
				gotoxy(168/2 + 10 + 1 + 3 - chuyen_int_string(row_truoc+1).length()/2, 15 + row_truoc + 2);
				cout << row_truoc + 1;
				gotoxy(168/2 + 10 + 6 + 9 - strlen(chontam[row_truoc].LopTC.MAMH)/2, 15 + row_truoc + 2);
				cout << chontam[row_truoc].LopTC.MAMH;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row_truoc + 2);
				cout << dsmh.Ds[j]->TENMH;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 4 - chuyen_int_string(chontam[row_truoc].LopTC.Nhom).length()/2, 15 + row_truoc + 2);
				cout << chontam[row_truoc].LopTC.Nhom;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row_truoc + 2);
				cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
				TextColor(binh_thuong);
				
				j=kt_mamh_trung(dsmh,chontam[row].LopTC.MAMH);
				CL=chontam[row].LopTC.SvMax- Sinhvienconlai(chontam[row].Dsdk);

				TextColor(hien_thanh_sang);
				gotoxy(168/2 + 10 + 1 + 3 - chuyen_int_string(row+1).length()/2, 15 + row + 2);
				cout << row + 1;
				gotoxy(168/2 + 10 + 6 + 9 - strlen(chontam[row].LopTC.MAMH)/2, 15 + row + 2);
				cout << chontam[row].LopTC.MAMH;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row + 2);
				cout << dsmh.Ds[j]->TENMH;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 4 - chuyen_int_string(chontam[row].LopTC.Nhom).length()/2, 15 + row + 2);
				cout << chontam[row].LopTC.Nhom;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row + 2);
				cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
				TextColor(binh_thuong);
			}
		}
		else if(phim == mui_ten_phai){
			phim = mui_ten_phai;
			if(xdinh_trai_phai == 0 && m >= 0){
				xdinh_trai_phai = 1;
				int j=kt_mamh_trung(dsmh,tam[row_truoc].LopTC.MAMH);
				int CL=tam[row_truoc].LopTC.SvMax- Sinhvienconlai(tam[row_truoc].Dsdk);
		
				TextColor(an_thanh_sang);
				gotoxy(8 - strlen(tam[row_truoc].LopTC.MAMH)/2, 15 + row_truoc + 2);
				cout << tam[row_truoc].LopTC.MAMH;
				gotoxy(16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row_truoc + 2);
				cout << dsmh.Ds[j]->TENMH;
				gotoxy(16 + 33 + 4 - chuyen_int_string(tam[row_truoc].LopTC.Nhom).length()/2, 15 + row_truoc + 2);
				cout << tam[row_truoc].LopTC.Nhom;
				gotoxy(16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row_truoc + 2);
				cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
				gotoxy(16 + 33 + 8 + 8 + 5 - chuyen_int_string(tam[row_truoc].LopTC.MALOPTC).length()/2, 15 + row_truoc + 2);
				cout << tam[row_truoc].LopTC.MALOPTC;
				gotoxy(16 + 33 + 8 + 8 + 9 + 5 - chuyen_int_string(tam[row_truoc].LopTC.SvMax).length()/2, 15 + row_truoc + 2);
				cout << tam[row_truoc].LopTC.SvMax;
				gotoxy(16 + 33 + 8 + 8 + 9 + 9 + 5 - chuyen_int_string(CL).length()/2, 15 + row_truoc + 2);
				cout << CL;
				TextColor(binh_thuong);
				
				row = 0;
				
				j=kt_mamh_trung(dsmh,chontam[row].LopTC.MAMH);
				CL=chontam[row].LopTC.SvMax- Sinhvienconlai(chontam[row].Dsdk);

				TextColor(hien_thanh_sang);
				gotoxy(168/2 + 10 + 1 + 3 - chuyen_int_string(row+1).length()/2, 15 + row + 2);
				cout << row + 1;
				gotoxy(168/2 + 10 + 6 + 9 - strlen(chontam[row].LopTC.MAMH)/2, 15 + row + 2);
				cout << chontam[row].LopTC.MAMH;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row + 2);
				cout << dsmh.Ds[j]->TENMH;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 4 - chuyen_int_string(chontam[row].LopTC.Nhom).length()/2, 15 + row + 2);
				cout << chontam[row].LopTC.Nhom;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row + 2);
				cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
				TextColor(binh_thuong);
			}
		}
		else if(phim == mui_ten_trai){
			phim = mui_ten_trai;
			if(xdinh_trai_phai == 1){
				xdinh_trai_phai = 0;
				int j=kt_mamh_trung(dsmh,chontam[row_truoc].LopTC.MAMH);
				int CL=chontam[row_truoc].LopTC.SvMax- Sinhvienconlai(chontam[row_truoc].Dsdk);

				TextColor(an_thanh_sang);
				gotoxy(168/2 + 10 + 1 + 3 - chuyen_int_string(row_truoc+1).length()/2, 15 + row_truoc + 2);
				cout << row_truoc + 1;
				gotoxy(168/2 + 10 + 6 + 9 - strlen(chontam[row_truoc].LopTC.MAMH)/2, 15 + row_truoc + 2);
				cout << chontam[row_truoc].LopTC.MAMH;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row_truoc + 2);
				cout << dsmh.Ds[j]->TENMH;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 4 - chuyen_int_string(chontam[row_truoc].LopTC.Nhom).length()/2, 15 + row_truoc + 2);
				cout << chontam[row_truoc].LopTC.Nhom;
				gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row_truoc + 2);
				cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
				TextColor(binh_thuong);
				
				row = 0;
				
				j=kt_mamh_trung(dsmh,tam[row].LopTC.MAMH);
				CL=tam[row].LopTC.SvMax- Sinhvienconlai(tam[row].Dsdk);
		
				TextColor(hien_thanh_sang);
				gotoxy(8 - strlen(tam[row].LopTC.MAMH)/2, 15 + row + 2);
				cout << tam[row].LopTC.MAMH;
				gotoxy(16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row + 2);
				cout << dsmh.Ds[j]->TENMH;
				gotoxy(16 + 33 + 4 - chuyen_int_string(tam[row].LopTC.Nhom).length()/2, 15 + row + 2);
				cout << tam[row].LopTC.Nhom;
				gotoxy(16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row + 2);
				cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
				gotoxy(16 + 33 + 8 + 8 + 5 - chuyen_int_string(tam[row].LopTC.MALOPTC).length()/2, 15 + row + 2);
				cout << tam[row].LopTC.MALOPTC;
				gotoxy(16 + 33 + 8 + 8 + 9 + 5 - chuyen_int_string(tam[row].LopTC.SvMax).length()/2, 15 + row + 2);
				cout << tam[row].LopTC.SvMax;
				gotoxy(16 + 33 + 8 + 8 + 9 + 9 + 5 - chuyen_int_string(CL).length()/2, 15 + row + 2);
				cout << CL;
				TextColor(binh_thuong);
			}
		}
		else if (phim == esc){
			phim = esc;
		}
		else if (phim == F1){
			phim = F1;
			//luu
		}
		break;
	}
}

void cau_Dangky(TREE t,DanhsachSV *Dssv,DsMonHoc dsmh, string masv, string nk, string hki){
	int hk = atoi(hki.c_str());
	int n=0;
	DsLopTC *tam=new DsLopTC[cau_j];
	bool kt=false;
	saochep(t,nk,hk,n,tam,kt);
	if(kt==false){
		gotoxy(168/2 - 33, 9);
		TextColor(noi_bat);
		cout << "KHONG TIM THAY LTC PHU HOP, ENTER TIEP TUC";
		TextColor(binh_thuong);
		getch();
	}
	else{
		gotoxy(168/2 - 33, 9);
		TextColor(noi_bat);
		cout << "ESC: THOAT, ENTER: CHON, F1: LUU";
		TextColor(binh_thuong);
		DsLopTC *chontam=new DsLopTC[n];
		int m=0;
		char phim;
		int row = 0;
		int xdinh_trai_phai = 0;
		xuat_bang_ben_trai(tam,n,dsmh);
		while(1){
			if(xdinh_trai_phai == 0){
				gotoxy(168 / 2 + 3, 17 + row);
				xu_li_gdien_dky(row, n - 1, m - 1, phim, tam, chontam, xdinh_trai_phai, dsmh);
			}
			else{
				gotoxy(168 - 6, 17 + row);
				xu_li_gdien_dky(row, n - 1, m - 1, phim, tam, chontam, xdinh_trai_phai, dsmh);
			}
			if(phim == enter){
				if(xdinh_trai_phai == 0){
					dk(tam,n,tam[row].LopTC.MALOPTC,chontam,m);
				   xuat_bang_ben_phai(chontam,m,dsmh);
				}
				else if(xdinh_trai_phai == 1){
					clear_Area(168/2 + 10, 11, 167, rong_khung_danh_sach);
					tao_khung_dang_ky(2);
					Xoa_chon_tam(chontam, m, chontam[row].LopTC.MALOPTC);
					row = 0;
					if(m > 0){
						xuat_bang_ben_phai(chontam, m, dsmh);
						int j=kt_mamh_trung(dsmh,chontam[row].LopTC.MAMH);
					int CL=chontam[row].LopTC.SvMax- Sinhvienconlai(chontam[row].Dsdk);

						TextColor(hien_thanh_sang);
						gotoxy(168/2 + 10 + 1 + 3 - chuyen_int_string(row+1).length()/2, 15 + row + 2);
						cout << row + 1;
						gotoxy(168/2 + 10 + 6 + 9 - strlen(chontam[row].LopTC.MAMH)/2, 15 + row + 2);
						cout << chontam[row].LopTC.MAMH;
						gotoxy(168/2 + 10 + 1 + 6 + 16 + 17 - dsmh.Ds[j]->TENMH.length()/2, 15 + row + 2);
						cout << dsmh.Ds[j]->TENMH;
						gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 4 - chuyen_int_string(chontam[row].LopTC.Nhom).length()/2, 15 + row + 2);
						cout << chontam[row].LopTC.Nhom;
						gotoxy(168/2 + 10 + 1 + 6 + 16 + 33 + 8 + 4 - chuyen_float_string(dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH).length()/2, 15 + row + 2);
						cout << dsmh.Ds[j]->STCLT+dsmh.Ds[j]->STCTH;
						TextColor(binh_thuong);
					}
					else{
						xdinh_trai_phai = 0;
						xuat_bang_ben_trai(tam, n, dsmh);
					}
				}
			}
			else if(phim == F1){
				bool kt=false;
			    for(int i=0;i<m;i++){
			    	bool ktsv=false;
			    	kt_sv_trong_dsdk(chontam[i].Dsdk,ktsv,masv);
			    	if(ktsv==false){
			    	kt=true;
		   		 	SVdangky *p=khoi_tao_node_SVdangky();
		    		p->Diem=0;
		    		strcpy(p->MASV,masv.c_str());
		    		luu(t,chontam[i].LopTC.MALOPTC,p);
		    	   }
				}
				if(kt==true){
					ofstream fileout;
	        		fileout.open("dsdk.txt", ios_base::out);
					ghi_het_dsdk(t,fileout);
					fileout.close();
				}
				clear_Area(0, 11, 168, rong_khung_danh_sach);
				break;		
			}
			else if(phim == esc){
				clear_Area(0, 11, 168, rong_khung_danh_sach);
				break;
			}
	}
	gotoxy(168/2 - 33, 9);
	cout << "                                              ";
	delete[] chontam;
  }
  delete[] tam;
}

void xu_li_dang_ky(TREE t, DanhsachSV *dssv, DsMonHoc dsmh, string masv){
	string s[2];
	int row = 0;
	char phim;
	while(1){
		if(s[0].length() == 0 || s[1].length() == 0){
			gotoxy(168/2 - 33, 9);
			cout << "                                          ";
			gotoxy(168/2 - 33, 9);
			TextColor(noi_bat);
			cout << "THIEU THUOC TINH";
			TextColor(binh_thuong);
		}
		else{
			TextColor(noi_bat);
			gotoxy(168/2 - 33, 9);
			cout << "                                          ";
			gotoxy(168/2 - 33, 9);
			cout << "F1 DE VAO DANG KI";
			TextColor(binh_thuong);
		}
		nhap_dki(s[row], phim, row);
		if (phim == mui_ten_len || phim == mui_ten_xuong || phim == enter){
			row = abs(row - 1);
		}
		else if (phim == esc){
			clrscr();
			Tao_khung_menu_main_sv();
			break;
		}
		else if (phim == F1){
			if(s[0].length() != 0 && s[1].length() != 0){
				cau_Dangky(t, dssv, dsmh, masv, s[0], s[1]);
				s[0] = s[1] = "";
				gotoxy(168 / 2 - 23, 5);
				cout << "                                                        ";
				gotoxy(168 / 2 - 23, 7);
				cout << "                                                        ";
				tao_khung_dang_ky(1);
				tao_khung_dang_ky(2);
			}
		}
	}
}

//////////////////////////////////////////
//MAIN + BLA...BLA...:

void init(){
	chuc_nang[0] = "Mo lop tin chi";
	chuc_nang[1] = "In danh sach sv dki lop tin chi";
	chuc_nang[2] = "Cap nhat sinh vien cua lop";
	chuc_nang[3] = "In danh sach sv cua 1 lop";
	chuc_nang[4] = "Cap nhat mon hoc";
	chuc_nang[5] = "In danh sach mon hoc";
	chuc_nang[6] = "Nhap diem";
	chuc_nang[7] = "In bang diem";
	chuc_nang[8] = "In bang diem trung binh ket thuc khoa hoc";
	chuc_nang[9] = "Exit";
	chuc_nang[10] = "Dang ky lop tin chi";
	int so_ki_tu = dai_khung_main - 3; // 2 ki tu la khung 1 ki tu la dau "."
	int length_cua_stt_chuc_nang = 1;
	for (int i = 0; i< so_chuc_nang; i++){
		if(i+1 == pow(10, length_cua_stt_chuc_nang)){
			length_cua_stt_chuc_nang++;
		}
		if(chuc_nang[i].length() + length_cua_stt_chuc_nang < so_ki_tu){
			chuc_nang[i] = chuoi_voi_n_ki_tu(chuc_nang[i], so_ki_tu - length_cua_stt_chuc_nang);
		}
	}
	
	arr[0] = "Them";
	arr[1] = "Xoa";
	arr[2] = "Hieu chinh";
	so_ki_tu = dai_khung_chuc_nang - 3; // 2 ki tu la khung 1 ki tu la dau "."
	length_cua_stt_chuc_nang = 1;
	for (int i = 0; i< so_chuc_nang_con; i++){
		if(i+1 == pow(10, length_cua_stt_chuc_nang)){
			length_cua_stt_chuc_nang++;
		}
		if(arr[i].length() + length_cua_stt_chuc_nang < so_ki_tu){
			arr[i] = chuoi_voi_n_ki_tu(arr[i], so_ki_tu - length_cua_stt_chuc_nang);
		}
	}
	
	thuoc_tinh_LTC[0][0] = "MALTC";
	thuoc_tinh_LTC[1][0] = "MAMH";
	thuoc_tinh_LTC[2][0] = "Nien khoa";
	thuoc_tinh_LTC[3][0] = "Hoc ki";
	thuoc_tinh_LTC[4][0] = "So sv min";
	thuoc_tinh_LTC[5][0] = "So sv max";
	thuoc_tinh_LTC[6][0] = "Nhom";
	
	thuoc_tinh_sv[0][0] = "MA LOP";
	thuoc_tinh_sv[1][0] = "MA SV";
	thuoc_tinh_sv[2][0] = "NAMNHAPHOC";
	thuoc_tinh_sv[3][0] = "PHAI";
	thuoc_tinh_sv[4][0] = "HO";
	thuoc_tinh_sv[5][0] = "TEN";
	thuoc_tinh_sv[6][0] = "SODT";

	thuoc_tinh_mon_hoc[0][0] = "MAMH";
	thuoc_tinh_mon_hoc[1][0] = "TENMH";
	thuoc_tinh_mon_hoc[2][0] = "SLTCLT";
	thuoc_tinh_mon_hoc[3][0] = "SLTCTH";
}

void resizeConsole(int width, int height){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void xu_li_menu_chuc_nang(int chuc_nang_duoc_chon, TREE &t, DanhsachSV *&dssv, DanhsachSV *&pTail, DsMonHoc &dsmh){
	int row = 0;
	if(chuc_nang_duoc_chon == 0){
		xuat_ds_lop_tc(t, row);
	}
	if(chuc_nang_duoc_chon == 4){
		xuat_mon_hoc(dsmh);
	}
	int chon_them_xoa_sua = 0;
	
	char key_chuc_nang;
	while (1){
		key_chuc_nang = getch();
		if(key_chuc_nang == mui_ten_len){
			gotoxy(1, ngang_chuc_nang + 2 + chon_them_xoa_sua * 2 - 1);
			TextColor(an_thanh_sang);
			cout << chon_them_xoa_sua + 1 << "." << arr[chon_them_xoa_sua];
			if(chon_them_xoa_sua == 0){
				chon_them_xoa_sua = (chon_them_xoa_sua - 1 + (so_chuc_nang_con + 1)) % (so_chuc_nang_con + 1) - 1;
			}
			else{
				chon_them_xoa_sua = chon_them_xoa_sua - 1;
			}
			gotoxy(1, ngang_chuc_nang + 2 + chon_them_xoa_sua * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << chon_them_xoa_sua + 1 << "." << arr[chon_them_xoa_sua];
		}
		
		if(key_chuc_nang == mui_ten_xuong){
			gotoxy(1, ngang_chuc_nang + 2 + chon_them_xoa_sua * 2 - 1);
			TextColor(an_thanh_sang);
			cout << chon_them_xoa_sua + 1 << "." << arr[chon_them_xoa_sua];
			if(chon_them_xoa_sua == so_chuc_nang_con - 1){
				chon_them_xoa_sua = 0;
			}
			else{
				chon_them_xoa_sua = chon_them_xoa_sua + 1;
			}
			gotoxy(1, ngang_chuc_nang + 2 + chon_them_xoa_sua * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << chon_them_xoa_sua + 1 << "." << arr[chon_them_xoa_sua];
		}
		
		if(key_chuc_nang == enter){
			
			if(chon_them_xoa_sua == 0){
				if(chuc_nang_duoc_chon == 0){
					thuoc_tinh_LTC[0][1] = chuyen_int_string(tao_ma_loptc(t));
					gotoxy(doc_chuc_nang_them0 + 1, rong_khung_chuc_nang + 2 + 5);
					TextColor(noi_bat);
					cout << thuoc_tinh_LTC[0][1];
					nhap_Lop_TC(t, dsmh);
					row = 0;
					xuat_ds_lop_tc(t, row);
				}
				else if(chuc_nang_duoc_chon == 2){
					tao_khung_them1_SV();
					thuoc_tinh_sv[0][1] = "";
					them_SinhVien(dssv, pTail);
					clear_Area(dai_khung_chuc_nang + 2, 0, dai_khung_chuc_nang + 2 + dai_khung_danh_sach, rong_khung_danh_sach);
					show_danh_sach(2);
				}
				else if(chuc_nang_duoc_chon == 4){
					tao_khung_them_or_sua2_MH(0);
					Them_mon_hoc(dsmh);
					xuat_mon_hoc(dsmh);
				}
			}
			if(chon_them_xoa_sua == 1){
				if(chuc_nang_duoc_chon == 0){
					xu_li_xoa_LTC(t);
					row = 0;
					xuat_ds_lop_tc(t, row);
				}
				else if(chuc_nang_duoc_chon == 2){
					xu_li_xoa_SV(dssv, pTail, t);
					clear_Area(dai_khung_chuc_nang + 2, 0, dai_khung_chuc_nang + 2 + dai_khung_danh_sach, rong_khung_danh_sach);
					show_danh_sach(2);
				}
				else if(chuc_nang_duoc_chon == 4){
					xu_li_xoa_MH(dsmh, t);
					xuat_mon_hoc(dsmh);
				}
			}
			if(chon_them_xoa_sua == 2){
				if(chuc_nang_duoc_chon == 0){
					xu_li_sua_LTC(t, dsmh);
					row = 0;
					xuat_ds_lop_tc(t, row);
					tao_khung_menu_chuc_nang(0);
				}
				else if(chuc_nang_duoc_chon == 2){
					xu_li_sua_SV(dssv, pTail, t);
					clear_Area(dai_khung_chuc_nang + 2, 0, dai_khung_chuc_nang + 2 + dai_khung_danh_sach, rong_khung_danh_sach);
					show_danh_sach(2);
					tao_khung_menu_chuc_nang(2);
				}
				else if(chuc_nang_duoc_chon == 4){
					xu_li_sua_MH(dsmh, t);
					xuat_mon_hoc(dsmh);
					tao_khung_menu_chuc_nang(4);
				}
				chon_them_xoa_sua = 0;
			}
		}
		if(key_chuc_nang == esc){
			gotoxy(0,0);
			system(ma_system);
			clrscr();
			Tao_khung_menu_main();
			break;
		}
	}
}

void xu_li_in_danh_sach(int chuc_nang_duoc_chon, TREE &t, DanhsachSV *dssv, DanhsachSV *pTail){
//	gotoxy(0,0);
//	cout << "DA VAO CHUC NANG IN DANH SACH" << endl;
//	cout << "NHAN ESC DE THOAT";
	if(chuc_nang_duoc_chon == 1){
		gotoxy(0,0);
		tao_khung_chuc_nang_2();
		int row = 0;
		xuat_goi_y_ds_lop_tc(t, row, 1);
		xu_li_in_dsach_sv_ltc(t);
	}
	else if(chuc_nang_duoc_chon == 3){
		tao_khung_chuc_nang_4();
		xuat_goi_y_chuc_nang_4(dssv);
		xu_li_in_dsach_sv_lop(dssv, pTail);
	}
	else{
//		xu_li_xoa(chuc_nang_duoc_chon, t);
		clrscr();
		Tao_khung_menu_main();
	}
}

void chon_chuc_nang(int lua_chon, TREE &t, DanhsachSV *&dssv, DanhsachSV *pTail, DsMonHoc &dsmh){
	// them xoa sua
	if((lua_chon == 0) || (lua_chon == 2) || (lua_chon == 4)){
		show_danh_sach(lua_chon);
		tao_khung_menu_chuc_nang(lua_chon);
		xu_li_menu_chuc_nang(lua_chon, t, dssv, pTail, dsmh);
	}
	// in danh sach sv cua ltc, sv cua lop
	if((lua_chon == 1) || (lua_chon == 3)){
		tao_khung_in_danh_sach(lua_chon);
		xu_li_in_danh_sach(lua_chon, t, dssv, pTail);
	}
	//in danh sach mon hoc
	if(lua_chon == 5){
		tao_khung_in_danh_sach(lua_chon);
		cau_f(dsmh);
		getch();
		clrscr();
		Tao_khung_menu_main();
	}
	// in bang diem
	if(lua_chon == 7){
		tao_khung_chuc_nang_8(0);
		tao_khung_chuc_nang_8(1);
		tao_khung_chuc_nang_8(2);
		tao_khung_chuc_nang_8(3);
		tao_khung_chuc_nang_8(4);
		xu_li_in_diem(t, dssv, pTail, dsmh);
	}
	if(lua_chon == 8){
		tao_khung_chuc_nang_9(0);
		tao_khung_chuc_nang_9(1);
		tao_khung_chuc_nang_9(2);
		tao_khung_chuc_nang_9(3);
		tao_khung_chuc_nang_9(4);
		xu_li_in_diem_tb(dssv, pTail, t, dsmh);
	}
	//nhap diem
	if(lua_chon == 6){
		tao_khung_chuc_nang_7(0);
		tao_khung_chuc_nang_7(1);
		tao_khung_chuc_nang_7(2);
		tao_khung_chuc_nang_7(3);
		tao_khung_chuc_nang_7(4);
		xu_li_nhap_diem(t, dssv, pTail, dsmh);
	}
}

void xu_li_menu_main(TREE &t, DanhsachSV *&dssv, DanhsachSV *&pTail, DsMonHoc &dsmh){
	int chon = 0;
	char key;
	while (1){
		key = getch();
		if(key == mui_ten_len){
			gotoxy(1, ngang_main + 2 + chon * 2 - 1);
			TextColor(an_thanh_sang);
			cout << chon + 1 << "." << chuc_nang[chon];
			if(chon == 0){
				chon = (chon - 1 + (so_chuc_nang + 1)) % (so_chuc_nang + 1) - 2;
			}
			else{
				chon = chon - 1;
			}
			gotoxy(1, ngang_main + 2 + chon * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << chon + 1 << "." << chuc_nang[chon];
		}
		
		if(key == mui_ten_xuong){
			gotoxy(1, ngang_main + 2 + chon * 2 - 1);
			TextColor(an_thanh_sang);
			cout << chon + 1 << "." << chuc_nang[chon];
			if(chon == so_chuc_nang - 2){
				chon = 0;
			}
			else{
				chon = chon + 1;
			}
			gotoxy(1, ngang_main + 2 + chon * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << chon + 1 << "." << chuc_nang[chon];
		}
		
		if(key == enter){
			clrscr();
			system(ma_system);	
			gotoxy(0,0);
			//thoat
			if(chon == 9){	
				break;
			}
			else{
				chon_chuc_nang(chon, t, dssv, pTail, dsmh);
				chon = 0;
			}
		}
		if(key == esc){
			clrscr();
			system(ma_system);	
			gotoxy(0,0);
			//thoat
			break;
		}
	}
}

void xu_li_menu_sv(TREE t, DanhsachSV *dssv, DanhsachSV *pTail, DsMonHoc &dsmh,string &masv){
	int chon = so_chuc_nang - 1;
	char key;
	while (1){
		key = getch();
		if(key == mui_ten_len){
			gotoxy(1, ngang_main + 2 + abs(so_chuc_nang - chon - 1) * 2 - 1);
			TextColor(an_thanh_sang);
			cout << abs(so_chuc_nang - chon) << "." << chuc_nang[chon] + " ";
			if(chon == so_chuc_nang - 1){
				chon = so_chuc_nang - 2;
			}
			else{
				chon = so_chuc_nang - 1;
			}
			gotoxy(1, ngang_main + 2 + abs(so_chuc_nang - chon - 1) * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << abs(so_chuc_nang - chon) << "." << chuc_nang[chon] + " ";
		}
		
		if(key == mui_ten_xuong){
			gotoxy(1, ngang_main + 2 + abs(so_chuc_nang - chon - 1) * 2 - 1);
			TextColor(an_thanh_sang);
			cout << abs(so_chuc_nang - chon) << "." << chuc_nang[chon] + " ";
			if(chon == so_chuc_nang - 2){
				chon = so_chuc_nang - 1;
			}
			else{
				chon = so_chuc_nang - 2;
			}
			gotoxy(1, ngang_main + 2 + abs(so_chuc_nang - chon - 1) * 2 - 1);
			TextColor(hien_thanh_sang);
			cout << abs(so_chuc_nang - chon) << "." << chuc_nang[chon] + " ";
		}
		
		if(key == enter){
			clrscr();
			system(ma_system);	
			gotoxy(0,0);
			//thoat
			if(chon == 9){	
				break;
			}
			else{
				clrscr();
				tao_khung_dang_ky(0);
				tao_khung_dang_ky(1);
				tao_khung_dang_ky(2);
				xu_li_dang_ky(t, dssv, dsmh, masv);
			}
		}
		if(key == esc){
			clrscr();
			system(ma_system);	
			gotoxy(0,0);
			//thoat
			break;
		}
	}
}

void tao_khung_dang_nhap(){
	//cot max 168
	int x0 = 168 / 2 - 34;
	int y0 = 5;
	gotoxy(x0, y0);
	
	for (int i = 0; i < 68; i++){
		gotoxy(x0 + i, y0);
		cout << char(khung_ngoai);
		gotoxy(x0 + i, y0 + 10);
		cout << char(khung_ngoai);
		gotoxy(x0 + i, y0 + 4);
		cout << char(khung_ngoai);
		gotoxy(x0 + i, y0 + 8);
		cout << char(khung_ngoai);
		gotoxy(x0 + i, y0 + 6);
		cout << char(khung_trong);
	}
	
	for (int i = 0; i < 10; i++){
		gotoxy(x0, y0 + i);
		cout << char(khung_ngoai);
		gotoxy(x0 + 67, y0 + i);
		cout << char(khung_ngoai);
	}
	
	for (int i = 5; i < 9; i++){
		gotoxy(x0 + 10, y0 + i);
		cout << char(khung_ngoai);
	}
	
	gotoxy(x0 + 34 - 5, y0 + 2);
	TextColor(noi_bat);
	cout << "DANG  NHAP";
	
	gotoxy(x0 + 1, y0 + 5);
	cout << "TAI KHOAN";
	gotoxy(x0 + 1, y0 + 7);
	cout << "PASSWORD";
}

void nhap_login(string &tai_khoan, string &pass){
	int x0 = 168 / 2 - 34;
	int y0 = 5;
	gotoxy(x0 + 11, y0 + 5);
	
	string o_nhap[2];
	int o_duoc_nhap = 0;
	string xoa = "";
	xoa = chuoi_voi_n_ki_tu(xoa, 56);
	char key_nhap;
	while (1){
		key_nhap = getch();
		if(key_nhap == -32){
			//truong hop la cac phim mui ten
			key_nhap = getch();
			if((key_nhap == mui_ten_len) || (key_nhap == mui_ten_xuong)){
				o_duoc_nhap = abs(1 - o_duoc_nhap);
				gotoxy(x0 + 11 + o_nhap[o_duoc_nhap].length(), y0 + 5 + o_duoc_nhap * 2);
			}
		}
		else if(key_nhap == enter){
			if((o_nhap[0].length() > 0) && (o_nhap[1].length() > 0)){
				tai_khoan = o_nhap[0];
				pass = o_nhap[1];
				break;
			}
			else{
				o_duoc_nhap = abs(1 - o_duoc_nhap);
				gotoxy(x0 + 11 + o_nhap[o_duoc_nhap].length(), y0 + 5 + o_duoc_nhap * 2);
			}
		}
		else if (key_nhap == esc){
			break;
		}
		else{
			if(key_nhap == backspace){
				o_nhap[o_duoc_nhap] = o_nhap[o_duoc_nhap].substr(0, o_nhap[o_duoc_nhap].length() - 1);
			}
			else{
				if(o_duoc_nhap == 0){
					rang_buoc_chuoi(o_nhap[o_duoc_nhap], key_nhap, chi_so_va_chu_in_hoa);
				}
				else{
					rang_buoc_chuoi(o_nhap[o_duoc_nhap], key_nhap, password);
				}
			}
			TextColor(binh_thuong);
			gotoxy(x0 + 11, y0 + 5 + o_duoc_nhap * 2);
			cout << xoa;
			TextColor(noi_bat);
			gotoxy(x0 + 11, y0 + 5 + o_duoc_nhap * 2);
			if(o_duoc_nhap == 1){
				string cover_pass = "******";
				cover_pass = cover_pass.substr(0,o_nhap[1].length());
				cout << cover_pass;
			}
			else{
				cout << o_nhap[o_duoc_nhap];
			}
			TextColor(binh_thuong);
		}
	}
}

void xu_li_login(string &xdinh, DanhsachSV *dssv, DanhsachSV *pTail){
	int x0 = 168 / 2 - 34;
	int y0 = 5;
	
	string tk, mk, file_sv_or_gv;
	
	gotoxy(x0 + 1, y0 + 9);
	cout << "Xin moi dang nhap!!!";
	
//	gotoxy(0,0);
//	cout << data;
	int kt = 0;
	
	while(kt == 0){
		nhap_login(tk, mk);
//		gotoxy(0,0);
		if((tk == "ADMIN") && (mk == "ADMIN")){
			kt = 1;
			xdinh = "GV";
			clrscr();
		}
		else{
			DanhsachSV *Node_ktra = kt_masv_trung(dssv, pTail, tk);

			if(stricmp(Node_ktra->SV.MASV, tk.c_str()) == 0 && stricmp(Node_ktra->SV.pass.c_str(), mk.c_str()) == 0){
					xdinh = tk;
					kt = 1;
					clrscr();
					break;
			}
		}
		
		if(tk.length() + mk.length() == 0){
			break;
		}
		
		if(kt == 0){
			gotoxy(x0 + 1, y0 + 9);
			TextColor(noi_bat);
			cout << "TaiKhoan hoac Password sai, enter de nhap lai, esc de thoat!!!";
			TextColor(binh_thuong);
			gotoxy(x0 + 11, y0 + 5);
			char phim = getch();
			if(phim == esc){
				clrscr();
				break;
			}
			else{
				while (phim != enter){
					phim = getch();
					if(phim == esc){
						clrscr();
						kt = 1;
						break;
					}
				}
				gotoxy(x0 + 1, y0 + 9);
				cout << "                                                               ";
				gotoxy(x0 + 1, y0 + 9);
				TextColor(noi_bat);
				cout << "Xin moi dang nhap!!!";
				TextColor(binh_thuong);
				tk = "";
				mk = "";
				gotoxy(x0 + 11, y0 + 5);
				cout << "                                                        ";
				gotoxy(x0 + 11, y0 + 7);
				cout << "      ";
			}
		}
	}
}
void freeTree(TREE &t)
{
	if(t==NULL) return; 
    freeTree(t->pLeft);  
    freeTree(t->pRight);
    free(t);
}
void Giai_Phong_Danh_Sach(DanhsachSV *&dssv)
{
	DanhsachSV *k = NULL;
	while (dssv != NULL)
	{
		k = dssv;
		dssv = dssv->NEXT;
		delete k;
	}
}
void Giai_phong_svdk(SVdangky *&ds){
	SVdangky *k=NULL;
	while (ds!= NULL)
	{
		k = ds;
		ds = ds->next;
		delete k;
	}
}
void Giai_phong_dssvdk(TREE &t){
	if(t!=NULL){
		Giai_phong_svdk(t->Dsdk);
		Giai_phong_dssvdk(t->pLeft);
		Giai_phong_dssvdk(t->pRight);
	}
}
void Giai_phong_mang_con_tro(DsMonHoc &dsmh){
	for(int i=0;i<dsmh.n;i++){
		delete dsmh.Ds[i];
	}
}
void Giai_phong_tong(DsMonHoc &dsmh,DanhsachSV *&dssv,TREE &t){
	Giai_phong_dssvdk(t);
	freeTree(t);
	Giai_Phong_Danh_Sach(dssv);
	Giai_phong_mang_con_tro(dsmh);
}
int main(){
	resizeConsole(dai_console, rong_console);
	init();
	system(ma_system);	
	tao_khung_dang_nhap();
	
	srand(time(NULL));
	
	TREE t=NULL;
	DsMonHoc dsmh;
	DanhsachSV *dssv=NULL;DanhsachSV *pTail = NULL;
	ifstream filein;
	filein.open("dsmh.txt", ios_base::in);
	    if (filein.fail() == true)
	    {
		    cout << "\nFile cua ban khong ton tai";
	    }
		Doc_file_dsmh(filein, dsmh);
    filein.close();
		
	filein.open("dssv.txt", ios_base::in);
   		if (filein.fail() == true)
		{
			cout << "\nFile cua ban khong ton tai";
		}
		doc_dssv(dssv,pTail,filein);
	filein.close();
		
	filein.open("ds_loptc.txt", ios_base::in);
	    if (filein.fail() == true)
	    {
		    cout << "\nFile cua ban khong ton tai";
	    }
        Doc_file_ds_loptc(t,filein);
    filein.close();
        
    filein.open("dsdk.txt", ios_base::in);
	    if (filein.fail() == true)
	    {
		    cout << "\nFile cua ban khong ton tai";
	    }
		Doc_file_dsdk(t,filein);
	filein.close();
	    string sv_or_gv;
        xu_li_login(sv_or_gv, dssv, pTail);
        
		if (sv_or_gv == "GV"){
			gotoxy(0,0);
			Tao_khung_menu_main();
			xu_li_menu_main(t, dssv, pTail, dsmh);
		}
		else if(sv_or_gv != "GV" && sv_or_gv.length() != 0){
			Tao_khung_menu_main_sv();
			xu_li_menu_sv(t, dssv, pTail, dsmh,sv_or_gv);
		}
	Giai_phong_tong(dsmh,dssv,t);	
	gotoxy(0,0);
	return 0;
}
