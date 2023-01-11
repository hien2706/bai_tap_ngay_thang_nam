#include <iostream>
#include <cmath>
using namespace std;
struct DATE
{
	int d;
	int m;
	int y;
};
void input(DATE& date);
bool kt_nam_nhuan(int year);
void output(DATE date);
string xuat_thu_trong_tuan(int day, int month, int year);
DATE tim_ngay_ke_tiep(DATE date);
int tim_khoang_cach_so_voi_0_0_0(DATE date);
int tinh_khoang_cach_giua_2_ngay(DATE date1, DATE date2);
int tim_so_ngay_trong_thang(DATE date);
void xuat_ra_lich_thang(DATE date);

int main()
{
	DATE date{}, date1{}, date2{};
	cout << endl << "B1 + B2 + B3 " << endl; // B1+2+3
	input(date);
	output(date);

	cout << endl << xuat_thu_trong_tuan(date.d, date.m, date.y) << endl;

	cout << "ngay tiep theo: ";
	output(tim_ngay_ke_tiep(date)); cout << endl;

	cout << endl << "B4: " << endl; // B4

	cout << "Nhap 2 ngay de tinh khoang cach: " << endl;
	cout << "Ngay 1: " << endl; input(date1); output(date1);
	cout << endl << "ngay 2: " << endl; input(date2); output(date2);
	cout << endl << "Khoang cach giua 2 ngay: " << tinh_khoang_cach_giua_2_ngay(date1, date2);

	cout << endl << "B5: " << endl; // B5

	DATE date_j_j_do{};
	xuat_ra_lich_thang(date_j_j_do);

	return 0;
}
bool kt_nam_nhuan(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	return false;
}
void input(DATE& date)
{
	do {
		cout << "Nhap nam: "; cin >> date.y;
	} while (date.y < 0 && cout << "khong hop le, nhap lai" << endl);
	do
	{
		cout << "Nhap thang: "; cin >> date.m;
	} while (date.m < 1 || date.m > 12 && cout << "khong hop le, nhap lai" << endl);

	switch (date.m) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		do {
			cout << "Nhap ngay: "; cin >> date.d;

		} while (date.d < 1 || date.d > 31 && cout << "khong hop le, nhap lai" << endl);

		break;
	case 4:
	case 6:
	case 9:
	case 11:
		do {
			cout << "Nhap ngay: "; cin >> date.d;

		} while (date.d < 1 || date.d > 30 && cout << "khong hop le, nhap lai" << endl);
		break;
	case 2:
		if (kt_nam_nhuan(date.y))
		{
			do {
				cout << "Nhap ngay: "; cin >> date.d;

			} while (date.d < 1 || date.d > 29 && cout << "khong hop le, nhap lai" << endl);
		}
		else
		{
			do {
				cout << "Nhap ngay: "; cin >> date.d;

			} while (date.d < 1 || date.d > 28 && cout << "khong hop le, nhap lai" << endl);
		}
	}
}
void output(DATE date)
{
	cout << date.d << "/" << date.m << "/" << date.y;
}
//Bai 2:
string xuat_thu_trong_tuan(int day, int month, int year)
{
	//Julian day calculation
	int i = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) +
		(365 * (year + 4800 - ((14 - month) / 12))) +
		((year + 4800 - ((14 - month) / 12)) / 4) -
		((year + 4800 - ((14 - month) / 12)) / 100) +
		((year + 4800 - ((14 - month) / 12)) / 400) - 32045) % 7;
	string thu[7]{ "thu 2","thu 3","thu 4", " thu 5","thu 6","thu 7", "chu nhat" };
	return thu[i];

}
DATE tim_ngay_ke_tiep(DATE date)
{
    switch (date.m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
		if (date.d < 31 && date.d >= 1)
			date.d += 1;

		else if (date.d == 31)
		{
			date.d = 1;
			date.m += 1;
		}
        break;
    case 12:
        if (date.d < 31 && date.d >= 1)
		{
			date.d += 1;
		}

        else if (date.d == 31)
		{
			date.d = 1;
			date.m = 1;
			date.y += 1;
		}
        break;

    case 2:
		if (kt_nam_nhuan(date.y))
        {
            if (date.d < 29 && date.d >= 1)
			{
				date.d += 1;
			}

            else if (date.d == 29)
			{
				date.d = 1;
				date.m += 1;
			}
        }
        else
        {
            if (date.d < 28 && date.d >= 1)
			{
				date.d += 1;
			}

            else if (date.d == 28)
			{
				date.d = 1;
				date.m += 1;
			}
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (date.d < 30 && date.d >= 1)
        {
			date.d += 1;
        }
        else if (date.d == 30)
        {
			date.d = 1;
			date.m += 1;
        }
    }
	return date;
}

int tim_khoang_cach_so_voi_0_0_0(DATE date)
{
	if (date.m < 3)
	{
		date.y--;
		date.m += 12;
	}
	return 365 * date.y + date.y / 4 - date.y / 100 + date.y / 400 + (153 * date.m - 457) / 5 + date.d - 306;
}
int tinh_khoang_cach_giua_2_ngay(DATE date1, DATE date2)
{
	int d1{}, d2{}; //d1,d2 la khoang cach cua date1, date2 so voi 0/0/0;
	int khoang_cach = abs(tim_khoang_cach_so_voi_0_0_0(date1) - tim_khoang_cach_so_voi_0_0_0(date2));
	return khoang_cach;

}
int tim_so_ngay_trong_thang(DATE date)
{
	int so_ngay_trong_thang{};
	switch (date.m) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		so_ngay_trong_thang = 31;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		so_ngay_trong_thang = 30;
		break;

	case 2:
		if (kt_nam_nhuan(date.y))
		{
			so_ngay_trong_thang = 29;
		}
		else
		{
			so_ngay_trong_thang = 28;
		}
	}
	return so_ngay_trong_thang;
}
void xuat_ra_lich_thang(DATE date)
{
	do {
		cout << "Nhap nam: "; cin >> date.y;
	} while (date.y < 0 && cout << "khong hop le, nhap lai" << endl);
	do
	{
		cout << "Nhap thang: "; cin >> date.m;
	} while (date.m < 1 || date.m > 12 && cout << "khong hop le, nhap lai" << endl);

	string thu_dau_tien = xuat_thu_trong_tuan(1, date.m, date.y);
	int ngay_trong_thang = tim_so_ngay_trong_thang(date);
	string thu[7]{ "thu 2","thu 3","thu 4", " thu 5","thu 6","thu 7", "chu nhat" };

	int k{};
	for (k = 0; k < 7; k++)
	{
		if (thu_dau_tien == thu[k])
			break;
	}
	string thu_trong_tuan[7] = { "T2","T3","T4","T5","T6","T7","CN" };
	for (int i = 0; i < 7; i++)
	{
		cout << thu_trong_tuan[i] << "\t";
	}
	cout << endl;
	int ngay = 1;
	for (int i = 0; i < k; i++)
	{
		cout << "  " << "\t";
	}
	while(ngay <= ngay_trong_thang)
	{
		cout << ngay << "\t";
		ngay++;
		k++;
		if (k == 7)
		{
			k = 0;
			cout << endl;
		}
	}
}
