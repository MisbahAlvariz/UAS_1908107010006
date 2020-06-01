#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

void menu();
void tampil_mobil();
void cari_mobil();
void tambah_mobil();
void hapus_mobil();
void edit_mobil();


void close();
struct DATA {
	int no_mesin;
	char nama_pemilik[30];
	char merk_mobil[30];
	char kerusakan[30];
}tambah,cek,hapus,temp;

int main()
{
	system("cls");
	char username[6];
    char password[5];

    login:
    printf("===Login===\nUsername: \n"); scanf("%s", username);

    printf("password: \n"); scanf("%s", password);

    if((strcmp(username,"admin")==0)&&(strcmp(password,"root")==0)){
        printf("status: login sukses");
    } else {
        printf("status: login gagal");
        goto login;
    }
    menu();
	return 0;
}
void menu(){
	int pilih;
	menu:
		system("cls");
		printf("====MENU====");
		printf("\n1. Tampil Data Mobil");
		printf("\n2. Cari Data Mobil");
		printf("\n3. Tambah Mobil");
		printf("\n4. Hapus Data Mobil");
		printf("\n5. Edit Data Mobil");
		printf("\n6. Keluar");
		printf("\n\nInput Pilihan Nomor Menu : ");
		scanf("%d", &pilih);

		switch(pilih){
			case 1:tampil_mobil();
				break;
			case 2:cari_mobil();
				break;
			case 3:tambah_mobil();
				break;
			case 4:hapus_mobil();
				break;
			case 5:edit_mobil();
				break;
			case 6:close();
				break;
			default:printf("\nPilihan Anda Salah !");
				getche();
				goto menu;
		}
}


void tampil_mobil()
{
	FILE *view;
	view = fopen("data.txt","r");
	int test=0;
	system ("cls");
	printf ("No. Mesin\t\tNama Pemilik\t\tMerk Mobil\t\tKerusakan\n");
	while (fscanf (view,"%d;%[^;];%[^;];%[^;];\n",&tambah.no_mesin,tambah.nama_pemilik,tambah.merk_mobil,&tambah.kerusakan)!=EOF)
	{
		printf("%d\t\t\t%s\t\t%s\t\t\t%s\n",tambah.no_mesin,tambah.nama_pemilik,tambah.merk_mobil,tambah.kerusakan);
		test++;
	}
	printf ("\nJumlah Data Mobil : %d",test);
	fclose(view);

	if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nKetik 1 untuk kembali ke menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': menu();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}
void cari_mobil()
{
	FILE *ptr;
	int test=0;
	system("cls");
	ptr=fopen("data.txt","r");
	system("cls");
	printf("Input No. Mesin : ");
	scanf("%d", &cek.no_mesin);
	while(fscanf (ptr,"%d;%[^;];%[^;];%[^;];\n",&tambah.no_mesin,tambah.nama_pemilik,tambah.merk_mobil,&tambah.kerusakan)!=EOF){
		if(tambah.no_mesin==cek.no_mesin){
			test=1;
		}
	}

	fclose(ptr);
	if(test!=1){
		system("cls");
		detail_print:
		printf("\nData tidak ditemukan !\a\a\a");
		detail_invalid:
		printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': cari_mobil();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaff Kesalahan Input !");
            	getche();
            	goto detail_invalid;
        }
	}else{
		detail_valid:
		printf("\n\n\nKetik 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto detail_valid;
       	}
    }

}

void tambah_mobil(){
	FILE *ptr,*ptr1;
	int count=0;

	ptr =fopen("data.txt","a");
		system("cls");
		ptr1 =fopen("data.txt","r");
		while (fscanf (ptr1,"%d;%[^;];%[^;];%[^;];\n",&tambah.no_mesin,&tambah.nama_pemilik,&tambah.merk_mobil,&tambah.kerusakan)!=EOF)
		{
			tambah.no_mesin++;
		}
		cek.no_mesin = tambah.no_mesin;
		fclose(ptr1);
		printf ("masukan Nama Pemilik : ");fflush(stdin);
		scanf ("%[^\n]",tambah.nama_pemilik);
		printf ("masukan Merk Mobil : ");fflush(stdin);
		scanf ("%[^\n]",tambah.merk_mobil);
		printf ("masukan Kerusakan : ");fflush(stdin);
		scanf ("%s",&tambah.kerusakan);

		fprintf(ptr,"%d;%s;%s;%s;\n",tambah.no_mesin,tambah.nama_pemilik,tambah.merk_mobil,tambah.kerusakan);
		fclose(ptr);

		printf("\n\nData Mobil Sudah Disimpan !");
		add_invalid:
		printf("\n\n\tKetik 1 untuk kembali ke menu utama dan 0 untuk keluar : ");

		switch(getch()){
    		case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}

void hapus_mobil()
{
	FILE *lama, *baru;
	int test=0;
	lama = fopen("data.txt","r");
	baru = fopen("baru.txt","w");
	system("cls");
	printf("Input No. Mesin yang akan di hapus : ");
	scanf("%d", &hapus.no_mesin);
	while(fscanf (lama,"%d;%[^;];%[^;];%[^;];\n",&tambah.no_mesin,tambah.nama_pemilik,tambah.merk_mobil,&tambah.kerusakan)!=EOF)
	{
		if(tambah.no_mesin != hapus.no_mesin)
		{
			fprintf(baru,"%d;%s;%s;%s;\n",tambah.no_mesin,tambah.nama_pemilik,tambah.merk_mobil,tambah.kerusakan);
		}
		else{
			test++;
			printf("\nData mobil No. Mesin : %d dengan merk_mobil : %s\n",tambah.no_mesin,tambah.merk_mobil);
			printf("\nBerhasil dihapus dari Daftar !");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("data.txt");
	rename("baru.txt","data.txt");
		if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nKetik 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': hapus_mobil();
            		break;
            	case '1': menu();
            		break;
            	case '2': close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else{
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }

}

void edit_mobil()
{
	int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("data.txt","r");
	baru = fopen ("baru.txt","w");
	system("cls");

	printf ("Masukan No. Mesin : ");
	scanf ("%d",&cek.no_mesin);
	while(fscanf (lama,"%d;%[^;];%[^;];%[^;];\n",&tambah.no_mesin,tambah.nama_pemilik,tambah.merk_mobil,&tambah.kerusakan)!=EOF)
	{
		if(tambah.no_mesin == cek.no_mesin)
		{
			test=1;
			ganti:
				printf("\nNo. Mesin : %d dimiliki Mobil dengan Merk : %s",tambah.no_mesin,tambah.merk_mobil);
				printf("\n\nData yang akan diganti : ");
				printf("\n1. Nama_Pemilik");
				printf("\n2. Merk_Mobil");
				printf("\n3. Kerusakan");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);

				if(pilih == 1)
				{
					printf ("\nMasukan Data Nama Pemilik Baru: ");fflush(stdin);
					scanf ("%[^\n]",cek.nama_pemilik);
					strcpy(tambah.nama_pemilik,cek.nama_pemilik);
						fprintf(baru,"%d;%s;%s;%s;\n",tambah.no_mesin,tambah.nama_pemilik,tambah.merk_mobil,tambah.kerusakan);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Data Merk Mobil Baru: ");fflush(stdin);
					scanf ("%[^\n]",cek.merk_mobil);
					strcpy(tambah.merk_mobil,cek.merk_mobil);
						fprintf(baru,"%d;%s;%s;%s;\n",tambah.no_mesin,tambah.nama_pemilik,tambah.merk_mobil,tambah.kerusakan);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf ("\nMasukan Data Kerusakan Baru: ");
					scanf ("%s",&cek.kerusakan);
					strcpy(tambah.kerusakan,cek.kerusakan);
					fprintf(baru,"%d;%s;%s;%s;\n",tambah.no_mesin,tambah.nama_pemilik,tambah.merk_mobil,tambah.kerusakan);
					printf ("\nPerubahan Sudah Disimpan !");
				}

				else{
					printf("\n\nInput Anda Salah !");
					getche();
					goto ganti;
				}
		}
		else
		{
			fprintf(baru,"%d;%s;%s;%s;\n",tambah.no_mesin,tambah.nama_pemilik,tambah.merk_mobil,tambah.kerusakan);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("data.txt");
	rename("baru.txt","data.txt");
	if(test!=1){
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': edit_mobil();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}

